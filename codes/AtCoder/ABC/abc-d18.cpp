#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    int x;
    int y;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;
template <typename Iterator>
inline bool next_combination(const Iterator first, Iterator k, const Iterator last){
    /* Credits: Thomas Draper */
    // do{}while(next_combination(v.begin(),v.begin() + K,  v.end()));
    if ((first == last) || (first == k) || (last == k)) return false;
    Iterator itr1 = first;
    Iterator itr2 = last;
    ++itr1;
    if (last == itr1) return false;
    itr1 = k;
    --itr2;
    while (first != itr1){
        if (*--itr1 < *itr2){
            Iterator j = k;
            while (!(*itr1 < *j)) ++j;
            iter_swap(itr1,j);
            ++itr1;
            ++j;
            itr2 = k;
            rotate(itr1,j,last);
            while (last != j){
            ++j;
            ++itr2;
            }
            rotate(k,itr2,last);
            return true;
        }
    }
    rotate(first,k,last);
    return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M,P,Q,R;
    cin >> N >> M >> P >> Q >> R;
    ll x[400], y[400], z[400];
    rep(i,0,R){
        cin >> x[i] >> y[i] >> z[i];
    }
    vector<ll> women(N), men(M);
    iota(women.begin(), women.end(), 1);
    // printa(women,N);
    iota(men.begin(), men.end(), 1);
    ll ans = 0;
    // print("--");
    do{
        // printa(women,P);
        ll men_cnt[20] = {};
        rep(i,0,R){
            bool is_exist = false;
            rep(j,0,P){
                if(women[j] == x[i]) is_exist = true;
            }
            if(is_exist){
                men_cnt[y[i]] += z[i];
            }
        }
        sort(men_cnt, men_cnt+M+1, greater<ll>());
        ll tt = 0;
        rep(i,0,Q){
            tt += men_cnt[i];
        }
        // printa(men_cnt,M);
        ans = max(ans, tt);
        // printa(women, P);

        // printa(women,P);
    }while(next_combination(women.begin(), women.begin() +P, women.end()));
    print(ans);



}
