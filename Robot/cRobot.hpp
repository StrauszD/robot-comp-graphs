//
//  cRobot.hpp
//  Robot
//
//  Created by:
//      Daniel Strausz      A01332949
//      Alfonso Ledesma     A01339894
//      Alejandro Montaño   A01339420
//      Braulio Santiago    A01650398
//      Mariana Piscil      A01651783
//  on 9/10/18.
//  Copyright © 2018 Daniel Strausz. All rights reserved.
//

#pragma once
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include "glew.h"
#include "freeglut.h"
#include <stdio.h>
#include <math.h>
#endif

#include "cBlock.hpp"

class Robot
{
public:
    Robot();
    ~Robot();
    
    void draw();    //Called from "display"
    void update();  //Called from "idle"
    
    Block* blocks;
    
    Block* lFoot;
    Block* lLeg;
    Block* lThigh;
    Block* rFoot;
    Block* rLeg;
    Block* rThigh;
    Block* hips;
    Block* waist;
    Block* torso;
    Block* neck;
    Block* head;
    Block* lShoulder;
    Block* lUpperArm;
    Block* lLowerArm;
    Block* lHand;
    Block* rShoulder;
    Block* rUpperArm;
    Block* rLowerArm;
    Block* rHand;
};


