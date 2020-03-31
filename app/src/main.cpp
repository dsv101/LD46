#include <iostream>

#include "CAGE/Runtime.hpp"
#include "CAGE/SFML/SfRuntime.hpp"

#include "Shooter/app.hpp"

int main()
{
  cage::Runtime *runtime;

  cage::sfml::SfRuntime sfRuntime;

  runtime = &sfRuntime;

  return runtime->run(1280, 720, "Shooter Game");
}
