#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX 1000
#define EMPTY 9999
#define PENALTY -1
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
	string30 materialType;
	int numberOfCopies;
	int bookID;
	int datesOverdue[MAX];
	
}readingMaterialType;

typedef struct
{
	string50 name;
	string10 idNumber;
	string30 clientCategory;
	int nBooksBorrowed;
	int dueDates[MAX];
	int borrowedBooks[MAX];
	int clientID;
	
}clientType;

readingMaterialType createBook(string50 title,string200 authors,string50 publicationDate,int callNumber,string30 materialType,int numberOfCopies,int *currentBookNumber)
{
	int x=0;
	readingMaterialType book;
	strcpy(book.title,title);
	strcpy(book.authors,authors);
	strcpy(book.publicationDate,publicationDate);
	book.callNumber=callNumber;
	strcpy(book.materialType,materialType);
	book.numberOfCopies=numberOfCopies;	
	book.bookID=*currentBookNumber;	
	for(x=0;x<MAX;x++){
		book.datesOverdue[x]=EMPTY;
	}
	(*currentBookNumber)++;

	return book;
}

clientType createClient(string50 name, string10 idNumber, string30 clientCategory,int *currentClientNumber)
{	
	int x=0;
	clientType client;
	strcpy(client.name,name);
	strcpy(client.idNumber,idNumber);
	strcpy(client.clientCategory,clientCategory);
	client.nBooksBorrowed=0;
	client.clientID=*currentClientNumber;
	for(x=0;x<MAX;x++){
		client.dueDates[x]=EMPTY;
		client.borrowedBooks[x]=EMPTY;
	}
	(*currentClientNumber)++;
	return client;
}

void viewOverdueBooks(clientType clientList[]){
	int x=0;
	int y=0;
	int overdueBooks=0;
	int totalFine=0;
	int totalOverdueBorrowedPerPerson=0;
	int totalFinePerPerson=0;
	printf("\n");
	for(x=0;x<50;x++){
		totalOverdueBorrowedPerPerson=0;
		totalFinePerPerson=0;
		for(y=0;y<1000;y++){
			if(clientList[x].dueDates[y]<=0)
			{
				totalOverdueBorrowedPerPerson++;
				totalFinePerPerson+=clientList[x].dueDates[y]*PENALTY;
				overdueBooks++;
				totalFine+= clientList[x].dueDates[y]*PENALTY;
			}
		}
		printf("%s:\t\t\t\t Overdue Books: %d\t Total Fine: %d \n",clientList[x].name,totalOverdueBorrowedPerPerson,totalFinePerPerson);
	}
	
	printf("\nTotal Books Overdue: %d", overdueBooks);
	printf("\nTotal Fine: %d\n\n", totalFine);
}
void viewBooksStatus(readingMaterialType bookList[],clientType clientList[]){
	int x=0;
	int y=0;
	int totalBooksOnShelf=0;
	int totalBooksWereBorrowed=0;
	for(x=0;x<50;x++){
		totalBooksOnShelf+=bookList[x].numberOfCopies;
	}
	for(x=0;x<50;x++){
		for(y=0;y<1000;y++){
			if(clientList[x].borrowedBooks[y]!=EMPTY)
			{
				totalBooksWereBorrowed++;
			}
		}
	}	
	printf("\nTotal Books on Shelf:%d\n",totalBooksOnShelf);
	printf("Total Books Borrowed:%d\n",totalBooksWereBorrowed);
}

void showBorrowers(clientType clientList[]){
	int x=0;
	for(x=0;x<50;x++){
		printf("\nName:%s \nID:%s\n",clientList[x].name,clientList[x].idNumber);
	}	
}

int findUser(string10 idNumber,clientType clientList[]){
	for()
}


int main(){
	
	readingMaterialType bookList[50];
	clientType clientList[50];
	int currentBookNumber=0;
	int currentClientNumber=0;
	int command;
	int backToMenu=0;
	string10 inputIDNumber;
	
	
	bookList[currentBookNumber]=createBook("Adamantite","Alden Smith","12/12/1990",69692919,"book",3,&currentBookNumber); //0
	bookList[currentBookNumber]=createBook("Air Machine 101","Arthur Schenizer","12/22/1981",2111233,"book",4,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Armor Smithing","Larry Anderson","03/30/2000",6343919,"magazine",1,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Bee Rendering","Brandon Lee","12/03/1990",6924519,"book",3,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Brass: New Findings","Mary Smith","12/12/1990",61232919,"book",3,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Breeze of New Air","Mon Mamon","09/02/1930",69342919,"book",2,&currentBookNumber);//5
	bookList[currentBookNumber]=createBook("Bright Star of the North","Martin Lax","04/28/1990",69554919,"book",2,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Cars","Sylph Pitt","07/19/1997",61242919,"book",1,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Carz","Sylph Pitt","09/02/1998",24342919,"book",2,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Cazer","Maria Latex","04/22/2006",18854919,"book",2,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Cezar","Larry Baym","09/16/2003",25854919,"book",3,&currentBookNumber);//10
	bookList[currentBookNumber]=createBook("Denmark News","Antonidas Mex, Yam Saro and Metros Magi","08/20/2011",88999972,"magazine",2,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Dome Architecture","Max Garrosh","04/30/1990",4454919,"magazine",2,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Drone Warz","Levy Aquino","08/23/2012",88359972,"magazine",4,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Drum News","Amber Guinto","12/05/2002",82359972,"magazine",2,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Elephant Wars","Meg Alto","10/25/2013",86659972,"book",7,&currentBookNumber);//15
	bookList[currentBookNumber]=createBook("Erman's News","Antonidas Mex","08/20/2012",88356972,"magazine",34,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Fahr's Architectures","Mash Mell","09/30/2005",12346789,"magazine",2,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Guns","Levy Aquino","08/23/2012",72728383,"magazine",4,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Killing with Style","Amber Guinto","12/05/2002",74757372,"magazine",2,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Lover's Death","Meg Alto","10/25/2013",91919111,"book",7,&currentBookNumber);//20
	bookList[currentBookNumber]=createBook("Monday's News","Antonidas Mex, Yam Saro and Metros Magi","08/20/2011",90291910,"magazine",2,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Noland's Opinion","Max Garrosh","04/30/1990",78901234,"magazine",2,&currentBookNumber);
	bookList[currentBookNumber]=createBook("People's Choice","Levy Aquino","08/23/2012",45352516,"magazine",4,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Prince Abilities","Amber Guinto","12/05/2002",1903819,"magazine",2,&currentBookNumber);	
	bookList[currentBookNumber]=createBook("Queen's Wrath","Alden Smith","12/12/1990",69692912,"book",3,&currentBookNumber); //25
	bookList[currentBookNumber]=createBook("Quiditch 101","Arthur Schenizer","12/22/1981",9911233,"book",4,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Quotes","Larry Anderson","03/30/2000",77343919,"magazine",1,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Racketeer Rendering","Brandon Lee","12/03/1990",2451779,"book",3,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Remy","Mary Smith","12/12/1990",67887879,"book",3,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Rex","Mon Mamon","09/02/1930",90042919,"book",2,&currentBookNumber);//30
	bookList[currentBookNumber]=createBook("Rico","Martin Lax","04/28/1990",90054919,"book",2,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Rumper","Sylph Pitt","07/19/1997",90042919,"book",1,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Rupper","Sylph Pitt","09/02/1998",90742919,"book",2,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Ruzzer","Maria Latex","04/22/2006",98854919,"book",2,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Stars","Larry Baym","09/16/2003",95854919,"book",3,&currentBookNumber);//35
	bookList[currentBookNumber]=createBook("Stars News","Antonidas Mex, Yam Saro and Metros Magi","08/20/2011",87799972,"magazine",2,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Stars Points","Max Garrosh","04/30/1990",9904919,"magazine",2,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Steam Engines","Levy Aquino","08/23/2012",98658972,"magazine",4,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Steam News","Amber Guinto","12/05/2002",82350002,"magazine",2,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Steam Wars","Meg Alto","10/25/2013",90009972,"book",7,&currentBookNumber);//40
	bookList[currentBookNumber]=createBook("Steam Wears","Antonidas Mex","08/20/2012",85356972,"magazine",2,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Steargare's' Architectures","Mash Mell","09/30/2005",11226789,"magazine",2,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Steel Series","Levy Aquino","08/23/2012",90238383,"magazine",4,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Steering with Style","Amber Guinto","12/05/2002",70887372,"magazine",2,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Stim Pointer","Meg Alto","10/25/2013",9000111,"book",7,&currentBookNumber);//45
	bookList[currentBookNumber]=createBook("Stimmer's News","Antonidas Mex, Yam Saro and Metros Magi","08/20/2011",97871910,"magazine",2,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Stomp's Opinion","Max Garrosh","04/30/1990",71211234,"magazine",2,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Tumple Choice","Levy Aquino","08/23/2012",49999516,"magazine",4,&currentBookNumber);
	bookList[currentBookNumber]=createBook("Zen Abilities","Amber Guinto","12/05/2002",1902819,"magazine",2,&currentBookNumber);//49
	clientList[currentClientNumber]= createClient("Alric Mendoza","11223249","student",&currentClientNumber);//0
	clientList[currentClientNumber]= createClient("Aria Zel","11255249","student",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Baron Geron","11235249","student",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Bax Alcantara","11245564","student",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Brendan Sara","11290564","student",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Brim Pol","11222249","student",&currentClientNumber);//5
	clientList[currentClientNumber]= createClient("Cell Ponoria","11365249","student",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Cyla Saltino","11235245","student",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Dexter Mata","11242764","student",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Diter Newgate","11290564","student",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Eugene Lax","11219249","student",&currentClientNumber);//10
	clientList[currentClientNumber]= createClient("Exom Penaca","11465249","student",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Firro Mariano","11345645","student",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Freddy Jaena","11248634","student",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Fro Late","11577564","student",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Garry Lacaso","11219929","student",&currentClientNumber);//15
	clientList[currentClientNumber]= createClient("Grom Helca","11163249","student",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Helveca Tica","11340045","student",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Hugh Armstrong","11274934","student",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Jack Atlas","11075064","student",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Jerry Miah","11599249","student",&currentClientNumber);//20
	clientList[currentClientNumber]= createClient("Jessy Mendoza","11491149","student",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Jez Amaz","11505645","student",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Killa Milla","11628934","student",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Kosaka Itukuki","11104064","student",&currentClientNumber);//24
	
	clientList[currentClientNumber]= createClient("Anderson Mesh","201112345","teacher",&currentClientNumber);//25
	clientList[currentClientNumber]= createClient("Brandy Embota","201112355","teacher",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Carly Estesio","201112445","teacher",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Dominic Pua","201113345","teacher",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Eliah Conum","201122345","teacher",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Fardy Marky","201212345","teacher",&currentClientNumber);//30
	clientList[currentClientNumber]= createClient("Greciel Sita","201212355","teacher",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Hondor Henrya","201212445","teacher",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Laposa Delosa","201213345","teacher",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Maria Cruz","201222345","teacher",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Nicky Gram","201312345","teacher",&currentClientNumber);//35
	clientList[currentClientNumber]= createClient("Nolly Abusino","201312355","teacher",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Nuggy Maris","201312445","teacher",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Oswald Ot","201313345","teacher",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Orion Jennix","201322345","teacher",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Perry Perkins","201412345","teacher",&currentClientNumber);//40
	clientList[currentClientNumber]= createClient("Picaso Aeros","201412355","teacher",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Pocahon Tasero","201412445","teacher",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Prince Kuro","201413345","teacher",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Robin Nich","201422345","teacher",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Rush Mandy","201512345","teacher",&currentClientNumber);//45
	clientList[currentClientNumber]= createClient("Serrena Sagim","201512355","teacher",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Solen Highser","201512445","teacher",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Tenny Core","201513345","teacher",&currentClientNumber);
	clientList[currentClientNumber]= createClient("Zack Sero","201522345","teacher",&currentClientNumber);//49
	
	
	
	
	while(1){
		printf("User Commands:\n");
		printf("[1] - Borrow Book\n");
		printf("[2] - Return Book\n");
		printf("Administrator Commands:\n");
		printf("[3] - View Overdue Books\n");
		printf("[4] - View Books Status\n");
		scanf("%d",&command);
		if(command==1){
			backToMenu=1;
				showBorrowers(clientList);
			while(backToMenu){
				printf("\nInput Borrower's ID Number (Type \"Cancel\" to Cancel Borrowing):");
				scanf("%s",&inputIDNumber);
				
				if(strcmp(inputIDNumber,"Cancel")==0){
					printf("\n");
					backToMenu=0;
				}
				else if(findUser(inputIDNumber,clientList)){
					
				}
				else{
					printf("Invalid ID Number, Please Try Again\n\n");
				}
			}
		}
		else if(command==2){
			
		}
		else if(command==3){
			viewOverdueBooks(clientList);
		}
		else if(command==4){
			viewBooksStatus(bookList,clientList);
		}
	}
	return 0;
}
