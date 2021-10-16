/*
	ԭ��ģʽ����ԭ��ʵ��ָ��������������࣬����ͨ��������Щԭ�ʹ����µĶ���
		ͨ�׵Ľ����ǵ���Ҫ����һ���µ�ʵ��������ʱ�����Ǹպ���һ��ʵ�������󣬵����Ѿ����ڵ�ʵ���������ֲ���ֱ��ʹ�á���������¿���һ�����е�ʵ�����������ã����ܻ�����㡣
	
	�������ο��Կ���ʹ��ԭ��ģʽ��
		��newһ�����󣬷ǳ���������ʱ������ʹ��ԭ��ģʽ�����и���һ�����󡣱��紴������ʱ�����캯���Ĳ����ܶ࣬���Լ��ֲ���ȫ��֪��ÿ�����������壬
		�Ϳ���ʹ��ԭ��ģʽ������һ���µĶ��󣬲���ȥ��ᴴ���Ĺ��̡�

		����Ҫnewһ���µĶ��������������еĶ������𲻴����ǾͿ���ֱ�Ӹ���һ�����еĶ���Ȼ���Լ��޸ġ�
		����Ҫһ�����󸱱�ʱ��������Ҫ�ṩ��������ݣ�ͬʱ����Ҫ�����ⲿ�����ݶ�������޸ģ��ǾͿ���һ�����󸱱����ⲿʹ�á�
 */


 /*
 * �ؼ����룺������return new className(*this);
 */
#include <iostream>

using namespace std;

//�ṩһ�������¡���ࡣ
class Clone
{
public:
	virtual Clone* clone() = 0;
	virtual void show() = 0;
};

//�����ʵ����
class Sheep :public Clone
{
public:
	Sheep(int id, string name) :Clone(),
		m_id(id), m_name(name)
	{
		cout << "Sheep() id address:" << &m_id << endl;
		cout << "Sheep() name address:" << &m_name << endl;
	}
	~Sheep()
	{
	}
	//�ؼ����뿽�����캯��
	Sheep(const Sheep& obj)
	{
		this->m_id = obj.m_id;
		this->m_name = obj.m_name;
		cout << "Sheep(const Sheep& obj) id address:" << &m_id << endl;
		cout << "Sheep(const Sheep& obj) name address:" << &m_name << endl;
	}
	//�ؼ������¡����������return new Sheep(*this)
	Clone* clone()
	{
		return new Sheep(*this);
	}
	void show()
	{
		cout << "id  :" << m_id << endl;
		cout << "name:" << m_name.data() << endl;
	}

private:
	int m_id;
	string m_name;
};

int testPrototype()
{
	Clone* s1 = new Sheep(1, "abs");
	s1->show();
	Clone* s2 = s1->clone();
	s2->show();

	delete s1;
	s1 = nullptr;
	delete s2;
	s2 = nullptr;
	return 0;
}
