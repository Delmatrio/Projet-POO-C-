#include"match.h"
#include"tournoi.h"
#include"game.h"
#include<time.h>
#include<windows.h>
#include<fstream>
#include<string>
#include<iostream>
using namespace std;

tournoi::tournoi()
{
    for (int i=0;i<8;i++)
    {
        tabq[i].setgrp(i+1);
    }
}
void tournoi::saisir()
{
    int pl;
    float pr;
    cout<<"saisir le prix d'un billet"<<endl;
    cin>>pr;
    cout<<"saisir le nbr de places disponibles"<<endl;
    cin>>pl;
    for (int i=0;i<8;i++)
        {
        tabq[i].setprix(pr);
        tabq[i].setplaces(pl);
        tabq[i].settype("qualificatif");
        tabq[i].setdate("12/12/2012");
        tabq[i].setgrp(i+1);
        }
    elimin=0;
}
tournoi::~tournoi()
{
    //dtor
}
void tournoi::afficherparties(game g)
{
system("cls");
{
    cout<<"**les parties qualificatives**"<<endl;
    for(int i=0;i<8;i++)
    {
        cout<<"jour :"<<i+1<<endl;
        tabq[i].afficher();
        cout<<"liste des joueurs"<<endl;
        g.affichernom(i+1);
        cout<<endl;
    }
}

}
void tournoi::modifierdate(int i)
{
    string s;
    system("cls");
    cout<<"saisir la nouvelle date jj/mm/aaaa"<<endl;
    cin>>s;
    tabq[i].setdate(s);
}
void tournoi::modifierprix(int i)
{
    float p;
    system("cls");
    cout<<"saisir le nouveau prix"<<endl;
    cin>>p;
    tabq[i].setprix(p);
}
void tournoi::modifierplaces(int i)
{
    int p;
    system("cls");
    cout<<"saisir le nombre de places a ajouter"<<endl;
    cin>>p;
    tabq[i].ajoutplaces(p);
}
void tournoi::save()
{
    ofstream file8("tournoi.txt",ios::trunc);
    for(int i=0;i<8;i++)
    file8<<tabq[i];
    file8<<elimin;
    file8.close();
}
void tournoi::charge()
{
    float p;
    int plt,plr,g;
    string t,d,l;
        ifstream file9("tournoi.txt",ios::in);
        for(int i=0;i<8;i++)
        {
            file9>>t>>p>>plt>>plr>>d>>g;
            qualif q(t,p,plr,plt,d,g);
            tabq[i]=q;
            getline(file9,l);
        }
        file9>>elimin;
        file9.close();
}
void tournoi::reserver(int i)
{
    bool b;
    int pl;
    cout<<"saisir le nombre de places a reserver"<<endl;
    cin>>pl;
    b=tabq[i].retirerplaces(pl);
    if(b==false)
    cout<<"places non disponibles"<<endl;
    else
    {
        cout<<"vous avez reservé "<<pl<<" places"<<endl;
        cout<<"montant a payer :"<<pl*tabq[i].getprix()<<endl;
    }
}

