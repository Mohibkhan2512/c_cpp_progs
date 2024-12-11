#include <cstdlib>
#include <iostream>
#include <cstddef>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
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

vector<int> nodesAtDist_K_FromNode(sNode* root, int dist) {
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

    set<sNode*> visited;
    q.push(targetNode);
    visited.insert(targetNode);
    int curDist = 0;

    while (!q.empty()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            sNode* cNode = q.front();
            visited.insert(cNode);
            q.pop();

            if (cNode->left) {
                q.push(cNode->left);
            }
            if (cNode->right) {
                q.push(cNode->right);
            }
            if (parentMap[cNode]) {
                q.push(parentMap[cNode]);
            }
        }

        if (curDist == dist) {
            break;
        }
        
        curDist++;
    }

    cout << "Nodes at dist:>> " << dist << " from node :>> " << target << "\n";
    for (auto it : visited) {
        cout << it->data << " ";
    }

    return ans;
}

int main() {
    int arr[] = {1,2,3,4,5,6,7};
    int nSize = sizeof(arr)/sizeof(arr[0]);

    sNode* root = createTree(arr, nSize);
    int dist = 2;

    vector<int> nodesAns = nodesAtDist_K_FromNode(root, dist);


    printf("\n");
}