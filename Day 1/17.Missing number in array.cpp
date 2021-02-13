// 17. Missing number in array
// https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1#
int MissingNumber(vector<int>& array, int n) {
    // Your code goes here
    int missingNumber = 0;
    for(int i=0; i<n-1; i++) {
        // cout<<missingNumber<<endl;
        missingNumber = missingNumber ^ array[i];
    }
    int mN2 = 0;
    for(int j=1; j<=n; j++) {
        // missingNumber = missingNumber ^
        mN2 = mN2 ^ j;
    }
    // missingNumber ^ n;
    
    return missingNumber^mN2;
}