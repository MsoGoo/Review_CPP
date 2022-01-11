#include <iostream>
#include <string>
using namespace std;

//有些特定的数据类型，需要具体化实现方式
//c++ 提供模板的重载，为特定的类型提供具体化的模板

class Person{
private:

public: 
    Person (string name, int age){
        this->name = name;
        this->age = age;
    }

    string name;
    int age;
};

//对比两个数据是否相等
template<class T>
bool myCompare(T &a, T &b)
{
    if(a == b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//方法一： 利用具体化person 的版本来实现代码，具体化优先调用
template<> 
bool myCompare(Person &p1, Person &p2)
{
    if(p1.name == p2.name && p1.age == p2.age)
    {
        return true;
    }
    else 
    {
        return false;
    }    
}

//方法2： 在person class 里重载 == operator  （这里不演示）

void test01(){
    int a = 10;
    int b = 20;

    bool res = myCompare(a,b);
    if(res)
    {
        cout <<  "a == b " << endl;
    }
    else 
    {
        cout << "a != b " << endl;
    }
}

void test02(){
    Person p1("Tom", 10);
    Person p2("Tom", 10);

    bool res = myCompare(p1,p2);

    if(res)
    {
        cout <<  " a == b " << endl;
    }
    else 
    {
        cout << "a != b " << endl;
    }
}


int main(){
    test01();
    test02();
    return 0;
}