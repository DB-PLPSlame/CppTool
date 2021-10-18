#include "Sort.h"

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
void Sort::quick(vector<int>& array, int left, int right)
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

		quick(array, left, low - 1);
		quick(array, low + 1, right);
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

void Sort::bubble(vector<int>& array)
{
	for (int j = array.size() - 1; j >= 0; j--)
		for (int i = 0; i < j; i++)
			if (array[i] > array[i + 1])
				swap(array[i], array[i + 1]);
}
