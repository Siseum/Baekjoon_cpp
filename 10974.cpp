#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
bool Select[9];
string Result;

void dfs(int Count)
{
	if (Count == N)
	{
		for (int i = 0; i < N; i++)
			cout << Result[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (Select[i] == false)
		{
			Result.push_back(i + '0');
			Select[i] = true;
			dfs(Count + 1);
			Select[i] = false;
			Result.pop_back();
		}
	}

}

int main()
{
	cin >> N;

	dfs(0);

}
