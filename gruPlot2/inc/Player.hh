#pragma once

#include "Model.hh"
/**
 * @brief Class what defines all required information of player, its movvement etc
 * 
 */
class Player : public Model
{
private:
  /**
   * @brief position before movement
   * 
   */
  Vector3 prevPos;
  /**
   * @brief distance left to destination
   * 
   */
  Vector3 toMove;
  /**
   * @brief  angle left to destination
   * 
   */
  Vector3 toRotate;
  /**
   * @brief angle before rotating
   * 
   */
  Vector3 prevRot;
  /**
   * @brief Makes movement ant rotation smooth instead of teleporting
   * ! Requires instance of Ftime class
   * 
   * @return true - we are still moving
   * @return false - moving finished
   */
  bool dynamicMovement();
  /**
   * @brief instance of Ftime class
   * 
   */
  Ftime fps;

public:
  /**
   * @brief is object moving?
   * 
   */
  bool isMoving;
  /**
   * @brief is object rotating?
   * 
   */
  bool isRotating;
  /**
   * @brief speed of dynamic movement
   * 
   */
  float movementSpeed = 10;
  /**
   * @brief change position of object
   * 
   * dynamicMovement() makes it smooth instead of teleporting 
   * @param movementVector vector we want object to move
   * @return true - all good
   * @return false - not good
   */
  bool Move(Vector3 movementVector);
  /**
   * @brief change rotation of object
   * dynamicMovement() makes it smooth instead of teleporting 
   * @param rotateVector vector we want our object rotate
   * @return true - all good
   * @return false - not good
   */
  bool Rotate(Vector3 rotateVector);
  /**
   * @brief Updating position and rendering it
   * 
   * @return true - object is moving, and all magic happens 
   * @return false - nothing is happening, computer resources are saved
   */
  bool Update();
  /**
   * @brief Some startup settings, need to be activated on start!
   * 
   * @return true - loading player model data complete!
   * @return false - loading player model data failed!
   */
  bool Start();
};