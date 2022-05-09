#include <GL/glut.h>
#include "TransformMatrix.h"
#include <math.h>
#define VAL_PI 3.1415
void Init()
{
	  glClearColor(0.0, 0.0, 0.0, 0.0);
	  glEnable(GL_LIGHTING);
	  glEnable(GL_LIGHT0);
	  glEnable(GL_DEPTH_TEST);
	
	  GLfloat light_pos [] = {0.0, 0.0, 1.0, 0.0};
	  glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	
	  GLfloat ambient [] = {1.0, 1.0, 0.0, 1.0};
	  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	
	  GLfloat diff_use [] = {0.5, 1.0, 0.0, 1.0};
	  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
	
	  GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
	  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	
	  GLfloat shininess = 50.0f;
	  glMateriali(GL_FRONT, GL_SHININESS, shininess);

}

void MakeCube(const float& size)
{
	  glBegin(GL_QUADS);
	  // Front Face
	  glNormal3f(0.0, 0.0, 1.0);
	  glVertex3f(-size, -size, size);
	  glVertex3f( size, -size, size);
	  glVertex3f( size, size, size);
	  glVertex3f(-size, size, size);
	  // Back Face
	  glNormal3f(0.0, 0.0, -1.0);
	  glVertex3f(-size, -size, -size);
	  glVertex3f(-size, size, -size);
	  glVertex3f(size, size, -size);
	  glVertex3f(size, -size, -size);
	  // Top Face
	  glNormal3f(0.0, 1.0, 0.0);
	  glVertex3f(-size, size, -size);
	  glVertex3f(-size, size, size);
	  glVertex3f( size, size, size);
	  glVertex3f( size, size, -size);
	  // Bottom Face
	  glNormal3f(0.0, -1.0, 0.0);
	  glVertex3f(-size, -size, -size);
	  glVertex3f( size, -size, -size);
	  glVertex3f( size, -size, size);
	  glVertex3f(-size, -size, size);
	  // Right face
	  glNormal3f(1.0, 0.0, 0.0);
	  glVertex3f( size, -size, -size);
	  glVertex3f( size, size, -size);
	  glVertex3f( size, size, size);
	  glVertex3f( size, -size, size);
	  // Left Face
	  glNormal3f(-1.0, 0.0, 0.0);
	  glVertex3f(-size, -size, -size);
	  glVertex3f(-size, -size, size);
	  glVertex3f(-size, size, size);
	  glVertex3f(-size, size, -size);
	
	  glEnd();
}

void DrawCoorDinate()
{
	  glDisable(GL_LIGHTING);
	  glPushMatrix();
	  glBegin(GL_LINES);
	  glColor3f(1.0, 0.0, 0.0);
	  glVertex3f(-100, 0.0, 0.0);
	  glVertex3f(100, 0.0, 0.0);
	  glEnd();
	
	  glBegin(GL_LINES);
	  glColor3f(0.0, 1.0, 0.0);
	  glVertex3f(0, -100.0, 0.0);
	  glVertex3f(0, 100.0, 0.0);
	  glEnd();
	
	  glBegin(GL_LINES);
	  glColor3f(0.0, 0.0, 1.0);
	  glVertex3f(0, 0.0, -100.0);
	  glVertex3f(0, 0.0, 100.0);
	  glEnd();
	
	  glPopMatrix();
	  glEnable(GL_LIGHTING);
}

void RenderScene()
{
	  glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	  glLoadIdentity();
	  gluLookAt(3.0, 5.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	  DrawCoorDinate();
	  glTranslatef(0.5, 0.0, 0.0);
	  glPushMatrix();
	  MakeCube(1.0);
	  glPopMatrix();
	  glFlush();
}
void ReShape(int width, int height)
{
	  if (height == 0)
	  {
	    height = 1;
	  }
	  float ratio = (float)width/(float)height;
	  glViewport(0, 0, width, height);
	  glMatrixMode(GL_PROJECTION);
	  glLoadIdentity();
	
	  gluPerspective(45.0, ratio, 0.1, 100.0);
	  glMatrixMode(GL_MODELVIEW);

}
int main()
{
	  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	  glutInitWindowSize(640, 480);
	  glutInitWindowPosition(100, 100);
	  glutCreateWindow("Opengl Study");
	
	  Init();
	  glutReshapeFunc(ReShape);
	  glutDisplayFunc(RenderScene);
	  glutMainLoop();
	
	  return 0;
}
