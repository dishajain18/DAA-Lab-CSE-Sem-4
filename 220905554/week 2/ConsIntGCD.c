#include <stdio.h>

unsigned int GCD(unsigned int m,unsigned int n,int * opcount)
{
	int t=m<n?m:n;
	while(t>0)
	{
		(*opcount)++;
		
		  if(m%t==0&&n%t==0)

		  		return t;
		t--;
	}
	return 1;
}

int main()
{
	int m,n,opcount=0;
	printf("Enter the numbers m and n: ");
	scanf("%d%d",&m,&n);
	printf("GCD of m and n is: %d",GCD(m,n,&opcount));
	printf("\nopcount: %d\n",opcount);
}