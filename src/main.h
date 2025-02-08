#include <locale.h>
#include <LCUI.h>
#include <LCUI/main.h>
#include "home.h"
#include "image-view.h"

static void app_init(void)
{
        lcui_init();
        ui_load_home_resources();
        ui_load_image_view_resources();
        ui_register_home();
        ui_register_image_view();
}

static int app_run(void)
{
        return lcui_run();
}
