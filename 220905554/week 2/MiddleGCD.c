#include<stdio.h>
int isPrime(int n,int *opcount)
{
	int i;
	for(i=2;i*i<n;i++)
	{
		if(n%i==0)
			return 0;
	}
	return 1;
}
int main()
{
	int n1,n2,i=2,x,y,gcd=1,opcount=0;
	printf("Enter two numbers: ");
	scanf("%d%d",&n1,&n2);
	x=n1<n2?n1:n2;
	y=n1>n2?n1:n2;
	do{
		opcount++;
		
		if((x%i==0) && (y%i==0))
		{
			if(isPrime(i,&opcount))
			{
				printf("prime factors: %d\n",i);
				x=x/i;
		        y=y/i;
		        gcd=gcd*i;
		        i--;
		    }
		}
		i++;

	}while(i<=x);
	printf("GCD of %d and %d is: %d\n",n1,n2,gcd);
	printf("opcount: %d\n",opcount);


}