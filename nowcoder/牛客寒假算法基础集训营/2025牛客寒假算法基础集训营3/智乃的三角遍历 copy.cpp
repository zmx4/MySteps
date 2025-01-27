#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	if(n==1)
	{
		cout << "Yes" << endl<< "1 3 2 1" << endl;
	}
	else if(n==2)
	{
		cout << "Yes" << endl << "1 3 6 5 2 4 5 3 2 1" << endl;
	}
	/*
	else if(n==3)
	{
		cout<< "Yes" << "1 3 6 10 9 8 7 4 2 1" <<endl;
	}
	else if(n==4)
	{
		cout << "Yes" << "1 3 6 10 15 14 13 12 11 7 4 2 1" << endl;
	}
	else if(n==5)
	{
		cout << "Yes" << "1 3 6 10 15 21 20 19 18 17 16 11 7 4 2 1" << endl;
	}
	*/
	else if(n == 3)
	{
		cout << "Yes" << endl << "1 3 6 10 9 8 7 4 8 5 9 6 5 4 2 5 3 2 1" << endl;
	}
	else if(n == 4)
	{
		cout << "Yes" << endl<< "1 3 6 10 15 14 13 12 11 7 12 8 13 9 14 10 9 8 7 4 8 5 9 6 5 4 2 5 3 2 1" << endl;
	}
	else if(n == 5)
	{
		cout << "Yes" << endl<< "1 3 6 10 15 21 20 19 18 17 16 11 17 12 18 13 19 14 20 15 14 13 12 11 7 12 8 13 9 14 10 9 8 7 4 8 5 9 6 5 4 2 5 3 2 1" << endl;
	}
	else if(n == 6)
	{
		cout << "Yes" << endl<< "1 3 6 10 15 21 28 27 26 25 24 23 22 16 23 17 24 18 25 19 26 20 27 21 20 19 18 17 16 11 17 12 18 13 19 14 20 15 14 13 12 11 7 12 8 13 9 14 10 9 8 7 4 8 5 9 6 5 4 2 5 3 2 1" << endl;
	}
	else if(n == 7)
	{
		cout << "Yes" << endl<< "1 3 6 10 15 21 28 36 35 34 33 32 31 30 29 22 30 23 31 24 32 25 33 26 34 27 35 28 27 26 25 24 23 22 16 23 17 24 18 25 19 26 20 27 21 20 19 18 17 16 11 17 12 18 13 19 14 20 15 14 13 12 11 7 12 8 13 9 14 10 9 8 7 4 8 5 9 6 5 4 2 5 3 2 1" << endl;
	}

	return 0;
}