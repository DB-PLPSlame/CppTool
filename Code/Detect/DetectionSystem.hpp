#pragma once
#include <ctime>


class SystemDetection
{
public:
	/*********************************************************
	 * ʹ�����͵�ǿ��ת��ʵ��little-endian��big-endian���ж�
	 *********************************************************
	 * ����ֵ��
	 *          1 ��ʾ��С���ֽ���
	 *          0 ��ʾ����С���ֽ���
	 *********************************************************/
	static bool IsLittleEndian()
	{
		unsigned short flag = 0x4321;
		if (*(unsigned char*)&flag == 0x21)
			return true;
		else
			return false;
	}
};
