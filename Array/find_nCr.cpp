#include <iostream>
using namespace std;

int find_nCr(int n, int r) {
    int ans = 1;

    for (int i = 0; i < (n-r); i++) {
        ans = ans*(n-i);
        ans = ans/(i+1);
    }

    return ans;
}

int main()
{
    int n = 5;  
    int r = 3;
    int ans = find_nCr(n, r);
    cout << "nCr :>> " << ans << "\n";

    return 0;
}