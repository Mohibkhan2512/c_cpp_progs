#include <bits/stdc++.h>
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

void printTreeBFS(sNode* root) {
    queue<sNode*> q;

    q.push(root);

    while (!q.empty()) {
        sNode* cNode = q.front();
        q.pop();

        cout << cNode->data << " ";

        if (cNode->left) {
            q.push(cNode->left);
        }
        if (cNode->right) {
            q.push(cNode->right);
        }
    }
}

void printTreeDFS_PreOrder(sNode* node) {
    if (node == NULL) {
        return;
    }
    cout << node->data << " ";
    printTreeDFS_PreOrder(node->left);
    printTreeDFS_PreOrder(node->right);
}

void printTreeDFS_InOrder(sNode* node) {
    if (node == NULL) {
        return;
    }
    printTreeDFS_InOrder(node->left);
    cout << node->data << " ";
    printTreeDFS_InOrder(node->right);
}

void printTreeDFS_PostOrder(sNode* node) {
    if (node == NULL) {
        return;
    }
    printTreeDFS_PostOrder(node->left);
    printTreeDFS_PostOrder(node->right);
    cout << node->data << " ";
}

int main() {
    int arr[] = {1,2,3,4,5};
    int nSize = sizeof(arr)/sizeof(arr[0]);

    sNode* root = createTree(arr, nSize);

    cout << "Cur Tree BFS :>> ";
    printTreeBFS(root);
    printf("\n");

    cout << "Cur Tree DFS Pre Order :>> ";
    printTreeDFS_PreOrder(root);
    printf("\n");

    cout << "Cur Tree DFS In Order :>> ";
    printTreeDFS_InOrder(root);
    printf("\n");

    cout << "Cur Tree DFS Post Order:>> ";
    printTreeDFS_PostOrder(root);
    printf("\n");
}