
#include "PicPay.h"

PicPay::PicPay(){
    this->completeName = " ";
    this->cpf = " ";
    this->email = " ";
    this->password = " ";
    this->balance = 0.0;
}

PicPay::PicPay(string completeName, string cpf, string email, string password, double balance){
    this->completeName = completeName;
    this->cpf = cpf;
    this->email = email;
    this->password = password;
    this->balance = balance;
}

PicPay::PicPay(const PicPay& orig){
    this->completeName = orig.getCompleteName();
    this->cpf = orig.getCpf();
    this->email = orig.getEmail();
    this->password = orig.getPassword();
    this->balance = orig.getBalance();
}

void PicPay::setCompleteName(string completeName){
    this->completeName = completeName;
}

string PicPay::getCompleteName() const{
    return completeName;
}

void PicPay::setCpf(string cpf){
    this->cpf = cpf;
}

string PicPay::getCpf() const{
    return cpf;
}

void PicPay::setEmail(string email){
    this->email = email;
}

string PicPay::getEmail() const{
    return email;
}

void PicPay::setPassword(string password){
    this->password = password;
}

string PicPay::getPassword() const{
    return password;
}

void PicPay::setBalance(double balance){
    this->balance = balance;
}

double PicPay::getBalance() const{
    return balance;
}

void PicPay::save_in_file(){
    string pathPaste = "picpay_user_data.txt";
    ofstream save_file;
    save_file.open(pathPaste, ios::app);

    if(!save_file.is_open()){
        cout << "ERROR! File " << pathPaste << " not found in paste\n";
    }else{
        save_file << left <<  setw(50) << "COMPLETE NAME" << setw(15) << "CPF" << setw(30) << "EMAIL" << setw(10) << "BALANCE" << "\n";
        save_file << left << setw(50) << completeName << setw(15) << cpf << setw(30) << email << setw(10) << balance << endl;

        save_file.close();
    }
}

void PicPay::fillData(){
    cout << "------------FILL BANK ACCOUNT-----------\n"; 
    cout << "COMPLETE NAME: ";    
    cin.ignore();
    getline(cin, this->completeName);
    cout << "CPF: ";
    getline(cin, this->cpf);
    cout << "E-MAIL(name@example.com): ";
    getline(cin, this->email);
    cout << "PASSWORD: ";
    cin.ignore();
    getline(cin, this->password);
    cout << "BALANCE: ";
    cin >> this->balance;

    save_in_file();
    cout << "----------------------------------------\n";
}

void PicPay::printData(){
    cout << "-------------DATA BANK ACCOUNT-------------\n";
    cout << "COMPLETE NAME: " << completeName << endl;
    cout << "CPF: " << cpf << endl;
    cout << "E-MAIL: " << email << endl;
    cout << "BALANCE: " << balance << endl;
    cout << "-------------------------------------------\n";
}

void PicPay::copy(PicPay& other){
    this->completeName = other.getCompleteName();
    this->cpf = other.getCpf();
    this->email = other.getEmail();
    this->password = other.getPassword();
    this->balance = other.getBalance();
}

void PicPay::abbreviationPrint() const{
    cout << left << setw(50) << "COMPLETE NAME" << setw(15) << "CPF" << setw(30) << "EMAIL" << setw(10) << "BALANCE" << "\n";
    cout << left << setw(50) << completeName << setw(15) << cpf << setw(30) << email << setw(10) << "R$-" << balance << "\n";
}

void PicPay::options_menu(){
    cout << "====================|OPTIONS MENU|=====================\n";
    cout << "|| 1- ADD NEW ACCOUNT IN THE FIRST POSITION          ||\n";
    cout << "||---------------------------------------------------||\n";
    cout << "|| 2- ADD NEW ACCOUNT IN ANY POSITION THE LIST       ||\n";
    cout << "||---------------------------------------------------||\n";
    cout << "|| 3- REMOVE ACCOUNT IN THE FIRST POSITION           ||\n";
    cout << "||---------------------------------------------------||\n";
    cout << "|| 4- REMOVE ACCOUNT IN ANY POSTTION THE LIST        ||\n";
    cout << "||---------------------------------------------------||\n";
    cout << "|| 5 - FIND FOR ACCOUNT IN LIST                      ||\n";
    cout << "||---------------------------------------------------||\n";
    cout << "|| 6- REALIZE TRANSACTION                            ||\n";
    cout << "||---------------------------------------------------||\n";
    cout << "|| 7- ENVISION DATA BANK ACCOUNT                     ||\n";
    cout << "||---------------------------------------------------||\n";
    cout << "|| s- FINISH OPERATION                               ||\n";
    cout << "=======================================================\n";
}

void PicPay::options_transaction(){
    cout << "========|OPTIONS TRANSACTIONS|========\n";
    cout << "|| 1 -> BANK DEPOSIT                ||\n";
    cout << "||----------------------------------||\n";
    cout << "|| 2 -> BANK BOOTY                  ||\n";
    cout << "||----------------------------------||\n";
    cout << "|| 0 -> BACK TO MENU                ||\n";
    cout << "======================================\n";
}

PicPay::~PicPay(){
}

