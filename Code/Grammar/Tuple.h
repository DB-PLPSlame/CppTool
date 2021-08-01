#pragma once
#include <tuple>
#include <string>
#include <iostream>


namespace cpp11 {
	using namespace std;

	class Tuple
	{
	public:
		void TestTuple()
		{
			int size;
			//����һ�� tuple ����洢 10 �� 'x'
			std::tuple<int, char> mytuple(10, 'x');

			//���� mytuple �洢Ԫ�صĸ���
			size = std::tuple_size<decltype(mytuple)>::value;

			//��� mytuple �д洢��Ԫ��
			std::cout << std::get<0>(mytuple) << " " << std::get<1>(mytuple) << std::endl;

			//�޸�ָ����Ԫ��
			std::get<0>(mytuple) = 100;
			std::cout << std::get<0>(mytuple) << std::endl;

			//ʹ�� makde_tuple() ����һ�� tuple ����
			auto bar = std::make_tuple("test", 3.1, 14);

			//��� bar ���󣬷ֱ�ֵ�� mystr��mydou��myint
			const char* mystr = nullptr;
			double mydou;
			int myint;
			//ʹ�� tie() ʱ������������ĳ��Ԫ�ص�ֵ��ʵ�ο����� std::ignore ����
			std::tie(mystr, mydou, myint) = bar;
			//std::tie(std::ignore, std::ignore, myint) = bar;  //ֻ���յ� 3 ������ֵ

			//�� mytuple �� bar �е�Ԫ�����ϵ� 1 �� tuple ������
			auto mycat = std::tuple_cat(mytuple, bar);
			size = std::tuple_size<decltype(mycat)>::value;
			std::cout << size << std::endl;

			// ����һ��������ֵ������Ԫ�鷽����forward_as_tuple
			std::map<int, std::string> m;
			m.emplace(std::piecewise_construct, std::forward_as_tuple(10), std::forward_as_tuple(20, 'a'));
		}
	};
}
