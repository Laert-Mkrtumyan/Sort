#include <iostream>
#include <vector>
using namespace std;
// Merge Sort
void Merge(vector<int> &v, int start, int end, int middle)
{
    vector<int> curr;
    int left = start;
    int right = middle + 1;
    while (left <= middle && right <= end)
    {
        if (v[left] <= v[right])
        {
            curr.push_back(v[left]);
            ++left;
        }
        else
        {
            curr.push_back(v[right]);
            ++right;
        }
    }
    while (left <= middle)
        curr.push_back(v[left]), ++left;
    while (right <= end)
        curr.push_back(v[right]), ++right;
    for (int i = start, j = 0; i <= end; i++, j++)
        v[i] = curr[j];
}
void MergeSort(vector<int> &v, int left, int right)
{
    if (left == right) return;
    int middle = (left + right) / 2;
    MergeSort(v, left, middle);
    MergeSort(v, middle + 1, right);
    Merge(v, left, right, middle);
}


//Quick sort
int Partition(vector<int> &v, int start, int end)
{
    int i = start - 1;
    int pivot = v[end];
    for (int j = start; j <= end - 1; j++)
    {
        if (v[j] <= pivot)
        {
            ++i;
            swap(v[i],v[j]);
        }
    }
    swap(v[i + 1], v[end]);
    return i + 1;
}
void QuickSort(vector<int> &v, int start, int end)
{
    if (start < end)
    {
        int pi = Partition(v, start, end);
        QuickSort(v, start, pi - 1);
        QuickSort(v, pi + 1, end);
    }
}
//Insertion sort
void InsertionSort(vector<int>& v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            // swap(v[j + 1], v[j]);
            --j;
        }
        v[j + 1] = key;
    }
}


// Bubble sort
void BubbleSort(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size() - 1; j++)
        {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
}
int main()
{
    vector<int> v{21,4984,61,21,23,11,-56,12, -100, 12};
    BubbleSort(v);
    for (int a : v)
        cout<<a<<" ";
}
