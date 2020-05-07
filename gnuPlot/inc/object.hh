#pragma once

#include <string>
#include <cstring>
#include <iostream>
#include <vector>

#include "gnuplot_link.hh"
#include "polygon.hh"
#include "vector.hh"

using Vector3 = Vector<double, 3>;

template <typename T, int SIZE>
class Object
{
private:
  PzG::GnuplotLink link;
  T object[SIZE];

  Vector3 realPosition;
  Vector3 objectRealPosition[SIZE];

  bool is_valid;
  std::string name;
  std::string tempPath = "../models/tmp/";
  std::string path = "../models/3d/";

  const bool putToTempFile()
  {
    std::ofstream file_stream;

    std::string tempName_temp = tempPath + name + ".dat";
    file_stream.open(tempName_temp);
    if (!file_stream.is_open())
    {
      std::cerr << ":(  Operacja otwarcia do zapisu \""
                << "../models/tmp/" + tempName_temp << "\"" << std::endl
                << ":(  nie powiodla sie." << std::endl;
      return false;
    }
    for (int i = 0; i < SIZE; i++)
    {
      std::cout << object[i];
      file_stream << objectRealPosition[i];
      file_stream << "#\n";
    }
    file_stream.close();

    is_valid = true;
    return true;
  }

public:
  Vector3 position;
  Vector3 rotation;

  bool load(std::string loadFileName, std::string objectName)
  {

    std::ifstream file_stream;
    file_stream.open(path + loadFileName);
    if (!file_stream.is_open())
    {
      std::cerr << "Operacja otwarcia pliku " << path + loadFileName << " nie powiodla sie." << std::endl;
      return false;
    }

    name = objectName;
    for (int i = 0; i < SIZE; i++)
    {
      file_stream >> object[i];
    }
    file_stream.close();
    is_valid = true;
    start();
    putToTempFile();
    return true;
  }
  bool draw()
  {
    char cstr[512];
    std::string tempName_temp = tempPath + name + ".dat";
    strcpy(cstr, tempName_temp.c_str());
    std::cout << "drawing: " << tempName_temp << std::endl;
    link.AddFilename(cstr, PzG::LS_CONTINUOUS, 1);
  }
  void start()
  {
    for (int i = 0; i < SIZE; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        realPosition.value[j] = 100;
        objectRealPosition[0].value[j] = 0;
        objectRealPosition[1].value[j] = 10;
      }
    }
    }
  void rotateZ(double z);
};