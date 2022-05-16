#ifndef Matrix_H_
#define Matrix_H_
#include <iostream>
using namespace std;
class Matrix
{
	private:
		double	**data;
		int row, col;
	public:
		Matrix();
		Matrix(const int&, const int&);
		Matrix(const Matrix &src);
		virtual ~Matrix();
		void unitMatrix();

		double** getData();
		int getRow();
		int getCol();
		
		double& at(const int row, const int col);
		
		static Matrix getTranslate(const double tx = 0.0, const double ty = 0.0, const double tz = 0.0);
		static Matrix getScale(const double sx = 1.0, const double sy = 1.0, const double sz = 1.0);
		static Matrix getReflect(const double rx = 1.0, const double ry = 1.0, const double rz = 1.0);
	
		static Matrix getRotateAroundX(const double theta = 0.0);
		static Matrix getRotateAroundY(const double theta = 0.0);
		static Matrix getRotateAroundZ(const double theta = 0.0);
	
	
		friend Matrix operator*(const Matrix &M1, const Matrix &M2);
		const Matrix& operator=(const Matrix&);
		friend ostream& operator<<(ostream&, Matrix&);
};
#endif
