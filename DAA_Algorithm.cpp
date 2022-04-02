#include<GL/glut.h>
#include<iostream>
#include<cmath>
using namespace std; float x1, x2, Y1, y2;
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	float dy, dx, step, x, y, k, Xin, Yin;
	dx = x2 - x1;
	dy = y2 - Y1;
	if (abs(dx) > abs(dy))
	{
		step = abs(dx);
	}
	else step =
		abs(dy);
	Xin = dx / step;
	Yin = dy / step;
	x = x1;
	y = Y1;
	glBegin(GL_POINTS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(x, y);
	glEnd();
	for (k = 1; k <= step; k++)
	{
		x = x + Xin;
		y = y + Yin;
		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();
	}
	glFlush();
}
void init(void)
{
	glClearColor(1, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 400, 0, 400);
}
int main(int argc, char** argv)
{
	cout << "Enter the value of x1:"; cin >> x1;
	cout << "Enter the value of y1:";
	cin >> Y1;
	cout << "Enter the value of x2:";
	cin >> x2;
	cout << "Enter the value of y2:";
	cin >> y2;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("DDA line drawing algorithm");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}