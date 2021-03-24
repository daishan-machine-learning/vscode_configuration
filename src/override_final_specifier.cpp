#if 0
#include<iostream>
/*
    之所以需要override，是因为，虚函数的覆盖，是要求返回类型和参数类型和const完全一致，
    但是在大型的程序中，我们有时没办法保证这一点，所以c++就推出了override,来显式的表明，
    该函数是某个基类虚函数的覆盖，如果出现不匹配的情况，或者基类压根就没有需要override的函数，
    编译器就会报错。

*/

/*
    final specifier:
        final 用来表示当前函数不允许被override 或者是 当前类不允许被继承，final放置的位置是当前函数
        之后，或者是当前类之后。
*/

/*
covariant return type :协变返回类型
这是c++中唯一允许的返回类型不一致，也可被编译器认为match的virtual function override。
也就是:如果一个虚函数的返回类型是某个类Base的指针和引用，而该虚函数的覆盖版本返回的是
Base的派生类的指针和引用，这种情况被称为covariant return type

*/
class A{
public:
    virtual const char* getName1(int a){return "A";}
    virtual const char* getName2(int b){return "A";}
    virtual const char* getName3(int c) /*final*/ {return "A";}
    virtual A* getThis(){
        std::cout<<"A get this:"<<std::endl;
        return this;
    }
    const char* speak(){
        return "Base";
    }
};

class B final:public A{
public:
    //  override virtual function must strictly match
    #if 0
    const char* getName1(short a)override{return "B";} // 编译器报错
    const char* getName2(int b)const override{return "B";}; // 编译器报错
    #endif
    const char* getName3(int c)override{return "B";}
    // covariant return type
    B* getThis() override {
        std::cout<<"B get this:"<<std::endl;
        return this;
    }
    const char* speak(){
        return "Derived";
    }
};

#if 0 
class C :public B{   // 编译器报错，因为B这个类被final修饰，所以不可以被继承

};
#endif
int main(){
    B b;
    A &ra = b;
    std::cout<<ra.getName1(1)<<std::endl;
    std::cout<<ra.getName2(1)<<std::endl;
    std::cout<<ra.getName3(1)<<std::endl;

    std::cout<<b.getThis()->speak() << std::endl;
    std::cout<<ra.getThis()->speak()<< std::endl; // note:ra.getThis()返回B*，但是因为A中原virtual function返回A*，所以B*会向上转换
    std::cin.get();
}

#endif