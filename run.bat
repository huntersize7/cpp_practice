@echo off
g++ cpp_practice01.cpp -o cpp_practice01.exe
if %errorlevel% equ 0 (
    echo 编译成功！运行程序：
    echo.
    cpp_practice01.exe
) else (
    echo 编译失败！
)
pause
