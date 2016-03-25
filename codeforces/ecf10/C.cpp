#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define MP(x,y) make_pair(x,y)

int check(int fi, vector<int> &done, vector< vector<int>  > &foe) {
    int maxInd = -1;
    for(int i=0; i<foe[fi].size(); i++){
        if(done[foe[fi][i]] > -1)
            maxInd = max(maxInd, done[foe[fi][i]]);
    }
    return maxInd+1;
}

int main(){
    int n, m;
    cin >> n >> m ;
    vector<int> p(n,0);
    vector< vector<int>  > foe(n);
    for(int i=0; i<n; i++) {
        cin >> p[i];
        p[i]--;
    }
    int u,v;
    for(int i=0; i<m; i++){
        cin >> u >> v ;
        u--, v--;
        foe[u].push_back(v);
        foe[v].push_back(u);
    }
    vector<int> done(n, -1);
    long long ans = n;
    done[p[0]] = 0;
    int fi = 1, bi=0;
    while(fi < n){
        bi = max(check(p[fi], done, foe), bi);
        ans += fi-bi;
        done[p[fi]] = fi;
        fi++;
    }
    cout << ans << endl;
    return 0;
}