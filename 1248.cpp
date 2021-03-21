#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
char Sign[10][10];
vector<int> V;

bool Check(int Index)
{
	int Sum = 0;

	for (int i = Index; i >= 0; i--)
	{
		Sum += V[i];

		if (Sign[i][Index] == '+' && Sum <= 0) return false;
		if (Sign[i][Index] == '-' && Sum >= 0) return false;
		if (Sign[i][Index] == '0' && Sum != 0) return false;
	}

	return true;
}


void dfs(int Count)
{
	if (Count == N)
	{
		for (int i = 0; i < N; i++)
		{
			cout << V[i] << ' ';
		}

		exit(0);
	}

	for (int i = -10; i <= 10; i++)
	{
		V.push_back(i);
		if (Check(Count))
		{
			dfs(Count + 1);
		}
		V.pop_back();
	}
}


int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
			cin >> Sign[i][j];
	}

	dfs(0);
}
