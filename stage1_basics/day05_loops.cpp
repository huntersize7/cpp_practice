/*
 * 第5天：循环语句学习与实践
 * 学习内容：for循环、while循环、do-while循环、break和continue语句
 * 练习任务：九九乘法表、计算1到100的和
 */

#include <iostream>
#include <iomanip>
using namespace std;

// 函数声明
void demonstrateForLoop();
void demonstrateWhileLoop();
void demonstrateDoWhileLoop();
void demonstrateBreakContinue();
void multiplicationTable();
void calculateSum();
void practiceExercises();

int main() {
    cout << "=== 第5天：循环语句学习与实践 ===" << endl;
    cout << "今天我们将学习：" << endl;
    cout << "1. for循环" << endl;
    cout << "2. while循环" << endl;
    cout << "3. do-while循环" << endl;
    cout << "4. break和continue语句" << endl;
    cout << "5. 实际应用练习" << endl;
    cout << "================================" << endl << endl;

    // 1. for循环演示
    cout << "1. for循环演示：" << endl;
    demonstrateForLoop();
    cout << endl;

    // 2. while循环演示
    cout << "2. while循环演示：" << endl;
    demonstrateWhileLoop();
    cout << endl;

    // 3. do-while循环演示
    cout << "3. do-while循环演示：" << endl;
    demonstrateDoWhileLoop();
    cout << endl;

    // 4. break和continue演示
    cout << "4. break和continue语句演示：" << endl;
    demonstrateBreakContinue();
    cout << endl;

    // 5. 实际应用练习
    cout << "5. 实际应用练习：" << endl;
    
    // 练习1：九九乘法表
    cout << "练习1：九九乘法表" << endl;
    multiplicationTable();
    cout << endl;

    // 练习2：计算1到100的和
    cout << "练习2：计算1到100的和" << endl;
    calculateSum();
    cout << endl;

    // 练习3：更多练习
    cout << "练习3：综合练习" << endl;
    practiceExercises();

    return 0;
}

// for循环演示
void demonstrateForLoop() {
    // 基本for循环
    cout << "基本for循环 - 输出1到5：";
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl;

    // 倒序for循环
    cout << "倒序for循环 - 输出5到1：";
    for (int i = 5; i >= 1; i--) {
        cout << i << " ";
    }
    cout << endl;

    // 步长为2的for循环
    cout << "步长为2的for循环 - 输出1到10的奇数：";
    for (int i = 1; i <= 10; i += 2) {
        cout << i << " ";
    }
    cout << endl;

    // 嵌套for循环 - 打印矩形
    cout << "嵌套for循环 - 打印3x4的星号矩形：" << endl;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 4; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    // for循环计算阶乘
    int n = 5;
    long factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    cout << n << "! = " << factorial << endl;
}

// while循环演示
void demonstrateWhileLoop() {
    // 基本while循环
    cout << "基本while循环 - 输出1到5：";
    int i = 1;
    while (i <= 5) {
        cout << i << " ";
        i++;
    }
    cout << endl;

    // while循环求和
    cout << "while循环计算1到10的和：";
    int sum = 0;
    int num = 1;
    while (num <= 10) {
        sum += num;
        num++;
    }
    cout << sum << endl;

    // while循环处理用户输入
    cout << "while循环处理输入（输入0结束）：" << endl;
    int input;
    int total = 0;
    int count = 0;
    cout << "请输入数字（输入0结束）：";
    while (cin >> input && input != 0) {
        total += input;
        count++;
        cout << "请输入下一个数字（输入0结束）：";
    }
    if (count > 0) {
        cout << "输入了 " << count << " 个数字，总和为：" << total << endl;
        cout << "平均值为：" << (double)total / count << endl;
    }
}

// do-while循环演示
void demonstrateDoWhileLoop() {
    // 基本do-while循环
    cout << "基本do-while循环 - 输出1到5：";
    int i = 1;
    do {
        cout << i << " ";
        i++;
    } while (i <= 5);
    cout << endl;

    // do-while与while的区别演示
    cout << "do-while与while的区别：" << endl;
    
    // while循环 - 条件不满足时不执行
    cout << "while循环（i=10, 条件i<=5）：";
    i = 10;
    while (i <= 5) {
        cout << i << " ";
        i++;
    }
    cout << "（没有输出）" << endl;

    // do-while循环 - 至少执行一次
    cout << "do-while循环（i=10, 条件i<=5）：";
    i = 10;
    do {
        cout << i << " ";
        i++;
    } while (i <= 5);
    cout << "（至少执行一次）" << endl;

    // do-while用于菜单系统
    cout << "do-while用于简单菜单：" << endl;
    char choice;
    do {
        cout << "选择操作：(a)加法 (s)减法 (q)退出：";
        cin >> choice;
        switch (choice) {
            case 'a':
                cout << "执行加法操作" << endl;
                break;
            case 's':
                cout << "执行减法操作" << endl;
                break;
            case 'q':
                cout << "退出程序" << endl;
                break;
            default:
                cout << "无效选择" << endl;
                break;
        }
    } while (choice != 'q');
}

// break和continue演示
void demonstrateBreakContinue() {
    // break语句演示
    cout << "break语句演示 - 找到第一个大于15的平方数：" << endl;
    for (int i = 1; i <= 10; i++) {
        int square = i * i;
        cout << i << "² = " << square;
        if (square > 15) {
            cout << " （找到了！退出循环）" << endl;
            break;
        }
        cout << endl;
    }

    // continue语句演示
    cout << "continue语句演示 - 输出1到10中的奇数：";
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue; // 跳过偶数
        }
        cout << i << " ";
    }
    cout << endl;

    // 嵌套循环中的break和continue
    cout << "嵌套循环中的break和continue：" << endl;
    for (int i = 1; i <= 3; i++) {
        cout << "外层循环 i = " << i << "：";
        for (int j = 1; j <= 5; j++) {
            if (j == 3) {
                continue; // 跳过j=3
            }
            if (j == 5 && i == 2) {
                break; // 当i=2且j=5时退出内层循环
            }
            cout << j << " ";
        }
        cout << endl;
    }
}

// 练习1：九九乘法表
void multiplicationTable() {
    cout << "完整的九九乘法表：" << endl;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << "×" << i << "=" << setw(2) << (i * j) << " ";
        }
        cout << endl;
    }

    cout << "\n表格形式的九九乘法表：" << endl;
    cout << "   ";
    for (int j = 1; j <= 9; j++) {
        cout << setw(4) << j;
    }
    cout << endl;
    
    for (int i = 1; i <= 9; i++) {
        cout << setw(2) << i << " ";
        for (int j = 1; j <= 9; j++) {
            cout << setw(4) << (i * j);
        }
        cout << endl;
    }
}

// 练习2：计算1到100的和
void calculateSum() {
    // 方法1：使用for循环
    int sum1 = 0;
    for (int i = 1; i <= 100; i++) {
        sum1 += i;
    }
    cout << "方法1 (for循环)：1到100的和 = " << sum1 << endl;

    // 方法2：使用while循环
    int sum2 = 0;
    int i = 1;
    while (i <= 100) {
        sum2 += i;
        i++;
    }
    cout << "方法2 (while循环)：1到100的和 = " << sum2 << endl;

    // 方法3：数学公式验证
    int sum3 = 100 * 101 / 2;
    cout << "方法3 (数学公式)：1到100的和 = " << sum3 << endl;

    // 扩展：计算1到100中偶数的和
    int evenSum = 0;
    for (int i = 2; i <= 100; i += 2) {
        evenSum += i;
    }
    cout << "扩展：1到100中偶数的和 = " << evenSum << endl;

    // 扩展：计算1到100中奇数的和
    int oddSum = 0;
    for (int i = 1; i <= 100; i += 2) {
        oddSum += i;
    }
    cout << "扩展：1到100中奇数的和 = " << oddSum << endl;
}

// 练习3：综合练习
void practiceExercises() {
    // 练习1：打印数字金字塔
    cout << "练习1：数字金字塔" << endl;
    int rows = 5;
    for (int i = 1; i <= rows; i++) {
        // 打印空格
        for (int j = 1; j <= rows - i; j++) {
            cout << " ";
        }
        // 打印数字
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }

    // 练习2：找出1到100中的所有素数
    cout << "\n练习2：1到100中的素数：" << endl;
    int primeCount = 0;
    for (int num = 2; num <= 100; num++) {
        bool isPrime = true;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cout << setw(3) << num << " ";
            primeCount++;
            if (primeCount % 10 == 0) {
                cout << endl;
            }
        }
    }
    cout << "\n共找到 " << primeCount << " 个素数" << endl;

    // 练习3：猜数字游戏
    cout << "\n练习3：简单的猜数字游戏" << endl;
    int secretNumber = 42; // 预设的数字
    int guess;
    int attempts = 0;
    const int maxAttempts = 5;

    cout << "我想了一个1到100之间的数字，你有" << maxAttempts << "次机会猜中它！" << endl;
    
    do {
        cout << "请输入你的猜测：";
        cin >> guess;
        attempts++;

        if (guess == secretNumber) {
            cout << "恭喜！你猜对了！用了" << attempts << "次尝试。" << endl;
            break;
        } else if (guess < secretNumber) {
            cout << "太小了！";
        } else {
            cout << "太大了！";
        }

        if (attempts < maxAttempts) {
            cout << "还有" << (maxAttempts - attempts) << "次机会。" << endl;
        }

    } while (attempts < maxAttempts);

    if (guess != secretNumber) {
        cout << "很遗憾，你没有猜中。正确答案是：" << secretNumber << endl;
    }
}

/*
 * 学习要点总结：
 * 
 * 1. for循环：
 *    - 语法：for (初始化; 条件; 更新) { 语句 }
 *    - 适用于已知循环次数的情况
 *    - 可以嵌套使用
 * 
 * 2. while循环：
 *    - 语法：while (条件) { 语句 }
 *    - 先判断条件再执行
 *    - 适用于未知循环次数的情况
 * 
 * 3. do-while循环：
 *    - 语法：do { 语句 } while (条件);
 *    - 先执行再判断条件
 *    - 至少执行一次
 * 
 * 4. break和continue：
 *    - break：跳出整个循环
 *    - continue：跳过当前迭代，继续下一次
 * 
 * 5. 实践技巧：
 *    - 选择合适的循环类型
 *    - 注意循环条件和边界
 *    - 避免无限循环
 *    - 合理使用break和continue
 */
