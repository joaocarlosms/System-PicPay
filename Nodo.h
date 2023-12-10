
/* 
 * File:   Nodo.h
 * Author: Admin
 *
 * Created on 17 de agosto de 2023, 09:15
 */
#include "PicPay.h"
#include <iostream>

using namespace std;

#ifndef NODO_H
#define NODO_H

class Nodo {
public:
    Nodo();
    Nodo(PicPay item, Nodo* ant, Nodo* prox);
    Nodo(const Nodo& orig);
    void setItem(PicPay item);
    PicPay getItem() const;
    void setAnt(Nodo* ant);
    Nodo* getAnt() const;
    void setProx(Nodo* prox);
    Nodo* getProx() const;
    virtual ~Nodo();

private:
    PicPay item;
    Nodo* ant;
    Nodo* prox;
};

#endif /* NODO_H */

