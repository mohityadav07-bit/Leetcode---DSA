
       //// int i =0;
        //for( int j=0;j<nums.size();j++){
           // if(nums[j]!=0){
               // swap(nums[j],nums[i]);
                //i++;
            //}
        //}
        class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> arr;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                arr.push_back(nums[i]);
            }
        }

        for(int j = 0; j < arr.size(); j++) {
            nums[j] = arr[j];
        }

        int n = arr.size();

        for(int k = n; k < nums.size(); k++) {
            nums[k] = 0;
        }
    }
};
    