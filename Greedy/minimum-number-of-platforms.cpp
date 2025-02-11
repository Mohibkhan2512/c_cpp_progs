// https://takeuforward.org/data-structure/minimum-number-of-platforms-required-for-a-railway/
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
 
int countPlatforms(int n,int arr[],int dep[]) {
    int minPlatforms = 1, i = 1, j = 0, curPlat = 1;

    sort(arr, arr+n);
    sort(dep, dep+n);

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) { //one more platform needed
            curPlat++;
            i++;
        }
        else {
            curPlat--; //one platform can be reduced
            j++;
        }
        minPlatforms = max(minPlatforms, curPlat); //updating the value with the current maximum
    }

    return minPlatforms;
}

int main() {
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    int n=sizeof(dep)/sizeof(dep[0]);
    cout << "Minimum number of Platforms required :>> "<< countPlatforms(n,arr,dep) << endl;
}