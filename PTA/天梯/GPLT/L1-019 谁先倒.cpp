#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tolA, tolB;
	cin >> tolA >> tolB;
	int N;
	cin >> N;

	int cupA = 0, cupB = 0;
	char loser = '\0';
	for (int i = 0; i < N; i++)
	{
		int Acall, Agesture, Bcall, Bgesture;
		cin >> Acall >> Agesture >> Bcall >> Bgesture;
		int sum = Acall + Bcall;
		bool Alose = (Agesture == sum);
		bool Blose = (Bgesture == sum);

		if (Alose ^ Blose)
		{
			if (Alose)
			{
				cupA++;
				if (cupA > tolA)
				{
					loser = 'A';
					break;
				}
			}
			else
			{
				cupB++;
				if (cupB > tolB)
				{
					loser = 'B';
					break;
				}
			}
		}
	}

	if (loser == 'A')
	{
		cout << "A" << "\n"
			 << cupB << "\n";
	}
	else if (loser == 'B')
	{
		cout << "B" << "\n"
			 << cupA << "\n";
	}

	return 0;
}