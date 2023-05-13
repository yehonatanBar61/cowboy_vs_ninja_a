#include "Team.hpp"

using namespace ariel;

Point::Point(double x, double y): x(x), y(y) {}

double Point::distance(Point p) {
    double a = pow(p.x - this->x, 2);
    double b = pow(p.y - this->y, 2);
    return sqrt(a + b);
}

string Point::print() const{
    return "(" + to_string(this->x) + "," + to_string(this->y)  + ")";
}

Point moveTowards(Point src, Point des, double dis) {
    return Point(1,1);
}

double Point::getX() {
    return this->x;
}

double Point::getY() {
    return this->y;
}

bool Point::operator==(const Point &other) const {
    return x == other.x && y == other.y;
}

