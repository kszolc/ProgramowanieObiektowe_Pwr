#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

#include "gnuplot_link.hh"
#include "polygon.hh"
#include "fps.hh"
#include "object.hh"


using namespace std;
using Triangle3 = Object<Rectangle,2>;




int main()
{
  Rectangle rect;        // To tylko przykladowe definicje zmiennej
  PzG::GnuplotLink link; // Ta zmienna jest potrzebna do wizualizacji
                         // rysuPolygon
  
  Triangle3 triangle;
  FrameTime fps_measure;
  char c;
  double mo[3];
  mo[0] = -100;
  mo[1] = -200;
  mo[2] = 100;
  
  triangle.load("cuboid.dat","trojkat");
  link.SetDrawingMode(PzG::DM_3D);
  fps_measure.measure();
  triangle.draw();
  link.Draw();
  fps_measure.wait(50);

  /*
  punkt[0].loadFromFile("../models/3d/point.dat", 0);
  punkt[0].drawQueue();
  link.Draw();
  punkt[0].move(mo);
  while (1)
  {
  //  fps_measure.wait(0.5);
    fps_measure.measure();
  //  cout<<"fps: " <<fps_measure.fps_now<<endl;
    //for(int i = 0 ; i <3;i++) mo[i] +=1;
    punkt[0].update(fps_measure.fps_now);
    //punkt[0].tp(mo);
    link.Draw();
    
  }
  */

  return 0;
}
