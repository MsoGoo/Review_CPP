#include <iostream>
#include <string>
using namespace std;

//提前让编译器知道person 类的存在
template<class T1, class T2>
class Person;

//类外实现 
template<class T1, class T2>
void printPerson2(Person<T1, T2> p){
    cout <<"类外: Name: " << p.m_Name << ", Age: " << p.m_age << endl;
}

template<class T1, class T2>
class Person{
    //全局函数 类内实现
    // friend void printPerson(Person<T1, T2> p){
    //     cout << "Name: " << p.m_Name << ", Age: " << p.m_age << endl;
    // }

    //全局函数 类外实现
    //加空模板参数列表
    //如果是全局函数 的类外实现， 需要让编译器提前知道这个函数的存在
    friend void printPerson2<>(Person<T1, T2> p);

public:
    Person(T1 name, T2 age){
        this->m_age = age;
        this->m_Name = name;
    }

private:
    T1 m_Name;
    T2 m_age;
};

//1. 全局函数类内实现
void test01(){
    Person<string, int> P ("Tom" , 10);
    // printPerson(P);
    printPerson2(P);
}

int main(){
    test01();

    return 0;
}