#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[100001];
int dp[100001][2];
int Result;

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	Result = dp[1][0] = arr[1];


	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
		Result = max({ Result, dp[i][0], dp[i][1] });
	}

	cout << Result;

}
