#include<iostream>
#include<conio.h>
using namespace std;
void add();
void deleteAcc();
void edit();
void transaction();
void bank();
void display(); // to check if na add, na edit ug na delete ba ang account and if na update ba ang balance. pwede ni ninyu idelete after pag ipasa na ninyu. tapos, basin naa koy wala na comment nga para sa display or any other unused variables, kamo nlg delete.
void Balance();
void Deposit();
void Withdraw();

string pins[10] = "";
string name[10] = "";
int bal[10];
int iterate = 0;
int deposit = 0;
int choice, loop=1;
string accName, pin, rePin;
string desired;
int withdrawBal, withdraw;
int availableBal, totalBal;

int main(){
	
	int action;
	
	cout<<"\nChoose Action";
	cout<<"\n[1] Add Account";
	cout<<"\n[2] Edit Account";
	cout<<"\n[3] Delete Account";
	cout<<"\n[4] Transaction";
	cout<<"\n[5] Exit";
	cout<<"\nEnter Choice: ";
	cin>>action;
	
	if (action == 1){
		add();		
	} else if (action == 2){
		edit();
	} else if (action == 3){
		deleteAcc();
	} else if (action == 4){
		bank();	
	} else if (action == 5){
		cout<<"\n\n Thank You For Visiting Park bank!";
		exit(0);
	} else {
		cout<<"\nInvalid Input!\n";
		main();
	}
	
	getch();	
}


void add(){
	int availableBal = 1000;
	cout<<"\n ----- Add Account -----";
	cout<<"\n Enter Name: ";
	cin>>accName;
	cout<<" Enter 6 Digit Pin Code: ";
	cin>>pin;
		if (pin.length() != 6){
			cout<<"Pin Code Must Have 6 Digits ";
			add();
		}
		
		for(int x = 0; x<10; x++){
			if(pin == pins[x]){
				cout<<"\n Pin Not Available. Use Other Pin!";
				add();
			}
		}

		do{
			cout<<" Re-Enter Pin Code: ";
			cin>>rePin;
	
			if ( rePin == pin){
				name[iterate] = accName;	
				pins[iterate] = rePin;
				bal[iterate] = availableBal;
				break;
			} else {
				cout<<" Try Again!";
			}	
	
	}while(rePin != pin);
	
	iterate++;
	cout<<iterate;
	cout<<"\nCongratulations! You Are Now Successfully Registered! ";
	display();//---------------------------------------------------------------------------------------------------------------
	main();	
}


void edit(){
	
	cout<<"\n ----- Edit Account -----";
	cout<<"\n Enter Old Pin Code: ";
	cin>>pin;
	
	for(int x = 0; x< 10; x++){
	
		if (pin == pins[x]){
			
			cout<<"\n Hello "<<name[x]<<"!\n";
			cout<<"\n Enter Desired Pin Code: ";
			cin>>desired;
			
				if (desired.length() != 6){
				
				cout<<"Pin Code Must Have 6 Digits ";
				edit();
				} 
				
				for(int y= 0; y<10; y++){
					 
					if ( desired == pins[y]){
					
						cout<<"Pin Code Not Available!\n";
						edit();
					}	
				}
			
			cout<<"\n Are You Sure You Want To Change Your Pin?\n[1] Yes\n[2] No\n Enter Choice:  ";
			cin>>choice;
			
			if ( choice == 1){
				cout<<"\nAccount Successfully Edited! ";
				pins[x] = desired;
				main();
			} else if ( choice == 2){
				main();
			} else {
				cout<<"Invalid Input! ";
				main();
			}
		} 
		
	}
		cout<<"\nSystem doesn't recognized Pin Code. \n";
		main();
}

void deleteAcc(){
	
	cout<<"\n ----- Delete Account -----";
	cout<<"\n Enter 6 Digit Pin Code: ";
	cin>>pin;
	
	for(int x = 0; x< 10; x++){
	
		if (pin == pins[x]){
			
			cout<<"\n Hello "<<name[x]<<"\n";
			cout<<"\n Are You Sure You Want To Delete Your Account?\n[1] Yes\n[2] No\n Enter Choice:  ";
			cin>>choice;
			
			if ( choice == 1){
				
				for(int y = x; y < 10; y++){
				
				pins[y] = pins[y+1];
				name[y] = name[y+1];
				bal[y] = bal[y+1];
				
					if ( pins[y+1] == ""){
						
						iterate--;
						break;
					}
				}
				cout<<iterate;
				cout<<"\nAccount Successfully Deleted! ";
				display(); // -------------------------------------------------------------------------------------------------------------------------------------------
				main();
			} else if ( choice == 2){
				main();
			} else {
				cout<<"Invalid Input! ";
				main();
			}
		}
		
	}
	
	cout<<"\nSystem doesn't recognized Pin Code. \n";
	main();
}

void bank(){
	
	string pinHere;
	
	cout<<"\nEnter Your Pin Code: ";
	cin>>pinHere;
	pin = pinHere;
	
	while( loop != 4){
			int x;
			for( x = 0; x<10; x++){
				if(pinHere == pins[x]){
					cout<<"\n\n\t Welcome To Park Bank, "<< name[x] <<"!\n";
					loop = 0;
					transaction();
						break;
			 	} 
		 }
		 	
			cout<<"\n Try Again (" << 3-loop <<" try remaining)";
			loop++;
			
			if (3-loop == -1){
			
				cout<<"\n\n Program Terminated! ";
				exit(0);
			}
			bank();
		}
		
		
	}
	
void transaction(){
		
		int transaction;
		cout<<"\nChoose Your Transaction: ";
		cout<<"\n[1] Balance Inquiry";
		cout<<"\n[2] Withdraw";
		cout<<"\n[3] Deposit";
		cout<<"\n[4] Exit Transaction";
		cout<<"\n Your Transaction: ";
		cin>>transaction;
	
	if ( transaction == 1){
		Balance();
	} else if ( transaction == 2){
		Withdraw();
	} else if ( transaction == 3){
		Deposit();
	} else if ( transaction == 4){
		cout<<"\n\n Thank You For Visiting Park bank!";
		main();
	} else {
		cout<<"Invalid Input!";
	}
	
	display(); //----------------------------------------------------------------------------------------------------------------------------------------
}

//-----------------------------------------------------------------------------------------------
void display(){
	
	
		cout<<"\n Names"<<"\t Pins "<<"\t Balances\n";
	for (int x = 0 ; x<10; x++){
		
		cout<<"\n"<<x+1<<". "<<name[x] <<"\t" << pins[x] <<"\t"<< bal[x];
	}
}
//-------------------------------------------------------------------------------------------------
void Balance(){
	
			for(int x = 0; x<10; x++){
			if(pin == pins[x]){
				cout<<"\n Available Balance: P"<<bal[x] - 1000<<".00";
				cout<<"\n Total Balance: P"<<bal[x]<<".00";
				
			}
		}
		
	cout<<"\n\n Do You Want Another Transaction?\n[1] Yes\n[2] No\n Enter Choice: ";
	cin>>choice;
	
	if (choice == 1){
		transaction();
	} else if( choice == 2){
		cout<<"\n\n Log Out?\n[1] Yes\n[2] No\n Enter Choice: ";
		cin>>choice;
		
			if ( choice == 1){
				system("cls");
				main();
			} else if (choice == 2){
				
				transaction();
			}
		
	} else {
		cout<<"\n Input Invalid!";
	}	
}

void Deposit(){
	
		cout<<"\nDeposit Amount: P";
		cin>>deposit;
	
		for(int x = 0; x<10; x++){
			if(pin == pins[x]){
				bal[x] = bal[x] + deposit;
				cout<<"\n Available Balance: P"<< bal[x] - 1000<<".00";
				cout<<"\n Total Balance: P"<<bal[x]<<".00";
				cout<<"\n Total Credit: P"<<deposit<<".00";
			}
		}	
		
	cout<<"\n\n Do You Want Another Transaction?\n[1] Yes\n[2] No\n Enter Choice: ";
	cin>>choice;
	
	if (choice == 1){
		transaction();
	} else if( choice == 2){
		cout<<"\n\n Log Out?\n[1] Yes\n[2] No\n Enter Choice: ";
		cin>>choice;
		
			if ( choice == 1){
				system("cls");
				display(); // -------------------------------------------------------------------------------------------------------------------------------------------
				main();
			} else if (choice == 2){
				
				transaction();
			}
		
	} else {
		cout<<"\n Input Invalid!";
	}	
}

void Withdraw(){
	int amount;
	cout<<"\nWithdraw Amount: P";
	cin>>withdraw;
	
		for(int x = 0; x<10; x++){
			if(pin == pins[x]){
				amount = bal[x] - withdraw;
			}
		}
		
		if (amount < 1000){
			
		cout<<"\n Insufficient Amount! ";
			
		} else {
			
			for(int x = 0; x<10; x++){
				if(pin == pins[x]){
				bal[x] = amount;
				amount = bal[x];
				}
			}
			cout<<"\n Available Balance: P"<<amount - 1000<<".00";
			cout<<"\n Total Balance: P"<<amount<<".00";
			cout<<"\n Total Debit: P"<<withdraw<<".00";	
		}
		
			cout<<"\n\n Do You Want Another Transaction?\n[1] Yes\n[2] No\n Enter Choice: ";
			cin>>choice;
	
			if (choice == 1){
				transaction();
			} else if( choice == 2){
				
				cout<<"\n\n Log Out?\n[1] Yes\n[2] No\n Enter Choice: ";
				cin>>choice;
		
					if ( choice == 1){
					system("cls");
					display(); // -------------------------------------------------------------------------------------------------------------------------------------------
					main();
					
					} else if (choice == 2){
	
					transaction();
					}	
		
			} else {
	
			cout<<"\n Input Invalid!";
			}
		
}

