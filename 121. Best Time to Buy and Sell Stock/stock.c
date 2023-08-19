int maxProfit(int* prices, int pricesSize){

    int i;
    int highest_seen_so_far;
    int max_profit = 0;

    for(i=(pricesSize - 1); i>=0; i--) {
        if (i==(pricesSize - 1)) {
            highest_seen_so_far = prices[i];
        }

        if(prices[i] > highest_seen_so_far)
            highest_seen_so_far = prices[i];

        if((highest_seen_so_far - prices[i] > max_profit))
            max_profit = highest_seen_so_far - prices[i];
    }

    return max_profit;

}