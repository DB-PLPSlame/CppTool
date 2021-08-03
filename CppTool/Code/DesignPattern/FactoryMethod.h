#pragma once
/*
	1.2����������ģʽ
	����һ����������Ľӿڣ�������ȥ������ʵ����ӿ�����ɾ���Ĵ��������������Ҫ�����µĲ�Ʒ�ֻ࣬��Ҫ��չһ����Ӧ�Ĺ����༴�ɡ�

	ȱ�㣺��Ʒ�����ݽ϶�ʱ����Ҫʵ�ִ����Ĺ����࣬�����������˴�������
*/
#include "Tank.h"
#include <iostream>
#include <string>
using namespace std;


//���󹤳��࣬�ṩһ�������ӿ�
class TankFactory
{
public:
	//�ṩ������Ʒʵ���Ľӿڣ����س����Ʒ��
	virtual Tank* createTank() = 0;
};

//����Ĵ��������࣬ʹ�ó��󹤳����ṩ�Ľӿڣ�ȥ��������Ĳ�Ʒʵ��
class Tank56Factory : public TankFactory
{
public:
	Tank* createTank() override
	{
		return new Tank56();
	}
};

//����Ĵ��������࣬ʹ�ó��󹤳����ṩ�Ľӿڣ�ȥ��������Ĳ�Ʒʵ��
class Tank96Factory : public TankFactory
{
public:
	Tank* createTank() override
	{
		return new Tank96();
	}
};


int testFactoryMethod();
