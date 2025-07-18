/*
 * 第11天：结构体学习与实践
 * 学习内容：struct的定义和使用、结构体数组、结构体指针
 * 练习任务：定义学生信息结构体、管理多个学生的信息
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 结构体定义
struct Student {
    int id;
    string name;
    int age;
    double score;
    string major;
};

struct Point {
    double x;
    double y;
};

struct Rectangle {
    Point topLeft;
    Point bottomRight;
};

struct Book {
    string title;
    string author;
    int year;
    double price;
    bool available;
};

// 函数声明
void demonstrateStructBasics();
void demonstrateStructArrays();
void demonstrateStructPointers();
void studentManagementSystem();
void practiceExercises();

// 辅助函数
void printStudent(const Student& s);
void printStudentArray(const Student students[], int size);
double calculateDistance(const Point& p1, const Point& p2);
double calculateRectangleArea(const Rectangle& rect);

int main() {
    cout << "=== 第11天：结构体学习与实践 ===" << endl;
    cout << "今天我们将学习：" << endl;
    cout << "1. struct的定义和使用" << endl;
    cout << "2. 结构体数组" << endl;
    cout << "3. 结构体指针" << endl;
    cout << "4. 结构体的实际应用" << endl;
    cout << "================================" << endl << endl;

    // 1. 结构体基础演示
    cout << "1. 结构体基础演示：" << endl;
    demonstrateStructBasics();
    cout << endl;

    // 2. 结构体数组演示
    cout << "2. 结构体数组演示：" << endl;
    demonstrateStructArrays();
    cout << endl;

    // 3. 结构体指针演示
    cout << "3. 结构体指针演示：" << endl;
    demonstrateStructPointers();
    cout << endl;

    // 4. 实际应用练习
    cout << "4. 实际应用练习：" << endl;
    
    // 练习1：学生管理系统
    cout << "练习1：学生信息管理系统" << endl;
    studentManagementSystem();
    cout << endl;

    // 练习2：综合练习
    cout << "练习2：综合练习" << endl;
    practiceExercises();

    return 0;
}

// 结构体基础演示
void demonstrateStructBasics() {
    // 创建和初始化结构体
    Student student1;
    student1.id = 1001;
    student1.name = "张三";
    student1.age = 20;
    student1.score = 85.5;
    student1.major = "计算机科学";
    
    cout << "结构体基本使用：" << endl;
    printStudent(student1);
    
    // 结构体初始化列表
    Student student2 = {1002, "李四", 21, 92.0, "软件工程"};
    cout << "\n使用初始化列表：" << endl;
    printStudent(student2);
    
    // 结构体赋值
    Student student3 = student1;
    student3.name = "王五";
    student3.id = 1003;
    cout << "\n结构体赋值：" << endl;
    printStudent(student3);
    
    // 嵌套结构体
    Rectangle rect = {{0, 10}, {5, 0}};
    cout << "\n嵌套结构体（矩形）：" << endl;
    cout << "左上角：(" << rect.topLeft.x << ", " << rect.topLeft.y << ")" << endl;
    cout << "右下角：(" << rect.bottomRight.x << ", " << rect.bottomRight.y << ")" << endl;
    cout << "面积：" << calculateRectangleArea(rect) << endl;
    
    // 结构体比较（需要逐个成员比较）
    Point p1 = {3.0, 4.0};
    Point p2 = {3.0, 4.0};
    Point p3 = {1.0, 2.0};
    
    bool isEqual = (p1.x == p2.x && p1.y == p2.y);
    cout << "\n点(" << p1.x << ", " << p1.y << ")和点(" << p2.x << ", " << p2.y << ")";
    cout << (isEqual ? "相等" : "不相等") << endl;
    
    cout << "点p1到p3的距离：" << calculateDistance(p1, p3) << endl;
}

// 结构体数组演示
void demonstrateStructArrays() {
    // 结构体数组声明和初始化
    Student students[5] = {
        {1001, "张三", 20, 85.5, "计算机科学"},
        {1002, "李四", 21, 92.0, "软件工程"},
        {1003, "王五", 19, 78.5, "信息技术"},
        {1004, "赵六", 22, 88.0, "网络工程"},
        {1005, "钱七", 20, 95.5, "人工智能"}
    };
    
    cout << "学生信息列表：" << endl;
    printStudentArray(students, 5);
    
    // 查找最高分学生
    int maxIndex = 0;
    for (int i = 1; i < 5; i++) {
        if (students[i].score > students[maxIndex].score) {
            maxIndex = i;
        }
    }
    cout << "\n最高分学生：" << endl;
    printStudent(students[maxIndex]);
    
    // 计算平均分
    double totalScore = 0;
    for (int i = 0; i < 5; i++) {
        totalScore += students[i].score;
    }
    double averageScore = totalScore / 5;
    cout << "\n班级平均分：" << averageScore << endl;
    
    // 按分数排序（冒泡排序）
    cout << "\n按分数排序后：" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (students[j].score < students[j + 1].score) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printStudentArray(students, 5);
}

// 结构体指针演示
void demonstrateStructPointers() {
    Student student = {1001, "张三", 20, 85.5, "计算机科学"};
    Student* ptr = &student;
    
    cout << "结构体指针使用：" << endl;
    cout << "通过指针访问成员：" << endl;
    cout << "ID: " << ptr->id << endl;
    cout << "姓名: " << ptr->name << endl;
    cout << "年龄: " << (*ptr).age << endl;  // 另一种访问方式
    cout << "分数: " << ptr->score << endl;
    cout << "专业: " << ptr->major << endl;
    
    // 通过指针修改结构体
    ptr->score = 90.0;
    ptr->age = 21;
    cout << "\n修改后的学生信息：" << endl;
    printStudent(student);
    
    // 动态分配结构体内存
    Student* dynamicStudent = new Student;
    dynamicStudent->id = 2001;
    dynamicStudent->name = "李四";
    dynamicStudent->age = 22;
    dynamicStudent->score = 88.0;
    dynamicStudent->major = "数据科学";
    
    cout << "\n动态分配的学生信息：" << endl;
    printStudent(*dynamicStudent);
    
    delete dynamicStudent;  // 释放内存
    
    // 结构体指针数组
    Student s1 = {3001, "王五", 19, 92.5, "软件工程"};
    Student s2 = {3002, "赵六", 20, 87.0, "计算机科学"};
    Student s3 = {3003, "钱七", 21, 94.5, "人工智能"};
    
    Student* studentPtrs[3] = {&s1, &s2, &s3};
    
    cout << "\n通过指针数组访问学生信息：" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "学生" << (i + 1) << ": " << studentPtrs[i]->name 
             << ", 分数: " << studentPtrs[i]->score << endl;
    }
}

// 练习1：学生管理系统
void studentManagementSystem() {
    vector<Student> students;
    int choice;
    
    do {
        cout << "\n=== 学生管理系统 ===" << endl;
        cout << "1. 添加学生" << endl;
        cout << "2. 显示所有学生" << endl;
        cout << "3. 查找学生" << endl;
        cout << "4. 修改学生信息" << endl;
        cout << "5. 删除学生" << endl;
        cout << "6. 统计信息" << endl;
        cout << "0. 退出" << endl;
        cout << "请选择操作：";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                Student newStudent;
                cout << "请输入学生信息：" << endl;
                cout << "ID: ";
                cin >> newStudent.id;
                cout << "姓名: ";
                cin >> newStudent.name;
                cout << "年龄: ";
                cin >> newStudent.age;
                cout << "分数: ";
                cin >> newStudent.score;
                cout << "专业: ";
                cin >> newStudent.major;
                
                students.push_back(newStudent);
                cout << "学生添加成功！" << endl;
                break;
            }
            case 2: {
                if (students.empty()) {
                    cout << "没有学生信息！" << endl;
                } else {
                    cout << "\n所有学生信息：" << endl;
                    for (size_t i = 0; i < students.size(); i++) {
                        cout << "学生" << (i + 1) << ": ";
                        printStudent(students[i]);
                    }
                }
                break;
            }
            case 3: {
                int searchId;
                cout << "请输入要查找的学生ID: ";
                cin >> searchId;
                
                bool found = false;
                for (const auto& student : students) {
                    if (student.id == searchId) {
                        cout << "找到学生：" << endl;
                        printStudent(student);
                        found = true;
                        break;
                    }
                }
                
                if (!found) {
                    cout << "未找到ID为 " << searchId << " 的学生！" << endl;
                }
                break;
            }
            case 4: {
                int modifyId;
                cout << "请输入要修改的学生ID: ";
                cin >> modifyId;
                
                bool found = false;
                for (auto& student : students) {
                    if (student.id == modifyId) {
                        cout << "当前学生信息：" << endl;
                        printStudent(student);
                        
                        cout << "请输入新的信息：" << endl;
                        cout << "姓名: ";
                        cin >> student.name;
                        cout << "年龄: ";
                        cin >> student.age;
                        cout << "分数: ";
                        cin >> student.score;
                        cout << "专业: ";
                        cin >> student.major;
                        
                        cout << "学生信息修改成功！" << endl;
                        found = true;
                        break;
                    }
                }
                
                if (!found) {
                    cout << "未找到ID为 " << modifyId << " 的学生！" << endl;
                }
                break;
            }
            case 5: {
                int deleteId;
                cout << "请输入要删除的学生ID: ";
                cin >> deleteId;
                
                auto it = students.begin();
                bool found = false;
                while (it != students.end()) {
                    if (it->id == deleteId) {
                        cout << "删除学生：" << it->name << endl;
                        students.erase(it);
                        found = true;
                        break;
                    }
                    ++it;
                }
                
                if (!found) {
                    cout << "未找到ID为 " << deleteId << " 的学生！" << endl;
                } else {
                    cout << "学生删除成功！" << endl;
                }
                break;
            }
            case 6: {
                if (students.empty()) {
                    cout << "没有学生信息！" << endl;
                } else {
                    double totalScore = 0;
                    double maxScore = students[0].score;
                    double minScore = students[0].score;
                    
                    for (const auto& student : students) {
                        totalScore += student.score;
                        if (student.score > maxScore) maxScore = student.score;
                        if (student.score < minScore) minScore = student.score;
                    }
                    
                    cout << "\n统计信息：" << endl;
                    cout << "学生总数：" << students.size() << endl;
                    cout << "平均分：" << totalScore / students.size() << endl;
                    cout << "最高分：" << maxScore << endl;
                    cout << "最低分：" << minScore << endl;
                }
                break;
            }
            case 0:
                cout << "感谢使用学生管理系统！" << endl;
                break;
            default:
                cout << "无效选择，请重新输入！" << endl;
                break;
        }
    } while (choice != 0);
}

// 综合练习
void practiceExercises() {
    // 练习1：图书管理
    cout << "练习1：图书管理系统" << endl;
    
    Book library[3] = {
        {"C++ Primer", "Stanley Lippman", 2012, 89.99, true},
        {"Effective C++", "Scott Meyers", 2005, 59.99, false},
        {"The C++ Programming Language", "Bjarne Stroustrup", 2013, 79.99, true}
    };
    
    cout << "图书馆藏书：" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "书名：" << library[i].title << endl;
        cout << "作者：" << library[i].author << endl;
        cout << "年份：" << library[i].year << endl;
        cout << "价格：$" << library[i].price << endl;
        cout << "状态：" << (library[i].available ? "可借" : "已借出") << endl;
        cout << "-------------------" << endl;
    }
    
    // 练习2：几何计算
    cout << "\n练习2：几何图形计算" << endl;
    
    Point points[4] = {{0, 0}, {3, 0}, {3, 4}, {0, 4}};
    
    cout << "四个点的坐标：" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "点" << (i + 1) << ": (" << points[i].x << ", " << points[i].y << ")" << endl;
    }
    
    // 计算周长
    double perimeter = 0;
    for (int i = 0; i < 4; i++) {
        int next = (i + 1) % 4;
        perimeter += calculateDistance(points[i], points[next]);
    }
    cout << "四边形周长：" << perimeter << endl;
}

// 辅助函数实现
void printStudent(const Student& s) {
    cout << "ID: " << s.id << ", 姓名: " << s.name << ", 年龄: " << s.age 
         << ", 分数: " << s.score << ", 专业: " << s.major << endl;
}

void printStudentArray(const Student students[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "学生" << (i + 1) << ": ";
        printStudent(students[i]);
    }
}

double calculateDistance(const Point& p1, const Point& p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

double calculateRectangleArea(const Rectangle& rect) {
    double width = abs(rect.bottomRight.x - rect.topLeft.x);
    double height = abs(rect.topLeft.y - rect.bottomRight.y);
    return width * height;
}

/*
 * 学习要点总结：
 * 
 * 1. 结构体定义：
 *    - 使用struct关键字定义
 *    - 可以包含不同类型的成员
 *    - 成员默认是public的
 * 
 * 2. 结构体使用：
 *    - 使用.操作符访问成员
 *    - 可以整体赋值
 *    - 支持初始化列表
 * 
 * 3. 结构体数组：
 *    - 可以创建结构体数组
 *    - 适合管理同类型的多个对象
 * 
 * 4. 结构体指针：
 *    - 使用->操作符访问成员
 *    - 支持动态内存分配
 *    - 可以创建指针数组
 * 
 * 5. 实践技巧：
 *    - 结构体适合表示相关数据的集合
 *    - 可以嵌套使用结构体
 *    - 注意内存管理（动态分配时）
 *    - 合理设计结构体成员
 */
