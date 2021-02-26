#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
// const ll INF = 1e18;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define rREP(i,m,n) for(ll i = (m); i >= (n); i--)
#define ALL(c) (c).begin(), (c).end()
#define print(x) cout << (x) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;

int INF = 1e9;

struct LazySegmentTree {
private:
    int n;
    //lazyを追加
    vector<long long> node, lazy;

public:
    LazySegmentTree(vector<long long> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2 * n - 1);
        lazy.resize(2 * n - 1, 0);

        for (int i = 0; i < sz; i++) node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--) node[i] = node[i * 2 + 1] + node[i * 2 + 2];
    }

// k 番目のノードについて遅延評価を行う
void eval(int k, int l, int r) {

    // 遅延配列が空でない場合、自ノード及び子ノードへの
    // 値の伝播が起こる
    if (lazy[k] != 0) {
        node[k] += lazy[k];

        // 最下段かどうかのチェックをしよう
        // 子ノードは親ノードの 1/2 の範囲であるため、
        // 伝播させるときは半分にする（区間に一様に値を足すとすれば、半分に割るというのも納得がいく）
        if (r - l > 1) {
            lazy[2 * k + 1] += lazy[k] / 2;
            lazy[2 * k + 2] += lazy[k] / 2;
        }

        // 伝播が終わったので、自ノードの遅延配列を空にする
        lazy[k] = 0;
    }
}

void add(int a, int b, long long x, int k = 0, int l = 0, int r = - 1) {
    if(r < 0) r = n;

    // k 番目のノードに対して遅延評価を行う
    eval(k, l, r);

    // 範囲外なら何もしない
    if (b <= l || r <= a) return;
    
    // 完全に被覆しているならば、遅延配列に値を入れた後に評価
    if (a <= l && r <= b) {
        lazy[k] += (r - l) * x;
        eval(k, l, r);
    }

    // そうでないならば、子ノードの値を再帰的に計算して、
    // 計算済みの値をもらってくる
    else {
        add(a, b, x, 2 * k + 1, l, (l + r) / 2);
        add(a, b, x, 2 * k + 2, (l + r) / 2, r);
        node[k] = node[2 * k + 1] + node[2 * k + 2];
    }
}

long long getsum(int a, int b, int k = 0, int l = 0, int r = - 1) {
    if (r < 0) r = n;
    if (b <= l || r <= a) return 0;

    // 関数が呼び出されたら評価！
    eval(k, l, r);
    if(a <= l && r <= b) return node[k];
    long long vl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);
    long long vr = getsum(a, b, 2 * k + 2, (l + r) / 2, r);
    return vl + vr;
}

};



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    ll d,a;
    cin >> d >> a;
    vector<pair<ll, ll> > enemy(n);
    rep(i,n)
    {
        ll x,h;
        cin >> x >> h;
        enemy[i].first = x;
        enemy[i].second = h;
    }
    sort(enemy.begin(), enemy.end());
    vector<ll> health(n);
    vector<ll> zahyo(n);
    rep(i,n) health[i] = enemy[i].second;
    rep(i,n) zahyo[i] = enemy[i].first;
    // rep(i,n)
    // {
    //     cout << i << " " << health[i] << " " << zahyo[i] << endl;
    // }
    // ok

    LazySegmentTree seg(health);

    ll ans = 0;
    rep(i,n)
    {
        if (seg.getsum(i,i+1)<0) continue;
        int distance = upper_bound(zahyo.begin(), zahyo.end(), zahyo[i]+2*d) - zahyo.begin();
        ll tmp_n = seg.getsum(i,i+1) / a;
        if (seg.getsum(i,i+1)%a!=0) tmp_n++;
        // cout << i << " " << distance << " " << " " << seg.getsum(i,i+1) << " " << tmp_n << endl;
        seg.add(i, distance, tmp_n * a * (ll)(-1));
        ans += tmp_n;
    }
    cout << ans << endl;

}


