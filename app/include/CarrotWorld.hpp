#ifndef CARROTWORLD_HPP
#define CARROTWORLD_HPP

#include "CAGE/lib.hpp"
#include "JoeKeeper.hpp"
#include "BunchOfCarrots.hpp"

class CarrotWorld : public cage::World
{
  public:
    CarrotWorld();
    void update(float dt) override;
  private:
    JoeKeeper m_joe;
    BunchOfCarrots m_bunch;
};

#endif
