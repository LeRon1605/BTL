#include "Matrix.h"
#include <math.h>
#include <iomanip>

Matrix::Matrix()
{
	this -> row = 0;
	this -> col = 0;
}

Matrix::Matrix(const int &row, const int &col)
{
	data = new double*[row];
	for (int i = 0; i < col; i++)
	{
		data[i] = new double[col];
	}
	this -> row = row;
	this -> col = col;
}

Matrix::Matrix(const Matrix &src)
{
	this -> row = src.row;
	this -> col = src.col;
	for (int i = 0;i < this -> row;i++)
	{
		for (int j = 0;j < this -> col;j++)
		{
			data[i][j] = src.data[i][j];
		}
	}
}


Matrix::~Matrix()
{
}

int Matrix::getRow()
{
	return this -> row;
}

int Matrix::getCol()
{
	return this -> col;
}

double& Matrix::at(const int row, const int col)
{
	return data[row][col];
}

void Matrix::unitMatrix()
{
	for (int i = 0;i < this -> row;i++)
	{
		for (int j = 0;j < this -> col;j++)
		{
			data[i][j] = (i == j);
		}
	}
}

double** Matrix::getData()
{
	return this -> data;
}

Matrix Matrix::getTranslate(const double tx, const double ty, const double tz)
{
	Matrix translateMatrix(4, 4);
	translateMatrix.unitMatrix();
	translateMatrix.data[0][3] = tx;
	translateMatrix.data[1][3] = ty;
	translateMatrix.data[2][3] = tz;
	return translateMatrix;
}

Matrix Matrix::getScale(const double sx, const double sy, const double sz)
{
	Matrix scaleMatrix(4, 4);
	scaleMatrix.unitMatrix();
	scaleMatrix.data[0][0] = sx;
	scaleMatrix.data[1][1] = sy;
	scaleMatrix.data[2][2] = sz;
	return scaleMatrix;
}

Matrix Matrix::getReflect(const double rx, const double ry, const double rz)
{
	Matrix reflectMatrix(4, 4);
	reflectMatrix.unitMatrix();
	reflectMatrix.data[0][0] = rx;
	reflectMatrix.data[1][1] = ry;
	reflectMatrix.data[2][2] = rz;
	return reflectMatrix;
}

Matrix Matrix::getRotateAroundZ(const double theta)
{
	Matrix RotateZ(4, 4);
	RotateZ.unitMatrix();

	double c = cos(theta);
	double s = sin(theta);

	RotateZ.data[0][0] = c;
	RotateZ.data[0][1] = -s;
	RotateZ.data[1][0] = s;
	RotateZ.data[1][1] = c;
	return RotateZ;
}

Matrix Matrix::getRotateAroundX(const double theta)
{
	Matrix RotateX(4, 4);
	RotateX.unitMatrix();

	double c = cos(theta);
	double s = sin(theta);

	RotateX.data[1][1] = c;
	RotateX.data[1][2] = -s;
	RotateX.data[2][1] = s;
	RotateX.data[2][2] = c;
	return RotateX;
}

Matrix Matrix::getRotateAroundY(const double theta)
{
	Matrix RotateY(4, 4);
	RotateY.unitMatrix();

	double c = cos(theta);
	double s = sin(theta);

	RotateY.data[0][0] = c;
	RotateY.data[0][2] = s;
	RotateY.data[2][0] = -s;
	RotateY.data[2][2] = c;
	return RotateY;
}

Matrix operator*(const Matrix &M1, const Matrix &M2)
{
	Matrix result(4, 4);

	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			double pre = 0.0;
			for (int t = 0; t < 4; t++)
			{
				pre += M1.data[r][t] * M2.data[t][c];
			}
			result.data[r][c] = pre;
		}
	}

	return result;
}

ostream& operator<<(ostream& out, Matrix &m) 
{
	for (int i = 0; i < m.getRow(); i++)
    {
        cout << endl << setw(5) << "|" << setw(10);
        for (int j = 0; j < m.getCol(); j++)
        {
            cout << setw(10) << m.at(i, j);
            if (j == m.getCol() - 1) cout << setw(3) << "|";
        }
    }
    cout << endl << endl;
}

const Matrix& Matrix::operator=(const Matrix &m)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			this -> data[i][j] = m.data[i][j];
		}
	}
	return *this;
}
