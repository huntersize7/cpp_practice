/*
 * C++ 学习计划 - 第1天：环境搭建与Hello World
 * 学习目标：
 * 1. 理解C++程序的基本结构
 * 2. 掌握基本的输出语句
 * 3. 学会编译和运行C++程序
 */

#include <iostream>  // 包含输入输出流库

int main() {
    // 这是你的第一个C++程序！
    std::cout << "Hello, C++ World!" << std::endl;
    
    // 练习1：输出你的姓名
    std::cout << "我的名字是：[请在这里填入你的姓名]" << std::endl;
    
    // 练习2：输出多行信息
    std::cout << "欢迎来到C++编程世界！" << std::endl;
    std::cout << "今天是我学习C++的第一天。" << std::endl;
    std::cout << "我会坚持每天练习编程。" << std::endl;
    
    // 练习3：使用不同的输出方式
    std::cout << "这是第一行\n";  // 使用\n换行
    std::cout << "这是第二行" << std::endl;  // 使用endl换行
    
    // 练习4：输出一些特殊字符
    std::cout << "引号：\"Hello\"" << std::endl;
    std::cout << "反斜杠：\\" << std::endl;
    std::cout << "制表符：\t制表符后的内容" << std::endl;
    
    return 0;  // 程序正常结束
}

/*
 * 编译和运行说明：
 * 
 * 方法1：使用g++编译器
 * 1. 打开命令行/终端
 * 2. 导航到文件所在目录
 * 3. 输入：g++ -o day01 day01_hello_world.cpp
 * 4. 运行：./day01 (Linux/Mac) 或 day01.exe (Windows)
 * 
 * 方法2：使用VS Code
 * 1. 安装C/C++扩展
 * 2. 按F5运行程序
 * 
 * 今天的作业：
 * 1. 成功编译并运行这个程序
 * 2. 修改程序，输出你的个人信息（姓名、年龄、爱好等）
 * 3. 尝试输出一个简单的ASCII艺术图案
 * 4. 实验不同的换行方式和特殊字符
 */
