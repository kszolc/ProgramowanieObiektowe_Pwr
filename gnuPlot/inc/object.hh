#pragma once

#include <string>
#include <cstring>
#include <iostream>

#include "gnuplot_link.hh"
#include "polygon.hh"

using Vector3 = Point3;

template <typename T, int SIZE>
class Object
{
private:
  T subObject[SIZE];

  Vector3 realPosition;
  Vector3 objectRealPosition[SIZE];

  bool is_valid;
  std::string name;
  std::string tempPath = "../models/tmp/";
  std::string path = "../models/3d/";

  const bool putToTempFile()
  {
    std::ofstream file_stream;
    for (int i = 0; i < SIZE; i++)
    {
      std::string tempName_temp = tempPath + name + std::to_string(i) + ".dat";
      file_stream.open(tempName_temp);
      if (!file_stream.is_open())
      {
        std::cerr << ":(  Operacja otwarcia do zapisu \""
                  << "../models/tmp/" + tempName_temp << "\"" << std::endl
                  << ":(  nie powiodla sie." << std::endl;
        return false;
      }
      file_stream << "3" << std::endl;
      Vector3 sum = realPosition + objectRealPosition[i];
      std::cout << sum;
      file_stream << subObject[i] + sum << std::endl;
      file_stream.close();
    }
    is_valid = true;
    return true;
  }


public:

  Vector3 position;
  Vector3 rotation;

  Vector3 objectPosition[SIZE];
  Vector3 objectRotarion[SIZE];

  bool load(std::string loadFileName, std::string objectName)
  {
    int check;
    std::ifstream file_stream;
    file_stream.open(path + loadFileName);
    if (!file_stream.is_open())
    {
      std::cerr << "Operacja otwarcia pliku " << path + loadFileName << " nie powiodla sie." << std::endl;
      return false;
    }
    file_stream >> check;
    if (check != 3)
    {
      std::cerr << "Plik \""
                << path + loadFileName << "\"" << std::endl
                << "Ma niewłaściwą liczbę danych" << std::endl;
      return false;
    }
    name = objectName;
    for (int i = 0; i < SIZE; i++)
    {
      file_stream >> subObject[i];
    }
    file_stream.close();
    is_valid = true;
    putToTempFile();
    return true;
  }
};