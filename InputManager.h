#ifndef InputManager_H
#define InputManager_H

#include <Ogre.h>
#include <OgreRenderWindow.h>
#include <OgreInput.h>
#include <ois/OIS.h>

using namespace Ogre;

class InputManager : public FrameListener, protected OIS::KeyListener
{
public:
    InputManager(Ogre::RenderWindow * renderWindow);

    void start();

    bool exit() const {return shouldExit;}

    bool frameRenderingQueued(const FrameEvent& evt);

    bool keyPressed(const OIS::KeyEvent &evt) ;
    bool keyReleased(const OIS::KeyEvent &evt) ;

protected:

    OIS::Keyboard * keyboard;
    OIS::InputManager * inputSystem;

    bool shouldExit;

};
#endif