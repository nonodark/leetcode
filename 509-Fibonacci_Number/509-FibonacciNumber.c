int fib(int N){
    if(N <= 1)
    {
        return N;
    }

    int preNum = 1;
    int prePreNum = 0;
    int num = 0;
    for(int i = 2; i<= N; i++)
    {     
       num = preNum + prePreNum;
       prePreNum = preNum;
       preNum = num;
    }
    
    return num;
}