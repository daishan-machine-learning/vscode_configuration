#include<iostream>

// diamond inheritance problem
// To share a base class ,simply insert the "virtual" keyword in the
// inheirtance list of the derived class.This creates what is called 
// a virtual base class,which means there is only one base object.
// The base object is shared between all objects in the inheritance tree
// and it is only constructed once.
// 有一个问题，那就是谁负责创建virtual base 的对象，答案就是Copier，所以每一次
// Copier被创建的时候，就可以创建一个，也是唯一的一个virtual base class object。
// 虚基类必须在所有非虚基类前面创建，这样可以保证，所有的基类都在派生类之前创建
// most-derived class is responsible for virtual base class construction.
class PoweredDevice{
public:
    PoweredDevice(int power){
        std::cout<<"PowerDevice:"<<power<<std::endl;
    }
};

class Scanner:virtual public PoweredDevice{
public:
    Scanner(int scanner,int power)
        :PoweredDevice(power){
            std::cout<<"Scanner:"<<scanner<<std::endl;
    }
};

class Printer:virtual public PoweredDevice{
public:
    Printer(int printer,int power)
        :PoweredDevice(power){
            std::cout<<"Printer:"<<printer<<std::endl;
        }
};

class Copier:public Scanner,public Printer{
public:
    Copier(int scanner,int printer,int power)
        : PoweredDevice(power),// PoweredDevice is constructed here
        Scanner(scanner,power),Printer(printer,power){
            std::cout<<"Copier:"<<std::endl;
    }
};

int main(){
    Copier copier{1,2,3};
    std::cin.get();
    return 0;
}