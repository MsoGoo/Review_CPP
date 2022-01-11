//C++ 提供两种模板机制： 函数模板和类模板
//函数模板： 建立通用函数，函数返回值类型和形参类型 可以不具体定制， 用虚拟的类型来代表
//函数声明定义： template<typename T> 
//template -- 声明创建模板;   
//typename -- 表明其后面的符号是一种数据类型，可以用class 代替； 
//T -- 通用数据类型，名称可以自定义，通常为大写字母

#include <iostream>
using namespace std;

//函数模板
template<typename T> //声明一个模板， 告诉编译器后面代码中的T不要报错，T是一个通用数据类型
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp; 
}


//整形交换函数
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;

    //位运算, 仅使用int
    // a = a^b;
    // b = a^b;
    // a = a^b;
}

void swapDouble(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

void test()
{
    // int a = 10;
    // int b = 20;
    // cout << "a = " << a << ", b = " << b << endl;
    // swap(a, b);
    // cout << "a = " << a << ", b = " << b << endl;

    // double a = 10.5;
    // double b = 20.5;
    // cout << "a = " << a << ", b = " << b << endl;
    // swapDouble(a, b);
    // cout << "a = " << a << ", b = " << b << endl;

    float c = 1.234;
    float d = 2.345;
    cout << "c = " << c << ", d = " << d << endl;
    //这里直接放入 c,d ==> 自动类型推导
    mySwap(c, d);
    cout << "c = " << c << ", d = " << d << endl;

    //显示指定类型： 
    mySwap<float>(c,d);
    cout << "c = " << c << ", d = " << d << endl;
}


int main()
{   
    test();
    return 0;
}