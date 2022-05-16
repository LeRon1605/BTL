#ifndef Drawer_H_
#define Drawer_H_
#include "Matrix.h"
#include <iostream>
#include <GL/glut.h>
using namespace std;
class Drawer
{
    private:
        Matrix matrix;
        float points[8][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    public:
        Drawer();
        void inputPoint(const double&);
        void printPoint();
        void Transpoints();
        void drawCoordinateAxisZ();
        void drawCoordinateAxisX();
        void drawCoordinateAxisY();
        void drawFrame();
        void drawCoordinateAxis();
        void Draw();
        void DrawRotLine(int x1, int y1, int z1, int x2, int y2, int z2, int x, int y, int z);
        void Translate(int, int, int);
        void Scale(float, float, float);
        void Reflect(float, float, float);
};
#endif
