#include <iostream>

#include "CAGE/Runtime.hpp"
#include "CAGE/World.hpp"
#include "CAGE/InputManager.hpp"
#include "CAGE/Entity.hpp"
#include "CAGE/SFML/sf.hpp"

#include "Shooter/app.hpp"

#include <iostream>

class Dude : public cage::Entity
{
  public:
    Dude(float x=0.0f, float y=0.0f) :
      m_texture(),
      m_sprite(),
      cage::Entity(x, y, &m_sprite)
    {
      m_texture.loadFromFile("assets/dude.png");
      m_sprite.setTexture(m_texture);
    }

  private:
    cage::Texture m_texture;
    cage::Sprite m_sprite;
};

class MyWorld : public cage::World
{
  private:
    Dude dude;
  public:
    MyWorld() : cage::World(), dude()
    {
      addEntity(&dude);

      cage::InputManager::defineKeyset
      (
        "move-left",
        std::vector<cage::Keyboard::Key>
        {
          cage::Keyboard::Key::A,
          cage::Keyboard::Key::Left
        }
      );

      cage::InputManager::defineKeyset
      (
        "move-right",
        std::vector<cage::Keyboard::Key>
        {
          cage::Keyboard::Key::D,
          cage::Keyboard::Key::Right
        }
      );

      cage::InputManager::defineKeyset
      (
        "jump",
        std::vector<cage::Keyboard::Key>
        {
          cage::Keyboard::Key::W,
          cage::Keyboard::Key::Z,
          cage::Keyboard::Key::Up,
          cage::Keyboard::Key::Space
        }
      );

      cage::InputManager::defineKeyset
      (
        "action",
        std::vector<cage::Keyboard::Key>
        {
          cage::Keyboard::Key::X,
        }
      );
    }

    void update(float dt) override
    {
      cage::World::update(dt);

      int hdir = 0;
      if (cage::InputManager::isKeysetDown("move-left"))
      {
        --hdir;
      }
      if (cage::InputManager::isKeysetDown("move-right"))
      {
        ++hdir;
      }

      int vdir = 0;
      if (cage::InputManager::isKeysetPressed("jump"))
      {
        --vdir;
      }

      if (cage::InputManager::isKeysetReleased("action"))
      {
        std::cout << "action released" << std::endl;
      }

      if (cage::InputManager::isPressed(cage::Mouse::Button::Left))
      {
        const float x = cage::InputManager::getMouseX();
        const float y = cage::InputManager::getMouseY();
        std::cout << "mouse left pressed (x,y):" << "(" << x << "," << y << ")" << std::endl;
      }

      if (cage::InputManager::isReleased(cage::Mouse::Button::Left))
      {
        std::cout << "mouse left released" << std::endl;
      }

      bool moving = hdir != 0 || vdir != 0;
      if (moving)
        std::cout << "moving (hdir,vdir):(" << hdir << "," << vdir << ")" << std::endl;
    }
};

int main()
{
  cage::Runtime runtime(400, 600, "Yum Yum Carrot");
  MyWorld myWorld;

  runtime.gotoWorld(&myWorld);

  runtime.run();

  return 0;
}
