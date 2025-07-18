/*
 * 第7天：字符串处理学习与实践
 * 学习内容：C风格字符串、string类的使用、常用字符串函数
 * 练习任务：字符串反转程序、统计字符串中字符个数
 */

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

// 函数声明
void demonstrateCStyleStrings();
void demonstrateStringClass();
void demonstrateStringFunctions();
void stringReverseProgram();
void characterCountProgram();
void practiceExercises();

int main() {
    cout << "=== 第7天：字符串处理学习与实践 ===" << endl;
    cout << "今天我们将学习：" << endl;
    cout << "1. C风格字符串" << endl;
    cout << "2. string类的使用" << endl;
    cout << "3. 常用字符串函数" << endl;
    cout << "4. 字符串处理实践" << endl;
    cout << "================================" << endl << endl;

    // 1. C风格字符串演示
    cout << "1. C风格字符串演示：" << endl;
    demonstrateCStyleStrings();
    cout << endl;

    // 2. string类演示
    cout << "2. string类演示：" << endl;
    demonstrateStringClass();
    cout << endl;

    // 3. 字符串函数演示
    cout << "3. 字符串函数演示：" << endl;
    demonstrateStringFunctions();
    cout << endl;

    // 4. 实际应用练习
    cout << "4. 实际应用练习：" << endl;
    
    // 练习1：字符串反转
    cout << "练习1：字符串反转程序" << endl;
    stringReverseProgram();
    cout << endl;

    // 练习2：字符统计
    cout << "练习2：字符统计程序" << endl;
    characterCountProgram();
    cout << endl;

    // 练习3：综合练习
    cout << "练习3：综合练习" << endl;
    practiceExercises();

    return 0;
}

// C风格字符串演示
void demonstrateCStyleStrings() {
    // C风格字符串声明和初始化
    char str1[20] = "Hello";
    char str2[] = "World";
    char str3[20];
    
    cout << "C风格字符串基础：" << endl;
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    
    // 字符串复制
    strcpy(str3, "C++ Programming");
    cout << "复制后的str3: " << str3 << endl;
    
    // 字符串连接
    strcat(str1, " ");
    strcat(str1, str2);
    cout << "连接后的str1: " << str1 << endl;
    
    // 字符串长度
    cout << "str1的长度: " << strlen(str1) << endl;
    cout << "str3的长度: " << strlen(str3) << endl;
    
    // 字符串比较
    char str4[] = "Hello World";
    int result = strcmp(str1, str4);
    cout << "str1与str4比较结果: " << result;
    if (result == 0) {
        cout << " (相等)" << endl;
    } else if (result < 0) {
        cout << " (str1 < str4)" << endl;
    } else {
        cout << " (str1 > str4)" << endl;
    }
    
    // 字符数组遍历
    cout << "逐字符输出str3: ";
    for (int i = 0; str3[i] != '\0'; i++) {
        cout << str3[i] << " ";
    }
    cout << endl;
}

// string类演示
void demonstrateStringClass() {
    // string对象创建和初始化
    string s1 = "Hello";
    string s2("World");
    string s3(s1);
    string s4(5, 'A'); // 5个'A'
    
    cout << "string对象创建：" << endl;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    cout << "s4: " << s4 << endl;
    
    // 字符串连接
    string s5 = s1 + " " + s2;
    cout << "连接结果s5: " << s5 << endl;
    
    // 字符串赋值
    s1 += " C++";
    cout << "赋值后s1: " << s1 << endl;
    
    // 字符串长度
    cout << "s5的长度: " << s5.length() << " 或 " << s5.size() << endl;
    
    // 字符串比较
    if (s1 == s3) {
        cout << "s1 等于 s3" << endl;
    } else {
        cout << "s1 不等于 s3" << endl;
    }
    
    // 字符串访问
    cout << "s5的第一个字符: " << s5[0] << endl;
    cout << "s5的最后一个字符: " << s5[s5.length() - 1] << endl;
    
    // 字符串修改
    s5[0] = 'h';
    cout << "修改后的s5: " << s5 << endl;
}

// 字符串函数演示
void demonstrateStringFunctions() {
    string text = "Hello C++ Programming World";
    
    cout << "原字符串: " << text << endl;
    
    // 子字符串
    string sub = text.substr(6, 3); // 从位置6开始，长度3
    cout << "子字符串substr(6,3): " << sub << endl;
    
    // 查找字符串
    size_t pos = text.find("C++");
    if (pos != string::npos) {
        cout << "找到'C++'在位置: " << pos << endl;
    }
    
    // 替换字符串
    string text2 = text;
    text2.replace(pos, 3, "Python");
    cout << "替换后: " << text2 << endl;
    
    // 插入字符串
    string text3 = text;
    text3.insert(6, "Advanced ");
    cout << "插入后: " << text3 << endl;
    
    // 删除字符串
    string text4 = text;
    text4.erase(6, 4); // 从位置6删除4个字符
    cout << "删除后: " << text4 << endl;
}

// 练习1：字符串反转程序
void stringReverseProgram() {
    string input;
    cout << "请输入一个字符串: ";
    getline(cin, input);
    
    // 方法1：使用循环反转
    string reversed1 = input;
    int len = reversed1.length();
    for (int i = 0; i < len / 2; i++) {
        char temp = reversed1[i];
        reversed1[i] = reversed1[len - 1 - i];
        reversed1[len - 1 - i] = temp;
    }
    cout << "方法1反转结果: " << reversed1 << endl;
    
    // 方法2：使用string构造函数
    string reversed2(input.rbegin(), input.rend());
    cout << "方法2反转结果: " << reversed2 << endl;
    
    // 方法3：逐字符构建
    string reversed3;
    for (int i = input.length() - 1; i >= 0; i--) {
        reversed3 += input[i];
    }
    cout << "方法3反转结果: " << reversed3 << endl;
}

// 练习2：字符统计程序
void characterCountProgram() {
    string text;
    cout << "请输入一段文本: ";
    getline(cin, text);
    
    cout << "原文本: " << text << endl;
    cout << "文本长度: " << text.length() << " 个字符" << endl;
    
    // 统计各种字符
    int letters = 0, digits = 0, spaces = 0, others = 0;
    int uppercase = 0, lowercase = 0;
    
    for (char c : text) {
        if (isalpha(c)) {
            letters++;
            if (isupper(c)) uppercase++;
            else lowercase++;
        } else if (isdigit(c)) {
            digits++;
        } else if (isspace(c)) {
            spaces++;
        } else {
            others++;
        }
    }
    
    cout << "字符统计结果:" << endl;
    cout << "字母: " << letters << " 个 (大写: " << uppercase << ", 小写: " << lowercase << ")" << endl;
    cout << "数字: " << digits << " 个" << endl;
    cout << "空格: " << spaces << " 个" << endl;
    cout << "其他: " << others << " 个" << endl;
    
    // 统计每个字母出现的次数
    int letterCount[26] = {0};
    cout << "\n字母出现频率:" << endl;
    for (char c : text) {
        if (isalpha(c)) {
            char lower = tolower(c);
            letterCount[lower - 'a']++;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        if (letterCount[i] > 0) {
            cout << (char)('a' + i) << ": " << letterCount[i] << " 次  ";
        }
    }
    cout << endl;
}

// 练习3：综合练习
void practiceExercises() {
    // 练习1：回文检测
    cout << "练习1：回文检测" << endl;
    string palindrome;
    cout << "请输入一个字符串检测是否为回文: ";
    getline(cin, palindrome);
    
    // 转换为小写并移除空格
    string cleaned;
    for (char c : palindrome) {
        if (isalnum(c)) {
            cleaned += tolower(c);
        }
    }
    
    bool isPalindrome = true;
    int len = cleaned.length();
    for (int i = 0; i < len / 2; i++) {
        if (cleaned[i] != cleaned[len - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }
    
    cout << "'" << palindrome << "' " << (isPalindrome ? "是" : "不是") << "回文" << endl;
    
    // 练习2：单词计数
    cout << "\n练习2：单词计数" << endl;
    string sentence;
    cout << "请输入一句话: ";
    getline(cin, sentence);
    
    int wordCount = 0;
    bool inWord = false;
    
    for (char c : sentence) {
        if (isalpha(c)) {
            if (!inWord) {
                wordCount++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }
    
    cout << "句子: " << sentence << endl;
    cout << "单词数量: " << wordCount << endl;
    
    // 练习3：字符串加密（凯撒密码）
    cout << "\n练习3：凯撒密码加密" << endl;
    string message;
    int shift;
    cout << "请输入要加密的消息: ";
    getline(cin, message);
    cout << "请输入位移量 (1-25): ";
    cin >> shift;
    
    string encrypted;
    for (char c : message) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            encrypted += (char)((c - base + shift) % 26 + base);
        } else {
            encrypted += c;
        }
    }
    
    cout << "原文: " << message << endl;
    cout << "密文: " << encrypted << endl;
}

/*
 * 学习要点总结：
 * 
 * 1. C风格字符串：
 *    - 以'\0'结尾的字符数组
 *    - 使用<cstring>中的函数操作
 *    - 需要手动管理内存和长度
 * 
 * 2. string类：
 *    - C++标准库提供的字符串类
 *    - 自动管理内存
 *    - 提供丰富的成员函数
 * 
 * 3. 常用操作：
 *    - 连接：+ 或 +=
 *    - 比较：==, !=, <, >, <=, >=
 *    - 访问：[] 或 at()
 *    - 长度：length() 或 size()
 * 
 * 4. 实践技巧：
 *    - 优先使用string类而不是C风格字符串
 *    - 注意字符串输入时的空格处理
 *    - 合理使用字符串函数提高效率
 *    - 字符处理时注意大小写转换
 */
