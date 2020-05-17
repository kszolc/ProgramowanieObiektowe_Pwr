#include "Model.hh"

void Model::Start()
{
  id = count++;

  for (int i = 0; i < 3; i++)
    position.value[i] = rotation.value[i] = 0;
}

bool Model::LoadFromFile(std::string fileName)
{
  std::string checkWord;
  int rectangles;
  std::ifstream file_stream;

  //Opening file
  file_stream.open("../models/" + fileName);
  if (!file_stream.is_open()) // check if opened correctly
  {
    std::cerr << "Opening file: " << fileName << " failed!" << std::endl;
    return false;
  }

  //Check if file is safe to read
  file_stream >> checkWord;
  if (checkWord != "3D-Rectangle-Konrad-Szolc")
  {
    std::cerr << "Invalid filetype: " << fileName << std::endl
              << "File must start with: \"3D-Rectangle-Konrad-Szolc\"";
    return false;
  }

  // do some start settings
  Start();
  // load expected number of rectangles
  file_stream >> rectangles;
  meshes += rectangles;
  while (rectangles > 0) // load rectangles
  {
    Rectangle placeholder;
    file_stream >> placeholder;
    rect.push_back(placeholder);
    rectangles--;
  }

  file_stream.close();

  return true;
}

bool Model::PutToFile(Vector3 shift, Vector3 angle)
{
  std::ofstream file_stream;
  file_stream.open("../models/tmp/" + std::to_string(id) + ".dat");
  if (!file_stream.is_open())
  {
    std::cerr << "Opening file TO WRITE: "
              << "models/tmp/" + std::to_string(id)
              << ".dat failed!" << std::endl;
    return false;
  }
 // std::cout << rotation;
  for (int i = 0; i < rect.size(); i++)
    file_stream << rect[i] * rotation + shift;
  return true;
}

void Model::Draw()
{
  PutToFile(position,rotation);
  std::string filename = "../models/tmp/" + std::to_string(id) + ".dat";
  char cstr[512];
  std::strcpy(cstr, filename.c_str());
  link.AddFilename(cstr, PzG::LS_CONTINUOUS, 1);
}

const bool Model::achivedDestination()
{
  if (abs(posDest.length() - position.length()) < 0.5)
  {
    for (int i = 0; i < 3; i++)
    {
      if (abs(posDest.value[i] - position.value[i]) > 0.5)
      {
        return false;
      }
    }
    return true;
  }else return false;
}

const bool Model::achivedRotationDestination()
{
  if (abs(rotDest.length() - rotation.length()) < 0.5)
  {
    for (int i = 0; i < 3; i++)
    {
      if (abs(rotDest.value[i] - rotation.value[i]) > 0.5)
      {
        return false;
      }
    }
    return true;
  }else return false;
}
