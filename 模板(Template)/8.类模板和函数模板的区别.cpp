#include <iostream> 
using namespace std;

template<class NameType, class AgeType = int>   //设置默认Age type为整形
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

//1. 类模板没有自动类型推导使用方法
void test01(){
    //Person p1("Tom", 20);   //错误
    Person<string, int> p1("Tom", 20);
    p1.showPerson();
}

//类模板在模板参数列表中可以有默认参数
void test02(){
    Person<string>p ("HELLO", 10);  //在类模板参数列表中已设置有agetype 的数据类型，所以不用加int
    Person<string, double>p_2 ("GG", 20.5);  //虽然设置了默认数据类型，但是依然能够修改传入的参数且不报错.
    p.showPerson();
    p_2.showPerson();
}


int main(){
    test01();
    test02();

    return 0;
}

