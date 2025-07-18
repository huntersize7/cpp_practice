/*
 * 第4天：条件语句学习与实践
 * 学习内容：if-else语句、switch-case语句、三元运算符
 * 练习任务：奇偶数判断程序、菜单选择程序
 */

#include <iostream>
#include <windows.h>
using namespace std;

// 函数声明
void demonstrateIfElse();
void demonstrateSwitchCase();
void demonstrateTernaryOperator();
void oddEvenChecker();
void menuSystem();

int main() {
    // 设置控制台编码为UTF-8，解决中文乱码问题
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    cout << "=== 第4天：条件语句学习与实践 ===" << endl;
    cout << "今天我们将学习：" << endl;
    cout << "1. if-else语句" << endl;
    cout << "2. switch-case语句" << endl;
    cout << "3. 三元运算符" << endl;
    cout << "4. 实际应用练习" << endl;
    cout << "================================" << endl << endl;

    // 1. if-else语句演示
    cout << "1. if-else语句演示：" << endl;
    demonstrateIfElse();
    cout << endl;

    // 2. switch-case语句演示
    cout << "2. switch-case语句演示：" << endl;
    demonstrateSwitchCase();
    cout << endl;

    // 3. 三元运算符演示
    cout << "3. 三元运算符演示：" << endl;
    demonstrateTernaryOperator();
    cout << endl;

    // 4. 实际应用练习
    cout << "4. 实际应用练习：" << endl;
    
    // 练习1：奇偶数判断
    cout << "练习1：奇偶数判断程序" << endl;
    oddEvenChecker();
    cout << endl;

    // 练习2：菜单系统
    cout << "练习2：菜单选择程序" << endl;
    menuSystem();

    return 0;
}

// if-else语句演示
void demonstrateIfElse() {
    int score = 85;
    
    cout << "学生成绩：" << score << endl;
    
    // 简单if语句
    if (score >= 60) {
        cout << "恭喜！你及格了！" << endl;
    }
    
    // if-else语句
    if (score >= 90) {
        cout << "等级：优秀" << endl;
    } else if (score >= 80) {
        cout << "等级：良好" << endl;
    } else if (score >= 70) {
        cout << "等级：中等" << endl;
    } else if (score >= 60) {
        cout << "等级：及格" << endl;
    } else {
        cout << "等级：不及格" << endl;
    }
    
    // 嵌套if语句
    if (score >= 60) {
        cout << "通过考试！";
        if (score >= 90) {
            cout << " 并且获得奖学金！" << endl;
        } else {
            cout << endl;
        }
    }
}

// switch-case语句演示
void demonstrateSwitchCase() {
    int dayOfWeek = 3;
    
    cout << "今天是星期：";
    switch (dayOfWeek) {
        case 1:
            cout << "一" << endl;
            break;
        case 2:
            cout << "二" << endl;
            break;
        case 3:
            cout << "三" << endl;
            break;
        case 4:
            cout << "四" << endl;
            break;
        case 5:
            cout << "五" << endl;
            break;
        case 6:
            cout << "六" << endl;
            break;
        case 7:
            cout << "日" << endl;
            break;
        default:
            cout << "无效的日期" << endl;
            break;
    }
    
    // 字符switch示例
    char grade = 'B';
    cout << "成绩等级 " << grade << " 对应：";
    switch (grade) {
        case 'A':
        case 'a':
            cout << "优秀 (90-100分)" << endl;
            break;
        case 'B':
        case 'b':
            cout << "良好 (80-89分)" << endl;
            break;
        case 'C':
        case 'c':
            cout << "中等 (70-79分)" << endl;
            break;
        case 'D':
        case 'd':
            cout << "及格 (60-69分)" << endl;
            break;
        case 'F':
        case 'f':
            cout << "不及格 (0-59分)" << endl;
            break;
        default:
            cout << "无效等级" << endl;
            break;
    }
}

// 三元运算符演示
void demonstrateTernaryOperator() {
    int a = 10, b = 20;
    
    // 基本三元运算符
    int max = (a > b) ? a : b;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "较大的数是：" << max << endl;
    
    // 三元运算符用于字符串
    string result = (a > b) ? "a更大" : "b更大";
    cout << "比较结果：" << result << endl;
    
    // 嵌套三元运算符（不推荐过度使用）
    int c = 15;
    int maxOfThree = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    cout << "三个数中最大的是：" << maxOfThree << endl;
    
    // 三元运算符用于输出
    cout << "数字 " << a << " 是" << ((a % 2 == 0) ? "偶数" : "奇数") << endl;
}

// 练习1：奇偶数判断程序
void oddEvenChecker() {
    int number;
    
    cout << "请输入一个整数：";
    cin >> number;
    
    // 方法1：使用if-else
    cout << "方法1 (if-else)：";
    if (number % 2 == 0) {
        cout << number << " 是偶数" << endl;
    } else {
        cout << number << " 是奇数" << endl;
    }
    
    // 方法2：使用三元运算符
    cout << "方法2 (三元运算符)：";
    cout << number << " 是" << ((number % 2 == 0) ? "偶数" : "奇数") << endl;
    
    // 扩展：判断正负性
    cout << "扩展判断：";
    if (number > 0) {
        cout << number << " 是正数";
    } else if (number < 0) {
        cout << number << " 是负数";
    } else {
        cout << number << " 是零";
    }
    
    if (number != 0) {
        cout << "，并且是" << ((number % 2 == 0) ? "偶数" : "奇数") << endl;
    } else {
        cout << endl;
    }
}

// 练习2：菜单选择程序
void menuSystem() {
    int choice;

    cout << "\n=== 简单计算器菜单 ===" << endl;
    cout << "1. 加法运算" << endl;
    cout << "2. 减法运算" << endl;
    cout << "3. 乘法运算" << endl;
    cout << "4. 除法运算" << endl;
    cout << "5. 判断奇偶数" << endl;
    cout << "6. 比较两个数大小" << endl;
    cout << "请选择操作 (1-6)：";

    cin >> choice;
        
    switch (choice) {
        case 1: {
            double num1, num2;
            cout << "请输入两个数：";
            cin >> num1 >> num2;
            cout << "结果：" << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
            break;
        }
        case 2: {
            double num1, num2;
            cout << "请输入两个数：";
            cin >> num1 >> num2;
            cout << "结果：" << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
            break;
        }
        case 3: {
            double num1, num2;
            cout << "请输入两个数：";
            cin >> num1 >> num2;
            cout << "结果：" << num1 << " × " << num2 << " = " << (num1 * num2) << endl;
            break;
        }
        case 4: {
            double num1, num2;
            cout << "请输入两个数：";
            cin >> num1 >> num2;
            if (num2 != 0) {
                cout << "结果：" << num1 << " ÷ " << num2 << " = " << (num1 / num2) << endl;
            } else {
                cout << "错误：除数不能为零！" << endl;
            }
            break;
        }
        case 5: {
            int num;
            cout << "请输入一个整数：";
            cin >> num;
            cout << num << " 是" << ((num % 2 == 0) ? "偶数" : "奇数") << endl;
            break;
        }
        case 6: {
            double num1, num2;
            cout << "请输入两个数：";
            cin >> num1 >> num2;
            if (num1 > num2) {
                cout << num1 << " 大于 " << num2 << endl;
            } else if (num1 < num2) {
                cout << num1 << " 小于 " << num2 << endl;
            } else {
                cout << num1 << " 等于 " << num2 << endl;
            }
            break;
        }
        default:
            cout << "无效选择！请输入1-6之间的数字。" << endl;
            break;
    }

    cout << "\n菜单演示完成！" << endl;
}

/*
 * 学习要点总结：
 * 
 * 1. if-else语句：
 *    - 基本语法：if (条件) { 语句 }
 *    - 多重条件：if-else if-else
 *    - 嵌套if语句
 * 
 * 2. switch-case语句：
 *    - 适用于多个固定值的判断
 *    - 必须使用break防止穿透
 *    - default处理其他情况
 * 
 * 3. 三元运算符：
 *    - 语法：条件 ? 值1 : 值2
 *    - 简洁的条件表达式
 *    - 不要过度嵌套
 * 
 * 4. 实践技巧：
 *    - 合理选择条件语句类型
 *    - 注意边界条件处理
 *    - 添加错误检查和用户友好提示
 */
