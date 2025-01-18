#include <iostream>
#include <string>
using namespace std;

int main() {
    int a[31][31] = {0};
    int X, Y;
    cin >> X >> Y;
    cin.ignore();

    string b;
    for (int x = 1; x <= X; x++) 
    {
        getline(cin, b);
        for (int y = 1; y <= Y; y++) 
        {
            if (b[y - 1] == '.') a[x][y] = 0;
            else if (b[y - 1] == '*') a[x][y] = 1;
        }
    }

    for (int x = 1; x <= X; x++) 
    {
        for (int y = 1; y <= Y; y++) 
        {
            if(a[x][y]==1)continue;
            
        }
        cout << endl;
    }

    return 0;
}