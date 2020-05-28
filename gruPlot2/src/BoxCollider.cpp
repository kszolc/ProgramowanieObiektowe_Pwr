#include "BoxCollider.hh"

int SphereCollider::setSphereCollider(Vector3 point, double rad, std::string name)
{
    colliders.push_back(point);
    radius.push_back(rad);
    names.push_back(name);
    return colliders.size() - 1;
}

void SphereCollider::CheckCollision()
{
    for (int i = 1; i < colliders.size(); i++)
    {
        Vector3 vec = colliders[i] - colliders[0];
        double len = vec.length();
        if (len < (radius[0] + radius[i]))
        {
            std::cout << "collision" << std::endl;
            stopMoving = true;
            std::cout << "You are about to hit " << names[i]
                      << "!\n Collision detection has stopped you!\n";
        }
    }
}