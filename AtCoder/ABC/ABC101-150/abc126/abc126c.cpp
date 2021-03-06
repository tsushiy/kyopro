#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  int n, k; cin>>n>>k;
  double ans = 0;

  REP(i, 1, n+1) {
    double t = (double)1 / n;
    for (int j = i; j < k; j *= 2) t /= 2;
    ans += t;
  }
  cout << fixed << setprecision(10) << ans << endl;

  return 0;
}