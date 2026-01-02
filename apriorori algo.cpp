#include <iostream>
using namespace std;

const int MAX = 50;
int min_sup = 2;

/* check if candidate set exists in transaction */
bool isPresent(int cand[], int clen, int trans[], int tlen)
{
    int count = 0;
    for (int i = 0; i < clen; i++)
        for (int j = 0; j < tlen; j++)
            if (cand[i] == trans[j])
            {
                count++;
                break;
            }
    return (count == clen);
}

/* count support */
int supportCount(int cand[], int clen, int trans[][MAX], int items[], int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (isPresent(cand, clen, trans[i], items[i]))
            cnt++;
    return cnt;
}

int main()
{
    int n, trans[MAX][MAX], items[MAX];
    int freq[MAX][MAX], fcount = 0;

    cout << "Enter number of transactions: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "No of items in transaction " << i + 1 << ": ";
        cin >> items[i];
        for (int j = 0; j < items[i]; j++)
            cin >> trans[i][j];
    }

    /* Generate 1-itemsets */
    int uniq[MAX], ucount = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < items[i]; j++)
        {
            bool found = false;
            for (int k = 0; k < ucount; k++)
                if (uniq[k] == trans[i][j])
                    found = true;
            if (!found)
                uniq[ucount++] = trans[i][j];
        }

    cout << "\nFrequent 1-itemsets:\n";
    for (int i = 0; i < ucount; i++)
    {
        int s = supportCount(&uniq[i], 1, trans, items, n);
        if (s >= min_sup)
        {
            cout << uniq[i] << endl;
            freq[fcount++][0] = uniq[i];
        }
    }

    /* Generate 2-itemsets */
    cout << "\nFrequent 2-itemsets:\n";
    for (int i = 0; i < fcount; i++)
        for (int j = i + 1; j < fcount; j++)
        {
            int cand[2] = {freq[i][0], freq[j][0]};
            int s = supportCount(cand, 2, trans, items, n);
            if (s >= min_sup)
                cout << cand[0] << " " << cand[1] << endl;
        }

    return 0;
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
