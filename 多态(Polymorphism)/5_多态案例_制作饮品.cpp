#include "iostream"
#include <string>
using namespace std;

class abstract_makeDrink{
private:
    //煮水
    virtual void boilWater() = 0; 

    //冲泡
    virtual void brew() = 0; 

    //倒入杯中
    virtual void pourInCup() = 0;

    //加入辅料
    virtual void add() = 0;


public:
    void makeDrink()
    {
        boilWater();
        brew();
        pourInCup();
        add();
    }
};

class coffee: public abstract_makeDrink{
private:
    //煮水
    void boilWater(){
        cout << "倒水呢！ -------" << endl;
    }

    //冲泡
    void brew(){
        cout <<  "泡咖啡豆呢！ -------" << endl;
    }

    //倒入杯中
    void pourInCup(){
        cout << "咖啡！ 杯里到！ -------" << endl;
    }

    //加入辅料
    void add(){
        cout << "加点枸杞！ -------" << endl;
    }

public: 

};

void doWork(abstract_makeDrink* abs)
{
    abs->makeDrink();
    delete abs;         //释放堆区数据！
}

void test01()
{
    doWork(new coffee);
}


int main()
{   
    test01();
    return 0;
}