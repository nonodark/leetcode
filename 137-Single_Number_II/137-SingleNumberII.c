  
/*  we use Karnaugh Map to reduce the logic caculation.
 *  Counter status
 *  current add result
 *  AB      C   RA    RB
 *  00      0   0(F)  0(F)
 *  01      0   0(F)  1(T)
 *  10      0   1(T)  0(F)
 *  11      0    (X)   (X)
 *  00      1   0(F)  1(T)
 *  01      1   1(T)  0(F)
 *  10      1   0(F)  0(F)
 *  11      1    (X)   (X)
 *
 *   add/current|  A'B'| A'B  | AB |  AB' 
 *   ----------------------------------------
 *   C'         |   F  |  F  |  X  |  T
 *   ----------------------------------------
 *   C          |   F  |  T  |  X  |  F
 *
 *   So RA  = A'BC+ AB'C' ==> (A' & B & C) | (A & B' & C') 
 *
 *   add/current|  A'B'| A'B  | AB |  AB' 
 *   ----------------------------------------
 *   C'         |   F  |  T   |  X  |  F
 *   ----------------------------------------
 *   C          |   T  |  F   |  X  |  F
 *   So RB  = A'B'C + A'BC' ==> (A' & B' & C) | (A' & B & C') 
 */ 
int singleNumber(int* nums, int numsSize){
    
    int i = 0;
    int RA = 0;
    int RB = 0;
    for(i = 0; i<numsSize;i++)
    {  
        int tmpRA = RA;
        int tmpRB = RB;

        RB = ((~tmpRA) & (~tmpRB) & nums[i]) | ((~tmpRA) & (tmpRB) & (~nums[i]));        
        RA = ((~tmpRA) & tmpRB & nums[i]) | (tmpRA & (~tmpRB) & (~nums[i]));
    }    
    
   return RB;
     
}