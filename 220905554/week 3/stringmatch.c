#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int stringmatch(char str[],char substr[])
{
	int m=strlen(str);
	int n=strlen(substr);
	int i,j;

	for(i=0;i<=m-n;i++)
	{
		for(j=0;j<n;j++)
		{
          if(str[i+j]!=substr[j])
          	break;
		}
		if(j==n)
			return i;

	}

		return -1;
}

int main()
{
	printf("Enter a string: ");
	char*str=(char*)malloc(sizeof(char));
	scanf("%s",str);
	printf("Enter substring: ");
	char*substr=(char*)malloc(sizeof(char));
	scanf("%s",substr);
	int index = stringmatch(str,substr);
	if(index==-1)
		printf("NO MATCH\n");
	else
		printf("Match found at %d position\n",(index+1));

}