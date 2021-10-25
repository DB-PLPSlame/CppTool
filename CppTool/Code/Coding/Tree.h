#pragma once
#include <vector>
#include <queue>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x = 0, TreeNode *left = nullptr, TreeNode *right = nullptr) : val(x), left(left), right(right) {}

	// �������
	vector<int> levelOrder(TreeNode* root);

private:
	void bfs(queue<TreeNode*>& que, vector<int>& res);
};

// ������ǰ����������������������������������ֱ�����
// https://blog.csdn.net/u013834525/article/details/80421684?spm=1001.2101.3001.6650.2&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-2.no_search_link&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-2.no_search_link
