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


int ceil_in_BST(sNode* node, int key) {
    // smallest value >= key
    
    int ceil = -1e9;
    while (node != NULL) {
        if (node->data == key) {
            ceil = node->data;
            break;
        }
        else if (node->data >= key) {
            ceil = node->data;
            node = node->left;
        }
        else if (node->data < key) {
            node = node->right;
        }
    }

    return ceil;
}


int main() {
    int arr[] = {10,5,13,3,9,11,14,2,4};
    int nSize = sizeof(arr)/sizeof(arr[0]);

    sNode* root = createTree(arr, nSize);

    int key = 3;

    int ceil = ceil_in_BST(root, key);

    cout << "Ceil of key in BT :>> " << ceil;

    printf("\n");
}