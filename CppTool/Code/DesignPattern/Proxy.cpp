/*
	����ģʽ��Ϊ���������ṩһ�ִ����Կ����������ķ��ʡ���ĳЩ����£�һ�������ʺϻ��߲���ֱ��������һ�����󣬶������������ڿͻ��˺�Ŀ�����֮�����н����á�
	�ŵ㣺
		ְ����������ʵ�Ľ�ɫֻ����ʵ��ʵ�ʵ�ҵ���߼������ù��������Ǳ�ְ�������ͨ�����ڵĴ�����ɾ�������������������������
		�����������ڿͻ��˺�Ŀ�����֮�����н�����ã������ͱ�����Ŀ�����
		��չ�Ժá�
 */
 /*
 * �ؼ����룺һ������������Ҫ���ʵĶ���(Ŀ����)��һ���Ǵ������,����������������ʵ��ͬһ���ӿ�,�ȷ��ʴ������ٷ�������Ҫ���ʵĶ���
 */
#include <iostream>
using namespace std;

class Girl
{
public:
	Girl(const string& name = "girl") :m_string(name) {}
	string getName()
	{
		return m_string;
	}
private:
	string m_string;
};

class Profession
{
public:
	virtual ~Profession() {}
	virtual void profess() = 0;
};

class YoungMan : public Profession
{
public:
	YoungMan(const Girl& girl) :m_girl(girl) {}
	void profess()
	{
		cout << "Young man love " << m_girl.getName().data() << endl;
	}

private:
	Girl m_girl;
};

class ManProxy : public Profession
{
public:
	ManProxy(const Girl& girl) :m_pMan(new YoungMan(girl)) {}
	~ManProxy()
	{
		delete m_pMan;
		m_pMan = nullptr;
	}
	void profess()
	{
		m_pMan->profess();
	}
private:
	YoungMan* m_pMan;
};

int testProxy(int argc, char *argv[])
{
	Girl girl("heihei");
	ManProxy* proxy = new ManProxy(girl);
	proxy->profess();

	delete proxy;
	proxy = nullptr;
	return 0;
}
