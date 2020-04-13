#include "CAGE/InputManager.hpp"

std::map<cage::Keyboard::Key,bool> cage::InputManager::s_keysPressed;
std::map<cage::Keyboard::Key,bool> cage::InputManager::s_keysReleased;
std::map<cage::Keyboard::Key,bool> cage::InputManager::s_keysDown;

void cage::InputManager::handleEvent(Event &event)
{
  if (event.type == Event::EventType::KeyPressed)
  {
    if (!s_keysPressed[event.key.code] && !s_keysDown[event.key.code])
    {
      s_keysPressed[event.key.code] = true;
    }
    s_keysDown[event.key.code] = true;
  }
  else if (event.type == Event::EventType::KeyReleased)
  {
    s_keysReleased[event.key.code] = true;
    s_keysDown[event.key.code] = false;
  }
}

void cage::InputManager::flush()
{
  s_keysPressed.clear();
  s_keysReleased.clear();
}

bool cage::InputManager::isPressed(Keyboard::Key key)
{
  return s_keysPressed[key];
}
bool cage::InputManager::isReleased(Keyboard::Key key)
{
  return s_keysReleased[key];
}
bool cage::InputManager::isDown(Keyboard::Key key)
{
  return s_keysDown[key];
}
