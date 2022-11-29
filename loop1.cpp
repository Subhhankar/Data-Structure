#include<stdio.h>
int main()
{
	int flag=0, 1, num;
	printf("\n 	Enter any number: ");
	scanf("%d", &num);
	for(i=2; i<num/2;i++)
	{
	if(num%i==0)
	{
	   flag=1;
	   break;
	}
	}
	ig (flag==1)
	printf("\n %d is a composite number", num);
	elsee
	printf("\n %d is a prime number", num);
	return 0;
    
}
