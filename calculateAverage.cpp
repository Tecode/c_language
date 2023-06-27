//
// Created by 昊轩 on 2023/6/27.
//

#include <iostream>
#include <vector>

// 求平均值的函数
double calculateAverage(const std::vector<double>& values) {
    double sum = 0.0;
    for (size_t i = 0; i < values.size(); ++i) {
        sum += values[i];
    }
    return sum / values.size();
}

int main() {
    std::vector<std::string> studentNames;
    std::vector<double> scores1, scores2, scores3;

    // 输入学生姓名和成绩
    int numStudents;
    std::cout << "请输入学生人数：";
    std::cin >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        std::string name;
        double score1, score2, score3;

        std::cout << "请输入第 " << i + 1 << " 名学生的姓名：";
        std::cin >> name;
        studentNames.push_back(name);

        std::cout << "请输入该学生的三门课程成绩（用空格分隔）：";
        std::cin >> score1 >> score2 >> score3;
        scores1.push_back(score1);
        scores2.push_back(score2);
        scores3.push_back(score3);
    }

    // 计算每个学生的平均分并输出
    std::cout << "\n每个学生的平均分：" << std::endl;
    for (int i = 0; i < numStudents; ++i) {
        std::vector<double> studentScores;
        studentScores.push_back(scores1[i]);
        studentScores.push_back(scores2[i]);
        studentScores.push_back(scores3[i]);

        double average = calculateAverage(studentScores);
        std::cout << studentNames[i] << " 的平均分是：" << average << std::endl;
    }

    // 计算每门课程的平均分并输出
    double averageScore1 = calculateAverage(scores1);
    double averageScore2 = calculateAverage(scores2);
    double averageScore3 = calculateAverage(scores3);

    std::cout << "\n每门课程的平均分：" << std::endl;
    std::cout << "第一门课程的平均分是：" << averageScore1 << std::endl;
    std::cout << "第二门课程的平均分是：" << averageScore2 << std::endl;
    std::cout << "第三门课程的平均分是：" << averageScore3 << std::endl;

    return 0;
}

