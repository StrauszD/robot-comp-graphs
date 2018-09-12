//
//  cRobot.cpp
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

#include "cRobot.hpp"
#include <iostream>
using namespace std;


int directionLeft = 1;
int directionRight = -1;

float torDir = 1.0;
float rShDir = 1.0;
float rLaDir = 1.0;
float lLaDir = -1.0;

Robot::Robot()
{
    lFoot = new Block(3.5, 1.5, 5, .202, .329, .605, 1.0, 0.0, -5.0);                //Blue
    lLeg = new Block(3.5, 6, 3, .202, .329, .605, 1.0, 0.0, 15.0);                //Blue
    lThigh = new Block(2.7, 6, 2.7, 1, 1, 1, -1.0, 0.0, 1.0);            //White
    
    rFoot = new Block(3.5, 1.5, 5, .202, .329, .605, 0.0, 0.0, -5.0);                //Blue
    rLeg = new Block(3.5, 6, 3, .202, .329, .605, 1.0, 0.0, 15.0);                //Blue
    rThigh = new Block(2.7, 6, 2.7, 1, 1, 1, -1.0, 0.0, -1.0);
    
    hips = new Block(7, 2.5, 4, 0.5, 0.5, 0.5, 0.0, 0.0, 0.0);            //Gray
    waist = new Block(6, 3, 3, 1, 1, 1, 0.0, 0.0, 0.0);                //White
    torso = new Block(8, 5, 5, .627, .155, .139, 0, 1, 0);                //Red
    neck = new Block(2, 1.5, 2, 1, 1, 1, 0.0, 0.0, 0.0);
    head = new Block(3, 3.5, 3, .202, .329, .605, 0.0, 0.0, 0.0);                //Blue
    
    lShoulder = new Block(3, 2.5, 3, .627, .155, .139, 0.1, 0.0, 0.0);            //Red
    lUpperArm = new Block(2.3, 2, 2.3, 1, 1, 1, 0.0, 0.0, 0.0);            //White
    lLowerArm = new Block(3, 4, 3, .627, .155, .139, 0.1, 0.0, 0.0);                //Red
    lHand = new Block(2.3, 2.5, 2.3, .202, .329, .605, 0.0, 0.0, 0.0);            //Blue
    
    rShoulder = new Block(3, 2.5, 3, .627, .155, .139, 0.1, 0.0, 0.0);            //Red
    rUpperArm = new Block(2.3, 2, 2.3, 1, 1, 1, 0.0, 0.0, 0.0);            //White
    rLowerArm = new Block(3, 4, 3, .627, .155, .139, 0.1, 0.0, 0.0);                //Red
    rHand = new Block(2.3, 2.5, 2.3, .202, .329, .605, 0.0, 0.0, 0.0);
    
}


Robot::~Robot()
{
}


void Robot::draw()
{
    //HEAD
    glPushMatrix();
    {
        glTranslatef(0, 18.75, 0);
        head->draw();
    }
    glPopMatrix();
    
    
    //NECK
    glPushMatrix();
    {
        glTranslatef(0, 17, 0);
        neck->draw();
    }
    glPopMatrix();
    
    
    //WAIST
    glPushMatrix();
    {
        glTranslatef(0, 10, 0);
        waist->draw();
    }
    glPopMatrix();
    
    
    //HIPS
    glPushMatrix();
    {
        glTranslatef(0, 7.75, 0);
        hips->draw();
    }
    glPopMatrix();
    
    
    //TORSO
    glPushMatrix();
    {
        glTranslatef(0, 14, 0);
        glRotatef(torso->rotAngle, torso->rotX, torso->rotY, 0);
        torso->draw();
        
        //RIGHT ARM
        glPushMatrix();
        {
            glTranslatef(0, 1.5, 0);                //To Change Shoulder Pivot
            
            glPushMatrix();
            {
                //RIGHT SHOULDER
                glTranslatef(-5.5, 0, 0);
                glRotatef(rShoulder->rotAngle, rShoulder->rotX, rShoulder->rotY, 0);
                rShoulder->draw();
                
                //RIGHT UPPER ARM
                glTranslatef(0, -2.25, 0);
                rUpperArm->draw();
                
                //RIGHT LOWER ARM
                glTranslatef(0, -3, 0);
                glRotatef(rLowerArm->rotAngle, rLowerArm->rotX, rLowerArm->rotY, 0);
                rLowerArm->draw();
                
                //RIGHT HAND
                glTranslatef(0, -3.25, 0);
                rHand->draw();
            }
            glPopMatrix();
        }
        glPopMatrix();
        
        //LEFT ARM
        glPushMatrix();
        {
            glTranslatef(0, 1.5, 0);                //To Change Shoulder Pivot
            
            glPushMatrix();
            {
                //LEFT SHOULDER
                glTranslatef(5.5, 0, 0);
                glRotatef(lShoulder->rotAngle, lShoulder->rotX, lShoulder->rotY, 0);
                lShoulder->draw();
                
                //LEFT UPPER ARM
                glTranslatef(0, -2.25, 0);
                lUpperArm->draw();
                
                //LEFT LOWER ARM
                glTranslatef(0, -3, 0);
                glRotatef(lLowerArm->rotAngle, lLowerArm->rotX, lLowerArm->rotY, 0);
                lLowerArm->draw();
                
                //LEFT HAND
                glTranslatef(0, -3.25, 0);
                lHand->draw();
            }
            glPopMatrix();
            
        }
        glPopMatrix();
    }
    glPopMatrix();
    
    //LEGS
    //RIGHT LEG
    glPushMatrix();
    {
        //RIGHT THIGH
        glTranslatef(-2.3, 3.5, 0);
        glRotatef(rThigh->rotAngle, rThigh-> rotX, rThigh-> rotY, 0);
        rThigh->draw();
        
        //RIGHT LEG
        glTranslatef(0, -6, 0);
        glRotatef(rLeg->rotAngle, rLeg->rotX, rLeg->rotY, 0);
        rLeg->draw();
        
        //RIGHT FOOT
        glTranslatef(0, -3.75, 1);
        glRotatef(rFoot->rotAngle, rFoot->rotX, rFoot->rotY, 0);
        rFoot->draw();
    }
    glPopMatrix();
    
    //LEFT LEG
    glPushMatrix();
    {
        //LEFT THIGH
        glTranslatef(2.3, 3.5, 0);
        glRotatef(lThigh->rotAngle, lThigh-> rotX, lThigh-> rotY, 0);
        lThigh->draw();
        
        //LEFT LEG
        glTranslatef(0, -6, 0);
        glRotatef(lLeg->rotAngle, lLeg-> rotX, lLeg->rotY, 0);
        lLeg->draw();
        
        //LEFT FOOT
        glTranslatef(0, -3.75, 1);
        glRotatef(lFoot->rotAngle, lFoot->rotX, lFoot->rotY, 0);
        lFoot->draw();
    }
    glPopMatrix();
    
    
}

void Robot::update()
{
    lThigh -> rotAngle += 0.5*directionLeft;
    lLeg -> rotAngle += 0.2*directionRight;
    lFoot-> rotAngle += 0.2*directionLeft;
    
    rThigh -> rotAngle += 0.5*directionRight;
    rLeg -> rotAngle += 0.2*directionLeft;
    rFoot -> rotAngle += 0.2*directionRight;
    
    if(lThigh->rotAngle == 25 || lThigh->rotAngle == -25){
        directionLeft = directionLeft*-1.0f;
    }
    
    if(rThigh->rotAngle == -25 || rThigh->rotAngle == 25){
        directionRight = directionRight*-1.0f;
    }
    
    torso->rotAngle += 0.55 * torDir;
    if (torso->rotAngle < -7 || torso->rotAngle > 7) {
            torDir = torDir * -1.0f;
    }
    
    rShoulder->rotAngle += 0.5*rShDir;
    rLowerArm->rotAngle += 0.5*rLaDir;
    lShoulder->rotAngle += -0.5*rShDir;
    lLowerArm->rotAngle += 0.5*lLaDir;
    if (rShoulder->rotAngle > 0 || rShoulder ->rotAngle < -10) {
        rShDir = rShDir * -1.0f;
    }
    if (rLowerArm->rotAngle > 0 || rLowerArm->rotAngle < -10) {
        rLaDir = rLaDir * -1.0f;
    }
    if (rLowerArm->rotAngle > 0 || rLowerArm->rotAngle < -10) {
        lLaDir = lLaDir * -1.0f;

    }
    
}
