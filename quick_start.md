# 🚀 C++ 学习快速开始指南

## 第一步：验证环境

首先确保你的编译环境正常工作：

```bash
# 检查g++是否安装
g++ --version

# 如果没有安装，Windows用户可以安装MinGW-w64
# 或者使用Visual Studio
```

## 第二步：运行第一个程序

```bash
# 编译并运行Hello World程序
g++ -o hello day01_hello_world.cpp
./hello
```

## 第三步：开始系统学习

### 今天就开始第1天的学习：

1. **打开学习计划**：查看 `cpp_learning_plan.md`
2. **运行示例代码**：编译运行 `day01_hello_world.cpp`
3. **记录学习进度**：在 `learning_progress.md` 中记录今天的学习情况

### 每日学习流程：

1. **阅读当天的学习目标**
2. **运行并理解示例代码**
3. **完成练习任务**
4. **记录学习心得**
5. **预习明天的内容**

## 第四步：建立学习习惯

- ⏰ **固定学习时间**：每天同一时间学习1-2小时
- 📝 **做好笔记**：记录重点概念和易错点
- 💻 **多写代码**：理论学习后立即实践
- 🤝 **寻求帮助**：遇到问题及时解决

## 常用命令速查

```bash
# 编译单个文件
g++ -o program_name source_file.cpp

# 编译多个文件
g++ -o program main.cpp file1.cpp file2.cpp

# 带调试信息编译
g++ -g -o program source.cpp

# 显示警告信息
g++ -Wall -o program source.cpp
```

## 目录结构说明

```
cpp_practice/
├── README.md                 # 项目总览
├── cpp_learning_plan.md      # 详细学习方案
├── learning_progress.md      # 学习进度跟踪
├── quick_start.md            # 快速开始指南
├── day01_hello_world.cpp     # 第1天练习
├── stage1_basics/            # 第一阶段练习代码
│   ├── day02_data_types.cpp
│   └── day03_input_output.cpp
└── resources/                # 学习资源
    └── cpp_reference.md      # C++语法参考
```

## 🎯 开始你的C++之旅！

现在就开始第一天的学习吧：

```bash
# 编译第一个程序
g++ -o hello day01_hello_world.cpp

# 运行程序
./hello

# 开始第二天的学习
cd stage1_basics
g++ -o day02 day02_data_types.cpp
./day02
```

祝你学习顺利！记住：**坚持每天练习，你一定能掌握C++！** 💪
