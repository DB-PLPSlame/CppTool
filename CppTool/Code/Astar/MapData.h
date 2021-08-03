#pragma once
/*
	��ͼ������
*/
#include <vector>
#include <list>
#include "Point.h"

class MapData
{
public:
	MapData() = default;
	~MapData() = default;
	MapData(Point const& start, Point const& end);
	MapData(Point const& start, Point const& end, int Max);

	std::vector<std::vector<int>>& GetMap() { return map; }	//�ṩ�޸ĺͷ��ʵ�ͼ�Ľӿ�
	void RandomMap(int mapSize);			//�������ָ����С��ͼ
	void PrintMap() const;					//��ӡ��ͼ
private:
	Point m_start;
	Point m_end;
	std::vector<std::vector<int>> map;
};
