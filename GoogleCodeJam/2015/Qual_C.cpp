#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define MP(x,y) make_pair(x,y)

map<pair<int, int>, int> mT;
map<char, int> val;
void init(){
// 1, 2, 3, 4,
for(int i=1; i<=4; i++){
mT[MP(1,i)] = i;
mT[MP(-1,i)] = -i;
mT[MP(1,-i)] = -i;
mT[MP(-1,-i)] = i;
mT[MP(i,1)] = i;
mT[MP(i,-1)] = -i;
mT[MP(-i,1)] = -i;
mT[MP(-i,-1)] = i;
}
mT[MP(2,3)] = 4;
mT[MP(2,4)] = -3;
mT[MP(3,4)] = 2;
mT[MP(3,2)] = -4;
mT[MP(4,3)] = -2;
mT[MP(4,2)] = 3;
for(int i=2; i<=4; i++){
mT[MP(i,i)] = -1;
mT[MP(-i,-i)] = -1;
mT[MP(-i,i)] = 1;
mT[MP(i,-i)] = 1;
for(int j=2; j<=4; j++){
if(i==j) continue;
mT[MP(-j,i)] = -mT[MP(j,i)];
mT[MP(-j,-i)] = mT[MP(j,i)];
mT[MP(j,-i)] = -mT[MP(j,i)];

mT[MP(-i,j)]  = -mT[MP(i,j)];
mT[MP(i,-j)]  = -mT[MP(i,j)];
mT[MP(-i,-j)] =  mT[MP(i,j)];
}
}
val['i'] = 2;
val['j'] = 3;
val['k'] = 4;
}

bool isNeg1Poss(string &s, long long L, long long X){
int all_mul = 1;
if(X%4==0) return false;
for(long long i=0; i<L; i++){
all_mul = mT[MP(all_mul, val[s[i]])];
}
int temp_mul = 1;
for(long long i=0; i<X%4; i++) {
temp_mul = mT[MP(temp_mul, all_mul)];
}
if(temp_mul != -1) return false;
return true;
}

bool if_i_j_pos(string &s, long long L, long long X) {
int max_rnd = 4, temp_val = val[s[0]];
int start_ind = 0, ind = 0, rnd = 0;;
while(temp_val != 2 && rnd < max_rnd && X>0){
ind = (ind+1)%L;
temp_val = mT[MP(temp_val, val[s[ind]])];
if(ind == start_ind) rnd++;
if(ind==0) X--;
}
if(temp_val!=2) return false;
if(X==0) return false;
ind = (ind+1)%L;
if(ind==0) X--;
start_ind = ind;
temp_val = val[s[ind]];
while(temp_val != 3 && rnd < max_rnd && X>0){
ind = (ind+1)%L;
temp_val = mT[MP(temp_val, val[s[ind]])];
if(ind == start_ind) rnd++;
if(ind==0) X--;
}
if(temp_val!=3) return false;
return true;
}

int main(){
init();
int t;
cin >> t;
for(int _t=1; _t<=t; _t++){
cout << "Case #" << _t << ": ";
string s;
long long L, X;
cin >> L >> X;
cin >> s;
if(!isNeg1Poss(s, L, X)) {
cout << "NO" << endl;
continue;
}
if(!if_i_j_pos(s, L, X)) {
cout << "NO" << endl;
continue;
}
cout << "YES" << endl;
}
return 0;
}