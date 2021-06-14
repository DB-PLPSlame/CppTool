#pragma once
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

class CommonProblem
{
public:
	void VectorUnique()
	{
		vector<int> ivec = { 4,2,3,3,3,2,4,1,2,3,4 };
		std::sort(ivec.begin(), ivec.end());
		auto unique_end = std::unique(ivec.begin(), ivec.end());
		ivec.erase(unique_end, ivec.end());
	}

	void UseWeakPtr()
	{
		auto sp = make_shared<int>(42);
		weak_ptr<int> wp(sp);
		if (auto spt = wp.lock()) {
			// ֻ��lock()֮�󣬲��к�������
		}
	}

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

