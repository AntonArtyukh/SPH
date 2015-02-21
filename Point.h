/*
 * @file Point.h
 * @brief Point class declaration
 * @author Maxim Shpakovich (maxim.shpakovitch@yandex.ru)
 * created 17.02.2015
 */

#ifndef POINT_H_193E66CE4E38469095BEA102E55A4A0C
#define POINT_H_193E66CE4E38469095BEA102E55A4A0C


#include "Typedef.h"

namespace SPH
{

/// @brief Point class describes point type
class Point
{
public:

    /// @brief default constructor
    Point();

    /// @brief constructor
    /// @param [in] x    x-coordinate in Cartesian domain
    /// @param [in] y    y-coordinate in Cartesian domain
    Point(double x, double y);

    /// @brief overloaded assignment operator
    Point& operator=(const Point& other);

    /// @brief overloaded multiplication operator
    Point& operator*(const Point& other);

    /// @brief overloaded addition operator
    Point& operator+(const Point& other);

    /// @brief function of scalar product
    /// @param [in] left    left-first point of scalar product
    /// @param [in] right    right-secont point of scalar product
    double Scalar_product(const Point& left, const Point& right);


    double getX();

    double getY();

private:

    double m_x;

    double m_y;
};


} // SPH

#endif // POINT_H_193E66CE4E38469095BEA102E55A4A0C

