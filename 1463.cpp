#include <iostream>
#include <algorithm>

using namespace std;

int X;
int DP[1000001];

int main() 
{
	cin >> X;

	for (int i = 2; i <= X; i++)
	{
		DP[i] = DP[i - 1] + 1;
		if (i % 2 == 0)
			DP[i] = min(DP[i], DP[i / 2] + 1);
		if (i % 3 == 0)
			DP[i] = min(DP[i], DP[i / 3] + 1);
	}

	cout << DP[X];
}
