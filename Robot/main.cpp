//
//  main.cpp
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


void init() // FOR GLUT LOOP
{
    robot = new Robot();
    
    glEnable(GL_DEPTH_TEST);            // Enable check for close and far objects.
    glClearColor(0.5, 0.5, 0.5, 0);    // Clear the color state.
    glMatrixMode(GL_MODELVIEW);            // Go to 3D mode.
    glLoadIdentity();                    // Reset 3D view matrix.
}


void display()                                                        // Called for each frame (about 60 times per second).
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);               // Clear color and depth buffers.
    glLoadIdentity();                                               // Reset 3D view matrix.
    gluLookAt(40, 19, 40,                                               // Where the camera is.
              0, 8.5, 0,                                                      // To where the camera points at.
              0.0, 1, 0.0);                                               // "UP" vector.
    
    robot->draw();
    glutSwapBuffers();                                                // Swap the hidden and visible buffers.
}


void idle()                                                            // Called when drawing is finished.
{
    robot->update();
    glutPostRedisplay();                                            // Display again.
}


//KEYS IS A CALLBACK FOR THE KEYBOARD EVENT
void keys(unsigned char pressedKey, int x, int y)
{
    
}



void reshape(int h, int v)                                            // Called when the window geometry changes.
{
    glMatrixMode(GL_PROJECTION);                                    // Go to 2D mode.
    glLoadIdentity();                                                // Reset the 2D matrix.
    gluPerspective(40.0, (GLdouble)h / (GLdouble)v, 0.5, 200.0);        // Configure the camera lens aperture.
    glMatrixMode(GL_MODELVIEW);                                        // Go to 3D mode.
    glViewport(0, 0, h, v);                                            // Configure the camera frame dimensions.
    gluLookAt(0.0, 1.0, 4.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    display();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);                                            // Init GLUT with command line parameters.
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);        // Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
    glutInitWindowSize(800, 600);
    glutCreateWindow("CG TEST");
    
    init();
    glutKeyboardFunc(keys);
    glutReshapeFunc(reshape);                                        // Reshape CALLBACK function.
    glutDisplayFunc(display);                                        // Display CALLBACK function.
    glutIdleFunc(idle);                                                // Idle CALLBACK function.
    glutMainLoop();                                                    // Begin graphics program.
    return 0;                                                        // ANSI C requires a return value.
}
