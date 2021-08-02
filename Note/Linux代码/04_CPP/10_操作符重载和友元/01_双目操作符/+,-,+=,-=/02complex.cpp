//'+='��'-='
#include <iostream>
using namespace std;

class Complex{
public:
    Complex(int r,int i):m_r(r),m_i(i){}
    void print(void)const{
        cout << m_r << '+' << m_i << 'i' << endl;
    }
    Complex& operator+=(const Complex& c){
        m_r += c.m_r;
        m_i += c.m_i;
        return *this;
    }
    //��Ԫ����������Է�������ڲ�,���ǲ�������,
    //Ҳû��thisָ��
    friend Complex& operator-=(Complex& l,const Complex& r){
        l.m_r -= r.m_r;
        l.m_i -= r.m_i;
        return l;	
    }
private:
    int m_r;//����ʵ��
    int m_i;//�����鲿
};

int main(void)
{
    Complex c1(1,2);
    Complex c2(3,4);
    Complex c3(5,6);

    c1 += c2;//c1.operator+=(c2)
    c1.print();//4+6i
    (c1 += c2) = c3;
    c1.print();//5+6i

    c3 -= c2;//operator-=(c3,c2)
    c3.print();//2+2i
    return 0;
}

