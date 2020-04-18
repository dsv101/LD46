#include <iostream>

#include "CAGE/Runtime.hpp"
#include "CAGE/World.hpp"
#include "CAGE/InputManager.hpp"
#include "CAGE/Entity.hpp"
#include "CAGE/SFML/sf.hpp"

#include "Shooter/app.hpp"

#include <iostream>

#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 600
#define TITLE "Yum Yum Carrot"
#define DUDE_START_X 200
#define DUDE_START_Y 536

class Dude : public cage::Entity
{
  private:
    const float HSPD = 150;

  public:
    Dude(float x=0.0f, float y=0.0f) :
      m_texture(),
      m_sprite(),
      cage::Entity(x, y, &m_sprite)
    {
      m_texture.loadFromFile("assets/dude.png");
      m_sprite.setTexture(m_texture);
      m_transformable.setOrigin(12, 16);

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

      m_transformable.move(hdir * HSPD * dt, 0);

      cage::Entity::update(dt);
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
    MyWorld() : cage::World(), dude(DUDE_START_X, DUDE_START_Y)
    {
      addEntity(&dude);
    }
};

int main()
{
  cage::Runtime runtime(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
  MyWorld myWorld;

  runtime.gotoWorld(&myWorld);

  runtime.run();

  return 0;
}
