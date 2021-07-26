// Interview.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <memory>
#include <type_traits>
#include "Common.h"
#include "C++11.h"
#include "shared_ptr.h"
#include "DesignClass.h"
using namespace cpp11;


template <class T>
void swap(T&& a, T&& b)
{
	T temp = move(a);
	a = move(b);
	b = move(temp);
}

// 1.右值引用 2.常左值引用
void testDesignClass()
{
	{
		Base a(4, 3.14), b, c;
		b = a;
		b = std::move(a);
		a = b;
		std::cout << "=======================" << std::endl;
	}

	{
		Base c;
		c = Base::ReturnValue();
	}
	std::cout << "=======================" << std::endl;
	{
		Base&& d = Base::ReturnValue();
		d.setC(2.34);
		cout << is_lvalue_reference<Base&&>::value << endl;
		cout << is_rvalue_reference<Base&&>::value << endl;
		cout << is_reference<Base&&>::value << endl;
		cout << is_move_constructible<Base>::value << endl;
		cout << is_trivially_move_assignable<Base>::value << endl;
		cout << is_nothrow_move_constructible<Base>::value << endl;
	}
	std::cout << "=======================" << std::endl;
	{
		const Base& d = Base::ReturnValue();
		//d.setC(2.34);	// error
	}
	std::cout << "=======================" << std::endl;
	{
		::swap(Base(1, 2.3), Base(2, 5.4));
	}
	std::cout << "============testDesignClass()===========" << std::endl;
}


int main()
{
	//VectorMoveCopy::testVectorMoveCopy();
	testDesignClass();
	ReferenceCollapse::testPerfectForward();
	return 0;
}
