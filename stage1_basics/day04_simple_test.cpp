/*
 * 第4天：条件语句简化测试版本
 * 避免复杂的输入处理，专注于学习条件语句
 */

#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    // 设置控制台编码为UTF-8，解决中文乱码问题
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    
    cout << "=== 第4天：条件语句学习与实践（简化版） ===" << endl;
    cout << "今天我们将学习条件语句的基本用法" << endl;
    cout << "=======================================" << endl << endl;

    // 1. if-else语句演示
    cout << "1. if-else语句演示：" << endl;
    int score = 85;
    cout << "学生成绩：" << score << endl;
    
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
    cout << endl;

    // 2. switch-case语句演示
    cout << "2. switch-case语句演示：" << endl;
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
    cout << endl;

    // 3. 三元运算符演示
    cout << "3. 三元运算符演示：" << endl;
    int a = 10, b = 20;
    int max = (a > b) ? a : b;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "较大的数是：" << max << endl;
    cout << endl;

    // 4. 奇偶数判断
    cout << "4. 奇偶数判断：" << endl;
    int number = 42;
    cout << "数字 " << number << " 是";
    if (number % 2 == 0) {
        cout << "偶数" << endl;
    } else {
        cout << "奇数" << endl;
    }
    
    // 使用三元运算符的版本
    cout << "使用三元运算符：" << number << " 是" << ((number % 2 == 0) ? "偶数" : "奇数") << endl;
    cout << endl;

    // 5. 简单的菜单选择演示
    cout << "5. 菜单选择演示：" << endl;
    int choice = 2; // 模拟用户选择
    cout << "用户选择了选项：" << choice << endl;
    
    switch (choice) {
        case 1:
            cout << "执行加法运算" << endl;
            cout << "10 + 5 = " << (10 + 5) << endl;
            break;
        case 2:
            cout << "执行减法运算" << endl;
            cout << "10 - 5 = " << (10 - 5) << endl;
            break;
        case 3:
            cout << "执行乘法运算" << endl;
            cout << "10 × 5 = " << (10 * 5) << endl;
            break;
        case 4:
            cout << "执行除法运算" << endl;
            cout << "10 ÷ 5 = " << (10 / 5) << endl;
            break;
        default:
            cout << "无效选择" << endl;
            break;
    }
    cout << endl;

    // 6. 综合示例：成绩等级判断
    cout << "6. 综合示例：多个学生成绩等级判断" << endl;
    int scores[] = {95, 87, 76, 65, 45};
    string names[] = {"张三", "李四", "王五", "赵六", "钱七"};
    
    for (int i = 0; i < 5; i++) {
        cout << names[i] << "的成绩：" << scores[i] << "分，等级：";
        
        if (scores[i] >= 90) {
            cout << "优秀";
        } else if (scores[i] >= 80) {
            cout << "良好";
        } else if (scores[i] >= 70) {
            cout << "中等";
        } else if (scores[i] >= 60) {
            cout << "及格";
        } else {
            cout << "不及格";
        }
        cout << endl;
    }
    cout << endl;

    cout << "=== 条件语句学习完成！===" << endl;
    cout << "主要学习内容：" << endl;
    cout << "1. if-else 条件判断" << endl;
    cout << "2. switch-case 多分支选择" << endl;
    cout << "3. 三元运算符 ? :" << endl;
    cout << "4. 条件语句的实际应用" << endl;
    
    return 0;
}

/*
 * 学习要点总结：
 * 
 * 1. if-else语句：
 *    - 基本语法：if (条件) { 语句 }
 *    - 多重条件：if-else if-else
 *    - 适用于范围判断
 * 
 * 2. switch-case语句：
 *    - 适用于多个固定值的判断
 *    - 必须使用break防止穿透
 *    - default处理其他情况
 * 
 * 3. 三元运算符：
 *    - 语法：条件 ? 值1 : 值2
 *    - 简洁的条件表达式
 *    - 适用于简单的二选一情况
 * 
 * 4. 实践技巧：
 *    - 合理选择条件语句类型
 *    - 注意条件的逻辑顺序
 *    - 处理边界情况
 */
