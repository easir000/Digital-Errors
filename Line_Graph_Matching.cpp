#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Edge {
    int u, v, w;
};

int maximumWeightedMatching(const vector<Edge>& edges) {
    unordered_map<int, int> matching;
    int matchingSum = 0;

    for (const auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;

        // Check if both vertices are available for matching
        if (matching.find(u) == matching.end() && matching.find(v) == matching.end()) {
            matching[u] = v;
            matching[v] = u;
            matchingSum += edge.w;
        }
    }

    return matchingSum;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int result = maximumWeightedMatching(edges);
    cout << result << endl;

    return 0;
}
