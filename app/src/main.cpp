#include <iostream>

#include "CAGE/Runtime.hpp"
#include "CAGE/World.hpp"
#include "CAGE/InputManager.hpp"

#include "Shooter/app.hpp"

#include <iostream>

class MyWorld : public cage::World
{
  public:
    void update(float dt) override
    {
      cage::World::update(dt);

      if (cage::InputManager::isPressed(cage::SfKeyboard::Key::Z))
      {
        std::cout << "pressed z" << std::endl;
      }

      if (cage::InputManager::isReleased(cage::SfKeyboard::Key::Z))
      {
        std::cout << "released z" << std::endl;
      }

      if (cage::InputManager::isDown(cage::SfKeyboard::Key::X))
      {
        std::cout << "down x" << std::endl;
      }
    }
};

int main()
{
  cage::Runtime runtime;
  MyWorld myWorld;

  runtime.gotoWorld(&myWorld);

  runtime.run();

  return 0;
}
