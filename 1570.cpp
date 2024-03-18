class SparseVector {
    vector<pair<int,int>> vec; //index, val
public:
    
    SparseVector(vector<int> &nums) {
        for (int i =0 ;i<nums.size();i++){
            if(nums[i]!=0)
                vec.push_back({i,nums[i]});
       }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& other) {
        int i = 0;
        int j =0 ;
        int sum = 0;
        while (i<vec.size() && j<other.vec.size()){
            if(vec[i].first == other.vec[j].first){
                sum +=vec[i].second*other.vec[j].second;
                i++;
                j++;
            }
            else {
                if(vec[i].first<other.vec[j].first)
                    i++;
                else 
                    j++;
            }
        }
        return sum;
    }

};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
