#include <iostream>

#include <Ogre.h>
#include <OgreRenderWindow.h>
#include <OgreRoot.h>
#include <OgreWindowEventUtilities.h>
#include "MainApp.h"
#include "DFFObject.h"

using namespace Ogre;

using std::cout;
using std::endl;

int main(int argc, char ** argv)
{
    Root * root=new Root("","","");
    SceneManager * scnMgr=root->createSceneManager();

    root->loadPlugin("/usr/lib/OGRE/RenderSystem_GL");

    root->setRenderSystem(root->getAvailableRenderers()[0]);

    RenderWindow * window=root->initialise(true);

    // also need to tell where we are
    Ogre::SceneNode* camNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    camNode->setPosition(0, 0, 15);
    camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);
    // create the camera
    Ogre::Camera* cam = scnMgr->createCamera("myCam");
    cam->setNearClipDistance(5); // specific to this sample
    cam->setAutoAspectRatio(true);
    camNode->attachObject(cam);

    window->addViewport(cam);

    ManualObject * manualObject=scnMgr->createManualObject("cubeTest");
    manualObject->begin("BaseWhiteNoLighting");
    {
        manualObject->position( -2, 0, 0 );
        manualObject->colour( 1,1,0);
        manualObject->position( 2, 0, 0 );
        manualObject->colour( 1,0,1);
        manualObject->position( 0, 2, 0 );
        manualObject->colour( ColourValue::Red);
        manualObject->triangle( 0, 1, 2 );
        manualObject->end();
    }
    MeshPtr triang=manualObject->convertToMesh("cube");

    Ogre::Entity* ent = scnMgr->createEntity(triang);
    //ent->setDisplaySkeleton(true);
    Ogre::SceneNode* node = scnMgr->getRootSceneNode()->createChildSceneNode();
    node->attachObject(ent);

    InputManager inputManager;
    inputManager.init(window);

    DFFObject dffFile("../SimpleCube.dff");

    bool exit=false;
    while(!exit)
    {
        inputManager.capture();
        root->renderOneFrame();
    }
    return 0;
}