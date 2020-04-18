#ifndef CARROTWORLD_HPP
#define CARROTWORLD_HPP

#include "CAGE/lib.hpp"
#include "JoeKeeper.hpp"

class CarrotWorld : public cage::World
{
  public:
    CarrotWorld();
  private:
    JoeKeeper m_joe;
};

#endif
