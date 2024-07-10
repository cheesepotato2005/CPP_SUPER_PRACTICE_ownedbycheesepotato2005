#include<iostream>
#include<iomanip>
//Chapter1.引用

//第一题
void swap(int& a,int& b) {
	int temp = a;
	a = b;
	b = temp;
}

/*——————————————————————————————————————————————————————————
第二题：
  此程序输出结果为：
  2025

  1.Function()所返回的是一个引用，相当于a。
  2.a是一个静态变量，并不是局部的。不会因为函数的退出而自动销毁。
  ——————————————————————————————————————————————————————————
*/

//Chapter2.函数重载
int factorial(int a) {
	if (a == 0)return 1;// 注意0!=1
	for (int i = a - 1; i > 0; i--) {
		a *= i;
	}
	return a;
}
int factorial(int a, int b) {
	return factorial(a) / factorial(b);
}


//Chapter3.类·属性和行为
class Matrix {
public:
	double** G;
	Matrix(){
		G = new double* [3];
		for (int i = 0; i < 3; i++) {
			G[i] = new double[3];
		}
	}//默认构造函数
	Matrix(const Matrix& other) {
		G = new double* [3];
		for (int i = 0; i < 3; i++) {
			G[i] = new double[3];
			for (int j = 0; j < 3; j++) {
				G[i][j] = other.G[i][j];
			}
		}
	}//拷贝构造函数
	Matrix(double a11,double a21,double a31,double a12,double a22,double a32,double a13,double a23,double a33) {
		G = new double*[3];
		for (int i = 0; i < 3; i++) {
			G[i] = new double[3];
		}
		G[0][0] = a11; G[1][0] = a21; G[2][0] = a31;
		G[0][1] = a12; G[1][1] = a22; G[2][1] = a32;
		G[0][2] = a13; G[1][2] = a23; G[2][2] = a33;
	}//有参构造
	~Matrix() {
		for (int i = 0; i < 3; i++) {
			delete[] G[i];
		}
		delete[] G;
	}
	void PrintMx() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::cout << std::fixed << std::setprecision(0) << G[i][j] << " ";//这里运用了格式化输出
			}
			std::cout << std::endl;
		}
	}
	double determinant() {
		double det = (G[0][0] * G[1][1] * G[2][2] )+ (G[0][1] * G[1][2] * G[2][0] )+ (G[0][2] * G[1][0] * G[2][1] )- (G[0][2] * G[1][1] * G[2][0] )- (G[0][1] * G[1][0] * G[2][2] )- (G[0][0] * G[1][2] * G[2][1]);
		//三阶方阵求行列式，直接用对角线法则即可
		return det;
	}
	//下面这个方法是附加题所需要的，仅作第一题可以不写
	Matrix& operator=(const Matrix& A) {
		if (this == &A) {
			return *this;
		}
		for (int i = 0; i < 3; i++) {
			delete[] G[i];
		}
		delete[] G;//清理原有空间
		G = new double* [3];
		for (int i = 0; i < 3; i++) {
			G[i] = new double[3];
			for (int j = 0; j < 3; j++) {
				G[i][j] = A.G[i][j];
			}
		}
		return *this;
	}
};
//【附加题】
class Equation {
	Matrix A;
	double b[3];
public:
	Equation(Matrix A,double b1,double b2,double b3) {
		this->A = A;
		b[0] = b1; b[1] = b2; b[2] = b3;
	}
	void PrintA_b() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::cout << std::fixed << std::setprecision(0) << A.G[i][j] << " ";//这里运用了格式化输出
			}
			std::cout << b[i] << std::endl;
		}
	}
	void solve() {
		double detD = A.determinant();
		if (detD == 0) {
			std::cout << "The equation has no solution" << std::endl;
			return;
		}
		Matrix D1 = A;
		for (int i = 0; i < 3; i++) {
			D1.G[i][0] = b[i];
		}
		Matrix D2 = A;
		for (int i = 0; i < 3; i++) {
			D2.G[i][1] = b[i];
		}
		Matrix D3 = A;
		for (int i = 0; i < 3; i++) {
			D3.G[i][2] = b[i];
		}
		double detD1 = D1.determinant();
		double detD2 = D2.determinant();
		double detD3 = D3.determinant();
		std::cout << "x1 = " << std::fixed << std::setprecision(0) << detD1/detD << std::endl;
		std::cout << "x2 = " << std::fixed << std::setprecision(0) << detD2/detD << std::endl;
		std::cout << "x3 = " << std::fixed << std::setprecision(0) << detD3/detD << std::endl;
	}
};
int main() {
	Matrix A(0, 1, -2, 1, 3, -1, 4, 7, 1);
	Equation Ax_b(A, 10, 16, 3);
	Ax_b.PrintA_b();
	Ax_b.solve();
}
