#include<bits/stdc++.h>
using namespace std;

const int mx = 50;
int minsup = 2;

bool isPresent(int candidate[], int cn, int transactions[], int tn) {
    int c = 0;
    for(int i=0;i<cn;i++) {
        for(int j=0;j<tn;j++) {
            if(candidate[i] == transactions[j]) {
                c++;
                break;
            }
        }
    }
    return c == cn;
}

int supportCount(int candidate[], int cn, int transactions[][mx], int items[], int n) {
    int c = 0;
    for(int i=0;i<n;i++) {
        if(isPresent(candidate, cn, transactions[i], items[i])) c++;
    }
    return c;
}

int main() {
    int n, transactions[mx][mx], items[mx];
    int f[mx][mx], fc = 0;
    cout << "enter no. of transactions = ";
    cin >> n;
    for(int i=0;i<n;i++) {
        cout << "enter no. of items in transaction" << i+1 << " = ";
        cin >> items[i];
        cout << "enter items = ";
        for(int j=0;j<items[i];j++) cin >> transactions[i][j];
    }
    int u[mx], uc = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<items[i];j++) {
            bool x = false;
            for(int k=0;k<uc;k++) {
                if(u[k] == transactions[i][j]) x = true;
            }
            if(!x) u[uc++] = transactions[i][j];
        }
    }
    cout << "\nfrequent 1-itemset = \n";
    for(int i=0;i<uc;i++) {
        int s = supportCount(&u[i], 1, transactions, items, n);
        if(s>=minsup) {
            cout << u[i] <<endl;
            f[fc++][0] = u[i];
        }
    }
    cout << "\nfrequent 2-itemset = \n";
    for(int i=0;i<fc;i++) {
        for(int j=i+1;j<fc;j++) {
            int candidate[2] = {f[i][0], f[j][0]};
            int s = supportCount(candidate, 2, transactions, items, n);
            if(s>=minsup) cout << candidate[0] << " " << candidate[1] <<endl;
        }
    }
}







#include <stdio.h>

static int row, col, min_freq = 2;

void findFrequentSets(int items[][100], int transactions[][100],
                      int no_of_items[], int no_of_transactions,
                      int result_item[][100]);

void generateSubsets(int items[][100], int setCount, int result_item[][100]);

int main()
{
    int no_of_transactions;
    int transactions[100][100], no_of_items[100];
    int items[100][100], result_item[100][100];
    int i, j, k = 0, l, setCount = 2, maxCount;

    printf("enter no.of transactions\n");
    scanf("%d", &no_of_transactions);

    for (i = 1; i <= no_of_transactions; i++)
    {
        printf("enter no.of items in transaction:%d\n", i);
        scanf("%d", &no_of_items[i]);

        printf("enter %d items for transaction:%d\n", no_of_items[i], i);
        for (j = 1; j <= no_of_items[i]; j++)
            scanf("%d", &transactions[i][j]);
    }

    /* Generate unique 1-itemsets */
    for (i = 1; i <= no_of_transactions; i++)
    {
        for (j = 1; j <= no_of_items[i]; j++)
        {
            for (l = 1; l <= k; l++)
                if (items[l][1] == transactions[i][j])
                    break;
            if (l > k)
                items[++k][1] = transactions[i][j];
        }
    }

    row = k;
    col = 1;
    maxCount = k;

    findFrequentSets(items, transactions,
                     no_of_items, no_of_transactions,
                     result_item);

    printf("\nFrequent 1-itemsets:\n");
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= col; j++)
            printf("%d ", result_item[i][j]);
        printf("\n");
    }

    while (setCount <= maxCount)
    {
        generateSubsets(result_item, setCount, items);
        findFrequentSets(items, transactions,
                         no_of_items, no_of_transactions,
                         result_item);

        printf("\nFrequent %d-itemsets:\n", setCount);
        for (i = 1; i <= row; i++)
        {
            for (j = 1; j <= col; j++)
                printf("%d ", result_item[i][j]);
            printf("\n");
        }
        setCount++;
    }

    return 0;
}

/* Count support and select frequent itemsets */
void findFrequentSets(int items[][100], int transactions[][100],
                      int no_of_items[], int no_of_transactions,
                      int result_item[][100])
{
    int i, j, l = 1, p = 1, count, m;

    while (l <= row)
    {
        count = 0;
        for (i = 1; i <= no_of_transactions; i++)
        {
            int found = 0;
            for (m = 1; m <= col; m++)
            {
                for (j = 1; j <= no_of_items[i]; j++)
                {
                    if (items[l][m] == transactions[i][j])
                    {
                        found++;
                        break;
                    }
                }
            }
            if (found == col)
                count++;
        }

        if (count >= min_freq)
        {
            for (m = 1; m <= col; m++)
                result_item[p][m] = items[l][m];
            p++;
        }
        l++;
    }

    row = p - 1;
}

/* Generate candidate itemsets */
void generateSubsets(int items[][100], int setCount, int result_item[][100])
{
    int i, j, k, newRow = 0, newCol;

    for (i = 1; i <= row; i++)
    {
        for (j = i + 1; j <= row; j++)
        {
            newCol = 1;
            newRow++;

            for (k = 1; k <= col; k++)
                result_item[newRow][newCol++] = items[i][k];

            for (k = 1; k <= col; k++)
            {
                int exists = 0, m;
                for (m = 1; m < newCol; m++)
                    if (result_item[newRow][m] == items[j][k])
                        exists = 1;
                if (!exists)
                    result_item[newRow][newCol++] = items[j][k];
            }

            if (newCol - 1 != setCount)
            {
                for (k = 1; k < newCol; k++)
                    result_item[newRow][k] = 0;
                newRow--;
            }
        }
    }

    row = newRow;
    col = setCount;
}
