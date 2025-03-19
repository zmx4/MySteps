#include <bits/stdc++.h>
using namespace std;

int main() {
    int qwe;
    cin >> qwe;
    cin.ignore(); // 清除缓冲区中的换行符

    while (qwe--) {
        int n;
        cin >> n;
        cin.ignore(); // 清除缓冲区中的换行符

        string forbiddenWords[110];
        for (int i = 0; i < n; i++) {
            getline(cin, forbiddenWords[i]);
        }

        int m;
        cin >> m;
        if (m == 0) {
            cout << 0 << endl << "YLSZJJFJQ" << endl;
        } else {
            cin.ignore(); // 清除缓冲区中的换行符
            string s;
            getline(cin, s);

            int cnt = 0;
            for (int i = 0; i < n; i++) {
                string word = forbiddenWords[i];
                size_t pos = 0;
                while ((pos = s.find(word, pos)) != string::npos) {
                    cnt++;
                    s.replace(pos, word.length(), "-_-");
                    pos += 3; // 跳过刚插入的 "-_-"，防止重复匹配
                }
            }

            if (cnt >= m) {
                cout << cnt << endl << "YLSZJJFJQ" << endl;
            } else {
                size_t pos = 0; // 声明 pos 变量
                while ((pos = s.find("-_-")) != string::npos) {
                    s.replace(pos, 3, "<censored>");
                }
                cout << s << endl;
            }
        }
    }

    return 0;
}