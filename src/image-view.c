#include <stdio.h>
#include <ptk.h>
#include <LCUI/widgets.h>
#include "image-view.tsx.h"
#include "image-view.h"
#include "image-controller.h"
#include "utils.h"

typedef struct {
        image_view_react_t base;
        image_controller_t controller;
        float mouse_x, mouse_y;
        float mouse_offset_x, mouse_offset_y;
        bool dragging;
} image_view_t;

static image_view_t *image_view_get(ui_widget_t *w)
{
        return ui_widget_get_data(w, image_view_proto);
}

static void image_view_on_keydown(ui_widget_t *root, ui_event_t *e, void *arg)
{
        ui_widget_t *w = e->data;
        image_view_t *view = image_view_get(w);

        switch (e->key.code) {
        case KEY_EQUAL:
                image_controller_zoom_in(&view->controller);
                break;
        case KEY_MINUS:
                image_controller_zoom_out(&view->controller);
                break;
        default:
                return;
        }
        image_view_update(w);
}

static void image_view_on_mutation(ui_mutation_list_t *list,
                                   ui_mutation_observer_t *observer, void *arg)
{
        image_view_reset(arg);
}

static void image_view_init(ui_widget_t *w)
{
        image_view_t *view =
            ui_widget_add_data(w, image_view_proto, sizeof(image_view_t));
        ui_mutation_observer_t *observer;
        ui_mutation_observer_init_t options = { .properties = true };

        image_view_react_init(w);
        image_controller_init(&view->controller);
        image_view_update(w);
        ui_widget_on(ui_root(), "keydown", image_view_on_keydown, w);

        observer = ui_mutation_observer_create(image_view_on_mutation, w);
        ui_mutation_observer_observe(observer, view->base.refs.content,
                                     options);
}

static void image_view_destroy(ui_widget_t *w)
{
        image_view_t *view = image_view_get(w);
        image_view_react_destroy(w);
        image_controller_destroy(&view->controller);
}

void image_view_update(ui_widget_t *w)
{
        char size_str[64];
        image_view_t *view = image_view_get(w);
        image_controller_t *c = &view->controller;
        image_view_refs_t *refs = &view->base.refs;

        if (ui_image_valid(c->image)) {
                snprintf(size_str, 31, "%gpx %gpx",
                         c->scale * c->image->data.width,
                         c->scale * c->image->data.height);
                ui_widget_set_style_string(view->base.refs.content,
                                           "background-size", size_str);
                ui_widget_set_style_unit_value(refs->content,
                                               css_prop_background_position_x,
                                               c->image_offset_x, CSS_UNIT_PX);
                ui_widget_set_style_unit_value(refs->content,
                                               css_prop_background_position_y,
                                               c->image_offset_y, CSS_UNIT_PX);
        } else {
                ui_widget_set_style_string(refs->content, "background-size",
                                           "contain");
                ui_widget_set_style_string(refs->content, "background-position",
                                           "center");
        }
        if (!c->image || c->image->state != UI_IMAGE_STATE_COMPLETE ||
            c->image->error == PD_OK) {
                ui_widget_hide(refs->tip);
        } else {
                ui_widget_show(refs->tip);
        }
        image_view_react_update(w);
}

static void image_view_on_mousedown(ui_widget_t *w, ui_event_t *e, void *arg)
{
        float offset_x, offset_y;
        image_view_t *view = image_view_get(e->data);

        ui_widget_get_offset(w, NULL, &offset_x, &offset_y);
        ui_widget_set_mouse_capture(w);
        view->mouse_offset_x =
            e->mouse.x - offset_x - view->controller.image_offset_x;
        view->mouse_offset_y =
            e->mouse.y - offset_y - view->controller.image_offset_y;
        view->dragging = true;
}

static void image_view_on_mousemove(ui_widget_t *w, ui_event_t *e, void *arg)
{
        float offset_x, offset_y;
        image_view_t *view = image_view_get(e->data);

        ui_widget_get_offset(w, NULL, &offset_x, &offset_y);
        view->mouse_x = e->mouse.x - offset_x;
        view->mouse_y = e->mouse.y - offset_y;
        if (view->dragging) {
                image_controller_set_position(
                    &view->controller,
                    e->mouse.x - offset_x - view->mouse_offset_x,
                    e->mouse.y - offset_y - view->mouse_offset_y);
                image_view_update(e->data);
        }
}

static void image_view_on_mouseup(ui_widget_t *w, ui_event_t *e, void *arg)
{
        image_view_t *view = image_view_get(e->data);
        view->dragging = false;
        ui_widget_release_mouse_capture(w);
}

static void image_view_on_image_start_load(ui_image_event_t *e)
{
        image_view_reset(e->data);
        ui_image_off_progress(e->image, image_view_on_image_start_load,
                              e->data);
}

static void image_view_on_image_event(ui_image_event_t *e)
{
        image_view_t *view = image_view_get(e->data);

        switch (e->type) {
        case UI_IMAGE_EVENT_PROGRESS:
                ui_widget_set_style_unit_value(
                    view->base.refs.progressbar, css_prop_width,
                    e->image->progress, CSS_UNIT_PERCENT);
                return;
        case UI_IMAGE_EVENT_LOAD:
                image_view_reset(e->data);
                break;
        case UI_IMAGE_EVENT_ERROR:
                logger_error("load image error: %d", e->image->error);
                image_view_update(e->data);
                break;
        default:
                break;
        }
        ui_widget_hide(view->base.refs.progressbar);
}

static void image_view_on_mousewheel(ui_widget_t *w, ui_event_t *e, void *arg)
{
        image_view_t *view = image_view_get(e->data);

        image_controller_t *c = &view->controller;
        float scale = view->controller.scale;
        float center_x = (view->mouse_x - c->image_offset_x) / scale;
        float center_y = (view->mouse_y - c->image_offset_y) / scale;

        if (e->wheel.delta_y > 0) {
                image_controller_zoom_in(c);
        } else {
                image_controller_zoom_out(c);
        }
        image_controller_set_position(c, view->mouse_x - center_x * c->scale,
                                      view->mouse_y - center_y * c->scale);
        image_view_update(e->data);
}

void image_view_load_file(ui_widget_t *w, const char *file)
{
        char *url;
        image_view_t *view = image_view_get(w);
        image_controller_t *c = &view->controller;
        wchar_t title[256];
        size_t len = mbstowcs(title, path_basename(file), 255);

        title[255] = 0;
        ui_widget_set_title(ui_root(), title);

        if (c->image) {
                ui_image_off_load(c->image, image_view_on_image_event, w);
                ui_image_off_error(c->image, image_view_on_image_event, w);
                ui_image_off_progress(c->image, image_view_on_image_event, w);
                ui_image_off_progress(c->image, image_view_on_image_start_load,
                                      w);
        }
        image_controller_load_file(c, file);
        ui_image_on_load(c->image, image_view_on_image_event, w);
        ui_image_on_error(c->image, image_view_on_image_event, w);
        ui_image_on_progress(c->image, image_view_on_image_event, w);
        ui_image_on_progress(c->image, image_view_on_image_start_load, w);
        ui_widget_set_style_unit_value(view->base.refs.progressbar,
                                       css_prop_width, 0, CSS_UNIT_PERCENT);
        ui_widget_show(view->base.refs.progressbar);
        ui_text_set_content(view->base.refs.filename, path_basename(file));

        url = malloc(sizeof(char) * (strlen(file) + 10));
        sprintf(url, "url(%s)", file);
        ui_widget_set_style_string(view->base.refs.content, "background-image",
                                   url);
        free(url);
}

void image_view_reset(ui_widget_t *w)
{
        image_view_t *view = image_view_get(w);
        image_controller_t *c = &view->controller;

        c->viewport_width = view->base.refs.content->padding_box.width;
        c->viewport_height = view->base.refs.content->padding_box.height;
        image_controller_zoom_to_fit(c);
        image_view_update(w);
}

ui_widget_t *ui_create_image_view(void)
{
        return ui_create_widget_with_prototype(image_view_proto);
}

void ui_register_image_view(void)
{
        image_view_init_prototype();
        image_view_proto->init = image_view_init;
        image_view_proto->destroy = image_view_destroy;
}
