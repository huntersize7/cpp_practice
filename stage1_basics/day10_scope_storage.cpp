/*
 * 第10天：作用域与存储类
 * 学习内容：局部变量和全局变量、static关键字、extern关键字
 * 练习任务：理解变量作用域的程序、使用static变量计数函数调用次数
 */

#include <iostream>
using namespace std;

// 全局变量
int globalVar = 100;
static int staticGlobalVar = 200;

// 函数声明
void demonstrateScope();
void demonstrateStaticVariables();
void demonstrateExternVariables();
void functionCallCounter();
void practiceExercises();

// 辅助函数
void localVariableDemo();
void staticLocalDemo();
void globalVariableDemo();
int getNextId();
void resetCounter();

int main() {
    cout << "=== 第10天：作用域与存储类 ===" << endl;
    cout << "今天我们将学习：" << endl;
    cout << "1. 局部变量和全局变量" << endl;
    cout << "2. static关键字" << endl;
    cout << "3. extern关键字" << endl;
    cout << "4. 变量生命周期" << endl;
    cout << "================================" << endl << endl;

    // 1. 作用域演示
    cout << "1. 变量作用域演示：" << endl;
    demonstrateScope();
    cout << endl;

    // 2. static变量演示
    cout << "2. static变量演示：" << endl;
    demonstrateStaticVariables();
    cout << endl;

    // 3. extern变量演示
    cout << "3. extern变量演示：" << endl;
    demonstrateExternVariables();
    cout << endl;

    // 4. 实际应用练习
    cout << "4. 实际应用练习：" << endl;
    
    // 练习1：函数调用计数
    cout << "练习1：函数调用计数" << endl;
    functionCallCounter();
    cout << endl;

    // 练习2：综合练习
    cout << "练习2：综合练习" << endl;
    practiceExercises();

    return 0;
}

// 作用域演示
void demonstrateScope() {
    cout << "全局变量 globalVar = " << globalVar << endl;
    
    // 局部变量
    int localVar = 50;
    cout << "局部变量 localVar = " << localVar << endl;
    
    // 块作用域
    {
        int blockVar = 25;
        cout << "块变量 blockVar = " << blockVar << endl;
        
        // 局部变量遮蔽全局变量
        int globalVar = 300;
        cout << "局部 globalVar = " << globalVar << " (遮蔽了全局变量)" << endl;
        cout << "全局 globalVar = " << ::globalVar << " (使用::访问全局变量)" << endl;
    }
    // blockVar在这里不可访问
    
    // 函数调用演示作用域
    localVariableDemo();
    globalVariableDemo();
    
    // for循环中的变量作用域
    for (int i = 0; i < 3; i++) {
        cout << "循环变量 i = " << i << endl;
    }
    // i在这里不可访问
    
    // 同名变量在不同作用域
    int x = 10;
    cout << "外层 x = " << x << endl;
    {
        int x = 20;
        cout << "内层 x = " << x << endl;
        {
            int x = 30;
            cout << "最内层 x = " << x << endl;
        }
        cout << "回到内层 x = " << x << endl;
    }
    cout << "回到外层 x = " << x << endl;
}

// static变量演示
void demonstrateStaticVariables() {
    cout << "static变量特性：" << endl;
    
    // 多次调用函数观察static变量
    cout << "多次调用staticLocalDemo()：" << endl;
    for (int i = 0; i < 5; i++) {
        staticLocalDemo();
    }
    
    // static全局变量
    cout << "static全局变量 staticGlobalVar = " << staticGlobalVar << endl;
    staticGlobalVar += 50;
    cout << "修改后 staticGlobalVar = " << staticGlobalVar << endl;
    
    // ID生成器示例
    cout << "\nID生成器示例：" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "生成的ID：" << getNextId() << endl;
    }
    
    resetCounter();
    cout << "重置后生成的ID：" << getNextId() << endl;
}

// extern变量演示
void demonstrateExternVariables() {
    cout << "extern变量使用：" << endl;
    
    // 访问全局变量
    extern int globalVar;
    cout << "通过extern访问 globalVar = " << globalVar << endl;
    
    // 修改全局变量
    globalVar = 150;
    cout << "修改后 globalVar = " << globalVar << endl;
    
    // 在函数中声明extern变量
    auto externDemo = []() {
        extern int globalVar;
        cout << "函数内通过extern访问 globalVar = " << globalVar << endl;
        globalVar += 10;
    };
    
    externDemo();
    cout << "函数修改后 globalVar = " << globalVar << endl;
}

// 练习1：函数调用计数
void functionCallCounter() {
    auto countedFunction = []() {
        static int callCount = 0;
        callCount++;
        cout << "函数被调用了 " << callCount << " 次" << endl;
        return callCount;
    };
    
    cout << "多次调用计数函数：" << endl;
    for (int i = 0; i < 8; i++) {
        countedFunction();
    }
    
    // 不同函数的独立计数
    auto anotherCountedFunction = []() {
        static int count = 0;
        count++;
        cout << "另一个函数被调用了 " << count << " 次" << endl;
    };
    
    cout << "\n调用另一个计数函数：" << endl;
    for (int i = 0; i < 3; i++) {
        anotherCountedFunction();
    }
    
    // 再次调用第一个函数
    cout << "\n再次调用第一个函数：" << endl;
    countedFunction();
}

// 综合练习
void practiceExercises() {
    // 练习1：银行账户余额管理
    cout << "练习1：银行账户余额管理" << endl;
    
    auto bankAccount = []() {
        static double balance = 1000.0;
        static int transactionCount = 0;
        
        auto deposit = [](double amount) {
            extern double balance;
            extern int transactionCount;
            balance += amount;
            transactionCount++;
            cout << "存款 " << amount << "，余额：" << balance << "，交易次数：" << transactionCount << endl;
        };
        
        auto withdraw = [](double amount) {
            static double& bal = balance;
            static int& count = transactionCount;
            if (bal >= amount) {
                bal -= amount;
                count++;
                cout << "取款 " << amount << "，余额：" << bal << "，交易次数：" << count << endl;
            } else {
                cout << "余额不足，无法取款 " << amount << endl;
            }
        };
        
        auto checkBalance = []() {
            static double& bal = balance;
            static int& count = transactionCount;
            cout << "当前余额：" << bal << "，总交易次数：" << count << endl;
        };
        
        return make_tuple(deposit, withdraw, checkBalance);
    };
    
    auto [deposit, withdraw, checkBalance] = bankAccount();
    
    checkBalance();
    deposit(500);
    withdraw(200);
    withdraw(2000);  // 余额不足
    checkBalance();
    
    // 练习2：单例模式计数器
    cout << "\n练习2：单例模式计数器" << endl;
    
    auto getCounter = []() -> int& {
        static int counter = 0;
        return counter;
    };
    
    auto incrementCounter = [&getCounter]() {
        getCounter()++;
        cout << "计数器递增，当前值：" << getCounter() << endl;
    };
    
    auto decrementCounter = [&getCounter]() {
        getCounter()--;
        cout << "计数器递减，当前值：" << getCounter() << endl;
    };
    
    auto resetCounterLocal = [&getCounter]() {
        getCounter() = 0;
        cout << "计数器重置，当前值：" << getCounter() << endl;
    };
    
    for (int i = 0; i < 5; i++) {
        incrementCounter();
    }
    
    for (int i = 0; i < 2; i++) {
        decrementCounter();
    }
    
    resetCounterLocal();
    incrementCounter();
    
    // 练习3：配置管理器
    cout << "\n练习3：配置管理器" << endl;
    
    auto configManager = []() {
        static string appName = "MyApp";
        static string version = "1.0.0";
        static bool debugMode = false;
        
        auto setAppName = [](const string& name) {
            static string& app = appName;
            app = name;
            cout << "应用名称设置为：" << app << endl;
        };
        
        auto setVersion = [](const string& ver) {
            static string& v = version;
            v = ver;
            cout << "版本设置为：" << v << endl;
        };
        
        auto toggleDebug = []() {
            static bool& debug = debugMode;
            debug = !debug;
            cout << "调试模式：" << (debug ? "开启" : "关闭") << endl;
        };
        
        auto showConfig = []() {
            static string& app = appName;
            static string& ver = version;
            static bool& debug = debugMode;
            cout << "当前配置：" << endl;
            cout << "  应用名称：" << app << endl;
            cout << "  版本：" << ver << endl;
            cout << "  调试模式：" << (debug ? "开启" : "关闭") << endl;
        };
        
        return make_tuple(setAppName, setVersion, toggleDebug, showConfig);
    };
    
    auto [setAppName, setVersion, toggleDebug, showConfig] = configManager();
    
    showConfig();
    setAppName("C++学习程序");
    setVersion("2.1.0");
    toggleDebug();
    showConfig();
}

// 辅助函数实现
void localVariableDemo() {
    int localVar = 75;
    cout << "localVariableDemo中的局部变量：" << localVar << endl;
}

void staticLocalDemo() {
    static int staticVar = 0;
    staticVar += 10;
    cout << "staticLocalDemo中的static变量：" << staticVar << endl;
}

void globalVariableDemo() {
    cout << "globalVariableDemo中访问全局变量：" << globalVar << endl;
    globalVar += 5;
}

int getNextId() {
    static int id = 1000;
    return ++id;
}

void resetCounter() {
    // 注意：这里无法直接重置getNextId中的static变量
    // 这是static变量的一个限制
    cout << "注意：static变量无法从外部直接重置" << endl;
}

/*
 * 学习要点总结：
 * 
 * 1. 变量作用域：
 *    - 全局作用域：整个程序可见
 *    - 函数作用域：函数内部可见
 *    - 块作用域：{}内部可见
 *    - 局部变量会遮蔽同名的全局变量
 * 
 * 2. static关键字：
 *    - static局部变量：函数调用间保持值
 *    - static全局变量：限制在当前文件
 *    - static函数：限制在当前文件
 * 
 * 3. extern关键字：
 *    - 声明变量在其他地方定义
 *    - 用于访问其他文件的全局变量
 * 
 * 4. 变量生命周期：
 *    - 自动变量：进入作用域时创建，离开时销毁
 *    - static变量：程序开始时创建，程序结束时销毁
 *    - 全局变量：程序开始时创建，程序结束时销毁
 * 
 * 5. 实践技巧：
 *    - 尽量使用局部变量
 *    - 合理使用static变量保存状态
 *    - 避免过多的全局变量
 *    - 注意变量名的遮蔽问题
 */
