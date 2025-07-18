/*
 * 第12天：文件操作基础
 * 学习内容：文件的打开和关闭、文件的读写操作、文件流的使用
 * 练习任务：将数据写入文件、从文件读取数据并显示
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// 结构体定义
struct Student {
    int id;
    string name;
    double score;
};

// 函数声明
void demonstrateFileWriting();
void demonstrateFileReading();
void demonstrateFileAppending();
void demonstrateBinaryFiles();
void studentFileManagement();
void practiceExercises();

// 辅助函数
void writeStudentsToFile(const vector<Student>& students, const string& filename);
vector<Student> readStudentsFromFile(const string& filename);
void displayStudents(const vector<Student>& students);

int main() {
    cout << "=== 第12天：文件操作基础 ===" << endl;
    cout << "今天我们将学习：" << endl;
    cout << "1. 文件的打开和关闭" << endl;
    cout << "2. 文件的读写操作" << endl;
    cout << "3. 文件流的使用" << endl;
    cout << "4. 文件操作实践" << endl;
    cout << "================================" << endl << endl;

    // 1. 文件写入演示
    cout << "1. 文件写入演示：" << endl;
    demonstrateFileWriting();
    cout << endl;

    // 2. 文件读取演示
    cout << "2. 文件读取演示：" << endl;
    demonstrateFileReading();
    cout << endl;

    // 3. 文件追加演示
    cout << "3. 文件追加演示：" << endl;
    demonstrateFileAppending();
    cout << endl;

    // 4. 二进制文件演示
    cout << "4. 二进制文件演示：" << endl;
    demonstrateBinaryFiles();
    cout << endl;

    // 5. 实际应用练习
    cout << "5. 实际应用练习：" << endl;
    
    // 练习1：学生文件管理
    cout << "练习1：学生信息文件管理" << endl;
    studentFileManagement();
    cout << endl;

    // 练习2：综合练习
    cout << "练习2：综合练习" << endl;
    practiceExercises();

    return 0;
}

// 文件写入演示
void demonstrateFileWriting() {
    // 创建输出文件流
    ofstream outFile("example.txt");
    
    if (outFile.is_open()) {
        cout << "成功创建文件 example.txt" << endl;
        
        // 写入文本数据
        outFile << "Hello, File Operations!" << endl;
        outFile << "这是第一行文本" << endl;
        outFile << "这是第二行文本" << endl;
        outFile << "数字：" << 42 << endl;
        outFile << "浮点数：" << 3.14159 << endl;
        
        // 关闭文件
        outFile.close();
        cout << "数据已写入文件并关闭" << endl;
    } else {
        cout << "无法创建文件！" << endl;
    }
    
    // 使用构造函数直接打开文件
    ofstream dataFile("data.txt");
    if (dataFile) {
        dataFile << "学生成绩数据：" << endl;
        dataFile << "张三 85.5" << endl;
        dataFile << "李四 92.0" << endl;
        dataFile << "王五 78.5" << endl;
        dataFile.close();
        cout << "学生数据已写入 data.txt" << endl;
    }
}

// 文件读取演示
void demonstrateFileReading() {
    // 读取整个文件内容
    ifstream inFile("example.txt");
    
    if (inFile.is_open()) {
        cout << "读取 example.txt 内容：" << endl;
        cout << "------------------------" << endl;
        
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        
        inFile.close();
        cout << "------------------------" << endl;
    } else {
        cout << "无法打开文件 example.txt！" << endl;
    }
    
    // 逐词读取
    ifstream dataFile("data.txt");
    if (dataFile) {
        cout << "\n逐词读取 data.txt：" << endl;
        string word;
        while (dataFile >> word) {
            cout << "读取到：" << word << endl;
        }
        dataFile.close();
    }
    
    // 读取特定格式的数据
    ifstream scoreFile("data.txt");
    if (scoreFile) {
        cout << "\n读取学生成绩：" << endl;
        string header;
        getline(scoreFile, header); // 跳过标题行
        
        string name;
        double score;
        while (scoreFile >> name >> score) {
            cout << "学生：" << name << "，成绩：" << score << endl;
        }
        scoreFile.close();
    }
}

// 文件追加演示
void demonstrateFileAppending() {
    // 追加模式打开文件
    ofstream appendFile("example.txt", ios::app);
    
    if (appendFile.is_open()) {
        appendFile << "这是追加的内容" << endl;
        appendFile << "追加时间：2024年" << endl;
        appendFile.close();
        cout << "内容已追加到 example.txt" << endl;
    }
    
    // 读取追加后的文件
    ifstream readFile("example.txt");
    if (readFile) {
        cout << "\n追加后的文件内容：" << endl;
        cout << "------------------------" << endl;
        string line;
        while (getline(readFile, line)) {
            cout << line << endl;
        }
        cout << "------------------------" << endl;
        readFile.close();
    }
}

// 二进制文件演示
void demonstrateBinaryFiles() {
    // 写入二进制文件
    ofstream binFile("binary_data.bin", ios::binary);
    if (binFile) {
        int numbers[] = {10, 20, 30, 40, 50};
        binFile.write(reinterpret_cast<char*>(numbers), sizeof(numbers));
        
        double pi = 3.14159;
        binFile.write(reinterpret_cast<char*>(&pi), sizeof(pi));
        
        binFile.close();
        cout << "二进制数据已写入 binary_data.bin" << endl;
    }
    
    // 读取二进制文件
    ifstream binReadFile("binary_data.bin", ios::binary);
    if (binReadFile) {
        int readNumbers[5];
        binReadFile.read(reinterpret_cast<char*>(readNumbers), sizeof(readNumbers));
        
        double readPi;
        binReadFile.read(reinterpret_cast<char*>(&readPi), sizeof(readPi));
        
        binReadFile.close();
        
        cout << "从二进制文件读取的数据：" << endl;
        cout << "整数数组：";
        for (int i = 0; i < 5; i++) {
            cout << readNumbers[i] << " ";
        }
        cout << endl;
        cout << "π值：" << readPi << endl;
    }
}

// 练习1：学生文件管理
void studentFileManagement() {
    vector<Student> students = {
        {1001, "张三", 85.5},
        {1002, "李四", 92.0},
        {1003, "王五", 78.5},
        {1004, "赵六", 88.0},
        {1005, "钱七", 95.5}
    };
    
    // 将学生数据写入文件
    writeStudentsToFile(students, "students.txt");
    cout << "学生数据已保存到 students.txt" << endl;
    
    // 从文件读取学生数据
    vector<Student> loadedStudents = readStudentsFromFile("students.txt");
    cout << "\n从文件读取的学生数据：" << endl;
    displayStudents(loadedStudents);
    
    // 添加新学生并保存
    Student newStudent = {1006, "孙八", 89.5};
    loadedStudents.push_back(newStudent);
    
    writeStudentsToFile(loadedStudents, "students_updated.txt");
    cout << "\n更新后的学生数据已保存到 students_updated.txt" << endl;
    
    // 计算并保存统计信息
    ofstream statsFile("statistics.txt");
    if (statsFile) {
        double totalScore = 0;
        double maxScore = loadedStudents[0].score;
        double minScore = loadedStudents[0].score;
        
        for (const auto& student : loadedStudents) {
            totalScore += student.score;
            if (student.score > maxScore) maxScore = student.score;
            if (student.score < minScore) minScore = student.score;
        }
        
        double averageScore = totalScore / loadedStudents.size();
        
        statsFile << "学生统计信息" << endl;
        statsFile << "===============" << endl;
        statsFile << "学生总数：" << loadedStudents.size() << endl;
        statsFile << "平均分：" << averageScore << endl;
        statsFile << "最高分：" << maxScore << endl;
        statsFile << "最低分：" << minScore << endl;
        
        statsFile.close();
        cout << "统计信息已保存到 statistics.txt" << endl;
    }
}

// 综合练习
void practiceExercises() {
    // 练习1：日志文件管理
    cout << "练习1：日志文件管理" << endl;
    
    auto writeLog = [](const string& message) {
        ofstream logFile("application.log", ios::app);
        if (logFile) {
            // 简单的时间戳（实际应用中应使用更精确的时间）
            logFile << "[LOG] " << message << endl;
            logFile.close();
        }
    };
    
    writeLog("程序启动");
    writeLog("用户登录：张三");
    writeLog("执行操作：查看学生信息");
    writeLog("用户退出");
    writeLog("程序结束");
    
    cout << "日志已写入 application.log" << endl;
    
    // 读取并显示日志
    ifstream logFile("application.log");
    if (logFile) {
        cout << "\n日志内容：" << endl;
        cout << "------------------------" << endl;
        string line;
        while (getline(logFile, line)) {
            cout << line << endl;
        }
        cout << "------------------------" << endl;
        logFile.close();
    }
    
    // 练习2：配置文件处理
    cout << "\n练习2：配置文件处理" << endl;
    
    // 写入配置文件
    ofstream configFile("config.txt");
    if (configFile) {
        configFile << "# 应用程序配置文件" << endl;
        configFile << "app_name=学生管理系统" << endl;
        configFile << "version=1.0.0" << endl;
        configFile << "max_students=1000" << endl;
        configFile << "debug_mode=true" << endl;
        configFile << "database_path=./data/students.db" << endl;
        configFile.close();
        cout << "配置文件已创建" << endl;
    }
    
    // 读取配置文件
    ifstream readConfig("config.txt");
    if (readConfig) {
        cout << "\n配置文件内容：" << endl;
        cout << "------------------------" << endl;
        string line;
        while (getline(readConfig, line)) {
            if (line.empty() || line[0] == '#') {
                cout << line << endl; // 显示注释和空行
            } else {
                // 解析键值对
                size_t pos = line.find('=');
                if (pos != string::npos) {
                    string key = line.substr(0, pos);
                    string value = line.substr(pos + 1);
                    cout << "配置项：" << key << " = " << value << endl;
                }
            }
        }
        cout << "------------------------" << endl;
        readConfig.close();
    }
    
    // 练习3：CSV文件处理
    cout << "\n练习3：CSV文件处理" << endl;
    
    // 创建CSV文件
    ofstream csvFile("students.csv");
    if (csvFile) {
        csvFile << "ID,姓名,年龄,分数,专业" << endl;
        csvFile << "1001,张三,20,85.5,计算机科学" << endl;
        csvFile << "1002,李四,21,92.0,软件工程" << endl;
        csvFile << "1003,王五,19,78.5,信息技术" << endl;
        csvFile.close();
        cout << "CSV文件已创建" << endl;
    }
    
    // 读取CSV文件
    ifstream readCSV("students.csv");
    if (readCSV) {
        cout << "\nCSV文件内容：" << endl;
        cout << "------------------------" << endl;
        string line;
        bool isHeader = true;
        
        while (getline(readCSV, line)) {
            if (isHeader) {
                cout << "表头：" << line << endl;
                isHeader = false;
            } else {
                // 简单的CSV解析
                stringstream ss(line);
                string field;
                vector<string> fields;
                
                while (getline(ss, field, ',')) {
                    fields.push_back(field);
                }
                
                if (fields.size() >= 5) {
                    cout << "学生：ID=" << fields[0] << ", 姓名=" << fields[1] 
                         << ", 年龄=" << fields[2] << ", 分数=" << fields[3] 
                         << ", 专业=" << fields[4] << endl;
                }
            }
        }
        cout << "------------------------" << endl;
        readCSV.close();
    }
}

// 辅助函数实现
void writeStudentsToFile(const vector<Student>& students, const string& filename) {
    ofstream file(filename);
    if (file) {
        file << "学生信息" << endl;
        file << "========" << endl;
        for (const auto& student : students) {
            file << student.id << " " << student.name << " " << student.score << endl;
        }
        file.close();
    }
}

vector<Student> readStudentsFromFile(const string& filename) {
    vector<Student> students;
    ifstream file(filename);
    
    if (file) {
        string line;
        getline(file, line); // 跳过标题
        getline(file, line); // 跳过分隔线
        
        int id;
        string name;
        double score;
        
        while (file >> id >> name >> score) {
            students.push_back({id, name, score});
        }
        
        file.close();
    }
    
    return students;
}

void displayStudents(const vector<Student>& students) {
    for (const auto& student : students) {
        cout << "ID: " << student.id << ", 姓名: " << student.name 
             << ", 分数: " << student.score << endl;
    }
}

/*
 * 学习要点总结：
 * 
 * 1. 文件流类型：
 *    - ifstream：输入文件流（读取）
 *    - ofstream：输出文件流（写入）
 *    - fstream：双向文件流（读写）
 * 
 * 2. 文件打开模式：
 *    - ios::in：读取模式
 *    - ios::out：写入模式
 *    - ios::app：追加模式
 *    - ios::binary：二进制模式
 * 
 * 3. 文件操作步骤：
 *    - 打开文件
 *    - 检查是否成功打开
 *    - 进行读写操作
 *    - 关闭文件
 * 
 * 4. 错误处理：
 *    - 检查文件是否成功打开
 *    - 使用is_open()或直接判断流对象
 * 
 * 5. 实践技巧：
 *    - 及时关闭文件释放资源
 *    - 合理选择文件格式（文本/二进制）
 *    - 注意文件路径和权限
 *    - 处理文件不存在的情况
 */
