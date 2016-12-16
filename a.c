#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef char string10 [11];
typedef char string30 [31];
typedef char string50 [51];
typedef char string200 [201];

typedef struct
{
	string50 title;
	string200 authors;
	string50 publicationDate;
	int callNumber;
	string30 readingMaterialType;
	int numberOfCopies;
}bookType;

typedef struct
{
	string50 name;
	string10 idNumber;
	string30 clientType;
	int nBooksBorrowed;
	int dueDates;
	double fines;
	
}clientType;

int main(){
	bookType pAcc;
	strcpy(pAcc.authors,"Shit");
	printf(pAcc.authors);
	return 0;
}
