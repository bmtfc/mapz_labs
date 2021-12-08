#ifndef LAB3_FACTORY_H
#define LAB3_FACTORY_H

#include <iostream>
#include <vector>


class User
{
protected:
    std::string name;
    std::string surname;
public:
    virtual void PrintInfo() = 0;

    std::string GetName();

    std::string GetSurname();

    virtual ~User() = default;

};

class Student : public User
{
private:
    std::string department;
public:
    Student(std::string name1, std::string surname1, std::string department1);

    void PrintInfo() override;
};

class Teacher : public User
{
private:
    std::string position;
public:
    Teacher(std::string name1, std::string surname1, std::string position1);

    void PrintInfo() override;
};

class Admin : public User
{
public:
    Admin(std::string name1, std::string surname1);

    void PrintInfo() override;
};

class Factory
{
public:
    virtual User *CreateUser() = 0;

    virtual User *CreateUserFromUser(User *user) = 0;
};

class StudentsFactory : public Factory
{
public:
    StudentsFactory() = default;

    User *CreateUser() override;

    User *CreateUserFromUser(User *user) override;
};

class TeachersFactory : public Factory
{
public:
    TeachersFactory() = default;

    User *CreateUser() override;

    User *CreateUserFromUser(User *user) override;
};

class AdminsFactory : public Factory
{
public:
    AdminsFactory() = default;

    User *CreateUser() override;

    User *CreateUserFromUser(User *user) override;
};

class Client
{
private:
    Factory *factory;
public:
    Client(Factory *factory1);

    void PrintInfo();
};


#endif //LAB3_FACTORY_H
