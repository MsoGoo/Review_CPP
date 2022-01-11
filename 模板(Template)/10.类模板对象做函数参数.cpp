#include <iostream>
using namespace std;

//类模板对象做函数参数
//三种传入方式：

template<class T1, class T2> 
class Person{
private: 

public:
    Person(T1 name, T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    void who()
    {
        cout << "Name: " << this->m_Name << "，年龄: " << this->m_Age << endl;
    }

    T1 m_Name;
    T2 m_Age;
};

//1. 指定传入的类型 --直接显示对象的数据类型
void pringPerson_1(Person<string, int> &p){
    p.who();
}

void test01(){
    Person<string, int>p("Tom", 10);
    pringPerson_1(p);
}

//2. 参数模板化 --将对象中的参数变为模板进行传递
template<class T1, class T2> 
void pringPerson_2(Person<T1, T2> &p){
    p.who();
    // cout << "T1 类型为： " <<typeid(T1).name() << endl;   //显示T1 类型
    // cout << "T2 类型为： " <<typeid(T2).name() << endl;   //显示T2 类型， 不知道为什么不能正常显示
}

void test02(){
    Person<string, int>p("Ram", 20);
    pringPerson_2(p);

}

//3. 整个类模板化 -- 将这个对象类型模板化进行传递
template<class T>       //直接用T 代替 person类型
void pringPerson_3(T &p){
    p.who();
    cout << "T 类型为: " << typeid(T).name() << endl;
}

void test03(){
    Person<string, int>p("Bee", 5);
    pringPerson_3(p);

}


int main(){
    test01();
    test02();
    test03();

    return 0;
}