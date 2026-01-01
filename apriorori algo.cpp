#include <iostream>
using namespace std;

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

    cout << "enter no.of transactions\n";
    cin >> no_of_transactions;

    for (i = 1; i <= no_of_transactions; i++)
    {
        cout << "enter no.of items in transaction:" << i << "\n";
        cin >> no_of_items[i];

        cout << "enter " << no_of_items[i] << " items for transaction:" << i << "\n";
        for (j = 1; j <= no_of_items[i]; j++)
            cin >> transactions[i][j];
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

    findFrequentSets(items, transactions, no_of_items,
                     no_of_transactions, result_item);

    cout << "\nFrequent 1-itemsets:\n";
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= col; j++)
            cout << result_item[i][j] << " ";
        cout << "\n";
    }

    while (setCount <= maxCount)
    {
        generateSubsets(result_item, setCount, items);
        findFrequentSets(items, transactions, no_of_items,
                         no_of_transactions, result_item);

        cout << "\nFrequent " << setCount << "-itemsets:\n";
        for (i = 1; i <= row; i++)
        {
            for (j = 1; j <= col; j++)
                cout << result_item[i][j] << " ";
            cout << "\n";
        }
        setCount++;
    }

    return 0;
}

/* Count support and filter frequent itemsets */
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

/* Generate candidate subsets */
void generateSubsets(int items[][100], int setCount, int result_item[][100])
{
    int i, j, k = 1, newRow = 0, newCol;

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
                bool exists = false;
                for (int m = 1; m < newCol; m++)
                    if (result_item[newRow][m] == items[j][k])
                        exists = true;
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
