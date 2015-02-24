/*
 * @file Search.h
 * @brief Algoritm of searching neighbors
 * @author Maxim Shpakovich (maxim.shpakovitch@yandex.ru)
 * created 24.02.2015
 */
#ifndef SEARCH_H_
#define SEARCH_H_
#include "Typedef.h"

namespace SPH
{


class NeighborsSearch
{
public:

    NeighborsSearch(double radius_, double epsilon_, double xmax_, double ymax_);

    bool Search(Points& _particles, VectorOfSizeTVectors& _result);

private:

    struct Box
{
    SizeTVector points;
};
    double m_width;

    double m_height;

    double m_radius;

    double m_epsilon;

    int m_count;

};

}//SPH
#endif