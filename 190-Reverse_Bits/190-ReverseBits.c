uint32_t reverseBits(uint32_t n) {
    unsigned int i = 0;
    unsigned int ret = 0;
   
    for(i = 0; i < 32; i++)
    {
        ret |= (unsigned int)((n&( (unsigned int) 1<<i) ? 1:0)) << (32-i-1);
    }
        
    return ret;
    
}