// CpE Laboratory Management Portal
// Group 7
// CADA, Mark Jay V.
// MACION, Trisha G.
// MANALANG, Melvin V.
// TAN, Paul Christian F.
// BS-CpE 2-1

#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#define ITEM 15
#define total 50
using namespace std;

int limit = 0;
int array1[ITEM] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
int arrayAvail[ITEM] = { 3, 15, 19, 7, 9, 6, 5, 4, 5, 10, 13, 7, 4, 9, 6 };
string arrayofItems[ITEM][ITEM] = {{"  [1]"," Amplifier"},
						{"  [2]"," Breadboard"}, {"  [3]"," Chair"},
						{"  [4]"," Electric Fan"}, {"  [5]"," Extension"},
						{"  [6]"," HDMI Cord"}, {"  [7]"," Monitor"},
						{"  [8]", " Motherboard"}, {"  [9]"," Multimeter"},
						{"  [10]"," Oscilloscope"}, {"  [11]"," Power Cord"},
						{"  [12]"," Power Supply"}, {"  [13]"," Projector"},
						{"  [14]"," Screwdriver"}, {"  [15]"," Table"}};
struct info {
	int entryNum;
	char name[30], yearandSec[7], dateTime[30], studNum[11];
	struct itemInfo {
		string itemName;
		int itemNum, itemCount, containUnit;
	} itemInfo[total];
} info[total];

//FUNCTION PROTOTYPE
void defaultTime();
void mainMenu();
void fillBorrow();
void display();
void displaySlip();
void returnSlip();

// MAIN
int main() {
	system("color 37");
	char choice;
	mainMenu();
	cin >> choice;
	switch(choice) {
		case '1':
			system("cls");
			fillBorrow();
			break;
		case '2':
			system("cls");
			display();
			break;
		case '3':
			system("cls");
			displaySlip();
			break;
		case '4':
			system("cls");
			returnSlip();
			break;
		case '5':
			cout << "\n\n\n\t\t[THANK YOU FOR USING THE PROGRAM]";
			system("pause>0");
			system("cls");
			cout << "\n\n\n\n\n\n\t\t[PROGRAM EXITING . . . . ]\n\n\n\n\n\n";
			system("pause>0");
			return 0;
			break;
		default:
			cout << "\n\n\n\t\t     [INVALID INPUT]\n\n\t\t   [PLEASE TRY AGAIN]\n\n\n";
			system("pause>0");
			system("cls");
			main();
			break;
	}
}

// FUNCTION DEFINITION

/*SYSTEM TIME & DATE*/
void defaultTime() {
	char buffer[80];
    time_t t = time(0);
	struct tm * now = localtime(&t);
	strftime (buffer,80,"SYSTEM DATE: %m/%d/%y                 SYSTEM TIME: %I:%M %p",now);
	cout << endl << buffer << endl;
}

/*MAIN MENU*/
void mainMenu() {
	defaultTime();
	cout << "***********************************************************" << endl
		 << "*****   				              *****" << endl
		 << "*****   WELCOME TO CpE Laboratory Management Portal   *****" << endl
		 << "*****   				              *****" << endl
		 << "***********************************************************" << endl
		 << "******   				             ******" << endl
		 << "*****   1. Fill Borrow Slip			      *****" << endl
		 << "*****   2. Display Entire Items			      *****" << endl
		 << "*****   3. Display Borrow Slip			      *****" << endl
		 << "*****   4. Return Borrow Slip			      *****" << endl
		 << "*****   5. Exit				              *****" << endl
		 << "******   				             ******" << endl
		 << "***********************************************************" << endl
		 << endl << "Enter your choice : : ";	
}

/*FILLING BORROW SLIP*/
void fillBorrow() {
	for(int l=0; l<1; l++) {
		ofstream outfile;
		outfile.open("CpE Laboratory.dat");
	
		char buffer[30];
		string str;
		int i=0, temp=0;
		limit++;
		time_t t = time(0);
		struct tm * now = localtime(&t);
		
		defaultTime();
		cout << "***********************************************************" << endl;
		cout << "\t\t     [LABORATORY LIST]" << endl << endl;
		cout << "  Available\t    Laboratory\n   Unit(s)\t     Item(s)\n";
		
		for(int k=0; k<ITEM; k++) {
			cout << "     " << arrayAvail[k] << "\t\t";
			for(int l=0; l<ITEM; l++) {
				cout << arrayofItems[k][l];
			}
			cout << endl;
		}
		
		cout << "==========================================================="
			 << "\n\n\t         [FILLING BORROWER's SLIP]" << endl << endl;	 
		i = limit;
		cout << "Fill up the required data" << "\t\t\t    CN: 00" << i << endl << endl;
		
		char confirm;
		bool cont, loop;
		
		do{
			do {
				/*Default System Time*/			
				strftime(buffer,30,"%m/%d/%y (%I:%M %p)",now);
				strcpy(info[i].dateTime, buffer);
				
				outfile << "********************************************************************************************" << endl;		
				outfile << "*******************************************RECEIPT******************************************" << endl;		
				outfile << "Date / Time Borrowed: \t\t\t";
				outfile << buffer << "\t\t\t\t\t\t\t\t CN: 00" << i << endl << endl << endl;
				
				/*Name*/
				cin.clear();
				cin.sync();
				cout << "Name: ";
				cin.getline(info[i].name,50);
				str = info[i].name;
				str.length();
				
				outfile << "Name: \t\t\t\t\t\t\t";
				outfile << info[i].name << endl;
			} while((str.length() == 0) || (isspace(info[i].name[0])) ||
				(isdigit(info[i].name[0])) || (ispunct(info[i].name[0])));
			
			/*Year and Section*/
			do {
				cin.clear();
				cin.sync();
				cout << "Year & Section: ";
				cin.getline(info[i].yearandSec,7);
				str = info[i].yearandSec;
				str.length();
				outfile << "Year & Section: \t\t\t\t";		
				outfile << info[i].yearandSec << endl;
			} while((str.length() == 0) || (isspace(info[i].yearandSec[0])) ||
				(isalpha(info[i].yearandSec[0])) || (ispunct(info[i].yearandSec[0])));
			
			do {
				cout << "\n\t    Is this information correct? (Y/N) ";
				cin >> confirm;
				switch(confirm) {
					case 'Y':
					case 'y':
						cont = true;
						break;
					case 'N':
					case 'n':
						cont = false;
						break;
					default:
						cout << "\t\t      Invalid answer!\n\n";
						loop = false;
						break;
				}
			} while(loop);
		} while(!cont);
		cout << endl;
		
		/*Default System Time*/			
		strftime(buffer,30,"%m/%d/%y (%I:%M %p)",now);
		cout << "Date / Time Borrowed: " << buffer;
		strcpy(info[i].dateTime, buffer);
		cout << endl;
		
		/*Laboratory Items*/
		do {
			cin.clear();
			cin.sync();
			cout << "\nTotal item(s) to be borrowed: ";
			cin >> info[i].itemInfo[i].itemNum;
			str = info[i].itemInfo[i].itemNum;
			
			outfile << "Item(s) borrowed: \t\t\t"<< info[i].itemInfo[i].itemNum << " [Unit/s]"<< endl;
			
		} while((str.length() == 0) || (isspace(info[i].itemInfo[i].itemNum)) ||
				(isalpha(info[i].itemInfo[i].itemNum)) || (ispunct(info[i].itemInfo[i].itemNum)));
		
		cout << "\n\t      CHOOSE FROM THE LABORATORY LIST";
		
		for(int j=0; j<info[i].itemInfo[i].itemNum; j++) {
			bool match;
			
			do {
				do {	
				cin.clear();
				cin.sync();
				cout << "\nITEM #" << j+1 << ": ";
				cin >> info[i].itemInfo[j].itemCount;
				str = info[i].itemInfo[j].itemCount;
				} while((str.length() == 0) || (isspace(info[i].itemInfo[j].itemCount)) ||
						(isalpha(info[i].itemInfo[j].itemCount)));
				
				outfile << "Item Description:  \t\t\t " ;
				cout << "Item Description: ";
				
				for(int k=0; k<ITEM; k++) {
					for(int l=0; l<ITEM; l++) {
						if(info[i].itemInfo[j].itemCount == array1[k]) {
							cout << arrayofItems[k][l];
							info[i].itemInfo[j].itemName += arrayofItems[k][l];
							outfile << arrayofItems[k][l];
						}
					}
				}
				
				do {
					cout << "\nQuantity of that item: ";
					cin >> info[i].itemInfo[j].containUnit;
					str = info[i].itemInfo[j].containUnit;
				} while((str.length() == 0) || (isspace(info[i].itemInfo[j].containUnit)) ||
						(isalpha(info[i].itemInfo[j].containUnit)));
				
				outfile << endl << "Quantity of item: \t\t\t\t" << info[i].itemInfo[j].containUnit << " [Unit/s]" << endl ;
				
				for(int k=0; k<ITEM; k++) {
					if(info[i].itemInfo[j].itemCount == array1[k]) {
						temp = arrayAvail[k];
						
						if(info[i].itemInfo[j].containUnit > temp) {
							cout << "\n\n[Your desired number of item(s) on your entry is not match in available unit(s)]\n\n"
								 << "\t\t\t[ITEM NOT SAVED]";
							info[i].itemInfo[j].containUnit;
							i--;
							match = false;
						}
						
						else {
							arrayAvail[k]-=info[i].itemInfo[j].containUnit;
							
							if(arrayAvail[k] == -1) {
								info[i].itemInfo[j].containUnit;
								j--;
								cout << "Item not available. . .\n\n";
								arrayAvail[k] == 0;
							}
							match = true;
						}
					}
				}
			} while(!match);
		}
		int saveN;
		bool flag;
		string studNum;
		cout << endl;
		
		do {
			cin.clear();
			cin.sync();
			cout << "        Enter STUDENT NUMBER to confirm, [Q] to quit\n\t\t\t";
			cin.getline(info[i].studNum,11);
			studNum = info[i].studNum;
			
			outfile << "Student Number: \t\t\t\t";
			outfile << info[i].studNum << "-MN-0" << endl << endl << endl;
			outfile << "******************************CpE Laboratory Management Portal******************************" << endl;
			outfile << "********************************************************************************************" << endl;
		} while(studNum.length() == 0);
		
		if(studNum.length() == 10)
			flag = true;
			
		if((studNum == "q")||(studNum == "Q")) {
			cout << "\n\n\t         [TRANSACTION NOT SAVED]\n\n";  
			flag = false;
		}
		
		else if((studNum.length() != 10) || (isalpha(info[i].studNum[0]))) {
			cout << "\n\n\t      [STUDENT NUMBER IS NOT VALID]";
			cout << "\n\n\t         [TRANSACTION NOT SAVED]\n\n"; 
			flag = false;
		}
		
		/*Filters Student Number*/
		if(!flag) {
			for(i; i<=limit; i++) {
				strcpy(info[i].name, info[i+1].name); 
				strcpy(info[i].yearandSec, info[i+1].yearandSec);
				strcpy(info[i].dateTime, info[i+1].dateTime);
				info[i].itemInfo[i].itemNum = info[i+1].itemInfo[i+1].itemNum;
				
				for(int j=0; j<info[i].itemInfo[i].itemNum; j++) {
					info[i].itemInfo[j].itemName == info[i+1].itemInfo[j+1].itemName;
					info[i].itemInfo[j].containUnit = info[i+1].itemInfo[j+1].containUnit;
				
					for(int k=0; k<ITEM; k++) {
						if(info[i].itemInfo[j].itemCount == array1[k+1])
							arrayAvail[k]+=info[i].itemInfo[j].containUnit;
					}	
				}	
			}
			limit--;
			system("pause>0");
			system("cls");
			main();
		}	
		
		else {
			cout << "\n\n\t\t   [SAVED SUCCESSFULLY]\n\n";	
			system("pause>0");
			system("cls");
			main();
		}	
		system("pause>0");
		system("cls");
		main();
	}
}

// DISPLAY INVENTORY
void display() {
	defaultTime();
	cout << "***********************************************************" << endl;
	cout << "\n\t\t   [LABORATORY LIST]" << endl << endl;
	cout << "  Unit(s)\t" << "Laboratory Item(s)\n\n";
	for(int k=0; k<ITEM; k++) {
		cout << "     " << arrayAvail[k] << "\t\t";
		for(int l=0; l<ITEM; l++) {
			cout << arrayofItems[k][l];
		} cout << endl;
	}
	system("pause>0");
	system("cls");
	main();
}

// DISPLAY BORROWER'S SLIP
void displaySlip() {
	defaultTime();
	cout << "***********************************************************" << endl;

	cout << "\n\t\t     [BORROWER's SLIP]" << endl;
	if(limit!=0) {
		for(int i=1; i<=limit; i++) {
		cout << "\n===========================================================\n\n";
		cout << "\t\t\t\t\t\t CN: 00" << i << endl << endl;
		cout << "   STUDENT NUMBER: " << info[i].studNum <<"-MN-0"<< endl 
			 << "   Name: " << info[i].name << endl 
			 << "   Year & Section: " << info[i].yearandSec << endl 
			 << "   Date / Time Borrowed: " << info[i].dateTime << endl
			 << "\n   Total item(s) borrowed: "<< info[i].itemInfo[i].itemNum << endl;
		
		for(int j=0; j<info[i].itemInfo[i].itemNum; j++)
			cout << "     Entry #"<< j+1 <<": "<< info[i].itemInfo[j].itemName << "  ["
			     << info[i].itemInfo[j].containUnit<< " unit(s)]"<< endl;
		cout << "\n===========================================================\n";
		}
	}
	
	else 
		cout << "\n\n\t      [NO TRANSACTION HAD BEEN SAVED]\n";
	
	system("pause>0");
	system("cls");
	main();
}

// RETURN SLIP
void returnSlip() {
	char locStudNum[11];
	defaultTime();
	cout << "***********************************************************" << endl;
	cout << "\n\t\t [RETURNING BORROWER's SLIP]" << endl << endl;
	
	if(limit!=0) {
		cout << "Please enter EXACT STUDENT NUMBER to be returned: ";
		cin.clear();
		cin.sync();
		cin.getline(locStudNum,11);
		
		for(int i=1; i<=limit; i++)
			if(strcmp(locStudNum,info[i].studNum)==0) {
				cout << "\n-----------------------------------------------------------\n\n";
				cout << "\t\t\t\t\t\t CN: 00" << i<<endl;
				cout << "   STUDENT NUMBER: " << info[i].studNum<< "-MN-0"<<endl 
					 << "   Name: " << info[i].name << endl 
					 << "   Year & Section: " << info[i].yearandSec << endl 
					 << "   Date / Time Borrowed: " << info[i].dateTime << endl
					 << "\n   Number of item(s) borrowed: "<< info[i].itemInfo[i].itemNum << endl;
				
				for(int j=0; j<info[i].itemInfo[i].itemNum; j++)
					cout << "     Entry #"<< j+1 <<": "<< info[i].itemInfo[j].itemName << "  ["
					     << info[i].itemInfo[j].containUnit<< " unit(s)]"<< endl;
				cout << "\n-----------------------------------------------------------\n\n";
				
				char ans;
				int n;
				cout << "Is this the borrower's slip you want to return? [Y/N]: ";
				cin >> ans;	
						
				switch(ans) {
					case 'Y':
					case 'y':			  
						for(i=1; i<=limit; i++) {
							strcpy(info[i].studNum, info[i+1].studNum);
							strcpy(info[i].name, info[i+1].name);
							strcpy(info[i].yearandSec, info[i+1].yearandSec);
							strcpy(info[i].dateTime, info[i+1].dateTime);
							info[i].itemInfo[i].itemNum = info[i+1].itemInfo[i+1].itemNum;
							
							for(int j=0; j<=info[i].itemInfo[i].itemNum; j++) {
								for(int k=0; k<=ITEM; k++) {
									if (info[i+1].itemInfo[j+1].itemCount == array1[k])
										arrayAvail[k]-=info[i].itemInfo[j].containUnit;
								}
							info[i].itemInfo[j].itemName == info[i+1].itemInfo[j+1].itemName;
							info[i].itemInfo[j].itemCount = info[i+1].itemInfo[j+1].itemCount;  
							}
						}
						limit--;
						cout << "\n\n\t\t   [DELETED SUCCESSFULLY]\n\n";		
						break;
					case 'N':
					case 'n':
						cout << "\n\n\t\t[BORROWER's SLIP NOT DELETED]\n\n";
						break;
					default:
						cout << "\n\n\t\t\t[INVALID INPUT]\n\n";				
						break;
				}
			}
			
			else 
				cout << "\n\n\t       [NOT REGISTERED STUDENT NUMBER]\n";
			system("pause>0");
			system("cls");
			main();
	}
	
	else {
		cout << "\n\t       [NO TRANSACTION HAD BEEN SAVED]\n";
		system("pause>0");
		system("cls");
		main();
	}
}
