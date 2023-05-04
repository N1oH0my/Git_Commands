#include<iostream>
#include<conio.h>
using namespace std;
class knapsack
{
private:
	int p[20], w[20], m, x[20], y[20], n, mv;
	int Bound(int, int, int);
	int fp, fw;

public:
	knapsack()
	{
		fp = 0;
	}
	void BKnap(int, int, int);
	void setdata();
	void getdata();
};

void knapsack::setdata()
{
	int i;

	cout << "\nEnter number of elements: ";
	cin >> n;

	cout << "\nEnter elements in the descending order of P/W\n";

	for (i = 1; i <= n; i++)
	{
		cout << "\nEnter profit of " << i << " element: ";
		cin >> p[i];
		cout << "\nEnter weight of " << i << " element: ";
		cin >> w[i];
	}

	cout << "\nEnter capcity of kanpsack: ";
	cin >> m;
	cout << "\nEnter maxValue of kanpsack: ";
	cin >> mv;
}

int knapsack::Bound(int cp, int cw, int k)
{
	int b, c, i;

	b = cp;
	c = cw;


	for (i = k + 1; i <= n; i++)
	{
		c = c + w[i];
		if (c < m && b<mv)
			b = b + p[i];
		else
			return (b + (1 - (c - m) / w[i]) * p[i]);
	}
	return b;
}

void knapsack::BKnap(int k, int cp, int cw)
{
	int j;

	if (cw + w[k] <= m && cp + p[k] <= mv)
	{
		y[k] = 1;
		if (k < n)
			BKnap(k + 1, cp + p[k], cw + w[k]);
		if ((cp + p[k] > fp) && (k == n))
		{
			fp = cp + p[k];
			fw = cw + w[k];
			for (j = 1; j <= k; j++)
				x[j] = y[j];
		}
	}

	int tmp = Bound(cp, cw, k);
	if ( tmp >= fp && tmp<=mv)
	{
		y[k] = 0;
		if (k < n)
			BKnap(k + 1, cp, cw);
		if ((cp > fp) && (k == n))
		{
			fp = cp;
			fw = cw;
			for (j = 1; j <= k; j++)
				x[j] = y[j];
		}
	}
}

void knapsack::getdata()
{
	int i;

	for (i = 1; i <= n; i++)
		cout << "x[" << i << "]= " << x[i] << endl;
}

void main()
{
	knapsack k;

	k.setdata();

	k.BKnap(1, 0, 0);

	cout << "\nSolution is :\n";
	k.getdata();

	cin.ignore();
	cin.get();
}