#include <bits/stdc++.h>
using namespace std;

void KwindowMax(int arr[], int n, int k)
{
    deque<int> Queue(k);
    int i;
    for (i = 0; i < k; ++i)
    {
        while ((!Queue.empty()) && arr[i] >= arr[Queue.back()])
            Queue.pop_back();
        Queue.push_back(i);
    }
    for (i = k; i < n; ++i)
    {

        cout << arr[Queue.front()] << " ";
        while ((!Queue.empty()) && Queue.front() <= i - k)

            Queue.pop_front();

        while ((!Queue.empty()) && arr[i] >= arr[Queue.back()])
            Queue.pop_back();
        Queue.push_back(i);
    }
    cout << arr[Queue.front()];
}

int main()
{
    int arr[] = {12, 1, 78, 90, 57, 89, 56};
    int n;
    int k;
    cin >> n;
    cin >> k;
    KwindowMax(arr, n, k);
    return 0;
}