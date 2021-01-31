/*** author: yuji9511 ***/
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
using vll = vector<ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
template< int char_size >
struct TrieNode {
  int nxt[char_size];

  int exist;
  vector< int > accept;

  TrieNode() : exist(0) {
    memset(nxt, -1, sizeof(nxt));
  }
};

template< int char_size, int margin >
struct Trie {
  using Node = TrieNode< char_size >;

  vector< Node > nodes;
  int root;

  Trie() : root(0) {
    nodes.push_back(Node());
  }

  void update_direct(int node, int id) {
    nodes[node].accept.push_back(id);
  }

  void update_child(int node, int child, int id) {
    ++nodes[node].exist;
  }

  void add(const string &str, int str_index, int node_index, int id) {
    if(str_index == str.size()) {
      update_direct(node_index, id);
    } else {
      const int c = str[str_index] - margin;
      if(nodes[node_index].nxt[c] == -1) {
        nodes[node_index].nxt[c] = (int) nodes.size();
        nodes.push_back(Node());
      }
      add(str, str_index + 1, nodes[node_index].nxt[c], id);
      update_child(node_index, nodes[node_index].nxt[c], id);
    }
  }

  void add(const string &str, int id) {
    add(str, 0, 0, id);
  }

  void add(const string &str) {
    add(str, nodes[0].exist);
  }

  void query(const string &str, const function< void(int) > &f, int str_index, int node_index) {
    for(auto &idx : nodes[node_index].accept) f(idx);
    if(str_index == str.size()) {
      return;
    } else {
      const int c = str[str_index] - margin;
      if(nodes[node_index].nxt[c] == -1) return;
      query(str, f, str_index + 1, nodes[node_index].nxt[c]);
    }
  }

  void query(const string &str, const function< void(int) > &f) {
    query(str, f, 0, 0);
  }

  int count() const {
    return (nodes[0].exist);
  }

  int size() const {
    return ((int) nodes.size());
  }
};

void solve(){
    string S;
    cin >> S;
    ll M;
    cin >> M;
    vector<string> P(M+1);
    vll W(M);
    rep(i,0,M) cin >> P[i];
    rep(i,0,M) cin >> W[i];

    ll N = S.size();
    vll dp(N+1, 0);
    Trie< 26, 'a' > trie;
    rep(i,0,M){
        trie.add(P[i]);
    }

    rep(i,0,N){
        auto update = [&](int idx) {
            dp[i+P[idx].size()] = max(dp[i+P[idx].size()], dp[i] + W[idx]);
        };
        trie.query(S, update, i, 0);
        dp[i+1] = max(dp[i+1], dp[i]);
    }
    print(dp[N]);

    

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}