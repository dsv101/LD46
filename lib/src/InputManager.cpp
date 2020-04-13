#include "CAGE/InputManager.hpp"

std::map<cage::Keyboard::Key,bool> cage::InputManager::s_keysPressed;
std::map<cage::Keyboard::Key,bool> cage::InputManager::s_keysReleased;
std::map<cage::Keyboard::Key,bool> cage::InputManager::s_keysDown;
std::map<std::string,std::vector<cage::Keyboard::Key>> cage::InputManager::s_keysets;

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

void cage::InputManager::defineKeyset(const std::string &name, const std::vector<Keyboard::Key> &keys)
{
  s_keysets[name] = keys;
}

bool cage::InputManager::isKeysetPressed(const std::string &name)
{
  if (s_keysets.count(name) > 0)
  {
    for (const Keyboard::Key &key : s_keysets[name])
    {
      if (isPressed(key))
      {
        return true;
      }
    }
  }

  return false;
}

bool cage::InputManager::isKeysetReleased(const std::string &name)
{
  if (s_keysets.count(name) > 0)
  {
    for (const Keyboard::Key &key : s_keysets[name])
    {
      if (isReleased(key))
      {
        return true;
      }
    }
  }

  return false;
}

bool cage::InputManager::isKeysetDown(const std::string &name)
{
  if (s_keysets.count(name) > 0)
  {
    for (const Keyboard::Key &key : s_keysets[name])
    {
      if (isDown(key))
      {
        return true;
      }
    }
  }

  return false;
}
