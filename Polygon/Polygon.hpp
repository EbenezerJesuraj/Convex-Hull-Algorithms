#ifndef POLYGON_H_INCLUDED
#define POLYGON_H_INCLUDED
#include <iostream>
#include <vector>
#include <algorithm>
#include "../Point/Point.hpp"

using namespace std;

class Polygon
{
private:
    vector<Point> pntSet;

public:
    Polygon(vector<Point>);
    void addPoint(Point);
    void delPoint(int);
    int getNumOfPoints();
    Point getPoint(int);
    void setPoints(vector<Point> &);
};

#endif // POLYGON_H_INCLUDED
