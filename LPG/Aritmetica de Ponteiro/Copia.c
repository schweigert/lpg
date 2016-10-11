#include <stdio.h>

void copia1 (char * const p1, const char *const p2);
void copia2 (char *p1, const char *p2);

int main (void){

	char s1[10];
	char *s2 = "Banana";
	char s3[10];
	char s4[] = "Maça";

	copia1 (s1,s2);
	copia2 (s3,s4);

	printf ("%s %s %s %s\n",s1,s2,s3,s4);
	
	return 0;

}

void copia1 (char * const p1, const char * const p2){


int i;
for (i = 0; (p1[i] = p2[i])!= '\0'; i++);	

}

void copia2 ( char *p1, const char *p2){

for ( ; (*p1 = *p2) != '\0'; p1++, p2++);



}
