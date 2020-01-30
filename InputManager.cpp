#include <iostream>
#include <sstream>
#include "InputManager.h"

using std::cout;
using std::endl;

InputManager::InputManager(Ogre::RenderWindow * renderWindow): shouldExit(false)
{
    OIS::ParamList paramList;

    unsigned int size;
    std::ostringstream out;
    out<<size;

    std::string wind;

    renderWindow->getCustomAttribute(wind,&size);

    auto pair=std::make_pair(wind,out.str());
    paramList.insert(pair);

    inputSystem=OIS::InputManager::createInputSystem(paramList);
}

void InputManager::start()
{
    keyboard= (OIS::Keyboard*)(inputSystem->createInputObject(OIS::OISKeyboard,true));
    keyboard->setEventCallback(this);
}

bool InputManager::frameRenderingQueued(const FrameEvent& evt)
{
    if(keyboard)
        keyboard->capture();
    return true;
}

bool InputManager::keyPressed(const OIS::KeyEvent &evt)
{
    if(evt.key==OIS::KC_ESCAPE)
    {
        cout << "exit"<<endl;
        shouldExit=true;
    }
    return true;
}
bool InputManager::keyReleased(const OIS::KeyEvent &evt)
{
    cout << "ba"<<endl;
    return true;
}