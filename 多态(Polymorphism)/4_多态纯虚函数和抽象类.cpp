#include "iostream"
using namespace std; 

//纯虚函数 语法： virtual 返回值类型 函数名 (参数列表) = 0
//当类中有了纯虚函数， 这个类也就被成为抽象类 

//抽象类特点： 1. 无法实例化对象   2. 子类必须重写抽象类中的纯虚函数， 不然也属于抽象类


class Base{
private:

public: 
    //纯虚函数
    //类中只要有一个纯虚函数就是抽象类， 不能实例化对象
    //子列必须重写纯虚函数，不然也是抽象类！  
    virtual void func() = 0; 
}; 

class Son: public Base{
private: 

public: 
    void func(){
        cout << "纯虚函数重写! " << endl;
    }
};


void test01()
{   
    //纯虚函数无能实例化对象， 不论是栈区或者堆区
    //Base b; 
    //new Base;

    Base* base = new Son; 
    base -> func();


}

int main(){
    test01();
    return 0;
}