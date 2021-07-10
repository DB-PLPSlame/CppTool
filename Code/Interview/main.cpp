// Interview.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "CommonProblem.h"
#include "shared_ptr.h"

class A
{
	void foo() {}
};

class B :public A
{
public:
	virtual void foo() {}

	// “inline”是构造函数的唯一合法存储类
	/*virtual*/ B() {}

private:
	// “B::~B”: 无法访问 private 成员(在“B”类中声明)
	//~B() {}
};

int main()
{
	B test;
	std::cout << sizeof(A) << std::endl;
	std::cout << sizeof(B) << std::endl;

	std::vector<int> vec = { 1,2,3 };
	VectorMoveCopy a(vec);
	VectorMoveCopy b = std::move(a);
	return 0;
}
