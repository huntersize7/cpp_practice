/*
 * 第6天：数组基础学习与实践
 * 学习内容：一维数组的声明和初始化、数组元素的访问和修改、数组的遍历
 * 练习任务：找出数组中的最大值和最小值、实现数组排序(冒泡排序)
 */

#include <iostream>
#include <iomanip>
using namespace std;

// 函数声明
void demonstrateArrayBasics();
void demonstrateArrayInitialization();
void demonstrateArrayTraversal();
void findMinMax();
void bubbleSort();
void practiceExercises();

int main() {
    cout << "=== 第6天：数组基础学习与实践 ===" << endl;
    cout << "今天我们将学习：" << endl;
    cout << "1. 数组的声明和初始化" << endl;
    cout << "2. 数组元素的访问和修改" << endl;
    cout << "3. 数组的遍历" << endl;
    cout << "4. 数组的实际应用" << endl;
    cout << "================================" << endl << endl;

    // 1. 数组基础演示
    cout << "1. 数组基础演示：" << endl;
    demonstrateArrayBasics();
    cout << endl;

    // 2. 数组初始化演示
    cout << "2. 数组初始化演示：" << endl;
    demonstrateArrayInitialization();
    cout << endl;

    // 3. 数组遍历演示
    cout << "3. 数组遍历演示：" << endl;
    demonstrateArrayTraversal();
    cout << endl;

    // 4. 实际应用练习
    cout << "4. 实际应用练习：" << endl;
    
    // 练习1：找最大值和最小值
    cout << "练习1：找出数组中的最大值和最小值" << endl;
    findMinMax();
    cout << endl;

    // 练习2：冒泡排序
    cout << "练习2：冒泡排序实现" << endl;
    bubbleSort();
    cout << endl;

    // 练习3：综合练习
    cout << "练习3：综合练习" << endl;
    practiceExercises();

    return 0;
}

// 数组基础演示
void demonstrateArrayBasics() {
    // 数组声明和基本使用
    int numbers[5]; // 声明一个包含5个整数的数组
    
    // 给数组元素赋值
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    numbers[3] = 40;
    numbers[4] = 50;
    
    cout << "数组元素访问：" << endl;
    cout << "numbers[0] = " << numbers[0] << endl;
    cout << "numbers[1] = " << numbers[1] << endl;
    cout << "numbers[2] = " << numbers[2] << endl;
    cout << "numbers[3] = " << numbers[3] << endl;
    cout << "numbers[4] = " << numbers[4] << endl;
    
    // 修改数组元素
    cout << "\n修改数组元素：" << endl;
    numbers[2] = 35;
    cout << "修改后 numbers[2] = " << numbers[2] << endl;
    
    // 数组大小
    cout << "\n数组信息：" << endl;
    cout << "数组大小：" << sizeof(numbers) << " 字节" << endl;
    cout << "数组元素个数：" << sizeof(numbers) / sizeof(numbers[0]) << endl;
}

// 数组初始化演示
void demonstrateArrayInitialization() {
    // 方法1：声明时初始化
    int arr1[5] = {1, 2, 3, 4, 5};
    cout << "方法1 - 完全初始化：";
    for (int i = 0; i < 5; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    // 方法2：部分初始化
    int arr2[5] = {1, 2, 3}; // 剩余元素自动初始化为0
    cout << "方法2 - 部分初始化：";
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    // 方法3：全部初始化为0
    int arr3[5] = {0}; // 或者 = {}
    cout << "方法3 - 全部初始化为0：";
    for (int i = 0; i < 5; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;
    
    // 方法4：自动推导大小
    int arr4[] = {10, 20, 30, 40, 50, 60}; // 编译器自动确定大小为6
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    cout << "方法4 - 自动推导大小（大小为" << size4 << "）：";
    for (int i = 0; i < size4; i++) {
        cout << arr4[i] << " ";
    }
    cout << endl;
    
    // 字符数组
    char str1[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char str2[] = "World"; // 自动添加'\0'
    cout << "字符数组1：" << str1 << endl;
    cout << "字符数组2：" << str2 << endl;
}

// 数组遍历演示
void demonstrateArrayTraversal() {
    int scores[8] = {85, 92, 78, 96, 88, 76, 94, 82};
    int size = sizeof(scores) / sizeof(scores[0]);
    
    // 方法1：使用for循环遍历
    cout << "方法1 - for循环遍历：";
    for (int i = 0; i < size; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;
    
    // 方法2：使用while循环遍历
    cout << "方法2 - while循环遍历：";
    int i = 0;
    while (i < size) {
        cout << scores[i] << " ";
        i++;
    }
    cout << endl;
    
    // 方法3：范围for循环（C++11）
    cout << "方法3 - 范围for循环：";
    for (int score : scores) {
        cout << score << " ";
    }
    cout << endl;
    
    // 倒序遍历
    cout << "倒序遍历：";
    for (int i = size - 1; i >= 0; i--) {
        cout << scores[i] << " ";
    }
    cout << endl;
    
    // 计算数组统计信息
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    double average = (double)sum / size;
    cout << "数组统计：总和=" << sum << ", 平均值=" << fixed << setprecision(2) << average << endl;
}

// 练习1：找最大值和最小值
void findMinMax() {
    int numbers[] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    cout << "原始数组：";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    // 找最大值和最小值
    int max = numbers[0];
    int min = numbers[0];
    int maxIndex = 0;
    int minIndex = 0;
    
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
            maxIndex = i;
        }
        if (numbers[i] < min) {
            min = numbers[i];
            minIndex = i;
        }
    }
    
    cout << "最大值：" << max << "（位置：" << maxIndex << "）" << endl;
    cout << "最小值：" << min << "（位置：" << minIndex << "）" << endl;
    
    // 找第二大的数
    int secondMax = (numbers[0] == max) ? numbers[1] : numbers[0];
    for (int i = 0; i < size; i++) {
        if (numbers[i] > secondMax && numbers[i] < max) {
            secondMax = numbers[i];
        }
    }
    cout << "第二大的数：" << secondMax << endl;
}

// 练习2：冒泡排序
void bubbleSort() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "排序前：";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // 冒泡排序实现
    cout << "\n冒泡排序过程：" << endl;
    for (int i = 0; i < size - 1; i++) {
        cout << "第" << (i + 1) << "轮：";
        bool swapped = false;
        
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换元素
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        
        // 显示每轮结果
        for (int k = 0; k < size; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
        
        // 如果没有交换，说明已经排序完成
        if (!swapped) {
            cout << "提前完成排序！" << endl;
            break;
        }
    }
    
    cout << "\n排序后：";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 练习3：综合练习
void practiceExercises() {
    // 练习1：数组反转
    cout << "练习1：数组反转" << endl;
    int original[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(original) / sizeof(original[0]);
    
    cout << "原数组：";
    for (int i = 0; i < size; i++) {
        cout << original[i] << " ";
    }
    cout << endl;
    
    // 反转数组
    for (int i = 0; i < size / 2; i++) {
        int temp = original[i];
        original[i] = original[size - 1 - i];
        original[size - 1 - i] = temp;
    }
    
    cout << "反转后：";
    for (int i = 0; i < size; i++) {
        cout << original[i] << " ";
    }
    cout << endl;
    
    // 练习2：查找元素
    cout << "\n练习2：查找元素" << endl;
    int searchArray[] = {10, 25, 30, 45, 50, 65, 70, 85, 90};
    int searchSize = sizeof(searchArray) / sizeof(searchArray[0]);
    int target = 45;
    
    cout << "在数组中查找元素 " << target << "：";
    for (int i = 0; i < searchSize; i++) {
        cout << searchArray[i] << " ";
    }
    cout << endl;
    
    bool found = false;
    int position = -1;
    for (int i = 0; i < searchSize; i++) {
        if (searchArray[i] == target) {
            found = true;
            position = i;
            break;
        }
    }
    
    if (found) {
        cout << "找到了！元素 " << target << " 在位置 " << position << endl;
    } else {
        cout << "未找到元素 " << target << endl;
    }
    
    // 练习3：统计数组中各数字出现的次数
    cout << "\n练习3：统计数字出现次数" << endl;
    int countArray[] = {1, 2, 3, 2, 1, 3, 4, 2, 1, 5, 3, 2};
    int countSize = sizeof(countArray) / sizeof(countArray[0]);
    
    cout << "原数组：";
    for (int i = 0; i < countSize; i++) {
        cout << countArray[i] << " ";
    }
    cout << endl;
    
    // 找出数组中的最大值，用于确定计数数组大小
    int maxVal = countArray[0];
    for (int i = 1; i < countSize; i++) {
        if (countArray[i] > maxVal) {
            maxVal = countArray[i];
        }
    }
    
    // 创建计数数组
    int count[10] = {0}; // 假设数字不超过9
    for (int i = 0; i < countSize; i++) {
        if (countArray[i] <= 9) {
            count[countArray[i]]++;
        }
    }
    
    cout << "各数字出现次数：" << endl;
    for (int i = 1; i <= maxVal; i++) {
        if (count[i] > 0) {
            cout << "数字 " << i << " 出现 " << count[i] << " 次" << endl;
        }
    }
}

/*
 * 学习要点总结：
 * 
 * 1. 数组声明：
 *    - 语法：数据类型 数组名[大小];
 *    - 数组大小必须是常量
 *    - 数组下标从0开始
 * 
 * 2. 数组初始化：
 *    - 声明时初始化：int arr[5] = {1,2,3,4,5};
 *    - 部分初始化：int arr[5] = {1,2}; // 其余为0
 *    - 自动推导大小：int arr[] = {1,2,3};
 * 
 * 3. 数组访问：
 *    - 使用下标访问：arr[index]
 *    - 注意数组边界，避免越界访问
 * 
 * 4. 数组遍历：
 *    - for循环是最常用的方式
 *    - 可以使用范围for循环（C++11）
 * 
 * 5. 实践技巧：
 *    - 使用sizeof计算数组大小
 *    - 数组作为函数参数时会退化为指针
 *    - 注意数组边界检查
 *    - 合理使用数组解决实际问题
 */
