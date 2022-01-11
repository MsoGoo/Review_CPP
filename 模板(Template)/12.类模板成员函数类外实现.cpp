#include <iostream>
#include <string>
using namespace std; 

template<class T1, class T2>
class Person{
public:
    Person(T1 name, T2 age);
    // {
    //     this->m_Name = name;
    //     this->m_age = age;
    // }

    void Who();
    // {
    //     cout << "Name: " << m_Name << ", Age: " << m_age << endl;
    // }

    T1 m_Name;
    T2 m_age;
};

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

void test01(){
    Person<string, int> P1("Tom", 10);
    P1.Who();
}

int main(){
    test01();
    return 0;
}
