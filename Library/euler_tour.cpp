/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using lpair = pair<int, int>;
const int MOD = 1e9+7;
const int INF = 1e9;
#define rep(i,m,n) for(int i=(m);i<(n);i++)
#define rrep(i,m,n) for(int i=(m);i>=(n);i--)
#define printa(x,n) for(int i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
// verify: https://codeforces.com/contest/383/problem/C

class SegmentTree {
  struct Node {
    Node *left, *right;
    int max_v, smax_v, max_c;
    int min_v, smin_v, min_c;
    int sum;
    int len, ladd, lval;

    Node() : left(0), right(0), ladd(0), lval(INF) {}

    void init(int x) {
      max_v = min_v = sum = x;
      smax_v = -INF; smin_v = INF;
      max_c = min_c = 1;
    }

    void init_empty() {
      max_v = smax_v = -INF;
      min_v = smin_v = INF;
      max_c = min_c = 0;
    }

    void update_max(int x) {
      sum += (x - max_v) * max_c;

      if(max_v == min_v) {
        max_v = min_v = x;
      } else if(max_v == smin_v) {
        max_v = smin_v = x;
      } else {
        max_v = x;
      }

      if(lval != INF && x < lval) {
        lval = x;
      }
    }

    void update_min(int x) {
      sum += (x - min_v) * min_c;

      if(max_v == min_v) {
        max_v = min_v = x;
      } else if(max_v == smin_v) {
        min_v = smax_v = x;
      } else {
        min_v = x;
      }

      if(lval != INF && lval < x) {
        lval = x;
      }
    }

    void addaint(int x) {
      max_v += x;
      if(smax_v != -INF) smax_v += x;
      min_v += x;
      if(smin_v != INF) smin_v += x;

      sum += len * x;
      if(lval != INF) {
        lval += x;
      } else {
        ladd += x;
      }
    }

    void updateaint(int x) {
      max_v = min_v = x;
      smax_v = -INF; smin_v = INF;
      max_c = min_c = len;

      sum = len * x;
      lval = x; ladd = 0;
    }

    void push() {

      if(lval != INF) {
        left->updateaint(lval);
        right->updateaint(lval);
        lval = INF;
        return;
      }

      if(ladd != 0) {
        left->addaint(ladd);
        right->addaint(ladd);
        ladd = 0;
      }

      if(max_v < left->max_v) {
        left->update_max(max_v);
      }
      if(left->min_v < min_v) {
        left->update_min(min_v);
      }

      if(max_v < right->max_v) {
        right->update_max(max_v);
      }
      if(right->min_v < min_v) {
        right->update_min(min_v);
      }
    }

    void update() {
      sum = left->sum + right->sum;

      if(left->max_v < right->max_v) {
        max_v = right->max_v;
        max_c = right->max_c;
        smax_v = max(left->max_v, right->smax_v);
      } else if(left->max_v > right->max_v) {
        max_v = left->max_v;
        max_c = left->max_c;
        smax_v = max(left->smax_v, right->max_v);
      } else {
        max_v = left->max_v;
        max_c = left->max_c + right->max_c;
        smax_v = max(left->smax_v, right->smax_v);
      }

      if(left->min_v < right->min_v) {
        min_v = left->min_v;
        min_c = left->min_c;
        smin_v = min(left->smin_v, right->min_v);
      } else if(left->min_v > right->min_v) {
        min_v = right->min_v;
        min_c = right->min_c;
        smin_v = min(left->min_v, right->smin_v);
      } else {
        min_v = left->min_v;
        min_c = left->min_c + right->min_c;
        smin_v = min(left->smin_v, right->smin_v);
      }
    }
  };

  int n, n0;
  Node *root;

  void _update_min(int x, int a, int b, Node *nd, int l, int r) {
    if(b <= l || r <= a || nd->max_v <= x) {
      return;
    }
    if(a <= l && r <= b && nd->smax_v < x) {
      nd->update_max(x);
      return;
    }

    nd->push();
    _update_min(x, a, b, nd->left, l, (l+r)/2);
    _update_min(x, a, b, nd->right, (l+r)/2, r);
    nd->update();
  }

  void _update_max(int x, int a, int b, Node *nd, int l, int r) {
    if(b <= l || r <= a || x <= nd->min_v) {
      return;
    }
    if(a <= l && r <= b && x < nd->smin_v) {
      nd->update_min(x);
      return;
    }

    nd->push();
    _update_max(x, a, b, nd->left, l, (l+r)/2);
    _update_max(x, a, b, nd->right, (l+r)/2, r);
    nd->update();
  }

  void _add_val(int x, int a, int b, Node *nd, int l, int r) {
    if(b <= l || r <= a) {
      return;
    }
    if(a <= l && r <= b) {
      nd->addaint(x);
      return;
    }

    nd->push();
    _add_val(x, a, b, nd->left, l, (l+r)/2);
    _add_val(x, a, b, nd->right, (l+r)/2, r);
    nd->update();
  }

  void _update_val(int x, int a, int b, Node *nd, int l, int r) {
    if(b <= l || r <= a) {
      return;
    }
    if(a <= l && r <= b) {
      nd->updateaint(x);
      return;
    }

    nd->push();
    _update_val(x, a, b, nd->left, l, (l+r)/2);
    _update_val(x, a, b, nd->right, (l+r)/2, r);
    nd->update();
  }

  int _query_max(int a, int b, Node *nd, int l, int r) {
    if(b <= l || r <= a) {
      return -INF;
    }
    if(a <= l && r <= b) {
      return nd->max_v;
    }
    nd->push();
    int lv = _query_max(a, b, nd->left, l, (l+r)/2);
    int rv = _query_max(a, b, nd->right, (l+r)/2, r);
    return max(lv, rv);
  }

  int _query_min(int a, int b, Node *nd, int l, int r) {
    if(b <= l || r <= a) {
      return INF;
    }
    if(a <= l && r <= b) {
      return nd->min_v;
    }
    nd->push();
    int lv = _query_min(a, b, nd->left, l, (l+r)/2);
    int rv = _query_min(a, b, nd->right, (l+r)/2, r);
    return min(lv, rv);
  }

  int _query_sum(int a, int b, Node *nd, int l, int r) {
    if(b <= l || r <= a) {
      return 0;
    }
    if(a <= l && r <= b) {
      return nd->sum;
    }
    nd->push();
    int lv = _query_sum(a, b, nd->left, l, (l+r)/2);
    int rv = _query_sum(a, b, nd->right, (l+r)/2, r);
    return lv + rv;
  }

public:
  SegmentTree(int n, int *a) : n(n) {
    n0 = 1;
    while(n0 < n) n0 <<= 1;

    Node *nds = new Node[2*n0];
    root = nds;

    nds[0].len = n0;
    for(int i=0; i<n0-1; ++i) {
      nds[i].left = &nds[2*i+1];
      nds[i].right = &nds[2*i+2];
      nds[2*i+1].len = nds[2*i+2].len = (nds[i].len >> 1);
    }

    for(int i=0; i<n; ++i) nds[n0-1+i].init(a[i]);
    for(int i=n; i<n0; ++i) nds[n0-1+i].init_empty();
    for(int i=n0-2; i>=0; i--) nds[i].update();
  }

  void update_min(int a, int b, int x) {
    _update_min(x, a, b, root, 0, n0);
  }

  void update_max(int a, int b, int x) {
    _update_max(x, a, b, root, 0, n0);
  }

  void add_val(int a, int b, int x) {
    _add_val(x, a, b, root, 0, n0);
  }

  void update_val(int a, int b, int x) {
    _update_val(x, a, b, root, 0, n0);
  }

  int query_max(int a, int b) {
    return _query_max(a, b, root, 0, n0);
  }

  int query_min(int a, int b) {
    return _query_min(a, b, root, 0, n0);
  }

  int query_sum(int a, int b) {
    return _query_sum(a, b, root, 0, n0);
  }
};

vector<int> tree[200010];
vector<int> euler;
int v_begin[200010] = {}, v_end[200010] = {};
int idx = 0;

void dfs(int cur, int par){
    v_begin[cur] = idx;
    euler.push_back(cur);
    idx++;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        dfs(e, cur);
        euler.push_back(cur);
        idx++;
    }
    v_end[cur] = idx;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Q;
    cin >> N >> Q;
    int a[200010];
    rep(i,0,N) cin >> a[i];
    rep(i,0,N-1){
        int u,v;
        cin >> u >> v;
        u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(0, -1);
    int v[400010] = {};
    rep(i,0,euler.size()){
        v[i] = a[euler[i]];
    }

    SegmentTree sg_even(euler.size()+10, v), sg_odd(euler.size()+10, v);

    while(Q--){
        int t;
        cin >> t;
        if(t == 1){
            int x,y;
            cin >> x >> y;
            x--;
            if(v_begin[x] % 2 == 0){
                sg_even.add_val(v_begin[x], v_end[x], y);
                sg_odd.add_val(v_begin[x], v_end[x], -y);
            }else{
                sg_odd.add_val(v_begin[x], v_end[x], y);
                sg_even.add_val(v_begin[x], v_end[x], -y);  
            }

        }else{
            int x;
            cin >> x;
            x--;
            if(v_begin[x] % 2 == 0){
                print(sg_even.query_sum(v_begin[x], v_begin[x]+1));
            }else{
                print(sg_odd.query_sum(v_begin[x], v_begin[x]+1));
            }
        }
    }
    

}