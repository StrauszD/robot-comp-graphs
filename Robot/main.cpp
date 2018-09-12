//
//  main.cpp
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

#include "cRobot.hpp"

Robot* robot;

void init()
{
    robot = new Robot();
    
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.5, 0.5, 0.5, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(40, 19, 40,
              0, 8.5, 0,
              0.0, 1, 0.0);
    
    robot->draw();
    glutSwapBuffers();
}


void idle()
{
    robot->update();
    glutPostRedisplay();
}

void reshape(int h, int v)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLdouble)h / (GLdouble)v, 0.5, 200.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, h, v);
    gluLookAt(0.0, 1.0, 4.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    display();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Robot");
    
    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
