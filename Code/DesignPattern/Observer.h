#pragma once
/*
 * �ؼ����룺��Ŀ����������һ��ArrayList����Ź۲����ǡ�

   �۲���ģʽ�����������һ��һ�Զ��������ϵ����һ�������״̬�����ı�ʱ���������������Ķ���Ҫ�õ�֪ͨ���Զ����¡�
   �۲���ģʽ�Ӹ����Ͻ��������������ɫ���۲��ߺͱ��۲����
   ���۲��������Ӧ�ð���һ����������Ź۲��߶��󣬵����۲����������ı�ʱ֪ͨ���������еĹ۲��߶����Զ����¡�
   �۲��߶������ע�ᵽ���۲��ߵ��У����ע�����Լ�ⱻ�۲��ߵı仯�����ձ��۲��ߵ�֪ͨ��
   ��Ȼ�۲���Ҳ���Ա�ע������ֹͣ�Ա��۲��ߵļ�ء�
 */
#include <iostream>
#include <list>
#include <memory>
#include <string>
using namespace std;

class View;

//���۲��߳�����   ����ģ��
class DataModel
{
public:
	virtual ~DataModel() {}
	virtual void addView(View* view) = 0;
	virtual void removeView(View* view) = 0;
	virtual void notify() const = 0;
};

//�۲��߳�����   ��ͼ
class View
{
public:
	virtual ~View() { cout << "~View()" << endl; }
	virtual void update() const = 0;
	virtual void setViewName(const string& name) = 0;
	virtual const string& name() const = 0;
};

//����ı��۲��࣬ ����ģ��
class IntDataModel :public DataModel
{
public:
	~IntDataModel() override
	{
		m_pViewList.clear();
	}

	void addView(View* view) override
	{
		//auto temp = make_shared<View>(view);
		shared_ptr<View> temp(view);
		if (find(m_pViewList.begin(), m_pViewList.end(), temp) == m_pViewList.end())
		{
			m_pViewList.push_front(temp);
		}
		else
		{
			cout << "View already exists" << endl;
		}
	}

	void removeView(View* view) override
	{
		for (auto iter = m_pViewList.begin(); iter != m_pViewList.end(); iter++)
		{
			if ((*iter).get() == view)
			{
				cout << "remove view" << (*iter)->name() << endl;
				m_pViewList.erase(iter);
				return;
			}
		}
	}

	void notify() const override
	{
		for (auto& view : m_pViewList)
		{
			view->update();
		}
	}

private:
	list<shared_ptr<View>> m_pViewList;
};

//����Ĺ۲�����    ����ͼ
class TableView : public View
{
public:
	TableView() : m_name("unknow") {}
	TableView(const string& name) : m_name(name) {}
	~TableView() { cout << "~TableView(): " << m_name.data() << endl; }

	void setViewName(const string& name) override
	{
		m_name = name;
	}

	const string& name() const override
	{
		return m_name;
	}

	void update() const override
	{
		cout << m_name.data() << " update" << endl;
	}

private:
	string m_name;
};

int testObserver();
