/** This file is generated from image-view.tsx */
#include <ui.h>
#include "../vendor.node_modules/@lcui/react-icons/dist/style.css.h"
#include "image-view.scss.h"
#include "global.css.h"

// UTF-8 encoded string from: %EE%B6%AE
static const unsigned char widget_text_0[] = {0xee, 0xb6, 0xae, 0};
// UTF-8 encoded string from: %EE%B6%B3
static const unsigned char widget_text_1[] = {0xee, 0xb6, 0xb3, 0};
// UTF-8 encoded string from: %EE%AF%BB
static const unsigned char widget_text_2[] = {0xee, 0xaf, 0xbb, 0};
// UTF-8 encoded string from: %EE%9C%B6
static const unsigned char widget_text_3[] = {0xee, 0x9c, 0xb6, 0};
// UTF-8 encoded string from: %EE%A8%94
static const unsigned char widget_text_4[] = {0xee, 0xa8, 0x94, 0};
// UTF-8 encoded string from: 0%20x%200
static const unsigned char widget_text_5[] = {0x30, 0x20, 0x78, 0x20, 0x30, 0};
// UTF-8 encoded string from: %EE%A9%83
static const unsigned char widget_text_6[] = {0xee, 0xa9, 0x83, 0};
// UTF-8 encoded string from: 0%20KB
static const unsigned char widget_text_7[] = {0x30, 0x20, 0x4b, 0x42, 0};
// UTF-8 encoded string from: 100%25
static const unsigned char widget_text_8[] = {0x31, 0x30, 0x30, 0x25, 0};
// UTF-8 encoded string from: %EF%96%8E
static const unsigned char widget_text_9[] = {0xef, 0x96, 0x8e, 0};
// UTF-8 encoded string from: %EE%BA%8F
static const unsigned char widget_text_10[] = {0xee, 0xba, 0x8f, 0};
// UTF-8 encoded string from: %EE%BA%8E
static const unsigned char widget_text_11[] = {0xee, 0xba, 0x8e, 0};
// UTF-8 encoded string from: %EF%85%9E
static const unsigned char widget_text_12[] = {0xef, 0x85, 0x9e, 0};

typedef struct {
        ui_widget_t *content;
        ui_widget_t *prev;
        ui_widget_t *ref_2;
        ui_widget_t *next;
        ui_widget_t *ref_4;
        ui_widget_t *ref_5;
        ui_widget_t *ref_6;
        ui_widget_t *ref_7;
        ui_widget_t *image_size;
        ui_widget_t *ref_9;
        ui_widget_t *file_size;
        ui_widget_t *percentage;
        ui_widget_t *ref_12;
        ui_widget_t *zoom_out;
        ui_widget_t *zoom_in;
        ui_widget_t *maximize;
} image_view_refs_t;

typedef struct image_view_react_state {
        char empty;
} image_view_react_state_t;

typedef struct image_view_react {
        image_view_react_state_t state;
        image_view_refs_t refs;
} image_view_react_t;

static ui_widget_prototype_t *image_view_proto;

static void image_view_init_prototype(void)
{
        image_view_proto = ui_create_widget_prototype("image_view", NULL);
}

static void image_view_load_template(ui_widget_t *parent, image_view_refs_t *refs)
{
        ui_widget_t *w[4];

        ui_widget_add_class(parent, "image-view");
        refs->content = ui_create_widget(NULL);
        ui_widget_add_class(refs->content, "content");
        refs->prev = ui_create_widget(NULL);
        ui_widget_add_class(refs->prev, "switch-button prev");
        refs->ref_2 = ui_create_widget("text");
        ui_widget_add_class(refs->ref_2, "fui-icon-filled");
        ui_widget_set_text(refs->ref_2, (const char*)widget_text_0);
        ui_widget_append(refs->prev, refs->ref_2);
        refs->next = ui_create_widget(NULL);
        ui_widget_add_class(refs->next, "switch-button next");
        refs->ref_4 = ui_create_widget("text");
        ui_widget_add_class(refs->ref_4, "fui-icon-filled");
        ui_widget_set_text(refs->ref_4, (const char*)widget_text_1);
        ui_widget_append(refs->next, refs->ref_4);
        ui_widget_append(refs->content, refs->prev);
        ui_widget_append(refs->content, refs->next);
        w[0] = ui_create_widget(NULL);
        ui_widget_add_class(w[0], "toolbar");
        refs->ref_5 = ui_create_widget("text");
        ui_widget_add_class(refs->ref_5, "fui-icon-regular icon button");
        ui_widget_set_text(refs->ref_5, (const char*)widget_text_2);
        w[1] = ui_create_widget(NULL);
        ui_widget_add_class(w[1], "divider");
        refs->ref_6 = ui_create_widget("text");
        ui_widget_add_class(refs->ref_6, "fui-icon-regular icon button mr-1");
        ui_widget_set_text(refs->ref_6, (const char*)widget_text_3);
        w[2] = ui_create_widget(NULL);
        ui_widget_add_class(w[2], "file-info");
        refs->ref_7 = ui_create_widget("text");
        ui_widget_add_class(refs->ref_7, "fui-icon-regular mr-2");
        ui_widget_set_text(refs->ref_7, (const char*)widget_text_4);
        refs->image_size = ui_create_widget("text");
        ui_widget_add_class(refs->image_size, "mr-4");
        ui_widget_set_text(refs->image_size, (const char*)widget_text_5);
        refs->ref_9 = ui_create_widget("text");
        ui_widget_add_class(refs->ref_9, "fui-icon-regular mr-2");
        ui_widget_set_text(refs->ref_9, (const char*)widget_text_6);
        refs->file_size = ui_create_widget("text");
        ui_widget_set_text(refs->file_size, (const char*)widget_text_7);
        ui_widget_append(w[2], refs->ref_7);
        ui_widget_append(w[2], refs->image_size);
        ui_widget_append(w[2], refs->ref_9);
        ui_widget_append(w[2], refs->file_size);
        refs->percentage = ui_create_widget("text");
        ui_widget_add_class(refs->percentage, "px-2");
        ui_widget_set_text(refs->percentage, (const char*)widget_text_8);
        refs->ref_12 = ui_create_widget("text");
        ui_widget_add_class(refs->ref_12, "fui-icon-regular icon button");
        ui_widget_set_text(refs->ref_12, (const char*)widget_text_9);
        refs->zoom_out = ui_create_widget("text");
        ui_widget_add_class(refs->zoom_out, "fui-icon-regular icon button");
        ui_widget_set_text(refs->zoom_out, (const char*)widget_text_10);
        refs->zoom_in = ui_create_widget("text");
        ui_widget_add_class(refs->zoom_in, "fui-icon-regular icon button");
        ui_widget_set_text(refs->zoom_in, (const char*)widget_text_11);
        w[3] = ui_create_widget(NULL);
        ui_widget_add_class(w[3], "divider");
        refs->maximize = ui_create_widget("text");
        ui_widget_add_class(refs->maximize, "fui-icon-regular icon button");
        ui_widget_set_text(refs->maximize, (const char*)widget_text_12);
        ui_widget_append(w[0], refs->ref_5);
        ui_widget_append(w[0], w[1]);
        ui_widget_append(w[0], refs->ref_6);
        ui_widget_append(w[0], w[2]);
        ui_widget_append(w[0], refs->percentage);
        ui_widget_append(w[0], refs->ref_12);
        ui_widget_append(w[0], refs->zoom_out);
        ui_widget_append(w[0], refs->zoom_in);
        ui_widget_append(w[0], w[3]);
        ui_widget_append(w[0], refs->maximize);
        ui_widget_append(parent, refs->content);
        ui_widget_append(parent, w[0]);
}

static void image_view_react_update(ui_widget_t *w)
{
        image_view_react_t *_that = ui_widget_get_data(w, image_view_proto);
}

static void image_view_react_init(ui_widget_t *w)
{
        image_view_react_t *_that = ui_widget_get_data(w, image_view_proto);
        image_view_load_template(w, &_that->refs);
}

static void image_view_react_destroy(ui_widget_t *w)
{
}

void ui_load_image_view_resources(void)
{
        ui_load_css_string(css_str_style, "style.css");
        ui_load_css_string(css_str_image_view, "image-view.scss");
        ui_load_css_string(css_str_global, "global.css");
}
