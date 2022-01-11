#ifndef MYARRAY_HPP
#define  MYARRAY_HPP

#include <iostream>
using namespace std;

template<class T>
class MyArray{
private:
    T* pAddress;    //指针指向堆区开辟的真实数组

    int m_Capacity; //数组容量

    int m_Size;      //数组大小

public:
    //有参构造, 传入初始容量
    MyArray(int capacity)
    {   
        cout << "MyArray 有参构造调用。" << endl; 
        this -> m_Capacity = capacity;
        this -> m_Size = 0;
        this -> pAddress = new T[this -> m_Capacity];
    }   

    //operator = 防止浅拷贝问题
    MyArray& operator=(const MyArray& arr)
    {   
        cout << "MyArray 的 operator= 调用。" << endl; 
        //先判断原来堆区是否有数据，如果有，先释放
        if(this->pAddress != NULL)
        {
            delete []this -> pAddress;
            this -> pAddress = NULL;
            this -> m_Capacity = 0;
            this -> m_Size = 0;
        }

        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];  //深拷贝

        for(int i = 0; i < this->m_Size; ++i)
        {
            this -> pAddress[i] = arr.pAddress[i];
        }

        return *this;
    }


    //拷贝构造
    MyArray(const MyArray& arr)
    {   
        cout << "MyArray 拷贝函数调用。" << endl; 
        this -> m_Capacity = arr.m_Capacity;
        this -> m_Size = arr.m_Size;
        //this -> pAddress = arr.pAddress;   //浅拷贝会导致堆区的数据重复释放!!
        
        this -> pAddress = new T[arr.m_Capacity];  //深拷贝

        for(int i = 0; i < this->m_Size; ++i)
        {
            this -> pAddress[i] = arr.pAddress[i];
        }
    }

    //尾插法：
    void Push_Back(const T &val){
        //判断容量大小
        if(this->m_Size == this->m_Capacity)
        {
            cout << "No more space!" << endl;
            return;
        }

        this->pAddress[this->m_Size] = val;     //在数组末尾插入数据
        this->m_Size++;     //更新大小
    }

    //尾删法
    void Pop_Back()
    {   
        if(this->m_Size == 0)
        {
            cout << "It's empty." << endl;
            return;
        }

        this->m_Size--;     //直接让用户访问不到最后一个元素即可， 下次删除会覆盖该位置数值
    }

    //通过下标的方式来访问array
    T& operator[](int index)
    {
        return this->pAddress[index];
    }

    //返回数组容量
    int getCapacity()
    {
        return this->m_Capacity;
    }

    //返回数组大小
    int getSize()
    {
        return this->m_Size;
    }

    //析构函数
    ~MyArray(){
        cout << "MyArray 析构函数调用。" << endl; 
        if(this->pAddress != NULL)
        {
            delete [] this-> pAddress;
            this -> pAddress =  NULL;
        }
    }

};

#endif