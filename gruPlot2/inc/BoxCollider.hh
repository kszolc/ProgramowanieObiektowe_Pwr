#pragma once
#include <vector>
#include <string>

#include "vector.hh"
#include "Model.hh"

class SphereCollider
{
public:
  static std::vector<Vector3> colliders;
  static std::vector<double> radius;
  static std::vector<std::string> names;
  static std::string nameOfCollision;
  static bool stopMoving;

  int setSphereCollider(Vector3 stats,double rad,std::string name);

  void CheckCollision();

};