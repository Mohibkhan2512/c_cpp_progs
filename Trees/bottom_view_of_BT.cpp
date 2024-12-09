#include <cstdlib>
#include <iostream>
#include <cstddef>
#include <cstdio>
#include <map>
#include <queue>
#include <utility>
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

void topViewOfBt(sNode* node) {
    map<int, int> mp;

    queue<pair<int, sNode*>> q;

    q.push({0, node});

    while (!q.empty()) {
        sNode* cNode = q.front().second;
        int vLevel = q.front().first;
        q.pop();

        mp[vLevel] = cNode->data;

        if (cNode->left) {
            q.push({vLevel-1, cNode->left});
        }

        if (cNode->right) {
            q.push({vLevel+1, cNode->right});
        }

    }

    cout << "Bottom view of tree :>> ";
    for (auto it : mp) {
        cout << it.second << " ";
    }

}

int main() {
    int arr[] = {1,2,3,4,5, 6};
    int nSize = sizeof(arr)/sizeof(arr[0]);

    sNode* root = createTree(arr, nSize);

    topViewOfBt(root);

    printf("\n");
}