#include"match.h"
#include"finales.h"
#include"game.h"
#include"tournoi.h"
#include<iostream>
#include<windows.h>
#include<fstream>
using namespace std;
void gotoxy(int x,int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
finales::finales()
{
}

finales::~finales()
{
}
void finales::initialiser(game g)
{
    int pl,j;
    float pr;
    cout<<"saisir le prix d'un billet des huitiemes"<<endl;
    cin>>pr;
    cout<<"saisir le nbr de places disponibles"<<endl;
    cin>>pl;
    int q=32;
    int r;
    for(int i=0;i<8;i++)
        {
        tabf[i].setprix(pr);
        tabf[i].setplaces(pl);
        tabf[i].settype("huitieme");
        tabf[i].setdate("12/12/2012");
        for(j=0;j<q;j++)
        {
            if(g.getelim(j)==0)
            r=j+1;
            tabf[i].setjoueur1(r);
        }
        q=r-1;
        for(j=0;j<q;j++)
        {
            if(g.getelim(j)==0)
            r=j+1;
            tabf[i].setjoueur2(r);
        }
        q=r-1;
        }
    cout<<"saisir le prix d'un billet des quart finales"<<endl;
    cin>>pr;
    cout<<"saisir le nbr de places disponibles"<<endl;
    cin>>pl;
    for (int k=8;k<12;k++)
        {
        tabf[k].setprix(pr);
        tabf[k].setplaces(pl);
        tabf[k].settype("quart_finales");
        tabf[k].setdate("12/12/2012");
        }
    cout<<"saisir le prix d'un billet des demi finales"<<endl;
    cin>>pr;
    cout<<"saisir le nbr de places disponibles"<<endl;
    cin>>pl;
    for (int l=12;l<14;l++)
        {
        tabf[l].setprix(pr);
        tabf[l].setplaces(pl);
        tabf[l].settype("demi_finales");
        tabf[l].setdate("12/12/2012");
        }
    cout<<"saisir le prix d'un billet du finale"<<endl;
    cin>>pr;
    cout<<"saisir le nbr de places disponibles"<<endl;
    cin>>pl;
        tabf[14].setprix(pr);
        tabf[14].setplaces(pl);
        tabf[14].settype("finale");
        tabf[14].setdate("12/12/2012");
    cout<<"saisir le prix d'un billet de la 3eme place"<<endl;
    cin>>pr;
    cout<<"saisir le nbr de places disponibles"<<endl;
    cin>>pl;
        tabf[15].setprix(pr);
        tabf[15].setplaces(pl);
        tabf[15].settype("3eme place");
        tabf[15].setdate("12/12/2012");

}
void finales::consulter(tournoi tour,game g)
{
if (tour.getelimin()<24)
{
    system("cls");
    cout<<"**les parties huitiemes**"<<endl;
    for(int i=0;i<8;i++)
    {
        cout<<"partie :"<<i+1<<endl;
        tabf[i].afficher();
        cout<<"joueurs participants"<<endl;
        g.affichernom2(tabf[i].getjoueur1()-1);
        g.affichernom2(tabf[i].getjoueur2()-1);
        cout<<endl;
    }
}
else if((tour.getelimin()<28)&&(tour.getelimin()>23))
{
    system("cls");
    cout<<"**les parties quart finales**"<<endl;
    for(int j=8;j<12;j++)
    {
        cout<<"partie :"<<j-7<<endl;
        tabf[j].afficher();
        cout<<"joueurs participants"<<endl;
        g.affichernom2(tabf[j].getjoueur1()-1);
        g.affichernom2(tabf[j].getjoueur2()-1);
        cout<<endl;
    }
}
else if((tour.getelimin()<30)&&(tour.getelimin()>27))
{
    system("cls");
    cout<<"**les parties demi finales**"<<endl;
    for(int k=12;k<14;k++)
    {
        cout<<"partie :"<<k-11<<endl;
        tabf[k].afficher();
        cout<<"joueurs participants"<<endl;
        g.affichernom2(tabf[k].getjoueur1()-1);
        g.affichernom2(tabf[k].getjoueur2()-1);
        cout<<endl;
    }
}
else
{
    system("cls");
    cout<<"****la partie finale****"<<endl;
    tabf[14].afficher();
    cout<<"joueurs participants"<<endl;
    g.affichernom2(tabf[14].getjoueur1()-1);
    g.affichernom2(tabf[14].getjoueur2()-1);
    cout<<endl;
}
}
void finales::save()
{
    ofstream file11("final.txt",ios::trunc);
    for(int i=0;i<16;i++)
    file11<<tabf[i];
    file11.close();
}

void finales::charge()
{
    float p;
    int plt,plr,j1,j2;
    string t,d,l;
        ifstream file12("final.txt",ios::in);
        for(int i=0;i<16;i++)
        {
            file12>>t>>p>>plt>>plr>>d>>j1>>j2;
            finale f(t,p,plr,plt,d,j1,j2);
            tabf[i]=f;
            getline(file12,l);
        }
        file12.close();
}

void finales::modifierdate(int i,tournoi tour)
{
    int k;
    k=i;
    if((tour.getelimin()<28)&&(tour.getelimin()>23))
    k=i+8;
    if((tour.getelimin()<30)&&(tour.getelimin()>27))
    k=i+12;
    if(tour.getelimin()==30)
    k=i+14;
    string s;
    system("cls");
    cout<<"saisir la nouvelle date jj/mm/aaaa"<<endl;
    cin>>s;
    tabf[k].setdate(s);
}
void finales::modifierprix(int i,tournoi tour)
{
    int k;
    k=i;
    if((tour.getelimin()<28)&&(tour.getelimin()>23))
    k=i+8;
    if((tour.getelimin()<30)&&(tour.getelimin()>27))
    k=i+12;
    if(tour.getelimin()==30)
    k=i+14;
    float p;
    system("cls");
    cout<<"saisir le nouveau prix"<<endl;
    cin>>p;
    tabf[k].setprix(p);
}
void finales::modifierplaces(int i,tournoi tour)
{
    int k;
    k=i;
    if((tour.getelimin()<28)&&(tour.getelimin()>23))
    k=i+8;
    if((tour.getelimin()<30)&&(tour.getelimin()>27))
    k=i+12;
    if(tour.getelimin()==30)
    k=i+14;
    int p;
    system("cls");
    cout<<"saisir le nombre de places a ajouter"<<endl;
    cin>>p;
    tabf[k].ajoutplaces(p);
}

void finales::reserver(int i,tournoi tour)
{
    int k;
    k=i;
    if((tour.getelimin()<28)&&(tour.getelimin()>23))
    k=i+8;
    if((tour.getelimin()<30)&&(tour.getelimin()>27))
    k=i+12;
    if(tour.getelimin()==30)
    k=i+14;
    bool b;
    int pl;
    cout<<"saisir le nombre de places a reserver"<<endl;
    cin>>pl;
    b=tabf[k].retirerplaces(pl);
    if(b==false)
    cout<<"places non disponibles"<<endl;
    else
    {
        cout<<"vous avez reservé "<<pl<<" places"<<endl;
        cout<<"montant a payer :"<<pl*tabf[k].getprix()<<endl;
    }
}
void finales::verif(game g,tournoi tour)
{
    int q=32;
    int i,r,j;
    if (tour.getelimin()==24)
    {
    for(i=8;i<12;i++)
        {
        for(j=0;j<q;j++)
        {
            if(g.getelim(j)==0)
            r=j+1;
            tabf[i].setjoueur1(r);
        }
        q=r-1;
        for(j=0;j<q;j++)
        {
            if(g.getelim(j)==0)
            r=j+1;
            tabf[i].setjoueur2(r);
        }
        q=r-1;
        }
    }
    if (tour.getelimin()==28)
    {
    for(i=12;i<14;i++)
        {
        for(j=0;j<q;j++)
        {
            if(g.getelim(j)==0)
            r=j+1;
            tabf[i].setjoueur1(r);
        }
        q=r-1;
        for(j=0;j<q;j++)
        {
            if(g.getelim(j)==0)
            r=j+1;
            tabf[i].setjoueur2(r);
        }
        q=r-1;
        }
    }
    if (tour.getelimin()==30)
    {
    for(j=0;j<q;j++)
    {
        if(g.getelim(j)==0)
        r=j+1;
        tabf[14].setjoueur1(r);
    }
    q=r-1;
    for(j=0;j<q;j++)
    {
        if(g.getelim(j)==0)
        r=j+1;
        tabf[14].setjoueur2(r);
    }
    q=r-1;
    }
}

