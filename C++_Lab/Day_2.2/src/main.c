#include <stdio.h>
int ADD(int, int);		//


int main1(int x, int y)
{
	printf("Hello C");
	int Res=ADD(10,30);	//Message Passing
	return 0;
}

int ADD(int P, int Q)	//Parameters
{
	int C=P+Q;
	return C;
}
