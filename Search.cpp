/*
 * @file Search.cpp
 * @brief Search class implementation
 * @author Maxim Shpakovich (maxim.shpakovitch@yandex.ru)
 * created 24.02.2015
 */
#include"Search.h"

namespace SPH
{


NeighborsSearch::NeighborsSearch(double radius_, double epsilon_, double xmax_, double ymax_)
{
    m_radius = radius_;

    m_width = xmax_;

    m_height = ymax_;

    m_epsilon = epsilon_;

    m_count = (int)((m_width/m_radius)*(m_height/m_radius));

}

bool NeighborsSearch::Search(Points& _particles, VectorOfSizeTVectors& _result)
{
    std::vector<Box> Boxes(m_count);


}



}//SPH