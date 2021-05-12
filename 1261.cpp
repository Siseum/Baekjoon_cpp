#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int M;
const int Max = 1234567890;

queue<pair<int, int>> que;

char arr[101][101];
int Count[101][101];

int ni[4] = { -1,1,0,0 };
int nj[4] = { 0,0,-1,1 };

void bfs()
{
	while (!que.empty())
	{
		int t_i = que.front().first;
		int t_j = que.front().second;
		
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int nexti = t_i + ni[i];
			int nextj = t_j + nj[i];

			if (nexti > 0 && nexti <= N && nextj > 0 && nextj <= M)
			{
				if (arr[nexti][nextj] == '1')
				{
					if (Count[nexti][nextj] > Count[t_i][t_j] + 1)
					{
						Count[nexti][nextj] = Count[t_i][t_j] + 1;
						que.push({ nexti,nextj });
					}
				}
				else if (arr[nexti][nextj] == '0')
				{
					if (Count[nexti][nextj] > Count[t_i][t_j])
					{
						Count[nexti][nextj] = Count[t_i][t_j];
						que.push({ nexti,nextj });
					}
				}
			}
		}
	}
}

int main()
{
	cin >> M >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
			Count[i][j] = Max;
		}
	}

	que.push({ 1,1 });
	Count[1][1] = 0;

	bfs();

	cout << Count[N][M];
}
