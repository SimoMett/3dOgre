#include "InputManager.h"

InputManager::InputManager(Ogre::RenderWindow & window)
{
    size_t windowHandle=0;
    window.getCustomAttribute("WINDOW",&windowHandle);
    std::ostringstream winHnd;
    winHnd<<windowHandle;
    std::string windowsHandleStr=winHnd.str();

    OIS::ParamList paramList;
    paramList.insert(std::make_pair(std::string("WINDOW"),windowsHandleStr));

    inputManager = OIS::InputManager::createInputSystem(paramList);
    keyboard= static_cast<OIS::Keyboard*>(inputManager->createInputObject(OIS::OISKeyboard,false));
}