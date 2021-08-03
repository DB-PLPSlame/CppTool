#include "AStarUtil.h"


Astar* Astar::s_instance = NULL;
int Astar::s_counter = 0;


Astar& Astar::getInstance(void)
{
	if (!s_instance)
		s_instance = new Astar();
	++s_counter;
	return *s_instance;
}
void Astar::release(void)
{
	if (s_counter && --s_counter == 0) {
		delete this;
		s_instance = NULL;
	}
}

void Astar::Clear(bool isDown)
{
	//��������ͼ����
	if (isDown) {
		openList.clear();
		closeList.clear();
	}
	else {
		path.clear();
	}
}

std::shared_ptr<Point> Astar::getLeastFpoint() const
{
	if (!openList.empty())
	{
		auto resPoint = openList.front();
		for (auto &point : openList)
			if (point->F < resPoint->F)
				resPoint = point;
		return resPoint;
	}
	return NULL;
}

void Astar::MarkPath(std::vector<std::vector<int>>& _maze) const
{
	for (auto &p : path)
		_maze[p->x][p->y] = 2;
}

std::shared_ptr<Point> Astar::findPath(Point const& start, Point const& end, bool isIgnoreCorner)
{
	openList.emplace_back(new Point(start.x, start.y));//�������,��������һ���ڵ㣬�������
	while (!openList.empty())
	{
		auto curPoint = getLeastFpoint();	//�ҵ�Fֵ��С�ĵ�  
		openList.remove(curPoint);			//�ӿ����б���ɾ��
		closeList.push_back(curPoint);		//�ŵ��ر��б�
		//1,�ҵ���ǰ��Χ�˸����п���ͨ���ĸ���  
		auto surroundPoints = getSurroundPoints(curPoint, isIgnoreCorner);
		for (auto &target : surroundPoints)
		{
			//2,��ĳһ�����ӣ���������ڿ����б��У����뵽�����б����õ�ǰ��Ϊ�丸�ڵ㣬����F G H  
			if (!isInList(openList, target.get()))
			{
				target->parent = curPoint;

				target->G = calcG(curPoint.get(), target.get());
				target->H = calcH(target.get(), &end);
				target->F = calcF(target.get());

				openList.push_back(target);
			}
			//3����ĳһ�����ӣ����ڿ����б��У�����Gֵ, �����ԭ���Ĵ�, ��ʲô������, �����������ĸ��ڵ�Ϊ��ǰ��,������G��F  
			else
			{
				int tempG = calcG(curPoint.get(), target.get());
				//�ӿ����б����ҵ���Ӧ�ĸ���
				for (auto &point : openList)
				{
					if ((target->x == point->x) && (target->y == point->y))
					{
						target = point;
						break;
					}
				}
				if (tempG < target->G)
				{
					target->parent = curPoint;
					target->G = tempG;
					target->F = calcF(target.get());
				}
			}
			std::shared_ptr<Point> resPoint = isInList(openList, &end);
			if (resPoint)
				return resPoint; //�����б���Ľڵ�ָ�룬��Ҫ��ԭ�������endpointָ�룬��Ϊ���������
		}
	}
	return NULL;
}

std::list<std::shared_ptr<Point>> const& Astar::GetPath(Point const& start, Point const& end, std::vector<std::vector<int>>& map, bool isIgnoreCorner)
{
	Clear(false);
	std::shared_ptr<Point> result = findPath(start, end, isIgnoreCorner);
	//����·�������û�ҵ�·�������ؿ�����  
	while (result)
	{
		path.push_front(result);
		result = result->parent;
	}
	MarkPath(map);
	Clear(true);
	return path;
}

std::shared_ptr<Point> Astar::isInList(const std::list<std::shared_ptr<Point>> &list, const Point* point) const
{
	//�ж�ĳ���ڵ��Ƿ����б��У����ﲻ�ܱȽ�ָ�룬��Ϊÿ�μ����б����¿��ٵĽڵ㣬ֻ�ܱȽ�����  
	for (auto p : list)
		if (p->x == point->x&&p->y == point->y)
			return p;
	return NULL;
}

bool Astar::isCanReach(const std::shared_ptr<Point> point, const std::shared_ptr<Point> target, bool isIgnoreCorner) const
{
	if (target->x<0 || target->x>maze.size() - 1
		|| target->y<0 || target->y>maze[0].size() - 1
		|| maze[target->x][target->y] == 1
		|| target->x == point->x&&target->y == point->y
		|| isInList(closeList, target.get())) //������뵱ǰ���غϡ�������ͼ�����ϰ�������ڹر��б��У�����false  
		return false;

	if (abs(point->x - target->x) + abs(point->y - target->y) == 1) //��б�ǿ���  
		return true;
	else
	{
		//б�Խ�Ҫ�ж��Ƿ��ס  
		if (maze[point->x][target->y] == 0 && maze[target->x][point->y] == 0)
			return true;
		else
			return isIgnoreCorner;
	}
}

std::vector<std::shared_ptr<Point>> Astar::getSurroundPoints(const std::shared_ptr<Point> point, bool isIgnoreCorner)
{
	std::vector<std::shared_ptr<Point>> surroundList;

	for (int x = point->x - 1; x <= point->x + 1; x++)
		for (int y = point->y - 1; y <= point->y + 1; y++) {
			std::shared_ptr<Point> surroundPoint = std::make_shared<Point>(x, y);
			if (isCanReach(point, surroundPoint, isIgnoreCorner))
				surroundList.push_back(surroundPoint);
		}
	return surroundList;
}