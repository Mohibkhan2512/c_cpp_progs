#include <iostream>
#include <vector>

using namespace std;

void RearrangebySign(vector<int> &vec, int nSize) {
    vector<int> pos;
    vector<int> neg;

    for (int i = 0; i < nSize; i++) {
        if (vec[i] > 0) {
            pos.push_back(vec[i]);
        }
        else {
            neg.push_back(vec[i]);
        }
    }

    for (int i = 0; i < nSize/2; i++) {
        vec[2*i] = pos[i];
        vec[2*i+1] = neg[i];
    }

}

int main() {
    
  // Array Initialisation.
  int n = 4;
  vector<int> A = {1,2,-4,-5};

  RearrangebySign(A,n);
  
  for (int i = 0; i < A.size(); i++) {
    cout << A[i] << " ";
  }

  return 0;
}