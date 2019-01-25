#pragma once
#include"player.h"
#include"tournoi.h"
#include"match.h"
class game
{
    public:
        game();
        void ajouter();
        void retirer(int);
        void modifier(int);
        void eliminer(int,int,class tournoi&);
        void affichage();
        void affichernom(int);
        void affichernom2(int);
        void affichagegrp();
        int random();
        void enregistrer();
        void charger();
        void reinitialiser();
        int getelim(int i){return tab[i].getelimin();}
        int getplaces(){return places;}
    private:
        player tab[32];
        int alea[8];
        int nbelim[8];
        int places;
};
