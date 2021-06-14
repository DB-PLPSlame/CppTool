//�����ʼ����ͼ��Ѱ·�㷨ʵ��
#include <iostream>
#include "AStarUtil.h"
#include "MapData.h"

#if 0
#define	CUSTOM	//�Զ����ͼ
#else
#define	RANDOM	//�����ͼ
#endif // 0

#ifdef RANDOM
const int Max = 20;
#endif // RANDOM

int main()
{	
	using namespace std;
	//������ʼ�ͽ�����
	Point start(1, 1);
#ifdef RANDOM
	Point end(Max - 2, Max - 2);

	//�����ʼ����ͼ
	MapData maze(start, end, Max);
#elif defined(CUSTOM)
	Point end(6, 10);	//�Զ����ͼ�յ�

	MapData maze(start, end);
	//�Զ����ʼ����ͼ���ö�ά��������ͼ��1��ʾ�ϰ��0��ʾ��ͨ
	maze.GetMap() = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,0,1,1,0,1,0,0,0,0,1 },
		{ 1,0,0,1,1,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,1,0,0,1,1,1 },
		{ 1,1,1,0,0,0,0,0,1,1,0,1 },
		{ 1,1,0,1,0,0,0,0,0,0,0,1 },
		{ 1,0,1,0,0,0,0,1,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1 }
	};
#endif // RANDOM/CUSTOM

	Astar& astar = Astar::getInstance();
	astar.InitAstar(maze.GetMap());

	//A*�㷨��Ѱ·����������ڵ�ͼ������
	list<std::shared_ptr<Point>> const& path = astar.GetPath(start, end, maze.GetMap(), false);

	//���ھʹ�ӡ·��
	if (!path.empty())
	{
/*		for (auto &p : path)
			cout << '(' << p->x << ',' << p->y << ')' << endl;*/
		cout << "���·����\n";
		maze.PrintMap();
	}else {
		cout << "�Ҳ���·����\n";
		maze.PrintMap();
	}
	astar.release();

	return 0;
}