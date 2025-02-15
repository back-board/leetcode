class ProductOfNumbers {
private:
    int current;
    vector<int> products;
    int lastProduct;
    int lastZero;
public:
    ProductOfNumbers() {
        current = 0;
        lastProduct = 1;
        lastZero = -1;
    }
    
    void add(int num) {
        lastProduct *= num;
        products.push_back(lastProduct);
        if( num == 0 ) {
            lastProduct = 1;
            lastZero = current;
        }
        current++;
    }
    
    int getProduct(int k) {
        if( current - lastZero <= k ) {
            return 0;
        }

        if( k >= current ) {
            return lastProduct;
        }

        int product = products[current - 1 - k];
        product = product == 0 ? 1 : product;
        product = lastProduct / product;
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
