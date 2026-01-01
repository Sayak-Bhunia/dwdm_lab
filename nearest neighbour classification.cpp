#include <iostream>
#include <cmath>
using namespace std;

int tuples, attr, k;
float nearDist[20];

void NNC(int d[20][20], int t[1][20]);
int isNear();

int main()
{
    int i, j, data[20][20], test[1][20], s;

    cout << "enter no of tuples:";
    cin >> tuples;

    cout << "enter no of attributes:";
    cin >> attr;

    cout << "enter " << tuples << " tuples" << endl;
    for (i = 0; i < tuples; i++)
    {
        for (j = 0; j < attr; j++)
        {
            cin >> data[i][j];
        }
    }

    cout << "enter test tuple" << endl;
    for (i = 0; i < attr; i++)
    {
        cin >> test[0][i];
    }

    cout << "enter k value:";
    cin >> k;

    NNC(data, test);

    cout << "The nearest neighbours are" << endl;
    for (i = 0; i < k; i++)
    {
        s = isNear();
        cout << "(";
        for (j = 0; j < attr; j++)
        {
            cout << " " << data[s][j];
        }
        cout << " )" << endl;
    }

    return 0;
}

void NNC(int d[20][20], int t[1][20])
{
    int i, j;
    float sum;

    for (i = 0; i < tuples; i++)
    {
        sum = 0;
        for (j = 0; j < attr; j++)
        {
            sum += (d[i][j] - t[0][j]) * (d[i][j] - t[0][j]);
        }
        nearDist[i] = sqrt(sum);
    }
}

int isNear()
{
    float min = 9999;
    int s = -1;

    for (int i = 0; i < tuples; i++)
    {
        if (nearDist[i] < min)
        {
            min = nearDist[i];
            s = i;
        }
    }

    nearDist[s] = 9999;   // mark as used
    return s;
}











#include <stdio.h>
#include <math.h>

int tuples, attr, k;
float near[20];

void NNC(int d[20][20], int t[1][20]);
int isNear();

int main()
{
    int i, j, data[20][20], test[1][20], s;

    printf("enter no of tuples:");
    scanf("%d", &tuples);

    printf("enter no of attributes:");
    scanf("%d", &attr);

    printf("enter %d tuples\n", tuples);
    for (i = 0; i < tuples; i++)
    {
        for (j = 0; j < attr; j++)
        {
            scanf("%d", &data[i][j]);
        }
    }

    printf("enter test tuple\n");
    for (i = 0; i < attr; i++)
    {
        scanf("%d", &test[0][i]);
    }

    printf("enter k value:");
    scanf("%d", &k);

    NNC(data, test);

    printf("The nearest neighbours are\n");
    for (i = 0; i < k; i++)
    {
        s = isNear();
        printf("(");
        for (j = 0; j < attr; j++)
        {
            printf("%3d", data[s][j]);
        }
        printf(" )\n");
    }

    return 0;
}

void NNC(int d[20][20], int t[1][20])
{
    int i, j;
    float sum;

    for (i = 0; i < tuples; i++)
    {
        sum = 0;
        for (j = 0; j < attr; j++)
        {
            sum += (d[i][j] - t[0][j]) * (d[i][j] - t[0][j]);
        }
        near[i] = sqrt(sum);
    }
}

int isNear()
{
    float min = 9999;
    int s = -1, i;

    for (i = 0; i < tuples; i++)
    {
        if (near[i] < min)
        {
            min = near[i];
            s = i;
        }
    }

    near[s] = 9999;   // mark as selected
    return s;
}


