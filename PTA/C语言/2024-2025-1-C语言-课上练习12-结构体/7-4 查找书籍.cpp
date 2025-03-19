	#include <bits/stdc++.h>
	#define endl "\n"
	using namespace std;

	struct Book
	{
		string title;
		double price;
	};

	bool judge(const Book &a,const Book &b)
	{
		if(a.price == b.price)
		{
			return a.title < b.title;
		}
		return a.price < b.price;
	}

	signed main()
	{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);cout.tie(nullptr);

		int n;
		cin>>n;
		cin.ignore();
		vector<Book> books(n);
		for(int i = 0;i<n;i++)
		{
			getline(cin,books[i].title);
			cin>>books[i].price;
			cin.ignore();
		}
		sort(books.begin(),books.end(),judge);
		printf("%.2f", books[n - 1].price);
		cout<< ", " << books[n - 1].title << "\n";
		printf("%.2f", books[0].price);
		cout<< ", " << books[0].title << "\n";
		return 0;
	}