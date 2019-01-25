#include "game.h"
#include "player.h"
#include<fstream>
#include<string>
#include<windows.h>
#include<time.h>
#include<cstdlib>
#include<iostream>
using namespace std;
game::game()
{
places=0;
for(int i=0;i<8;i++)
alea[i]=4;
for(int j=0;j<8;j++)
nbelim[j]=4;
}
void game::ajouter()
{
if(places!=32)
{
bool test=true;
string n,p;
int j,m,a,r;
cout<<"saisir le nom du participant à ajouter"<<endl;
cin>>n;
cout<<"saisir le prenom du participant à ajouter"<<endl;
cin>>p;
cout<<"saisir la date de naissance du participant à ajouter(jour mois annee)"<<endl;

cin>>j;
cin>>m;
cin>>a;
r=random();
player pl(places+1,n,p,j,m,a,r);
tab[places]=pl;
places=places+1;
alea[r-1]=alea[r-1]-1;
system("cls");
cout<<"joueur bien ajouté"<<endl;
}
else
{
system("cls");
cout<<"liste pleine"<<endl;
}
}
void game::retirer(int ind)
{
int g;
g=tab[ind-1].getgroup();
if(ind<=places)
{
for(int i=ind;i<places;i++)
{
tab[i].recul();
tab[i-1]=tab[i];
}
places=places-1;
alea[g-1]=alea[g-1]+1;
system("cls");
cout<<"joueur retire"<<endl;
}
else
{
system("cls");
cout<<"indice inexistant"<<endl;
}
}
void game::modifier(int ind)
{
string n,p;
int j,m,a;
if(ind<=places)
{
cout<<"saisir le nouveau nom du participant :"<<ind<<endl;
cin>>n;
tab[ind-1].setnom(n);
cout<<"saisir le nouveau prenom du participant"<<endl;
cin>>p;
tab[ind-1].setprenom(p);
cout<<"saisir la nouvelle date de naissance du participant(jj mm aaaa)"<<endl;
cin>>j>>m>>a;
tab[ind-1].setdate(j,m,a);
system("cls");
cout<<"joueur change"<<endl;
}
else
{
system("cls");
cout<<"indice inexistant"<<endl;
}
}
int game::random()
{
int r;
srand (time(NULL));
do
{
r=rand()%8;
}while(alea[r]==0);
return(r+1);
}
void game::affichage()
{
for(int i=0;i<places;i++)
{
tab[i].afficher();
cout<<"**************************"<<endl;
}
}
void game::enregistrer()
{
ofstream file1("players.txt",ios::trunc);
for(int i=0;i<32;i++)
file1<<tab[i];
file1<<places<<endl;
file1.close();
ofstream file2("groups.txt",ios::trunc);
for(int j=0;j<8;j++)
file2<<alea[j]<<endl;
file2.close();
ofstream file5("elim.txt",ios::trunc);
for(int k=0;k<8;k++)
file5<<nbelim[k]<<endl;
file5.close();
}
void game::charger()
{
string n,p,l,k;
int id,j,m,a,r,g,e,el;
ifstream file3("players.txt",ios::in);
if(!file3)
cout<<"fichier non chargé"<<endl;
for(int i=0;i<32;i++)
{
    file3>>id>>n>>p>>j>>m>>a>>r>>el;
    player pl(id,n,p,j,m,a,r,el);
    tab[i]=pl;
    getline(file3,l);
}
file3>>places;
file3.close();
ifstream file4("groups.txt",ios::in);
for(int j=0;j<8;j++)
{
    file4>>g;
    alea[j]=g;
    getline(file4,k);
}
file4.close();
ifstream file6("elim.txt",ios::in);
for(int b=0;b<8;b++)
{
    file6>>e;
    nbelim[b]=e;
    getline(file6,k);
}
file6.close();
}
void game::reinitialiser()
{
places=0;
for(int i=0;i<8;i++)
{alea[i]=4;
nbelim[i]=4;}
system("cls");
cout<<"programme reinitialisé"<<endl;
}

void game::affichagegrp()
{
for(int i=0;i<8;i++)
{
    for(int j=0;j<places;j++)
    if(tab[j].getgroup()==i+1)
    tab[j].afficher();
    cout<<"***********************"<<endl;
}
}
void game::eliminer(int i,int b,tournoi &tour)
{
system("cls");
if(b==1)
{
if(nbelim[tab[i-1].getgroup()-1]==2)
cout<<"deux joueurs sonts deja eliminés"<<endl;
else if(tab[i-1].getelimin()==1)
cout<<"joueur deja eliminé"<<endl;
else if((i>0)&&(i<33))
{
    tab[i-1].eliminer();
    nbelim[tab[i-1].getgroup()-1]=nbelim[tab[i-1].getgroup()-1]-1;
    tour.elimine();
    cout<<"joueur eliminé"<<endl;
}
}
else if(b==2)
{
if(tab[i-1].getelimin()==1)
cout<<"joueur deja eliminé"<<endl;
else if((i>0)&&(i<33))
    {tab[i-1].eliminer();
    nbelim[tab[i-1].getgroup()-1]=nbelim[tab[i-1].getgroup()-1]-1;
    tour.elimine();
    cout<<"joueur eliminé"<<endl;}
}
}

void game::affichernom(int g)
{
    for(int i=0;i<32;i++)
        if((tab[i].getgroup()==g)&&(tab[i].getelimin()==0))
        cout<<tab[i];
}
void game::affichernom2(int i)
{
    cout<<"joueur"<<i+1<<"  ";
    cout<<tab[i];
}
