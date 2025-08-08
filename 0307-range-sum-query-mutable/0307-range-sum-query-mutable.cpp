class NumArray {
public:

	vector<int> st;

	// build segment tree 
	void BuildingSegmentTree(vector<int> & nums, int i, int l, int r){

		if(l == r){
			//left node
			st[i] = nums[l];
			return;
		}

		int mid = l + (r-l)/2;
		BuildingSegmentTree(nums, 2*i+1, l, mid);
		BuildingSegmentTree(nums, 2*i+2, mid+1, r);

		st[i] = st[2*i+1] + st[2*i+2];
	}

	void updateSegmentTree(int index, int val, int i, int l, int r){

		if(l == r){
			st[i] = val;
			return;
		}

		int mid = l + (r-l)/2;
		if(index <= mid ){
			updateSegmentTree(index, val, 2*i+1, l, mid);
		}else{
			updateSegmentTree(index, val, 2*i+2, mid+1, r);
		
		}

		st[i] = st[2*i+1] + st[2*i+2];
		
	}

	int getSum(int start, int end, int i, int l, int r){

		// out of bound
		if(r < start || l > end ){
			return 0;
		}

		// inside or equal 
		if(start <= l && end >= r){
			return st[i];

		}

			// overlapping
		int mid = l + (r-l)/2;
		return getSum(start, end, 2*i+1, l, mid) + getSum(start, end, 2*i+2, mid+1, r);
	}



    NumArray(vector<int>& nums) {
    	int n =  nums.size();

    	st = vector<int>(4*n);


        BuildingSegmentTree(nums, 0, 0 , n-1);
        
    }
    
    void update(int index, int val) {

    	updateSegmentTree(index, val, 0, 0, (st.size()/4) - 1);
    }
    
    int sumRange(int left, int right) {

    	return getSum(left, right, 0, 0, (st.size()/4) - 1);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */