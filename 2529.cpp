#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int K;
long long Max = 0;
long long Min = 9999999999;
char Inequality[10];
bool Select[10];
string minStr;
string maxStr;
string temptStr;

void bfs(int Count, int prevNum)
{
	if (Count == K + 1)
	{
		long long tempt = stoll(temptStr);

		if (tempt < Min)
		{
			Min = tempt;
			minStr.clear();
			minStr = temptStr;
		}

		else if (tempt > Max)
		{
			Max = tempt;
			maxStr.clear();
			maxStr = temptStr;
		}

		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (Count == 0)
		{
			Select[i] = true;
			temptStr.push_back(i + 48);
			bfs(Count + 1, i);
			temptStr.pop_back();
			Select[i] = false;
		}

		else if (Select[i]==false && Inequality[Count] == '<' && prevNum < i)
		{
			Select[i] = true;
			temptStr.push_back(i+48);
			bfs(Count + 1, i);
			temptStr.pop_back();
			Select[i] = false;
		}
			

		else if (Select[i]==false&&Inequality[Count] == '>' && prevNum > i)
		{
			Select[i] = true;
			temptStr.push_back(i+48);
			bfs(Count + 1, i);
			temptStr.pop_back();
			Select[i] = false;
		}

	}
}


int main()
{
	cin >> K;

	for (int i = 1; i <= K; i++)
	{
		cin >> Inequality[i];
	}

	bfs(0, 0);

	cout << maxStr << '\n';
	cout << minStr;
}
