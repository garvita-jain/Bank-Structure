/* DECLARE THE STRUCTURE 'ACCOUNTS' FOR 5 CUSTOMERS WITH THE FOLLOWING FIELDS: 
  1. DEPOSITOR NAME 
  2. ACCOUNT NO. 
  3. ACCOUNT TYPE 
  4. BALANCE 
  WRITE A MENU DRIVEN PROGRAM TO PERFORM THE FOLLOWING FUNCTIONS : 
  1. INITIALISE STRUCTURE MEMBERS 
  2. DEPOSIT MONEY 
  3. WITHDRAWAL AFTER CHECKING MIN. BALANCE ( MIN. BALANCE = RS. 1000) 
  4. DISPLAY INFORMATION OF A PARTICULAR CUSTOMER ACCORDING TO ACCOUNT NO. 
  5. DISPLAY STATUS OF ALL CUSTOMERS  */ 

#include<iostream.h> 
#include<conio.h> 
#include<stdio.h> 
struct accounts 
{ 
   char depositor[15]; 
   long accno; 
   char acctype; 
   float balance; 
}; 

accounts A1[5]; 
void input(); 
void deposit(int); 
void withdrawal(int); 
int identify(int); 

void main() 
{ 
   clrscr(); 
   int choice, accno; 
   input(); 
   cout<<"\n 1. DEPOSIT MONEY "; 
   cout<<"\n 2. WITHDRAW MONEY "; 
   cout<<"\n 3. DISPLAY INFO OF DEPOSITOR "; 
   cout<<"\n 4. DISPLAY STATUS OF ALL CUSTOMERS "; 
   cout<<"\n ENTER CHOICE : "; 
   cin>>choice; 
   switch(choice) 
   { 
      case 1: { 
        cout<<"\n ENTER ACCOUNT NUMBER : "; 
        cin>>accno; 
        deposit(accno); 
       }break; 
      case 2: { 
        cout<<"\n ENTER ACCOUNT NUMBER : "; 
        cin>>accno; 
        withdrawal(accno); 
       }break; 
      case 3: { 
        cout<<"\n ENTER ACCOUNT NUMBER : "; 
        cin>>accno; 
        int x=identify(accno); 
        if(x!=5) 
        { 
         cout<<"\n DEPOSITOR'S NAME : "<<A1[x].depositor; 
         cout<<"\n ACCOUNT TYPE : "<<A1[x].acctype; 
         cout<<"\n BALANCE: "<<A1[x].balance; 
        } 
       }break; 
      case 4: { 
        for(int i=0; i<5; i++) 
        { 
         cout<<"\n ACCOUNT NO. : "<<A1[i].accno; 
         cout<<"\n DEPOSITOR'S NAME : "<<A1[i].depositor; 
         cout<<"\n ACCOUNT TYPE : "<<A1[i].acctype; 
         cout<<"\n BALANCE : "<<A1[i].balance; 
        } 
       }break; 
      default : cout<<"\n INVALID CHOICE "; 
   } 
   getch(); 
} 

void input() 
{ 
   for(int i=0; i<5; i++) 
   { 
      cout<<"\n ENTER DEPOSITOR'S NAME "; 
      gets(A1[i].depositor); 
      cout<<"\n ENTER ACCOUNT NO. "; 
      cin>>A1[i].accno; 
      cout<<"\n ENTER ACCOUNT TYPE [ S-SAVINGS : C-CURRENT ] "; 
      cin>>A1[i].acctype; 
      cout<<"\n ENTER BALANCE AMOUNT "; 
      cin>>A1[i].balance; 
      getch(); 
      clrscr(); 
   } 
} 

int identify(int accno) 
{ 
 int flag=0; 
 for(int i=0; i<5; i++) 
 { 
    if(A1[i].accno==accno) 
      flag=1; 
    else 
      flag=-1; 
 } 
 if(flag==-1) 
    cout<<"\n CANNOT IDENTIFY ACCOUNT NO "; 
  
 return(i); 
} 

void deposit(int accno) 
{ 
   int deposit; 
   for(int i=0; i<5; i++) 
   { 
      if(accno==A1[i].accno) 
      { 
         cout<<"\n ENTER THE AMOUNT TO BE DEPOSITED "; 
         cin>>deposit; 
         A1[i].balance+=deposit; 
         cout<<"\n TRANSACTION COMPLETED"; 
         cout<<"\n YOUR CURRENT BALANCE IS "<<A1[i].balance; 
      } 
   } 
   clrscr(); 
} 

void withdrawal(int accno) 
{ 
   int withdraw; 
   for(int i=0; i<5; i++) 
   { 
      if(A1[i].accno==accno) 
      { 
         cout<<"\n DEPOSITOR'S NAME : "<<A1[i].depositor; 
         cout<<"\n ENTER AMOUNT TO BE WITHDRAWED "; 
         cin>>withdraw; 
         if(A1[i].balance-withdraw>=1000) 
         { 
            A1[i].balance-=withdraw; 
            cout<<"\n TRANSACTION COMPLETED"; 
            cout<<"\n YOUR CURRENT BALANCE IS "<<A1[i].balance; 
         } 
         else 
         { 
            cout<<"\n TRANSACTION FAILED "; 
            cout<<"\n INSUFFICIENT BALANCE "; 
         } 
      } 
   } 
   getch(); 
   clrscr(); 
} 
