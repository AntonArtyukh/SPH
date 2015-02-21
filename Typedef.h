/*
 * @file Typedef.h
 * @brief Typedef of vector
 * @author Maxim Shpakovich (maxim.shpakovitch@yandex.ru)
 * created 19.02.2015
 */

#ifndef TYPEDEF_H_
#define TYPEDEF_H_

#include"Point.h"
#include <vector>

namespace SPH
{

    typedef std::vector<Point> Points; 
    typedef std::vector<Point>::iterator PointsIterator;
    typedef std::vector<Point>::const_iterator PointsConstIterator;

    typedef std::vector<size_t> SizeTVector; 
    typedef std::vector<size_t>::iterator SizeTIterator;
    typedef std::vector<size_t>::const_iterator SizeTConstIterator;

    typedef std::vector<SizeTVector> VectorOfSizeTVectors;
    typedef std::vector<SizeTVector>::iterator VectorOfSizeTVectorsIterator;
    typedef std::vector<SizeTVector>::const_iterator VectorOfSizeTVectorsConstIterator;

}//SHP
#endif