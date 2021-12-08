#include "App.h"

int main()
{
    App *app = App::GetInstance();
    app->Work();
    return 0;
}
