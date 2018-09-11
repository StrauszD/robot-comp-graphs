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
    
    Block* foot;
    Block* leg;
    Block* thigh;
    Block* hips;
    Block* waist;
    Block* torso;
    Block* neck;
    Block* head;
    Block* shoulder;
    Block* upperArm;
    Block* lowerArm;
    Block* hand;
};


