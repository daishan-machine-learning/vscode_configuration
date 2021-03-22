
#ifndef STORAGE_H
#define STORAGE

#include<iostream>
template<typename T>
class Storage{
private:
    T m_data[8];
public:
    Storage(){

    }
    void Set(int index,const T& value){
        m_data[index] = value;
    }

    const T& Get(int index)const{   // 如果是const函数，那么返回值要么是按值传递，要么返回是常引用
        return m_data[index];
    }
};

template<typename T>
void print(const Storage<T>& obj){
    for(int i =0;i<8;i++)
        std::cout<<obj.Get(i)<<" ";
}

#endif