#include <bits/stdc++.h>
using namespace std;

int main()
{
    int M, N; cin >> M >> N;

	int cnt = 0;
	int MH;
    for(int i = 0;i < M;i+=1)
    {
		//if (N - (cnt * 2) <= 0)break;
	    for(int j = 0;j <= N;j +=2)
	    {
			if (j + 2 > N)break;
			//cout << i << " " << j << endl;
			cnt++;
			MH = j + 2;
	    }
    }
	//cout << N - (cnt * 2) << endl;
	//if(N-(cnt*2)>=0)
	//cout << MH;
	if(N-MH>0)
	{
		/*
		cout << "qwq";
		for(int i = 0;i < N;i+=2)
		{
			//cout << i + 2;
			if (i + 2 > N)break;
			cnt++;
		}
		*/
		//cout << M / 2;
		cnt += M / 2;
	}

	cout << cnt;
}
