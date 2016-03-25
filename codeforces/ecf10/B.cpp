#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define MP(x,y) make_pair(x,y)



int main(){
int n;
cin >> n ;
vector<int> arr(n,0);
for(int i=0; i<n; i++) {
cin >> arr[i];
}
sort(arr.begin(), arr.end());
int i=0, j=n-1;
vector<int> resarr;
resarr.push_back(arr[i++]);
for(int x = 1; x<n; x++){
if(x%2){
resarr.push_back(arr[j]);
if(resarr[x] < resarr[x-1]) {
cout << -1 << endl;
return 0;
}
j--;
}else{
resarr.push_back(arr[i]);
if(resarr[x] > resarr[x-1]) {
cout << -1 << endl;
return 0;
}
i++;
}
}
for(int x = 0; x<n; x++){
cout << resarr[x] << " ";
}
cout << endl;
return 0;
}