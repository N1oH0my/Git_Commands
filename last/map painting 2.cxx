#include <iostream> 

const int N = 9;
int mode[N];
int arr[N];
bool res = false;

void print()
{
	int ptr;
	int i = 0;
	bool isfirst = true;
	while (i != N)
	{
		if (mode[i] == 0)
			ptr = arr[i];
		else
			ptr = -arr[i];
		i++;
		while (mode[i] == 2 && i !=N)
		{
			ptr = ptr * 10 + arr[i];
			i++;
		}
		if (ptr >= 0&& !isfirst)
			std::cout << "+";
		std::cout << ptr;
		isfirst = false;
	}
}

bool check(int n)
{
	int num = 0;
	int ptr;
	int i = 0;
	while (i != 9)
	{
		if (mode[i] == 0)
			ptr = arr[i];
		else
			ptr = -1*arr[i];
		i++;
		while (mode[i] == 2 && i != 9)
		{
			ptr = ptr * 10 + arr[i];
			i++;
		}
		num += ptr;
	}
	return n == num;
}

void task(int n, int lvl = 0)
{
	if (lvl == N)
	{
		res = check(n);
	}
	else
	{
		for (int i = 0; i < 2 + (lvl != 0) && !res; i++)
		{
			mode[lvl]++;
			task(n, lvl + 1);
		}
		if (!res)
			mode[lvl] = -1;
	}
}


void main()
{
	for (int i = 0; i < N; i++)
	{
		std::cin >> arr[i];
		mode[i] = -1;
	}
	int n;
	std::cin >> n;
	task(n);
	if (res)
		print();
	else
		std::cout << -1;
	
}