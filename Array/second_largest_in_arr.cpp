#include <iostream>

using namespace std;

class Solution{
    public:
        int secondSmallestElement(int *arr, int nSize) {
            int result = 1e9, smallest = arr[0];

            for (int i = 0; i < nSize; i++) {
                if (arr[i] < smallest) {
                    result = smallest;
                    smallest = arr[i];
                }
                else if (arr[i] > smallest && result > arr[i]) {
                    result = arr[i];
                }
            }

            return result;
        }

        int secondLargetElemenent(int *arr, int nSize) {
            int result = -1e9, largest = arr[0];

            for (int i = 0; i < nSize; i++) {
                if (arr[i] > largest) {
                    largest = arr[i];
                }
            }

            for (int i = 0; i < nSize; i++) {
                if (arr[i] != largest && arr[i] > result) {
                    result = arr[i];
                }
            }

            return result;
        }
};

int main() {
    Solution obj;

    int arr [] = {10,1, 2, 5, 7, 7, 4};
    int nSize = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Second largest element :>> " << obj.secondLargetElemenent(arr, nSize) << "\n";
    cout << "Second smallest element :>> " << obj.secondSmallestElement(arr, nSize) << "\n";

}