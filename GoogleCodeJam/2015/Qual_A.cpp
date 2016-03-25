#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int _t=1; _t<=t; _t++){
        cout << "Case #" << _t << ": ";
        int frnds = 0;
        string k_str ;
        int s_max;
        cin >> s_max >> k_str;
        int standing =0 ;
        for (int Si=0; Si<=s_max; Si++) {
            if(k_str[Si] > '0' && standing<Si){
                frnds += Si - standing;
                standing = Si;
            }
            standing += k_str[Si] -'0';
        }
        cout << frnds << endl;
    }
    return 0;
}