#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int Input[1001];
int dp[1001];
vector<int> tempt[1001]; // 매번 새로 갱신할려고 하는것보다 
vector<int> Result;      // 여러가지 후보군을 저장해 놓은뒤 그중 하나를 고르는것이 더 쉽다 


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	int Count = 0;

	for (int i = 0; i < N; i++)
		cin >> Input[i];

	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
		tempt[i].push_back(Input[i]);
		for (int j = 0; j < i; j++)
		{
			if (Input[i] > Input[j] && dp[j] >= dp[i])
			{
				dp[i] = dp[j] + 1;
				tempt[i].clear();
				tempt[i] = tempt[j];
				tempt[i].push_back(Input[i]);
			}
		}

		Count = max(dp[i], Count);

		if (tempt[i].size() > Result.size())
		{
			Result.clear();
			Result = tempt[i];
		}

	}

	cout << Count << "\n";

	for (int i = 0; i < Count; i++)
		cout << Result[i] << " ";
}
