#pragma once

#include "Rectangle.hh"
#include "gnuplot_link.hh"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

class Model
{
private:

/**
 * @brief Writing whole model to temporary file.
 *  Renderer uses it later to render this model
 * 
 * @param shift Shift from startup position. This makes moving work
 * @return true - all went good
 * @return false - something went wrong, expext program to die its natural way
 */
  bool PutToFile(Vector3 shift, Vector3 angle);

  PzG::GnuplotLink  link;

public:

  //number of all models in game
  static int count;

  //number of all rectangles
  static int meshes;

  //specyfic number of this mesh
  int id;

  //Enamble/disable rendering mesh
  bool isActive;

  Vector3 position;
  Vector3 rotation;
  //Destination of dynamic movement
  Vector3 posDest;
  //Destination of dynamic rotation
  Vector3 rotDest;

  //container of all rectangles in this model
  std::vector<Rectangle> rect;

/**
 * @brief Load model data from "model" directory
 * 
 * @param fileName name of file we want to load data from
 * @return true - all done, we are good to go
 * @return false - something went horribly wrong
 */
  bool LoadFromFile(std::string fileName);
  /**
 * @brief Add this model to queue of drawing
 * 
 */
  void Draw();
  /**
 * @brief Startup settings of mesh renderrer
 * 
 */
  void Start();

  /**
   * @brief Check if moving object achived its destination
   * 
   * @return true - yes
   * @return false - no
   */
  const bool achivedDestination();
  const bool achivedRotationDestination();
};  
