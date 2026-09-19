// yuan.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
class Point
{
public:
	Point(int x, int y) : m_x(x), m_y(y) {}
	int getX()
	{
		return m_x;
	}
	int getY()
	{
		return m_y;
	}
private:
	int m_x;
	int m_y;
};

class Circle
{
public:
	Circle(Point center, int radius) : m_center(center), m_radius(radius) {}
	Point getCenter()
	{
		return m_center;
	}
	int getRadius()
	{
		return m_radius;
	}
private:
	Point m_center;
	int m_radius;
};
int main()
{
	cout << "请输入圆心坐标和半径：" << endl;
	int x, y, r;
	cin >> x >> y >> r;

	Point C_point(x, y);
	Circle circle(C_point, r);

	Point p1(1, 1);
	Point p2(2, 5);
	Point p3(3, 4);
	

	int x1_diff = (p1.getX() - circle.getCenter().getX()) * (p1.getX() - circle.getCenter().getX());
	int y1_diff = (p1.getY() - circle.getCenter().getY()) * (p1.getY() - circle.getCenter().getY());
	int x2_diff = (p2.getX() - circle.getCenter().getX()) * (p2.getX() - circle.getCenter().getX());
	int y2_diff = (p2.getY() - circle.getCenter().getY()) * (p2.getY() - circle.getCenter().getY());
	int x3_diff = (p3.getX() - circle.getCenter().getX()) * (p3.getX() - circle.getCenter().getX());
	int y3_diff = (p3.getY() - circle.getCenter().getY()) * (p3.getY() - circle.getCenter().getY());

	if (x1_diff + y1_diff < circle.getRadius() * circle.getRadius())
	{
		cout << "p1在圆内" << endl;
	}
	else if (x1_diff + y1_diff == circle.getRadius() * circle.getRadius())
	{
		cout << "p1在圆上" << endl;
	}
	else
	{
		cout << "p1在圆外" << endl;
	}

	if (x2_diff + y2_diff < circle.getRadius() * circle.getRadius())
	{
		cout << "p2在圆内" << endl;
	}
	else if (x2_diff + y2_diff == circle.getRadius() * circle.getRadius())
	{
		cout << "p2在圆上" << endl;
	}
	else
	{
		cout << "p2在圆外" << endl;
	}

	if (x3_diff + y3_diff < circle.getRadius() * circle.getRadius())
	{
		cout << "p3在圆内" << endl;
	}
	else if (x3_diff + y3_diff == circle.getRadius() * circle.getRadius())
	{
		cout << "p3在圆上" << endl;
	}
	else
	{
		cout << "p3在圆外" << endl;
	}
}

