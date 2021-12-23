/*function to count number bits change from x to y */
int bitcntfunc(int x, int y)
{
    long long int count =0;
    int c;

    for(c = x ^ y; c!=0; c= c&(c-1)){
        count++;
    }

    return (int)(count % 1000000007);

}