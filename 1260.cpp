#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int M;
int V;
int arr[1001][1001];
bool visit[1001];
bool visit2[1001];
queue<int>que;

void dfs(int Start)
{
	for (int i = 1; i <= N; i++)
	{
		if (arr[Start][i] == 1 && visit[i] == false)
		{
			visit[i] = true;
			que.push(i);
			dfs(i);
		}
	}
}

void bfs(int Start)
{
	for (int i = 1; i <= N; i++)
	{
		if (arr[Start][i] == 1 && visit2[i] == false)
		{
			visit2[i] = true;
			cout << i << " ";
			que.push(i);
		}
	}

	while (!que.empty())
	{
		int s = que.front();
		que.pop();
		bfs(s);
	}
}

int main()
{
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int a = 0;
		int b = 0;

		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	visit[V] = true;
	que.push(V);
	dfs(V);
	
	while (!que.empty())
	{
		cout << que.front() << " ";
		que.pop();
	}
	cout << "\n";
	
	visit2[V] = true;
	cout << V << " ";
	bfs(V);
}
