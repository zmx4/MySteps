#pragma once
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
	//埃氏筛质数
	int countPrimes(int n)
	{
		if(n < 3)
			return 0;
		int count = 0;
		bool state[n];
		for (int i = 0; i < n;i++)
		{
			state[i] = false;
		}
		for (int i = 2; i < n;i++)
		{
			if (!state[i])
			{
				count++;
				for (int j = i + 1; i < n;j+=i)
					state[i] = true;
			}
			return count;
		}
	}
	
};
class mysort{
	public:
		virtual void quicksort(int a[], int l, int r);
		virtual void insertsort(int a[], int n);
};
class uppersort:public mysort
{
	public:
		virtual void quicksort(int a[], int l, int r)
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
		virtual void insertsort(int a[], int n)
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
class lowwersort:public mysort
{
	public:
		virtual void insertsort(int a[], int n)
		{
			for (int j = 1; j < n; j++)
			{
				int key = a[j];
				int i = j - 1;
				while (i >= 0&&a[i]<key)
				{
					a[i + 1] = a[i];
					i--;
				}
				a[i + 1] = key;
			}
		}
		virtual void quicksort(int a[], int l, int r)
		{
			if (l < r)
			{
				int i = l;
				int j = r;
				int key = a[l];
				while (i < j)
				{
					while (i < j && a[j] <= key)
						j--;
					a[i] = a[j];
					while (i < j && a[i] >= key)
						i++;
					a[j] = a[i];
				}
				a[i] = key;
				quicksort(a, l, i - 1);
				quicksort(a, i + 1, r);
			}
		}
};
class myjudge{
	private:
		int powa(int n,int s)
		{
			int total = 1;
			while(s--)
			{
				total *= n;
			}
			return total;
		}
		int countDigits(int number)
		{
			int count = 0;
			if (number == 0)
				return 1;
			while (number != 0)
			{
				number /= 10;
				count++;
			}
			return count;
		}

	public:
		bool isPrime(const int &n)
		{
			if (n <= 1)
				return false;
			if (n == 2)
				return true;
			if (n % 2 == 0)
				return false;
			for (int i = 3; i * i <= n; i += 2)
			{
				if (n % i == 0)
					return false;
			}
			return true;
		}
		bool isNarcissistic(const int &n)
		{
			int numDigits = countDigits(n);
			int numDIgitsA = numDigits;
			int sum = 0, temp = n;
			while(numDIgitsA--)
			{
				int a = temp % 10;
				sum += powa(a, numDigits);
				temp /= 10;
			}
			if(sum == n)
				return true;
			else
				return false;
		}
		
};