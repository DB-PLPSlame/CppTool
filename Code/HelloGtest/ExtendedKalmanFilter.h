#pragma once
#include <iostream>


// gmock ����C++��̬���ƽ��й�����ֻ���麯�����ܱ�mock
class ExtendedKalmanFilter
{
public:
	//virtual int Add(int a, int b) = 0;
	virtual int Add(int a, int b)
	{
		return a + b;
	}

	virtual int NoChange(int a)
	{
		return a;
	}

	virtual bool Pass()
	{
		return false;
	}

	void Print()
	{
		std::cout << "Print......" << std::endl;
	}
};
