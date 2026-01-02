#include<bits/stdc++.h>
using namespace std;

char cls[10][20];
int countCls[10], fc = 0;

void findClass(char items[][20][20], int n, int tuples) {
    strcpy(cls[fc++], items[0][n-1]);
    for(int i=1;i<tuples;i++) {
        bool f = false;
        for(int j=0;j<fc;j++) {
            if(strcmp(items[i][n-1], cls[j]) == 0) {
                f = true;
                break;
            }
        }
        if(!f) strcpy(cls[fc++], items[i][n-1]);
    }
    for(int i=0;i<fc;i++) {
        countCls[i] = 0;
        for(int j=0;j<tuples;j++) {
            if(strcmp(items[j][n-1], cls[i]) == 0) countCls[i]++;
        }
    } 
}

int main() {
    int j, k, n, tuples, res = 0, pc[20], c = 0;
    char attributes[10][20], items[50][20][20], tup[15][20];
    float p[10], prob[50], pre[10], result[10];
    cout << "enter no of attributes = ";
    cin >> n;
    cout << "enter no of tuples = ";
    cin >> tuples;
    cout << "enter" << n << " attributes" <<endl;
    for(int i=0;i<n;i++) cin >> attributes[i];
    for(int i=0;i<tuples;i++) {
        cout << "enter tuple" << i+1 <<endl;
        for(int j=0;j<n;j++) cin >> items[i][j];
    }
    cout << "enter test tuple = " <<endl;
    for(int i=0;i<n-1;i++) cin >> tup[i];
    findClass(items, n, tuples);
    for(int i=0;i<fc;i++) p[i] = countCls[i]/(float)tuples;
    for(int i=0;i<fc;i++) {
        for(int j=0;j<n-1;j++) {
            pc[j] = 0;
            for(int k=0;k<tuples;k++) {
                if(strcmp(items[k][j], tup[j]) == 0 && strcmp(items[k][n-1], cls[i]) == 0) pc[j]++;
            }
            prob[c++] = (pc[j] == 0)?(1.0/countCls[i]):(pc[j]/(float)countCls[i]);
        }
    }
    c = 0;
    for(int i=0;i<fc;i++) {
        pre[i] = 1.0;
        for(int j=0;j<n-1;j++) pre[i] *= prob[c++];
    }
    for(int i=0;i<fc;i++) {
        result[i] = pre[i]*p[i];
        if(i>0 && result[i]>result[res]) res = i;
    }
    cout << "test tuple belongs to = " << cls[res] << " class" <<endl;
}













#include <stdio.h>
#include <string.h>

void class(int, int);

char cls[10][20], items[50][20][20], attr[10][20];
char tup[15][20];
int pcount[20], count[10], fc = 0;
float p[10], prob[50], pre[10], result[10];

int main()
{
    int i, j, n, tuples, k, ans = 0, c = 0;

    printf("enter no of attributes:");
    scanf("%d", &n);

    printf("enter no of tuples:");
    scanf("%d", &tuples);

    printf("enter %d attributes\n", n);
    for (i = 0; i < n; i++)
        scanf("%s", attr[i]);

    for (i = 0; i < tuples; i++)
    {
        printf("enter tuple%d\n", i + 1);
        for (j = 0; j < n; j++)
            scanf("%s", items[i][j]);
    }

    printf("enter test tuple\n");
    for (i = 0; i < n - 1; i++)
        scanf("%s", tup[i]);

    class(n, tuples);

    /* Prior probabilities */
    for (i = 0; i < fc; i++)
        p[i] = count[i] / (float)tuples;

    /* Conditional probabilities */
    for (i = 0; i < fc; i++)
    {
        for (j = 0; j < n - 1; j++)   // FIXED index
        {
            pcount[j] = 0;
            for (k = 0; k < tuples; k++)
            {
                if (strcmp(items[k][j], tup[j]) == 0 &&
                    strcmp(cls[i], items[k][n - 1]) == 0)
                    pcount[j]++;
            }

            /* Laplace smoothing */
            if (pcount[j] == 0)
                prob[c++] = (pcount[j] + 1) / (float)count[i];
            else
                prob[c++] = pcount[j] / (float)count[i];
        }
    }

    /* Posterior probabilities */
    c = 0;
    for (i = 0; i < fc; i++)
    {
        pre[i] = 1.0;
        for (j = 0; j < n - 1; j++)
            pre[i] *= prob[c++];
    }

    for (i = 0; i < fc; i++)
    {
        result[i] = pre[i] * p[i];
        if (i > 0 && result[i] > result[ans])
            ans = i;
    }

    printf("The test tuple belongs to %s class\n", cls[ans]);
    return 0;
}

/* Find unique classes and counts */
void class(int p, int q)
{
    int i, k, t;

    strcpy(cls[fc++], items[0][p - 1]);

    for (i = 1; i < q; i++)
    {
        t = 0;
        for (k = 0; k < fc; k++)
        {
            if (strcmp(items[i][p - 1], cls[k]) == 0)
            {
                t = -1;
                break;
            }
        }
        if (t != -1)
            strcpy(cls[fc++], items[i][p - 1]);
    }

    for (i = 0; i < fc; i++)
    {
        count[i] = 0;
        for (k = 0; k < q; k++)
        {
            if (strcmp(items[k][p - 1], cls[i]) == 0)
                count[i]++;
        }
    }
}



























