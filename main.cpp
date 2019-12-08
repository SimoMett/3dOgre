#include <iostream>

//#define OGRE_STATIC_LIB
#include <Ogre.h>
#include <OgreRenderWindow.h>
#include <OgreRoot.h>
#include "MainApp.h"

using namespace Ogre;

using std::cout;
using std::endl;

int main(int argc, char ** argv)
{
    MainApp app("Test");
    app.start();

    /*SceneManager* sceneManager = root->createSceneManager();
    sceneManager->setAmbientLight(Ogre::ColourValue(0.0, 0.0, 0.0));

    // Create a new camera
    Camera* camera = sceneManager->createCamera("Camera");
    camera->setPosition(Ogre::Vector3(0,0,15));
    camera->lookAt(Ogre::Vector3(0,0,0));
    camera->setNearClipDistance(5);*/

    return 0;
}