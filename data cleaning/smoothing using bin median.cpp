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
    cout << "given eles are\n";
    for(int i=0;i<bins;i++) {
        for(int j=0;j<n;j++) cout << a[i*n+j] << " ";
        cout <<endl;
    }
    cout << "median vals are\n";
    cout << fixed << setprecision(6);
    for(int i=0;i<bins;i++) {
        median = a[i*n+n/2];
        for(int j=0;j<n;j++) cout << median << " ";
        cout <<endl;
    }
}
