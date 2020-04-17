#ifndef CAGE__INPUTMANAGER_HPP
#define CAGE__INPUTMANAGER_HPP

#include "CAGE/SFML/sf.hpp"
#include <unordered_map>
#include <vector>

namespace cage
{
  class InputManager
  {
    public:
      static void handleEvent(const Event &event);
      static void flush();

      static bool isPressed(const Keyboard::Key &key);
      static bool isReleased(const Keyboard::Key &key);
      static bool isDown(const Keyboard::Key &key);

      static bool isPressed(const Mouse::Button &button);
      static bool isReleased(const Mouse::Button &button);
      static bool isDown(const Mouse::Button &button);
      static float getMouseX();
      static float getMouseY();

      static void defineKeyset(const std::string &name, const std::vector<Keyboard::Key> &keys);
      static bool isKeysetPressed(const std::string &name);
      static bool isKeysetReleased(const std::string &name);
      static bool isKeysetDown(const std::string &name);
    private:
      static float s_mouseX;
      static float s_mouseY;
      static std::unordered_map<Mouse::Button,bool> s_mousePressed;
      static std::unordered_map<Mouse::Button,bool> s_mouseReleased;
      static std::unordered_map<Mouse::Button,bool> s_mouseDown;
      static std::unordered_map<Keyboard::Key,bool> s_keysPressed;
      static std::unordered_map<Keyboard::Key,bool> s_keysReleased;
      static std::unordered_map<Keyboard::Key,bool> s_keysDown;
      static std::unordered_map<std::string,std::vector<Keyboard::Key>> s_keysets;
  };
}

#endif
