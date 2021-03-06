/*Kuzminov Artem, 13/03/2017, 10-4*/

#include <stdlib.h>
#include <glut.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "pic.h"

unsigned char Frame[Frame_H][Frame_W][3];

void Keyboard(unsigned char Key, int X, int Y)
{
	if (Key == 27)
		exit(0);
}

void Display(void)
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glRasterPos2d(-1, 1);
	glPixelZoom(1, -1);

        DrawPicFile("X:\\PICS\\M.G24", 3, 3);

	glDrawPixels(Frame_W, Frame_H, GL_BGR_EXT, GL_UNSIGNED_BYTE, Frame);
	glFinish();

	glutSwapBuffers();
	glutPostRedisplay();
}



int main(int argc, char *argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutInitWindowPosition(50, 50);
	glutInitWindowSize(Frame_W, Frame_H);
        glutCreateWindow("PICS");
	
	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);

	glutMainLoop();

	return 0;
}
