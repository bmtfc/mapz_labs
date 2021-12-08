#include <iostream>
#include <string>
class Request {
public:
    virtual ~Request(){};
    virtual std::string fill_info() const = 0;
};
class RequestFromStudent : public Request {
public:
    std::string fill_info() const override {
        std::cout << "Enter Student Request";
        std::string request;
        std::cin>>request;
        return request;
    }
};
class RequestFromProfessor : public Request {
    std::string fill_info() const override {
        std::cout << "Enter Professor Request";
        std::string request;
        std::cin>>request;
        return request;
    }
};
class Account {
public:
    virtual ~Account(){};
    virtual std::string fill_account() const = 0;
};
class StudentAccount : public Account {
public:
    std::string fill_account() const override {
        std::cout << "Enter Student Info";
        std::string info;
        std::cin>>info;
        return info;
    }
};
class ProfessorAccount : public Account {
public:
    std::string fill_account() const override {
        std::cout << "Enter Professor Request";
        std::string info;
        std::cin>>info;
        return info;
    }
};
class AbstractFactory {
public:
    virtual Request * create_request() const = 0;
    virtual Account * create_account() const = 0;
};
class StudentFactory : public AbstractFactory {
public:
    Request * create_request() const override {
        return new RequestFromStudent();
    }
    Account * create_account() const override {
        return new StudentAccount();
    }
};
class ProfessorFactory : public AbstractFactory {
public:
    Request * create_request() const override {
        return new RequestFromProfessor();
    }
    Account * create_account() const override {
        return new ProfessorAccount();
    }
};
void ClientCode(const AbstractFactory &factory) {
    const Request *request = factory.create_request();
    const Account *account = factory.create_account();
    std::cout << request->fill_info() << "\n";
    std::cout << account->fill_account() << "\n";
    delete request;
    delete account;
}
int main() {
    std::cout << "Student\n";
    auto *f1 = new StudentFactory();
    ClientCode(*f1);
    std::cout << std::endl;
    std::cout << "Professor\n";
    auto *f2 = new ProfessorFactory();
    ClientCode(*f2);
    return 0;
}
