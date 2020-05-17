#pragma once

//#include "Object.hh"
#include "gnuplot_link.hh"
#include "vector.hh"
#include <vector>
#include "fps.hh"
#include "Player.hh"
#include "Model.hh"

/**
 * @brief Class what operates all objects
 * 
 *  It defines all obects, manages their movement, rendering and all other stuff
 */
class Scene
{
  /**
   * @brief instance of time managing class
   * 
   */
Ftime fps;
/**
 * @brief link to gnuplot, required to render
 * 
 */
PzG::GnuplotLink  link;
/**
 * @brief instance of player
 * required to operate on it
 */
Player player;
/**
 * @brief all static meshes
 * 
 */
std::vector<Model> models;


public:
/**
 * @brief Startup sequence, loading data, setting rendering ect
 * 
 */
  void Start();
  /**
   * @brief Manages comunication, and frame rendering
   * 
   * @return true - continue running
   * @return false - program-exit code
   */
  bool Update();

};