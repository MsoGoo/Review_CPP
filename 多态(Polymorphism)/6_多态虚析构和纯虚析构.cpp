//如果子类中有属性为开辟到堆区， 父类指针在释放时候无法调用子类析构代码
//解决方法： 将父类中的析构函数改为虚析构 或者 纯虚析构

//虚析构和纯虚析构 共性：
//1: 都可以解决父类指针释放子类对象
//2. 都要有具体的函数实现

//虚析构和纯虚析构区别： 
//如果是纯虚析构， 不能实例化对象

//虚析构语法： virtual ~类名(){}
//纯虚析构语法： virtual ~类名(){}= 0,  类外： 类名::~类名(){}

#include "iostream"
#include <string>
using namespace std;

class Animal{ 
private:

public: 
    Animal(){
        cout << "Animal 构造函数调用。" << endl;
    }

    //纯虚函数
    virtual void speak() = 0;

    //加入virtual后， 析构父类指针时， 就会执行子类析构函数
    // virtual ~Animal()
    // {
    //     cout << "Animal 析构函数调用。" << endl; 
    // }

    //纯虚析构
    virtual ~Animal() = 0;
};
//Animal 下的纯虚析构，要类外声明
Animal::~Animal(){
    cout << "Animal 纯虚析构调用" << endl;
}

class Cat: public Animal{
private:
    string *m_Name;

public: 
    Cat(string name)
    {   
        cout << "Cat 构造函数调用" << endl;
        m_Name = new string(name);
    }

    //重写纯虚函数
    void speak()
    {
         cout << *m_Name << " 猫在说话` " << endl;
    }
    
    ~Cat()
    {
        if(m_Name != NULL)
        {   
            cout << "Cat 析构函数调用" << endl; 
            delete m_Name;
            m_Name = NULL;
        }
    }
};


void test()
{   
    Animal* animal = new Cat("TOM");
    animal->speak();

    //父类指针在析构时候不会调用子类中的析构函数， 导致子类中如果有堆区属性，就会出现内存泄漏 
    delete animal;


}

int main(){   
    test();
    return 0;
}
