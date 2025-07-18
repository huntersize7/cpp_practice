/*
 * 第8天：函数基础学习与实践
 * 学习内容：函数的定义和声明、函数的调用、参数传递(值传递)、返回值
 * 练习任务：编写计算阶乘的函数、编写判断素数的函数
 */

#include <iostream>
#include <cmath>
using namespace std;

// 函数声明
void demonstrateFunctionBasics();
void demonstrateParameterPassing();
void demonstrateReturnValues();
long long calculateFactorial(int n);
bool isPrime(int n);
void practiceExercises();

// 一些示例函数
void greetUser();
void greetUserWithName(string name);
int add(int a, int b);
double add(double a, double b);
void printArray(int arr[], int size);
int findMax(int arr[], int size);

int main() {
    cout << "=== 第8天：函数基础学习与实践 ===" << endl;
    cout << "今天我们将学习：" << endl;
    cout << "1. 函数的定义和声明" << endl;
    cout << "2. 函数的调用" << endl;
    cout << "3. 参数传递" << endl;
    cout << "4. 返回值" << endl;
    cout << "5. 实际应用练习" << endl;
    cout << "================================" << endl << endl;

    // 1. 函数基础演示
    cout << "1. 函数基础演示：" << endl;
    demonstrateFunctionBasics();
    cout << endl;

    // 2. 参数传递演示
    cout << "2. 参数传递演示：" << endl;
    demonstrateParameterPassing();
    cout << endl;

    // 3. 返回值演示
    cout << "3. 返回值演示：" << endl;
    demonstrateReturnValues();
    cout << endl;

    // 4. 实际应用练习
    cout << "4. 实际应用练习：" << endl;
    
    // 练习1：阶乘函数
    cout << "练习1：阶乘计算" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << i << "! = " << calculateFactorial(i) << endl;
    }
    cout << endl;

    // 练习2：素数判断函数
    cout << "练习2：素数判断" << endl;
    cout << "1到50中的素数：";
    for (int i = 2; i <= 50; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl << endl;

    // 练习3：综合练习
    cout << "练习3：综合练习" << endl;
    practiceExercises();

    return 0;
}

// 函数基础演示
void demonstrateFunctionBasics() {
    cout << "基本函数调用：" << endl;
    
    // 无参数无返回值函数
    greetUser();
    
    // 有参数无返回值函数
    greetUserWithName("张三");
    greetUserWithName("李四");
    
    // 有参数有返回值函数
    int result1 = add(10, 20);
    cout << "整数加法：10 + 20 = " << result1 << endl;
    
    double result2 = add(3.14, 2.86);
    cout << "浮点数加法：3.14 + 2.86 = " << result2 << endl;
    
    // 数组作为参数
    int numbers[] = {5, 2, 8, 1, 9, 3};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    cout << "原数组：";
    printArray(numbers, size);
    
    int maxValue = findMax(numbers, size);
    cout << "数组中的最大值：" << maxValue << endl;
}

// 参数传递演示
void demonstrateParameterPassing() {
    cout << "值传递演示：" << endl;
    
    int original = 100;
    cout << "调用前 original = " << original << endl;
    
    // 演示值传递
    auto modifyValue = [](int x) {
        cout << "函数内部：x = " << x << endl;
        x = 200;
        cout << "函数内部修改后：x = " << x << endl;
    };
    
    modifyValue(original);
    cout << "调用后 original = " << original << " (值没有改变)" << endl;
    
    // 数组参数传递（实际上是指针）
    cout << "\n数组参数传递：" << endl;
    int arr[] = {1, 2, 3, 4, 5};
    int arrSize = 5;
    
    cout << "修改前数组：";
    printArray(arr, arrSize);
    
    auto modifyArray = [](int array[], int size) {
        for (int i = 0; i < size; i++) {
            array[i] *= 2;
        }
    };
    
    modifyArray(arr, arrSize);
    cout << "修改后数组：";
    printArray(arr, arrSize);
    cout << "数组内容被修改了！" << endl;
}

// 返回值演示
void demonstrateReturnValues() {
    cout << "不同类型的返回值：" << endl;
    
    // 返回整数
    auto square = [](int x) -> int {
        return x * x;
    };
    cout << "5的平方：" << square(5) << endl;
    
    // 返回浮点数
    auto circleArea = [](double radius) -> double {
        return 3.14159 * radius * radius;
    };
    cout << "半径为3的圆面积：" << circleArea(3.0) << endl;
    
    // 返回布尔值
    auto isEven = [](int n) -> bool {
        return n % 2 == 0;
    };
    cout << "8是偶数吗？" << (isEven(8) ? "是" : "否") << endl;
    cout << "7是偶数吗？" << (isEven(7) ? "是" : "否") << endl;
    
    // 返回字符串
    auto getGrade = [](int score) -> string {
        if (score >= 90) return "优秀";
        else if (score >= 80) return "良好";
        else if (score >= 70) return "中等";
        else if (score >= 60) return "及格";
        else return "不及格";
    };
    cout << "85分的等级：" << getGrade(85) << endl;
    
    // 多个返回点
    auto absoluteValue = [](int x) -> int {
        if (x >= 0) {
            return x;
        } else {
            return -x;
        }
    };
    cout << "-15的绝对值：" << absoluteValue(-15) << endl;
}

// 练习1：计算阶乘的函数
long long calculateFactorial(int n) {
    if (n < 0) {
        cout << "错误：负数没有阶乘" << endl;
        return -1;
    }
    
    if (n == 0 || n == 1) {
        return 1;
    }
    
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    
    return result;
}

// 练习2：判断素数的函数
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    
    if (n <= 3) {
        return true;
    }
    
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    
    // 只需要检查到sqrt(n)
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    
    return true;
}

// 综合练习
void practiceExercises() {
    // 练习1：数学函数库
    cout << "练习1：数学函数库" << endl;
    
    auto power = [](double base, int exponent) -> double {
        double result = 1.0;
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
        return result;
    };
    
    auto gcd = [](int a, int b) -> int {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    };
    
    auto lcm = [&gcd](int a, int b) -> int {
        return (a * b) / gcd(a, b);
    };
    
    cout << "2的8次方：" << power(2, 8) << endl;
    cout << "12和18的最大公约数：" << gcd(12, 18) << endl;
    cout << "12和18的最小公倍数：" << lcm(12, 18) << endl;
    
    // 练习2：字符串处理函数
    cout << "\n练习2：字符串处理函数" << endl;
    
    auto countVowels = [](const string& str) -> int {
        int count = 0;
        string vowels = "aeiouAEIOU";
        for (char c : str) {
            if (vowels.find(c) != string::npos) {
                count++;
            }
        }
        return count;
    };
    
    auto reverseString = [](string str) -> string {
        int len = str.length();
        for (int i = 0; i < len / 2; i++) {
            swap(str[i], str[len - 1 - i]);
        }
        return str;
    };
    
    string testStr = "Hello World";
    cout << "字符串 \"" << testStr << "\" 中的元音字母个数：" << countVowels(testStr) << endl;
    cout << "反转后：\"" << reverseString(testStr) << "\"" << endl;
    
    // 练习3：数组处理函数
    cout << "\n练习3：数组处理函数" << endl;
    
    auto arraySum = [](int arr[], int size) -> int {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return sum;
    };
    
    auto arrayAverage = [&arraySum](int arr[], int size) -> double {
        return (double)arraySum(arr, size) / size;
    };
    
    auto findSecondMax = [](int arr[], int size) -> int {
        if (size < 2) return -1;
        
        int max1 = arr[0], max2 = -1;
        for (int i = 1; i < size; i++) {
            if (arr[i] > max1) {
                max2 = max1;
                max1 = arr[i];
            } else if (arr[i] > max2 && arr[i] != max1) {
                max2 = arr[i];
            }
        }
        return max2;
    };
    
    int testArray[] = {64, 34, 25, 12, 22, 11, 90, 88};
    int testSize = sizeof(testArray) / sizeof(testArray[0]);
    
    cout << "测试数组：";
    printArray(testArray, testSize);
    cout << "数组总和：" << arraySum(testArray, testSize) << endl;
    cout << "数组平均值：" << arrayAverage(testArray, testSize) << endl;
    cout << "第二大的数：" << findSecondMax(testArray, testSize) << endl;
}

// 辅助函数实现
void greetUser() {
    cout << "你好！欢迎学习C++函数！" << endl;
}

void greetUserWithName(string name) {
    cout << "你好，" << name << "！" << endl;
}

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

/*
 * 学习要点总结：
 * 
 * 1. 函数定义：
 *    - 语法：返回类型 函数名(参数列表) { 函数体 }
 *    - 函数声明：在使用前声明函数原型
 * 
 * 2. 参数传递：
 *    - 值传递：传递参数的副本
 *    - 数组参数：实际传递的是指针
 * 
 * 3. 返回值：
 *    - 可以返回各种数据类型
 *    - void表示无返回值
 *    - return语句结束函数执行
 * 
 * 4. 函数重载：
 *    - 同名函数，不同参数
 *    - 编译器根据参数选择合适的函数
 * 
 * 5. 实践技巧：
 *    - 函数应该只做一件事
 *    - 使用有意义的函数名
 *    - 合理使用参数和返回值
 *    - 注意函数的作用域
 */
