#include <cstdlib>
#include <functional>
#include <iostream>
#include <cstddef>
#include <cstdio>
#include <queue>
#include <utility>
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

void verticalViewOfBT(sNode* node) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    queue<pair<int, sNode*>> q;

    q.push({0, node});

    while (!q.empty()) {
        sNode* cNode = q.front().second;
        int vLevel = q.front().first;
        q.pop();
        pq.push({vLevel, cNode->data});

        if (cNode->left) {
            q.push({vLevel-1, cNode->left});
        }

        if (cNode->right) {
            q.push({vLevel+1, cNode->right});
        }
    }

    cout << "Vertical view of tree :>> ";
    while (!pq.empty()) {
        int nodeVal = pq.top().second;
        int vLevel = pq.top().first;
        pq.pop();

        cout << nodeVal << " ";
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6};
    int nSize = sizeof(arr)/sizeof(arr[0]);

    sNode* root = createTree(arr, nSize);

    verticalViewOfBT(root);

    printf("\n");
}