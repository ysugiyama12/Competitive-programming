/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

class SegmentTree {
  struct Node {
    Node *left, *right;
    ll max_v, smax_v, max_c;
    ll min_v, smin_v, min_c;
    ll sum;
    ll len, ladd, lval;

    Node() : left(0), right(0), ladd(0), lval(INF) {}

    void init(ll x) {
      max_v = min_v = sum = x;
      smax_v = -INF; smin_v = INF;
      max_c = min_c = 1;
    }

    void init_empty() {
      max_v = smax_v = -INF;
      min_v = smin_v = INF;
      max_c = min_c = 0;
    }

    void update_max(ll x) {
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

    void update_min(ll x) {
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

    void addall(ll x) {
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

    void updateall(ll x) {
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

  ll n, n0;
  Node *root;

  void _update_min(ll x, ll a, ll b, Node *nd, ll l, ll r) {
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

  void _update_max(ll x, ll a, ll b, Node *nd, ll l, ll r) {
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

  void _add_val(ll x, ll a, ll b, Node *nd, ll l, ll r) {
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

  void _update_val(ll x, ll a, ll b, Node *nd, ll l, ll r) {
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

  ll _query_max(ll a, ll b, Node *nd, ll l, ll r) {
    if(b <= l || r <= a) {
      return -INF;
    }
    if(a <= l && r <= b) {
      return nd->max_v;
    }
    nd->push();
    ll lv = _query_max(a, b, nd->left, l, (l+r)/2);
    ll rv = _query_max(a, b, nd->right, (l+r)/2, r);
    return max(lv, rv);
  }

  ll _query_min(ll a, ll b, Node *nd, ll l, ll r) {
    if(b <= l || r <= a) {
      return INF;
    }
    if(a <= l && r <= b) {
      return nd->min_v;
    }
    nd->push();
    ll lv = _query_min(a, b, nd->left, l, (l+r)/2);
    ll rv = _query_min(a, b, nd->right, (l+r)/2, r);
    return min(lv, rv);
  }

  ll _query_sum(ll a, ll b, Node *nd, ll l, ll r) {
    if(b <= l || r <= a) {
      return 0;
    }
    if(a <= l && r <= b) {
      return nd->sum;
    }
    nd->push();
    ll lv = _query_sum(a, b, nd->left, l, (l+r)/2);
    ll rv = _query_sum(a, b, nd->right, (l+r)/2, r);
    return lv + rv;
  }

public:
  SegmentTree(ll n, ll *a) : n(n) {
    n0 = 1;
    while(n0 < n) n0 <<= 1;

    Node *nds = new Node[2*n0];
    root = nds;

    nds[0].len = n0;
    for(ll i=0; i<n0-1; ++i) {
      nds[i].left = &nds[2*i+1];
      nds[i].right = &nds[2*i+2];
      nds[2*i+1].len = nds[2*i+2].len = (nds[i].len >> 1);
    }

    for(ll i=0; i<n; ++i) nds[n0-1+i].init(a[i]);
    for(ll i=n; i<n0; ++i) nds[n0-1+i].init_empty();
    for(ll i=n0-2; i>=0; i--) nds[i].update();
  }

  void update_min(ll a, ll b, ll x) {
    _update_min(x, a, b, root, 0, n0);
  }

  void update_max(ll a, ll b, ll x) {
    _update_max(x, a, b, root, 0, n0);
  }

  void add_val(ll a, ll b, ll x) {
    _add_val(x, a, b, root, 0, n0);
  }

  void update_val(ll a, ll b, ll x) {
    _update_val(x, a, b, root, 0, n0);
  }

  ll query_max(ll a, ll b) {
    return _query_max(a, b, root, 0, n0);
  }

  ll query_min(ll a, ll b) {
    return _query_min(a, b, root, 0, n0);
  }

  ll query_sum(ll a, ll b) {
    return _query_sum(a, b, root, 0, n0);
  }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll a[200010], p[200010];
    rep(i,0,N) cin >> p[i];
    rep(i,0,N) cin >> a[i];
    ll v[200010] = {};
    SegmentTree sg(N+1, v);
    rep(i,0,N){
        sg.add_val(p[i], N+1, a[i]);
    }
    ll ans = INF;
    rep(i,0,N-1){
        sg.add_val(p[i], N+1, -a[i]);
        sg.add_val(0, p[i], a[i]);
        ll val = sg.query_min(0, N+1);
        ans = min(ans, val);
    }
    print(ans);

}