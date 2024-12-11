#include <cstdlib>
#include <iostream>
#include <cstddef>
#include <cstdio>
#include <map>
#include <queue>
#include <unordered_map>
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

int minTimeToBurn(sNode* root) {
    vector<int> ans;
    int target = 2;
    sNode* targetNode;

    queue<sNode*> q;
    map<sNode*, sNode*> parentMap;

    parentMap[root] = NULL;
    q.push(root);

    while (!q.empty()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            sNode* cNode = q.front();
            q.pop();

            if (cNode->data == target) {
                targetNode = cNode;
            }

            if (cNode->left) {
                q.push(cNode->left);
                parentMap[cNode->left] = cNode;
            }
            if (cNode->right) {
                q.push(cNode->right);
                parentMap[cNode->right] = cNode;
            }
        }
    }

    unordered_map<sNode*, bool> visited;
    q.push(targetNode);
    visited[targetNode] = true;
    int minDist = 0;
    bool burntChildNode;

    while (!q.empty()) {
        burntChildNode = false;
        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            sNode* cNode = q.front();
            visited[cNode] = true;
            q.pop();

            if (cNode->left && !visited[cNode->left]) {
                q.push(cNode->left);
                burntChildNode = true;
            }
            if (cNode->right && !visited[cNode->right]) {
                q.push(cNode->right);
                burntChildNode = true;
            }
            if (parentMap[cNode] && !visited[parentMap[cNode]]) {
                q.push(parentMap[cNode]);
                burntChildNode = true;
            }
        }

        if (burntChildNode == true) {
            minDist++;
        }
        
    }

    return minDist;
}

int main() {
    int arr[] = {1,2,3,4,5,6,7};
    int nSize = sizeof(arr)/sizeof(arr[0]);

    sNode* root = createTree(arr, nSize);

    cout << "Min time to burn tree starting from node 2 :>> " << minTimeToBurn(root);

    printf("\n");
}