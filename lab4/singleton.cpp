#include <iostream>
#include <string>
class RequestSubmiter
{
protected:
    RequestSubmiter()
    {
    }
    static RequestSubmiter* singleton_;
    static int id;
public:
    RequestSubmiter(RequestSubmiter &other) = delete;
    void operator=(const RequestSubmiter &) = delete;
    static RequestSubmiter *GetInstance()
    {
        if(singleton_==nullptr){
            singleton_ = new RequestSubmiter();
        }
        return singleton_;
    }
    static std::string submit(std::string request)
    {
        std::cout << id << ": " << request << std::endl;
        ++id;
        return request;
    }
};
RequestSubmiter* RequestSubmiter::singleton_= nullptr;
int RequestSubmiter::id = 0;
void method_1()
{
    RequestSubmiter* singleton = RequestSubmiter::GetInstance();
    std::cout << "Enter request:" << "\n";
    std::string request;
    std::cin>>request;
    singleton->submit(request);
}
void method_2(){
    RequestSubmiter* singleton = RequestSubmiter::GetInstance();
    std::cout << "Enter request:" << "\n";
    std::string request;
    std::cin>>request;
    singleton->submit(request);
}
int main()
{
    method_1();
    method_2();
    return 0;
}
