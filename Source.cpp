#include <iostream>
#include <vector>
#define Parent(i)(i / 2)
#define L(i)(2 * i + 1)
#define R(i)(2 * i + 2)
using namespace std;
void Max_Heapify(vector<int>& v, int i, int heap_size)
{
    int largest = i;
    if (L(i) <= heap_size && v[L(i)] > v[largest])
        largest = L(i);
    if (R(i) <= heap_size && v[R(i)] > v[largest])
        largest = R(i);
    if (largest != i)
    {
        swap(v[i], v[largest]);
        Max_Heapify(v, largest, heap_size);
    }
}
void Build_Max_Heap(vector<int>& v, int heap_size) 
{
    for (int i = v.size() / 2 - 1; i >= 0; i--)
        Max_Heapify(v, i, heap_size);
}
void HeapSort(vector<int>& v) // We sort all array
{
    int heap_size = v.size() - 1;
    Build_Max_Heap(v, heap_size);
    for (int i = v.size() - 1; i >= 1; i--)
    {
        swap(v[0], v[i]);
        --heap_size;
        Max_Heapify(v, 0, heap_size);
    }
}
void Heap_Extract_Max(vector<int>& v) // We remove max element
{
    int heap_size = v.size() - 1;
    if (heap_size < 0)
        return;
    swap(v[0], v[heap_size]);
    v.pop_back();
    --heap_size;
    Max_Heapify(v, 0, heap_size);
}
void Heap_Increase_Key(vector<int>& v, int i, int key) // We change the value of given index if and only if value is greater
{
    if (v[i] > key)
        return;
    v[i] = key;
    while (i > 0 && v[i] > v[Parent(i)])
    {
        swap(v[i], v[Parent(i)]);
        i = Parent(i);
    }
}
void Max_Heap_Insert(vector<int>& v, int key) // We insert new key
{
    v.push_back(INT_MIN);
    Heap_Increase_Key(v, v.size() - 1 ,key);
}
int main()
{
    vector<int> v{ 16, 14, 10, 8, 1214545, 9, 3, 2, 4, 1 };
    Build_Max_Heap(v, v.size() - 1);
    for (int a : v)
        cout << a << " ";

}