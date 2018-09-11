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



Robot::Robot()
{
    foot = new Block(3.5, 1.5, 5, .202, .329, .605);                //Blue
    leg = new Block(3.5, 6, 3, .202, .329, .605);                //Blue
    thigh = new Block(2.7, 6, 2.7, 1, 1, 1);            //White
    
    hips = new Block(7, 2.5, 4, 0.5, 0.5, 0.5);            //Gray
    waist = new Block(6, 3, 3, 1, 1, 1);                //White
    torso = new Block(8, 5, 5, .627, .155, .139);                //Red
    neck = new Block(2, 1.5, 2, 1, 1, 1);
    head = new Block(3, 3.5, 3, .202, .329, .605);                //Blue
    
    shoulder = new Block(3, 2.5, 3, .627, .155, .139);            //Red
    upperArm = new Block(2.3, 2, 2.3, 1, 1, 1);            //White
    lowerArm = new Block(3, 4, 3, .627, .155, .139);                //Red
    hand = new Block(2.3, 2.5, 2.3, .202, .329, .605);            //Blue
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
        torso->draw();
        
        //RIGHT ARM
        glPushMatrix();
        {
            glTranslatef(0, 1.5, 0);                //To Change Shoulder Pivot
            
            glPushMatrix();
            {
                //RIGHT SHOULDER
                glTranslatef(-5.5, 0, 0);
                shoulder->draw();
                
                //RIGHT UPPER ARM
                glTranslatef(0, -2.25, 0);
                upperArm->draw();
                
                //RIGHT LOWER ARM
                glTranslatef(0, -3, 0);
                lowerArm->draw();
                
                //RIGHT HAND
                glTranslatef(0, -3.25, 0);
                hand->draw();
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
                shoulder->draw();
                
                //LEFT UPPER ARM
                glTranslatef(0, -2.25, 0);
                upperArm->draw();
                
                //LEFT LOWER ARM
                glTranslatef(0, -3, 0);
                lowerArm->draw();
                
                //LEFT HAND
                glTranslatef(0, -3.25, 0);
                hand->draw();
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
        thigh->draw();
        
        //RIGHT LEG
        glTranslatef(0, -6, 0);
        leg->draw();
        
        //RIGHT FOOT
        glTranslatef(0, -3.75, 1);
        foot->draw();
    }
    glPopMatrix();
    
    //LEFT LEG
    glPushMatrix();
    {
        //LEFT THIGH
        glTranslatef(2.3, 3.5, 0);
        thigh->draw();
        
        //LEFT LEG
        glTranslatef(0, -6, 0);
        leg->draw();
        
        //LEFT FOOT
        glTranslatef(0, -3.75, 1);
        foot->draw();
    }
    glPopMatrix();
    
    
}

void Robot::update()
{
    foot->update();
    leg->update();
    thigh->update();
    
    hips->update();
    waist->update();
    torso->update();
    neck->update();
    head->update();
    
    shoulder->update();
    upperArm->update();
    lowerArm->update();
    hand->update();
    
}
