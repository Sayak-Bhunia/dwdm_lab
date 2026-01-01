#include <bits/stdc++.h>
using namespace std;

int main() {
	int i1, i2, t1, t2, m1, m2, om1, om2;
	int k0[10], k1[10], k2[10];
	cout << "enter 10 eles = ";
	for(int i=0;i<10;i++) cin >> k0[i];
	cout << "enter initial mean 1 = ";
	cin >> m1;
	cout << "enter initial mean 2 = ";
	cin >> m2;
	do {
	    om1 = m1;
	    om2 = m2;
	    i1 = i2 = 0;
	    for(int i=0;i<10;i++) {
	        t1 = k0[i] - m1;
	        if(t1<0) t1 = -t1;
	        t2 = k0[i] - m2;
	        if(t2<0) t2 = -t2;
	        if(t1<t2) k1[i1++] = k0[i];
	        else k2[i2++] = k0[i];
	    }
	    int sum = 0;
	    for(int i=0;i<i1;i++) sum += k1[i];
	    m1 = sum/i1;
	    sum = 0;
	    for(int i=0;i<i2;i++) sum += k2[i];
	    m2 = sum/i2;
	    cout << "\ncluster 1 = ";
	    for(int i=0;i<i1;i++) cout << k1[i] << " ";
	    cout << "\nm1 = " << m1;
	    cout << "\nclsuter 2 = ";
	    for(int i=0;i<i2;i++) cout << k2[i] << " ";
	    cout << "\nm2 = " << m2;
	    cout << "\n ------------";
	} while(m1 != om1 && m2 != om2);
	cout << "\nclsuters created";
}













#include<stdio.h>

void main()
{
    int i1, i2, i3, t1, t2, m1, m2, om1, om2;
    int k0[10], k1[10], k2[10];

    printf("Enter 10 numbers:");
    for (i1 = 0; i1 < 10; i1++)
        scanf("%d", &k0[i1]);

    printf("Enter intial mean 1:");
    scanf("%d", &m1);
    printf("Enter intial mean 2:");
    scanf("%d", &m2);

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

        printf("\nCluster 1:");
        for (t1 = 0; t1 < i2; t1++)
            printf("%d ", k1[t1]);
        printf("\nm1=%d", m1);

        printf("\nCluster 2:");
        for (t1 = 0; t1 < i3; t1++)
            printf("%d ", k2[t1]);
        printf("\nm2=%d", m2);

        printf("\n -------- ");

    } while (m1 != om1 && m2 != om2);

    printf("\nClusters created");
}
