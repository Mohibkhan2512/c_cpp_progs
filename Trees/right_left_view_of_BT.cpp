#include <cstdlib>
#include <iostream>
#include <cstddef>
#include <cstdio>
#include <queue>
#include <vector>
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

void leftViewOfBT(sNode* node, vector<int>& ds, int curLvl) {
    if (node == NULL) {
        return;
    }

    // to check if we're visiting the level for the first time
    if (curLvl == ds.size()) {
        ds.push_back(node->data);
    }

    if (node->left) {
        leftViewOfBT(node->left, ds, curLvl+1);
    }
    if (node->right) {
        leftViewOfBT(node->right, ds, curLvl+1);
    }
}

void rightViewOfBT(sNode* node, vector<int>& ds, int curLvl) {
    if (node == NULL) {
        return;
    }

    // to check if we're visiting the level for the first time
    if (curLvl == ds.size()) {
        ds.push_back(node->data);
    }

    if (node->right) {
        rightViewOfBT(node->right, ds, curLvl+1);
    }
    if (node->left) {
        rightViewOfBT(node->left, ds, curLvl+1);
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6};
    int nSize = sizeof(arr)/sizeof(arr[0]);

    sNode* root = createTree(arr, nSize);
    vector<int> dsR;
    vector<int> dsL;

    rightViewOfBT(root, dsR, 0);

    cout << "Right view of BT :>> ";
    for (auto it : dsR) {
        cout << it << " ";
    }

    printf("\n");
    leftViewOfBT(root, dsL, 0);

    cout << "Left view of BT :>> ";
    for (auto it : dsL) {
        cout << it << " ";
    }

    printf("\n");
}