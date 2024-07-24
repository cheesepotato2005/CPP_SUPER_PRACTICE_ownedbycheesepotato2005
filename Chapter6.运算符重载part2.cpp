#include<iostream>
#include <chrono>
#include <thread>
#include<Windows.h>
#include<cmath>
                                                 /*
        -----Chapter6.运算符重载part2-----
_________________________________________________
Read the Title.这章继续练习运算符的重载
—————————————————————————————————————————————————
              1.递增/递减运算符的重载
定义如下类：
                                                 */
class Bomb {
public:
    //没错这是个炸弹
    int m_count;//这是炸弹的倒计时
    int m_yield;//这是炸药的TNT当量
    int m_escape;//这是安全逃离时间

    Bomb(int count,int yield) {
        m_count = count;
        m_yield = yield;
        m_escape = count;//安全逃离时间的初始值和倒计时相同
    }

    void motivateBomb() {
        while (m_count != 0) {
            std::cout << "剩余时间: " << m_count << " 秒\n";
            std::cout << "安全逃离时间：" << m_escape << " 秒\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            //这个语句的功能是让线程休眠一秒,实现计时功能
            --*this;//注意这里是前置递减
            system("cls");//控制台清屏
        }
        std::cout << "炸弹爆炸！" << std::endl;
    }//炸弹启动函数

    Bomb& operator--();//这是你要实现的函数
};
                                                  /*
motivateBomb()是一个显示装置，让炸弹每隔一秒更新一次
状态并输出倒计时和安全逃离时间。并在最后输出爆炸信息。
*倒计时更新规则：
    倒计时每秒减少一秒；
*安全逃离时间更新规则：
    安全逃离时间每秒减少当量秒;假设当量为3，则每秒减少
3秒。举例：10，7，4，1，0，0，0……
    注意：安全逃离时间不得为负数。
【要求】
  用成员函数重载递减运算符，让下面的入口函数正常运作。
  $解注释下方入口函数以检验程序。
                                                  */

//int main() {
//    Bomb myBomb(10, 3);
//    myBomb.motivateBomb();
//    system("pause");
//}

                                                  /*
__________________________________________________
                2.关系运算符重载
定义如下类：
                                                  */
class player {
public:
    std::string name;//角色名
    double max_Hp;//最大生命值
    double attack;//攻击力
    double defense;//防御力

    bool operator==(player B);
    bool operator>(player B);
    bool operator<(player B);
    //这是需要你重载的三个函数
};
                                                  /*
有两个玩家A和B，请比较他们的战斗力大小。
     战斗力 = (0.6*max_Hp + 2.1*defense)*e^attack
e为自然底数，取2.72
【要求】
重载相等运算符==、大于运算符>、小于运算符<，使得下面的
函数能够正常生效。
                                                  */
void Battle(player A,player B) {
    if (A == B) {
        std::cout << "平局" << std::endl;
    }
    if (A > B) {
        std::cout << A.name << "胜利" << std::endl;
    }
    if (A < B) {
        std::cout << B.name << "胜利" << std::endl;
    }
}

                                                   /*
___________________________________________________
             3.仿函数（函数调用运算符重载）

阅读下面这个程序，回答注释中的问题：
                                                   */
class Event {
public:
    int n;//事件个数
    double* p;//某事件发生的概率(p<1)
    double* w;//此事件的结果
    Event(int N) {
        n = N;
        p = new double[n];
        w = new double[n];
        double p_sum = 0;
        for (int i = 0; i < n; i++) {
            p[i] = w[i] = 0;
        }
        std::cout << "请依次输入" << n << "个事件发生的概率：" << std::endl;
        for (int i = 0; i < n; i++) {
            std::cin >> p[i];
            if (p[i] > 1) {
                std::cerr << "概率输入有误：概率应该均小于1" << std::endl;
                delete[] p;
                delete[] w;
                exit(EXIT_FAILURE);
            }
            p_sum += p[i];
        }
        if (fabs(p_sum - 1.0) > 1e-6) {//【思考】这里的p_sum-1.0>1e-6是什么意思？
            std::cerr << "概率输入有误：概率总和应该为1" << std::endl;
            delete[] p;
            delete[] w;
            exit(EXIT_FAILURE);
        }
        std::cout << "请依次输入" << n << "个事件的结果值：" << std::endl;
        for (int i = 0; i < n; i++) {
            std::cin >> w[i];
        }
    }
    ~Event() {
        delete[] p;
        delete[] w;
    }
};
class Expectation {//求期望
public:
    double operator()(Event& event) {//【思考】为什么参数是引用？如果不使用引用会导致什么后果？
        double E = 0;
        for (int i = 0; i < event.n; i++) {
            E += event.p[i] * event.w[i];
        }
        return E;
    }
};
//int main() {
//    Event myEvent(5);
//    Expectation getExpect;
//    std::cout << "数学期望:" << getExpect(myEvent) << std::endl;
//    //【思考】getExpect是一个函数吗？为什么？
//    system("pause");
//}
