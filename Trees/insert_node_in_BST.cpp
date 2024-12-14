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

void printBST(sNode* root) {
    queue<sNode*> q;
    q.push(root);

    while (!q.empty()) {
        sNode* cNode = q.front();
        cout << cNode->data << " ";
        q.pop();

        if (cNode->left) {
            q.push(cNode->left);
        }

        if (cNode->right) {
            q.push(cNode->right);
        }
    }
}


sNode* insertNodeInBST(sNode* root, int valueToBeInserted) {
    sNode* rootCopy = root;
    
    while (true) {
        if (valueToBeInserted >= root->data) {
            if (root->right != NULL) {
                root = root->right;
            }
            else {
                root->right = new sNode(valueToBeInserted);
                break;
            }
        }
        if (valueToBeInserted < root->data) {
            if (root->left != NULL) {
                root = root->left;
            }
            else {
                root->left = new sNode(valueToBeInserted);
                break;
            }
        }
    }

    return rootCopy;
}


int main() {
    int arr[] = {6,3,8,2,4,7};
    int nSize = sizeof(arr)/sizeof(arr[0]);

    sNode* root = createTree(arr, nSize);

    int value = 9;

    cout << "BST before insertion :>> " ;
    printBST(root);
    printf("\n");


    sNode* updatedTreeRoot = insertNodeInBST(root, value);

    cout << "BST after insertion :>> " ;

    printBST(updatedTreeRoot);

    printf("\n");
}