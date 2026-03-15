class DSU {
public:
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;

        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
};

class Solution {
public:
    int maxActivated(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 0) return 1;

        DSU dsu(n);

        unordered_map<int, vector<int>> xMap, yMap;
        xMap.reserve(n * 2);
        yMap.reserve(n * 2);

        for (int i = 0; i < n; i++) {
            xMap[points[i][0]].push_back(i);
            yMap[points[i][1]].push_back(i);
        }

        for (auto& [x, ids] : xMap) {
            for (int i = 1; i < (int)ids.size(); i++) {
                dsu.unite(ids[0], ids[i]);
            }
        }

        for (auto& [y, ids] : yMap) {
            for (int i = 1; i < (int)ids.size(); i++) {
                dsu.unite(ids[0], ids[i]);
            }
        }

        unordered_map<int, int> compSize;
        compSize.reserve(n * 2);

        for (int i = 0; i < n; i++) {
            compSize[dsu.find(i)]++;
        }

        int mx1 = 0, mx2 = 0;
        for (auto& [root, s] : compSize) {
            if (s > mx1) {
                mx2 = mx1;
                mx1 = s;
            } else if (s > mx2) {
                mx2 = s;
            }
        }

        if ((int)compSize.size() == 1) return mx1 + 1;
        return mx1 + mx2 + 1;
    }
};