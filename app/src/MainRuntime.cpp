#include "MainRuntime.hpp"
#include "app.hpp"

MainRuntime::MainRuntime() :
  m_carrotWorld(),
  cage::Runtime(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE)
{
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

  gotoWorld(m_carrotWorld);
}
