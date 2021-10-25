#pragma once
/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}

	// ������
	ListNode* reverseList(ListNode* head);
	ListNode* reverseList2(ListNode* head);

	// ɾ������ĵ����� N �����
	int cur = 0;
	ListNode* removeNthFromEnd(ListNode* head, int n);
	ListNode* removeNthFromEnd2(ListNode* head, int n);

private:
	ListNode* recursion(ListNode* pre, ListNode* cur);
};

/*
�������ܣ�
	1.˫ָ�뷨
	2.����ָ��(ͬ���������𲽣���ͬ������ͬʱ��)
	3.�ݹ�
*/
