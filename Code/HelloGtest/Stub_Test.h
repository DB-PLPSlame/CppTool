#pragma once


// ʹ��VADDR()��ݵػ�ȡ�麯����ַ�� ���ڹ���ʵ�ֲ��õ�gcc/g++��ת��������ĿǰӦ��ֻ֧��gcc/g++������
class StubTest
{
public:
	virtual int Add(int a, int b)
	{
		return a + b;
	}

	int NoChange(int a)
	{
		a += 100;
		return a;
	}

	bool Pass()
	{
		return false;
	}
};
