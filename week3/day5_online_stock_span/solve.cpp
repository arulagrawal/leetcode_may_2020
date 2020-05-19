class StockSpanner {
    stack<int> priceIndex;
    stack<int> prices;

  public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;

        while (!prices.empty() && prices.top() <= price) {
            span += priceIndex.top();
            priceIndex.pop();
            prices.pop();
        }

        prices.push(price);
        priceIndex.push(span);
        return span;
    }
};
