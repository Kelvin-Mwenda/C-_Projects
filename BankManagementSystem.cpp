#include<iostream>
#include<vector>
#include<list>
using namespace std;

class BankAccount{
private:
string name;
int accountno;
double balance,amount;

public:
BankAccount(string n,int ac,double bal){
name=n;
accountno=ac;
balance=bal;
}
void setname(string name1){
    name = name1;
}
string getname(){
return name;
}
void setaccount(int account1){
    accountno = account1;
}
int getaccount(){
return accountno;
}
double getbalance(){
return balance;
} 

void depositamount(double amount){
    balance+=amount;
}
void withdrawamount(double amount){
    if(balance<amount){
        cout<<"\tSorry, you have insufficient amount...!\n";
    }
    else{
        balance-=amount;
    }
}

void display(){
    cout<<"\tName:"<<name<<endl;
    cout<<"\tAccount Number:"<<accountno<<endl;
    cout<<"\tBalance:"<<balance<<endl;
}
};

//ADDING A NEW ACCOUNT
void AddNewAccount(vector<BankAccount> &accounts)
{
    double balance1 = 0;
    cout<<"\tEnter your name:";
    string name1;
    cin>>name1;
    int accountnumber;
    cout<<"\tEnter your preferred account number:";
    cin>>accountnumber;

    for(int i=0;i<accounts.size();i++)
    {
    if(accounts[i].getaccount()==accountnumber)
    {
        cout<<"\tSorry, this account already exist...\n";
        return;
    }
    else
    {
        BankAccount newaccount(name1,accountnumber,balance1);
        accounts.push_back(newaccount);
        cout<<"\tAccount added successfully...\n";
    }
    }
}

//DISPLAYS ALL ACCOUNTS
void showAllAccounts(vector<BankAccount> &accounts)
{
cout<<"\n\t*****All account holders*****\n";
for(int i=0;i<accounts.size();i++)
{
    if(accounts.empty()){
        cout<<"\tNo accounts found...!!"<<endl;
    }
    else
    {
        for(int i=0;i<accounts.size();i++)
        {
        accounts[i].display();
        cout<<endl;
        }
    }
}
}

//SEARCH FOR ACCOUNT
void searchAccount(vector<BankAccount> &accounts){
cout<<"\tEnter the account number:";
int accountnum1;
cin>>accountnum1;

for(int i=0;i<accounts.size();i++)
{
if(accounts[i].getaccount()==accountnum1)
{
accounts[i].display();
cout<<endl;
break;
}
else
{
cout<<"Sorry the account does not exist\n";
}
}
}

//DEPOSIT MONEY
void deposit(vector<BankAccount> &accounts){
    for(int i=0;i<accounts.size();i++)
    {
        bool found = false;
        do{
        cout<<"\tEnter account number:";
        int account1;
        cin>>account1;
        if(account1==accounts[i].getaccount())
        {
            found = true;
        }
        else{
            cout<<"\tSorry, this accountdoes not exist...!\n";
        }
        }while(found==false);

        if(found==true)
        {
            double amount;
            cout<<"\tEnter amount you want to deposit:";
            cin>>amount;
            accounts[i].depositamount(amount);
            cout<<"\tNew balance:"<<accounts[i].getbalance()<<endl;
        }
    }
}

//WITHDRAW MONEY
void withdraw(vector<BankAccount>&accounts){
for(int i=0;i<accounts.size();i++)
{
    cout<<"\tEnter account number:";
    int accountnum;
    cin>>accountnum;
    if(accountnum==accounts[i].getaccount())
    {
        double amount;
        cin>>amount;
        accounts[i].withdrawamount(amount);
        cout<<"\tNew balance is Ksh."<<accounts[i].getbalance();
    }
    else
    {
        cout<<"\tSorry, the account does not exist...!\n";
    }
}
}

int main(){
    vector<BankAccount> accounts;

    int choice;
    char op;
    do{
    system("cls");
    cout<<"\t-----Bank Management System-----\n";
    cout<<"\t**MAIN MENU**\n";
    cout<<"\t1. Create new account\n";
    cout<<"\t2. Show all accounts\n";
    cout<<"\t3. Search account\n";
    cout<<"\t4. Deposit money\n";
    cout<<"\t5. Withdraw money\n";
    cout<<"\t6. Exit\n";
    cout<<"\t-----------------------------\n";
    cout<<"\tEnter your choice:";
   
    cin>>choice;
    switch(choice){
        case 1:AddNewAccount(accounts);
        break;
        case 2:showAllAccounts(accounts);
        break;
        case 3:searchAccount(accounts);
        break;
        case 4:deposit(accounts); 
        break;
        case 5:withdraw(accounts);
        break;
        case 6:exit(1);
        break;
        default:
        cout<<"Invalid choice"<<endl;
        break;
    }
    cout<<"\tDo you wish to continue?[y/n]:";
    cin>>op;
    }while(op=='y'||op=='Y');
    
    return 0;
}