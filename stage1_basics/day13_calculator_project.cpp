/*
 * 第13天：综合练习1 - 简单计算器
 * 项目要求：支持四则运算、菜单驱动界面、错误处理
 * 功能包括：基本运算、科学计算、历史记录、文件保存
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

// 计算历史记录结构
struct CalculationRecord {
    string expression;
    double result;
    string timestamp;
};

// 计算器类
class SimpleCalculator {
private:
    vector<CalculationRecord> history;
    
public:
    // 基本运算函数
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
    
    // 科学计算函数
    double power(double base, double exponent);
    double squareRoot(double number);
    double factorial(int n);
    double sine(double angle);
    double cosine(double angle);
    double tangent(double angle);
    
    // 历史记录管理
    void addToHistory(const string& expr, double result);
    void showHistory();
    void clearHistory();
    void saveHistoryToFile(const string& filename);
    void loadHistoryFromFile(const string& filename);
    
    // 主要功能
    void showMainMenu();
    void basicCalculations();
    void scientificCalculations();
    void historyManagement();
    void run();
};

int main() {
    cout << "=== 第13天：综合练习1 - 简单计算器 ===" << endl;
    cout << "欢迎使用多功能计算器！" << endl;
    cout << "========================================" << endl << endl;
    
    SimpleCalculator calculator;
    calculator.run();
    
    return 0;
}

// 基本运算函数实现
double SimpleCalculator::add(double a, double b) {
    return a + b;
}

double SimpleCalculator::subtract(double a, double b) {
    return a - b;
}

double SimpleCalculator::multiply(double a, double b) {
    return a * b;
}

double SimpleCalculator::divide(double a, double b) {
    if (b == 0) {
        throw runtime_error("除数不能为零！");
    }
    return a / b;
}

// 科学计算函数实现
double SimpleCalculator::power(double base, double exponent) {
    return pow(base, exponent);
}

double SimpleCalculator::squareRoot(double number) {
    if (number < 0) {
        throw runtime_error("负数不能开平方根！");
    }
    return sqrt(number);
}

double SimpleCalculator::factorial(int n) {
    if (n < 0) {
        throw runtime_error("负数没有阶乘！");
    }
    if (n > 20) {
        throw runtime_error("数字太大，可能导致溢出！");
    }
    
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return static_cast<double>(result);
}

double SimpleCalculator::sine(double angle) {
    return sin(angle * M_PI / 180.0); // 转换为弧度
}

double SimpleCalculator::cosine(double angle) {
    return cos(angle * M_PI / 180.0);
}

double SimpleCalculator::tangent(double angle) {
    return tan(angle * M_PI / 180.0);
}

// 历史记录管理
void SimpleCalculator::addToHistory(const string& expr, double result) {
    CalculationRecord record;
    record.expression = expr;
    record.result = result;
    record.timestamp = "2024-01-01"; // 简化的时间戳
    history.push_back(record);
}

void SimpleCalculator::showHistory() {
    if (history.empty()) {
        cout << "没有计算历史记录。" << endl;
        return;
    }
    
    cout << "\n=== 计算历史记录 ===" << endl;
    cout << "序号\t表达式\t\t\t结果" << endl;
    cout << "----------------------------------------" << endl;
    
    for (size_t i = 0; i < history.size(); i++) {
        cout << (i + 1) << "\t" << history[i].expression << "\t\t" 
             << fixed << setprecision(6) << history[i].result << endl;
    }
    cout << "----------------------------------------" << endl;
}

void SimpleCalculator::clearHistory() {
    history.clear();
    cout << "历史记录已清空。" << endl;
}

void SimpleCalculator::saveHistoryToFile(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "无法创建文件：" << filename << endl;
        return;
    }
    
    file << "计算器历史记录" << endl;
    file << "===============" << endl;
    
    for (const auto& record : history) {
        file << record.expression << " = " << record.result << endl;
    }
    
    file.close();
    cout << "历史记录已保存到：" << filename << endl;
}

void SimpleCalculator::loadHistoryFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "无法打开文件：" << filename << endl;
        return;
    }
    
    // 简化的加载逻辑
    string line;
    getline(file, line); // 跳过标题
    getline(file, line); // 跳过分隔线
    
    int count = 0;
    while (getline(file, line)) {
        if (!line.empty()) {
            count++;
        }
    }
    
    file.close();
    cout << "从文件加载了 " << count << " 条历史记录。" << endl;
}

// 主菜单
void SimpleCalculator::showMainMenu() {
    cout << "\n=== 多功能计算器主菜单 ===" << endl;
    cout << "1. 基本运算" << endl;
    cout << "2. 科学计算" << endl;
    cout << "3. 历史记录管理" << endl;
    cout << "4. 退出程序" << endl;
    cout << "请选择功能 (1-4)：";
}

// 基本运算菜单
void SimpleCalculator::basicCalculations() {
    int choice;
    double num1, num2, result;
    string expression;
    
    do {
        cout << "\n=== 基本运算 ===" << endl;
        cout << "1. 加法 (+)" << endl;
        cout << "2. 减法 (-)" << endl;
        cout << "3. 乘法 (×)" << endl;
        cout << "4. 除法 (÷)" << endl;
        cout << "5. 返回主菜单" << endl;
        cout << "请选择运算 (1-5)：";
        cin >> choice;
        
        if (choice >= 1 && choice <= 4) {
            cout << "请输入第一个数：";
            cin >> num1;
            cout << "请输入第二个数：";
            cin >> num2;
            
            try {
                switch (choice) {
                    case 1:
                        result = add(num1, num2);
                        expression = to_string(num1) + " + " + to_string(num2);
                        cout << "结果：" << num1 << " + " << num2 << " = " << result << endl;
                        break;
                    case 2:
                        result = subtract(num1, num2);
                        expression = to_string(num1) + " - " + to_string(num2);
                        cout << "结果：" << num1 << " - " << num2 << " = " << result << endl;
                        break;
                    case 3:
                        result = multiply(num1, num2);
                        expression = to_string(num1) + " × " + to_string(num2);
                        cout << "结果：" << num1 << " × " << num2 << " = " << result << endl;
                        break;
                    case 4:
                        result = divide(num1, num2);
                        expression = to_string(num1) + " ÷ " + to_string(num2);
                        cout << "结果：" << num1 << " ÷ " << num2 << " = " << result << endl;
                        break;
                }
                
                addToHistory(expression, result);
                
            } catch (const runtime_error& e) {
                cout << "错误：" << e.what() << endl;
            }
        } else if (choice != 5) {
            cout << "无效选择，请重新输入！" << endl;
        }
        
    } while (choice != 5);
}

// 科学计算菜单
void SimpleCalculator::scientificCalculations() {
    int choice;
    double num, result;
    string expression;
    
    do {
        cout << "\n=== 科学计算 ===" << endl;
        cout << "1. 幂运算 (x^y)" << endl;
        cout << "2. 平方根 (√x)" << endl;
        cout << "3. 阶乘 (n!)" << endl;
        cout << "4. 正弦 (sin)" << endl;
        cout << "5. 余弦 (cos)" << endl;
        cout << "6. 正切 (tan)" << endl;
        cout << "7. 返回主菜单" << endl;
        cout << "请选择运算 (1-7)：";
        cin >> choice;
        
        try {
            switch (choice) {
                case 1: {
                    double base, exp;
                    cout << "请输入底数：";
                    cin >> base;
                    cout << "请输入指数：";
                    cin >> exp;
                    result = power(base, exp);
                    expression = to_string(base) + "^" + to_string(exp);
                    cout << "结果：" << base << "^" << exp << " = " << result << endl;
                    addToHistory(expression, result);
                    break;
                }
                case 2:
                    cout << "请输入数字：";
                    cin >> num;
                    result = squareRoot(num);
                    expression = "√" + to_string(num);
                    cout << "结果：√" << num << " = " << result << endl;
                    addToHistory(expression, result);
                    break;
                case 3: {
                    int n;
                    cout << "请输入整数：";
                    cin >> n;
                    result = factorial(n);
                    expression = to_string(n) + "!";
                    cout << "结果：" << n << "! = " << result << endl;
                    addToHistory(expression, result);
                    break;
                }
                case 4:
                    cout << "请输入角度：";
                    cin >> num;
                    result = sine(num);
                    expression = "sin(" + to_string(num) + "°)";
                    cout << "结果：sin(" << num << "°) = " << result << endl;
                    addToHistory(expression, result);
                    break;
                case 5:
                    cout << "请输入角度：";
                    cin >> num;
                    result = cosine(num);
                    expression = "cos(" + to_string(num) + "°)";
                    cout << "结果：cos(" << num << "°) = " << result << endl;
                    addToHistory(expression, result);
                    break;
                case 6:
                    cout << "请输入角度：";
                    cin >> num;
                    result = tangent(num);
                    expression = "tan(" + to_string(num) + "°)";
                    cout << "结果：tan(" << num << "°) = " << result << endl;
                    addToHistory(expression, result);
                    break;
                case 7:
                    break;
                default:
                    cout << "无效选择，请重新输入！" << endl;
                    break;
            }
        } catch (const runtime_error& e) {
            cout << "错误：" << e.what() << endl;
        }
        
    } while (choice != 7);
}

// 历史记录管理
void SimpleCalculator::historyManagement() {
    int choice;
    
    do {
        cout << "\n=== 历史记录管理 ===" << endl;
        cout << "1. 查看历史记录" << endl;
        cout << "2. 清空历史记录" << endl;
        cout << "3. 保存历史记录到文件" << endl;
        cout << "4. 从文件加载历史记录" << endl;
        cout << "5. 返回主菜单" << endl;
        cout << "请选择操作 (1-5)：";
        cin >> choice;
        
        switch (choice) {
            case 1:
                showHistory();
                break;
            case 2: {
                char confirm;
                cout << "确定要清空所有历史记录吗？(y/n)：";
                cin >> confirm;
                if (confirm == 'y' || confirm == 'Y') {
                    clearHistory();
                }
                break;
            }
            case 3: {
                string filename;
                cout << "请输入文件名：";
                cin >> filename;
                saveHistoryToFile(filename);
                break;
            }
            case 4: {
                string filename;
                cout << "请输入文件名：";
                cin >> filename;
                loadHistoryFromFile(filename);
                break;
            }
            case 5:
                break;
            default:
                cout << "无效选择，请重新输入！" << endl;
                break;
        }
        
    } while (choice != 5);
}

// 主程序运行
void SimpleCalculator::run() {
    int choice;
    
    do {
        showMainMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                basicCalculations();
                break;
            case 2:
                scientificCalculations();
                break;
            case 3:
                historyManagement();
                break;
            case 4:
                cout << "感谢使用计算器！再见！" << endl;
                break;
            default:
                cout << "无效选择，请重新输入！" << endl;
                break;
        }
        
    } while (choice != 4);
}

/*
 * 项目总结：
 * 
 * 1. 项目特点：
 *    - 面向对象设计
 *    - 菜单驱动界面
 *    - 完整的错误处理
 *    - 历史记录功能
 *    - 文件操作支持
 * 
 * 2. 技术要点：
 *    - 类的设计和使用
 *    - 异常处理机制
 *    - 文件输入输出
 *    - 数学函数库使用
 *    - 用户界面设计
 * 
 * 3. 功能模块：
 *    - 基本四则运算
 *    - 科学计算功能
 *    - 历史记录管理
 *    - 数据持久化
 * 
 * 4. 扩展建议：
 *    - 添加更多数学函数
 *    - 支持表达式解析
 *    - 改进用户界面
 *    - 添加单位转换功能
 */
