
/* 
 * File:   Transaction.cpp
 * Author: Admin
 * 
 * Created on 17 de agosto de 2023, 16:21
 */

#include "Transaction.h"

Transaction::Transaction(){
    this->balance_sender = 0.0;
    this->balance_receiver = 0.0;
    this->transaction_quantifier = 0;
}

Transaction::Transaction(double sender, double receiver, int transaction_quantifier){
    this->balance_sender = sender;
    this-> balance_receiver = receiver;
    this->transaction_quantifier = transaction_quantifier;
}

Transaction::Transaction(const Transaction& orig) {
    this->balance_sender = orig.getBalance_sender();
    this->balance_receiver = orig.getBalance_receiver();
    this->transaction_quantifier = orig.getTransactionQuantifier();
}

void Transaction::setBalance_sender(double sender){
    this->balance_sender = balance_sender;
}

double Transaction::getBalance_sender() const{
    return balance_sender;
}

void Transaction::setBalance_receiver(double receiver){
    this->balance_receiver = balance_receiver;
}

double Transaction:: getBalance_receiver() const{
    return balance_receiver;
}

void Transaction::setTransactionQuantifier(int transaction_quantifier){
    this->transaction_quantifier = transaction_quantifier;
}

int Transaction::getTransactionQuantifier() const{
    return transaction_quantifier;
}

void Transaction::deposit_transaction(){
    DoubleChaining chg;
    Transaction tr;
    PicPay pp;
    int optionUser = chg.verify_user_type();
    double value_transfer;

    if(optionUser == 1){
        cout << "-> USER: SHOPKEEPER\n";
        cout << "Shopkeeper can only receive transfers and are restricted from sending money!\n";
        cout << "Enter the amount received from the transfer: ";
        cin >> value_transfer;
        
        tr.setBalance_receiver(value_transfer);
        cout << "Operation realized with successly!\n";
    
    }else if(optionUser == 2){
        cout << "-> USER: COMMOM\n";
        
        if(!balance_verify()){
            cout << "Invalid Operation! Balance insufficient\n";
        }else{
            tr.setBalance_sender(value_transfer);
            cout << "Operation realized with successly!\n";
        }
    transaction_quantifier++;
    
    }else{
        cout << "ERROR! User not found\n";
    } 
}

void Transaction::booty_transaction(){
    DoubleChaining chg;
    Transaction tr;
    int optionUser = chg.verify_user_type();
    double value_transfer;

    if(optionUser == 1){
        cout << "-> USER: SHOPKEEPER\n";
        cout << "Shopkeeper can only receive transfers and are restricted from sending money!\n";
        cout << "Enter the amount received from the transfer: ";
        cin >> value_transfer;
        
        tr.setBalance_receiver(value_transfer);
        cout << "Operation realized with successly!\n";
    
    }else if(optionUser == 2){
        cout << "-> USER: COMMOM\n";
        
        if(!balance_verify()){
            cout << "Invalid Operation! Balance insufficient\n";
        }else{
            tr.setBalance_sender(value_transfer);
            cout << "Operation realized with successly!\n";
        }
        transaction_quantifier++;

    }else{
        cout << "ERROR! User not found\n";
    }
}

/*
 * Verifica o saldo do usuario para saber se ele está apto para realizar determinada transacao;
 * @param posicao
 * @return 
 */

bool Transaction::balance_verify(){ // 
    PicPay pp;
    double value_transfer;
    do{
        cout << "Enter the value to you want transfers: ";
        cin >> value_transfer;
    }while(value_transfer < 0);
    

    if(pp.getBalance() >= value_transfer){
        return true;
    }else{
        return false;
    }
}

Transaction::~Transaction() {
}

