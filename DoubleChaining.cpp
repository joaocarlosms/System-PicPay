
/* 
 * File:   DoubleChaining.cpp
 * Author: Admin
 * 
 * Created on 17 de agosto de 2023, 13:11
 */

#include "DoubleChaining.h"

DoubleChaining::DoubleChaining(){
    this->head = NULL;
    this->quant = 0;
}

DoubleChaining::DoubleChaining(Nodo* head, int quant){
    this->head = head;
    this->quant = quant;
}

DoubleChaining::DoubleChaining(const DoubleChaining& orig){
    this->head = orig.getHead();
    this->quant = orig.getQuant();
}

void DoubleChaining::setHead(Nodo* head){
    this->head = head;
}

Nodo* DoubleChaining::getHead() const{
    return head;
}

void DoubleChaining::setQuant(int quant){
    this->quant = quant;
}

int DoubleChaining::getQuant() const{
    return quant;
}

void DoubleChaining::insert(){
    PicPay user;
    user.fillData();
    
    string cpf_wanted,email_wanted;
    Nodo* verify_user = find(cpf_wanted, email_wanted);
    if(verify_user == NULL){
        Nodo* novo = new Nodo();
        novo->setItem(user);
        
        if(quant == 0){
            head = novo;
        }else{
            novo->setProx(head);
            head->setAnt(novo);
        }
    } 
    quant++;
    cout << "USER REGISTER WITH SUCCESSLY!\n";
}

void DoubleChaining::fill(){
    int numUsers;
    do{
       cout << "ENTER THE TOTAL NUMBER OF USERS: ";
       cin >> numUsers; 
    }while(numUsers < 0);
    
    for(int i = 0; i < numUsers; i++){
        cout << "USER # " << i+1 << endl;
        this->insert();
    }
}

void DoubleChaining::remove(){
    if(quant > 0){
        if(quant == 1){
            head = head->getProx(); // ele passa a apontar para o proximo nó, excluindo o primeiro;
        }else{
            head = head->getProx();
            head->setAnt(NULL);
        }
        quant--;
    }else{
        cout << "Operation invalid! Amount is empty\n";
    }
}

Nodo* DoubleChaining::getElement(int position){
    Nodo* p = head;
    int j = 1;
    
    while(j <= position-1 && p->getProx() != NULL){
        p = p->getProx();
        j++;
    }
    if(j == position){
        return p;
    }else{
        return NULL;
    }
}

Nodo* DoubleChaining::find(const string& cpf_wanted, const string& email_wanted){ 
    for(Nodo* p = head; p != NULL; p = p->getProx()){
        const string& cpf_element = p->getItem().getCpf(); //strings temporarias para comparar com os itens passados por parametro
        const string& email_element = p->getItem().getEmail(); //strings temporarias para comparar com os itens passados por parametro
        
        if(cpf_element == cpf_wanted || email_element == email_wanted){
            return p;
        }
    }
    return NULL; // Fora do loop, caso nenhum elemento corresponda.
}



void DoubleChaining::insert(int position){
    if(position >= 1 && position <= quant+1){
        PicPay user;
        user.fillData();
        
        string cpf_wanted,email_wanted;
        Nodo* verify_user = find(cpf_wanted, email_wanted);
        if(verify_user == NULL){
            Nodo* novo = new Nodo();
            novo->setItem(user);
            
            if(position == 1){ //adicionar elemento na primeira posicao;
                this->insert();
            }else if(position == quant+1){ //adicionar elemento na ultima posicao;
                Nodo* last = this->getElement(position-1);
                last->setProx(novo);
                novo->setProx(NULL);
                novo->setAnt(last);
            }else{ // adicionar elemento no meio da lista;
                Nodo* element = this->getElement(position);
                Nodo* previous = element->getAnt();
                novo->setProx(element);
                novo->setAnt(previous);
                previous->setProx(novo);
                element->setAnt(novo);
            }
            quant++;
        }else{
            cout << "Invalid Operation! User already has registration\n"; 
        }  
    }else{
        cout << "ERROR! Invalid Position\n";
    }
}

void DoubleChaining::remove(int position){
    if(position >= 1 && position <= quant){
        if(position == 1){
            this->remove();
        }else if(position == quant){
            Nodo* last = this->getElement(position);
            Nodo* previous = last->getAnt();
            last->setAnt(NULL);
            previous->setProx(NULL);
            
            quant--;
        }else{
            Nodo* element = this->getElement(position);
            Nodo* previous = element->getAnt();
            Nodo* successor = element->getProx();
            previous->setProx(successor);
            successor->setAnt(previous);
            element->setProx(NULL);
            element->setAnt(NULL);
            
            quant--;
        }
    }else{
        cout << "ERROR! Invalid position\n";
    }
}

bool DoubleChaining::isEmpty(){ // verificar se a lista esta vazia;
    if(quant == 0){
        return true;
    }else{
        return false;
    }
}

void DoubleChaining::print(){
    if(!isEmpty()){
        Nodo* p = head;
        while(p != NULL){ // percorrer nó por nó, imprimindo os dados resumidos;
            p->getItem().abbreviationPrint();
            p = p->getProx();
        }
    }
}

int DoubleChaining::verify_user_type(){
    int opc;
    do{
        cout << "---------CHOICE THE OPTION FOR USER TYPE---------\n";
        cout << "1- SHOPKEEPER\n";
        cout << "2- COMMON USER\n";
        cout << "-------------------------------------------------\n";
        cin >> opc;
    }while(opc != 1 && opc != 2);
    
    return opc;
}

DoubleChaining::~DoubleChaining(){
}

