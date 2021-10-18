#pragma once
/*
	ģʽ����
		״̬ģʽ��state������һ�����������״̬�ı�ʱ����ı�����Ϊ����������������Ǹı������ࡣ
	ģʽ����
		״̬ģʽ��Ҫ������ǵ�����һ������״̬ת�����������ʽ���ڸ���ʱ���������״̬���ж��߼�ת�Ƶ���ʾ��ͬ״̬��һϵ���൱�У����԰Ѹ��ӵ��ж��߼��򻯡�
		��һ���������Ϊȡ��������״̬������������������ʱ����״̬�ı�������Ϊʱ���Ϳ��Կ���ʹ��״̬ģʽ�ˡ�
	https://www.cnblogs.com/wzxNote/p/13321934.html
 */
#include <string>
#include <iostream>
#include <memory>
using namespace std;
class People;

class State
{
public:
	State(const std::string& context) :m_Content(context) {}
	virtual ~State() {}
	virtual void Handle(People* people) = 0;

	const std::string& Content() const
	{
		return m_Content;
	}
protected:
	std::string m_Content;

private:
	int     m_Time;
};

class People
{
public:
	People(std::shared_ptr<State> state) :m_State(state) {}
	void ChangeState(std::shared_ptr<State> state)
	{
		m_State = state;
	}

	void Show()
	{
		std::cout << "���ɣ�չʾ!" << std::endl;
		std::cout << "��ǰ״̬:" << m_State->Content() << std::endl;
	}

	void SetTime(int time)
	{
		m_Now = time;
		m_State->Handle(this);
	}

	int Time()
	{
		return m_Now;
	}

private:
	int							m_Now;
	std::shared_ptr<State>		m_State;
};

class LifeState : public State
{
public:
	LifeState(const std::string& content = "����״̬") :State(content) {}
	void Handle(People *people) override;
};

class PlayState : public State
{
public:
	PlayState(const std::string& content = "����״̬") :State(content) {}
	void Handle(People *people) override;
};

class WorkState : public State
{
public:
	WorkState(const std::string& content = "����״̬") :State(content) {}
	void Handle(People *people) override;
};

int testState();

