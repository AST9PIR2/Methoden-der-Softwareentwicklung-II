//
// Created by Pirmin on 21.05.2022.
//

#ifndef KLAUSUR_PRODUCT_H
#define KLAUSUR_PRODUCT_H

#include <iostream>

class Product {
protected:
    int type;

public:

    Product(int type) : type(type){
    }

    virtual ~Product() = default;

    int getType();

};

class ProductA : public Product {

public:
    ProductA() : Product(1) {
    }

    ~ProductA() {
        std::cout << " Destroying Product A " << std::endl;

    }
};

class ProductB : public Product {

public:
    ProductB():Product(2){
    }

    ~ProductB() {
        std::cout << " Destroying Product B " << std::endl;
    }
};

#endif //KLAUSUR_PRODUCT_H
