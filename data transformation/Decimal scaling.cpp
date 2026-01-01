#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int v, i = 0;
    cout << "enter v val = " <<endl;
    cin >> v;
    int tmp = abs(v);
    while(tmp>0) {
        tmp /= 10;
        i++;
    }
    cout << fixed << setprecision(6);
    cout << "normalized val = " << v/pow(10, i) <<endl;
}
