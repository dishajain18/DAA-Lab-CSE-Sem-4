#include <stdio.h>
#include <stdlib.h>
#define size 128

void ShitfTable(char P[],int m,int Table[])
{
	for(int i=0;i<size;i++)
		Table[i]=m;
	for(int i=0;i<m-1;i++)
		Table[P[i]]= m-1-i;
}

int Horsepool(char t[],char p[],int n,int m)
{
	int Table[size];
	ShitfTable(p,m,Table);

	int i = m-1;
	while(i<n)
	{
		int k=0;
		while(k<m & p[m-1-k]==t[i-k])
			k++;
		if(k==m)
			return i-m+1;
		else
			i=i+Table[t[i]];
	}
	return -1;
}
int main()
{
	int m,n;
	printf("Enter size of text: ");
	scanf("%d",&n);
	printf("Enter size of pattern");
	scanf("%d",&m);
	printf("Enter the text: ");
	char t[n],p[m];
	scanf(" %[^\n]c",t);
	printf("Enter the pattern: ");
	scanf(" %[^\n]c",p);
	int pos=Horsepool(t,p,n,m);
	if(pos>-1)
		printf("Pattern found at %d\n",pos);
	else
		printf("Pattern not found\n");
}