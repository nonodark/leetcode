#define NAX_NUM 30001

int singleNumber(int* nums, int numsSize){
    signed int ret = 0;

    unsigned char *pFlag =  malloc(sizeof(char)*NAX_NUM);
    unsigned char *nFlag =  malloc(sizeof(char)*NAX_NUM);
    memset(pFlag,0, sizeof(char) * NAX_NUM);
    memset(nFlag,0, sizeof(char) * NAX_NUM);
    int i = 0;
    for(i = 0; i<numsSize;i++)
    {
        if(nums[i] >= 0 )
        {
            pFlag[nums[i]]++;
        }
        else
        {
            nFlag[abs(nums[i])]++;
        }
    }
    
    for(i = 0; i<NAX_NUM;i++)
    {
        if(pFlag[i] == 1)
        {
            return i;
        }

        if(nFlag[i] == 1)
        {
              return (0-i);
        }
    }
    
    
    return ret;
}