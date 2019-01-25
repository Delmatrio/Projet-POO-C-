#pragma once
#include<windows.h>
#include"match.h"
class finales
{
    public:
        finales();
        void initialiser(class game);
        void consulter(class tournoi,class game);
        void modifierdate(int,class tournoi);
        void modifierprix(int,class tournoi);
        void modifierplaces(int,class tournoi);
        void reserver(int,class tournoi);
        void save();
        void verif(class game,class tournoi);
        void charge();
        virtual ~finales();
    private:
        finale tabf[16];
};
void gotoxy(int,int);
