#include <iostream>
using namespace std;

static int row, col, min_freq = 2;

void findFrequentSets(int items[][100], int transactions[][100],
                      int no_of_items[], int no_of_transactions,
                      int result_item[][100]);

void generateSubsets(int items[][100], int setCount, int result_item[][100]);

int main()
{
    int no_of_transactions, s = 0, k = 1, l = 0, i, j, setCount = 2, maxCount;
    int transactions[100][100], no_of_items[100], items[100][100];
    int result_item[100][100];

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

    k = 0;
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

    findFrequentSets(items, transactions, no_of_items, no_of_transactions, result_item);
    cout << "\n";

    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= col; j++)
            cout << result_item[i][j] << " ";
        cout << "\n";
    }

    while (setCount <= maxCount)
    {
        generateSubsets(result_item, setCount, items);
        findFrequentSets(items, transactions, no_of_items, no_of_transactions, result_item);

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
