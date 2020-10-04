#include <iostream>
#include "InputManager.h"

using std::cout;
using std::endl;

InputManager::InputManager()
{

}

void InputManager::init(Ogre::RenderWindow *renderWindow)
{
    OIS::ParamList paramList;
    std::ostringstream out;
    size_t hnd=0;
    renderWindow->getCustomAttribute("WINDOW",&hnd);
    out<<hnd;
    paramList.insert(std::make_pair(std::string("WINDOW"),out.str()));
    inputSystem=OIS::InputManager::createInputSystem(paramList);

    keyboard=(OIS::Keyboard*)inputSystem->createInputObject(OIS::OISKeyboard,true);
    keyboard->setEventCallback(this);
}

void InputManager::capture()
{
    if(keyboard)
        keyboard->capture();
}

bool InputManager::keyPressed(const OIS::KeyEvent &evt)
{
    if(evt.key == OIS::KC_F4 && keyboard->isKeyDown(OIS::KC_LMENU))
    {
        cout << "exit"<<endl;
    }
    return true;
}

bool InputManager::keyReleased(const OIS::KeyEvent &evt)
{
    return true;
}