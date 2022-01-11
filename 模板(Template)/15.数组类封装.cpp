#include <iostream> 
#include <string>
#include "MyArray.hpp"
using namespace std;

void printIntArray(MyArray<int>& arr)
{
    for(int i = 0; i< arr.getSize(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//测试int数据类型
void test01(){
    // MyArray<int> arr_1(10);
    // MyArray<int> arr_2(arr_1);
    // MyArray<int> arr_3(100);
    
    // arr_3 = arr_1;

    // int num = 10;
    // arr_1.Push_Back(num);
    // arr_1.Pop_Back();
    // arr_1.Pop_Back();

    MyArray<int> arr_1(5);
    
    for(int i = 0; i < 5; ++i)
    {
        arr_1.Push_Back(i);
    }
    
    printIntArray(arr_1);
    cout << "Capacity: " << arr_1.getCapacity() << ", Size: " << arr_1.getSize() << endl;

    MyArray<int> arr_2(arr_1);
    printIntArray(arr_2);
    for(int i = 0; i < 5; ++i)
    {
        arr_2.Pop_Back();
    }
    cout << "Capacity: " << arr_2.getCapacity() << ", Size: " << arr_2.getSize() << endl;

}

//测试自定义类型：
class Person{
public: 
    Person(){};
    Person(string name, int age)
    {
       this->m_name = name;
       this->m_age = age; 
    }

    void who()
    {
        cout << "Name: " << this->m_name << ", Age: " << this->m_age << endl;
    }

    string m_name;
    int m_age;
};

void printPerson(MyArray<Person> arr)
{
    for(int i = 0; i < arr.getSize(); ++i)
    {
        arr[i].who();
    }
}

void test02()
{   
    MyArray<Person> arr(10);
    Person p1("Tom", 10);
    Person P2("Joe", 5);
    Person P3("Steven", 15);


    //插入数据：
    arr.Push_Back(p1);
    arr.Push_Back(P2);
    arr.Push_Back(P3);
    printPerson(arr);
}


int main(){
    //test01();
    test02();
    return 0;
}

