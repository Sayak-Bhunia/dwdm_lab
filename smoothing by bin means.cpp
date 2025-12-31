#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int bins,n;
    double sum = 0.0, mean = 0.0;
    cout << "no. of bins = " <<endl;
    cin >> bins;
    cout << "no. of eles per bins = " <<endl;
    cin >> n;
    vector<int> a(bins*n);
    for(int i=0;i<bins*n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    cout << "given eles are\n";
    for(int i=0;i<bins;i++) {
        for(int j=0;j<n;j++) cout << a[i*n+j] << "\t";
        cout <<endl;
    }
    cout << "mean vals are\n";
    for(int i=0;i<bins;i++) {
        sum = 0;
        for(int j=0;j<n;j++) sum += a[i*n+j];
        mean = sum/n;
        for(int j=0;j<n;j++) cout << mean << " ";
        cout <<endl;
    }
}
