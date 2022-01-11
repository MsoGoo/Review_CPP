//多继承语法

#include <iostream> 
using namespace std;


class Base_1{
    public: 
        int m_A;

        Base_1()
        {
            m_A = 100;
        }
};


class Base_2{
    public: 
        int m_A;

        Base_2()
        {
            m_A = 200;
        }
};

//语法： class 子类 : 继承方式 父类1， 继承方式 父类2，...
class Son: public Base_1, public Base_2
{
    public:
        int m_C;
        int m_D;

        Son()
        {
            m_C = 300;
            m_D = 400;
        }
};


void test()
{
    Son s;
    
    //可以用vs 开发。。。。 来看结构
    cout << "Size of Son: " << sizeof(s) << endl;

    //当父类中出现同名成员，需要加作用域区分
    //实际开发中不推荐多继承， 因为， 可能是不同两个人写的两个类，出现同名函数的概率较高, 就要一直加作用域， 会比较麻烦。
    cout << "Base 1, m_A: " << s.Base_1::m_A << endl;
    cout << "Base 2, m_A: " << s.Base_2::m_A << endl;
}

int main()
{ 
    test();

    return 0;
}