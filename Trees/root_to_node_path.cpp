#include <cstdlib>
#include <iostream>
#include <cstddef>
#include <cstdio>
#include <map>
#include <queue>
#include <stack>
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

vector<int> rootToNodePath(sNode* node, int dest) {
    vector<int> ans;

    map<int, int> mp;

    stack<pair<sNode*, int>> st;

    st.push({node, 0});

    while (!st.empty()) {
        sNode* cNode = st.top().first;
        int hLevel = st.top().second;
        st.pop();

        mp[hLevel] = cNode->data;

        if (cNode->data == dest) {
            cout << "Dest node found at level :>> " << hLevel << "\n";
            break;
        }

        if (cNode->right) {
            st.push({cNode->right, hLevel+1});
        }

        if (cNode->left) {
            st.push({cNode->left, hLevel+1});
        }
    }

    for (auto it : mp) {
        ans.push_back(it.second);
    }

    return ans;
}

int main() {
    int arr[] = {1,2,3,4,5,6};
    int nSize = sizeof(arr)/sizeof(arr[0]);

    sNode* root = createTree(arr, nSize);
    int dest = 5;

    vector<int> path = rootToNodePath(root, dest);

    if (path.size() == 0) {
        cout << "Path to dest in not present";
    }
    else {
        cout << "Path from root to dest :>> ";
        for (auto it : path) {
            cout << it << " ";
        }
    }

    printf("\n");
}