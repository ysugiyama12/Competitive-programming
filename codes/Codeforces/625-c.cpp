/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const int MOD = 1e9+7;
const int INF = 2e9 + 100;
#define rep(i,m,n) for(int i=(m);i<(n);i++)
#define rrep(i,m,n) for(int i=(m);i>=(n);i--)
#define printa(x,n) for(int i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
int a[200010], ca[200010];
int b[200010], cb[200010];

int x[200010], y[200010], z[200010];
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

    void addall(int x) {
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

    void updateall(int x) {
      max_v = min_v = x;
      smax_v = -INF; smin_v = INF;
      max_c = min_c = len;

      sum = len * x;
      lval = x; ladd = 0;
    }

    void push() {

      if(lval != INF) {
        left->updateall(lval);
        right->updateall(lval);
        lval = INF;
        return;
      }

      if(ladd != 0) {
        left->addall(ladd);
        right->addall(ladd);
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
      nd->addall(x);
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
      nd->updateall(x);
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
int tmp[400010] = {};
// SegmentTree sg(200010, tmp);
SegmentTree sg_sum(400020, tmp);

typedef struct {
    int x;
    int y;
    int z;
} Q;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M,P;
    scanf("%d %d %d", &N, &M, &P);
    rep(i,0,N) scanf("%d %d", &a[i], &ca[i]);
    rep(i,0,M) scanf("%d %d", &b[i], &cb[i]);
    rep(i,0,P) scanf("%d %d %d", &x[i], &y[i], &z[i]);

    vector<int> va, vb;
    va.push_back(INF);
    va.push_back(-INF);
    vb.push_back(INF);
    vb.push_back(-INF);
    rep(i,0,N){
        va.push_back(a[i]);
    }
    rep(i,0,M){
        vb.push_back(b[i]);
    }
    rep(i,0,P){
        va.push_back(x[i]);
        vb.push_back(y[i]);
    }
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    va.erase(unique(va.begin(), va.end()), va.end());
    vb.erase(unique(vb.begin(), vb.end()), vb.end());
    rep(i,0,N){
        int p = lower_bound(va.begin(), va.end(), a[i]) - va.begin();
        a[i] = p;
    }
    rep(i,0,M){
        int p = lower_bound(vb.begin(), vb.end(), b[i]) - vb.begin();
        b[i] = p;
    }
    rep(i,0,P){
        int p = lower_bound(va.begin(), va.end(), x[i]) - va.begin();
        x[i] = p;
        p = lower_bound(vb.begin(), vb.end(), y[i]) - vb.begin();
        y[i] = p;
    }

    vector<lpair> lp_a;
    rep(i,0,N){
        lp_a.push_back({a[i], ca[i]});
    }
    sort(lp_a.begin(), lp_a.end());
    rep(i,0,N){
        a[i] = lp_a[i].first;
        ca[i] = lp_a[i].second;
    }

    int mp[400010] = {};

    rep(i,0,M){
        if(mp[b[i]] == 0){
            mp[b[i]] = cb[i];
        }else{
            mp[b[i]] = min(mp[b[i]], cb[i]);
        }
    }
    int MAX_NUM = 400010;
    sg_sum.add_val(1, MAX_NUM, -INF);
    // print("==debug==");
    rep(i,0,MAX_NUM){
        if(mp[i] != 0){
            sg_sum.update_max(1, i+1, -mp[i]);
        }
    }
    // for(auto &e: mp){
    //     int val = -e.second;
    //     sg_sum.update_max(1, e.first+1, val);
    // }
    int idx = 0;
    int ans = -INF;
    vector<Q> monster;
    rep(i,0,P){
        monster.push_back({x[i], y[i], z[i]});
    }
    sort(monster.begin(), monster.end(), [](Q q1, Q q2){
        return q1.x < q2.x;
    });

    rep(i,0,N){
        int res = - ca[i];
        while(idx < P){
            if(a[i] > monster[idx].x){
                sg_sum.add_val(monster[idx].y+1, MAX_NUM, monster[idx].z);
                idx++;
            }else{
                break;
            }
        }
        res += sg_sum.query_max(1, MAX_NUM);
        ans = max(ans, res);
    }
    print(ans);

    

}