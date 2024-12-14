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

int findHeight(sNode* node, string searchDir) {
    int height = 0;
    if (searchDir == "left") {
        while (node) {
            node = node->left;
            height += 1;
        }
    }
    else {
        while (node) {
            node = node->right;
            height += 1;
        }
    }

    return height;
}

int totalNodesInCompBT(sNode* node) {
    int numNodes = 0;

    if (node == NULL) {
        return 0;
    }

    int leftSubTreeHeight = findHeight(node, "left");
    int rightSubTreeHeight = findHeight(node, "right");

    if (leftSubTreeHeight == rightSubTreeHeight) {
        return (1 << leftSubTreeHeight) - 1;
    }

    return 1+totalNodesInCompBT(node->left)+totalNodesInCompBT(node->right);

    return numNodes;
}


int main() {
    int arr[] = {1,2,3,4,5,6,7};
    int nSize = sizeof(arr)/sizeof(arr[0]);

    sNode* root = createTree(arr, nSize);

    cout << "Total nodes in current BT :>> " << totalNodesInCompBT(root);

    printf("\n");
}