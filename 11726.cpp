#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long DP[1001];

int main() 
{
	cin >> N;

	DP[1] = 1;
	DP[2] = 2;

	for (int i = 3; i <= N; i++)
	{
		DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;
	}

	cout << DP[N];
}
