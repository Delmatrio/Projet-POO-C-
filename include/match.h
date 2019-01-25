#pragma once
#include<string>
#include<iostream>
using namespace std;
class match
{
    public:
        match(string=" ",float=0,int=0,int=0,string=" ");
        void ajoutplaces(int pl){places_tot=places_tot+pl;};
        void setplaces(int pl){places_tot=pl;places_res=0;};
        void setprix(float pr){prix=pr;};
        float getprix(){return prix;};
        void setdate(string d){date=d;};
        void settype(string t){type=t;};
        bool retirerplaces(int);
        void reserver();
        void affichernom();
        void afficher();
        virtual ~match(){};
    protected:
        string type;
        float prix;
        int places_res;
        int places_tot;
        string date;
};
class qualif:public match
{
    public:
        qualif(string t=" ",float p=0,int pr=0,int pt=0,string d=" ",int g=0):match(t,p,pr,pt,d){groupe=g;};
        virtual ~qualif(){};
        void setgrp(int g){groupe=g;};
        friend ofstream& operator<<(ofstream& out,qualif q);
    private:
        int groupe;
};
class finale:public match
{
    public:
        finale(string t=" ",float p=0,int pr=0,int pt=0,string d=" ",int j1=0,int j2=0):match(t,p,pr,pt,d){joueur1=j1;joueur2=j2;};
        virtual ~finale(){};
        void setjoueur1(int a){joueur1=a;}
        void setjoueur2(int a){joueur2=a;}
        int getjoueur1(){return joueur1;}
        int getjoueur2(){return joueur2;}
        friend ofstream& operator<<(ofstream& out,finale f);
    private:
        int joueur1;
        int joueur2;
};
