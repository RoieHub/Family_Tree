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
        Fnode* _root;
        std::map<std::string,Fnode*> _Fmap;

        Tree()
        {
            _root = new Fnode("Me");
            _Fmap[_root->_name] = _root; // _root* is the Fnode _root is pointing at.
        }
        Tree(string name)
        {
            //cout << name << endl;//For debugging
            _root = new Fnode(name);
            _Fmap[name] = _root;
        }
        bool addFather(string child, string father);
        //Returns true there is a key mapped to this name, else no such key exist return false
        bool nodeExist(string name);
        bool addMother(string child, string mother);

        string relation(string name);

        string find(string name);

        void display();

        void remove(string name);

        //Return the node which key is "name" if no such node exist trows ast::out_of_range Error.
        Fnode* getNode(string name);
        Fnode* getNode_imp(string);

        //Fnode getNode(int id);

        //Returns the Fnode the root is pointing at.
        Fnode getRoot();

    };
}
