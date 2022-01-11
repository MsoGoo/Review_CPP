//静态多态： 函数重载， 运算符重载， 复用函数名
//动态多态： 派生类和虚函数实现运行时多态

//静态多态和动态多态的区别：
//静态多态的函数地址早绑定 - 编译阶段确定函数地址
//动态多态 则在运行时 确定函数地址

#include <iostream>
using namespace std;



class Animal{
    public:
        virtual void sound()
        {
            cout << "......" << endl;
        }
};


class Cat: public Animal{
    public:
        //重写： 函数返回值， 函数名， 参数列表 完全相同。 
        void sound()
        {
            cout << "Miaoooo ~ " << endl;
        }
};



//动态多态满足条件
//1. 要有继承关系
//2. 子类要重写父类的虚函数

//动态多态
//父类的指针或者引用 指向子类对象 ！！   Animal & animal = cat

//执行说话的函数  //传入的是父类的引用  Animal & animal = cat;  C++ 允许父子类转换
//地址早绑定   在编译阶段确定函数地址
//如果想执行让猫说话，函数地址则不能提前绑定，要在运行阶段绑定 （地址晚绑定）
void Speak(Animal &animal) 
{
    animal.sound();
}


void test01()
{
    Cat cat;
    Speak(cat);
}


int main(){
    test01();
    
    return 0;
};
