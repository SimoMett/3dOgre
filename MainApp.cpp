//
// Created by matteo on 21/11/19.
//
#include <iostream>
#include <memory>
#include <Ogre.h>
#include <OgreRoot.h>
#include <ois/OIS.h>
#include "MainApp.h"

using std::cout;
using std::endl;

MainApp::MainApp(std::string appName) : appName(appName), windowEventListener()
{
    root = std::make_unique<Ogre::Root>("","");

    root->loadPlugin("/usr/lib/OGRE/RenderSystem_GL");
    root->setRenderSystem(root->getAvailableRenderers()[0]);
}

void MainApp::start()
{
    window=root->initialise(true,appName);
    sceneManager=root->createSceneManager();

    //inputManager=InputManager(*window);

    Entity * entity=sceneManager->createEntity("Cube","/usr/share/OGRE/Media/models/cube.mesh");
    SceneNode * node=sceneManager->getRootSceneNode()->createChildSceneNode();
    node->attachObject(entity);

    Light* l = sceneManager->createLight("MainLight");
    l->setPosition(20,80,50);

    root->startRendering();
}
/*
bool MainApp::keyPressed(const OgreBites::KeyboardEvent & evt)
{
    cout << "evt"<<endl;
    if(evt.keysym.sym == OgreBites::SDLK_ESCAPE)
    {
        root->queueEndRendering();
        window->destroy();
    }
    return true;
}*/

/*void MainApp::setup()
{

    root->startRendering();
}*/

