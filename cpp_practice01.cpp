#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;

int main() {
    // 设置控制台代码页为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    int age = 23;
    int x = 1810;
    int y = 600;
    double sum = x + y;
    float quotient = x/y;

    std::cout << "Hello,C++ World!" << endl;
    cout << "今天是我学习cpp的第一天。" << endl;
    cout << "我是一名大学生，专业是电子信息工程" << endl;
    std::cout << "引号：\"Hello\"" << std::endl;
    std::cout << "反斜杠：\\" << std::endl;
    cout << "制表符：\t制表符后的内容" << std::endl;
    std::cout << "我现在" << age << "岁啦。" << std::endl;
    std::cout << "商数 =" << quotient << '\n';
    std::cout << "和 = " << sum << '\n'<< std::endl;
    
    return 0;
}