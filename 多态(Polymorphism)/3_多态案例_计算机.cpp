#include <iostream> 
#include <string>
using namespace std;

//分别利用普通写法和多态写法来实现计算器

//多态好处：1.组织结构清晰 2.可读性强 3.前期和后期扩展以及维护性高

//普通写法
// class Calculator{
// private:

// public:
//     int m_Num1;
//     int m_Num2;

//     int getResult(string oper)
//     {
//         if (oper == "+")
//         {
//             return m_Num1 + m_Num2;
//         }
//         else if (oper == "-")
//         {
//             return m_Num1 - m_Num2;
//         }
//         else if (oper == "*")
//         {
//             return m_Num1 * m_Num2;
//         }

            //如果想扩展新的操作要修改源码
            //实际开发 提倡 开闭原则（扩展进行开放， 修改进行关闭）
//     }
// };

//多态计算器写法
class abstractCalculator{
private:

public:
    int m_A;
    int m_B;
    
    //这里用了纯虚函数，因为父类的getresult 用不着
    virtual int getResult() = 0;

};

//加法计算器类
class add_Calculator: public abstractCalculator{
private:

public:
    int getResult()
    {
        return this->m_A + this->m_B;
    }
};

//减法计算器类
class minus_Calculator: public abstractCalculator{
private:

public:
    int getResult()
    {
        return this->m_A - this->m_B;
    }
};

//乘法计算器类
class multiple_Calculator: public abstractCalculator{
private:

public:
    int getResult()
    {
        return this->m_A * this->m_B;
    }
};


void test01()
{   

    //普通计算器实现
    // Calculator c; 
    // c.m_Num1 = 10;
    // c.m_Num2 = 20; 
    // cout << " + : " << c.getResult("+") << endl;
    // cout << " - : " << c.getResult("-") << endl;
    // cout << " * : " << c.getResult("*") << endl;

    //多态计算器实现
    //多态使用条件： 父类指针或者引用子类对象 
    abstractCalculator *ABC = new add_Calculator;
    ABC->m_A = 10;
    ABC->m_B = 20;
    cout << "+ : " << ABC->getResult() << endl;
    delete ABC;  //指针销毁

    ABC = new minus_Calculator;
    ABC->m_A = 10;
    ABC->m_B = 20;
    cout << "- : " << ABC->getResult() << endl;
    delete ABC;  //指针销毁

    ABC = new multiple_Calculator;
    ABC->m_A = 10;
    ABC->m_B = 20;
    cout << "- : " << ABC->getResult() << endl;
    delete ABC;  //指针销毁
}

int main()
{
    test01();

    return 0;
}