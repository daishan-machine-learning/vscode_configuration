#if 0 
#include<iostream>
#include"Storage.h"
void print();
void test();
int main(){
    std::cout<<"Hello,VSCode"<<std::endl;
    print();
    test();

    
    Storage<int> obj;
    for(int i =0;i<8;i++)
        obj.Set(i,i%2);
    print(obj);
    std::cin.get();
}
#endif