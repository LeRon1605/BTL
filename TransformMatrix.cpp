#include "TransformMatrix.h"
#include <math.h>

TransformMatrix::TransformMatrix()
{
	unitMatrix();
}


TransformMatrix::TransformMatrix(const TransformMatrix &src)
{
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			k_[r][c] = src.k_[r][c];
		}
	}
}


TransformMatrix::~TransformMatrix()
{
}


double& TransformMatrix::at(const int row, const int col)
{
	return k_[row][col];
}


/* unit matrix initialization
//
//  /  1   0   0   0  \
//  |  0   1   0   0  |
//  |  0   0   1   0  |
//  \  0   0   0   1  /
*/

void TransformMatrix::unitMatrix()
{
	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			k_[r][c] = (r == c);
		}
	}
}


/* translation matrix
//
//  /  1   0   0  tx  \
//  |  0   1   0  ty  |
//  |  0   0   1  tz  |
//  \  0   0   0   1  /
*/

void TransformMatrix::translate(const double tx, const double ty, const double tz)
{
	unitMatrix();

	k_[0][3] = tx;
	k_[1][3] = ty;
	k_[2][3] = tz;
}


/* scale matrix
//
//  / sx   0   0   0  \
//  |  0  sy   0   0  |
//  |  0   0  sz   0  |
//  \  0   0   0   1  /
*/

void TransformMatrix::scale(const double sx, const double sy, const double sz)
{
	unitMatrix();

	k_[0][0] = sx;
	k_[1][1] = sy;
	k_[2][2] = sz;
}

void TransformMatrix::reflect(const double rx, const double ry, const double rz)
{
	unitMatrix();

	k_[0][0] = rx;
	k_[1][1] = ry;
	k_[2][2] = rz;
}

/* Z rotation matrix
//
//  /  cos(t)   -sin(t)      0         0  \
//  |  sin(t)    cos(t)      0         0  |
//  |    0         0         1         0  |
//  \    0         0         0         1  /
*/

void TransformMatrix::rotateAroundZ(const double theta)
{
	unitMatrix();

	double c = cos(theta);
	double s = sin(theta);

	k_[0][0] = c;
	k_[0][1] = -s;
	k_[1][0] = s;
	k_[1][1] = c;
}


/* X rotation matrix
//
//  /    1         0         0         0  \
//  |    0       cos(t)   -sin(t)      0  |
//  |    0       sin(t)    cos(t)      0  |
//  \    0         0         0         1  /
*/

void TransformMatrix::rotateAroundX(const double theta)
{
	unitMatrix();

	double c = cos(theta);
	double s = sin(theta);

	k_[1][1] = c;
	k_[1][2] = -s;
	k_[2][1] = s;
	k_[2][2] = c;
}


/* Y rotation matrix
//
//  /  cos(t)      0       sin(t)      0  \
//  |    0         1         0         0  |
//  | -sin(t)      0       cos(t)      0  |
//  \    0         0         0         1  /
*/

void TransformMatrix::rotateAroundY(const double theta)
{
	unitMatrix();

	double c = cos(theta);
	double s = sin(theta);

	k_[0][0] = c;
	k_[0][2] = s;
	k_[2][0] = -s;
	k_[2][2] = c;
}

TransformMatrix operator*(const TransformMatrix &M1, const TransformMatrix &M2)
{
	TransformMatrix result;

	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			double pre = 0.0;
			for (int t = 0; t < 4; t++)
			{
				pre += M1.k_[r][t] * M2.k_[t][c];
			}
			result.k_[r][c] = pre;
		}
	}

	return result;
}
