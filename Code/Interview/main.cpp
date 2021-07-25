// Interview.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <memory>
#include "Common.h"
#include "C++11.h"
#include "shared_ptr.h"
#include "DesignClass.h"

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
	cpp11::VectorMoveCopy a(vec);
	cpp11::VectorMoveCopy b = std::move(a);

	std::shared_ptr<Base> derived = std::make_shared<Derived>(1, 1.5);
	return 0;
}
