class StockSpanner {
    vector<int> prices;
    int i;

  public:
    StockSpanner() { i = 0; }

    int next(int price) {
        prices.push_back(price);
        int total = 0;
        for (int j = i; j >= 0; j--) {
            if (prices[j] <= price) {
                total++;
            } else
                break;
        }
        i++;
        return total;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
