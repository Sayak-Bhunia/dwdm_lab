#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int bins, n;
    cout << "enter no. of bins = " <<endl;
    cin >> bins;
    cout << "enter no. of eles per bin = " <<endl;
    cin >> n;
    vector<int> a(bins*n);
    cout << "enter elements = " <<endl;
    for(int i=0;i<bins*n;i++) cin >> a[i];
    cout << "given elements = " <<endl;
    for(int i=0;i<bins;i++) {
        for(int j=0;j<n;j++) cout << a[i*n+j] << "\t";
        cout <<endl;
    }
    cout << "bin boundaries are = " <<endl;
    for(int i=0;i<bins;i++) {
        int l = a[i*n], h = a[i*n+n-1];
        for(int j=0;j<n;j++) {
            int val = a[i*n+j];
            if(abs(val-l)<=abs(val-h)) cout << l << "\t";
            else cout << h << "\t";
        }
        cout <<endl;
    }
}
