#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr int MOD = 1000000007;
constexpr int INF = 1LL << 30;
constexpr long long LLINF = 1LL << 60;

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

template<typename T>
vector<vector<T>> warshall_floyd(const vector<vector<pair<int, T>>> &graph) {
  int n = graph.size();
  vector<vector<T>> dists(n, vector<T>(n, numeric_limits<T>::max()));
  for (int i = 0; i < n; ++i) {
    dists[i][i] = 0;
    for (auto e : graph[i]) {
      int nx; T cost;
      tie(nx, cost) = e;
      dists[i][nx] = cost;
    }
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) if (dists[i][k] != numeric_limits<T>::max()) {
      for (int j = 0; j < n; ++j) if (dists[k][j] != numeric_limits<T>::max()) {
        dists[i][j] = min(dists[i][j], dists[i][k]+dists[k][j]);
      }
    }
  }
  return dists;
}

int main() {
  int n, m, rt; cin>>n>>m>>rt;
  vector<int> r(rt);
  rep(i, rt) {
    cin>>r[i]; --r[i];
  }
  sort(r.begin(), r.end());
  vector<vector<pair<int, int>>> g(n);
  rep(i, m) {
    int a, b, c; cin>>a>>b>>c;
    --a; --b;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
  }

  auto dists = warshall_floyd(g);
  int ans = INF;
  do {
    int t = 0;
    rep(i, rt-1) {
      t += dists[r[i]][r[i+1]];
    }
    ans = min(ans, t);
  } while (next_permutation(r.begin(), r.end()));
  print(ans);

  return 0;
}
