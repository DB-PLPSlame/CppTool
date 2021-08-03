#pragma once
#include <iostream>
#include <vector>

// �ڴ�й©���
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>


class DetectMemoryLeaks
{
public:
	DetectMemoryLeaks()
	{
		// ǰ���������
		//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	}
	~DetectMemoryLeaks()
	{
		std::cout << "Memory leak test!" << std::endl;
		_CrtDumpMemoryLeaks();
	}

	void SetBreakAlloc(int breakPointIndex)
	{
		_CrtSetBreakAlloc(breakPointIndex);
	}

	void SetBreakAlloc(const std::vector<int>& vec)
	{
		for (auto bp : vec)
		{
			_CrtSetBreakAlloc(bp);
		}
	}
};
