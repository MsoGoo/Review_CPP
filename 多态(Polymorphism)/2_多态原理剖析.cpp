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
        //当子类重写父类虚函数是， 子类中的虚函数表 内部 会替换成 子类的虚函数地址
        void sound()
        {
            cout << "Miaoooo ~ " << endl;
        }
};

void Speak(Animal &animal) 
{
    animal.sound();
}

void test01()
{
    Cat cat;
    //因为传入的是cat 所以调用cat 的虚函数表， 在加virtual 和 重写函数后， cat 的虚函数表被覆盖
    Speak(cat);
}

void test02()
{
    //没在sound（）前加virtual的时候， Animal 类 的size 是 1.  （类的size 是 1 )   
    //加virtual之后， Animal 类 的size 是 4. （多了个指针， 虚函数(表)指针， virtual function pointer(vfptr)
    //vfptr 指向 vftable， vftable（虚函数表）表内记录了虚函数地址
    cout << "Size of Animal: " << sizeof(Animal) << endl;     

    cout << "Size of Cat: " << sizeof(Cat) << endl;
}


int main(){
    test01();
    test02(); 

    return 0;
};
