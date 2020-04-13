#ifndef CAGE__INPUTMANAGER_HPP
#define CAGE__INPUTMANAGER_HPP

#include "CAGE/SFML/sf.hpp"
#include <map>
#include <vector>

namespace cage
{
  class InputManager
  {
    public:
      static void handleEvent(Event &event);
      static void flush();

      static bool isPressed(Keyboard::Key key);
      static bool isReleased(Keyboard::Key key);
      static bool isDown(Keyboard::Key key);

      static void defineKeyset(const std::string &name, const std::vector<Keyboard::Key> &keys);
      static bool isKeysetPressed(const std::string &name);
      static bool isKeysetReleased(const std::string &name);
      static bool isKeysetDown(const std::string &name);
    private:
      static std::map<Keyboard::Key,bool> s_keysPressed;
			static std::map<Keyboard::Key,bool> s_keysReleased;
			static std::map<Keyboard::Key,bool> s_keysDown;
      static std::map<std::string,std::vector<Keyboard::Key>> s_keysets;
  };
}

#endif
