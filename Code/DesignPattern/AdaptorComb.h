#pragma once
#include <iostream>
using namespace std;

/*
* �ؼ����룺�������̳л��������еĶ���ʵ����Ҫ��Ŀ��ӿڡ�
* ����ʾ���У���������֮ǰ����һ��˫�˶��У��µ�����Ҫ��ʹ��ջ�Ͷ�������ɡ�
  ˫�˶��п�����ͷβɾ��������Ԫ�ء���ջ��һ���Ƚ���������ݽṹ���������ʱ��ӵ�ջ�Ķ�����ɾ������ʱ��ɾ   ��ջ���������ݡ����������ȫ���Խ�һ�����е�˫�˶��������һ��ջ��
*/

//˫�˶��У���������
class Deque
{
public:
	void push_back(int x)
	{
		cout << "Deque push_back:" << x << endl;
	}
	void push_front(int x)
	{
		cout << "Deque push_front:" << x << endl;
	}
	void pop_back()
	{
		cout << "Deque pop_back" << endl;
	}
	void pop_front()
	{
		cout << "Deque pop_front" << endl;
	}
};

//˳���࣬����Ŀ����
class Sequence
{
public:
	virtual void push(int x) = 0;
	virtual void pop() = 0;
};

//ջ,����ȳ�, ������
class Stack :public Sequence
{
public:
	void push(int x) override
	{
		m_deque.push_front(x);
	}
	void pop() override
	{
		m_deque.pop_front();
	}
private:
	Deque m_deque;
};

//���У��Ƚ��ȳ���������
class Queue :public Sequence
{
public:
	void push(int x) override
	{
		m_deque.push_back(x);
	}
	void pop() override
	{
		m_deque.pop_front();
	}
private:
	Deque m_deque;
};
