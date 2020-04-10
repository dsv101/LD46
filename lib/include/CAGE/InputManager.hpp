#ifndef CAGE__INPUTMANAGER_HPP
#define CAGE__INPUTMANAGER_HPP

#include "CAGE/SFML/sf.hpp"
#include <map>

namespace cage
{
  class InputManager
  {
    public:
      static void handleEvent(SfEvent &event);
      static void flush();

      static bool isPressed(SfKeyboard::Key key);
      static bool isReleased(SfKeyboard::Key key);
      static bool isDown(SfKeyboard::Key key);
    private:
      static std::map<SfKeyboard::Key,bool> s_keysPressed;
			static std::map<SfKeyboard::Key,bool> s_keysReleased;
			static std::map<SfKeyboard::Key,bool> s_keysDown;
  };
}

#endif
