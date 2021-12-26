// ������������ContainerAdaptor��
#include "pch.h"
#include "Adaptor.h"
using namespace std;

void Test_Adaptor()
{
	// ʹ��deque��ʼ��һ��ջ������
	deque<int> deque;
	stack<int> intStack(deque);

	// ����vector��ʵ�ֵĿ�ջ
	stack<string, vector<string>> str_stack;

	for (size_t ix = 0; ix != 10; ++ix)
		intStack.push(ix);
	while (!intStack.empty())
	{
		cout << intStack.top() << " ";
		intStack.pop();
	}
	cout << "----------Test_Adaptor---------" << endl;
}