#include <iostream>

using namespace std;

class Solution{
    public:
        void leftRotateArrBy_DPlaces(int *arr, int nSize, int d) {
            int arrIdx = 0;
            int temp[d];
            for (int i = 0; i < d; i++) {
                temp[i] = arr[i];
            }
            for (int i = d; i < nSize; i++) {
                arr[arrIdx] = arr[i]; arrIdx++;
            }
            for (int i = arrIdx; i < nSize; i++) {
                arr[i] = temp[i-1-d];
            }
        }

        void leftRotateArr(int *arr, int nSize) {
            int firstEle = arr[0];
            for (int i = 1; i < nSize; i++) {
                arr[i-1] = arr[i];
            }
            arr[nSize-1] = firstEle;
        }
};

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int nSize = sizeof(arr)/sizeof(arr[0]);
    int d = 2;

    Solution obj;
    // obj.leftRotateArr(arr, nSize);

    // cout << "Left rotated arr :>> ";
    // for (auto it : arr) {
    //     cout << it << " ";
    // }

    obj.leftRotateArrBy_DPlaces(arr, nSize, d);

    cout << "Left rotated arr by d places :>> ";
    for (auto it : arr) {
        cout << it << " ";
    }
}