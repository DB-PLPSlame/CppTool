#include "Exception.h"
#include <iostream>
using namespace std;
using namespace Exception;


// https://blog.csdn.net/chenlycly/article/details/45013817
/*
	1����throw��˵��
	C++���������ӹؼ���throw(something)���ƣ��Ƕ�����������쳣��ȫ���������ơ�
	�������������£�
	void fun() throw() ��ʾfun�������׳��κ��쳣����fun���쳣��ȫ�ġ�
	void fun() throw(...) ��ʾfun�����׳��κ���ʽ���쳣��
	void fun() throw(exceptionType) ��ʾfunֻ���׳�exceptionType���͵��쳣��
	���磺
	void GetTag() throw(int); ��ʾֻ�׳�int�����쳣
	void GetTag() throw(int��char); ��ʾ�׳�in��char�����쳣
	void GetTag() throw(); ��ʾ�����׳��κ������쳣
	void GetTag() throw(...); ��ʾ�׳��κ������쳣
	��ô��void GetTag() throw(int); ��ʾֻ�׳�int�����쳣
	��������ô����أ�������ʾһ�����׳��쳣������һ���׳��쳣ֻ���׳�int���͡�����׳���int�����쳣������unexsetpion()�������˳�����
 */
double Devide(double x, double y) throw(ExceptionOperator)
{
	// ���һ��������ִ�й����В������쳣�ڱ������ھͱ� catch �鲶�񲢴�����ô���쳣�Ͳ��ᒁ����������ĵ����ߣ�Ҳ��Ϊ����һ��ĺ���������
	// ����쳣�ڱ�������û�б����������ͻᱻ������һ��ĺ�����
	if (y == 0)
		throw ExceptionOperator("devided by zero");

	cout << "in Devide" << endl;
	return x / y;
}

int CountTax(int salary) throw(int)
{
	try {
		if (salary < 0)
			throw - 1;
		cout << "counting tax" << endl;
	}
	catch (int) {
		cout << "salary < 0" << endl;
	}
	cout << "tax counted" << endl;
	return salary * 0.15;
}

int testException()
{
	double f = 1.2;
	try {
		CountTax(-1);
		f = Devide(3, 0);
		cout << "end of try block" << endl;
	}
	catch (const ExceptionOperator& e) {
		cout << e.msg << endl;
	}
	cout << "f = " << f << endl;
	cout << "finished" << endl;
	return 0;
}
