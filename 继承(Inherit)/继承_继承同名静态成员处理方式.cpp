//继承中同名的静态成员在子类对象上如何访问
//静态成员和非静态成员出现同名， 处理方式一致： 访问子类同名成员，直接访问。 访问父类同名成员，加作用域

#include "iostream"
using namespace std;

class Base{
    public:
    static int m_A;     //静态成员属性特点： 编译阶段 分配内存， 所有对象共享同一份数据，类内声明，类外初始化！

    static void func()
    {
        cout << "Base" << endl;
    }
};
int Base::m_A = 100;


class Son: public Base{
    public:
    static int m_A;

    static void func()
    {
        cout << "Son" << endl;
    }
};
int Son::m_A = 200;

//同名静态成员属性    //静态成员访问方式有两种
void test01()
{   
    //通过对象访问数据  
    Son s;
    cout << "通过对象访问： " << endl;
    cout << "Son 下 m_A: " << s.m_A << endl;
    cout << "Base 下 m_A: " << s.Base::m_A << endl;

    //通过作用域直接访问数据
    cout << "通过类名访问： " << endl;
    cout << Son::m_A << endl;
    cout << Base::m_A << endl;
}

//同名静态成员函数
void test02()
{
    Son s;
    cout << "通过对象访问: " << endl;
    s.func();
    s.Base::func();

    cout << "通过类名访问：" << endl;
    Son::func();
    Base::func();
}

int main()
{
    //test01();
    test02();

    return 0;
}