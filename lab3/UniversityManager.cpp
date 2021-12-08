#include "UniversityManager.h"

UsersManager::UsersManager()
{
    students_factory = new StudentsFactory();
    teachers_factory = new TeachersFactory();
    admins_factory = new AdminsFactory();
}

UsersManager::~UsersManager()
{
    delete students_factory;
    delete teachers_factory;
    delete admins_factory;
}

void UsersManager::SetStudents()
{
    int number_of_students;
    std::cout << "Enter number of students : \n";
    std::cin >> number_of_students;
    for (int i = 0; i < number_of_students; i++)
    {
        students.push_back(dynamic_cast<Student *>(students_factory->CreateUser()));
    }
}

void UsersManager::SetTeachers()
{
    int number_of_teachers;
    std::cout << "Enter number of teachers : \n";
    std::cin >> number_of_teachers;
    for (int i = 0; i < number_of_teachers; i++)
    {
        teachers.push_back(dynamic_cast<Teacher *>(teachers_factory->CreateUser()));
    }
}

void UsersManager::SetAdmins()
{
    int number_of_admins;
    std::cout << "Enter number of admins : \n";
    std::cin >> number_of_admins;
    for (int i = 0; i < number_of_admins; i++)
    {
        admins.push_back(dynamic_cast<Admin *>(admins_factory->CreateUser()));
    }
}

void UsersManager::PrintInfo()
{
    for (auto s:students)
    {
        s->PrintInfo();
    }
    for (auto s:teachers)
    {
        s->PrintInfo();
    }
    for (auto s:admins)
    {
        s->PrintInfo();
    }
}

void CoursesManager::SetCourses()
{
    int number_of_courses;
    std::cout << "Enter number of courses : \n";
    std::cin >> number_of_courses;
    for (int i = 0; i < number_of_courses; i++)
    {
        std::string name;
        std::cout << "Enter course : \n";
        std::cin >> name;
        courses.push_back(name);
    }
}

void CoursesManager::PrintInfo()
{
    std::cout << "Courses : \n";
    for(const auto& c : courses){
        std::cout << c << std::endl;
    }
}

void UniversityManager::SetUsersManager(UsersManager *um)
{
    users_manager = um;
}

void UniversityManager::SetCoursesManager(CoursesManager *cm)
{
    courses_manager = cm;
}

void UniversityManager::PrintInfo()
{
    users_manager->PrintInfo();
    courses_manager->PrintInfo();
}

UsersManager *Builder::GetUsersManager()
{
    auto users_manager = new UsersManager();
    users_manager->SetStudents();
    users_manager->SetTeachers();
    users_manager->SetAdmins();
    return users_manager;
}

CoursesManager *Builder::GetCoursesManager()
{
    auto courses_manager = new CoursesManager();
    courses_manager->SetCourses();
    return courses_manager;
}

UniversityManager *Director::GetUniversityManager()
{
    auto university_manager = new UniversityManager();
    university_manager->SetUsersManager(builder->GetUsersManager());
    university_manager->SetCoursesManager(builder->GetCoursesManager());
    return university_manager;
}
