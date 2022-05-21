#include "Drawer.h"
#include <iomanip>
#include <math.h>
Drawer::Drawer() : matrix(4, 4)
{
    matrix.unitMatrix();
}
void Drawer::inputPoint(const double &a)
{
    points[0][0] = 2 * a + 10;
    points[0][1] = 2 * a + 10;
    points[0][2] = 2 * a + 10;

    points[1][0] = 10;
    points[1][1] = 2 * a + 10;
    points[1][2] = 2 * a + 10;

    points[2][0] = 10;
    points[2][1] = 10;
    points[2][2] = 2 * a + 10;

    points[3][0] = 2 * a + 10;
    points[3][1] = 10;
    points[3][2] = 2 * a + 10;

    points[4][0] = 2 * a + 10;
    points[4][1] = 2 * a + 10;
    points[4][2] = 10;

    points[5][0] = 10;
    points[5][1] = 2 * a + 10;
    points[5][2] = 10;

    points[6][0] = 10;
    points[6][1] = 10;
    points[6][2] = 10;

    points[7][0] = 2 * a + 10;
    points[7][1] = 10;
    points[7][2] = 10;
}
void Drawer::printPoint()
{
    for (int i = 0; i < 8; i++)
    {
        cout << fixed << setprecision(2);
        cout << setw(10) << "Dinh " << (i + 1) << ": ";
        cout << "(" << setw(3);
        for (int j = 0; j < 3; j++)
        {
            cout << setw(10);
            cout << points[i][j];
            if (j == 2)
                cout << setw(3) << ")" << endl;
            else
                cout << ",";
        }
    }
    cout << endl;
}
void Drawer::DrawRotLine(int x1, int y1, int z1, int x2, int y2, int z2, int x, int y, int z)
{
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 0.0f);
    glLineWidth(10.0f);
    glVertex3s(x1 - x * 500, y1 - y * 500, z1 - z * 500);
    glVertex3s(x2 + x * 500, y2 + y * 500, z2 + z * 500);
    glEnd();
}

// Bien doi toa do cac dinh theo yeu cau (tinh tien, ty le, quay, doi xung)
void Drawer::Transpoints()
{
    float pointsFin[8][3];
    for (int k = 0; k < 8; k++)
        for (int i = 0; i < 3; i++)
            pointsFin[k][i] = matrix.at(i, 0) * points[k][0] + matrix.at(i, 1) * points[k][1] + matrix.at(i, 2) * points[k][2] + matrix.at(i, 3);
    for (int k = 0; k < 8; k++)
        for (int i = 0; i < 3; i++)
            this->points[k][i] = pointsFin[k][i];
    cout << "Cac dinh sau khi bien doi" << endl;
    printPoint();
}

// Ve cac truc toa do
void Drawer::drawCoordinateAxisZ()
{
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 2000.0f);
    glEnd();
    glLineWidth(1.0f);
}

void Drawer::drawCoordinateAxisX()
{
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 2000.0f, 0.0f);
    drawCoordinateAxisZ();
    glPopMatrix();
}

void Drawer::drawCoordinateAxisY()
{
    glPushMatrix();
    glRotatef(-90.0f, 2000.0f, 0.0f, 0.0f);
    drawCoordinateAxisZ();
    glPopMatrix();
}

void Drawer::drawFrame()
{
    glLineWidth(2.0f);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glColor3f(0.0f, 0.0f, 0.0f);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glLineWidth(1.0f);
}

// Ve cac truc toa do
void Drawer::drawCoordinateAxis()
{
    glColor3f(0.0f, 0.0f, 1.0f);
    drawCoordinateAxisZ();
    glColor3f(0.0f, 1.0f, 0.0f);
    drawCoordinateAxisY();
    glColor3f(1.0f, 0.0f, 0.0f);
    drawCoordinateAxisX();
}

// Ve khoi lap phuong theo toa do cac dinh
void Drawer::Draw()
{
    int i;
    glColor3f(0.7, 0.4, 0.7);
    glBegin(GL_POLYGON);
    glVertex3f(points[0][0], points[0][1], points[0][2]);
    glVertex3f(points[1][0], points[1][1], points[1][2]);
    glVertex3f(points[2][0], points[2][1], points[2][2]);
    glVertex3f(points[3][0], points[3][1], points[3][2]);
    glEnd();
    i = 0;
    glColor3f(0.8, 0.6, 0.5);
    glBegin(GL_POLYGON);
    glVertex3s(points[0 + i][0], points[0 + i][1], points[0 + i][2]);
    glVertex3s(points[1 + i][0], points[1 + i][1], points[1 + i][2]);
    glVertex3s(points[5 + i][0], points[5 + i][1], points[5 + i][2]);
    glVertex3s(points[4 + i][0], points[4 + i][1], points[4 + i][2]);
    glEnd();
    glColor3f(0.2, 0.4, 0.7);
    glBegin(GL_POLYGON);
    glVertex3f(points[0][0], points[0][1], points[0][2]);
    glVertex3f(points[3][0], points[3][1], points[3][2]);
    glVertex3f(points[7][0], points[7][1], points[7][2]);
    glVertex3f(points[4][0], points[4][1], points[4][2]);
    glEnd();
    i = 1;
    glColor3f(0.5, 0.4, 0.3);
    glBegin(GL_POLYGON);
    glVertex3s(points[0 + i][0], points[0 + i][1], points[0 + i][2]);
    glVertex3s(points[1 + i][0], points[1 + i][1], points[1 + i][2]);
    glVertex3s(points[5 + i][0], points[5 + i][1], points[5 + i][2]);
    glVertex3s(points[4 + i][0], points[4 + i][1], points[4 + i][2]);
    glEnd();
    i = 2;
    glColor3f(0.5, 0.6, 0.2);
    glBegin(GL_POLYGON);
    glVertex3s(points[0 + i][0], points[0 + i][1], points[0 + i][2]);
    glVertex3s(points[1 + i][0], points[1 + i][1], points[1 + i][2]);
    glVertex3s(points[5 + i][0], points[5 + i][1], points[5 + i][2]);
    glVertex3s(points[4 + i][0], points[4 + i][1], points[4 + i][2]);
    glEnd();
    i = 4;
    glColor3f(0.7, 0.3, 0.4);
    glBegin(GL_POLYGON);
    glVertex3f(points[0 + i][0], points[0 + i][1], points[0 + i][2]);
    glVertex3f(points[1 + i][0], points[1 + i][1], points[1 + i][2]);
    glVertex3f(points[2 + i][0], points[2 + i][1], points[2 + i][2]);
    glVertex3f(points[3 + i][0], points[3 + i][1], points[3 + i][2]);
    glEnd();
}

void Drawer::Translate(int tx, int ty, int tz)
{
    Matrix m;
    matrix = matrix * m.getTranslate(tx, ty, tz);
    cout << "Ma tran tinh tien:" << endl;
    cout << matrix;
    Transpoints();
}

void Drawer::Scale(float sx, float sy, float sz)
{
    Matrix m;
    matrix = m.getScale(sx, sy, sz) * matrix;
    cout << "Ma tran ty le:" << endl;
    cout << matrix;
    Transpoints();
}

void Drawer::Reflect(float rx, float ry, float rz)
{
    Matrix m;
    matrix = m.getReflect(rx, ry, rz) * matrix;
    cout << "Ma tran doi xung:" << endl;
    cout << matrix;
    Transpoints();
}

void Drawer::RotateX(float angle)
{
    Matrix m;
    matrix = m.getRotateAroundX(angle) * matrix;
    cout << "Ma tran quay theo X:" << endl;
    cout << matrix;
}

void Drawer::RotateY(float angle)
{
    Matrix m;
    matrix = m.getRotateAroundY(angle) * matrix;
    cout << "Ma tran quay theo Y:" << endl;
    cout << matrix;
}

void Drawer::RotateZ(float angle)
{
    Matrix m;
    matrix = m.getRotateAroundZ(angle) * matrix;
    cout << "Ma tran quay theo Z:" << endl;
    cout << matrix;
}

void Drawer::Rotate(float x1, float y1, float z1, float x2, float y2, float z2, float Theta)
{
    float MOD = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
    float x = (x2 - x1) / MOD;
    float y = (y2 - y1) / MOD;
    float z = (z2 - z1) / MOD;
    Translate(-x1, -y1, -z1);
    float ThetaDash = 1260 * atan(y / z) / 22;
    RotateX(ThetaDash);
    RotateY(1260 * asin(-x) / 22);
    RotateZ(Theta);
	cout << "Bien doi nguoc lai:\n";
    RotateY(1260 * asin(x) / 22);
    RotateX(-ThetaDash);
    Translate(x1, y1, z1);
}
