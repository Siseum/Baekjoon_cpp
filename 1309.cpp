#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[100001][3];
int Result;
int Mod = 9901;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	dp[1][0] = dp[1][1] = dp[1][2] = 1;

	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % Mod;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % Mod;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % Mod;
	}

	Result = (dp[N][0] + dp[N][1] + dp[N][2]) % Mod;

	cout << Result;
}
