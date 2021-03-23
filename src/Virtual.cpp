#include<iostream>
#include<string>
#include<vector>
// 1.virtual function and polymorphism
// 2.virtual resolve to “most-derived” version between Base and current derived object
// 3.if a function is marked as virtual ,all matching overrides are alse considered virtual implicitly,even if they are not explicitly marked as such.
// 4.在派生类中的虚函数的override中，返回类型也必须一致，不然将被编译器视为两个函数
// 5.do not call virtual function from constructor or destructor
// 原因是当你调用基类的构造函数的时候，派生类对象还没创建，而基类已经创建，这时在基类的构造函数中调用virtual function 会导致只能调用基类函数
// 对于析构函数，当然也是相似的道理，因为当基类的析构函数开始析构的时候，派生类对象的部分已经析构完毕，此时调用的virtual function就只能是基类的函数了，
// 从这个知识点可以看出，virtual function的调用时程序运行时动态的，这种情况称为RTTI(runtime type information)
// 6.析构函数的缺点: 相比一般的函数性能低，因为程序动态的找虚函数，然后，每个类对象还要分配一个额外的指针。
#if 0 
class Base{
public:
    virtual std::string getName()const{return "Base";}
};

class Derived:public Base{
public:
virtual std::string getName()const{return "Derived";}
};
#endif
class Animal{
protected:
std::string m_name;
public:
    Animal(const std::string& name):m_name(name){
          std::cout<<"Animal Constructor"<<":"<<speak()<<std::endl; // 这个时候还没创建派生类对象
    }
    const std::string& getName()const{return m_name;}
    virtual std::string speak(){
        return "???";
    }
    virtual double getNumber(){
        return 1.0;
    }
};

class Cat:public Animal{
public:
    Cat(const std::string& name):Animal(name){
      
    }
    virtual std::string speak() override{
        return "Meow";
    }
};

class Dog:public Animal{
public:  
    Dog(const std::string& name):Animal(name){

    }
    virtual std::string speak()override{  // 最好加上overridev,不仅增加可读性，还可以增加编译器的效率
        return "Woof";
    }

    /*
    //下面函数想要重写基类的函数，返回类型必须一致，这和普通函数不同，普通函数是不在意返回类型重载的，但是虚函数在意
    virtual int getNumber()override{
        return 2.0;
    }*/
};

void report(Animal& animal){
    std::cout<<animal.getName()<<":"<<animal.speak()<<std::endl;
}
int main(){
    #if 0 
    Derived derived;
    Base &rBase = derived;
    std::cout<<"rBase is a"<<rBase.getName()<<"\n";
    std::cin.get();
    #endif
    std::vector<Animal*> anims={{new Dog("wangcai")},{new Cat("miaomiao")},{new Cat("huahua")},{new Dog("daishan")}};
    for(auto it = anims.begin();it != anims.end(); ++it){
        report(*(*it));
    }
    std::cin.get();
}