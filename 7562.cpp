#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>

using namespace std;

int L;
int s_i;
int s_j;
int e_i;
int e_j;
int Count;
queue<pair<int, int>>que;
queue<int>que_count;
bool visit[300][300];

int ni[8] = { 2,2,1,-1,-2,-2,-1,1 };
int nj[8] = { 1,-1,-2,-2,-1,1,2,2 };

void bfs()
{
	while (!que.empty())
	{
		int t_i = que.front().first;
		int t_j = que.front().second;
		Count = que_count.front();

		que.pop();
		que_count.pop();

		if (t_i == e_i && t_j == e_j)
		{
			while (!que.empty())
			{
				que.pop();
				que_count.pop();
			}
			return;
		}

		for (int i = 0; i < 8; i++)
		{
			int nexti = t_i + ni[i];
			int nextj = t_j + nj[i];

			if (nexti >= 0 && nexti < L && nextj >= 0 && nextj < L 
				&& visit[nexti][nextj] == false)
			{
				visit[nexti][nextj] = true;
				que.push(pair<int, int>(nexti, nextj));
				que_count.push(Count + 1);
			}
		}

	}
}

int main()
{
	int T = 0;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> L;
		cin >> s_i >> s_j;
		cin >> e_i >> e_j;

		memset(visit, false, sizeof(visit));

		que.push(pair<int, int>(s_i, s_j));
		que_count.push(0);
		visit[s_i][s_j] = true;

		bfs();

		cout << Count << "\n";
	}
}

