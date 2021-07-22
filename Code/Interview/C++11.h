#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

namespace cpp11 {
	/* STL vector move copy */
	class VectorMoveCopy
	{
	public:
		VectorMoveCopy(const std::vector<int>& vec)
		{
			int_vec = vec;
		}
		VectorMoveCopy(const VectorMoveCopy& other) = default;
		VectorMoveCopy(VectorMoveCopy&& other)
		{
			if (&other == this)
			{
				return;
			}

			int_vec = std::move(other.int_vec);
			std::cout << "Move Copy" << std::endl;
		}
	private:
		std::vector<int> int_vec;
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
