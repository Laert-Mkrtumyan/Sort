#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void Count_Sort(vector<int>& v, int k) // We should assume that minimum element of the array is not negative 
{
	vector<int> c(k + 1, 0);
	for (int i = 0; i < v.size(); i++)
		++c[v[i]];
	for (int i = 1; i <= k; i++)
		c[i] += c[i - 1];
	vector<int> b(v.size());
	for (int i = v.size() - 1; i >= 0; i--) 
	{
		b[c[v[i]] - 1] = v[i];
		--c[v[i]];
	}
	v = b;
}

// Radix Sort
void Count_Radix_Sort(vector<int>& v, int pow_10)
{
	vector<int> c(10, 0), b(v.size());
	for (int i = 0; i < v.size(); i++)
		++c[(v[i] / pow_10) % 10];
	for (int i = 1; i < 10; i++)
		c[i] += c[i - 1];
	for (int i = v.size() - 1; i >= 0; i--)
	{
		b[ c[(v[i] / pow_10) % 10] - 1 ] = v[i];
		--c[(v[i] / pow_10) % 10];
	}
	v = b;
}
void Radix_Sort(vector<int>& v)
{
	int maxel = *max_element(v.begin(), v.end());
	for (int pow_10 = 1; maxel / pow_10; pow_10 *= 10)
		Count_Radix_Sort(v, pow_10);
}
int main()
{
	vector<int> v{12, 1, 10, 9, 4, 11, 12, 0};
	Radix_Sort(v);
	for (int a : v)
		cout << a << " ";

}