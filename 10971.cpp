#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int map[10][10];
int Result = 1234567890;
vector<int> v;

void dfs(int Count)
{
	int tempt = 0;
	if (Count == N)
	{
		for (int i = 0; i < N; i++)
		{
			if (i == N - 1)
			{
				if (map[v[N - 1]][v[0]] == 0)
					return;

				tempt += map[v[i]][v[0]];
				break;
			}

			else if (map[v[i]][v[i + 1]] == 0)
				return;
			tempt += map[v[i]][v[i + 1]];
		}

		Result = min(Result, tempt);
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (find(v.begin(), v.end(), i) == v.end())
		{
			v.push_back(i);
			dfs(Count + 1);
			v.pop_back();
		}
	}

}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	dfs(0);

	cout << Result;
}
