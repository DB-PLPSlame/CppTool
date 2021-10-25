#include "List.h"

// ������˫ָ�뷨
ListNode * ListNode::reverseList(ListNode * head)
{
	// ������ʱ�临�Ӷ�O(n)��
	ListNode* one = nullptr;
	ListNode* two = head;

	while (two) {
		auto temp = two->next;
		two->next = one;
		one = two;

		two = temp;
	}

	return one;
}

// ������: �ݹ�
ListNode * ListNode::recursion(ListNode * pre, ListNode * cur)
{
	if (!cur->next)
	{
		cur->next = pre;
		return cur;
	}

	auto tail = recursion(cur, cur->next);
	cur->next = pre;
	return tail;
}

ListNode * ListNode::reverseList2(ListNode * head)
{
	if (!head)
	{
		return head;
	}
	return recursion(nullptr, head);
}

// ɾ������ĵ����� N �����: �ݹ�
ListNode * ListNode::removeNthFromEnd(ListNode * head, int n) {
	if (!head)
		return nullptr;
	head->next = removeNthFromEnd(head->next, n);
	cur++;
	if (n == cur)
		return head->next;
	return head;
}

// ɾ������ĵ����� N �����: ����ָ��
ListNode * ListNode::removeNthFromEnd2(ListNode * head, int n) {
	ListNode *fast = head, *slow = head;
	while (n--)
	{
		fast = fast->next;
	}

	if (!fast)
	{
		return head->next;
	}

	while (fast && fast->next)
	{
		fast = fast->next;
		slow = slow->next;
	}

	auto tmp = slow->next;
	slow->next = slow->next->next;
	tmp->next = nullptr;
	return head;
}
