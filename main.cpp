#include <iostream>

//#define OGRE_STATIC_LIB
#include <Ogre.h>
#include <OgreRenderWindow.h>
#include <OgreRoot.h>
#include <OgreWindowEventUtilities.h>
#include <RTShaderSystem/OgreRTShaderSystem.h>

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

    // register our scene with the RTSS
    //RTShader::ShaderGenerator* shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
    //shadergen->addSceneManager(scnMgr);
    // without light we would just get a black screen
    Ogre::Light* light = scnMgr->createLight("MainLight");
    Ogre::SceneNode* lightNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    lightNode->setPosition(0, 10, 15);
    lightNode->attachObject(light);
    // also need to tell where we are
    Ogre::SceneNode* camNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    camNode->setPosition(0, 0, 15);
    camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);
    // create the camera
    Ogre::Camera* cam = scnMgr->createCamera("myCam");
    cam->setNearClipDistance(5); // specific to this sample
    cam->setAutoAspectRatio(true);
    camNode->attachObject(cam);
    // and tell it to render into the main window
    window->addViewport(cam);
    // finally something to render

    ResourceGroupManager::getSingleton().addResourceLocation("/usr/share/OGRE/Media/models","FileSystem","General",true);

    Ogre::Entity* ent = scnMgr->createEntity("fish.mesh");
    ent->setDisplaySkeleton(true);
    Ogre::SceneNode* node = scnMgr->getRootSceneNode()->createChildSceneNode();
    node->attachObject(ent);


    root->startRendering();

    return 0;
}