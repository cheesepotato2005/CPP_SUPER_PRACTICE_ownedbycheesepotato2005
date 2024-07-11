#include<iostream>
                                                         /*
-----Chapter2.函数重载-----
_________________________________________________________
··函数重载就是用一个函数名实现多种功能
··举例：
int merge(int a, int b){}//返回两个数的和
int merge(int a, int b, int c){}//返回三个数的和          
—————————————————————————————————————————————————————————     
$解注释下方代码（12-23行）运行试试！
                                                         */
//int merge(int a, int b) {
//    return a + b;
//}
//int merge(int a, int b, int c) {
//    return a + b + c;
//}
//int main() {
//    int a = 0, b = 1, c = 2;
//    std::cout << merge(a, b) << std::endl;
//    std::cout << merge(a, b, c) << std::endl;
//    return 0;
//}

                                                                    /*
    可以发现，虽然使用了相同的函数名称merge，但因为参数个数不同，编译器
认出了他们是不同的函数！
    除了参数个数，还可以用参数的类型来区别不同的函数。
    比如：void func(int a,int b)和void func(int a, char b)                                    
                                                                    */
                                                                    /*
____________________________________________________________________
>>>>>题目一：请撰写一个函数及其重载实现以下功能：
            1.当输入一个整型参数a时，返回a的阶乘a!;
            2.当输入两个整型参数a，b(a>b)时，返回a!/b!;
            函数名规定为factorial
————————————————————————————————————————————————————————————————————
$解注释下方入口函数进行检验
检验结果应为：
    24
    1
    20
                                                                    */

//int main() {
//    std::cout << factorial(4) << std::endl;
//    std::cout << factorial(0) << std::endl;
//    std::cout << factorial(5, 3) << std::endl;
//    return 0;
//}

//作者：cheesepotato2005//NJAU//
