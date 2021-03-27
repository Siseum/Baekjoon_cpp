#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int Result;
string Input;

void Add(int Number)
{
	Result = Result | (1 << Number);
}

void Remove(int Number)
{
	int tempt = ~(1 << Number);
	Result = Result & tempt;
}

void Check(int Number)
{
	int tempt = 1 << Number;
	if (Result & tempt)
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
}

void Toggle(int Number)
{
	int tempt = 1 << Number;

	if (tempt & Result)
		Result = Result & (~tempt);

	else
		Result = Result | tempt;
}

void All()
{
	Result = ~(1 << 31);

}

void Empty()
{
	Result = 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int number = 0;
		Input.clear();
		cin >> Input;

		if (Input == "add")
		{
			cin >> number;
			Add(number);
		}
		else if (Input == "remove")
		{
			cin >> number;
			Remove(number);
		}
		else if (Input == "check")
		{
			cin >> number;
			Check(number);
		}
		else if (Input == "toggle")
		{
			cin >> number;
			Toggle(number);
		}
		else if (Input == "all")
		{
			All();
		}
		else if (Input == "empty")
		{
			Empty();
		}

	}

}
