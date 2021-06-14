#pragma once
/*
	�ڹ���ģʽ�У������ڴ�������ʱ����Կͻ��˱�¶�����߼���������ͨ��ʹ��һ����ͬ�Ľӿ���ָ���´����Ķ���
	����ģʽ��Ϊһ�ִ���ģʽ��һ���ڴ������Ӷ���ʱ������ʹ�ã��ڴ����򵥶���ʱ������ֱ��new���һ��ʵ������Ĵ�����

	1.1���򵥹���ģʽ
	��Ҫ�ص�����Ҫ�ڹ����������жϣ��Ӷ�������Ӧ�Ĳ�Ʒ���������²�Ʒʱ����Ҫ�޸Ĺ����ࡣ
	ʹ�ü򵥹���ģʽ������ֻ��Ҫ֪������Ĳ�Ʒ�ͺžͿ��Դ���һ����Ʒ��

	ȱ�㣺�����༯�������в�Ʒ��Ĵ����߼��������Ʒ���ϴ󣬻�ʹ�ù������ķǳ�ӷ�ס�
*/
#include "Tank.h"
#include <iostream>
#include <string>
using namespace std;


//�����Ʒ������Ϣ
typedef enum
{
	Tank_Type_56,
	Tank_Type_96,
	Tank_Type_None
}Tank_Type;

//������
class TankFactory
{
public:
	//���ݲ�Ʒ��Ϣ��������Ĳ�Ʒ��ʵ��������һ�������Ʒ��
	Tank* createTank(Tank_Type type)
	{
		switch (type)
		{
		case Tank_Type_56:
			return new Tank56();
		case Tank_Type_96:
			return new Tank96();
		default:
			return nullptr;
		}
	}
};


int testSimpleFactory();
