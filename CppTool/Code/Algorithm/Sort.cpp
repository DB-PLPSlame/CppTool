#include "Sort.h"


void Sort::bubbleSort(vector<int>& array)
{
	for (int j = array.size() - 1; j >= 0; j--)
	{
		bool find = false;
		for (int i = 0; i < j; i++)
			if (array[i] > array[i + 1])
			{
				swap(array[i], array[i + 1]);
				find = true;
			}
		if (!find)
			return;
	}
}

//��ѡ��
void Sort::selectSort(vector<int>& nums)
{
	int n = nums.size();
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

//����
void Sort::insertSort(vector<int>& nums)
{
	for (int i = 1; i < nums.size(); i++)
	{
		int temp = nums[i];
		int j = i - 1;
		while (j >= 0 && nums[j] > temp)
		{
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = temp;
	}
}

//ϣ��
void Sort::shellSort(vector<int>& nums, int n)
{
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

// https://www.cnblogs.com/sky20080101/articles/8693343.html
/*
�������ڿӷ�:
1.�������¼
2.ȡ����ָ��low��high����ʼֵ�������е������±꣬��֤low<=high
3.�ƶ�����ָ��
*��high�����ҵ���һ��С�����Ԫ��, ����low��λ��
*��low�����ҵ���һ���������Ԫ�أ�����high��λ��
4.�ظ���ֱ��low=high��
5.�������low��ָ��λ��
6.�ֱ��low��ָ��λ�õ���ߺ��ұ߽��������ĵݹ�
*/
void Sort::quickSort(vector<int>& array, int left, int right)
{
	if (left < right)
	{
		int low = left;									// ��ߵ�һ������Ϊ��һ���Ѿ���pivot������
		int high = right;								// �ұ�
		int pivot = array[left];						// ��һ�����ѱ�����
		while (low != high)								// ����С����,����ȵ�ʱ�������ѭ��
		{
			while (low < high && array[high] >= pivot)  // ���������ҵ�һ��С��x����
				high--;
			if (low < high)
				array[low++] = array[high];

			while (low < high && array[low] < pivot)	// ���������ҵ�һ�����ڵ���x����
				low++;
			if (low < high)
				array[high--] = array[low];
		}
		array[low] = pivot;
		//printArray(array);

		quickSort(array, left, low - 1);
		quickSort(array, low + 1, right);
	}
}

//void Sort::quick1(vector<int>& array, int left, int right)
//{
//	if (left < right)
//	{
//		int low = left;
//		int high = right;
//		int pivot = array[(low + high) / 2];
//		while (low != high)								// ����С����,����ȵ�ʱ�������ѭ��
//		{
//			while (low < high && array[high] > pivot)  // ���������ҵ�һ��С��x����
//				high--;
//			while (low < high && array[low] < pivot)	// ���������ҵ�һ�����ڵ���x����
//				low++;
//			if (low < high)
//				swap(array[high], array[low]);
//			printArray(array);
//		}
//
//		quick(array, left, low - 1);
//		quick(array, low + 1, right);
//	}
//}

// �鲢
void Sort::merge(vector<int>& arr, int left, int mid, int right)
{
	vector<int> L_arr(arr.begin() + left, arr.begin() + mid);
	vector<int> R_arr(arr.begin() + mid, arr.begin() + right + 1);

	int i = 0, j = 0, k = left;
	while (i < L_arr.size() && j < R_arr.size()) {
		if (L_arr[i] < R_arr[j])
			arr[k++] = L_arr[i++];
		else
			arr[k++] = R_arr[j++];
	}

	while (i < L_arr.size())
		arr[k++] = L_arr[i++];
	while (j < R_arr.size())
		arr[k++] = R_arr[j++];
}

void Sort::mergeSort(vector<int>& arr, int left, int right)
{
	if (left == right)
		return;
	else {
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid + 1, right);
	}
}

// https://blog.csdn.net/alzzw/article/details/98087519
// ������
void Sort::adjust(vector<int>& nums, int len, int index)
{
	int left = 2 * index + 1;	// index�����ӽڵ�
	int right = 2 * index + 2;	// index�����ӽڵ�

	int maxIdx = index;
	if (left < len && nums[left] > nums[maxIdx])
		maxIdx = left;
	if (right < len && nums[right] > nums[maxIdx])
		maxIdx = right;

	if (maxIdx != index)
	{
		swap(nums[maxIdx], nums[index]);
		adjust(nums, len, maxIdx);
	}
}

void Sort::heapSort(vector<int>& nums, int size)
{
	for (int root = size / 2 - 1; root >= 0; root--) {
		adjust(nums, size, root);
	}
	for (int i = size - 1; i >= 1; i--) {
		swap(nums[0], nums[i]);
		adjust(nums, i, 0);
	}
}

