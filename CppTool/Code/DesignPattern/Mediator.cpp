/*
	�н���ģʽ����һ���н��������װһϵ�еĶ��󽻻����н���ʹ��������Ҫ��ʾ���໥���ã��Ӷ�ʹ�������ɢ�����ҿ��Զ����ظı�����֮ǰ�Ľ�����
	������������֮ǰ���ڴ����Ĺ�����ϵ����һ������ı䣬������Ҫ������֮�����Ķ��󣬲�������Ӧ�Ĵ��������Ʊػ����ϵͳ��ø��ӣ�
	�����������ο��Կ���ʹ���н���ģʽ�������������ڹ�����ϵʱ��Ϊ�������һ���н���󣬵�һ������ı�ʱ��ֻ��Ҫ֪ͨ�����н�������������н����֪ͨÿ��������صĶ���
 */

 /*
 * �ؼ����룺����ض����ͨ�ŷ�װ��һ�����е�������
 */
#include <iostream>
using namespace std;

class Mediator;

//����ͬ���ࡣ
class Businessman
{
public:
	Businessman() {}
	Businessman(Mediator* mediator) : m_pMediator(mediator) {}

	virtual ~Businessman() {}

	virtual void setMediator(Mediator* m)
	{
		m_pMediator = m;
	}

	virtual void sendMessage(const string& msg) = 0;
	virtual void getMessage(const string& msg) = 0;

protected:
	Mediator* m_pMediator;
};

//�����н����ࡣ
class  Mediator
{
public:
	virtual ~Mediator() {}
	virtual void setBuyer(Businessman* buyer) = 0;
	virtual void setSeller(Businessman* seller) = 0;
	virtual void send(const string& msg, Businessman* man) = 0;
};

//����ͬ����
class Buyer : public Businessman
{
public:
	Buyer() : Businessman() {}
	Buyer(Mediator* mediator) : Businessman(mediator) {}

	void sendMessage(const string& msg) override
	{
		m_pMediator->send(msg, this);
	}

	void getMessage(const string& msg)
	{
		cout << "Buyer recv: " << msg.data() << endl;
	}
};

//����ͬ����
class Seller : public Businessman
{
public:
	Seller() : Businessman() {}
	Seller(Mediator* mediator) : Businessman(mediator) {}

	void sendMessage(const string& msg) override
	{
		m_pMediator->send(msg, this);
	}

	void getMessage(const string& msg)
	{
		cout << "Seller recv: " << msg.data() << endl;
	}
};

//�����н�����
class HouseMediator : public Mediator
{
public:
	void setBuyer(Businessman* buyer) override
	{
		m_pBuyer = buyer;
	}

	void setSeller(Businessman* seller) override
	{
		m_pSeller = seller;
	}

	void send(const string& msg, Businessman* man) override
	{
		if (man == m_pBuyer)
		{
			m_pSeller->getMessage(msg);
		}
		else if (man == m_pSeller)
		{
			m_pBuyer->getMessage(msg);
		}
	}

private:
	Businessman* m_pBuyer;
	Businessman* m_pSeller;
};

int testMediator()
{
	HouseMediator* hMediator = new HouseMediator;
	Buyer* buyer = new Buyer(hMediator);
	Seller* seller = new Seller(hMediator);

	hMediator->setBuyer(buyer);
	hMediator->setSeller(seller);

	buyer->sendMessage("Sell not to sell?");
	seller->sendMessage("Of course selling!");

	delete buyer;
	buyer = nullptr;

	delete seller;
	seller = nullptr;

	delete hMediator;
	hMediator = nullptr;


	return 0;
}
