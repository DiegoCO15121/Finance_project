#include<iostream>
#include "Finances_functions.h"
using namespace std;

void menu(){
    cout<<"\t***** Welcome to your finances manager *****"<<endl;
    cout<<"1.Save or add money"<<endl;
    cout<<"2.Save expences"<<endl;
    cout<<"3.Check available money "<<endl;
    cout<<"4.Check expenses"<<endl;
    cout<<"5.Exit"<<endl;
}

int main(){
    int ans;
    do{
        fflush(stdin);
        menu();
        cout<<"Choose an option: ";cin>>ans;
        
        switch(ans){
            case 1: 
            fflush(stdin);
            saveMoney();
            break;

            case 2: 
            fflush(stdin);
            saveExpenses();
            break;

            case 3: 
            fflush(stdin);
            showMoney();
            break;
            
            case 4: 
            fflush(stdin);
            showExpenses();
            break;

            case 5: cout<<"Bye!"<<endl;
            break;

            default : cout<<"That option is not in the menu"<<endl;
        }
        cout<<endl;
    }while(ans != 5);

    return 0;
}