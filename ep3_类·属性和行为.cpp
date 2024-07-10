#include<iostream>
                                                             /*
-----Ep3.类·属性和行为-----
____________________________________________________________
··类是C++中最重要的结构。
类是对象的蓝图，对象有其属性和行为。
属性：类的成员变量。
行为：又称方法，类的成员函数。
··如何访问对象中的变量or函数？
  使用结构：对象名.变量名 or 对象名.函数名
··class类默认其属性和行为是私有，外部函数不可访问。如果要外部函数
访问变量，应该在前添加“public:”使其公有。
————————————————————————————————————————————————————————————
>>>>>题目一：表达3*3矩阵<<<<<
实现一个类Matrix，表达一个3*3的矩阵。
要求：
1.包含以下属性：
  *二维数组(用一个二阶指针double** G表示）
2.包含以下行为：
  *构造函数Matrix(double a11,double a21,……,double a33){}
  给二维数组在堆上分配内存并初始化(按列向量初始化)
  *析构函数~Matrix(){}清理内存
  *打印这个矩阵：void PrintMx(){}
  *返回其行列式的值：double determinant(){}
—————————————————————————————————————————————————————————————
>>>>>【附加题】: 表达一个三阶线性方程组<<<<<
实现一个类Equation，表达一个三阶线性方程组Ax=b，并进行简单运算。
要求：
1.包含以下属性：
  *方阵A（线性方程组的系数矩阵）：Matrix A
  *数组b：double b[3]
  注意：请运用题目一构造的矩阵类，并且使这两个属性均为只读变量。
2.包含以下行为：
  *构造函数:Equation(Matrix A, double b1,b2,b3){}
  *析构函数:~Equation(){}清理内存
  *打印增广矩阵(A|b):void PrintA_b(){}
  *利用克拉默法则解出x1,x2,x3的值并打印:void solve(){}
3.写出主函数，表达方程：
  Ax=b;
   | 0 1 4 |
A= | 1 3 7 |    b=(10,16,3)T
   |-2 -1 1|
  打印增广矩阵和方程的解x1,x2,x3
—————————————————————————————————————————————————————————————
$解注释以下入口函数来检验函数。
                                                             */
//第一题：
// 
//int main() {
//    Matrix myMx(1,3,1,0,-1,2,2,0,-5);
//    myMx.PrintMx();
//    std::cout << myMx.determinant() << std::endl;
//    system("pause");
//    return 0;
//}

/*第一题：
输出应为：
1 0 2 
3 -1 0
1 2 -5
19
*/


//作者：cheesepotato2005//NJAU//