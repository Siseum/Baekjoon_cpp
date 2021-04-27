#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long dp[31] = { 0, };
int main()
{
	ios_base::sync_with_stdio(false);

	cin >> N;

	dp[2] = 3;
	dp[4] = 11;

	for (int i = 6; i <= N; i = i + 2)
	{
		dp[i] += 3 * dp[i - 2] + 2;
		for (int j = i - 4; j >= 2; j = j - 2)
		{
			dp[i] += 2 * dp[j];
		}
	}

	cout << dp[N];

}
