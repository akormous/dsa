/**
LC 307
 */
class SegTree {
    vector<int> arr;
    vector<int> segTree;
    int n;

    void build(int idx, int low, int high) {
        if(low == high) {
            segTree[idx] = arr[low];
            return;
        }

        int mid = (low + high)/2;

        build(2*idx + 1, low, mid);
        build(2*idx + 2, mid + 1, high);

        segTree[idx] = segTree[2*idx + 1] + segTree[2*idx + 2];
    }

    void update(int idx, int low, int high, int i, int newVal) {
        if(low == high) {
            segTree[idx] = newVal;
            arr[i] = newVal;
            return;
        }

        int mid = (low + high)/2;
        if(i <= mid) {
            update(2*idx + 1, low, mid, i, newVal);
        }
        else {
            update(2*idx + 2, mid + 1, high, i, newVal);
        }

        segTree[idx] = segTree[2*idx + 1] + segTree[2*idx + 2];
    }

    int querySumRange(int idx, int low, int high, int l, int r) {
        // if low and high are completely outside of query l,r
        if(low > r || high < l) return 0;

        // if low and high are completely inside of query l,r
        if(l <= low && high <= r) return segTree[idx];

        // partial overlap
        int mid = (low + high)/2;
        int left = querySumRange(2*idx + 1, low, mid, l, r);
        int right = querySumRange(2*idx + 2, mid + 1, high, l, r);

        return left + right;
    }
public:
    SegTree(vector<int>& nums) {
        this->arr = nums;
        this->n = nums.size();
        segTree.resize(4 * n, 0);
        build(0, 0, n - 1);
    }

    void update(int i, int newVal) {
        update(0, 0, n - 1, i, newVal);
    }

    int querySumRange(int l, int r) {
        return querySumRange(0, 0, n - 1, l, r);
    }
};

class NumArray {
    SegTree* seg;
public:
    NumArray(vector<int>& nums) {
        this->seg = new SegTree(nums);
    }
    
    void update(int index, int val) {
        seg->update(index, val);
    }
    
    int sumRange(int left, int right) {
        return seg->querySumRange(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */