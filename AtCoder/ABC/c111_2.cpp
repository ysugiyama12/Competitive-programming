#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define INF (1e9)
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    ll v[100010];
    cin >> N;
    rep(i,0,N){
        cin >> v[i];
    }
    map<ll, ll> mp_even, mp_odd;
    rep(i,0,N){
        if(i % 2 == 0){
            mp_even[v[i]]++;
        }else{
            mp_odd[v[i]]++;
        }
    }

    vector< pair<ll, ll> > p_even, p_odd;
    rep(i,1,100001){
        p_even.push_back(make_pair(mp_even[i], i));
        p_odd.push_back(make_pair(mp_odd[i], i));
    }
    sort(p_even.begin(), p_even.end(), greater< pair<ll,ll> >());
    sort(p_odd.begin(), p_odd.end(), greater< pair<ll,ll> >());
    ll ans = 0;
    if(p_even[0].second != p_odd[0].second){
        ans = N - p_even[0].first - p_odd[0].first;
    }else{
        ans = N - p_even[0].first - p_odd[1].first;
        ans = min(ans, N - p_even[1].first - p_odd[0].first);
    }
    print(ans);


}
