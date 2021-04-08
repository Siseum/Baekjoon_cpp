#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1001][4];
int dp[1001][4];
int Result = 1234567890;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
	}

	for (int i = 1; i <= N; i++)
	{
		dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + arr[i][2];
		dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][3];
		Result = min({dp[i][1], dp[i][2], dp[i][3]});
	}

	cout << Result;
}
