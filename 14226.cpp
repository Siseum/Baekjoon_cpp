#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int Count;
bool visit[2001][2001];
queue<pair<int, int>> que;
queue<int> q_count;

void bfs()
{
	while (!que.empty())
	{
		int Screen = que.front().first;
		int ClipBoard = que.front().second;
		Count = q_count.front();

		que.pop();
		q_count.pop();

		if (Screen == N)
			return;

		if (Screen != 0 && Screen < 2001 && visit[Screen][Screen] == false)
		{
			que.push(pair<int, int>(Screen, Screen));
			visit[Screen][Screen] = true;
			q_count.push(Count + 1);
		}

		if (ClipBoard != 0 && Screen + ClipBoard < 2001 && visit[Screen + ClipBoard][ClipBoard] == false)
		{
			que.push(pair<int, int>(Screen + ClipBoard, ClipBoard));
			visit[Screen + ClipBoard][ClipBoard] = true;
			q_count.push(Count + 1);
		}

		if (Screen != 0 && visit[Screen - 1][ClipBoard] == false)
		{
			que.push(pair<int, int>(Screen - 1, ClipBoard));
			visit[Screen - 1][ClipBoard] = true;
			q_count.push(Count + 1);
		}
	}
}

int main()
{
	cin >> N;

	que.push(pair<int, int>(1, 0));
	q_count.push(0);
	visit[1][0] = true;
	bfs();

	cout << Count;
}
