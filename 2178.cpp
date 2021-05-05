#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int M;
int Result;
char arr[101][101];
bool visit[101][101];
int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };
queue<pair<int, int>> q;
queue<int> q_count;

int bfs()
{
	q.push(pair<int,int>(1, 1));
	q_count.push(1);

	while (!q.empty())
	{
		int t_i = q.front().first;
		int t_j = q.front().second;
		int Count = q_count.front();

		if (t_i == N && t_j == M)
		{
			return Count;
		}

		q.pop();
		q_count.pop();

		for (int i = 0; i < 4; i++)
		{
			int ni = t_i + di[i];
			int nj = t_j + dj[i];
			if (ni <= 0 || ni > N || nj <= 0 || nj > M)
				continue;
			if (arr[ni][nj] == '1' && !visit[ni][nj])
			{
				visit[ni][nj] = true;
				q.push(pair<int, int>(ni, nj));
				q_count.push(Count + 1);
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
	}

	visit[1][1] = true;
	Result = bfs();

	cout << Result;
}
