#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#define endl "\n"
using namespace std;

struct humanMap
{
	int num;
	string name;
	int population;
};

bool compareBypopulation(const humanMap &p1, const humanMap &p2)
{
	return p1.name[0] < p2.name[0];
}

int main()
{
	int N;
	cin >> N;
	string human[5001];
	for (int i = 0; i < N; i++)
	{
		cin >> human[i];
	}
	int M;
	cin >> M;
	string humanList[10001];
	int population[10001] = {0};
	int sum = 0, ave = 0;
	humanMap human_map[10001];
	for (int i = 0; i < M; i++)
	{
		cin >> humanList[i] >> population[i];
		human_map[i].num = i;
		human_map[i].name = humanList[i];
		human_map[i].population = population[i];
		sum += population[i];
	}
	ave = sum / M;
	sort(human_map, human_map + M, compareBypopulation);
	bool isPrinted = false;
	for (int i = 0; i < M; i++)
	{
		if (human_map[i].population > ave)
		{
			for (int j = 0; j < N; j++)
			{
				if (human_map[i].name == human[j])
				{
					break;
				}
				else if (j == N - 1)
				{
					cout << human_map[i].name << endl;
					isPrinted = true;
				}
			}
		}
	}
	if (!isPrinted)
	{
		cout << "Bing Mei You";
	}
}