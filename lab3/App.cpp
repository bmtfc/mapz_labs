#include "App.h"

App *App::instance = nullptr;

App *App::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new App();
    }
    return instance;
}

void App::Work()
{
    bool check = true;
    UniversityManager *university_manager;
    Director Director1{};
    std::cout << "You can enter users and courses !\n";
    while (check)
    {
        university_manager = Director1.GetUniversityManager();
        while (true)
        {
            std::cout << "Enter users and courses one more time? (y/n)";
            char ans;
            std::cin >> ans;
            if (ans == 'y')
            {
                check = true;
                break;
            }
            else if (ans == 'n')
            {
                check = false;
                break;
            }
            else
            {
                std::cout << "Enter y for \"yes\" and n for \"no\".\n";
            }
        }
    }
    university_manager->PrintInfo();
    delete university_manager;
}

App::App() = default;
