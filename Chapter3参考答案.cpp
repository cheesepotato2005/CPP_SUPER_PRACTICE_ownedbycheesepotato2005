#include<iostream>
#include<string>
using namespace std;
class Car {
public:
	string brand;
	int price;
	int fuel_cspt;
	int speed;
	int mobilizeTime;
	int pullUpTime;
	Car(string Brand,int Price,int Fuel_cspt) {
		brand = Brand;
		price = Price;
		fuel_cspt = Fuel_cspt;
		speed = 0;
		mobilizeTime = 0;
		pullUpTime = 0;
	}
	//因为此题不需要深拷贝，所以让编译器提供浅拷贝函数即可。
	void Mobilize(int MobTime, int Speed) {
		mobilizeTime = MobTime;
		speed = Speed;
		//记录发动时刻和平均速率
	}
	void pullUp(int PullUpTime) {
		pullUpTime = PullUpTime;
	}//记录停车时刻
	double Fuel_consumption() {
		int time = pullUpTime - mobilizeTime;
		int distance = speed * time;
		return distance * fuel_cspt / 100.0;
	}
};
int main() {
	Car myCar("Bentley", 273, 7);
	myCar.Mobilize(3, 80);
	myCar.pullUp(9);
	cout << "品牌：" << myCar.brand << endl << "价格：" << myCar.price << "万元" << endl;
	cout << "这趟行程油耗为：" << myCar.Fuel_consumption() << "L" << endl;
}//答案为33.6L