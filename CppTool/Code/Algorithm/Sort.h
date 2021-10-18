#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Sort
{
public:
	void sortArray(vector<int>& nums)
	{
		quick(nums, 0, nums.size() - 1);
	}

	void printArray(const vector<int>& nums)
	{
		for (auto& i: nums)
		{
			cout << i << ',';
		}
		cout << endl;
	}

private:
	void bubble(vector<int>& array);

	void quick(vector<int>& array, int left, int right);
	//void quick1(vector<int>& array, int left, int right);

	//����
	void InsertSort(vector<int>& nums, int n) {
		for (int i = 0; i < n; i++) {
			int temp = nums[i];
			int j = i - 1;
			while (j >= 0 && nums[j] > temp) {
				nums[j + 1] = nums[j];
				j--;
			}
			nums[j + 1] = temp;
		}
	}
	//�۰����
	void HInsertSort(vector<int>& nums, int n) {
		int i, j, low, high, mid;
		for (i = 0; i < n; i++) {
			int tmp = nums[i];
			low = 0;
			high = i - 1;
			while (low <= high) {
				mid = low + (high - low) / 2;
				if (nums[mid] > tmp) {
					high = mid - 1;
				}
				else {
					low = mid + 1;
				}
			}
			for (j = i - 1; j >= high + 1; j--) {
				nums[j + 1] = nums[j];
			}
			nums[high + 1] = tmp;
		}
	}
	//ϣ��
	void ShellSort(vector<int>& nums, int n) {
		for (int dk = n / 2; dk >= 1; dk = dk / 2) {
			for (int i = dk; i < n; ++i) {
				if (nums[i] < nums[i - dk]) {
					int tmp = nums[i], j;
					for (j = i - dk; j >= 0 && tmp < nums[j]; j -= dk) {
						nums[j + dk] = nums[j];
					}
					nums[j + dk] = tmp;
				}
			}
		}
	}
	//ð��
	void BubbleSort(vector<int>& nums, int n) {
		for (int i = 0; i < n - 1; i++) {
			bool flag = false;
			for (int j = n - 1; j > i; j--) {
				if (nums[j - 1] > nums[j]) {
					swap(nums[j - 1], nums[j]);
					flag = true;
				}
			}
			if (flag == false) {
				return;
			}
		}
	}
	//��ѡ��
	void SelectSort(vector<int>& nums, int n) {
		for (int i = 0; i < n - 1; i++) {
			int min = i;
			for (int j = i + 1; j < n; j++) {
				if (nums[j] < nums[min])
					min = j;

			}
			if (min != i)
				swap(nums[i], nums[min]);
		}
	}
	//������
	void adjust(vector<int> &nums, int len, int index) {
		int left = 2 * index + 1; // index�����ӽڵ�
		int right = 2 * index + 2;// index�����ӽڵ�

		int maxIdx = index;
		if (left<len && nums[left] > nums[maxIdx])
			maxIdx = left;
		if (right<len && nums[right] > nums[maxIdx])
			maxIdx = right;

		if (maxIdx != index)
		{
			swap(nums[maxIdx], nums[index]);
			adjust(nums, len, maxIdx);
		}
	}

	// ������
	void HeapSort(vector<int> &nums, int size) {
		for (int i = size / 2 - 1; i >= 0; i--) {
			adjust(nums, size, i);
		}
		for (int i = size - 1; i >= 1; i--) {
			swap(nums[0], nums[i]);
			adjust(nums, i, 0);
		}
	}
};
