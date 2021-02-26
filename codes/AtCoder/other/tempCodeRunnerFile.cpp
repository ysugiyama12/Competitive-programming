    ll ans = 0;
    rep(i,0,M){
        ll val = (c[i] - 1) + (d[i] * c[i]) / 10;
        ans += val;
    }
    vector<ll> nxt[10];
    rep(n,0,10){
        ll cur = n;
        nxt[n].push_back(cur);
        while(1){
            cur += n;
            if(cur >= 10){
                cur = cur / 10 + cur % 10;
            }
            // print(n, cur);
            if(cur == nxt[n][0]) break;
            nxt[n].push_back(cur);
        }
    }
    ll num[200010] = {};
    rep(i,0,M){
        ll sz = nxt[d[i]].size();
        ll amari = c[i] % sz;
        if(amari == 0){
            num[i] = nxt[d[i]][sz-1];
        }else{
            num[i] = nxt[d[i]][amari-1];
        }
    }
    // printa(num, M);
    rep(i,0,10){
        rep(j,0,nxt[i].size()){
            cout << nxt[i][j] << " ";
        }
        cout << endl;
    }
    ll sum = 0;
    rep(i,0,M) sum += num[i];
    ans += (M-1) + sum / 10;

    print(ans);