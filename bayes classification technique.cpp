#include <iostream>
#include <cstring>
using namespace std;

void classify(int n, int tuples);

// Global variables (as in lab manuals)
char cls[10][20], titems[50][20][20], attr[10][20];
int pcount[20], countc[10], fc = 0;
float p[10], prob[50], pre[10], result[10];

int main()
{
    char tup[15][20];
    int i, j, n, tuples, k, ans = 0;
    int c = 0;

    cout << "enter no of attributes:";
    cin >> n;

    cout << "enter no of tuples:";
    cin >> tuples;

    cout << "enter " << n << " attributes\n";
    for (i = 0; i < n; i++)
        cin >> attr[i];

    for (i = 0; i < tuples; i++)
    {
        cout << "enter tuple" << i + 1 << endl;
        for (j = 0; j < n; j++)
            cin >> titems[i][j];
    }

    cout << "enter test tuple\n";
    for (i = 0; i < n - 1; i++)
        cin >> tup[i];

    // Find classes and their counts
    classify(n, tuples);

    // Prior probability P(class)
    for (i = 0; i < fc; i++)
        p[i] = countc[i] / (float)tuples;

    // Conditional probability P(attribute | class)
    for (i = 0; i < fc; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            pcount[j] = 0;

            for (k = 0; k < tuples; k++)
            {
                if (strcmp(titems[k][j], tup[j]) == 0 &&
                    strcmp(titems[k][n - 1], cls[i]) == 0)
                {
                    pcount[j]++;
                }
            }

            // Laplace smoothing
            if (pcount[j] != 0)
                prob[c++] = pcount[j] / (float)countc[i];
            else
                prob[c++] = (pcount[j] + 1) / (float)countc[i];
        }
    }

    // Multiply probabilities correctly
    int idx = 0;
    int attrs = n - 1;

    for (i = 0; i < fc; i++)
    {
        pre[i] = 1.0;
        for (j = 0; j < attrs; j++)
            pre[i] *= prob[idx++];
    }

    // Final probability
    for (i = 0; i < fc; i++)
    {
        result[i] = pre[i] * p[i];
        if (i > 0 && result[i] > result[ans])
            ans = i;
    }

    cout << "The test tuple belongs to " << cls[ans] << " class\n";

    return 0;
}

// Function to find unique classes and count
void classify(int p, int q)
{
    int i, k, t;

    strcpy(cls[fc++], titems[0][p - 1]);

    for (i = 1; i < q; i++)
    {
        t = 0;
        for (k = 0; k < fc; k++)
        {
            if (strcmp(titems[i][p - 1], cls[k]) == 0)
            {
                t = -1;
                break;
            }
        }
        if (t != -1)
            strcpy(cls[fc++], titems[i][p - 1]);
    }

    for (i = 0; i < fc; i++)
    {
        countc[i] = 0;
        for (k = 0; k < q; k++)
        {
            if (strcmp(titems[k][p - 1], cls[i]) == 0)
                countc[i]++;
        }
    }
}
