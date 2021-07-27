#include<bits/stdc++.h>
using namespace std;

/*
Given an array of stock prices each day,
calculate the maximum profit that can be acheived in atmost 2 trades
*/

int maximizeProfit(vector<int> price) {
    int n = price.size();

    // create an array profit which will keep track of the maximum profit that can be acheived
    vector<int> profit(n, 0);
    // now consider doing only 1 trade / transaction
    // ( and lets consider the price at last day to be max )
    int max_price = price[n - 1];

    // traverse the prices from right to left
    // keep track of the max_price and populate the profit array
    for(int i = n - 2; i >= 0; --i) {
        // check if price at this day is greater than max_price
        if(price[i] > max_price)
            max_price = price[i];

        // check the profit that can be made if the stock is bought at the current day
        // and compare it with the previous transaction
        profit[i] = max(profit[i + 1], max_price - price[i]);
    }

    // now traverse the array from left to right,
    // and keep track of the profit that can be acheived
    // ( and lets consider the price at first day to be min )
    int min_price = price[0];
    for(int i = 1; i < n; i++) {
        // check if the price of stock at current day is less than min_price
        if(price[i] < min_price)
            min_price = price[i];

        // update the profit array
        // check if the profit made on the previous day was greater 
        // than the profit made by selling the stock on the current day + profit already made
        profit[i] = max(profit[i - 1], profit[i] + ( price[i] - min_price ));
    }
    // the last element in profit is the maximum profit that can be made
    return profit[n - 1];
}

int main() {
    // price of stock for a series of days
    vector<int> price = { 2, 30, 15, 10, 8, 25, 80 };
    cout<<"Maximum profit that can be acheived in atmost 2 trades = "<<maximizeProfit(price)<<endl;
    return 0;
}