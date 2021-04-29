#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v[2000];
bool visit[2000];
int N;
int M;

void dfs(int Start, int Count)
{
	if (Count == 4)
	{
		cout << 1;
		exit(0);
	}
	
	for (int i = 0; i < v[Start].size(); i++)
	{
		if (!visit[v[Start][i]])
		{
			visit[v[Start][i]] = true;
			dfs(v[Start][i], Count + 1);
			visit[v[Start][i]] = false;
		}
	}

}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a = 0;
		int b = 0;

		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < N; i++)
	{
		visit[i] = true;
		dfs(i, 0);
		visit[i] = false;
	}

	cout << 0;
	
}
