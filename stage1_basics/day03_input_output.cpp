/*
 * C++ 学习计划 - 第3天：输入输出与运算符
 * 学习目标：
 * 1. 掌握cin和cout的使用
 * 2. 学习各种运算符
 * 3. 编写交互式程序
 */

#include <iostream>
#include <string>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "=== C++ 输入输出与运算符学习 ===" << std::endl;
    
    // 1. 基本输入输出
    std::cout << "\n1. 用户信息输入：" << std::endl;
    std::string name;
    int age;
    double height;
    
    std::cout << "请输入你的姓名: ";
    std::cin >> name;
    
    std::cout << "请输入你的年龄: ";
    std::cin >> age;
    
    std::cout << "请输入你的身高(米): ";
    std::cin >> height;
    
    std::cout << "\n你好, " << name << "!" << std::endl;
    std::cout << "你今年 " << age << " 岁" << std::endl;
    std::cout << "身高 " << height << " 米" << std::endl;
    
    // 2. 算术运算符
    std::cout << "\n2. 算术运算符演示：" << std::endl;
    int a = 10, b = 3;
    
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "a + b = " << (a + b) << std::endl;  // 加法
    std::cout << "a - b = " << (a - b) << std::endl;  // 减法
    std::cout << "a * b = " << (a * b) << std::endl;  // 乘法
    std::cout << "a / b = " << (a / b) << std::endl;  // 除法(整数)
    std::cout << "a % b = " << (a % b) << std::endl;  // 取余
    
    // 浮点数除法
    double da = 10.0, db = 3.0;
    std::cout << "10.0 / 3.0 = " << (da / db) << std::endl;
    
    // 3. 比较运算符
    std::cout << "\n3. 比较运算符演示：" << std::endl;
    int x = 5, y = 8;
    
    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "x == y: " << (x == y) << std::endl;  // 等于
    std::cout << "x != y: " << (x != y) << std::endl;  // 不等于
    std::cout << "x < y: " << (x < y) << std::endl;    // 小于
    std::cout << "x > y: " << (x > y) << std::endl;    // 大于
    std::cout << "x <= y: " << (x <= y) << std::endl;  // 小于等于
    std::cout << "x >= y: " << (x >= y) << std::endl;  // 大于等于
    
    // 4. 逻辑运算符
    std::cout << "\n4. 逻辑运算符演示：" << std::endl;
    bool p = true, q = false;
    
    std::cout << "p = " << p << ", q = " << q << std::endl;
    std::cout << "p && q: " << (p && q) << std::endl;  // 逻辑与
    std::cout << "p || q: " << (p || q) << std::endl;  // 逻辑或
    std::cout << "!p: " << (!p) << std::endl;          // 逻辑非
    std::cout << "!q: " << (!q) << std::endl;
    
    // 5. 自增自减运算符
    std::cout << "\n5. 自增自减运算符：" << std::endl;
    int count = 5;
    
    std::cout << "初始值 count = " << count << std::endl;
    std::cout << "count++ = " << count++ << std::endl;  // 后置自增
    std::cout << "现在 count = " << count << std::endl;
    std::cout << "++count = " << ++count << std::endl;  // 前置自增
    std::cout << "现在 count = " << count << std::endl;
    
    // 6. 实际应用：简单计算器
    std::cout << "\n6. 简单计算器：" << std::endl;
    double num1, num2;
    char operation;
    
    std::cout << "请输入第一个数字: ";
    std::cin >> num1;
    
    std::cout << "请输入运算符 (+, -, *, /): ";
    std::cin >> operation;
    
    std::cout << "请输入第二个数字: ";
    std::cin >> num2;
    
    double result;
    bool validOperation = true;
    
    switch(operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if(num2 != 0) {
                result = num1 / num2;
            } else {
                std::cout << "错误：除数不能为0！" << std::endl;
                validOperation = false;
            }
            break;
        default:
            std::cout << "错误：无效的运算符！" << std::endl;
            validOperation = false;
    }
    
    if(validOperation) {
        std::cout << num1 << " " << operation << " " << num2 << " = " << result << std::endl;
    }
    
    return 0;
}

/*
 * 练习任务：
 * 1. 运行程序，输入你的个人信息
 * 2. 尝试不同的运算符组合
 * 3. 测试计算器功能
 * 4. 观察整数除法和浮点数除法的区别
 * 
 * 编译命令：
 * g++ -o day03 day03_input_output.cpp
 * 
 * 扩展练习：
 * 1. 添加更多运算符（如求幂、开方）
 * 2. 改进错误处理
 * 3. 添加多次计算功能
 * 4. 计算圆的面积和周长（输入半径）
 */
