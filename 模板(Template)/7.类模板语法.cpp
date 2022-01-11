//建立一个通用类，类中的成员 数据类型可以不具体指定，用一个虚拟的类型来代表

#include <iostream>
#include <string>
using namespace std;

template<class NameType, class AgeType>
class Person{
public:
    Person(NameType name, AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson()
    {
        cout << "Name: " << this->m_Name << ", Age: " << this->m_Age << endl;
    }

    NameType m_Name;
    AgeType m_Age;
};

void test01()
{
    Person<string, int> p1("Tom", 20);
    p1.showPerson();
}


int main(){
    test01();


    return 0;
}

