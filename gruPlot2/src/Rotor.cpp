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

Vector3 Rotor::CalcRotate(){
    int rotationSpeed = 10;
    
  double rad = 360 * M_PI /180;
  Vector3 result;
  result.value[0] = cos(rad) * position.value[0] + sin(rad) * position.value[1];
  result.value[1] = -sin(rad) * position.value[0] + cos(rad) * position.value[1];
  result.value[2] = position.value[2];
  return result;
}