#pragma once
#include<string>
using namespace std;
class player
{
    public:
        player(int=0,string=" ",string=" ",int=0,int=0,int=0,int=0,int=0); //constructeur par defaut
        void setnom(string n){nom=n;}; // setteur du nom
        void setprenom(string p){prenom=p;}; // setteur de prenom
        void setdate(int,int,int); // setteur de la date de naissance d1 joueur
        int getgroup(){return group;}; // donner le numero
        void afficher();
        friend ostream& operator<<(ostream& out,player p);
        friend ofstream& operator<<(ofstream& out,player p);
        void recul(){id=id-1;};
        void eliminer(){elimine=1;}
        int getelimin(){return elimine;}
        virtual ~player();
    private:
        int id;
        string nom;
        string prenom;
        int jour,mois,an;
        int group;
        int elimine;
};
