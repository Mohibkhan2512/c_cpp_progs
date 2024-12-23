#include <iostream>

using namespace std;

class Solution{
    public:
        void swap(int &a, int &b) {
            // cout << "initially " << a << " " << b << "\n";
            a = a^b;
            b = a^b;
            a = a^b;

            // cout << "swapped " << a << " " << b << "\n";
        }
        void moveZeroesToEnd(int *arr, int nSize) {
            int i = 0, j;
            for (int i = 0; i < nSize; i++) {
                if (arr[i] == 0) {
                    j = i;
                    break;
                }
            }
            for (int i = j; i < nSize; i++) {
                if (arr[i] != 0) {
                    swap(arr[i], arr[j]);
                    j++;
                }
            }
        }
};

int main() {
    int arr[] = {1,0,2,3,2,0,0,4,5,1};
    int nSize = sizeof(arr)/sizeof(arr[0]);
    int d = 2;

    Solution obj;

    obj.moveZeroesToEnd(arr, nSize);

    cout << "\nArr after move :>> ";
    for (auto it : arr) {
        cout << it << " ";
    }
}