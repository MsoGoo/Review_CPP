//棱形继承（钻石继承）
//例如：  son1， son2 继承 Base， grandSon 继承 Son1， Son2
//棱形继承带来的主要问题就是 两个 子类继承两份相同数据， 然而我们只要一份数据，导致资源浪费
//可以用虚继承解决问题：   virtual public 父类
#include <iostream>
using namespace std;

//动物类
class Animal{
    public: 
        int m_Age;
};

//利用虚继承可以解决棱形继承的问题
//继承前加上关键词 virtual 变成虚继承
//animal类 成为虚基类
//羊类
class Sheep: virtual public Animal{

};

//驼类
class Camel: virtual public Animal{};

//草泥马
class Alpaca: public Sheep, public Camel{};

void test()
{
    Alpaca alpaca;
    //因为m_Age在sheep上有一份， Camel 上也有一份 所以 不明确
    //alpaca.m_Age = 18;
    
    //当灵性继承是，两个父类有相同数据，要加作用域做以区分
    alpaca.Sheep::m_Age = 18;
    alpaca.Camel::m_Age = 28;

    cout << "Alpaca.Sheep::m_Age: " << alpaca.Sheep::m_Age << endl;
    cout << "Alpaca.Camel::m_Age: " << alpaca.Camel::m_Age << endl;

    //但是我们只需要一份该数据， 棱形数据导致有两份数据，浪费资源。
    //在虚继承后可以直接以对象访问
    cout << "Alpaca, m_Age: " << alpaca.m_Age << endl;
    //在虚继承后，数据就只有一份所以 alpaca.Sheep::m_Age，  alpaca.Camel::m_Age 和 alpaca.m_age 为同一份数据
}


int main(){
    test();

    return 0;
}