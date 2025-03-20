#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

vector<int> ShortDist(const vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<int> distance(n, -1); 
    queue<int> q;
    
    distance[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        for (int neighbor : graph[v]) {
            if (distance[neighbor] == -1) { 
                distance[neighbor] = distance[v] + 1;
                q.push(neighbor);
            }
        }
    }
    return distance;
}

int main() {
    int numVertices, numEdges, start;

    ifstream file("graph.txt");
    if (!file) {
        cerr << "Ошибка открытия файла!" << endl;
    }

    file >> numVertices >> numEdges;

    vector<vector<int>> graph(numVertices);

    for (int i = 0; i < numEdges; i++) {
        int u, v;
        file >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }
    
    file >> start;
    file.close();
    
    vector<int> distances = ShortDist(graph, start);
    
    for (int d : distances) {
        cout << d << endl;
    }
    
}
