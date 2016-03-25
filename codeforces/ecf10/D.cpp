#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define MP(x,y) make_pair(x,y)

int main(){
    long n;
    cin >> n;
    map<long , int> startedBefore;
    map<long , int> endedBefore;
    vector<pair<long, long> > allpairs(n);
    vector<long> startv(n, 0), endv(n, 0);
    
    long si = 0, ei=0;
    long st, end;
    for(int i=0; i<n; i++) {
        cin >> st >> end;
        startv[i] = st;
        endv[i] = end;
        allpairs[i]= MP(st, end);
    }
    sort(startv.begin(), startv.end());
    sort(endv.begin(), endv.end());
    int segs = 0;
    int ended = 0;
    si = 0, ei=0;
    while(ei<n){
        while(si<n && startv[si] < endv[ei]){
            segs++;
            startedBefore[startv[si]] = segs;
            si++;
        }
        ended++;
        segs--;
        endedBefore[endv[ei]] = ended;
        ei++;
    }
    for(int i=0; i<n; i++) {
        st = allpairs[i].first, end = allpairs[i].second;
        int count  = 0;
        if(endedBefore[end] > startedBefore[st]){
            count =  endedBefore[end]  - startedBefore[st];
        }
        cout << count << endl;
    }
    return 0;
}