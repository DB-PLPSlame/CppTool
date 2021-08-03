#pragma once
/*
	���������
*/
struct Point
{
	int x, y;		//�����꣬����Ϊ�˷��㰴��C++�����������㣬x������ţ�y��������
	int F, G, H;	//F=G+H
	std::shared_ptr<Point> parent;	//parent������

	Point() = default;
	Point(int _x, int _y)
		: x(_x), y(_y), F(0), G(0), H(0), parent(0) {}
};
