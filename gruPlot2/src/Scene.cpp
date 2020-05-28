#include "Scene.hh"

void Scene::Start()
{
  //setting up 3d drawing mode
  link.SetDrawingMode(PzG::DM_3D);
  link.SetRangeX(-300, 300);
  link.SetRangeY(-300, 300);
  link.SetRangeZ(-100, 300);

  //loading presets
  Vector3 vectorOfMovement;
  for (int i = 0; i < 3; i++)
    vectorOfMovement.value[i] = 50;

  player.Start();

  Model placeholder;
  placeholder.LoadFromFile("water.dat");
  models.push_back(placeholder);
  placeholder.rect.clear();
  placeholder.LoadFromFile("ground.dat");
  models.push_back(placeholder);
  placeholder.rect.clear();
  placeholder.LoadFromFile("plant.dat");
  placeholder.position.value[0] = 00;
  placeholder.position.value[1] = 150;
  placeholder.position.value[2] = -100;
  placeholder.rotation.value[0] = 15;
    models.push_back(placeholder);
    placeholder.position.value[2] = 0;
  collider.setSphereCollider(placeholder.position, 10,"Plant");

  placeholder.rect.clear();
  placeholder.LoadFromFile("plant.dat");
  placeholder.position.value[0] = -100;
  placeholder.position.value[1] = -220;
  placeholder.position.value[2] = -100;
  placeholder.rotation.value[0] = -40;

  models.push_back(placeholder);
  placeholder.position.value[2] = 0;
    collider.setSphereCollider(placeholder.position, 10,"Plant");
  placeholder.rect.clear();
  player.Update();
  for (int i = 0; i < models.size(); i++)
  {
    models[i].Draw();
  }
  link.Draw();
  //player.Move(vectorOfMovement);
}
bool Scene::Update()
{
  Vector3 mov;
  double movDouble;
  std::string c;
  fps.measure();
  player.Update();

  //check if we can make desision;
  if (!player.isMoving && !player.isRotating)
  {
    std::cout << "Some info:\n"
              << " -> Number of rendered independent models: "
              << Model::count << std::endl
              << " -> Number of rendered independent rectangles: "
              << Model::meshes << std::endl;

    std::cout << "\n\nCHOOSE YOUR ACTION:\n"
              << "m - move\n"
              << "r - rotate\n"
              << "e - exit\n"
              << "Your choice: ";

    std::cin >> c;
    if (c == "m")
    {
      std::cout << "Write distance you want to move\n  ->  ";
      std::cin >> movDouble;

      fps.measure();
      player.Move((movDouble));
    }
    else if (c == "r")
    {
      std::cout << "Write angle you want box to rotate (last two numbers will be ignored)\n  ->  ";
      std::cin >> movDouble;
      fps.measure();
      player.Rotate(movDouble);
    }
    else if (c == "e")
    {
      return 0;
    }
    else
    {
      std::cout << "Choose one of options!";
    }
  }
  collider.CheckCollision();
  link.Draw();
  return 1;
}