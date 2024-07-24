#include<iostream>
#include <chrono>
#include <thread>
#include<Windows.h>
#include<cmath>
//1
class Bomb {
    int m_count;
    int m_yield;
    int m_escape;
    Bomb(int count, int yield) {
        m_count = count;
        m_yield = yield;
        m_escape = count;
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
    Bomb& operator--();
};

//重载前置递减
Bomb& Bomb::operator--() {
    m_count--;
    m_escape -= m_yield;
    if (m_escape < 0) {
        m_escape = 0;
    }
    return *this;
}

//2
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
bool player::operator==(player B) {
    double A_power = pow((0.6 * max_Hp + 2.1 * defense) * 2.72, attack);
    double B_power = pow((0.6 * B.max_Hp + 2.1 * B.defense) * 2.72, B.attack);
    if (fabs(A_power - B_power) < 1e-6)
        return 1;
    else
        return 0;
}
bool player::operator>(player B) {
    double A_power = pow((0.6 * max_Hp + 2.1 * defense) * 2.72, attack);
    double B_power = pow((0.6 * B.max_Hp + 2.1 * B.defense) * 2.72, B.attack);
    if (fabs(A_power - B_power) > 1e-6)
        return 1;
    else
        return 0;
}
bool player::operator<(player B) {
    double A_power = pow((0.6 * max_Hp + 2.1 * defense) * 2.72, attack);
    double B_power = pow((0.6 * B.max_Hp + 2.1 * B.defense) * 2.72, B.attack);
    if (fabs(B_power - A_power) > 1e-6)
        return 1;
    else
        return 0;
}