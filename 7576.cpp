#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int M;
int N;
int arr[1000][1000];
bool visit[1000][1000];
queue<pair<int, int>>que;
queue<int>que_count;
int Count;

int ni[4] = { 1,-1,0,0 };
int nj[4] = { 0,0,1,-1 };

void bfs()
{
	while (!que.empty())
	{
		int t_i = que.front().first;
		int t_j = que.front().second;
		Count = que_count.front();

		que.pop();
		que_count.pop();

		for (int i = 0; i < 4; i++)
		{
			int nexti = t_i + ni[i];
			int nextj = t_j + nj[i];

			if (nexti >= 0 && nexti < N && nextj >= 0 && nextj < M 
				&& visit[nexti][nextj] == false && arr[nexti][nextj] == 0)
			{
				arr[nexti][nextj] = 1;
				visit[nexti][nextj] = true;
				que.push(pair<int, int>(nexti, nextj));
				que_count.push(Count + 1);
			}
		}

	}
}

bool Check()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)
				return false;
		}
	}
	return true;
}

int main()
{
	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
			{
				que.push(pair<int, int>(i, j));
				que_count.push(0);
				visit[i][j] = true;
			}
		}
	}

	bfs();

	bool is_ok = Check();

	if (is_ok)
		cout << Count;
	else
		cout << -1;

}
