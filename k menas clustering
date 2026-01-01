#include <iostream>
using namespace std;

int main()
{
    int i1, i2, i3, t1, t2, m1, m2, om1, om2;
    int k0[10], k1[10], k2[10];

    cout << "Enter 10 numbers:";
    for (i1 = 0; i1 < 10; i1++)
        cin >> k0[i1];

    cout << "Enter intial mean 1:";
    cin >> m1;
    cout << "Enter intial mean 2:";
    cin >> m2;

    do
    {
        om1 = m1;
        om2 = m2;
        i1 = i2 = i3 = 0;

        for (i1 = 0; i1 < 10; i1++)
        {
            t1 = k0[i1] - m1;
            if (t1 < 0) t1 = -t1;

            t2 = k0[i1] - m2;
            if (t2 < 0) t2 = -t2;

            if (t1 < t2)
                k1[i2++] = k0[i1];
            else
                k2[i3++] = k0[i1];
        }

        t2 = 0;
        for (t1 = 0; t1 < i2; t1++)
            t2 += k1[t1];
        m1 = t2 / i2;

        t2 = 0;
        for (t1 = 0; t1 < i3; t1++)
            t2 += k2[t1];
        m2 = t2 / i3;

        cout << "\nCluster 1:";
        for (t1 = 0; t1 < i2; t1++)
            cout << k1[t1] << " ";
        cout << "\nm1=" << m1;

        cout << "\nCluster 2:";
        for (t1 = 0; t1 < i3; t1++)
            cout << k2[t1] << " ";
        cout << "\nm2=" << m2;
        cout << "\n -------- ";

    } while (m1 != om1 && m2 != om2);

    cout << "\nClusters created";
    return 0;
}
