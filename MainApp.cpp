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

MainApp::MainApp(std::string appName) : appName(appName)
{
    root = std::make_unique<Ogre::Root>("","");

    root->loadPlugin("/usr/lib/OGRE/RenderSystem_GL");
    root->setRenderSystem(root->getAvailableRenderers()[0]);
}

void MainApp::start()
{
    window=root->initialise(true,appName);
    sceneManager=root->createSceneManager();

    inputManager=InputManager(*window);

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

