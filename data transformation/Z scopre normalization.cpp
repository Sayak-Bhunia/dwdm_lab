#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "enter no. of eles = " <<endl;
    cin >> n;
    float a[20], sum = 0;
    cout << "enter eles = " <<endl;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        sum += a[i];
    }
    float v;
    cout << "enter v value = " <<endl;
    cin >> v;
    float mean = sum/n;
    float var = 0;
    for(int i=0;i<n;i++) var += pow(a[i] - mean, 2);
    float sd = sqrt(var/n);
    float v1 = (v - mean)/sd;
    cout << fixed << setprecision(6);
    cout << "sum = " << sum <<endl;
    cout << "mean = " << mean <<endl;
    cout << "varieance = " << sd <<endl;
    cout << "v1 value = " << v1 <<endl;
}
