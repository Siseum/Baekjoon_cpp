#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> Input;
vector<int> Result;

void dfs(int Count, int Index)
{
	if (Count == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << Result[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = Index; i < N; i++)
	{
		Result.push_back(Input[i]);
		dfs(Count + 1, i + 1);
		Result.pop_back();
	}

}

int main()
{
	while (true)
	{
		cin >> N;

		Input.clear();
		Result.clear();

		if (N == 0)
			return 0;

		for (int i = 0; i < N; i++)
		{
			int tempt = 0;
			cin >> tempt;
			Input.push_back(tempt);
		}

		dfs(0,0);

		cout << "\n";
	}
}
