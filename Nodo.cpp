
/* 
 * File:   Nodo.cpp
 * Author: Admin
 * 
 * Created on 17 de agosto de 2023, 09:15
 */
#include "Nodo.h"

Nodo::Nodo(){
    this->ant = NULL;
    this->prox = NULL;
}

Nodo::Nodo(PicPay item, Nodo* ant, Nodo* prox){
    this->item = item;
    this->ant = ant;
    this->prox = prox;
}

Nodo::Nodo(const Nodo& orig){
    this->item = orig.getItem();
    this->ant = orig.getAnt();
    this->prox = orig.getProx();
}

void Nodo::setItem(PicPay item){
    this->item = item;
}

PicPay Nodo::getItem() const{
    return item;
}

void Nodo::setAnt(Nodo* ant){
    this->ant = ant;
}

Nodo* Nodo::getAnt() const{
    return ant;
}

void Nodo::setProx(Nodo* prox){
    this->prox = prox;
}

Nodo* Nodo::getProx() const{
    return prox;
}

Nodo::~Nodo(){
}

