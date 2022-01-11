#include <iostream>
using namespace std;

template<class Element_1, class Element_2>
void Output(Element_1 E1, Element_2 E2)
{
    cout << E1 << endl;

    cout << E2 << endl;
}


void test()
{   
    string A = "abc";
    int b = 123;   
    Output<string, int>(A,b);

}

int main()
{   
    test();
    return 0;
}