#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cstddef>
#include <cstdio>
#include <queue>
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

int maxPathSumInBT(sNode* node, int& maxSum){
    int maxSumLST = 0, maxSumRST = 0; // ST -> subTree
    if (node == NULL) {
        return 0;
    }
    maxSumLST = maxPathSumInBT(node->left, maxSum);
    if (maxSumLST < 0) {
        maxSumLST = 0;
    }
    else if (maxSumRST < 0) {
        maxSumRST = 0;
    }
    maxSumRST = maxPathSumInBT(node->right, maxSum);

    maxSum = max(maxSum, maxSumLST+maxSumRST+node->data);
    
    return node->data+max(maxSumLST, maxSumRST);
}

int main() {
    int arr[] = {1,2,3,4,5, 6};
    int nSize = sizeof(arr)/sizeof(arr[0]);

    sNode* root = createTree(arr, nSize);
    static int maxSum;

    maxPathSumInBT(root, maxSum);

    cout << "Maximum Path Sum in Binary Tree :>> " <<  maxSum << "\n";

    printf("\n");
}