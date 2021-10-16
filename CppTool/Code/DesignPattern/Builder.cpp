/*
	������ģʽ�������Ӷ���Ĺ��������ʾ���룬ʹ����ͬ�Ĺ������̿��Բ�����ͬ�ı�ʾ��
	�������ο��Կ���ʹ�ý�����ģʽ��
		����Ĵ������ӣ�������������ֵ��Ӷ��󴴽��㷨һ����
		����仯�󣬹��츴�Ӷ�����Ӷ��󾭳��仯�������������һ����㷨����ȶ���

	������ģʽ���ŵ㣺
		������Ĵ����ͱ�ʾ���룬�ͻ��˲���Ҫ�˽����Ĺ���ϸ�ڡ�
		�����µĲ�Ʒ����ʱ��ֻ��Ҫ���������Ľ����༴�ɣ�����Ҫ�޸�ԭ���Ĵ��룬��չ���㡣

	��Ʒ֮������Դ��ڲ��仯�ϴ󡢽ϸ���ʱ������ʹ�ý�����ģʽ��
 */


 /*
 *�ؼ����룺�������ࣺ�������ṩʵ���� Director�ࣺ�����������ʵ����������ϵ��
 */

#include <iostream>
#include <string>

using namespace std;

//����Ĳ�Ʒ��
class Order
{
public:
	void setFood(const string& food)
	{
		m_strFood = food;
	}

	const string& food()
	{
		cout << m_strFood.data() << endl;
		return m_strFood;
	}

	void setDrink(const string& drink)
	{
		m_strDrink = drink;
	}

	const string& drink()
	{
		cout << m_strDrink << endl;
		return m_strDrink;
	}

private:
	string m_strFood;
	string m_strDrink;
};

//�������࣬�ṩ����ӿڡ�
class OrderBuilder
{
public:
	virtual ~OrderBuilder()
	{
		cout << "~OrderBuilder()" << endl;
	}
	virtual void setOrderFood() = 0;
	virtual void setOrderDrink() = 0;
	virtual Order* getOrder() = 0;
};

//����Ľ�����
class VegetarianOrderBuilder : public OrderBuilder
{
public:
	VegetarianOrderBuilder()
	{
		m_pOrder = new Order;
	}

	~VegetarianOrderBuilder()
	{
		cout << "~VegetarianOrderBuilder()" << endl;
		delete m_pOrder;
		m_pOrder = nullptr;
	}

	void setOrderFood() override
	{
		m_pOrder->setFood("vegetable salad");
	}

	void setOrderDrink() override
	{
		m_pOrder->setDrink("water");
	}

	Order* getOrder() override
	{
		return m_pOrder;
	}

private:
	Order* m_pOrder;
};

//����Ľ�����
class MeatOrderBuilder : public OrderBuilder
{
public:
	MeatOrderBuilder()
	{
		m_pOrder = new Order;
	}
	~MeatOrderBuilder()
	{
		cout << "~MeatOrderBuilder()" << endl;
		delete m_pOrder;
		m_pOrder = nullptr;
	}

	void setOrderFood() override
	{
		m_pOrder->setFood("beef");
	}

	void setOrderDrink() override
	{
		m_pOrder->setDrink("beer");
	}

	Order* getOrder() override
	{
		return m_pOrder;
	}

private:
	Order* m_pOrder;
};

//Director�࣬�������ʵ��������������ϵ��ָ�ӹ������ഴ��ʵ��
class Director
{
public:
	Director(OrderBuilder* builder) : m_pOrderBuilder(builder)
	{
	}
	void construct()
	{
		m_pOrderBuilder->setOrderFood();
		m_pOrderBuilder->setOrderDrink();
	}

private:
	OrderBuilder* m_pOrderBuilder;
};


int testBuilder()
{
	//  MeatOrderBuilder* mBuilder = new MeatOrderBuilder;
	OrderBuilder* mBuilder = new MeatOrderBuilder;  //ע����󹹽������������������������ʱ�Ż�����������������
	Director* director = new Director(mBuilder);
	director->construct();
	Order* order = mBuilder->getOrder();
	order->food();
	order->drink();

	delete director;
	director = nullptr;

	delete mBuilder;
	mBuilder = nullptr;

	return 0;
}
