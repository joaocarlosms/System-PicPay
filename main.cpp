#include "PicPay.h"
#include "Nodo.h"
#include "DoubleChaining.h"
#include "Transaction.h"
#include <cstdlib>

using namespace std;

int main(){
    PicPay pp;
    pp.fillData();
    int position;
    char option = 's';
    int opc;
    DoubleChaining chg;
    Transaction tr;
    string cpf_wanted, email_wanted;
    Nodo* account_wanted;

    do{
        pp.options_menu();
        cin >> option;
        cout << endl;

        switch(option){
            case '1':
                chg.insert();
                chg.print();
                break;
            
            case '2':
                cout << "ENTER THE POSITION FOR ADD NEW ACCOUNT: ";
                cin >> position;
                chg.insert(position);
                chg.print();
                break;
            
            case '3':
                chg.remove();
                chg.print();
                break;
            
            case '4':
                cout << "ENTER THE POSITION FOR REMOVE ACCOUNT: ";
                cin >> position;
                chg.remove(position);
                chg.print();
                break;

            case '5':
                cout << "------FIND ACCOUNT-----\n";
                cout << "ENTER YOUR CPF: ";
                cin.ignore();
                getline(cin, cpf_wanted);
                cout << "ENTER YOUR E-MAIL: ";
                cin.ignore();
                getline(cin, email_wanted);
                
                account_wanted = chg.find(cpf_wanted, email_wanted);
                if(account_wanted != NULL){
                    cout << "FOUND ACCOUNT!\n";
                    cout << "CPF: " << account_wanted->getItem().getCpf() << "\n";
                    cout << "E-MAIL: " << account_wanted->getItem().getEmail() << "\n";
                }else{
                    cout << "ERROR! Not found account\n";
                }
                break;            
            case '6':
                do{
                    pp.options_transaction();
                    cin >> opc;
                    if(opc < 0 || opc > 2){
                        cout << "INVALID OPTION!\n";
                    }
                }while(opc < 0 || opc > 2);
                
                if(opc == 1){
                    tr.deposit_transaction();
                    break;
                }else if(opc == 2){
                    tr.booty_transaction();
                    break;
                }else{
                    pp.options_menu();
                }

            case '7':
                pp.printData();
                break;          
        }
        
    }while(option != 's' && option != 'S');

    return 0;
}

