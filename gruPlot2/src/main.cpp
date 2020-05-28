#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "vector.hh"
#include "Model.hh"
#include "Player.hh"
#include "Scene.hh"
#include "gnuplot_link.hh"
#include "BoxCollider.hh"

using namespace std;


int Model::count = 0;
int Model::meshes = 0;
vector<Vector3> SphereCollider::colliders;
vector<double> SphereCollider::radius;
vector<string> SphereCollider::names;
string SphereCollider::nameOfCollision;
bool SphereCollider::stopMoving;
double Ftime::fps = 1;
double Ftime::ms = 1000;
bool Ftime::showFps = 0;


int main()
{

  Scene gameScene;


  gameScene.Start();
  while (gameScene.Update());

}
