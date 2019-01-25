#include "player.h"
#include<string>
#include <fstream>
#include <cstdlib>
#include<iostream>
using namespace std;
player::player(int i,string n,string p,int j,int m,int a,int g,int el)
{
id=i;
nom=n;
prenom=p;
jour=j;
mois=m;
an=a;
group=g;
elimine=el;
}
player::~player()
{
}
void player::setdate(int j,int m,int a)
{
jour=j;
mois=m;
an=a;
}
void player::afficher()
{
cout<<"joueur numero :"<<id<<endl<<"nom :"<<nom<<endl<<"prenom :"<<prenom<<endl<<"date de naissance :"<<jour<<"/"<<mois<<"/"<<an<<endl<<"groupe :"<<group<<endl;
if (elimine==1)
cout<<"participant elimine"<<endl;
}

ostream& operator<<(ostream& out,player p)
{
    if (p.elimine==1)
        out<<p.nom<<"   "<<p.prenom<<"   joueur eliminé"<<endl;
    else
        out<<p.nom<<"   "<<p.prenom<<endl;
    return out;
}
ofstream& operator<<(ofstream& out,player p)
{
out<<p.id<<" "<<p.nom<<" "<<p.prenom<<" "<<p.jour<<" "<<p.mois<<" "<<p.an<<" "<<p.group<<" "<<p.elimine<<endl;
return out;
}
