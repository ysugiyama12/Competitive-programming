#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<iomanip>
#include<set>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define brep(index,num) for(int index=num-1;index>=0;index--)
#define brep1(index,num) for(int index=num;index>0;index--)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-7
#define mp(a1,a2) make_pair(a1,a2)
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef long double ld;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
int main(){
	int N,M;
	int x[20],y[20];
	int rel[20][20]={};//rel[i][j]=1:iからjへ有効辺がある
	scan(N>>M);
	rep(i,M){
		scan(x[i]>>y[i]);
		x[i]--; y[i]--;
		rel[x[i]][y[i]]=1;
	}
	int twoNth=(1<<N);
	ll dp[twoNth]={};
	dp[0]=1;
	rep(bit,twoNth){
		rep(i,N){
			if(((bit>>i)&1)==0){
				int flag=1;
				rep(j,N){
					if((bit>>j)&1){
						if(rel[i][j]){
							flag=0;
							break;
						}
					}
				}
				if(flag){
					dp[bit+(1<<i)]+=dp[bit];
				}
			}
		}
	}
	prin(dp[twoNth-1]);
	return 0;
}
