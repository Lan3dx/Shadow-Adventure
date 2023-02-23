#pragma once

class Camera 
{
private:
  int X;
  int Y;
  int distance;
  float angle;
  int mapSizeX;
  int mapSizeY;

public:
  Camera(int, int, int, float, int, int);
  
  void setX(int);
  void setY(int);
  void setDistance(int);
  void setAngle(float);
  void setMapSizeX(int);
  void setMapSizeY(int);

  int getX();
  int getY();
  int getDistance();
  float getAngle();
};