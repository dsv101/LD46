#ifndef MAINRUNTIME_HPP
#define MAINRUNTIME_HPP

#include "CAGE/lib.hpp"
#include "CarrotWorld.hpp"

class MainRuntime : public cage::Runtime
{
  public:
    MainRuntime();
  private:
    CarrotWorld m_carrotWorld;
};

#endif
