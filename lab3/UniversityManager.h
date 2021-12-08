#ifndef LAB3_UNIVERSITYMANAGER_H
#define LAB3_UNIVERSITYMANAGER_H

#include "Factory.h"

class UsersManager
{
private:
    std::vector<Student *> students;
    std::vector<Teacher *> teachers;
    std::vector<Admin *> admins;
    StudentsFactory *students_factory;
    TeachersFactory *teachers_factory;
    AdminsFactory *admins_factory;
public:
    UsersManager();

    ~UsersManager();

    void SetStudents();

    void SetTeachers();

    void SetAdmins();

    void PrintInfo();
};

class CoursesManager
{
private:
    std::vector<std::string> courses;
public:
    void SetCourses();

    void PrintInfo();
};

class UniversityManager
{
private:
    UsersManager *users_manager = nullptr;
    CoursesManager *courses_manager = nullptr;
public:
    UniversityManager() = default;

    void SetUsersManager(UsersManager *um);

    void SetCoursesManager(CoursesManager *cm);

    void PrintInfo();
};

class Builder
{
public:
    UsersManager *GetUsersManager();

    CoursesManager *GetCoursesManager();
};

class Director{
private:
    Builder* builder;
public:
    UniversityManager *GetUniversityManager();
};


#endif //LAB3_UNIVERSITYMANAGER_H
