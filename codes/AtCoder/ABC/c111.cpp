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
ll v[100010];
ll v1[100010];
ll v2[100010];
vector< pair<ll, ll> > pair1, pair2;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    rep(i,0,N){
        cin >> v[i];
    }

    ll pp[100010];
    map<int,int> odd, even;
    rep(i,0,N){
        if(i % 2 == 0){

        }
    }
    return 0;
    rep(i,0,N){
        if(i % 2 == 0){
            v1[i/2] = v[i];
        }else{
            v2[i/2] = v[i];
        }
    }
    sort(v1, v1 + N/2);
    sort(v2, v2 + N/2);
    ll cnt = 1;
    rep(i,1,N/2){
        if(v1[i] == v1[i-1]){
            cnt++;
        }else{
            pair1.push_back(make_pair(cnt, v1[i-1]));
            cnt = 1;
        }
    }
    pair1.push_back(make_pair(cnt, v1[N/2 - 1]));

    cnt = 1;
    rep(i,1,N/2){
        if(v2[i] == v2[i-1]){
            cnt++;
        }else{
            pair2.push_back(make_pair(cnt, v2[i-1]));
            cnt = 1;
        }
    }
    pair2.push_back(make_pair(cnt, v2[N/2 - 1]));
    sort(pair1.begin(), pair1.end());
    sort(pair2.begin(), pair2.end());
    ll n1 = pair1.size();
    ll n2 = pair2.size();
    ll ans = 0;
    if(pair1[n1-1].second != pair2[n2-1].second){
        ans = N - pair1[n1-1].first - pair2[n2-1].first;
    }else{
        if(n2 == 1){
            ans = N - pair1[n1-1].first;
        }else{
            ans = N - pair1[n1-1].first - pair2[n2-2].first;
        }

        if(n1 == 1){
            ans = min(ans, N - pair2[n2-1].first);
        }else{
            ans = min(ans, N - pair2[n2-1].first - pair1[n1-2].first);
        }
    }

    print(ans);



}
