
/* 
 * File:   Transaction.h
 * Author: Admin
 *
 * Created on 17 de agosto de 2023, 16:21
 */
#include "DoubleChaining.h"
#include "PicPay.h"
#include "Nodo.h"
#include <iostream>

using namespace std;

#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction {
public:
    Transaction();
    Transaction(double balance_sender, double balance_receiver, int transaction_quantifier);
    Transaction(const Transaction& orig);
    void setBalance_sender(double balance_sender);
    double getBalance_sender() const;
    void setBalance_receiver(double balance_receiver);
    double getBalance_receiver() const;
    void setTransactionQuantifier(int transaction_quantifier);
    int getTransactionQuantifier() const;
    
    void deposit_transaction();
    void booty_transaction();
    bool balance_verify();
    virtual ~Transaction();

private:
    double balance_sender; // remetente(aquele que envia);
    double balance_receiver; // receptor(aquele que recebe);
    int transaction_quantifier;
};

#endif /* TRANSACTION_H */

