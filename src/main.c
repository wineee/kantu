#include "main.h"

int main(int argc, char *argv[])
{
        app_init();
        ui_widget_set_title(ui_root(), L"Kantu");
        ui_widget_append(ui_root(), ui_create_home());
        return app_run();
}
