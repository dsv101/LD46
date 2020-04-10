#include "CAGE/InputManager.hpp"

std::map<cage::SfKeyboard::Key,bool> cage::InputManager::s_keysPressed;
std::map<cage::SfKeyboard::Key,bool> cage::InputManager::s_keysReleased;
std::map<cage::SfKeyboard::Key,bool> cage::InputManager::s_keysDown;

void cage::InputManager::handleEvent(SfEvent &event)
{
  if (event.type == SfEvent::EventType::KeyPressed)
  {
    if (!s_keysPressed[event.key.code] && !s_keysDown[event.key.code])
    {
      s_keysPressed[event.key.code] = true;
    }
    s_keysDown[event.key.code] = true;
  }
  else if (event.type == SfEvent::EventType::KeyReleased)
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

bool cage::InputManager::isPressed(SfKeyboard::Key key)
{
  return s_keysPressed[key];
}
bool cage::InputManager::isReleased(SfKeyboard::Key key)
{
  return s_keysReleased[key];
}
bool cage::InputManager::isDown(SfKeyboard::Key key)
{
  return s_keysDown[key];
}
