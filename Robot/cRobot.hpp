//
//  cRobot.hpp
//  Robot
//
//  Created by:
//      Daniel Strausz
//      Alfonso Ledesma
//      Alejandro Montaño
//      Braulio Santiago
//      Mariana Piscil
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


