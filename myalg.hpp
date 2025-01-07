class myalg
{
public:
	// 求最大公约数
	int GCD1(int a, int b)
	{
		while (b != 0)
		{
			int r = a % b;
			a = b;
			b = r;
		}
		return a;
	}
	// 递归求最大公约数
	int GCD2(int a, int b)
	{
		if (b == 0)
			return a;
		else
			return GCD2(b, a % b);
	}
	// 求最小公倍数
	int lcm(int a, int b)
	{
		return a * b / GCD1(a, b);
	}
};
class mysort{
	public:
		void quicksort(int a[], int l, int r)
		{
			if (l < r)
			{
				int i = l;
				int j = r;
				int key = a[l];
				while (i < j)
				{
					while (i < j && a[j] >= key)
						j--;
					a[i] = a[j];
					while (i < j && a[i] <= key)
						i++;
					a[j] = a[i];
				}
				a[i] = key;
				quicksort(a, l, i - 1);
				quicksort(a, i + 1, r);
			}
		}
		void insertsort(int a[], int n)
		{
			for (int j = 1; j < n; j++)
			{
				int key = a[j];
				int i = j - 1;
				while (i >= 0 && a[i] > key)
				{
					a[i + 1] = a[i];
					i--;
				}
				a[i + 1] = key;
			}
		}
};
