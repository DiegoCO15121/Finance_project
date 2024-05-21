#include <bits/stdc++.h>
using namespace std;

// Aux functions
float string_to_float(string aux){
    float money = stof(aux);
    return money;
}
bool file_exist(string address){
    ifstream file(address.c_str());
    return file.good();
}
void rest_money(float mny){
    ofstream file;
    string address = "C:/data_finances/mny.txt", aux;
    float money_file;

    if (file_exist(address)){
        // saving old data
        ifstream file_aux(address.c_str(), ios::in);
        getline(file_aux, aux);
        money_file = string_to_float(aux);

        money_file -= mny;
        // Updating data
        file.open(address.c_str(), ios::out);
        file << money_file;
        file.close();
    }else{
        cout << "Error money file doesn't exist" << endl;
    }
}
struct Register{
    char exp[50];
    float price;
    char date[15];
};

// Mains functions
void saveMoney(){
    ofstream file;
    string address = "C:/data_finances/mny.txt", aux;
    float money_file,mny;

    cout<<"Amount to save: ";cin>>mny;

    if (file_exist(address)){//Compressing file existence to avoid data loss
        // Saving old data
        ifstream file_aux(address.c_str());
        getline(file_aux, aux);
        money_file = string_to_float(aux);

        mny += money_file;
        // Updating data
        file.open(address.c_str(), ios::out);
        file << mny;
        cout << "Saved" << endl;
        file.close(); 
        
    }else{ //Creating a file in case it doesn't exist
        file.open(address.c_str(), ios::out);
        file << mny;
        cout << "Saved" << endl;
        file.close();
    }
}

void saveExpenses(){
    if (file_exist("C:/data_finances/mny.txt")){ //Compressing file existence to avoid data loss
        string addss = "C:/data_finances/Exp";
        int x;

        cout << "Number of products to be registred: ";
        cin >> x;
        Register exp[x];

        for (int i = 0; i < x; ++i){ 
            fflush(stdin);
            cout << "Name of product: ";
            cin.getline(exp[i].exp, 30);
            cout << "Price: ";
            cin >> exp[i].price;
            fflush(stdin);
            cout<<"Date (dd/mm/yyyy): ";
            cin.getline(exp[i].date, 15);
            rest_money(exp[i].price); //Subtracting the money to update the balance
        }

        for(int i=0;i<x;++i){//Saving data
            if (file_exist(addss)){ 
                ofstream file(addss.c_str(), ios::app | ios::binary);
                file.write((char *)&exp[i], sizeof(Register)); 
                file.close();
            }else{
                ofstream file(addss.c_str(), ios::out | ios::binary);
                file.write((char *)&exp[i], sizeof(Register)); 
                file.close();
            }
        }
    }else{ 
        cout << "Error, money file does not exist. You must save your money data" << endl;
        saveMoney();
        saveExpenses();
    }
}

void showMoney(){
    string addss = "C:/data_finances/mny.txt";
    string data;

    if (file_exist(addss)){
        ifstream file(addss.c_str(), ios::in);
        getline(file, data);
        cout<<"\nYour balance is: "<<data<<endl;
        file.close();
    }else{
        cout << "Error, file 'Money' does not exist" << endl;
        saveMoney();
    }
}

void showExpenses(){
    string addss= "C:/data_finances/Exp";
    Register exp;
    int i = 1;

    if(file_exist(addss)){
        ifstream file(addss.c_str(),ios::in|ios::binary);
        cout<<"\nList of your expenses:"<<endl;
        while(!file.eof()){
            file.read((char *)(float *)(char *)&exp, sizeof(Register));
            if(!file.eof()){
                cout<<i<<". Name: "<<exp.exp<<" | Price: "<<exp.price<<" | Date: "<<exp.date<<endl;
            }
            i+=1;
        }
        file.close();
    }else{
        cout<<"Error, file 'Expenses' does not exist"<<endl;
        saveExpenses();
    }
}