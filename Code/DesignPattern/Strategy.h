#pragma once
/*
* �ؼ����룺ʵ��ͬһ���ӿڡ�
* ���´���ʵ���У�����Ϸ��ɫ��ͬ�Ĺ�����ʽΪ��ͬ�Ĳ��ԣ���Ϸ��ɫ��Ϊִ�в�ͬ���ԵĻ�����ɫ��

	����ģʽ��ָ����һϵ�е��㷨�������ǵ�����װ����������ʹ���ǿ��Ի����滻��ʹ���㷨���Զ�����ʹ�����Ŀͻ��˶��仯��
	Ҳ��˵��Щ�㷨����ɵĹ���������һ���ģ�����ӿ�Ҳ��һ���ģ�ֻ�ǲ�ͬ�Ĳ���Ϊ���𻷾���ɫ������ɫ���ֳ���ͬ����Ϊ��
	�����ʹ�ô�����if...else��ʹ�ò���ģʽ���Խ��͸��Ӷȣ�ʹ�ô��������ά����

	ȱ�㣺������Ҫ��������Ĳ����࣬������Щ�����඼Ҫ�ṩ���ͻ��ˡ�
	[������ɫ]  ����һ������������ã����ո��ͻ��˵��á�
*/

#include <iostream>

using namespace std;

//��������࣬�ṩһ���ӿ�
class Hurt
{
public:
	virtual void blood() = 0;
};

//����Ĳ���ʵ���࣬����ʵ�ֽӿڣ� Adc������ͨ����
class AdcHurt : public Hurt
{
public:
	void blood() override
	{
		cout << "Adc hurt, Blood loss" << endl;
	}
};

//����Ĳ���ʵ���࣬����ʵ�ֽӿڣ� Apc���ܹ���
class ApcHurt : public Hurt
{
public:
	void blood() override
	{
		cout << "Apc Hurt, Blood loss" << endl;
	}
};

/*
  ʵ�ַ�ʽһ��������ɫ�࣬ ��Ϸ��ɫսʿ������һ��������ָ�������
 */
class Soldier
{
public:
	Soldier(Hurt* hurt) :m_pHurt(hurt)
	{
	}
	//�ڲ�ͬ�Ĳ����£�����Ϸ��ɫ���ֳ���ͬ�Ĺ���
	void attack()
	{
		m_pHurt->blood();
	}
private:
	Hurt* m_pHurt;
};

/*
  ʵ�ַ�ʽ����������ɫ�࣬ ��Ϸ��ɫ��ʦ������һ�����Ա�ǩ������
 */
typedef enum
{
	Hurt_Type_Adc,
	Hurt_Type_Apc,
	Hurt_Type_Num
}HurtType;

class Mage
{
public:
	Mage(HurtType type)
	{
		switch (type)
		{
		case Hurt_Type_Adc:
			m_pHurt = new AdcHurt();
			break;
		case Hurt_Type_Apc:
			m_pHurt = new ApcHurt();
			break;
		default:
			break;
		}
	}
	~Mage()
	{
		delete m_pHurt;
		m_pHurt = nullptr;
		cout << "~Mage()" << endl;
	}

	void attack()
	{
		m_pHurt->blood();
	}
private:
	Hurt* m_pHurt;
};

/*
  ʵ�ַ�ʽ����������ɫ�࣬ ��Ϸ��ɫ�����֣�ʵ��ģ�崫�ݲ��ԡ�
 */
template<typename T>
class Archer
{
public:
	void attack()
	{
		m_hurt.blood();
	}
private:
	T m_hurt;
};

int testStrategy();
