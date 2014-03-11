/* idea :
 * 1. 先將極限狀況列出 i.e. 10 4 2 1 -> XXXXOXXOXO O
 * 2. 若自己的上一個為X則此格為必著色點
 * 3. 若多出的O為2個，則第二次檢查為上上一個是否為X
 * 4. 若每次都是必著色點，則此點為所求*/

#include <stdio.h>
void intersection(int count , int spaceCount,int blackCount,unsigned int a[]){
	 unsigned int i=0 , j=0 , p=0 , result[ 50 ]={0};
	 short int *test =(short int *) malloc ( count *sizeof(short int ));
     for (i= 0; i < blackCount ; ++i){
		 for (j=0 ; j< a[ i ] ; ++j)
			 test[ p++ ]=1;
		 test[ p++ ]=0;
     }
     for (j = 1 ; j<=spaceCount-blackCount+1 ; ++j)
	 for (i=0 ; i < count-1; ++i){
		 if ( (test[ i ]*test[ i+j ] == 1 ) && j==1) result[ i+j ] += 1;
		 else if ((test[ i]*test[ i+j] != 1) && j>1)result[ i+j ] =0;
	 }for (i=0 ; i < count; ++i){
			if (i==count-1)printf("%d\n",result[ i ]);
			else printf("%d ",result[ i ]);
	 }
}
int main()
{
    char buf[50] ,*p;
    unsigned int total=0,length=0,n=0,i=0, colorCount=0,test[50];
    gets(buf);
    for ( p = buf,i=0; sscanf( p, " %d %n", &n, &length ) == 1; p += length,++i ) {
    	if (i==0) total = n;
    	else { test[ i-1 ] = n; colorCount +=n; }
    }
     intersection (total, total- colorCount ,i-1,test);
    return 0;
}
