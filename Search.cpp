/*
 * @file Search.cpp
 * @brief Search class implementation
 * @author Maxim Shpakovich (maxim.shpakovitch@yandex.ru)
 * created 17.02.2015
 */
#include"Search.h"

namespace SPH
{
    Search::Search(Points SET, double WIDTH, double HEIGHT, double RADIUS) :
    m_width(WIDTH), m_height(HEIGHT), m_radius(RADIUS), _particles(SET),
    _GRID_WIDTH((int)(m_width/m_radius)),_GRID_HEIGHT((int)(m_height/m_radius))
    {}

    VectorOfSizeTVectors Search::Find()
    {

        Points _grid[_GRID_WIDTH][_GRID_HEIGHT];

        for (int i = 0; i < _GRID_WIDTH; ++i) 
        {
            for (int j = 0; j < _GRID_HEIGHT; ++j)
            {
                _grid[i][j].clear();
            }
        }


        for(int i=0;i<_grid.size();++i)
        {
            int x = (int)(_particles[i].getX()/m_radius);

            int y = (int)(_particles[i].getY()/m_radius);

            _grid[x][y].push_back(_particles[i]);
        }


}