//
// Created by roie on 21/04/2020.
//
#include "Fnode.hpp"

bool Fnode::setFather(Fnode* Father)
{
    if(this->_father == NULL) {
        this->_father = Father;
        return true;
    }
    else
    {
        return false;
    }
}
bool Fnode::setMother(Fnode* Mother)
{
    if(this->_mother == NULL) {
        this->_mother = Mother;
        return true;
    }
    else
    {
        return false;
    }
}

int Fnode::getID()
{
    return this->_id;
}





