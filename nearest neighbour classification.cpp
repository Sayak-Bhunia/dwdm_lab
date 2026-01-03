#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int tuples, attributes, k, data[20][20], test[20];
    float nearDst[20];
    cout << "enter no. of tuples = ";
    cin >> tuples;
    cout << "enter no. of attributes = ";
    cin >> attributes;
    cout << "enter " << tuples << " tuples" <<endl;
    for(int i=0;i<tuples;i++) {
        for(int j=0;j<attributes;j++) cin >> data[i][j];
    }
    cout << "enter test tuple = " <<endl;
    for(int j=0;j<attributes;j++) cin >> test[j];
    cout << "enter k value = ";
    cin >> k;
    for(int i=0;i<tuples;i++) {
        float sum = 0;
        for(int j=0;j<attributes;j++) sum += pow((data[i][j] - test[j]), 2);
        nearDst[i] = sqrt(sum);
    }
    cout << "the nearest neighbours are = " <<endl;
    for(int i=0;i<k;i++) {
        float mn = 9999;
        int s = -1;
        for(int j=0;j<tuples;j++) {
            if(nearDst[j]<mn) {
                mn = nearDst[j];
                s = j;
            }
        }
        cout << "(";
        for(int l=0;l<attributes;l++) cout << data[s][l];
        cout << ")" <<endl;
        nearDst[s] = 9999;
    }
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


