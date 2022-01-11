//继承中的构造和析构顺序

#include <iostream>
using namespace std;

class Base{
    public:
    Base()
    {
        cout << "Base 构造函数！ " << endl;
    }

    ~Base()
    {
        cout << "Base 析构函数！~" << endl;
    }
};

class Son: public Base
{
    public: 
    Son()
    {
        cout << "Son 构造函数！ " << endl;
    }

    ~Son()
    {
        cout << "Son 析构函数！ " << endl;
    }
};

void test01()
{   
    Base base;

    cout << "---------------------" << endl;

    Son son;
}


int main(){
    test01();

    //继承中的构造和析构顺序：
    //先构造父类， 再构造子类
    //先析构子类， 再析构父类
    //析构顺序和构造顺序相反

    return 0;
}