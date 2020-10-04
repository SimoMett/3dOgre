#ifndef InputManager_H
#define InputManager_H

#include <Ogre.h>
#include <OgreRenderWindow.h>
#include <OgreInput.h>
#include <ois/OIS.h>

using namespace Ogre;

class InputManager : public OIS::KeyListener
{
public:
    InputManager();

    void init(Ogre::RenderWindow * renderWindow);

    void capture();

    bool keyPressed(const OIS::KeyEvent & evt) override ;
    bool keyReleased(const OIS::KeyEvent & evt) override ;

protected:

    OIS::Keyboard * keyboard;
    OIS::InputManager * inputSystem;

};
#endif