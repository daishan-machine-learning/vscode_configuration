#if 0
#include<iostream>
#include<string>
#include<string_view>
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

class Animal{
protected:
    std::string m_name;
    Animal(std::string name):m_name(name){

    }
    // prevent slicing(covered later)
    Animal(const Animal&) = delete;
    Animal& operator=(const Animal&) = delete;
public:
    const std::string& getName()const{return m_name;}
    std::string speak()const{return "???";}
};

class Cat:public Animal{
public:
    Cat(std::string name):Animal(name){

    }
    std::string speak()const {return "Meow";}
};

class Dog:public Animal{
public:
    Dog(std::string name)
        :Animal(name){

    }
    
    std::string speak()const{return "Woof";}
};

int main(){
    #if 0 
    Derived d(12);
    std::cout<<d.GetName()<<":"<<d.GetValue()<<std::endl;

    Derived& rd = d;
    std::cout<<rd.GetName()<<":"<<d.GetValue()<<std::endl;

    Derived* pd = &d;
    std::cout<<pd->GetName()<<":"<<pd->GetValue()<<std::endl;
    #endif

#if 0 
    Derived derived{5};
    Base &rbase = derived;
    Base *pbase = &derived;
    // 通过基类的指针和引用，指向派生类的对象，我们可以访问派生类对象的基类部分
    // 在没有virtual的情况下，基类的指针和引用都看不到子类的数据和对象，只能
    // 看到子类对象的基类部分的数据和函数
    std::cout<<"derived is a"<<derived.GetName()<<" and has value "<<derived.GetValue()<<"\n";
    std::cout<<"rBase is a "<<rbase.GetName()<<" and has value "<<rbase.GetValue()<<"\n";
    std::cout<<"pBase is a "<<pbase->GetName()<<" and has value "<<pbase->GetValue()<<"\n"; 
    std::cin.get();
#endif

    const Cat cat("Fred");
    std::cout<<"cat is named "<<cat.getName()<<", and it says "<<cat.speak()<<"\n";
    
    const Dog dog("Garbo");
    std::cout<<"dog is named "<<dog.getName()<<", and it says "<<dog.speak()<<"\n";

    const Animal *pAnimal{&cat};
    std::cout<<"pAnimal is named "<<pAnimal->getName()<<", and it says "<<pAnimal->speak()<<"\n";

    pAnimal = &dog;
    std::cout<<"pAnimal is named "<<pAnimal->getName()<<", and it says "<<pAnimal->speak()<<"\n";
    std::cin.get();
    return 0;
}

#endif