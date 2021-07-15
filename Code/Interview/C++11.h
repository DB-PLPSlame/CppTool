#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

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

		auto a1 = [](int x) {/*仅能访问全局外部变量*/};
		auto a2 = [Value](int x) {/*值传递局部变量Value*/};
		auto a3 = [this](int x) {/*值传递this指针*/};
		auto a4 = [&Value](int x) {/*引用传递局部变量Value*/};
		auto a5 = [=](int x) {/*值传递所有可访问的外部变量*/};
		auto a6 = [&](int x) {/*引用传递所有可访问的外部变量*/};
		auto a7 = [=, &Value](int x) {/*引用传递局部变量Value，值传递所有其他可访问的外部变量*/};
		auto a8 = [&, Value](int x) {/*值传递局部变量Value，引用传递所有其他可访问的外部变量*/};
	}
};

