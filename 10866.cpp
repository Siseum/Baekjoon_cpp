#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;


int main()
{
	deque<int>deq;

	int N = 0;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		string str = "";
		cin >> str;

		if (str == "push_front")
		{
			int x = 0;
			cin >> x;
			deq.push_front(x);
		}

		else if (str == "push_back")
		{
			int x = 0;
			cin >> x;
			deq.push_back(x);
		}

		else if (str == "pop_front")
		{
			if (deq.empty())
				cout << -1 << "\n";
			else
			{
				cout << deq.front() << "\n";
				deq.pop_front();
			}
		}

		else if (str == "pop_back")
		{
			if (deq.empty())
				cout << -1 << "\n";
			else
			{
				cout << deq.back() << "\n";
				deq.pop_back();
			}
		}

		else if (str == "size")
		{
			cout << deq.size() << "\n";
		}

		else if (str == "empty")
		{
			if (deq.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}

		else if (str == "front")
		{
			if (deq.empty())
				cout << -1 << "\n";
			else
				cout << deq.front() << "\n";
		}

		else if (str == "back")
		{
			if (deq.empty())
				cout << -1 << "\n";
			else
				cout << deq.back() << "\n";
		}
	}
}
