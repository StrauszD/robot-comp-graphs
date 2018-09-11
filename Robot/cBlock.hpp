//
//  cBlock.hpp
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


class Block
{
public:
    Block();
    Block(float _x, float _y, float _z, float _r, float _g, float _b);        //Constructor's signature
    ~Block();        //Class Destructor
    
    void draw();    //Called from "display"
    void update();  //Called from "idle"
    
    float x;        // Scale
    float y;        // Scale
    float z;        // Scale
    
    float r, g, b;    // Color
    
    float rotX;        // Rotation in X Axis
};


