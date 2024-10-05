#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e3+10;
vector<bool> vis(MAX, false);
vector<vector<int>> g(MAX);

void dfs(int v) {
    vis[v] = true;
    for (int w : g[v]) {
        if (not vis[w]) {
            dfs(w);
        }
    }
}

int main(){
    int n, m;cin >> n >> m;

    while(n != 0 && m != 0){
        g.clear();
        g.resize(MAX);
        for (int i = 0; i < m; i++) {
            int a, b, c;cin >> a >> b >> c;
            g[a].push_back(b);
            if(c == 2) g[b].push_back(a);
        }
    
        int po = 0;
        for (int i = 1; i <= n; i++) {
            fill(vis.begin(), vis.end(), false);
            dfs(i);
            for (int j = 1; j <= n and po != 1; j++) {
                if (not vis[j])po = 1;
            }
            if(po == 1){
                cout << 0 << endl;
                break;
            }
        }
        if(po == 0)cout << 1 << endl;
        cin >> n >> m;
    }
    return 0;
}
