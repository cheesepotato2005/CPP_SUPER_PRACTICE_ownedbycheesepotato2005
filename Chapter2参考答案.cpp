//Chapter2.函数重载
#include<iostream>
int factorial(int a) {
	if (a == 0)return 1;// 注意0!=1
	for (int i = a - 1; i > 0; i--) {
		a *= i;
	}//实现阶乘
	return a;
}
int factorial(int a, int b) {
	return factorial(a) / factorial(b);
}
//当然，这个函数内部也可以写成另一种形式！
int factorial_new(int a, int b) {
	if (a == b) {
		return 1;
	}
	else if (a > b&&a*b!=0) {//这里必须保证a和b均不为零
		for (int i = a - 1; i != b; i--) {
			a *= i;
		}
		return a;
	}
	else if (b == 0) {
		return factorial(a);
	}//因为参数a>b>=0，所以不考虑a为0的情况。
}//这里只举例一种，还有很多种其他方法，运行成功即可。