#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Student {
    int num;
    char name[20];
    int score;
};

bool compare(const Student& a, const Student& b) {
    return a.score > b.score || (a.score == b.score && a.num < b.num);
}

int main() {
    vector<Student> students;
    Student temp;
    int count = 0;
    while (cin >> temp.name >> temp.score) {
        temp.num = count;
        students.push_back(temp);
        count++;
    }
    sort(students.begin(), students.end(), compare);
    for (const auto& student : students) {
        cout << student.name << " " << student.score << endl;
    }

    return 0;
}