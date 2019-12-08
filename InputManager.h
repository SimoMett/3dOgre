#ifndef InputManager_H
#define InputManager_H

#include <ois/OIS.h>

#include <OgreRenderWindow.h>

class InputManager /*: public OIS::KeyListener, public OIS::MouseListener, public OIS::JoyStickListener*/
{
public:
    InputManager(){};
    InputManager(Ogre::RenderWindow & window);

private:
    OIS::InputManager * inputManager;

    OIS::Keyboard * keyboard;
};
#endif