//��������
#include <iostream>
using namespace std;

int main(void)
{
    bool b = false;
    cout << b << endl;//0
    //���������Ʒ�boolalpha,���ַ�����ʽ��ӡbool
    cout << boolalpha << b << endl;//false
    b = 100;
    cout << b << endl;//true
    b = 3.14;
    cout << b << endl;//true	
    b = "hello world";
    cout << b << endl;//true
    char* p = NULL;//NULL==>(void*)0
    b = p;
    cout << b << endl;//false
    return 0;
}
