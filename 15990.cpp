#include <iostream>
#include <algorithm>

using namespace std;

int T;
int N;
int Mod = 1e9 + 9;
long long dp[100001][4];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;

	for (int j = 4; j <= 100000; j++)
	{
		dp[j][1] = (dp[j - 1][2] + dp[j - 1][3]) % Mod;
		dp[j][2] = (dp[j - 2][1] + dp[j - 2][3]) % Mod;
		dp[j][3] = (dp[j - 3][1] + dp[j - 3][2]) % Mod;
	}

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cout << (dp[N][1] + dp[N][2] + dp[N][3]) % Mod << '\n';
	}
}
