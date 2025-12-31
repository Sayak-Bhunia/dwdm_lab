#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int bins,n;
    double sum = 0.0, median = 0.0;
    cout << "no. of bins = " <<endl;
    cin >> bins;
    cout << "no. of eles per bins = " <<endl;
    cin >> n;
    vector<int> a(bins*n);
    for(int i=0;i<bins*n;i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    cout << "mean vals are\n";
    for(int i=0;i<bins;i++) {
        int l = a[i*n], h = a[i*n+n-1];
        for(int j=0;j<n;j++) {
            int val = a[i*n+j];
            if(abs(val-l)<=val(val-h)) cout << l << " ";
            else cout << h << " ";
        }
        cout <<endl;
    }
}
