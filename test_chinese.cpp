/*
 * 中文编码测试程序
 * 用于测试中文字符是否能正确显示
 */

#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    // 设置控制台编码为UTF-8，解决中文乱码问题
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    
    cout << "=== 中文编码测试程序 ===" << endl;
    cout << "如果您能看到下面的中文字符，说明编码设置成功！" << endl;
    cout << "================================" << endl;
    
    cout << "基本中文测试：" << endl;
    cout << "你好，世界！" << endl;
    cout << "欢迎学习C++编程！" << endl;
    
    cout << "\n数字和符号测试：" << endl;
    cout << "数字：1234567890" << endl;
    cout << "符号：！@#￥%……&*（）" << endl;
    cout << "英文：Hello, World!" << endl;
    
    cout << "\n程序功能测试：" << endl;
    cout << "请输入您的姓名：";
    string name;
    getline(cin, name);
    cout << "您好，" << name << "！" << endl;
    
    cout << "\n如果上述内容显示正常，说明中文编码设置成功！" << endl;
    cout << "现在可以正常运行其他学习程序了。" << endl;
    
    cout << "\n按回车键退出...";
    cin.get();
    
    return 0;
}
