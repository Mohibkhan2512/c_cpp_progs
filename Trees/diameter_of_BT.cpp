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

int diameterOfBT(sNode* node, int& diameter){
    int lSubTreeHeight = 0, rSubTreeHeight = 0;
    if (node->left == NULL && node->right == NULL) {
        return 1;
    }
    else if (node->left) {
        lSubTreeHeight = diameterOfBT(node->left, diameter);
    }
    else if (node->right) {
        rSubTreeHeight = diameterOfBT(node->right, diameter);
    }

    diameter = max(diameter, lSubTreeHeight+rSubTreeHeight);

    // cout << diameter << "\n";

    return 1+max(lSubTreeHeight, rSubTreeHeight);
}

int main() {
    int arr[] = {1,2,3,4,5, 6};
    int nSize = sizeof(arr)/sizeof(arr[0]);

    sNode* root = createTree(arr, nSize);
    static int diameter;

    cout << "Diameter of Binary Tree :>> " << diameterOfBT(root, diameter)+1 << "\n";

    
    printf("\n");
}