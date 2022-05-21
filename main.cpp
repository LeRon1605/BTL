#include <math.h>
#include "Drawer.h"
Drawer drawer;
float TransDistX, TransDistY, TransDistZ; 
float ScaleX, ScaleY, ScaleZ;        
float Theta;                       
float x, y, z;
float x1, y11, z1, x2, y2, z2;
int choice, choiceRef;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawer.drawFrame();
    gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    drawer.drawCoordinateAxis();
    glColor3f(1.0, 0.0, 0.0);
    drawer.Draw();

    switch (choice)
    {
	    case 1:
	    	drawer.Translate(TransDistX, TransDistY, TransDistZ);
	        break;
	    case 2:
	        drawer.Scale(ScaleX, ScaleY, ScaleZ);
	        break;
	    case 3:
	    {
	        drawer.DrawRotLine(x1, y11, z1, x2, y2, z2, x, y, z);
            drawer.Rotate(x1, y11, z1, x2, y2, z2, Theta);
	        break;
	    }
	    case 4:
	        switch (choiceRef)
		    {
		    case 1:
		        drawer.Reflect(1.0, 1.0, -1.0);
		        break;
		    case 2:
		        drawer.Reflect(-1.0, 1.0, 1.0);
		        break;
		    case 3:
		         drawer.Reflect(1.0, -1.0, 1.0);
		        break;
		    }
	        break;
    }
    drawer.Draw();
    glFlush();
}

void init()
{
    glOrtho(-1000.0, 1000.0, -500.0, 500.0, -500.0, 500.0);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char *argv)
{
    glutInit(&argc, &argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1362, 750);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("BTL");
    init();
    
    float a;
    cout << "Nhap do dai canh: ";
    cin >> a;
    drawer.inputPoint(a);
    cout << "\tCac dinh ban dau: " << endl;
    drawer.printPoint();
    cout << "Chon phep bien doi:\n1.Tinh tien\n2.Ty le\n3.Quay\n4.Doi xung\n=>";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Nhap gia tri tinh tien theo X, Y, Z\n=>";
        cin >> TransDistX >> TransDistY >> TransDistZ;
        break;
    case 2:
        cout << "Nhap gia tri ty le theo X, Y, Z\n=>";
        cin >> ScaleX >> ScaleY >> ScaleZ;
        break;
    case 3:
        cout << "Nhap toa do 2 diem (x1,y1,z1) & (x2,y2,z2)\n =>";
        cout << "Nhap gia tri x1 ,y1, z1:\n";
        cin >> x1 >> y11 >> z1;
        cout << "Nhap gia tri x2 ,y2, z2:\n";
        cin >> x2 >> y2 >> z2;
        cout << "Nhap gia tri goc quay: ";
        cin >> Theta;
        break;
    case 4:
        cout << "Chon mat phang doi xung:\n1.Oxy\n2.Oyz\n3.Oxz\n=>";
        cin >> choiceRef;
        break;
    default:
        cout << "Gia tri khong hop le!!!\n";
        return 0;
    }
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
