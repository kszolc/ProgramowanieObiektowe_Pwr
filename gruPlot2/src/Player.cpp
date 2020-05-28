#include "Player.hh"

bool Player::dynamicMovement()
{
  float ratio;
  double rotRatio;

  //dynamic rotation;
  if (!achivedRotationDestination())
  {
    toRotate = rotDest - prevRot;
    for (int i = 0; i < 3; i++)
    {
      double rotRatio = toRotate.value[i] / toRotate.length();
      rotation.value[i] += rotRatio * movementSpeed / fps.fps * 2;
    }
  }
  else
  {
    prevRot = rotDest;
    rotation = rotDest;
    isRotating = false;
  }
  // Rotating rotors
  rotor[0].rotation.value[1] += 90 / fps.fps;
  rotor[1].rotation.value[1] += -90 / fps.fps;

  //dynaminc positon;
  if (!achivedDestination())
  {
    toMove = posDest - prevPos;
    for (int i = 0; i < 3; i++)
    {
      double ratio = toMove.value[i] / toMove.length();
      position.value[i] += ratio * movementSpeed / fps.fps * 2;
    }
    return true;
  }
  else
  {
    prevPos = posDest;
    position = posDest;
    isMoving = false;
    return false;
  }
}

bool Player::Move(double shift)
{
  double rad = rotation.value[0] * M_PI / 180;

  isMoving = true;

  posDest.value[0] += -shift * cos(rad);
  posDest.value[1] += shift * sin(rad);
  posDest.value[2] += 0;
  for (int i = 0; i < 3; i++)
  {
    if (fabs(posDest.value[i]) < 0.01)
      posDest.value[i] = 0;
  }
  // checking boundries
  if (posDest.value[0] >= 250)
    posDest.value[0] = 250;
  if (posDest.value[0] <= -250)
    posDest.value[0] = -250;

  if (posDest.value[1] >= 250)
    posDest.value[0] = 250;
  if (posDest.value[1] <= -250)
    posDest.value[0] = -250;

  if (posDest.value[2] >= 250)
    posDest.value[0] = 250;
  if (posDest.value[2] <= -50)
    posDest.value[0] = -50;

  return true;
}

bool Player::Rotate(double rotateAngle)
{
  isRotating = true;
  rotDest.value[0] += rotateAngle;
  return true;
}

bool Player::Update()
{
  if (isMoving || isRotating)
  {
    dynamicMovement();
    collider.colliders[0] = position;
    if(collider.stopMoving){
      posDest = position;

    }
    Draw();
    for (int i = 0; i < 2; i++)
    {
      rotor[i].position = position;
      rotor[i].rotation.value[0] = rotation.value[0];
      rotor[i].Draw();
    }
    return 1;
  }
  return 0;
}
bool Player::Start()
{
  for (int i = 0; i < 3; i++)
  {
    prevPos.value[i] = toMove.value[i] = 0;
  }
  LoadFromFile("box.dat");
  rotor[0].LoadFromFile("screw.dat");
  rotor[1].LoadFromFile("screw.dat");
  defPos[0].value[0] = 35;
  defPos[0].value[1] = -35;
  defPos[1].value[0] = 35;
  defPos[1].value[1] = 35;
  rotor[0].position = defPos[0];
  rotor[1].position = defPos[1];
  rotor[0].ApplyShift();
  rotor[1].ApplyShift();
  collider.setSphereCollider(position, 80,"Player");
  return 1;
}