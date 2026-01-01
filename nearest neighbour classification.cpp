#include <iostream>
#include <cmath>
using namespace std;

int tuples, attr;
float nearv[20];

void NNC(int d[20][20], int t[1][20]);
int isNear();

int main()
{
    int i, j, k, data[20][20], test[1][20], s;

    cout << "enter no of tuples:";
    cin >> tuples;

    cout << "enter no of attributes:";
    cin >> attr;

    cout << "enter " << tuples << " tuples\n";
    for (i = 0; i < tuples; i++)
    {
        for (j = 0; j < attr; j++)
        {
            cin >> data[i][j];
        }
    }

    cout << "enter test tuple\n";
    for (i = 0; i < attr; i++)
    {
        cin >> test[0][i];
    }

    cout << "enter k value:";
    cin >> k;

    NNC(data, test);

    cout << "The nearest neighbours are\n";
    for (i = 0; i < k; i++)
    {
        s = isNear();
        cout << "(";
        for (j = 0; j < attr; j++)
        {
            cout << data[s][j];
        }
        cout << ")\n";
    }

    return 0;
}

void NNC(int d[20][20], int t[1][20])
{
    int i, j, sum = 0;

    for (i = 0; i < tuples; i++)
    {
        for (j = 0; j < attr; j++)
        {
            sum += (d[i][j] - t[0][j]) * (d[i][j] - t[0][j]);
        }
        nearv[i] = sqrt(sum);
        sum = 0;
    }
}

int isNear()
{
    float t = nearv[0];
    int s = 0, i;

    for (i = 1; i < tuples; i++)
    {
        if (t >= nearv[i] && nearv[i] != 999)
        {
            t = nearv[i];
            s = i;
        }
    }
    nearv[s] = 999;
    return s;
}
