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

Block::Block(float _x, float _y, float _z, float _r, float _g, float _b)
{
    x = _x;
    y = _y;
    z = _z;
    r = _r;
    g = _g;
    b = _b;
    rotX = 0;
}

Block::~Block()
{
}

void Block::update()
{
    rotX += 0.5f;
}



void Block::draw()            //Draw belongs to Block
{
    glPushMatrix();
    {
        glScalef(x, y, z);
        glColor3f(r, g, b);
        glutSolidCube(1);
        
        glColor3f(0, 0, 0);
        glutWireCube(1);
    }
    glPopMatrix();
}

