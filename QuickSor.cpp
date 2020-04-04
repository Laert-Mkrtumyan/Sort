#include <iostream>
#include <vector>
using namespace std;
int Hoare_Partition(vector<int>& v, int l, int r)
{
	int pivot = v[l];
	int i = l - 1, j = r + 1;
	while (1)
	{
		do
		{
			--j;
		} while (v[j] <= pivot);
		do
		{
			++i;
		} while (v[i] > pivot);
		if (i >= j)
			return j;
		swap(v[i], v[j]);
	}
}
int Partiton(vector<int>& v, int l, int r)
{
	int pivot = v[r];
	int last_small_value_index = l - 1;
	for (int i = l; i < r; i++)
	{
		if (pivot >= v[i])
			swap(v[++last_small_value_index], v[i]);
	}
	swap(v[last_small_value_index + 1], v[r]);
	return last_small_value_index + 1;
}
int Randomize_Partition(vector<int>& v, int l, int r)
{
	int random_index = rand() % (r - l) + l;
	swap(v[r], v[random_index]);
	return Partiton(v, l, r);
}
void Quick_Sort(vector<int>& v, int l, int r)
{
	if (l >= r) return;
	int index = Partiton(v, l, r); // int index = Randomize_Partition(v, l, r);
	Quick_Sort(v, l, index - 1);
	Quick_Sort(v, index + 1, r);
}
int main()
{
	vector<int> v{ -1, 126, 130, 999, -1561, 0 };
	Quick_Sort(v, 0, v.size() - 1);
	for (int e : v)
		cout << e << " ";
}
