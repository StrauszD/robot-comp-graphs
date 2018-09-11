//
//  cBlock.cpp
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

#include "cBlock.hpp"         //The only include we should have



Block::Block()
{
    rotX = 0;
}

Block::Block(float _x, float _y, float _z, float _r, float _g, float _b, float _rotX, float _rotY, float _rotAngle)
{
    x = _x;
    y = _y;
    z = _z;
    r = _r;
    g = _g;
    b = _b;
    rotX = _rotX;
    rotY = _rotY;
    rotAngle = _rotAngle;
}

Block::~Block()
{
}

void Block::update(float _rot)
{
    rotAngle = _rot;
}



void Block::draw()            //Draw belongs to Block
{
    glPushMatrix();
    {
        glScalef(x, y, z);
        glColor3f(r, g, b);
        glutSolidCube(1);
        glRotatef(rotAngle, 0, 1, 0);
        
        glColor3f(0, 0, 0);
        glutWireCube(1);
        glRotatef(rotAngle, rotX, rotY, 0);
    }
    glPopMatrix();
}

