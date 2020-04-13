#ifndef CAGE__INPUTMANAGER_HPP
#define CAGE__INPUTMANAGER_HPP

#include "CAGE/SFML/sf.hpp"
#include <map>

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
    private:
      static std::map<Keyboard::Key,bool> s_keysPressed;
			static std::map<Keyboard::Key,bool> s_keysReleased;
			static std::map<Keyboard::Key,bool> s_keysDown;
  };
}

#endif
