#pragma once
#include <cstring>
#include <iostream>
using namespace std;


class String {
public:
	String(char const* str) : m_str(strcpy(
		new char[strlen(str ? str : "") + 1],
		str ? str : "")) {
		cout << "���캯����" << this << endl;
	}
	~String(void) {
		cout << "����������" << this << endl;
		delete[] m_str;
	}

	String(String const& str) : m_str(strcpy(
		new char[strlen(str.m_str) + 1],
		str.m_str)) {
		cout << "����죺" << &str << "->" << this << endl;
	}
	String(String&& str) : m_str(str.m_str) {
		cout << "�ƶ����죺" << &str << "->" << this << endl;
		str.m_str = nullptr;
	}

	String& operator= (String const& str) {
		cout << "���ֵ��" << &str << "->" << this << endl;
		if (&str != this) {
			String tmp = str;
			swap(m_str, tmp.m_str);
		}
		return *this;
	}
	String& operator= (String&& str) {
		cout << "�ƶ���ֵ��" << &str << "->" << this << endl;
		if (&str != this) {
			// ����תΪ��ֵ���������������ƶ�����
			// ��Ϊ��ֵ����str��Ҳ����ֵ
			String tmp = move(str);
			swap(m_str, tmp.m_str);
		}
		return *this;
	}

	friend ostream& operator<< (ostream& os, String const& str) {
		return os << str.m_str;
	}

private:
	char* m_str;
};

String foo(void);

// �ƶ�����
void Test_move();