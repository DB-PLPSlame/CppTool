#include "pch.h"
#include "Move.h"
#include <iostream>
using namespace std;


String foo(void) {
	String str("Hello, World !");
	return str;
}

// �ƶ�����
void Test_move()
{
	String a("Hello, C++11 !"), b("Hello, C++14 !");
	cout << "-------- 1 --------" << endl;
	String c = a; // �����
	cout << a << endl;
	cout << c << endl;
	cout << "-------- 2 --------" << endl;
	c = b; // ���ֵ
	cout << b << endl;
	cout << c << endl;
	cout << "-------- 3 --------" << endl;
	String d = foo(); // �ƶ�����
	cout << d << endl;
	cout << "-------- 4 --------" << endl;
	c = foo(); // �ƶ���ֵ
	cout << c << endl;
	cout << "-------- 5 --------" << endl;
	String e = move(a); // �ƶ�����
	cout << e << endl;
	cout << "-------- 6 --------" << endl;
	c = move(b); // �ƶ���ֵ
	cout << c << endl;
	cout << "-------- 7 --------" << endl;
}

