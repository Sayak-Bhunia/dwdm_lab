#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    float min, max, newmin, newmax, v;
    cin >> min >> max >> newmin >> newmax >> v;
    float y = ((v - min)/(max - min))*(newmax - newmin) + newmin;
    cout << fixed << setprecision(6);
    cout << "normalized val = " << y <<endl;
}
