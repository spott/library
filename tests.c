/* 	tests.c
 *  Andrew Spott
 *
 *  tests the libraries that they do what they are supposed to do.
 */

#include "libraries/hash.h"
#include "libraries/spottlib.h"
#include <stdio.h> 
#include <stdlib.h>

int test_spottlib();
int test_hash();

int main() {

	int ispottlib = test_spottlib();
	int ihashlib = test_hash();

	printf("spottlib.h returned %d positive functions\n", ispottlib);
	printf("hash.h returned %d positive functions\n", ihashlib);

}

int test_hash() {
	hash_table *t = new_hash_table(1000);
	int i = 0;
	int b = 0;
	int d = 0;
	int tests = 0;

	while (!hash_table_add(t, i, b)){
		//printf("%d, %d\n", i, b);
		i++;
		b++;
		tests++;
	}
	i--;


	while (hash_table_find(t, i, &d, 1)) {
		if (d == i) {
			//printf("%d, %d\n",d,i);
			tests++;
			i--;
		}
		else 
			printf("key didn't match value");
	}

	return tests;
}

int test_spottlib() {
	int tests = 0;
	
	/* test itoa(int,char[]), by using atoi */
	int iitoa = 95047;
	char citoa[6];
	char fitoa[6];

	itoa(iitoa, citoa);
	sprintf(fitoa,"%d",iitoa);
	printf("%s - %s - %d\n",fitoa,citoa,iitoa);
	
	if ( strcmp(fitoa, citoa) == 0)
		tests++;

	/* test reverse (tested in itoa as well) */
	char ctest[106]    = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	int b = 0;
	int t = 0;
	char creverse[106] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";

	reverse( creverse );
	printf("%s\n%s\n", ctest, creverse);

	while(b < 52) {
		int j = 103 - b;
		printf("%d - %c, %c\n",b ,creverse[b],ctest[j]);
		if (creverse[b] == ctest[j]) 
			t++;
		b++;
	}
	printf("tests: %d\n",t);
	if (t == 52)
		tests++;

	return tests;
}
	
	
