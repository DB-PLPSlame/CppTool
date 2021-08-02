#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <map>           // ���ں����������ӳ��
#include <unordered_map> // ����ɢ�б������ӳ��
using namespace std;


namespace cpp11 {
	class Student {
	public:
		Student(string const& name = "", int age = 0) :
			m_name(name), m_age(age) {}
		friend ostream& operator<< (ostream& os, Student const& s) {
			return os << s.m_name << ',' << s.m_age;
		}
	private:
		string m_name;
		int m_age;
		friend class Hash;
		friend class Equal;
	};

	// ��ϣ��
	class Hash {
	public:
		size_t operator() (Student const& s) const {
			return std::hash<string>() (s.m_name);
		}
	};

	// �е���
	class Equal {
	public:
		bool operator() (Student const& a, Student const& b) const {
			return a.m_name == b.m_name && a.m_age == b.m_age;
		}
	};

	class Container
	{
	public:
		void TestList()
		{
			std::vector<int> vec = { 4,2,1,3 };
			std::sort(vec.begin(), vec.end());

			std::forward_list<int> lst = { 4,2,1,3 };
			//std::list<int> lst = { 4,2,1,3 };
			lst.sort();
		}

		void TestUnorderedMap()
		{
			map<string, int> m1{ {"zhangfei", 80}, {"guanyu", 90}, {"zhaoyun", 60} };
			for (auto a : m1)
				cout << a.first << "��" << a.second << endl;
			cout << "--------" << endl;

			unordered_map<string, int> m2{ {"zhangfei", 80}, {"guanyu", 90}, {"zhaoyun", 60} };
			for (auto a : m2)
				cout << a.first << "��" << a.second << endl;
			cout << "--------" << endl;
			
			unordered_map<Student, int, Hash, Equal> m3{ {{"zhangfei", 20}, 80}, { {"guanyu", 30}, 90}, { {"zhaoyun", 25}, 60} };
			for (auto a : m3)
				cout << a.first << "��" << a.second << endl;
		}
	};
}
