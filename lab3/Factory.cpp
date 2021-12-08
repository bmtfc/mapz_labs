#include "Factory.h"

std::string User::GetName()
{
    return name;
}

std::string User::GetSurname()
{
    return surname;
}

Student::Student(std::string name1, std::string surname1, std::string department1)
{
    name = std::move(name1);
    surname = std::move(surname1);
    department = std::move(department1);
}

void Student::PrintInfo()
{
    std::cout << "I`m student, Name : " + name + ", Surname : " + surname + ", Department :" + department + ".\n";
}

Teacher::Teacher(std::string name1, std::string surname1, std::string position1)
{
    name = std::move(name1);
    surname = std::move(surname1);
    position = std::move(position1);
}

void Teacher::PrintInfo()
{
    std::cout << "I`m teacher, Name : " + name + ", Surname : " + surname + ", Position :" + position + ".\n";
}

Admin::Admin(std::string name1, std::string surname1)
{
    name = std::move(name1);
    surname = std::move(surname1);
}

void Admin::PrintInfo()
{
    std::cout << "I`m admin, Name : " + name + ", Surname : " + surname + ".\n";
}

User *StudentsFactory::CreateUser()
{
    std::string name, surname, department;
    std::cout << "Enter name : ";
    std::cin >> name;
    std::cout << "Enter surname: ";
    std::cin >> surname;
    std::cout << "Enter department: ";
    std::cin >> department;
    return new Student(name, surname, department);
}

User *StudentsFactory::CreateUserFromUser(User *user)
{
    std::string department;
    std::cout << "Enter department: ";
    std::cin >> department;
    return new Student(user->GetName(), user->GetSurname(), department);
}

User *TeachersFactory::CreateUser()
{
    std::string name, surname, position;
    std::cout << "Enter name : ";
    std::cin >> name;
    std::cout << "Enter surname: ";
    std::cin >> surname;
    std::cout << "Enter position: ";
    std::cin >> position;
    return new Teacher(name, surname, position);
}

User *TeachersFactory::CreateUserFromUser(User *user)
{
    std::string position;
    std::cout << "Enter position: ";
    std::cin >> position;
    return new Teacher(user->GetName(), user->GetSurname(), position);
}

User *AdminsFactory::CreateUser()
{
    std::string name, surname;
    std::cout << "Enter name : ";
    std::cin >> name;
    std::cout << "Enter surname: ";
    std::cin >> surname;
    return new Admin(name, surname);
}

User *AdminsFactory::CreateUserFromUser(User *user)
{
    return new Admin(user->GetName(), user->GetSurname());
}


Client::Client(Factory *factory1)
{
    factory=factory1;
}

void Client::PrintInfo()
{
    User* user = factory->CreateUser();
    user->PrintInfo();
}
