#include "FamilyTree.hpp"


using namespace family;

bool Tree::addFather(string Child, string Father)
{
    //Check if child node exist ,  and father node doesn't
    if(this->nodeExist(Child) && !this->nodeExist(Father))
    {
       // Fnode child = this->getNode(Child); // this is child node in the map
        int father_id = (this->getNode(Child)._id)*2+1; // Father ID = (son ID)*2 +1
        Fnode* father = new Fnode(Father,father_id);
        if(this->getNode(Child).setFather(father)) {//if this is true, so this node is added as childs father
            cout<<"it seems father was added to child"<<endl;
            _Fmap[Father] = *father;
            return true;
        }
        else
        {
            return false;
        }

    }
    else{
       cerr << "Error message 1  bad name";
       cout << "Error message 2 bad name";
       return false;
    }
    return false;
}

bool Tree::addMother(string nameChild, string nameMother)
{
    return true;
}


string Tree::relation(string name)
{
    return "incest";
}

string Tree:: find(string name)
{
    return "I like the way u die boy";
}

void Tree:: display()
{

}

void Tree:: remove(string name)
{

}
//Returns the Fnode the root is pointing at.
Fnode Tree::getRoot()
{
    return *_root;
}
//Return the node which key is "name" if no such node exist trows ast::out_of_range Error
Fnode Tree::getNode(string name)
{
    return _Fmap.at(name);
}
bool Tree::nodeExist(string name)
{
    try{ getNode(name);}
    catch(out_of_range&){return false;}
    return true;

}
int main()
{
    family::Tree T = Tree("jhon");
    cout<<T._Fmap.size()<<endl;
    //cout<<T.getNode("jhon").myFather()<<endl;
    T.addFather("jhon","jhons father");
    cout<<T._Fmap.size()<<endl;
    T.addFather("jhons father","grand father");
    cout<<T._Fmap.size()<<endl;


    return 0;
}