/*
 * 第9天：函数重载与默认参数
 * 学习内容：函数重载的概念和使用、默认参数的设置、函数模板简介
 * 练习任务：重载计算面积的函数(圆形、矩形、三角形)、使用默认参数简化函数调用
 */

#include <iostream>
#include <cmath>
using namespace std;

// 函数声明
void demonstrateFunctionOverloading();
void demonstrateDefaultParameters();
void demonstrateFunctionTemplates();
void areaCalculationPractice();
void practiceExercises();

// 函数重载示例 - 计算面积
double calculateArea(double radius);                    // 圆形面积
double calculateArea(double length, double width);      // 矩形面积
double calculateArea(double a, double b, double c);     // 三角形面积（海伦公式）

// 默认参数示例
void printMessage(string message, int times = 1, char separator = '-');
double calculatePower(double base, int exponent = 2);
void displayInfo(string name, int age = 0, string city = "未知");

// 函数模板示例
template<typename T>
T getMax(T a, T b);

template<typename T>
void swapValues(T& a, T& b);

int main() {
    cout << "=== 第9天：函数重载与默认参数 ===" << endl;
    cout << "今天我们将学习：" << endl;
    cout << "1. 函数重载的概念和使用" << endl;
    cout << "2. 默认参数的设置" << endl;
    cout << "3. 函数模板简介" << endl;
    cout << "4. 实际应用练习" << endl;
    cout << "================================" << endl << endl;

    // 1. 函数重载演示
    cout << "1. 函数重载演示：" << endl;
    demonstrateFunctionOverloading();
    cout << endl;

    // 2. 默认参数演示
    cout << "2. 默认参数演示：" << endl;
    demonstrateDefaultParameters();
    cout << endl;

    // 3. 函数模板演示
    cout << "3. 函数模板演示：" << endl;
    demonstrateFunctionTemplates();
    cout << endl;

    // 4. 实际应用练习
    cout << "4. 实际应用练习：" << endl;
    
    // 练习1：面积计算
    cout << "练习1：面积计算函数重载" << endl;
    areaCalculationPractice();
    cout << endl;

    // 练习2：综合练习
    cout << "练习2：综合练习" << endl;
    practiceExercises();

    return 0;
}

// 函数重载演示
void demonstrateFunctionOverloading() {
    cout << "函数重载基础：" << endl;
    
    // 重载的print函数
    auto print = [](int x) { cout << "整数：" << x << endl; };
    auto printDouble = [](double x) { cout << "浮点数：" << x << endl; };
    auto printString = [](const string& x) { cout << "字符串：" << x << endl; };
    
    // 由于lambda不能重载，我们用普通函数演示
    cout << "不同类型的输出：" << endl;
    
    // 整数版本
    auto displayValue = [](int value) {
        cout << "显示整数：" << value << endl;
    };
    displayValue(42);
    
    // 浮点数版本
    auto displayValueDouble = [](double value) {
        cout << "显示浮点数：" << value << endl;
    };
    displayValueDouble(3.14);
    
    // 字符串版本
    auto displayValueString = [](const string& value) {
        cout << "显示字符串：" << value << endl;
    };
    displayValueString("Hello World");
    
    // 数学运算重载示例
    auto add = [](int a, int b) -> int {
        cout << "整数加法：";
        return a + b;
    };
    
    auto addDouble = [](double a, double b) -> double {
        cout << "浮点数加法：";
        return a + b;
    };
    
    auto addThree = [](int a, int b, int c) -> int {
        cout << "三个整数加法：";
        return a + b + c;
    };
    
    cout << add(10, 20) << endl;
    cout << addDouble(3.14, 2.86) << endl;
    cout << addThree(1, 2, 3) << endl;
}

// 默认参数演示
void demonstrateDefaultParameters() {
    cout << "默认参数使用：" << endl;
    
    // 使用默认参数的消息打印
    printMessage("欢迎学习C++");
    printMessage("重要提醒", 3);
    printMessage("分隔线", 5, '=');
    
    // 使用默认参数的幂运算
    cout << "2的默认次方（平方）：" << calculatePower(2) << endl;
    cout << "2的3次方：" << calculatePower(2, 3) << endl;
    cout << "5的4次方：" << calculatePower(5, 4) << endl;
    
    // 使用默认参数的信息显示
    displayInfo("张三");
    displayInfo("李四", 25);
    displayInfo("王五", 30, "北京");
}

// 函数模板演示
void demonstrateFunctionTemplates() {
    cout << "函数模板使用：" << endl;
    
    // 比较不同类型的最大值
    cout << "整数最大值：" << getMax(10, 20) << endl;
    cout << "浮点数最大值：" << getMax(3.14, 2.86) << endl;
    cout << "字符最大值：" << getMax('A', 'Z') << endl;
    cout << "字符串最大值：" << getMax(string("apple"), string("banana")) << endl;
    
    // 交换不同类型的值
    int a = 100, b = 200;
    cout << "交换前：a = " << a << ", b = " << b << endl;
    swapValues(a, b);
    cout << "交换后：a = " << a << ", b = " << b << endl;
    
    double x = 1.5, y = 2.5;
    cout << "交换前：x = " << x << ", y = " << y << endl;
    swapValues(x, y);
    cout << "交换后：x = " << x << ", y = " << y << endl;
    
    string s1 = "Hello", s2 = "World";
    cout << "交换前：s1 = " << s1 << ", s2 = " << s2 << endl;
    swapValues(s1, s2);
    cout << "交换后：s1 = " << s1 << ", s2 = " << s2 << endl;
}

// 练习1：面积计算函数重载
void areaCalculationPractice() {
    cout << "各种图形面积计算：" << endl;
    
    // 圆形面积
    double radius = 5.0;
    double circleArea = calculateArea(radius);
    cout << "半径为 " << radius << " 的圆形面积：" << circleArea << endl;
    
    // 矩形面积
    double length = 8.0, width = 6.0;
    double rectangleArea = calculateArea(length, width);
    cout << "长 " << length << "，宽 " << width << " 的矩形面积：" << rectangleArea << endl;
    
    // 三角形面积
    double a = 3.0, b = 4.0, c = 5.0;
    double triangleArea = calculateArea(a, b, c);
    cout << "边长为 " << a << ", " << b << ", " << c << " 的三角形面积：" << triangleArea << endl;
    
    // 用户交互计算
    cout << "\n交互式面积计算：" << endl;
    int choice;
    cout << "选择图形：1-圆形 2-矩形 3-三角形：";
    cin >> choice;
    
    switch (choice) {
        case 1: {
            double r;
            cout << "请输入圆的半径：";
            cin >> r;
            cout << "圆形面积：" << calculateArea(r) << endl;
            break;
        }
        case 2: {
            double l, w;
            cout << "请输入矩形的长和宽：";
            cin >> l >> w;
            cout << "矩形面积：" << calculateArea(l, w) << endl;
            break;
        }
        case 3: {
            double side1, side2, side3;
            cout << "请输入三角形的三边长：";
            cin >> side1 >> side2 >> side3;
            cout << "三角形面积：" << calculateArea(side1, side2, side3) << endl;
            break;
        }
        default:
            cout << "无效选择！" << endl;
            break;
    }
}

// 综合练习
void practiceExercises() {
    // 练习1：重载的数学函数
    cout << "练习1：重载的数学函数" << endl;
    
    auto distance = [](double x1, double y1, double x2, double y2) -> double {
        return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    };
    
    auto distance3D = [](double x1, double y1, double z1, double x2, double y2, double z2) -> double {
        return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) + (z2-z1)*(z2-z1));
    };
    
    cout << "2D距离 (0,0) 到 (3,4)：" << distance(0, 0, 3, 4) << endl;
    cout << "3D距离 (0,0,0) 到 (1,1,1)：" << distance3D(0, 0, 0, 1, 1, 1) << endl;
    
    // 练习2：默认参数的实际应用
    cout << "\n练习2：默认参数的银行账户" << endl;
    
    auto createAccount = [](string name, double balance = 0.0, string type = "储蓄账户") {
        cout << "创建账户：" << endl;
        cout << "  姓名：" << name << endl;
        cout << "  余额：" << balance << endl;
        cout << "  类型：" << type << endl;
        cout << "-------------------" << endl;
    };
    
    createAccount("张三");
    createAccount("李四", 1000.0);
    createAccount("王五", 5000.0, "支票账户");
    
    // 练习3：模板函数的实际应用
    cout << "\n练习3：模板函数排序" << endl;
    
    auto bubbleSort = [](auto arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    auto temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    };
    
    int intArr[] = {64, 34, 25, 12, 22, 11, 90};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    
    cout << "排序前：";
    for (int i = 0; i < intSize; i++) {
        cout << intArr[i] << " ";
    }
    cout << endl;
    
    bubbleSort(intArr, intSize);
    
    cout << "排序后：";
    for (int i = 0; i < intSize; i++) {
        cout << intArr[i] << " ";
    }
    cout << endl;
}

// 面积计算函数实现
double calculateArea(double radius) {
    return 3.14159 * radius * radius;
}

double calculateArea(double length, double width) {
    return length * width;
}

double calculateArea(double a, double b, double c) {
    // 使用海伦公式计算三角形面积
    double s = (a + b + c) / 2.0;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}

// 默认参数函数实现
void printMessage(string message, int times, char separator) {
    for (int i = 0; i < times; i++) {
        cout << message << endl;
    }
    for (int i = 0; i < message.length(); i++) {
        cout << separator;
    }
    cout << endl;
}

double calculatePower(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

void displayInfo(string name, int age, string city) {
    cout << "个人信息：" << endl;
    cout << "  姓名：" << name << endl;
    if (age > 0) {
        cout << "  年龄：" << age << endl;
    }
    cout << "  城市：" << city << endl;
    cout << "-------------------" << endl;
}

// 函数模板实现
template<typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

template<typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

/*
 * 学习要点总结：
 * 
 * 1. 函数重载：
 *    - 同名函数，不同参数列表
 *    - 编译器根据参数类型和数量选择函数
 *    - 返回类型不能作为重载的依据
 * 
 * 2. 默认参数：
 *    - 在函数声明中指定默认值
 *    - 默认参数必须从右到左连续
 *    - 调用时可以省略有默认值的参数
 * 
 * 3. 函数模板：
 *    - 使用template关键字定义
 *    - 可以处理多种数据类型
 *    - 编译器自动推导类型
 * 
 * 4. 实践技巧：
 *    - 合理使用函数重载提高代码可读性
 *    - 默认参数可以简化函数调用
 *    - 模板函数提高代码复用性
 *    - 注意重载函数的歧义性
 */
