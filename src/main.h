#include <locale.h>
#include <LCUI.h>
#include <LCUI/main.h>
#include "home.h"

static void app_init(void)
{
        lcui_init();
        ui_load_home_resources();
        ui_register_home();
}

static int app_run(void)
{
        return lcui_run();
}
