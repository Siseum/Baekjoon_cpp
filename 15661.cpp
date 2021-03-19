#include <iostream>
#include <algorithm>

using namespace std;

int N;
int Result = 1234567890;
int Stat[21][21];
bool Select[21];

void dfs(int Count, int Index)
{
	if (Count == N - 1)
		return;

	if (1 < Count && Count < N - 1)
	{
		int Tempt1 = 0;
		int Tempt2 = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i == j)
					continue;

				if (Select[i] && Select[j])
					Tempt1 += Stat[i][j];
				else if (Select[i] == false && Select[j] == false)
					Tempt2 += Stat[i][j];
			}
		}

		Result = min(Result, abs(Tempt1 - Tempt2));
	}

	for (int i = Index; i <= N; i++)
	{
		if (Select[i] == false)
		{
			Select[i] = true;
			dfs(Count + 1, i + 1);
			Select[i] = false;
		}
	}
}



int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> Stat[i][j];
		}
	}

	Select[1] = true;
	dfs(1,2);

	cout << Result;
}
