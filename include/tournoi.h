#pragma once
#include"game.h"
#include"match.h"
#include<iostream>
using namespace std;
class tournoi
{
    public:
        tournoi();
        void saisir();
        void afficherparties(class game);
        void modifierdate(int);
        void modifierprix(int);
        void modifierplaces(int);
        void reserver(int);
        void save();
        void charge();
        void elimine(){elimin=elimin+1;};
        int getelimin(){return elimin;};
        virtual ~tournoi();
    private:
        qualif tabq[8];
        int elimin;
};
