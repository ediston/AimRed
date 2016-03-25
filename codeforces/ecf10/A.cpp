#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define MP(x,y) make_pair(x,y)



int main(){
    int a, b, h1, h2;
    cin >> h1 >> h2 >> a >> b;
    if(h2 <= h1+8*a){
        cout << 0 << endl;
        return 0;
    }
    if(b>=a){
        cout << -1 << endl;
        return 0;
    }
    int days = h2 - h1 - 8*a;
    days = (days)/(12*(a-b)) + (days%(12*(a-b)) ? 1 : 0);
    cout << days << endl;
    return 0;
}