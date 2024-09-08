class NumArray {
public:
    int n;
    vector<int> segmentTree;

    void buildSegmentTree(int i, int l, int r, auto& nums){
        if(l==r){
            segmentTree[i] =nums[l];
            return;
        }

        int mid = l + (r-l)/2;
        buildSegmentTree(2*i+1, l, mid, nums);
        buildSegmentTree(2*i+2, mid+1, r, nums);

        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }   

    void updateSegTree(int index, int val, int i, int l, int r){
        if(l == r){
            segmentTree[i] = val;
            return;
        }

        int mid = l + (r-l)/2;

        if(index <= mid){
            updateSegTree(index, val, 2*i+1, l, mid);
        }else{
            updateSegTree(index, val, 2*i+2, mid+1, r);
        }

        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }

    int querySegmentTree(int start, int end, int i, int l, int r){
        if(l> end || r< start){
            return 0;
        }

        if(l>=start && r<= end){
            return segmentTree[i];
        }

        int mid = l + (r-l)/2;
        
        return querySegmentTree(start, end, 2*i+1, l, mid) + querySegmentTree(start, end, 2*i+2, mid+1, r);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTree.resize(4*n);
        buildSegmentTree(0, 0, n-1, nums);
    }

    void update(int index, int val) { 
        updateSegTree(index, val, 0, 0, n-1);
    }

    int sumRange(int left, int right) { 
        return querySegmentTree(left, right, 0, 0, n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
