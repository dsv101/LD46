#include "CarrotWorld.hpp"
#include "app.hpp"

CarrotWorld::CarrotWorld() :
  cage::World(),
  m_joe(DUDE_START_X, DUDE_START_Y)
{
  addEntity(&m_joe);
}
