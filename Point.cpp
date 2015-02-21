/*
 * @file Point.cpp
 * @brief Point class implementation
 * @author Maxim Shpakovich (maxim.shpakovitch@yandex.ru)
 * created 17.02.2015
 */
#include "Point.h"

namespace SPH
{

Point::Point() : m_x(0.), m_y(0.)
{}

Point::Point(double x, double y) : m_x(x), m_y(y)
{}

Point& Point::operator=(const Point& other)
{
    m_x = other.m_x;
    m_y = other.m_y;
    return *this;
}

Point& Point::operator*(const Point& other)
{
    Point temp;
    temp.m_x = m_x * other.m_x;
    temp.m_y = m_y * other.m_y;
    return temp;
}

Point& Point::operator+(const Point& other)
{
    Point temp;
    temp.m_x = m_x + other.m_x;
    temp.m_y = m_y + other.m_y;
    return temp;
}

 double Point::Scalar_product(const Point& left, const Point& right)
{

    double result;
    result = left.m_x * right.m_x + left.m_y * right.m_y;
    return result;

}

 double Point::getX() {return m_x;}

 double Point::getY() {return m_y;}

} // SPH