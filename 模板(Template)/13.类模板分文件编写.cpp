//问题： 类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到
//解决方法：  
//1.直接包含cpp源文件
//2.将声明和实现写到同一个文件中，后缀改为hpp


#include <iostream>
#include <string>
//#include "Person13.cpp"
//如果只是包含.h 文件， 因为编译器不会为!!! 在未调用前,为类模板生成成员函数， 所以导致cpp里的函数被编译器忽略 （编译阶段被忽略） 
//如果直接包含.cpp 文件，因为.cpp 文件中 include .h 文件 所以 编译器能生成所有需求文件.

//第二种方法： 将.h 和 .cpp内容写道一起，后缀改为.hpp 文件。  通常包含类模板的文件命名为 .hpp    //常规使用方法
#include "Person13.hpp"

using namespace std; 


void test01()
{
    Person<string, int> p1("Tom", 10);
    p1.Who();
}


int main(){
    test01();
    return 0;
}
