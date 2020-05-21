#include "rotor.hh"

void Rotor::ApplyShift()
{
    for (int i = 0; i < rect.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            rect[i].point[j] += position;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        position.value[i] = 0;
    }
}