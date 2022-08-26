#include<conio.h>
#include<iostream>
#include<string>
using namespace std;

class atm
{
private:
	long int accno;
	string name;
	int pin;
	double balance;
	string mobile;
public:
	void setdata(long int accno_a,string name_a,int pin_a,double balance_a,string mobile_a){
		accno= accno_a;
		name= name_a;
		pin = pin_a;
		balance = balance_a;
		mobile = mobile_a;
	}
	long int getaccno(){
		return accno;
	}
	string getname(){
		return name;
	}
	int getpin(){
		return pin;
	}
	double getbalance(){
		return balance;
	}
	string getmobile(){
		return mobile;
	}
	void setmobile(string mob_prev,string mob_new){
		if(mob_prev==mobile){
			cout<<endl<<"Enter new number: ";
			cin>>mob_new;
			if(mob_prev!=mob_new){
			mobile=mob_new;
			cout<<endl<<"Mobile Number updated successfully";
			_getch();}
			else{
				cout<<endl<<"Same number cant be new number!";
				_getch();
			}
		}
		else{
			cout<<endl<<"Incorrect Mobile Number!!";
			_getch();
		}
	}
	void cashwithdraw(int amount){
		if(amount>0&&amount<balance){
			balance-=amount;
			cout << endl << "Please Collect Your Cash";
			cout << endl << "Available Balance :" << balance;
			_getch();
		}
		else{
			cout<<endl<<"Insufficient Balance!!";
			_getch();
		}
	}
};


int main(){
	int choice=0,enterPin;
	long int accNum;
	
	system("cls");
	
	atm user1;
	user1.setdata(1234567, "Tim", 1111, 45000.90, "9087654321");
	
	do{
		system("cls");
		cout<<"*****Welcome to ATM****"<<endl;
		cout<<"Enter your account number";
		cin>>accNum;
		cout<<endl<<"Enter PIN";
		cin>>enterPin;
		
		if((accNum==user1.getaccno())&&(enterPin==user1.getpin())){
			do{
				int am =0;
				string ol_mob,new_mob;
				system("cls");
				cout << endl << "**** Welcome to ATM *****" << endl;
				cout << endl << "Select Options ";
				cout << endl << "1. Check Balance";
				cout << endl << "2. Cash withdraw";
				cout << endl << "3. Show User Details";
				cout << endl << "4. Update Mobile no.";
				cout << endl << "5. Exit" << endl;
				cin >> choice;	
				
				switch(choice){
					case 1:
						cout<<endl<<"Your bank balance is : "<<user1.getbalance();
						_getch();
						break;
					case 2:
						cout<<endl<<"Enter an amount to withdraw: ";
						cin>>am;
						user1.cashwithdraw(am);
						break;
					case 3:										// if user presses 3
						cout << endl << "*** User Details are :- ";
						cout << endl << "-> Account no" << user1.getaccno();
						cout << endl << "-> Name      " << user1.getname();
						cout << endl << "-> Balance   " << user1.getbalance();
						cout << endl << "-> Mobile No." << user1.getmobile();
													// getting and printing user details
					_getch();
					break;
					case 4:
						cout<<endl<<"Enter old number: ";
						cin>>ol_mob;
						user1.setmobile(ol_mob,new_mob);
						break;
					case 5:
						exit(0);
					default:
						cout<< endl<<"Enter  valid data ";
				}
				
			}while(1);
				
		}
		else
		{
			cout << endl << "User Details are Invalid !!! ";
			_getch();
		}
	}while(1);
	return 0;
}
