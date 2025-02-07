#include <locale.h>
#include <LCUI.h>
#include <LCUI/main.h>


static void app_init(void)
{
        lcui_init();

}

static int app_run(void)
{
        return lcui_run();
}
