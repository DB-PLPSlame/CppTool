// ͨ���������� �� ˳��������SequenceContainer��

#include "pch.h"
#include "SequenceContainer.h"
using namespace std;

// ͨ�����ײ���
void Test_Container()
{
	vector<A>::value_type a4(10);		// value_type��Ԫ�����ͣ�A
	vector<A>::reference ra = a4;		// reference����ֵ���ã�A&
	vector<A>::const_reference cra = a4;// const_reference������ֵ���ã�const A&

	// ���캯����������ʼ��
	vector<A> a2;
	auto iter1 = a2.begin(), iter2 = a2.end();
	vector<A> a5(iter1, iter2);
	vector<A> a6{ 1,2,3,4 };

	// ����Ԫ��
	a5.insert(a5.begin(), 5, A(0));
	cout << a5;
	a5.emplace(a5.begin(), 1);		// ������insert�����ù����м���ʱ������C++11��
	cout << a5;

	// 1�������Ŀ�����������Ԫ�����ͱ���ƥ��
	vector<string> v1 = { "asd","qwe" };
	//	vector<const char*> v2 = v1;// err��Ԫ������
	//	list<string> v3 = v1;		// err����������
		// 2�������ݵ�������ΧΪ����ʱ���Ͳ�Ҫ����������ƥ��
	deque<string> v4(v1.begin(), v1.end());
	cout << "----------Test_Container---------" << endl;
}

// ˳��������SequenceContainer��
void Test_string()
{
	string s1 = "abc";
	string s2 = "ABC";
	swap(s1, s2);
	cout << s1 << endl;
	s1.swap(s2);
	cout << s1 << endl;
	cout << s1.length() << endl;
	cout << s1.max_size() << endl;
	cout << "----------Test_string---------" << endl;
}

void Test_vector()
{
	//	std::vector<A> a1(4);		// error����ȱʡ���캯��
	std::vector<A> a2(4, 12);	// ����ת������
	std::vector<A> a3(4, A(12));
	cout << a2;
	cout << a3;

	vector<A>::reverse_iterator ri;

	// ֻ��˳����������
	vector<A> a7(4);
	vector<A> a8(5, A(12));

	a8.assign({ 1 });
	a8.assign(5, 1);
	cout << a8;

	a8 = { 1,2,3,4,5 };
	cout << a8;

	auto iter1 = a8.begin(); ++iter1;
	auto iter2 = a8.end(); --iter2;
	auto iter = a8.erase(iter1, iter2);
	cout << a8;
	cout << *iter << endl;
	cout << "----------Test_vector---------" << endl;

	vector<int> ivec;
	cout << "ivec: size " << ivec.size() << " capacity: " << ivec.capacity() << endl;

	for (vector<int>::size_type ix = 0; ix != 24; ++ix)
		ivec.emplace_back(ix);
	cout << "ivec: size " << ivec.size() << " capacity: " << ivec.capacity() << endl;

	ivec.reserve(30);
	cout << "ivec: size " << ivec.size() << " capacity: " << ivec.capacity() << endl;

	ivec.insert(ivec.end(), 10, 2);
	cout << "ivec: size " << ivec.size() << " capacity: " << ivec.capacity() << endl;

	ivec.shrink_to_fit();
	cout << "ivec: size " << ivec.size() << " capacity: " << ivec.capacity() << endl;
	cout << "----------Test_vector2---------" << endl;
}

void Test_forward_list()
{
	forward_list<int> a1 = { 1,2,3,4 };
	//	forward_list<int>::reverse_iterator ri;	// ��������֧�ַ��������
	//	cout << a1.size() << endl;				// ��֧��
	cout << a1.max_size() << endl;

	// ����Ԫ��
	forward_list<int> a2 = { 1,3,4,5 };
	a2.insert_after(a2.begin(), 2);
	cout << a2;
	a2.erase_after(a2.begin());
	cout << a2;
	a2.erase_after(a2.before_begin());	// ��ǰԪ�ص�����
	cout << a2;
	cout << "----------Test_forward_list---------" << endl;
}

void Test_array()
{
	// ����Ԫ�����ͺ�Ԫ�ظ���
	array<int, 4> a1 = { 1,2,3,4 };
	array<int, 4>::iterator iter1 = a1.begin(), iter2 = a1.end();
	//	array<int, 4> a2(iter1, iter2);	// array��֧�����ַ�ʽ

		// ��ֵ
	a1 = { 2,3,4,5 };

	// ����
	array<int, 4> a3 = a1;

	a3 = { 0,0,0 };
	//	a3.assign(1);	// err����֧��
	cout << a3;
	cout << "----------Test_array---------" << endl;
}