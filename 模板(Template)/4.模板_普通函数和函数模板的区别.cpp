//普通函数调用时可以发生自动类型转换 （隐式类型转换）
//函数模板调用时，如果利用自动类型推导， 不会发生隐式类型转换
//如果利用显示指定类型的方式，可以发生隐式类型转换  

#include <iostream>
using namespace std;

//普通函数
int myAdd_01(int a, int b)
{
    return a + b;
}

//函数模板
template<class T>
T myAdd_02(T a, T b)
{
    return a + b;
}

void test01()
{
    int a = 10;
    int b = 20;
    cout << myAdd_01(a,b) << endl;          //正常输出
    char c = 'c';
    cout << myAdd_01(a,c) << endl;          //把c 转成了 int 类型 （ASCII Code)
    

    //自动类型推导
    cout << myAdd_02(a, b) << endl;
    //cout << myAdd_02(a,c) << endl;        //不能自动类型推导

    cout << myAdd_02<int>(a,c) << endl;     //指定类型即可运行
    cout << myAdd_02<char>(a,c) << endl;    
}



int main(){
    test01();
    
    return 0;
}