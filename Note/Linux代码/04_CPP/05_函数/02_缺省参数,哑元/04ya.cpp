//��Ԫ����
#include <iostream>
using namespace std;

int add(int a){
    ++a;
    return a;
}
int add(int a,int/*��Ԫ*/){
    int old = a;
    ++a;
    return old;
}

int main(void)
{
    cout << add(10) << endl;//11
    cout << add(10,0) << endl;//10
    return 0;
}
