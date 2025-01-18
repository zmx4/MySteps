
#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	int N; //朋友圈个数（多少个朋友圈） 
	int M;//朋友圈人数 （一个人的朋友圈里有几个人） 
	int x;//ID 
	int a[100001] = {0};//初始化每个人都没有朋友  0表示没朋友，1表示有朋友 
	cin >> N;
	for(int i = 0; i < N; i++) {//给有朋友的人赋值1 
		cin >> M;
		for(int j = 0; j < M; j++) {
			cin >> x;
			if(M != 1) { //判断这个朋友圈是不是就一个人，不是一个人才给赋值1表示这个朋友圈里的人有朋友，否则不赋值。
				a[x] = 1;
			}
		}
	}	
	int K;//查询人数
	int y;//查询人ID
	int t = 0; //记录有几个人没朋友 
	cin >> K; 
	for(int p = 0; p < K; p++) {//边查询边判断，没朋友直接输出ID。
		cin >> y;
		if(a[y] != 1) {//不等于1表示没朋友 
			if(t == 0) {
				cout << setw(5) << setfill('0') << y;
				t++;			
			} else {
				cout << " " << setw(5) << setfill('0') << y;
				t++;//也可以省略 ，省略后t不表示记录没朋友人数 
			}
			a[y] = 1;//没朋友的人输出完ID，都变成 “有朋友的人”，以防止下次查询二次打印
		}
	}
	if(t == 0) {//t=0表示都没朋友 
		cout << "No one is handsome";
	}
 
	return 0;
}
#include <iostream>

using namespace std;
int main()
{
    int N; cin >> N;
    int M;
    int x;
    int a[100000] = { 0 }, b[100000] = { 0 };
    for (int i = 0; i < N; i++) {
        cin >> M;
        for (int j = 0; j < M; j++) {
            cin >> x;
            if (M != 1) { 
                a[x] = 1;
            }
        }
    }
    cin >> N;
    int sign = 0;
    if(N!=1){
        while (N--)
        {
        int f; cin >> f;
        if (a[f] == 0 && b[f] == 0)
        {
            printf("%05d",f);
            if (N != 1)cout << " ";
            a[f]++;
            sign += 1;
        }
        }
    }
    if(N==1)
    {
        int f; cin >> f;
        if (a[f] == 0 && b[f] == 0)
        {
            printf("%05d",f);
            //if (N != 1)cout << " ";
            a[f]++;
            sign += 1;
        }
    }
    if (sign == 0)cout << "No one is handsome";
}