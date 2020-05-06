#pragma once
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

#include "gnuplot_link.hh"

template <int SIZE>
class Pointtemp
{
private:
  double pos[SIZE];
  std::string name;
  std::string tempName;
  PzG::GnuplotLink link;

  double destination[SIZE];
  double remaining_move[SIZE];

  double length(double vec[])
  {
    double result = 0;
    for (int i = 0; i < SIZE; i++)
    {
      result += vec[i] * vec[i];
    }
    return sqrt(result);
  }

  void dynamicMovement(double frames)
  {
    //std::cout << "dynMoving\n";
    double ratio[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
      remaining_move[i] = destination[i] - pos[i];
      ratio[i] = abs(remaining_move[i]) / length(remaining_move);
    }
    for (int i = 0; i < SIZE; i++)
    {
      pos[i] += destination[i] * (speed * ratio[i] / frames);
      std::cout<<"adding: " <<destination[i] * (speed * ratio[i] / frames) << std::endl;
    }
    char c;
  //  std::cin >> c;
    if (length(remaining_move) < 3)
      moving = false;
    
    drawQueue();
  }

public:
  int id;

  float speed = 0.2;
  /**
   * @brief Is point correctly initialized, and has asigned position?
   * true - yes
   * false - no
   */
  bool valid;

  /**
   * @brief Is point currently moving?
   * true - yes
   * false - no
   */
  bool moving;

  /**
 * @brief Loads start parameters of point from file, and validates object
 * 
 * @param filename - path to the source file
 * @param id - id number of object
 * @return true  - loading data finished successfully 
 * @return false - loading data failed
 */
  bool loadFromFile(std::string filename, int id_number)
  {
    id = id_number;
    tempName ="../models/tmp/point_"+ std::to_string(id_number) +".pos";
    std::ifstream file_stream;

    file_stream.open(filename);
    if (!file_stream.is_open())
    {
      std::cerr << ":(  Operacja otwarcia do odczytu \"" << filename << "\"" << std::endl
                << ":(  nie powiodla sie." << std::endl;
      return false;
    }
    name = filename;
    for (int i = 0; i < SIZE; i++)
    {
      file_stream >> pos[i];
    } 
    file_stream.close();
    putToTempFile();
    return true;
  }
  bool putToTempFile()
  {
    std::ofstream file_stream;

    file_stream.open(tempName);
    if (!file_stream.is_open())
    {
      std::cerr << ":(  Operacja otwarcia do zapisu \"" << "../models/tmp/" + tempName<< "\"" << std::endl
                << ":(  nie powiodla sie." << std::endl;
      return false;
    }
    for (int i = 0; i < SIZE; i++)
    {
      file_stream << pos[i] << "  ";
    }
    file_stream << " \n";
    file_stream.close();
    valid = true;
    return true;
  }
  /**
   * @brief Ads point to queue of drawing
   * 
   * @return true - done correctly
   * @return false - point is unitialized, change its position to do so
   */
  bool drawQueue()
  {
    putToTempFile();
    if (valid)
    {
      char cstr[512];
      strcpy(cstr, tempName.c_str());
      std::cout <<"drawing: " <<tempName <<std::endl;
      link.AddFilename(cstr, PzG::LS_SCATTERED, 1);
      
    }
    else
    {
      std::cerr << "There is no writen temporary data of point "<<id << std::endl;
      return false;
    }
  }

  void move(double shift[])
  {
    
    //check if vector of movement is not zero
    if (length(shift) > 0.00001)
    {
     
      moving = true;
      for (int i = 0; i < SIZE; i++)
      {
        destination[i] += shift[i];
        std::cout<<"destination: " << destination[i] <<std::endl;
      }
    }
  }
  void tp(double tp_pos[]){
     for (int i = 0; i < SIZE; i++)
      {
        pos[i]=tp_pos[i];
        std::cout << pos[i] <<std::endl;
      }

      drawQueue();
  }
  void update(double frames)
  {
    //std::cout <<"updating\n";
    if (moving)
    {
      dynamicMovement(frames);
    }
  }
};