#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int K;
queue<pair<int,int>> q;
bool visit[100001];
int Count;

void bfs()
{
	while (!q.empty())
	{
		int tempt = q.front().first;
		Count = q.front().second;

		q.pop();

		if (tempt == K)
			return;

		if (tempt * 2 <= 100000 && visit[tempt * 2] == false)
		{
			visit[tempt * 2] = true;
			q.push(pair<int, int>(tempt * 2, Count + 1));
		}
		if (tempt - 1 >= 0 && visit[tempt - 1] == false)
		{
			visit[tempt - 1] = true;
			q.push(pair<int, int>(tempt - 1, Count + 1));
		}
		if (tempt + 1 <= 100000 && visit[tempt + 1] == false)
		{
			visit[tempt + 1] = true;
			q.push(pair<int, int>(tempt + 1, Count + 1));
		}
	}
}

int main()
{
	cin >> N >> K;

	q.push(pair<int, int>(N, 0));
	visit[N] = true;

	bfs();

	cout << Count;
}
