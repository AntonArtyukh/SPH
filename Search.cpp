/*
 * @file Search.cpp
 * @brief Search class implementation
 * @author Maxim Shpakovich (maxim.shpakovitch@yandex.ru)
 * created 02.03.2015
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
    Boxes.clear();
    int temp = 0;
    int M =((int)(m_width/m_radius));
    for(int i=0;i<_particles.size();++i)
    {
        Boxes[((int)(_particles[i].getY()/m_radius))*((int)(m_width/m_radius))+((int)(_particles[i].getX()/m_radius))].box_points.push_back(i);
    }
    for(int i=0;i<_particles.size();++i)
    {
        temp = ((int)(_particles[i].getY()/m_radius))*((int)(m_width/m_radius))+((int)(_particles[i].getX()/m_radius));
        if(temp%((int)(m_width/m_radius))==0)//правый ряд
        {
            if(temp==((int)(m_width/m_radius)))//нижний правый
            {
                for(int j=0;j<Boxes[temp+M-1].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp+M-1].box_points[j]);
                }
                for(int j=0;j<Boxes[temp+M].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp+M].box_points[j]);
                }
                for(int j=0;j<Boxes[temp-1].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp-1].box_points[j]);
                }
                for(int j=0;j<Boxes[temp].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp].box_points[j]);
                }
            }

            if(temp==(((int)(m_width/m_radius))*(((int)(m_height/m_radius))+1)))//верхний правый
            {
                for(int j=0;j<Boxes[temp-1].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp-1].box_points[j]);
                }
                for(int j=0;j<Boxes[temp-M-1].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp-M-1].box_points[j]);
                }
                for(int j=0;j<Boxes[temp-M].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp-M].box_points[j]);
                }
                for(int j=0;j<Boxes[temp].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp].box_points[j]);
                }

            }
            else//средина правого
            {
                for(int j=0;j<Boxes[temp-1].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp-1].box_points[j]);
                }
                for(int j=0;j<Boxes[temp-M-1].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp-M-1].box_points[j]);
                }
                for(int j=0;j<Boxes[temp-M].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp-M].box_points[j]);
                }
                for(int j=0;j<Boxes[temp+M-1].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp+M-1].box_points[j]);
                }
                for(int j=0;j<Boxes[temp+M].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp+M].box_points[j]);
                }
                for(int j=0;j<Boxes[temp].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp].box_points[j]);
                }

            }
        }
        if(temp%((int)(m_width/m_radius))==1)//левый ряд
        {
            if(temp==1)//нижний левый
            {
                for(int j=0;j<Boxes[temp+1].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp+1].box_points[j]);
                }
                for(int j=0;j<Boxes[temp+M].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp+M].box_points[j]);
                }
                for(int j=0;j<Boxes[temp+M+1].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp+M+1].box_points[j]);
                }
                for(int j=0;j<Boxes[temp].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp].box_points[j]);
                }
            }
            if(temp==(((int)(m_width/m_radius))*((int)(m_height/m_radius))+1))//верхний левый
            {
                for(int j=0;j<Boxes[temp+1].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp+1].box_points[j]);
                }
                for(int j=0;j<Boxes[temp-M].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp-M].box_points[j]);
                }
                for(int j=0;j<Boxes[temp-M+1].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp-M+1].box_points[j]);
                }
                for(int j=0;j<Boxes[temp].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp].box_points[j]);
                }
            }
            else//средина левого
            {
                for(int j=0;j<Boxes[temp+1].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp+1].box_points[j]);
                }
                for(int j=0;j<Boxes[temp-M].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp-M].box_points[j]);
                }
                for(int j=0;j<Boxes[temp-M+1].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp-M+1].box_points[j]);
                }
                for(int j=0;j<Boxes[temp+M].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp+M].box_points[j]);
                }
                for(int j=0;j<Boxes[temp+M+1].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp+M+1].box_points[j]);
                }
                for(int j=0;j<Boxes[temp].box_points.size();++j)
                {
                    _result[i].push_back(Boxes[temp].box_points[j]);
                }
            }
        }
        if(temp>1 && temp <((int)(m_width/m_radius)))//средина низа
        {
            for(int j=0;j<Boxes[temp-1].box_points.size();++j)
            {
                _result[i].push_back(Boxes[temp-1].box_points[j]);
            }
            for(int j=0;j<Boxes[temp+1].box_points.size();++j)
            {
                _result[i].push_back(Boxes[temp+1].box_points[j]);
            }
            for(int j=0;j<Boxes[temp+M-1].box_points.size();++j)
            {
                _result[i].push_back(Boxes[temp+M-1].box_points[j]);
            }
            for(int j=0;j<Boxes[temp+M].box_points.size();++j)
            {
                _result[i].push_back(Boxes[temp+M].box_points[j]);
            }
            for(int j=0;j<Boxes[temp+M+1].box_points.size();++j)
            {
                _result[i].push_back(Boxes[temp+M+1].box_points[j]);
            }
            for(int j=0;j<Boxes[temp].box_points.size();++j)
            {
                _result[i].push_back(Boxes[temp].box_points[j]);
            }

        }
        if(temp>(((int)(m_width/m_radius))*((int)(m_height/m_radius))+1) && temp<(((int)(m_width/m_radius))*(((int)(m_height/m_radius))+1)))//средина верха
        {
            for(int j=0;j<Boxes[temp-1].box_points.size();++j)
            {
                _result[i].push_back(Boxes[temp-1].box_points[j]);
            }
            for(int j=0;j<Boxes[temp+1].box_points.size();++j)
            {
                _result[i].push_back(Boxes[temp+1].box_points[j]);
            }
            for(int j=0;j<Boxes[temp-M-1].box_points.size();++j)
            {
                _result[i].push_back(Boxes[temp-M-1].box_points[j]);
            }
            for(int j=0;j<Boxes[temp-M].box_points.size();++j)
            {
                _result[i].push_back(Boxes[temp-M].box_points[j]);
            }
            for(int j=0;j<Boxes[temp-M+1].box_points.size();++j)
            {
                _result[i].push_back(Boxes[temp-M+1].box_points[j]);
            }
            for(int j=0;j<Boxes[temp].box_points.size();++j)
            {
                _result[i].push_back(Boxes[temp].box_points[j]);
            }
        }
        else
        {
            for(int j=0;j<Boxes[temp-1].box_points.size();++j)
            {
                _result[i].push_back(Boxes[temp-1].box_points[j]);
            }
            for(int j=0;j<Boxes[temp+1].box_points.size();++j)
            {
                _result[i].push_back(Boxes[temp+1].box_points[j]);
            }
            for(int j=0;j<Boxes[temp-M-1].box_points.size();++j)
            {
                _result[i].push_back(Boxes[temp-M-1].box_points[j]);
            }
            for(int j=0;j<Boxes[temp-M].box_points.size();++j)
            {
                _result[i].push_back(Boxes[temp-M].box_points[j]);
            }
            for(int j=0;j<Boxes[temp-M+1].box_points.size();++j)
            {
                _result[i].push_back(Boxes[temp-M+1].box_points[j]);
            }
            for(int j=0;j<Boxes[temp+M-1].box_points.size();++j)
            {
                _result[i].push_back(Boxes[temp+M-1].box_points[j]);
            }
            for(int j=0;j<Boxes[temp+M].box_points.size();++j)
            {
                _result[i].push_back(Boxes[temp+M].box_points[j]);
            }
            for(int j=0;j<Boxes[temp+M+1].box_points.size();++j)
            {
                _result[i].push_back(Boxes[temp+M+1].box_points[j]);
            }
            for(int j=0;j<Boxes[temp].box_points.size();++j)
            {
                _result[i].push_back(Boxes[temp].box_points[j]);
            }
        }
    }
    return true;

}



}//SPH