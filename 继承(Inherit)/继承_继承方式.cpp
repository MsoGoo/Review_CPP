//继承方式： public, private, protected
//1. 父类里所有private的内容，子类都不能继承
//2. 如果是公共继承， 父类中公共属性的内容，子类中的属性仍为公共属性。 父类中保护权限的内容，子类中也为保护权限
//3. 如果是保护继承， 父类中 公共属性的内容，和保护权限的内容在子类中都为保护权限内容。
//4. 如果是私有继承， 父类中 公共属性的内容，和保护权限的内容在子类中都是私有权限内容。

#include "iostream"
using namespace std;

//继承方式
class Base1
{
    public:
        int m_A;
    protected:
        int m_B;
    private:
        int m_C;
    
};

//公共继承
class Son_1: public Base1
{
    public:

    void func()
    {
        m_A = 10;      //父类中公共权限成员 到子类中还是公共权限
        m_B = 10;      //父类中保护权限成员 到子类中还是保护权限
        //m_C = 10;      //父类中的私有权限成员 子类无法访问
    }
};

void test01()
{
    Son_1 s1;
    s1.m_A = 100;   
    //s1.m_B = 100;   //Son_1 中 保护权限内容在类外 不能访问！ 
}

//保护继承
class Son_2: protected Base1
{
    public:

    void func()
    {
        m_A = 10;      //父类中公共权限成员 到子类中为保护权限
        m_B = 10;      //父类中保护权限成员 到子类中为保护权限
        //m_C = 10;      //父类中的私有权限成员 子类无法访问
    }
};

void test02()
{
    Son_2 s2;
    //s2.m_A = 100;     //Son_2 中 保护权限内容在类外 不能访问！ 
    //s2.m_B = 100;   //Son_2 中 保护权限内容在类外 不能访问！ 
}

//私有继承
class Son_3: private Base1
{
    public:

    void func()
    {
        m_A = 10;      //父类中公共权限成员 到子类中变为私有权限
        m_B = 10;      //父类中保护权限成员 到子类中变为私有权限
        //m_C = 10;      //父类中的私有权限成员 子类无法访问
    }
};

void test03()
{
    Son_3 s3;
    
    //s3.m_A = 100;   //Son_3 中 私有权限内容在类外 不能访问！ 
    //s3.m_B = 100;   //Son_3 中 私有权限内容在类外 不能访问！ .
    //m_C = 10;       //父类中的私有权限成员 子类无法访问
}


class GrandSon3 : public Son_3
{
    public:
    
    void function()
    {
        //m_A = 100;  //父类是Son_3 因为 Son_3 private 继承了 Base1， 所以内容都为私有，子类无法访问。
    }
};

int main()
{
    
    return 0;
}