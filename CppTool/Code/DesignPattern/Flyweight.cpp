/*
	��Ԫģʽ�����ù�������Ч��֧�ִ���ϸ���ȵĶ������д�������ʱ�������й�ͬ�Ĳ��ֳ���������������ͬ��ҵ������ֱ�ӷ����ڴ������еĶ��󣬱������´�����
	����������Կ���ʹ����Ԫģʽ��
		ϵͳ���д����Ķ�����Щ�������Ĵ������ڴ棬����Щ�����״̬���Ա��ⲿ����

	������Ԫģʽ����Ҫ���������Ϣ��Ϊ�������֣��ڲ�״̬���ⲿ״̬���ڲ�״̬��ָ�������������Ϣ����������Ԫ�����ڲ��Ҳ��滷���仯���ı䣻
	�ⲿ״̬�ǲ����Թ���ģ����滷���ı���ı䣬���ɿͻ��˿��Ƶġ�
 */
 /*
 * �ؼ����룺���ڲ�״̬��Ϊ��ʶ�����й���
 */
#include <iostream>
#include <map>
#include <memory>

using namespace std;

//������Ԫ�࣬�ṩ��Ԫ���ⲿ�ӿڡ�
class AbstractConsumer
{
public:
	virtual ~AbstractConsumer() {}
	virtual void setArticle(const string&) = 0;
	virtual const string& article() = 0;
};

//�������Ԫ��
class Consumer : public AbstractConsumer
{
public:
	Consumer(const string& strName) : m_user(strName) {}
	~Consumer()
	{
		cout << " ~Consumer()" << endl;
	}

	void setArticle(const string& info) override
	{
		m_article = info;
	}

	const string& article() override
	{
		return m_article;
	}

private:
	string m_user;
	string m_article;
};

//��Ԫ������
class Trusteeship
{
public:
	~Trusteeship()
	{
		m_consumerMap.clear();
	}

	void hosting(const string& user, const string& article)
	{
		if (m_consumerMap.count(user))
		{
			cout << "A customer named " << user.data() << " already exists" << endl;
			Consumer* consumer = m_consumerMap.at(user).get();
			consumer->setArticle(article);
		}
		else
		{
			shared_ptr<Consumer> consumer(new Consumer(user));
			consumer.get()->setArticle(article);
			m_consumerMap.insert(pair<string, shared_ptr<Consumer>>(user, consumer));
		}
	}

	void display()
	{
		map<string, shared_ptr<Consumer>>::iterator iter = m_consumerMap.begin();
		for (; iter != m_consumerMap.end(); iter++)
		{
			cout << iter->first.data() << " : " << iter->second.get()->article().data() << endl;
		}
	}

private:
	map<string, shared_ptr<Consumer>> m_consumerMap;
};


int testFlyweight()
{
	Trusteeship* ts = new Trusteeship;
	ts->hosting("zhangsan", "computer");
	ts->hosting("lisi", "phone");
	ts->hosting("wangwu", "watch");

	ts->display();

	ts->hosting("zhangsan", "TT");
	ts->hosting("lisi", "TT");
	ts->hosting("wangwu", "TT");

	ts->display();

	delete ts;
	ts = nullptr;

	return 0;
}
