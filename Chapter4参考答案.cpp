#include<iostream>
#include<iomanip>
class Matrix {
public:
	double** G;//使用一个二阶指针来指向一个二维数组，你也可以使用比较简单的声明：double G[3][3]，使用这种方法声明时不再需要分配空间
	Matrix() {
		G = new double* [3];//对G分配3个double空间,分配后得到三行G[0],G[1],G[2]
		for (int i = 0; i < 3; i++) {
			G[i] = new double[3];//给每个行分配3个double空间,即可得到3*3矩阵
		}
	}//默认构造函数
	Matrix(const Matrix& other) {
		G = new double* [3];
		for (int i = 0; i < 3; i++) {
			G[i] = new double[3];//与默认构造函数相同的分配方法相同
			for (int j = 0; j < 3; j++) {
				G[i][j] = other.G[i][j];//分配成功后根据被拷贝对象进行一对一初始化
			}
		}//这是一个深拷贝过程！
	}//拷贝构造函数
	Matrix(double a11, double a21, double a31, double a12, double a22, double a32, double a13, double a23, double a33) {
		G = new double* [3];
		for (int i = 0; i < 3; i++) {
			G[i] = new double[3];
		}//分配方法与上同
		G[0][0] = a11; G[1][0] = a21; G[2][0] = a31;
		G[0][1] = a12; G[1][1] = a22; G[2][1] = a32;
		G[0][2] = a13; G[1][2] = a23; G[2][2] = a33;//一对一初始化
	}//有参构造
	~Matrix() {
		for (int i = 0; i < 3; i++) {
			delete[] G[i];
		}
		delete[] G;
	}//清理内存空间
	void PrintMx() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::cout << std::fixed << std::setprecision(0) << G[i][j] << " ";//这里运用了格式化输出控制精确度
			}
			std::cout << std::endl;//每打印一行就输出换行
		}
	}
	double determinant() {
		double det = (G[0][0] * G[1][1] * G[2][2]) + (G[0][1] * G[1][2] * G[2][0]) + (G[0][2] * G[1][0] * G[2][1]) - (G[0][2] * G[1][1] * G[2][0]) - (G[0][1] * G[1][0] * G[2][2]) - (G[0][0] * G[1][2] * G[2][1]);
		//三阶方阵求行列式，直接用对角线法则即可
		return det;
	}
	//下面这个方法是附加题可能需要的赋值运算符重载函数，仅做第一题无需写出
	Matrix& operator=(const Matrix& A) {//注意，返回值类型为引用！
		if (this == &A) {
			return *this;
		}
		for (int i = 0; i < 3; i++) {
			delete[] G[i];
		}
		delete[] G;//因为构造函数的存在，只要声明一个矩阵就一定分配了空间，所以在这里要先清理原有空间
		G = new double* [3];
		for (int i = 0; i < 3; i++) {
			G[i] = new double[3];
			for (int j = 0; j < 3; j++) {
				G[i][j] = A.G[i][j];
			}
		}//再重新分配内存进行一对一初始化，类似深拷贝过程
		return *this;//返回这个对象本身
	}
};
//【附加题】
class Equation {
	Matrix A;//这里已经分配了空间，这块内存属于Matrix A,而不属于任何一个Equation的对象
	double b[3];//这里没有在堆上申请内存
	//可见，这个类并没有申请堆上内存，不需要析构函数来清理内存。
public:
	Equation(Matrix A, double b1, double b2, double b3) {
		this->A = A;//这个步骤一定要在赋值运算符已然重载了的条件下写出。如果没有进行重载，应该用循环结构对this->A.G这个二维数组一对一地赋值！
		b[0] = b1; b[1] = b2; b[2] = b3;
	}
	void PrintA_b() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::cout << std::fixed << std::setprecision(0) << A.G[i][j] << " ";//这里运用了格式化输出
			}
			std::cout << b[i] << std::endl;//每打印A的一行就打印b[]的一个元素，形成增广阵
		}
	}
	void solve() {
		double detD = A.determinant();//系数行列式
		if (detD == 0) {
			std::cout << "This equation has an infinite number of solutions" << std::endl;
			return;//如果系数行列式不可逆，说明此方程有无穷多解，此处不考虑
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
		std::cout << "x1 = " << std::fixed << std::setprecision(0) << detD1 / detD << std::endl;
		std::cout << "x2 = " << std::fixed << std::setprecision(0) << detD2 / detD << std::endl;
		std::cout << "x3 = " << std::fixed << std::setprecision(0) << detD3 / detD << std::endl;
		//这里的运算方法，详见线性代数：克拉默法则
	}
};
int main() {
	Matrix A(0, 1, -2, 1, 3, -1, 4, 7, 1);//创建矩阵
	Equation Ax_b(A, 10, 16, 3);//有参构造方程
	Ax_b.PrintA_b();//打印增广矩阵
	Ax_b.solve();//解方程and打印结果
	system("pause");
	return 0;
}
