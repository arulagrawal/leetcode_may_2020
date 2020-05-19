class StockSpanner {
    stack<int> priceIndex;
    stack<int> prices;
    int i;

  public:
    StockSpanner() {
        i = 0;
        // prices.push(0);
    }

    int next(int price) {
        while (!prices.empty() && prices.top() <= price) {
            priceIndex.pop();
            prices.pop();
        }
        int result = 0;

        if (prices.empty()) {
            result = i + 1;
        } else {
            result = i - priceIndex.top();
        }

        priceIndex.push(i);
        prices.push(price);
        i++;
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
