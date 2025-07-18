@echo off
echo 正在修复中文编码问题...

REM 设置代码页为UTF-8
chcp 65001 > nul

echo 编译和运行示例：
echo.

echo 第4天 - 条件语句：
cd stage1_basics
g++ -o day04 day04_conditional_statements.cpp
if exist day04.exe (
    echo 编译成功！运行程序：
    day04.exe
) else (
    echo 编译失败，请检查代码
)

echo.
echo 第5天 - 循环语句：
g++ -o day05 day05_loops.cpp
if exist day05.exe (
    echo 编译成功！运行程序：
    day05.exe
) else (
    echo 编译失败，请检查代码
)

echo.
echo 如果仍有乱码问题，请尝试以下方法：
echo 1. 在VS Code中设置文件编码为UTF-8
echo 2. 在终端中运行：chcp 65001
echo 3. 确保源文件保存为UTF-8编码

pause
