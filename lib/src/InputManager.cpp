#include "CAGE/InputManager.hpp"

float cage::InputManager::s_mouseX = 0;
float cage::InputManager::s_mouseY = 0;
std::unordered_map<cage::Mouse::Button,bool> cage::InputManager::s_mousePressed;
std::unordered_map<cage::Mouse::Button,bool> cage::InputManager::s_mouseReleased;
std::unordered_map<cage::Mouse::Button,bool> cage::InputManager::s_mouseDown;
std::unordered_map<cage::Keyboard::Key,bool> cage::InputManager::s_keysPressed;
std::unordered_map<cage::Keyboard::Key,bool> cage::InputManager::s_keysReleased;
std::unordered_map<cage::Keyboard::Key,bool> cage::InputManager::s_keysDown;
std::unordered_map<std::string,std::vector<cage::Keyboard::Key>> cage::InputManager::s_keysets;

void cage::InputManager::handleEvent(const Event &event)
{
  if (event.type == Event::EventType::MouseButtonPressed)
  {
    if (!s_mousePressed[event.mouseButton.button] && !s_mouseDown[event.mouseButton.button])
    {
      s_mousePressed[event.mouseButton.button] = true;
    }
    s_mouseDown[event.mouseButton.button] = true;
  }
  else if (event.type == Event::EventType::MouseButtonReleased)
  {
    s_mouseReleased[event.mouseButton.button] = true;
    s_mouseDown[event.mouseButton.button] = false;
  }
  else if (event.type == Event::EventType::MouseMoved)
  {
    s_mouseX = event.mouseMove.x;
    s_mouseY = event.mouseMove.y;
  }
  else if (event.type == Event::EventType::KeyPressed)
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
  s_mousePressed.clear();
  s_mouseReleased.clear();
  s_keysPressed.clear();
  s_keysReleased.clear();
}

bool cage::InputManager::isPressed(const Keyboard::Key &key)
{
  return s_keysPressed[key];
}

bool cage::InputManager::isReleased(const Keyboard::Key &key)
{
  return s_keysReleased[key];
}

bool cage::InputManager::isDown(const Keyboard::Key &key)
{
  return s_keysDown[key];
}

bool cage::InputManager::isPressed(const Mouse::Button &button)
{
  return s_mousePressed[button];
}

bool cage::InputManager::isReleased(const Mouse::Button &button)
{
  return s_mouseReleased[button];
}

bool cage::InputManager::isDown(const Mouse::Button &button)
{
  return s_mouseDown[button];
}

float cage::InputManager::getMouseX()
{
  return s_mouseX;
}

float cage::InputManager::getMouseY()
{
  return s_mouseY;
}

void cage::InputManager::defineKeyset(const std::string &name, const std::vector<Keyboard::Key> &keys)
{
  s_keysets[name] = keys;
}

bool cage::InputManager::isKeysetPressed(const std::string &name)
{
  std::unordered_map<std::string,std::vector<Keyboard::Key>>::const_iterator it = s_keysets.find(name);
  if (it != s_keysets.end())
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
  std::unordered_map<std::string,std::vector<Keyboard::Key>>::const_iterator it = s_keysets.find(name);
  if (it != s_keysets.end())
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
  std::unordered_map<std::string,std::vector<Keyboard::Key>>::const_iterator it = s_keysets.find(name);
  if (it != s_keysets.end())
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
