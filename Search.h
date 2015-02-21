/*
 * @file Search.h
 * @brief Algoritm of searching neighbors
 * @author Maxim Shpakovich (maxim.shpakovitch@yandex.ru)
 * created 19.02.2015
 */
#ifndef SEARCH_H_
#define SEARCH_H_
#include "Typedef.h"

namespace SPH
{
/// @brief Search class describes algoritm of searching neighbors
class Search
{
public:
    /// @brief constructor
    /// @param [in] SET    SET-set of points
    /// @param [in] WIDTH    WIDTH-width of field
    /// @param [in] HEIGH    HEIGH-heigh of field
    /// @param [in] RADIUS    RADIUS-radius of searching
    Search(Points SET, double WIDTH, double HEIGHT, double RADIUS);



    VectorOfSizeTVectors Find();



    Points _particles;


private:

    const int _GRID_WIDTH;

    const int _GRID_HEIGHT;

    double m_width;

    double m_height;

    double m_radius;

    const int _GRID_WIDTH;

    const int _GRID_HEIGHT;

};

}
#endif