#include <iostream>
using namespace std; 

//当类模板碰到继承时候 注意：
//当子类继承的父类是一个模板时， 子类在声明时，要指定父类中的T类型
//如果不指定，编译器无法给子类分配内存
//如果想灵活指定父类中T 的类型， 子类也要变成类模板
template<class T>
class Base 
{                     
    T m;
};


//class Son: public Base   错误，必须要知道父类中T的类型，才能用子类
class Son: public Base<int>
{
     
};

void test01()
{
    Son s1;
}

template<class T1, class T2>
class Son2: public Base<T2>{        //传入父类模板的类型为T2
public:
    Son2()
    {
        cout << "T1 类型: " << typeid(T1).name() << endl;
        cout << "T2 类型: " << typeid(T2).name() << endl;
    }

    T1 obj;
};

void test02()
{
    Son2<int, char> s2;         //char 是父类使用的类型（T2), int 是子类使用的类型（T1）   

}


int main(){
    test02();
    return 0;
}