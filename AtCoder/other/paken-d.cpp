#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;
bool comp(pair< lpair, ll> l1, pair< lpair, ll> l2){
    if(l1.first.first == l2.first.first){
        return (l1.first.second < l2.first.second);
    }
    return l1.first.first < l2.first.first;
}
char D[150010], F[150010];
ll T[150010], P[150010];
char ss[500010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    string S;
    ll M;
    cin >> N;
    cin >> S;
    cin >> M;
    rep(i,0,M){
        cin >> D[i] >> F[i];
    }
    ll Q;
    cin >> Q;
    rep(i,0,Q){
        cin >> T[i] >> P[i];
    }
    vector< pair<lpair, ll> > lp;
    rep(i,0,Q){
        lp.push_back(make_pair(make_pair(T[i], P[i]),i));
    }
    sort(lp.begin(), lp.end(), comp);

    ll start_pos = 160000;
    rep(i,0,N){
        ss[start_pos + i] = S[i];
    }
    ll end_pos = start_pos + N-1;
    ll t_cnt = 0;
    char ans[150010] = {};
    rep(i,0,Q){
        ll tt = lp[i].first.first;
        ll pp = lp[i].first.second;
        ll pos = lp[i].second;
        while(t_cnt < tt){
            // print2(D[t_cnt], F[t_cnt]);
            if(D[t_cnt] == 'L'){
                if(F[t_cnt] == 'B'){
                    ll b_pos = -1;
                    rep(j,start_pos, end_pos+1){
                        if(ss[j] == 'B'){
                            b_pos = j;
                            break;
                        }
                    }
                    if(b_pos != -1){
                        rep(j,start_pos, b_pos){
                            ss[j] = 'B';
                        }
                    }
                    ss[start_pos-1] = 'B';
                }else{
                    ll w_pos = -1;
                    rep(j,start_pos, end_pos+1){
                        if(ss[j] == 'W'){
                            w_pos = j;
                            break;
                        }
                    }
                    if(w_pos != -1){
                        rep(j,start_pos, w_pos){
                            ss[j] = 'W';
                        }
                    }
                    ss[start_pos-1] = 'W';

                }
                start_pos--;

            }else{
                if(F[t_cnt] == 'B'){
                    ll b_pos = -1;
                    rrep(j,end_pos, start_pos){
                        if(ss[j] == 'B'){
                            b_pos = j;
                            break;
                        }
                    }
                    if(b_pos != -1){
                        rrep(j,end_pos, b_pos+1){
                            ss[j] = 'B';
                        }
                    }
                    ss[end_pos+1] = 'B';
                }else{
                    ll w_pos = -1;
                    rrep(j,end_pos, start_pos){
                        if(ss[j] == 'W'){
                            w_pos = j;
                            break;
                        }
                    }
                    if(w_pos != -1){
                        rrep(j,end_pos, w_pos+1){
                            ss[j] = 'W';
                        }
                    }
                    ss[end_pos+1] = 'W';
                    
                }
                end_pos++;

            }
            // rep(k,start_pos, end_pos+1){
            //     cout << ss[k];
            // }
            // cout << endl;
            t_cnt++;
        }
        // print(pos);
        ans[pos] = ss[start_pos + pp - 1];
    }
    rep(i,0,Q){
        print(ans[i]);
    }
}
