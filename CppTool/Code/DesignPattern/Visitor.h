/*
	ģʽ����
	������ģʽ��Visitor������ʾһ��������ĳ����ṹ�еĸ���Ԫ�صĲ�������ʹ������ڲ��ı��Ԫ�ص����ǰ���¶�����������ЩԪ�ص��²�����
	ģʽ����
	    ������ģʽ���������ݽṹ����ȶ���ϵͳ
		�������ݽṹ�����������ݽṹ֮�ϵĲ���֮�����Ͻ��ѿ���ʹ�ò������Ͽ���������ɵ��ݻ���
		������ģʽ��Ŀ����Ҫ�Ѵ�������ݽṹ������������������ϵͳ�бȽ��ȶ������ݽṹ����������仯���㷨�Ļ���ʹ�÷�����ģʽ���ǱȽϺ��ʵģ���Ϊ������ģʽʹ���㷨���������ӱ�ø����ס���֮��Ȼ��
	https://www.cnblogs.com/wzxNote/p/13278443.html
 */

#include <iostream>
#include <vector>
#include <list>
#include <string>

class Action;
class Person
{
public:
	Person(const std::string& type) : m_Type(type) {}
	virtual void Accept(Action* action) = 0;

	std::string Type()
	{
		return m_Type;
	}
protected:
	std::string m_Type;
};

class Man : public Person
{
public:
	Man() : Person("����") {}
	virtual void Accept(Action *action);
};

class Woman : public Person
{
public:
	Woman() : Person("Ů��") {}
	virtual void Accept(Action *action);
};

class Action
{
public:
	Action(const std::string& type) : m_Type(type) {}
	virtual ~Action() {}
	virtual void PerformanceMan(Man* man) {};
	virtual void PerformanceWoman(Woman* woman) {};

protected:
	std::string     m_Type;
};

class Success : public Action
{
public:
	Success() :Action("�ɹ�") {}

	void PerformanceMan(Man* man) override
	{
		std::cout << man->Type() << this->m_Type << "ʱ��ı���" << std::endl;
	}

	void PerformanceWoman(Woman* woman) override
	{
		std::cout << woman->Type() << this->m_Type << "ʱ��ı���" << std::endl;
	}
};


class ObjectStruct
{
public:
	void Display(Action* action)
	{
		for (auto person : m_Person)
		{
			person->Accept(action);
		}
	}

	void Attach(Person *person)
	{
		m_Person.push_back(person);
	}

	void Detach(Person *person)
	{
		m_Person.remove(person);
	}

	std::list<Person*>       m_Person;
};


int testVisitor();
