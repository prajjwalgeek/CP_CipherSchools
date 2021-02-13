// 1. Merge 2 Sorted Arrays
//need more efficient solution
#include <bits/stdc++.h>
using namespace std;

vector <int> mergeSortedArrays(const vector<int> &first, const vector<int> &second) {
    int i = 0, j = 0, k = 0;
    vector <int> result(first.size() + second.size());

    while(i < first.size() && j < second.size()) {
        if(first[i] <= second[j]) {
            result[k] = first [i];
            i++; k++;
        }
        else {
            result[k] = second[j];
            j++; k++;
        }
    }
    while(i < first.size()) {
        result[k] = first[i];
        i++; k++;
    }
    while(j < second.size()) {
        result[k] = second[j];
        j++; k++;
    }
    return result;
}
int main() {
    vector <int> first = {1, 2, 5, 8, 9};
    vector <int> second = {3, 4, 6, 7, 11, 15};
    vector <int> result = mergeSortedArrays(first, second);

    for(auto x: result)
        cout<<x<<" ";
}