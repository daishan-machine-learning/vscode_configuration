#include<iostream>
#include<memory>
/*
    1.Whenever you are dealing with inheritance, you should make any explicit destructors virtual
    2.If you want to ignore the virtualization of a function,just simply use the scope resolution operator!

     recommendations:
     1.If you intend your class to be inherited from ,make sure your destructor is virtual.
     2.If you don't intend your class to be inherited from,mark your class as final.This will prevent other classes from inheriting it in the
       first place,without imposing any other use restrictions on the class itself.
*/
class Base {
public:
    virtual ~Base(){
        std::cout<<"Base Destructor!\n";
    }
    virtual const char* getName()const{return "Base";}
};

class Derived:public Base{
private:
    int* m_array;
public:
    typedef std::shared_ptr<Derived> ptr; // 使用智能指针管理很方便
    Derived(int length)
    :m_array(new int[length]){
        std::cout<<"Derived Constructor"<<std::endl;
    }
    ~Derived(){
        std::cout<<"Derived Destructor!\n";
        delete[] m_array;
    }
    virtual const char* getName()const override{return "Derived";}
};

int main(){
    Derived *derived = new Derived(5);
    Base* base = derived;
    delete base;
    std::cout<<base->Base::getName()<<std::endl;  // 使用scope operator来指定使用基类的virtual函数
 
    

    std::cin.get();
}