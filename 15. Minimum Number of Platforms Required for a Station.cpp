// 15. Minimum Number of Platforms Required for a Railway/Bus Station
// https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/

int findPlatform(int arr[], int dep[], int n)
{
	sort(arr, arr + n);
	sort(dep, dep + n);
// 	for (int i=0; i<n; i++)
// 	    cout<<arr[i]<<" ";
// 	cout<<endl;
// 	for (int i=0; i<n; i++)
// 	    cout<<dep[i]<<" ";
	int i = 1, j = 0;
	int platforms = 1;
	int maxPlatforms = 1;
    while(i < n && j < n) {
        if(arr[i] > dep[j]) {
            platforms--;   
            j++;
        }
        else if (arr[i] <= dep[j]) {
            platforms++;
            i++;
        }
        maxPlatforms = max(maxPlatforms, platforms);
        // i++;
    }
    return maxPlatforms;
}