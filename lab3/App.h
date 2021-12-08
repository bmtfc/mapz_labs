#ifndef LAB3_APP_H
#define LAB3_APP_H

#include "UniversityManager.h"

class App
{
private:
    static App *instance;

    App();

public:
    App(App const&) = delete;
    App& operator=(App const&) = delete;

    static App* GetInstance();
    void Work();
};


#endif //LAB3_APP_H
