#include "Model.hh"

class Rotor : public Model
{
private:
  Ftime fps;
  Vector3 CalcRotate();

public:
  void ApplyShift();
};