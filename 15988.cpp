#include <iostream>
#include <algorithm>

using namespace std;

int N;
int T;
long long dp[1000001];
int Mod = 1000000009;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	cin >> T;

	for (int j = 4; j <= 1000000; j++)
	{
		dp[j] = (dp[j - 1] + dp[j - 2] + dp[j - 3]) % Mod;
	}


	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cout << dp[N] << '\n';
	}
}
