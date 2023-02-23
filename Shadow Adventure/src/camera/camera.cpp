#include "../../include/camera/camera.h"

Camera::Camera(int cX, int cY, int cdistance, float cangle, int cmapSizeX, int cmapSizeY)
{
  X = cX;
  Y = cY;
  distance = cdistance;
  angle = cangle;
  mapSizeX = cmapSizeX;
  mapSizeY = cmapSizeY;
}

void Camera::setX(int cx)
{
  X = cx;
}
void Camera::setY(int cy)
{
  Y = cy;
}
void Camera::setDistance(int cdistance)
{
  distance = cdistance;
}
void Camera::setAngle(float cangle)
{
  angle = cangle;
}
void Camera::setMapSizeX(int cX)
{
  mapSizeX = cX;
}
void Camera::setMapSizeY(int cY)
{
  mapSizeY = cY;
}

int Camera::getX()
{
  return X;
}
int Camera::getY()
{
  return Y;
}
int Camera::getDistance()
{
  return distance;
}
float Camera::getAngle()
{
  return angle;
}