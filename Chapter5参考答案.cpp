#include<iostream>
#include<string>
using namespace std;
class Account {
	int balance;
	int debt;
	bool status;
public:
	string name;
	string number;
	Account() {
		name = "小明";
		number = "19223110";
		balance = 8000;
		debt = 2000;
		status = 0;//这里默认不启用账户，也可以默认启用，根据具体情况而定。
	}
	Account(string name,string number,int balance,int debt) {
		this->name = name;
		this->number = number;
		this->balance = balance;
		this->debt = debt;
		status = 0;
	}
	void enable() {
		this->status = 1;
	}
	void disable() {
		this->status = 0;
	}
	int getBalance() {
		return balance;
	}
	int getDebt() {
		return debt;
	}
	Account operator+(const Account& other) {
		Account tempSum;
		tempSum.name = this->name;
		tempSum.number = this->number;
		tempSum.balance = this->balance + other.balance;//this还是指向本对象，即重载后"+"前面的对象
		tempSum.debt = this->debt + other.debt;
		return tempSum;
	}
};

Account MergeAccout(Account A, Account B) {
	Account C = A + B;
	A.disable();
	B.disable();
	C.enable();
	return C;
}
//思考：为什么这个合并函数不能返回一个引用？
/*
答：我们不能返回一个局部变量的引用，因为局部变量在作用域结束之后就会被销毁，返回其引用属于非法操作！
而返回值的情况中，函数实际上是返回一个拷贝，这是合法的。
*/
ostream& operator<<(ostream &cout,Account &C) {
	cout << "姓名：" << C.name << "\n账号：" << C.number << "\n存款：" << C.getBalance() << "\n欠款：" << C.getDebt();
	return cout;
}//左移运算符一般用全局函数重载，因为这样才能在调用函数时，使得cout在左面。

void getInfo(Account C) {
	cout << C << endl;
}

int main() {
	Account A; A.enable();
	Account B("小明", "19223108", 964, 952); B.enable();
	Account C = MergeAccout(A, B);
	getInfo(C);
	system("pause");
}


