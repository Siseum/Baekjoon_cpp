#include <iostream>
#include <algorithm>

using namespace std;

class Queue
{
	int arr[10001] = { 0, };
	int Count = 0;

public: 
	void push(int x)
	{
		arr[++Count] = x;
	}

	void pop()
	{
		if (Count == 0)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << arr[1] << "\n";
			for (int i = 2; i <= Count; i++)
			{
				arr[i - 1] = arr[i];
			}
			Count--;
		}
	}

	void size()
	{
		cout << Count << "\n";
	}

	void empty()
	{
		if (Count == 0)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}

	void front()
	{
		if (Count == 0)
			cout << -1 << "\n";
		else
			cout << arr[1] << "\n";
	}

	void back()
	{
		if (Count == 0)
			cout << -1 << "\n";
		else
			cout << arr[Count] << "\n";
	}

};


int main()
{
	Queue que;
	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str = "";
		cin >> str;

		if (str == "push")
		{
			int x = 0;
			cin >> x;
			que.push(x);
		}

		else if (str == "pop")
			que.pop();

		else if (str == "size")
			que.size();

		else if (str == "empty")
			que.empty();

		else if (str == "front")
			que.front();

		else if (str == "back")
			que.back();
	}
}
