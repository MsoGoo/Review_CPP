#include <iostream>
using namespace std;


//函数模板注意事项
template<class T>   // typename 可以替换成 class
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}


//1.自动类型推导， 必须推导出一致的数据类型T 才能使用模板
void test01()
{
    int a = 10;
    int b = 20;
    mySwap(a, b);
    cout << "a: " << a << ", b: " << b << endl;

    char c = 'c';
    //mySwap(a,c);  推导不出一致的T类型
}


//2.模板必须要确定出T的数据类型可以使用
template <class T> 
void func(){
    cout << "func 函数调用。" << endl;
} 

void test02(){
    func<int>();        //必须要确定数据类型之后才能使用！ 如果不加上<int>， 则不能调用
}  

int main()
{
    test01();
    test02();
    return 0;
}