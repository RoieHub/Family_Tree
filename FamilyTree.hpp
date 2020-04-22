#pragma once
#include <stdbool.h>
#include <iostream>
#include <string>
#include <map>
#include "Fnode.hpp"
using namespace std;
namespace family {

    class Tree {
    public:
        Fnode _root;
        std::map<std::string,Fnode> _Fmap;

        Tree()
        {
            this->_root = new Fnode("Me");
        }
        Tree(string name)
        {
            //cout << name << endl;//For debugging
            Fnode root = Fnode(name);
            //_Fmap[name] = Tree(string name);
        }
        bool addFather(string child, string father);

        bool addMother(string child, string mother);

        string relation(string name);

        string find(string name);

        void display();

        void remove(string name);

    };
}
