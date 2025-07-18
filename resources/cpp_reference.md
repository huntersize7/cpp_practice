# C++ 学习参考资料

## 📖 基础语法速查

### 数据类型
```cpp
// 基本数据类型
int age = 25;           // 整数
float price = 19.99f;   // 单精度浮点数
double pi = 3.14159;    // 双精度浮点数
char grade = 'A';       // 字符
bool isTrue = true;     // 布尔值
string name = "张三";   // 字符串

// 常量
const int MAX_SIZE = 100;
```

### 输入输出
```cpp
#include <iostream>
using namespace std;

// 输出
cout << "Hello World" << endl;
cout << "数字: " << 42 << endl;

// 输入
int number;
string text;
cin >> number >> text;
```

### 运算符
```cpp
// 算术运算符
+ - * / %

// 比较运算符
== != < > <= >=

// 逻辑运算符
&& || !

// 自增自减
++ --
```

### 控制结构
```cpp
// if语句
if (condition) {
    // 代码
} else if (condition2) {
    // 代码
} else {
    // 代码
}

// switch语句
switch (variable) {
    case value1:
        // 代码
        break;
    case value2:
        // 代码
        break;
    default:
        // 代码
}

// for循环
for (int i = 0; i < 10; i++) {
    // 代码
}

// while循环
while (condition) {
    // 代码
}

// do-while循环
do {
    // 代码
} while (condition);
```

### 数组
```cpp
// 声明和初始化
int numbers[5] = {1, 2, 3, 4, 5};
int scores[10];  // 未初始化

// 访问元素
numbers[0] = 10;
cout << numbers[0] << endl;
```

### 函数
```cpp
// 函数声明
int add(int a, int b);

// 函数定义
int add(int a, int b) {
    return a + b;
}

// 函数调用
int result = add(5, 3);
```

## 🔧 常用编译命令

### 基本编译
```bash
g++ -o program source.cpp
```

### 带调试信息
```bash
g++ -g -o program source.cpp
```

### 多文件编译
```bash
g++ -o program main.cpp file1.cpp file2.cpp
```

### 常用编译选项
```bash
-Wall          # 显示所有警告
-std=c++11     # 使用C++11标准
-O2            # 优化级别2
```

## 🐛 常见错误和解决方案

### 编译错误
1. **未声明的标识符**
   ```
   error: 'cout' was not declared in this scope
   ```
   解决：添加 `#include <iostream>` 和 `using namespace std;`

2. **缺少分号**
   ```
   error: expected ';' before 'return'
   ```
   解决：在语句末尾添加分号

3. **类型不匹配**
   ```
   error: cannot convert 'string' to 'int'
   ```
   解决：检查变量类型是否匹配

### 运行时错误
1. **数组越界**
   ```cpp
   int arr[5];
   arr[10] = 1;  // 错误：越界访问
   ```

2. **除零错误**
   ```cpp
   int result = 10 / 0;  // 错误：除数为0
   ```

3. **未初始化变量**
   ```cpp
   int x;
   cout << x;  // 错误：使用未初始化的变量
   ```

## 📚 推荐学习资源

### 在线文档
- [cppreference.com](https://en.cppreference.com/) - C++标准库参考
- [cplusplus.com](http://www.cplusplus.com/) - C++教程和参考

### 在线练习平台
- [LeetCode](https://leetcode.com/) - 算法练习
- [牛客网](https://www.nowcoder.com/) - 编程练习
- [洛谷](https://www.luogu.com.cn/) - 算法竞赛

### 推荐书籍
- 《C++ Primer》- 经典入门书籍
- 《Effective C++》- 进阶技巧
- 《C++标准库》- STL详解

### 开发工具
- **IDE**: Visual Studio, Code::Blocks, Dev-C++
- **编辑器**: VS Code, Sublime Text, Vim
- **编译器**: GCC, Clang, MSVC

## 💡 学习技巧

1. **多动手练习**: 理论学习后立即编写代码验证
2. **阅读错误信息**: 仔细阅读编译器的错误提示
3. **调试技巧**: 使用cout输出中间结果调试程序
4. **代码规范**: 保持良好的代码格式和命名习惯
5. **循序渐进**: 从简单程序开始，逐步增加复杂度

## 🎯 学习检查清单

### 基础语法 ✓
- [ ] 数据类型和变量
- [ ] 输入输出操作
- [ ] 运算符使用
- [ ] 条件语句
- [ ] 循环语句
- [ ] 数组操作
- [ ] 函数定义和调用

### 面向对象 ✓
- [ ] 类和对象
- [ ] 构造函数和析构函数
- [ ] 继承
- [ ] 多态
- [ ] 封装

### 高级特性 ✓
- [ ] 指针和引用
- [ ] 动态内存管理
- [ ] 模板
- [ ] 异常处理
- [ ] 命名空间

### STL标准库 ✓
- [ ] 容器类
- [ ] 迭代器
- [ ] 算法
- [ ] 函数对象
