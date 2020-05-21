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

bool Player::Move(Vector3 movementVector)
{
  double rad = rotation.value[0] * M_PI / 180;
  isMoving = true;
  for (int i = 0; i < 3; i++)
  {
    posDest.value[0] = movementVector.length() * cos(rad) * cos(rad);
    posDest.value[1] = movementVector.length() * cos(rad) * sin(rad);
    posDest.value[2] = movementVector.length() * sin(rad);
  }
  return true;
}

bool Player::Rotate(Vector3 rotateVector)
{
  isRotating = true;
  rotDest += rotateVector;
  return true;
}

bool Player::Update()
{
  if (isMoving || isRotating)
  {
    dynamicMovement();
    Draw();
    for (int i = 0; i < 2; i++)
    {
      rotor[i].position = position;
      rotor[i].rotation = rotation;
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
  defPos[0].value[0] = -35;
  defPos[0].value[1] = 35;
  defPos[1].value[0] = -35;
  defPos[1].value[1] = -35;
  rotor[0].position = defPos[0];
  rotor[1].position = defPos[1];
  rotor[0].ApplyShift();
  rotor[1].ApplyShift();

  return 1;
}