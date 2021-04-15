#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1001];
int dp[1001][2];
int Result;

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = i - 1; j >= 1; j--)
		{
			if (arr[i] > arr[j])
				dp[i][0] = max(dp[i][0], dp[j][0]);
		}
		dp[i][0] += 1;
	}

	for (int i = N; i >= 1; i--)
	{
		for (int j = i + 1; j <= N; j++)
		{
			if (arr[i] > arr[j])
				dp[i][1] = max(dp[i][1], dp[j][1]);
		}
		dp[i][1] += 1;
	}

	for (int i = 1; i <= N; i++)
	{
		Result = max(Result, dp[i][0] + dp[i][1]);
	}

	Result = Result - 1;

	cout << Result;
}
