#include <iostream>
#include <cstring>
using namespace std;

void findClass(int, int);

char cls[10][20], items[50][20][20], attr[10][20];
char tup[15][20];
int pcount[20], countCls[10], fc = 0;
float p[10], prob[50], pre[10], result[10];

int main()
{
    int i, j, n, tuples, k, ans = 0, c = 0;

    cout << "enter no of attributes:";
    cin >> n;

    cout << "enter no of tuples:";
    cin >> tuples;

    cout << "enter " << n << " attributes" << endl;
    for (i = 0; i < n; i++)
        cin >> attr[i];

    for (i = 0; i < tuples; i++)
    {
        cout << "enter tuple" << i + 1 << endl;
        for (j = 0; j < n; j++)
            cin >> items[i][j];
    }

    cout << "enter test tuple" << endl;
    for (i = 0; i < n - 1; i++)
        cin >> tup[i];

    findClass(n, tuples);

    /* Prior probabilities */
    for (i = 0; i < fc; i++)
        p[i] = countCls[i] / (float)tuples;

    /* Conditional probabilities */
    for (i = 0; i < fc; i++)
    {
        for (j = 0; j < n - 1; j++)
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
                prob[c++] = (pcount[j] + 1) / (float)countCls[i];
            else
                prob[c++] = pcount[j] / (float)countCls[i];
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

    cout << "The test tuple belongs to " << cls[ans] << " class" << endl;
    return 0;
}

void findClass(int p, int q)
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
        countCls[i] = 0;
        for (k = 0; k < q; k++)
        {
            if (strcmp(items[k][p - 1], cls[i]) == 0)
                countCls[i]++;
        }
    }
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

