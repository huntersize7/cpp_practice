/*
 * 第14天：综合练习2 - 学生成绩管理系统
 * 项目要求：添加学生信息、查询学生成绩、计算平均分、数据保存到文件
 * 功能包括：学生信息管理、成绩统计、数据持久化、报表生成
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <windows.h>
using namespace std;

// 学生信息结构
struct Student {
    int id;
    string name;
    int age;
    string major;
    double mathScore;
    double englishScore;
    double computerScore;
    double averageScore;
    
    // 计算平均分
    void calculateAverage() {
        averageScore = (mathScore + englishScore + computerScore) / 3.0;
    }
    
    // 获取等级
    string getGrade() const {
        if (averageScore >= 90) return "优秀";
        else if (averageScore >= 80) return "良好";
        else if (averageScore >= 70) return "中等";
        else if (averageScore >= 60) return "及格";
        else return "不及格";
    }
};

// 学生管理系统类
class StudentManagementSystem {
private:
    vector<Student> students;
    string dataFile;
    
public:
    StudentManagementSystem(const string& filename = "students_data.txt") 
        : dataFile(filename) {
        loadFromFile();
    }
    
    ~StudentManagementSystem() {
        saveToFile();
    }
    
    // 核心功能
    void addStudent();
    void displayAllStudents();
    void searchStudent();
    void updateStudent();
    void deleteStudent();
    void calculateStatistics();
    void generateReport();
    
    // 数据管理
    void saveToFile();
    void loadFromFile();
    void exportToCSV();
    void importFromCSV();
    
    // 排序功能
    void sortByScore();
    void sortByName();
    void sortById();
    
    // 主程序
    void showMainMenu();
    void run();
    
    // 辅助函数
    int findStudentById(int id);
    void displayStudent(const Student& student);
    bool isValidScore(double score);
};

int main() {
    // 设置控制台编码为UTF-8，解决中文乱码问题
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "=== 第14天：综合练习2 - 学生成绩管理系统 ===" << endl;
    cout << "欢迎使用学生成绩管理系统！" << endl;
    cout << "===========================================" << endl << endl;
    
    StudentManagementSystem sms;
    sms.run();
    
    return 0;
}

// 添加学生
void StudentManagementSystem::addStudent() {
    Student newStudent;
    
    cout << "\n=== 添加学生信息 ===" << endl;
    
    cout << "请输入学生ID：";
    cin >> newStudent.id;
    
    // 检查ID是否已存在
    if (findStudentById(newStudent.id) != -1) {
        cout << "错误：学生ID " << newStudent.id << " 已存在！" << endl;
        return;
    }
    
    cout << "请输入学生姓名：";
    cin >> newStudent.name;
    
    cout << "请输入学生年龄：";
    cin >> newStudent.age;
    
    cout << "请输入专业：";
    cin >> newStudent.major;
    
    // 输入成绩
    do {
        cout << "请输入数学成绩 (0-100)：";
        cin >> newStudent.mathScore;
    } while (!isValidScore(newStudent.mathScore));
    
    do {
        cout << "请输入英语成绩 (0-100)：";
        cin >> newStudent.englishScore;
    } while (!isValidScore(newStudent.englishScore));
    
    do {
        cout << "请输入计算机成绩 (0-100)：";
        cin >> newStudent.computerScore;
    } while (!isValidScore(newStudent.computerScore));
    
    newStudent.calculateAverage();
    students.push_back(newStudent);
    
    cout << "学生信息添加成功！" << endl;
    cout << "学生平均分：" << fixed << setprecision(2) << newStudent.averageScore << endl;
    cout << "成绩等级：" << newStudent.getGrade() << endl;
}

// 显示所有学生
void StudentManagementSystem::displayAllStudents() {
    if (students.empty()) {
        cout << "没有学生信息！" << endl;
        return;
    }
    
    cout << "\n=== 所有学生信息 ===" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "ID\t姓名\t年龄\t专业\t\t数学\t英语\t计算机\t平均分\t等级" << endl;
    cout << "----------------------------------------------------------------" << endl;
    
    for (const auto& student : students) {
        cout << student.id << "\t" << student.name << "\t" << student.age << "\t"
             << student.major << "\t\t" << student.mathScore << "\t" << student.englishScore 
             << "\t" << student.computerScore << "\t" << fixed << setprecision(2) 
             << student.averageScore << "\t" << student.getGrade() << endl;
    }
    cout << "----------------------------------------------------------------" << endl;
    cout << "共 " << students.size() << " 名学生" << endl;
}

// 查找学生
void StudentManagementSystem::searchStudent() {
    if (students.empty()) {
        cout << "没有学生信息！" << endl;
        return;
    }
    
    int choice;
    cout << "\n=== 查找学生 ===" << endl;
    cout << "1. 按ID查找" << endl;
    cout << "2. 按姓名查找" << endl;
    cout << "请选择查找方式：";
    cin >> choice;
    
    switch (choice) {
        case 1: {
            int id;
            cout << "请输入学生ID：";
            cin >> id;
            
            int index = findStudentById(id);
            if (index != -1) {
                cout << "找到学生：" << endl;
                displayStudent(students[index]);
            } else {
                cout << "未找到ID为 " << id << " 的学生！" << endl;
            }
            break;
        }
        case 2: {
            string name;
            cout << "请输入学生姓名：";
            cin >> name;
            
            bool found = false;
            for (const auto& student : students) {
                if (student.name == name) {
                    if (!found) {
                        cout << "找到学生：" << endl;
                        found = true;
                    }
                    displayStudent(student);
                }
            }
            
            if (!found) {
                cout << "未找到姓名为 " << name << " 的学生！" << endl;
            }
            break;
        }
        default:
            cout << "无效选择！" << endl;
            break;
    }
}

// 更新学生信息
void StudentManagementSystem::updateStudent() {
    if (students.empty()) {
        cout << "没有学生信息！" << endl;
        return;
    }
    
    int id;
    cout << "\n=== 更新学生信息 ===" << endl;
    cout << "请输入要更新的学生ID：";
    cin >> id;
    
    int index = findStudentById(id);
    if (index == -1) {
        cout << "未找到ID为 " << id << " 的学生！" << endl;
        return;
    }
    
    Student& student = students[index];
    cout << "当前学生信息：" << endl;
    displayStudent(student);
    
    int choice;
    cout << "\n请选择要更新的信息：" << endl;
    cout << "1. 姓名" << endl;
    cout << "2. 年龄" << endl;
    cout << "3. 专业" << endl;
    cout << "4. 数学成绩" << endl;
    cout << "5. 英语成绩" << endl;
    cout << "6. 计算机成绩" << endl;
    cout << "7. 全部信息" << endl;
    cout << "请选择：";
    cin >> choice;
    
    switch (choice) {
        case 1:
            cout << "请输入新姓名：";
            cin >> student.name;
            break;
        case 2:
            cout << "请输入新年龄：";
            cin >> student.age;
            break;
        case 3:
            cout << "请输入新专业：";
            cin >> student.major;
            break;
        case 4:
            do {
                cout << "请输入新数学成绩：";
                cin >> student.mathScore;
            } while (!isValidScore(student.mathScore));
            student.calculateAverage();
            break;
        case 5:
            do {
                cout << "请输入新英语成绩：";
                cin >> student.englishScore;
            } while (!isValidScore(student.englishScore));
            student.calculateAverage();
            break;
        case 6:
            do {
                cout << "请输入新计算机成绩：";
                cin >> student.computerScore;
            } while (!isValidScore(student.computerScore));
            student.calculateAverage();
            break;
        case 7:
            cout << "请输入新姓名：";
            cin >> student.name;
            cout << "请输入新年龄：";
            cin >> student.age;
            cout << "请输入新专业：";
            cin >> student.major;
            do {
                cout << "请输入新数学成绩：";
                cin >> student.mathScore;
            } while (!isValidScore(student.mathScore));
            do {
                cout << "请输入新英语成绩：";
                cin >> student.englishScore;
            } while (!isValidScore(student.englishScore));
            do {
                cout << "请输入新计算机成绩：";
                cin >> student.computerScore;
            } while (!isValidScore(student.computerScore));
            student.calculateAverage();
            break;
        default:
            cout << "无效选择！" << endl;
            return;
    }
    
    cout << "学生信息更新成功！" << endl;
    cout << "更新后的信息：" << endl;
    displayStudent(student);
}

// 删除学生
void StudentManagementSystem::deleteStudent() {
    if (students.empty()) {
        cout << "没有学生信息！" << endl;
        return;
    }
    
    int id;
    cout << "\n=== 删除学生 ===" << endl;
    cout << "请输入要删除的学生ID：";
    cin >> id;
    
    int index = findStudentById(id);
    if (index == -1) {
        cout << "未找到ID为 " << id << " 的学生！" << endl;
        return;
    }
    
    cout << "要删除的学生信息：" << endl;
    displayStudent(students[index]);
    
    char confirm;
    cout << "确定要删除这名学生吗？(y/n)：";
    cin >> confirm;
    
    if (confirm == 'y' || confirm == 'Y') {
        students.erase(students.begin() + index);
        cout << "学生信息删除成功！" << endl;
    } else {
        cout << "取消删除操作。" << endl;
    }
}

// 计算统计信息
void StudentManagementSystem::calculateStatistics() {
    if (students.empty()) {
        cout << "没有学生信息！" << endl;
        return;
    }
    
    cout << "\n=== 成绩统计信息 ===" << endl;
    
    double totalMath = 0, totalEnglish = 0, totalComputer = 0, totalAverage = 0;
    double maxMath = students[0].mathScore, minMath = students[0].mathScore;
    double maxEnglish = students[0].englishScore, minEnglish = students[0].englishScore;
    double maxComputer = students[0].computerScore, minComputer = students[0].computerScore;
    double maxAverage = students[0].averageScore, minAverage = students[0].averageScore;
    
    int excellentCount = 0, goodCount = 0, averageCount = 0, passCount = 0, failCount = 0;
    
    for (const auto& student : students) {
        totalMath += student.mathScore;
        totalEnglish += student.englishScore;
        totalComputer += student.computerScore;
        totalAverage += student.averageScore;
        
        maxMath = max(maxMath, student.mathScore);
        minMath = min(minMath, student.mathScore);
        maxEnglish = max(maxEnglish, student.englishScore);
        minEnglish = min(minEnglish, student.englishScore);
        maxComputer = max(maxComputer, student.computerScore);
        minComputer = min(minComputer, student.computerScore);
        maxAverage = max(maxAverage, student.averageScore);
        minAverage = min(minAverage, student.averageScore);
        
        string grade = student.getGrade();
        if (grade == "优秀") excellentCount++;
        else if (grade == "良好") goodCount++;
        else if (grade == "中等") averageCount++;
        else if (grade == "及格") passCount++;
        else failCount++;
    }
    
    int totalStudents = students.size();
    
    cout << "学生总数：" << totalStudents << endl;
    cout << "----------------------------------------" << endl;
    cout << "各科平均分：" << endl;
    cout << "  数学：" << fixed << setprecision(2) << totalMath / totalStudents << endl;
    cout << "  英语：" << totalEnglish / totalStudents << endl;
    cout << "  计算机：" << totalComputer / totalStudents << endl;
    cout << "  总平均分：" << totalAverage / totalStudents << endl;
    
    cout << "----------------------------------------" << endl;
    cout << "各科最高分：" << endl;
    cout << "  数学：" << maxMath << endl;
    cout << "  英语：" << maxEnglish << endl;
    cout << "  计算机：" << maxComputer << endl;
    cout << "  平均分最高：" << maxAverage << endl;
    
    cout << "----------------------------------------" << endl;
    cout << "各科最低分：" << endl;
    cout << "  数学：" << minMath << endl;
    cout << "  英语：" << minEnglish << endl;
    cout << "  计算机：" << minComputer << endl;
    cout << "  平均分最低：" << minAverage << endl;
    
    cout << "----------------------------------------" << endl;
    cout << "成绩等级分布：" << endl;
    cout << "  优秀：" << excellentCount << " 人 (" << fixed << setprecision(1) 
         << (double)excellentCount / totalStudents * 100 << "%)" << endl;
    cout << "  良好：" << goodCount << " 人 (" << (double)goodCount / totalStudents * 100 << "%)" << endl;
    cout << "  中等：" << averageCount << " 人 (" << (double)averageCount / totalStudents * 100 << "%)" << endl;
    cout << "  及格：" << passCount << " 人 (" << (double)passCount / totalStudents * 100 << "%)" << endl;
    cout << "  不及格：" << failCount << " 人 (" << (double)failCount / totalStudents * 100 << "%)" << endl;
}

// 生成报表
void StudentManagementSystem::generateReport() {
    if (students.empty()) {
        cout << "没有学生信息！" << endl;
        return;
    }
    
    string filename;
    cout << "\n=== 生成成绩报表 ===" << endl;
    cout << "请输入报表文件名：";
    cin >> filename;
    
    ofstream reportFile(filename);
    if (!reportFile) {
        cout << "无法创建报表文件！" << endl;
        return;
    }
    
    reportFile << "学生成绩管理系统 - 成绩报表" << endl;
    reportFile << "生成时间：2024年1月1日" << endl;
    reportFile << "========================================" << endl << endl;
    
    reportFile << "学生成绩详细信息：" << endl;
    reportFile << "----------------------------------------------------------------" << endl;
    reportFile << "ID\t姓名\t年龄\t专业\t\t数学\t英语\t计算机\t平均分\t等级" << endl;
    reportFile << "----------------------------------------------------------------" << endl;
    
    for (const auto& student : students) {
        reportFile << student.id << "\t" << student.name << "\t" << student.age << "\t"
                  << student.major << "\t\t" << student.mathScore << "\t" << student.englishScore 
                  << "\t" << student.computerScore << "\t" << fixed << setprecision(2) 
                  << student.averageScore << "\t" << student.getGrade() << endl;
    }
    
    reportFile << "----------------------------------------------------------------" << endl;
    reportFile << "共 " << students.size() << " 名学生" << endl << endl;
    
    // 添加统计信息到报表
    double totalAverage = 0;
    for (const auto& student : students) {
        totalAverage += student.averageScore;
    }
    
    reportFile << "统计信息：" << endl;
    reportFile << "班级平均分：" << totalAverage / students.size() << endl;
    
    reportFile.close();
    cout << "成绩报表已生成：" << filename << endl;
}

// 保存到文件
void StudentManagementSystem::saveToFile() {
    ofstream file(dataFile);
    if (!file) return;
    
    for (const auto& student : students) {
        file << student.id << " " << student.name << " " << student.age << " "
             << student.major << " " << student.mathScore << " " << student.englishScore 
             << " " << student.computerScore << endl;
    }
    file.close();
}

// 从文件加载
void StudentManagementSystem::loadFromFile() {
    ifstream file(dataFile);
    if (!file) return;
    
    Student student;
    while (file >> student.id >> student.name >> student.age >> student.major 
           >> student.mathScore >> student.englishScore >> student.computerScore) {
        student.calculateAverage();
        students.push_back(student);
    }
    file.close();
}

// 按成绩排序
void StudentManagementSystem::sortByScore() {
    sort(students.begin(), students.end(), 
         [](const Student& a, const Student& b) {
             return a.averageScore > b.averageScore;
         });
    cout << "已按平均分降序排列！" << endl;
}

// 主菜单
void StudentManagementSystem::showMainMenu() {
    cout << "\n=== 学生成绩管理系统主菜单 ===" << endl;
    cout << "1. 添加学生信息" << endl;
    cout << "2. 显示所有学生" << endl;
    cout << "3. 查找学生" << endl;
    cout << "4. 更新学生信息" << endl;
    cout << "5. 删除学生" << endl;
    cout << "6. 成绩统计" << endl;
    cout << "7. 按成绩排序" << endl;
    cout << "8. 生成成绩报表" << endl;
    cout << "9. 退出系统" << endl;
    cout << "请选择功能 (1-9)：";
}

// 主程序运行
void StudentManagementSystem::run() {
    int choice;
    
    do {
        showMainMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAllStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: calculateStatistics(); break;
            case 7: sortByScore(); break;
            case 8: generateReport(); break;
            case 9: 
                cout << "感谢使用学生成绩管理系统！数据已自动保存。" << endl;
                break;
            default:
                cout << "无效选择，请重新输入！" << endl;
                break;
        }
        
    } while (choice != 9);
}

// 辅助函数实现
int StudentManagementSystem::findStudentById(int id) {
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}

void StudentManagementSystem::displayStudent(const Student& student) {
    cout << "ID：" << student.id << endl;
    cout << "姓名：" << student.name << endl;
    cout << "年龄：" << student.age << endl;
    cout << "专业：" << student.major << endl;
    cout << "数学成绩：" << student.mathScore << endl;
    cout << "英语成绩：" << student.englishScore << endl;
    cout << "计算机成绩：" << student.computerScore << endl;
    cout << "平均分：" << fixed << setprecision(2) << student.averageScore << endl;
    cout << "等级：" << student.getGrade() << endl;
    cout << "----------------------------" << endl;
}

bool StudentManagementSystem::isValidScore(double score) {
    if (score < 0 || score > 100) {
        cout << "错误：成绩必须在0-100之间！" << endl;
        return false;
    }
    return true;
}

/*
 * 项目总结：
 * 
 * 1. 项目特点：
 *    - 完整的CRUD操作
 *    - 数据持久化存储
 *    - 统计分析功能
 *    - 报表生成功能
 *    - 用户友好界面
 * 
 * 2. 技术要点：
 *    - 结构体和类的使用
 *    - 文件输入输出操作
 *    - STL容器和算法
 *    - 异常处理和数据验证
 *    - 菜单驱动程序设计
 * 
 * 3. 功能模块：
 *    - 学生信息管理
 *    - 成绩录入和修改
 *    - 数据查询和排序
 *    - 统计分析
 *    - 报表生成
 * 
 * 4. 扩展建议：
 *    - 添加更多科目
 *    - 支持班级管理
 *    - 图形化界面
 *    - 数据库存储
 */
