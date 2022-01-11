//继承中的对象模型  

#include <iostream>
using namespace std;

class Base
{
    public:
        int a;
    
    protected:
        int b;
    
    private:
        int c;

};

class Son: public Base
{
    public: 
        int d;
};

int main()
{
    Son son;
    //父类中所有非静态成员都会被继承，即使是private！
    //父类中私有成员属性 被编译器隐藏，所以访问不到，但是被继承！
    cout << "Size of son: " << sizeof(son) << endl;

    //windows 键， 搜 VS 开发人员命令工具    //管理员权限打开
    //复制当前文件路径    (检查文件所在盘符位置，如果不匹配，先跳转盘符 例： F:)
    // cd C:\Users\60491\Desktop\UCR\CS100\C++_Review     //跳转到当前文件所在文件夹
    // dir    // 查看当前文件夹所包含的文件
    // c1 /d1 reportSingleClassLayoutSon 继承_继承中的对象模型.cpp 

    return 0;
}