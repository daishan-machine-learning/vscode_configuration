#include<iostream>
#include<string>
class Base{
protected:
    int m_value;
public:
    Base(int value):m_value(value){

    }

    const std::string GetName()const{
        return "Base";
    }

    int GetValue()const{
        return m_value;
    }
};

class Derived:public Base{
public:
    Derived(int value):Base(value){

    }
    const std::string GetName()const{
      
        return "Derived";
    }

    int GetValue()const{
        
        return m_value*2;
    }
};
// 注意在同一个系统中由于多个libstdc++-6.dll产生的编译器无法选择问题
int main(){
    Derived d(12);
    std::cout<<d.GetName()<<":"<<d.GetValue()<<std::endl;

    Derived& rd = d;
    std::cout<<rd.GetName()<<":"<<d.GetValue()<<std::endl;

    Derived* pd = &d;
    std::cout<<pd->GetName()<<":"<<pd->GetValue()<<std::endl;
    std::cin.get();
}
