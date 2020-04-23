#include "FamilyTree.hpp"


using namespace family;

bool Tree::addFather(string Child, string Father)
{

    //Check if child node exist ,  and father node doesn't
    if(this->nodeExist(Child) && !this->nodeExist(Father))
    {

        int father_id = (this->getNode(Child)->_id)*2+1; // Father ID = (son ID)*2 +1
        Fnode* father = new Fnode(Father,father_id);
        //cout<<"AddFT father"<<father<<endl;
        if(this->getNode(Child)->setFather(father)) {//if this is true, so this node is added as childs father
           // cout<<"it seems father was added to child"<<endl;
            _Fmap[Father] = father;
            return true;
        }
        else
        {
            return false;
        }

    }
    else{
       cerr << "Error message 1  bad name";

       return false;
    }
    return false;
}

bool Tree::addMother(string Child, string Mother)
{
    //Check if child node exist ,  and mother node doesn't
    if(this->nodeExist(Child) && !this->nodeExist(Mother))
    {

        int mother_id = (this->getNode(Child)->_id)*2; // Mother ID = (son ID)*2
        Fnode* mother = new Fnode(Mother,mother_id);

        if(this->getNode(Child)->setMother(mother)) {//if this is true, so this node is added as childs mother
           // cout<<"it seems mother was added to child"<<endl;
            _Fmap[Mother] = mother;
            return true;
        }
        else
        {
            return false;
        }

    }
    else{
        cerr << "Error message 1  bad name";

        return false;
    }
    return false;
}


string Tree::relation(string name)
{
    if(this->nodeExist(name))//If this relative exist
    {
        int rel_id = this->getNode(name)->_id;//retrive ID from relative
        if(rel_id == 1){return "me";}// Is it me?
        string ans = "";
        if (rel_id % 2 == 0)
            // if its female
            ans = ans+"mother";
        else // Its a male
            ans = ans+"father";
        rel_id = rel_id/2;
        if(rel_id == 1){return ans;}
        else{
            rel_id = rel_id/2;
            ans = "grand"+ans;
        }
        while(rel_id != 1)
        {
            ans = "grate-"+ans;
            rel_id = rel_id/2;
        }
        return ans;

        return "I like the way u die boy";
    }
    else
        return "unrelated";
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
Fnode* Tree::getNode_imp(string name)
{
    //return _Fmap.at(name);
return nullptr;
}
Fnode* Tree::getNode(string name)
{
    if(nodeExist(name))
    {
        return _Fmap[name];
    }
    else
    {
        cerr<<"no shuch node";
        return nullptr;
    }
}

bool Tree::nodeExist(string name)
{
    return _Fmap.find(name) != _Fmap.end();
}
int main()
{
    family::Tree T = Tree("Yosef");
    T.addFather("Yosef","Yaakov");
    T.addMother("Yosef","Rachel");
    T.addFather("Yaakov","Isaac");
    T.addMother("Yaakov","Rivka");
    T.addFather("Isaac","Avraham");
    T.addFather("Avraham","Terah");

    cout<< T.relation("Yaakov")<<endl;
    cout<< T.relation("Rachel")<<endl;
    cout<< T.relation("Rivka")<<endl;
    cout<< T.relation("Avraham")<<endl;
    cout<< T.relation("Terah")<<endl;
    cout<< T.relation("xyz")<<endl;
    cout<< T.relation("Yosef")<<endl;


    return 0;
}