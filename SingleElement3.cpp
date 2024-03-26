vector<int> singleNumber(vector<int>& nums) {
        long XOR=0; int rightmost=0;
        for(int i=0;i<nums.size();i++){
            XOR=XOR^nums[i];
            rightmost=(XOR & XOR-1)^XOR;
        }
            int b1=0;int b2=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i] & rightmost)
                b1=b1^nums[i];
                else
                b2=b2^nums[i];
            }
            return {b1,b2};
    }