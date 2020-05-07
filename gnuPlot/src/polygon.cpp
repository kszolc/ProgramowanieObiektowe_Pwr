#include "polygon.hh"

Triangle Triangle::operator+(Vector<double, 3> vec)
{
    Triangle result;
    for (int i = 0; i < 3; i++)
    {
        result.point[i] = point[i] + vec;
    }
    return result;
}

Rectangle Rectangle::operator+(Vector<double, 3> vec)
{
    Rectangle result;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << point[i].value[j] << " ";
            result.point[i].value[j] = point[i].value[j] + vec.value[j];
        }
    }

    return result;
}