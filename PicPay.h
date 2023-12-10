
/* 
 * File:   PicPay.h
 * Author: Admin
 *
 * Created on 17 de agosto de 2023, 08:01
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

#ifndef PICPAY_H
#define PICPAY_H

class PicPay{
public:
    PicPay();
    PicPay(string completeName, string cpf, string email, string password, double balance);
    PicPay(const PicPay& orig);
    void setCompleteName(std::string completeName);
    std::string getCompleteName() const;
    void setCpf(std::string cpf);
    std::string getCpf() const;
    void setEmail(std::string email);
    std::string getEmail() const;
    void setPassword(std::string password);
    std::string getPassword() const;
    void setBalance(double balance);
    double getBalance() const;
    
    void save_in_file();
    void fillData();
    void printData();
    void copy(PicPay& other);
    void abbreviationPrint() const;
    void options_menu();
    void options_transaction();
    virtual ~PicPay();

private:
    std::string completeName;
    std::string cpf;
    std::string email;
    std::string password;
    double balance;
};

#endif /* PICPAY_H */

