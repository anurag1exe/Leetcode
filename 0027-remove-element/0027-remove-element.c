int removeElement(int* nums,int numSize,int val){
    int k=0;
    for(int i=0; i<numSize; i++){
        if(nums[i]!=val){
            nums[k]=nums[i];
            k++;
        }
    }
    return k;
}