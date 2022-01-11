#include "Person13.h"

//构造函数类外实现:
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age){
        this->m_Name = name;
        this->m_age = age;
}

//成员函数类外实现：
template<class T1, class T2>
void Person<T1, T2>::Who(){
    cout << "Name: " << m_Name << ", Age: " << m_age << endl;
}

