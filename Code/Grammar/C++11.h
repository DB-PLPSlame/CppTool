#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

namespace cpp11 {
	// �����۵�(Reference Collapsing)/ͨ������
	/*
		1)�ں���ģ����ʽ�ƶϹ����У���ʵ��Ϊ��ֵ����T&&���ƶ�Ϊ��ֵ���ã���ʵ��Ϊ��ֵ����T&&���ƶ�Ϊ��ֵ���ã����������ñ���Ϊͨ�����á�
		--->������ֵ���ûᴫȾ��ֻ�д���ֵ&& && = &&��մ��һ����ֵ���þͱ���ֵ������
		--->��������(ָ�����õ�����)
		A& & ��� A&
		A& && ��� A&
		A&& & ��� A&
		A&& && ��� A&&

		2)ֻ��T&&����ͨ�����ã�����const�Ͳ����ˡ�
		3)������ʽ�ƶϣ�û��ͨ�����á�
		4)���ƵĹ���Ҳͬ�������ڻ���auto�ؼ��ֵ������Ƶ���
	 */
	class ReferenceCollapse
	{
	public:
		void RunCode(int& a) { cout << "lvalue ref." << endl; }
		void RunCode(const int& a) { cout << "const lvalue ref." << endl; }
		void RunCode(int&& a) { cout << "rvalue ref." << endl; }
		void RunCode(const int&& a) { cout << "const rvalue ref." << endl; }

		// ����ת��
		template<typename T>
		void PerfectForward(T &&t) { RunCode(std::forward<T>(t)); }

		static void testPerfectForward()
		{
			ReferenceCollapse rc;
			int a, b;
			const int c = 0, d = 0;

			rc.PerfectForward(a);
			rc.PerfectForward(move(b));
			rc.PerfectForward(c);
			rc.PerfectForward(move(d));
			std::cout << "============testPerfectForward()===========" << std::endl;
		}
	};

	class NewSkill
	{
	public:
		void TestLamdba(int InValue)
		{
			int Value = 0;

			auto a1 = [](int x) {/*���ܷ���ȫ���ⲿ����*/};
			auto a2 = [Value](int x) {/*ֵ���ݾֲ�����Value*/};
			auto a3 = [this](int x) {/*ֵ����thisָ��*/};
			auto a4 = [&Value](int x) {/*���ô��ݾֲ�����Value*/};
			auto a5 = [=](int x) {/*ֵ�������пɷ��ʵ��ⲿ����*/};
			auto a6 = [&](int x) {/*���ô������пɷ��ʵ��ⲿ����*/};
			auto a7 = [=, &Value](int x) {/*���ô��ݾֲ�����Value��ֵ�������������ɷ��ʵ��ⲿ����*/};
			auto a8 = [&, Value](int x) {/*ֵ���ݾֲ�����Value�����ô������������ɷ��ʵ��ⲿ����*/};
		}
	};

	// ��̬���ԣ�����ʱ���
	//static_assert(sizeof(NewSkill) == sizeof(VectorMoveCopy), "sizeof(NewSkill) != sizeof(VectorMoveCopy)!");

	class UnPopular
	{
	public:
		void UseWeakPtr()
		{
			auto sp = make_shared<int>(42);
			weak_ptr<int> wp(sp);
			if (auto spt = wp.lock()) {
				// ֻ��lock()֮�󣬲��к�������
			}
		}
	};
};
