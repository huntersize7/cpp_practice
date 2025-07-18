/*
 * C++ 学习计划 - 第2天：基本数据类型
 * 学习目标：
 * 1. 掌握C++的基本数据类型
 * 2. 学会变量的声明和初始化
 * 3. 理解常量的使用
 */

#include <iostream>
#include <string>
#include <windows.h>


int main() {
     SetConsoleOutputCP(CP_UTF8);
    std::cout << "=== C++ 基本数据类型学习 ===" << std::endl;
    
    // 1. 整数类型
    std::cout << "\n1. 整数类型：" << std::endl;
    int age = 20;                    // 整数
    short height = 175;              // 短整数
    long population = 1400000000;    // 长整数
    
    std::cout << "年龄: " << age << std::endl;
    std::cout << "身高: " << height << " cm" << std::endl;
    std::cout << "人口: " << population << std::endl;
    
    // 2. 浮点数类型
    std::cout << "\n2. 浮点数类型：" << std::endl;
    float score = 95.5f;             // 单精度浮点数
    double pi = 3.14159265359;       // 双精度浮点数
    
    std::cout << "分数: " << score << std::endl;
    std::cout << "圆周率: " << pi << std::endl;
    
    // 3. 字符类型
    std::cout << "\n3. 字符类型：" << std::endl;
    char grade = 'A';                // 字符
    char newline = '\n';             // 特殊字符
    
    std::cout << "等级: " << grade << std::endl;
    std::cout << "换行符后的内容" << newline;
    
    // 4. 布尔类型
    std::cout << "\n4. 布尔类型：" << std::endl;
    bool isStudent = true;           // 布尔值
    bool isWorking = false;
    
    std::cout << "是学生: " << isStudent << std::endl;  // 1表示true
    std::cout << "在工作: " << isWorking << std::endl; // 0表示false
    
    // 5. 字符串类型
    std::cout << "\n5. 字符串类型：" << std::endl;
    std::string name = "张三";        // C++字符串
    std::string hobby = "编程";
    
    std::cout << "姓名: " << name << std::endl;
    std::cout << "爱好: " << hobby << std::endl;
    
    // 6. 常量
    std::cout << "\n6. 常量：" << std::endl;
    const int MAX_SCORE = 100;       // 常量，不能修改
    const double GRAVITY = 9.8;
    
    std::cout << "最高分: " << MAX_SCORE << std::endl;
    std::cout << "重力加速度: " << GRAVITY << " m/s²" << std::endl;
    
    // 7. 变量大小
    std::cout << "\n7. 数据类型大小：" << std::endl;
    std::cout << "int 大小: " << sizeof(int) << " 字节" << std::endl;
    std::cout << "float 大小: " << sizeof(float) << " 字节" << std::endl;
    std::cout << "double 大小: " << sizeof(double) << " 字节" << std::endl;
    std::cout << "char 大小: " << sizeof(char) << " 字节" << std::endl;
    std::cout << "bool 大小: " << sizeof(bool) << " 字节" << std::endl;
    
    return 0;
}

/*
 * 练习任务：
 * 1. 运行程序，观察不同数据类型的输出
 * 2. 修改变量的值，重新编译运行
 * 3. 尝试声明自己的变量（姓名、年龄、身高、体重等）
 * 4. 计算并输出你的BMI指数（体重/身高²）
 * 
 * 编译命令：
 * g++ -o day02 day02_data_types.cpp
 * 
 * 扩展练习：
 * 1. 尝试给常量赋值，观察编译错误
 * 2. 研究不同整数类型的取值范围
 * 3. 比较float和double的精度差异
 */
