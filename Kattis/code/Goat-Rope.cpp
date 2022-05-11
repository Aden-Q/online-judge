// Goat Rope

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

double min_dist = 10000000.0;

typedef struct Point {
	int x;
	int y;
	Point(int x, int y):x(x), y(y) {}	// constructor
} P;

double distance(P p1, P p2);

double distance(P p1, P p2) {
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

int main() {
	int x,y,x1,y1,x2,y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	Point p(x,y), p1(x1,y1), p2(x2,y2);
	Point p3(x1,y2), p4(x2,y1);
	double cur_min = 10000000.0;
	if(y>=y1 && y<=y2) {
		if(x > x2)	min_dist = double(x-x2);
		else if(x < x1)	min_dist = double(x1-x);
	}
	else if(x>x1 && x<x2) {
		if(y > y2)	min_dist = double(y-y2);
		else if(y < y1)	min_dist = double(y1-y);
	}
	else if(x>x2 && y>y2)
		min_dist = distance(p, p2);
	else if(x>x2 && y<y1)
		min_dist = distance(p, p4);
	else if(x<x1 && y>y2)
		min_dist = distance(p, p3);
	else
		min_dist = distance(p, p1);

	cout << min_dist << endl;

	return 0;
}
