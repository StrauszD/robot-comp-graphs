//
//  cBlock.hpp
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


class Block
{
public:
    Block();
    Block(float _x, float _y, float _z, float _r, float _g, float _b, float _rotX, float _rotY, float _rotAngle);
    ~Block();
    
    void draw();
    
    float x;
    float y;
    float z;
    
    float r, g, b;
    
    float rotX;
    float rotY;
    float rotAngle;
};


