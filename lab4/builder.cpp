#include <iostream>
#include <vector>
#include<string>
class Request{
public:
    std::vector<std::string> details;
    void list_details()const{
        std::cout << "Request details: ";
        for (size_t i=0;i<details.size();i++){
            if(details[i]== details.back()){
                std::cout << details[i];
            }else{
                std::cout << details[i] << ", ";
            }
        }
        std::cout << "\n\n";
    }
};
class Builder{
public:
    virtual ~Builder(){}
    virtual void ProduceTitle(std::string) const =0;
    virtual void ProduceLevel(std::string) const =0;
    virtual void ProduceInfo(std::string) const =0;
};
class ConcreteBuilder1 : public Builder{
private:
    Request* request;
public:
    ConcreteBuilder1(){
        this->Reset();
    }
    ~ConcreteBuilder1(){
        delete request;
    }
    void Reset(){
        this->request= new Request();
    }
    void ProduceTitle(std::string title)const override{
        this->request->details.push_back(title);
    }
    void ProduceLevel(std::string level)const override{
        this->request->details.push_back(level);
    }
    void ProduceInfo(std::string info)const override{
        this->request->details.push_back(info);
    }
    Request* GetRequest() {
        Request* result= this->request;
        this->Reset();
        return result;
    }
};
class Director{
private:
    Builder* builder;
public:
    void set_builder(Builder* builder){
        this->builder=builder;
    }
    void BuildMinimalRequest(std::string &title){
        this->builder->ProduceTitle(title);
    }
    void BuildFullRequest(std::string &title,std::string &level,std::string &info){
        this->builder->ProduceTitle(title);
        this->builder->ProduceLevel(level);
        this->builder->ProduceInfo(info);
    }
};
void ClientCode(Director& director)
{
    ConcreteBuilder1* builder = new ConcreteBuilder1();
    director.set_builder(builder);
    std::cout << "Enter Request only with title:\n";
    std::string title, level, info;
    std::cin>>title;
    director.BuildMinimalRequest(title);
    Request* p= builder->GetRequest();
    p->list_details();
    delete p;
    std::cout << "Enter full Request product:\n";
    std::cout << "Title: ";
    std::cin>>title;
    std::cout << "Level: ";
    std::cin>>level;
    std::cout << "Info: ";
    std::cin>>info;
    director.BuildFullRequest(title, level, info);
    p= builder->GetRequest();
    p->list_details();
    delete p;
    // Remember, the Builder pattern can be used without a Director class.
    std::cout << "Custom Request:\n";
    std::cout << "Title: ";
    std::cin>>title;
    std::cout << "Info: ";
    std::cin>>info;
    builder->ProduceTitle(title);
    builder->ProduceInfo(info);
    p=builder->GetRequest();
    p->list_details();
    delete p;
    delete builder;
}
int main(){
    Director* director= new Director();
    ClientCode(*director);
    delete director;
    return 0;
}
