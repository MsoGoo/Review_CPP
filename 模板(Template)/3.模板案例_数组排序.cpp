//实现通用 对数组进行排序的函数
//规则: 从大到小
//算法： 选择
//测试 char， int数组
#include <iostream>
using namespace std;

template <class T>
void mySwap(T &a, T&b)
{
    T temp = a;
    a = b;
    b = temp;
}


template<class T>
void sort(T A[], int length)    
{   
    for(int i = 0; i < length; ++i)
    {
        int max = i;
        for(int j = i+1; j< length; ++j)
        {
            if (A[max] < A[j])
            {
                max = j;
            }
        }

        if(max != i)
        {   
            swap(A[i], A[max]);
        }

    }
}

void test01()
{
    char charArr[] = {'a', 'v', 'c', 'e', 'f'};    //char 数组也能写成： char charArr[] = "asdhkjdfs";
    int intArr[] = {3,4,2,1,5,6,1};
    sort(charArr, (sizeof(charArr)/sizeof(charArr[0]))  );
    sort(intArr,  (sizeof(intArr)/sizeof(intArr[0])) );

    for(int i = 0; i < (sizeof(charArr)/sizeof(charArr[0])); ++i)
    {
        cout << charArr[i] << "   ";
    }

    cout << endl; 

    for(int i = 0; i < (sizeof(intArr)/sizeof(intArr[0])); ++i)
    {
        cout << intArr[i] << "   ";
    }

}

int main()
{
    test01();

    return 0;
}