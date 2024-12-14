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


sNode* BST(sNode* node, int toSearch) {
    while (node != NULL && node->data != toSearch) {
        node = node->data > toSearch ? node=node->left : node=node->right;
    }

    return node;
}


int main() {
    int arr[] = {8, 3, 10, 1, 6, 9, 14};
    int nSize = sizeof(arr)/sizeof(arr[0]);

    sNode* root = createTree(arr, nSize);

    int toSearch = 9;

    sNode* nodeFound = BST(root, toSearch);

    nodeFound == NULL ? cout << "Current value not present in BT :>> " : cout << "Value found in BT :>> " << nodeFound->data;

    printf("\n");
}