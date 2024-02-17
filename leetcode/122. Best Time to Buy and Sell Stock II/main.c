#include <stdio.h>
#include "nothing.h"

int maxProfit(int *prices, int pricesSize)
{
    int res = 0;
    for (int i = 0; i < pricesSize - 1; i++)
    {
        if (prices[i] < prices[i + 1])
        {
            res += prices[i + 1] - prices[i];
        }
    }
    return res;
}

int maxProfit1(int *prices, int pricesSize)
{
    int res = 0;
    int dp[pricesSize][2];
    dp[0][0] = 0;
    dp[0][1] = -prices[0];

    for (int i = 1; i < pricesSize; i++)
    {
        dp[i][0] = fmax(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = fmax(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[pricesSize - 1][0];
}

int main(int argc, char const *argv[])
{
    int prices[] = {7, 1, 5, 3, 6, 4};
    int pricesSize = sizeof(prices) / sizeof(prices[0]);

    printArray(&prices[0], pricesSize);
    int profit1 = maxProfit(&prices[0], pricesSize);
    int profit2 = maxProfit(&prices[0], pricesSize);

    printf("the Maximum profit1 is: %d\n", profit1);
    printf("the Maximum profit2 is: %d\n", profit2);

    return 0;
}
