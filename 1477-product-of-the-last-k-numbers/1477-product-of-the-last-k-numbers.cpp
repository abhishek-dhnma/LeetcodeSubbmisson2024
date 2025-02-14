class ProductOfNumbers {
public:

    vector<int> stream;

    ProductOfNumbers() {
        
    }
    
    void add(int num) {

        stream.push_back(num);
        
    }
    int ans = 0;

    int getProduct(int k) {

        if(k > stream.size()){
            return 0;
        }

            int product = 1;
           for(int i=stream.size()-k; i<stream.size(); i++){
            product *= stream[i];
           }

        return product;
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */