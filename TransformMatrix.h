#ifndef TRANSFORMMATRIX_H_
#define TRANSFORMMATRIX_H_
class TransformMatrix
{
	private:
		double k_[4][4];

		void unitMatrix();
	public:
		TransformMatrix();
		TransformMatrix(const TransformMatrix &src);
		virtual ~TransformMatrix();
	
		double& at(const int row, const int col); // getter, setter
	
		void translate(const double tx = 0.0, const double ty = 0.0, const double tz = 0.0);
		void scale(const double sx = 1.0, const double sy = 1.0, const double sz = 1.0);
		// Reflection
		// xy: z = -1
		// yz: x = -1
		// xz: y = -1
		void reflect(const double rx = 1.0, const double ry = 1.0, const double rz = 1.0);
	
		void rotateAroundX(const double theta = 0.0);
		void rotateAroundY(const double theta = 0.0);
		void rotateAroundZ(const double theta = 0.0);
	
	
		friend TransformMatrix operator*(const TransformMatrix &M1, const TransformMatrix &M2);
};
#endif
