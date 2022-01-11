//当子类和父类出现同名成员，怎么通过子类对象访问子类或父类中的同名数据。
//1. 访问子类同名成员。 直接访问即可
//2. 访问父类同名成员， 需要加作用域  

#include <iostream>
#include <string>
using namespace std;

class Base{
    public:
    Base()
    {
        m_A = 200;
    }

    void func()
    {
        cout << "This is Base" << endl;
    }

    void func(int a)
    {
        cout << "This is Base 100" << endl;
    }

    int m_A;
};

class Son: public Base{
    public:
    Son()
    {
        m_A = 100;
    }

    void func()
    {
        cout << "This is Son" << endl;
    }

    int m_A;
};

//同名成员属性处理方式
void test01() 
{   
    Son s;
    cout <<"Son 下 m_A: " << s.m_A << endl;
    
    //如果通过子类对象访问父类同名成员，需要加作用域
    cout <<"Base 下 m_A: " << s.Base::m_A << endl; 
}

//同名成员函数的处理方式
void test02()
{
    Son s;
    s.func();

    //如果通过子类对象访问父类同名函数， 一样加作用域
    s.Base::func();

    //如果子类中出现和父类同名的成员函数，那么子类中会隐藏父类中所有的同名函数包括（重载函数）
    //s.func(100);
    s.Base::func(100);
}

int main()
{
    test02();

    return 0;
}