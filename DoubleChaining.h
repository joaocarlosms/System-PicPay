
/* 
 * File:   DoubleChaining.h
 * Author: Admin
 *
 * Created on 17 de agosto de 2023, 13:11
 */
#include "PicPay.h"
#include "Nodo.h"
#include <iostream>

using namespace std;

#ifndef DOUBLECHAINING_H
#define DOUBLECHAINING_H

class DoubleChaining {
public:
    DoubleChaining();
    DoubleChaining(Nodo* head, int quant);
    DoubleChaining(const DoubleChaining& orig);
    void setHead(Nodo* head);
    Nodo* getHead() const;
    void setQuant(int quant);
    int getQuant() const;
    
    void insert();
    void fill();
    void remove();
    Nodo* getElement(int position);
    Nodo* find(const string& cpf_wanted, const string& email_wanted);
    void insert(int position);
    void remove(int position);
    bool isEmpty();
    void print();
    int verify_user_type();
    virtual ~DoubleChaining();

private:
    Nodo* head;
    int quant;
};

#endif /* DOUBLECHAINING_H */

