#include <cstdlib>
#include <iostream>
#include <cstddef>
#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

struct sNode {
    int data;
    sNode* left;
    sNode* right;
    sNode(int curData) {
        data = curData;
        left = NULL;
        right = NULL;
    }
};

sNode* createTree(int arr[], int nSize) {
    sNode* root = new sNode(arr[0]);
    int Idx = 1;

    queue<sNode*> q;

    q.push(root);

    while (!q.empty()) {
        sNode* cNode = q.front();
        q.pop();

        if(Idx < nSize) {
            cNode->left = new sNode(arr[Idx]);
            q.push(cNode->left);
            Idx++;
        }
        if(Idx < nSize) {
            cNode->right = new sNode(arr[Idx]);
            q.push(cNode->right);
            Idx++;
        }
    }

    return root;
}

int maxWidthOfBT(sNode* node) {
    int maxWidth = 0;
    queue<pair<sNode*, int>> q;

    q.push({node, 1});

    int leftIdx = 0, rightIdx = 0, leftMostNodeIdx = 0, rightMostNodeIdx = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int cIdx = q.front().second;
            sNode* cNode = q.front().first;
            q.pop();
            if (i == 0) {
                leftMostNodeIdx = cIdx;
                // cout << "leftMostNodeIdx :>> " <<leftMostNodeIdx << "\n";
            } 
            else if (i == size-1) {
                rightMostNodeIdx = cIdx;
                // cout << "rightMostNodeIdx :>> " <<rightMostNodeIdx << "\n";
            }

            if (cNode->left) {
                leftIdx = 2*cIdx;
                q.push({cNode->left, leftIdx});
            }

            if (cNode->right) {
                rightIdx = 2*cIdx+1;
                q.push({cNode->right, rightIdx});
            }
            // cout << cIdx << " " << leftIdx << " " << rightIdx << "\n";
        }
        maxWidth = max(maxWidth, rightMostNodeIdx-leftMostNodeIdx+1);
    }

    return maxWidth;
}

int main() {
    int arr[] = {1,2,3,4,5,6,7};
    int nSize = sizeof(arr)/sizeof(arr[0]);

    sNode* root = createTree(arr, nSize);

    cout << "Max width of BT :>> " << maxWidthOfBT(root);

    printf("\n");
}