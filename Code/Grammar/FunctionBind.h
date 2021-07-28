#pragma once
#include <iostream>
#include <map>
#include <functional>
using namespace std;
using namespace std::placeholders;

// https://zhuanlan.zhihu.com/p/381639427

namespace cpp11 {
	//�����������غ���
	int good(int) { return 0; }
	double good(double) { return 0.0; }

	int funcValue(int x)
	{
		return x;
	}

	class Functor
	{
	public:
		int operator()(int a)
		{
			return a;
		}
	};

	class CFunc
	{
	public:
		int Func(int a)
		{
			return a;
		}
		static int staticFunc(int a)
		{
			return a;
		}
	};

	class FunctionAndBind
	{
	public:
		void TestBind()
		{
			auto f = [](int a, char, double)->int { return a; };
			auto ff = std::bind(f, _1, 'c', 2.2);
			int result = ff(10);     // f(10,'c',2.2)

			auto reflect = std::bind(f, _3, _2, _1);    // ��ת����˳��
			result = reflect(2.2, 'c', 10);				// f(10,'c',2.2); 


			//auto result = std::bind(good, _1);      //������ʽ����֪��������һ��good����
			//��ȷ�����������ǱȽϸ���
			auto result_1 = std::bind((double(*)(double))good, _1);
			//���Ǹ��õķ�ʽ
			//auto result_2 = std::bind<double>(good, _1);   //ָ�������ķ�������
		}

		void TestFunction()
		{
			using Functional = function<int(int)>;

			//��װ��ͨ����
			Functional obj = funcValue;
			int result = obj(100);

			//��װlambda���ʽ
			obj = [](int a)->int { return a; };
			result = obj(100);

			//��װ�º���
			Functor funObj;
			obj = funObj;
			result = obj(100);

			//��װ��ĳ�Ա����
			CFunc func;
			obj = std::bind(&CFunc::Func, &func, std::placeholders::_1);
			result = obj(100);

			//��װ��ľ�̬����
			obj = CFunc::staticFunc;
			result = obj(100);
		}
	};
};
