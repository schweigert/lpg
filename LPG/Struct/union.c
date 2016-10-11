#include <stdio.h>

union numero {
	int a;
	double b;
}

int main (){

	union numero x;
	
	x.a = 100;
	
	printf ("x.a=%d\nx.b=%lf\n",x.a,x.b);
	
	x.b = 300.0;
	
	printf ("x.a=%d\nx.b=%lf\n",x.a,x.b);



	return 0;
}

