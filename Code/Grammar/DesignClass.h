#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;


namespace cpp11 {
	// ���캯�����ͱ��
	class TemplateConstruct
	{
	public:
		TemplateConstruct(vector<short>& vec) : l(vec.begin(), vec.end()) {}
		TemplateConstruct(deque<int>& deq) : l(deq.begin(), deq.end()) {}
		template<class T> TemplateConstruct(T first, T last) : l(first, last) {}

	private:
		list<int> l;
	};

	/*
		1.ί�й��캯��
		2.���
		3.�ƶ���������/��ֵ
		4.��ֵ����
	 */
	class Base
	{
	public:
		// ί�й��캯��
		Base() :Base(0.0) {}
		Base(int _b) :Base(_b, 0.0) {}
		// Ŀ�깹�캯��
		Base(double _c) :p(nullptr), c(_c) { init(); }
		Base(int _b, double _c) :p(new int(_b)), c(_c) { init(); }

		virtual ~Base() { delete p; cout << this << " Deconstruct." << endl; }

		// ��������/��ֵ
		Base(const Base& other)
		{
			if (this == &other)
			{
				return;
			}
			if (other.p)
			{
				p = new int(*other.p);
			}
			else
			{
				p = nullptr;
			}
			c = other.c;
			cout << this << " Copy Construct from " << &other << "." << endl;
		}
		Base& operator=(const Base& other)
		{
			if (this == &other)
			{
				return *this;
			}
			if (p)
			{
				this->~Base();
				//cout << "Leak." << endl;
			}
			if (other.p)
			{
				p = new int(*other.p);
			}
			else
			{
				p = nullptr;
			}
			c = other.c;
			cout << this << " Copy Assign from " << &other << "." << endl;
			return *this;
		}

		// �ƶ���������/��ֵ
		Base(Base&& other)
		{
			if (this == &other)
			{
				return;
			}
			p = other.p;
			c = other.c;
			other.p = nullptr;
			cout << this << " Move Copy Construct from " << &other << "." << endl;
		}
		Base& operator=(Base&& other)
		{
			if (this == &other)
			{
				return *this;
			}
			if (p)
			{
				this->~Base();
				//cout << "Leak." << endl;
			}
			p = other.p;
			c = other.c;
			other.p = nullptr;
			cout << this << " Move Copy Assign from " << &other << "." << endl;
			return *this;
		}

		static Base ReturnValue()
		{
			Base temp;
			return temp;
		}

#if 0
		// ��ֹ���ؾֲ���ֵ����
		static Base&& ReturnValue(int)
		{
			return Base();
		}
#endif // 0
		void setC(const double& _c)
		{
			c = _c;
		}

	private:
		void init() { cout << this << " Construct." << endl; }

	protected:
		int* p;
		double c;
	};


	class Derived :public Base
	{
	public:
		using Base::Base;	// �̳й��캯��
		virtual ~Derived() {}

	private:
		int d{ 100 };
	};

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
		static void testVectorMoveCopy()
		{
			B test;
			std::cout << sizeof(A) << std::endl;
			std::cout << sizeof(B) << std::endl;

			std::vector<int> vec = { 1,2,3 };
			cpp11::VectorMoveCopy a(vec);
			cpp11::VectorMoveCopy b = std::move(a);
			std::cout << "============testVectorMoveCopy()===========" << std::endl;
		}
	private:
		std::vector<int> int_vec;
	};
}
