//
//  cBlock.cpp
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

#include "cBlock.hpp"

Block::Block() {}

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

Block::~Block() {}

void Block::draw()
{
    glPushMatrix();
    {
        glScalef(x, y, z);
        glColor3f(r, g, b);
        glutSolidCube(1);
        glRotatef(rotAngle, 0, 1, 0);
    }
    glPopMatrix();
}
