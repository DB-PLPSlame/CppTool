#pragma once
#include <iostream>
#include <string>
using namespace std;

//��Ʒ������
class Tank
{
public:
	Tank(const string& strType = "") :m_strType(strType)
	{
	}
	virtual const string& type() = 0;
protected:
	string m_strType;
};

//����Ĳ�Ʒ��
class Tank56 : public Tank
{
public:
	Tank56() :Tank("Tank56")
	{
	}

	const string& type() override
	{
		cout << m_strType.data() << endl;
		return m_strType;
	}
};

//����Ĳ�Ʒ��
class Tank96 : public Tank
{
public:
	Tank96() :Tank("Tank96")
	{
	}
	const string& type() override
	{
		cout << m_strType.data() << endl;
		return m_strType;
	}
};
