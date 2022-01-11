//页面继承例子
#include <iostream>
using namespace std;


//--------------------------------------------不用继承的方法：-------------------------------------
// //JAVA 页面
// class Java
// {
//     public:

//     void header()
//     {
//         cout << "首页、公开课、登录、注册...(公共头部）" << endl;
//     }

//     void footer()
//     {
//         cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
//     }

        // void left()
        // {
        //     cout << "Java、Python、C++、...(公共分类列表）" << endl;
        // }

//     void content()
//     {
//         cout << "JAVA 学科视频" << endl;
//     }
// };

// //Python 页面
// class Python
// {
//     public:

//     void header()
//     {
//         cout << "首页、公开课、登录、注册...(公共头部）" << endl;
//     }

//     void footer()
//     {
//         cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
//     }

        // void left()
        // {
        //     cout << "Java、Python、C++、...(公共分类列表）" << endl;
        // }
//     void content()
//     {
//         cout << "Python 学科视频" << endl;
//     }
// };

// //c++ 页面
// class CPP
// {
//     public:

//     void header()
//     {
//         cout << "首页、公开课、登录、注册...(公共头部）" << endl;
//     }

//     void footer()
//     {
//         cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
//     }

        // void left()
        // {
        //     cout << "Java、Python、C++、...(公共分类列表）" << endl;
        // }

//     void content()
//     {
//         cout << "c++ 学科视频" << endl;
//     }
// };

// void test_0()
// {
//     cout << "Java 下载视频页面如下：" << endl;
//     Java ja;
//     ja.header();
//     ja.footer();
//     ja.content();

//     cout << "------------------------------" << endl;
//     cout << "Python 下载视频页面如下：" << endl;
//     Python Py;
//     Py.header();
//     Py.footer();
//     Py.content();

//     cout << "------------------------------" << endl;
//     cout << "C++ 下载视频页面如下：" << endl;
//     CPP cpp;
//     cpp.header();
//     cpp.footer();
//     cpp.content();

// }


//--------------------------------------------用继承的方法：-------------------------------------
//继承的好处： 减少重复代码
//语法： class 子类 : 继承方式 父类
//子类 也称 派生类
//父类 也称 基类

class BasePage
{
    public: 
    void header()
    {
        cout << "首页、公开课、登录、注册...(公共头部）" << endl;
    }

    void footer()
    {
        cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
    }

    void left()
    {
        cout << "Java、Python、C++、...(公共分类列表）" << endl;
    }
};

class Java : public BasePage
{
    public: 
    void content()
    {
        cout << "JAVA 学科视频" << endl;
    }
};


class Python : public BasePage
{
    public: 
    void content()
    {
        cout << "Python 学科视频" << endl;
    }
};

class CPP : public BasePage
{
    public: 
    void content()
    {
        cout << "C++ 学科视频" << endl;
    }
};



void test_0()
{
    cout << "Java 下载视频页面如下：" << endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.content();

    cout << "------------------------------" << endl;
    cout << "Python 下载视频页面如下：" << endl;
    Python Py;
    Py.header();
    Py.footer();
    Py.content();

    cout << "------------------------------" << endl;
    cout << "C++ 下载视频页面如下：" << endl;
    CPP cpp;
    cpp.header();
    cpp.footer();
    cpp.content();

}


int main()
{
    test_0();
    return 0;
}