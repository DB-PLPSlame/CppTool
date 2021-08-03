#pragma once
#include <string>
#include <iostream>
#include <bitset>

// https://www.cnblogs.com/magisk/p/8809922.html
namespace cpp11 {
	using namespace std;

	class BitSet
	{
	public:
		void InitBitSet()
		{
			std::bitset<4> bitset1;			// �޲ι��죬����Ϊ����Ĭ��ÿһλΪ��
			std::bitset<8> bitset2(12);		//����Ϊ���������Ʊ��棬ǰ���ã�����

			std::string s = "100101";
			std::bitset<10> bitset3(s);		//����Ϊ10��ǰ���ã�����

			char s2[] = "10101";
			std::bitset<13> bitset4(s2);	//����Ϊ13��ǰ���ã�����

			cout << bitset1 << endl;	//0000
			cout << bitset2 << endl;	//00001100
			cout << bitset3 << endl;	//0000100101
			cout << bitset4 << endl;	//0000000010101
		}

		void Foo()
		{
			bitset<4> foo(string("1001"));
			bitset<4> bar(string("0011"));

			cout << (foo ^= bar) << endl;       // 1010 (foo��bar��λ����ֵ��foo)
			cout << (foo &= bar) << endl;       // 0010 (��λ���ֵ��foo)
			cout << (foo |= bar) << endl;       // 0011 (��λ���ֵ��foo)

			cout << (foo <<= 2) << endl;        // 1100 (���ƣ�λ����λ������������ֵ)
			cout << (foo >>= 1) << endl;        // 0110 (���ƣ�λ����λ������������ֵ)

			cout << (~bar) << endl;           // 1100 (��λȡ��)
			cout << (bar << 1) << endl;         // 0110 (���ƣ�����ֵ)
			cout << (bar >> 1) << endl;         // 0001 (���ƣ�����ֵ)

			cout << (foo == bar) << endl;       // false (0110==0011Ϊfalse)
			cout << (foo != bar) << endl;       // true  (0110!=0011Ϊtrue)

			cout << (foo&bar) << endl;        // 0010 (��λ�룬����ֵ)
			cout << (foo | bar) << endl;        // 0111 (��λ�򣬲���ֵ)
			cout << (foo^bar) << endl;        // 0101 (��λ��򣬲���ֵ)

			cout << foo[0] << endl;		//1
			cout << foo[1] << endl;		//1
			cout << foo[2] << endl;		//0
		}

		void Foo2()
		{
			bitset<8> foo("10011011");

			cout << foo.count() << endl;	//5������count����������bitset��1��λ����foo�й��У�����
			cout << foo.size() << endl;		//8������size����������bitset�Ĵ�С��һ���У�λ

			cout << foo.test(0) << endl;	//true������test�����������±괦��Ԫ���ǣ����ǣ���������false��true���˴�foo[0]Ϊ��������true
			cout << foo.test(2) << endl;	//false������ͬ��foo[2]Ϊ��������false

			cout << foo.any() << endl;		//true������any�������bitset���Ƿ��У�
			cout << foo.none() << endl;		//false������none�������bitset���Ƿ�û�У�
			cout << foo.all() << endl;		//false������all�������bitset����ȫ��Ϊ��
		}

		void Foo3()
		{
			bitset<8> foo("10011011");

			cout << foo.flip(2) << endl;	//10011111������flip����������ʱ�����ڽ�����λȡ�������д��뽫foo�±ꣲ��"��ת"�������䣱�����䣰
			cout << foo.flip() << endl;		//01100000������flip������ָ������ʱ����bitsetÿһλȫ��ȡ��

			cout << foo.set() << endl;		//11111111������set������ָ������ʱ����bitset��ÿһλȫ����Ϊ��
			cout << foo.set(3, 0) << endl;	//11110111������set����ָ����λ����ʱ������һ����λ��Ԫ����Ϊ�ڶ�������ֵ�����ж�foo�Ĳ����൱��foo[3]=0
			cout << foo.set(3) << endl;		//11111111������set����ֻ��һ������ʱ���������±괦��Ϊ��

			cout << foo.reset(4) << endl;	//11101111������reset������һ������ʱ�������±괦��Ϊ��
			cout << foo.reset() << endl;	//00000000������reset������������ʱ��bitset��ÿһλȫ����Ϊ��
		}

		void Foo4()
		{
			bitset<8> foo("10011011");

			string s = foo.to_string();			//��bitsetת����string����
			unsigned long a = foo.to_ulong();	//��bitsetת����unsigned long����
			unsigned long long b = foo.to_ullong();	//��bitsetת����unsigned long long����

			cout << s << endl;		//10011011
			cout << a << endl;		//155
			cout << b << endl;		//155
		}
	};
};
