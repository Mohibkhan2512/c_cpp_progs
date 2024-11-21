#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void BFS(int startNode, vector<vector<int>>& graph, bool* visited){
    queue<int> q;

    q.push(startNode);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int it = 0; it < graph[node].size(); it++) {
            if (!visited[it] && graph[node][it] == 1) {
                visited[it] = true;
                q.push(it);
            }   
        }
    }
}

int numOfProvinces(vector<vector<int>>& graph){
    bool visited[graph.size()];

    for (int i = 0; i < graph.size(); i++) {
        visited[i] = false;
    }

    int totalProvinces = 0;

    for (int vertex = 0; vertex < graph.size(); vertex++) {
        if (!visited[vertex]) {
            visited[vertex] = true;
            totalProvinces++;
            BFS(vertex, graph, visited);
        }
    }

    return totalProvinces;
}


int main() {
    vector<vector<int>> graph = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    cout << "Number of Provinces: " << numOfProvinces(graph) << endl;

    return 0;
}