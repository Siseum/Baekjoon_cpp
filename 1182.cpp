#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int Count;
int Sum;
int CalSum;
int Result;
vector<int> Input;

void dfs(int count, int Index)
{
	if (count == Count)
	{
		if (CalSum == Sum)
			Result++;
		return;
	}

	for (int i = Index; i < N; i++)
	{
		CalSum += Input[i];
		dfs(count + 1, i + 1);
		CalSum -= Input[i];
	}

}



int main()
{
	cin >> N >> Sum;

	for (int i = 0; i < N; i++)
	{
		int tempt = 0;
		cin >> tempt;
		Input.push_back(tempt);
	}

	for (Count = 1; Count <= N; Count++)
	{
		CalSum = 0;
		dfs(0, 0);
	}

	cout << Result;
}
