#include <iostream>
using namespace std;

//普通函数和函数模板的调用规则
//1.如果普通函数和函数模板都能调用，优先调用普通函数
void myPrint(int a, int b){
    cout << "调用普通模板 ------" << endl;
}

template <class T>
void myPrint(T a ,T b){
    cout << "调用函数模板 ------" << endl;
}

template <class T>
void myPrint(T a ,T b, T c){
    cout << "调用函数模板_重载模板 ------" << endl;
}

void test01(){
    int a = 5;
    int b = 10;
    myPrint(a,b);          //调用普通模板
}

//2.可以通过空模板参数列表来强制调用函数模板
void test02(){
    int a = 5;
    int b = 10;
    myPrint<>(a,b);          //空模板 即：<> 里面不加任何类型
}

//3.函数模板也能重载
void test03(){
    int a = 5;
    int b = 10;
    int c = 15;
    myPrint(a,b,c);          //空模板 即：<> 里面不加任何类型
}

//4.如果函数模板能产生更好的匹配， 则优先调用函数模板
void test04(){
    char a = '1';
    char b = '2';

    myPrint(a,b);           //如果调用普通函数，则需要隐式类型转换，然而使用函数模板只要推导T类型即可，所以先用函数模板
}

//Note: 一般有函数模板，则不会写普通函数

int main()
{   
    test01();
    test02();
    test03();
    test04();


    return 0;
}