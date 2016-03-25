#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    int D, ans, maxP ;
    vector<int> P(1000,0);
    for(int _t=1; _t<=t; _t++){
        cout << "Case #" << _t << ": ";
        maxP = 0;
        cin >> D;
        for(int i=0; i<D; i++){
            cin >> P[i];
            maxP = max(maxP, P[i]);
        }
        ans = maxP;
        for(int p = 1; p<maxP; p++){
            int temp_ans = p;
            for(int i=0; i<D; i++){
                if(P[i] <= p) continue;
                if(P[i]%p)
                    temp_ans += P[i]/p;
                else
                    temp_ans += P[i]/p - 1;
            }
            ans = min(ans, temp_ans);
        }
        cout << ans << endl;
    }
    return 0;
}