#include <iostream>
#include <fstream>
#include<string>
#include<windows.h>
#include "game.h"
#include"player.h"
#include"match.h"
#include"tournoi.h"
#include"finales.h"
using namespace std;

void etat_jeu(int a)
{
    if(a==0)
    {gotoxy(90,0);
        cout<<"'''JEU PAS ENCORE COMMENCE'''"<<endl;}
    if(a==1)
    {gotoxy(90,0);
        cout<<"'''DANS LE PARTIES QUALIFICATIVES'''"<<endl;}
    if(a==2)
    {gotoxy(90,0);
        cout<<"'''FINALES'''"<<endl;}
}
void password(string& passwd)
{
ifstream password("password.txt",ios::in);
getline(password,passwd);
password.close();
}
void changermdp()
{
string newpass;
cout<<"saisir le nouveau mot de passe"<<endl;
cin>>newpass;
ofstream passout("password.txt",ios::out|ios::trunc);
passout<<newpass;
passout.close();
system("cls");
cout<<"mot de passe change"<<endl;
}
int main()
{
int block=0;
game g;
tournoi tour;
finales fin;
int c,id;
string pass,passwd;
ifstream blockf("block.txt",ios::in);
blockf>>block;
blockf.close();
g.charger();
tour.charge();
fin.charge();
i1:etat_jeu(block);
if (block==0)
{
    cout<<"***********GTT***********"<<endl;
    cout<<"* 1 :mode administrateur *"<<endl<<"* 2 :mode utilisateur   *"<<endl<<"* 0 :sortir             *"<<endl;
    cout<<"***********GTT***********"<<endl;
    cin>>c;
    switch (c)
    {
        case 1:
        {
            password(passwd);
            system("cls");
            i11:cout<<"1 :entrer le mot de passe"<<endl<<"0 :sortir"<<endl;
            cin>>c;
            if(c==0)
            {
                system("cls");
                goto i1;
            }
            else if(c==1)
            {
                cout<<"******mot de passe******"<<endl;
                cin>>pass;
                cout<<"************************"<<endl;
                if(pass!=passwd)
                {
                    system("cls");
                    cout<<"mot de passe eronne"<<endl;
                    goto i11;
                }
                else
                {
                    system("cls");
                    i111:cout<<"                                   ***mode administrateur***"<<endl;
                    cout<<"1 :ajouter joueur"<<endl<<"2 :modifier joueur"<<endl<<"3 :retirer joueur"<<endl<<"4 :afficher la liste de joueurs"<<endl;
                    cout<<"5 :commencer les parties"<<endl;
                    cout<<"6 :changer le mot de passe"<<endl<<"7 :reinitialisier le tournoi"<<endl<<"0 :sortir"<<endl;
                    cin>>c;
                    system("cls");
                    switch (c)
                    {
                        case 1:g.ajouter();goto i111;
                        case 2:g.affichage();cout<<"saisir l'identifiant du joueur a modifier"<<endl;cin>>id;g.modifier(id);goto i111;
                        case 3:g.affichage();cout<<"saisir l'identifiant du joueur a retirer"<<endl;cin>>id;g.retirer(id);goto i111;
                        case 4:g.affichage();goto i111;
                        case 5:if(g.getplaces()!=32)
                                {
                                system("cls");
                                cout<<"joueurs insuffisants"<<endl;
                                goto i111;
                                }
                                else
                                {
                                block=1;
                                tour.saisir();
                                goto i1;
                                }
                        case 6:changermdp();goto i111;
                        case 7:g.reinitialiser();goto i1;
                        case 0:system("cls");goto i1;
                        default:system("cls");cout<<"choix eronne"<<endl;goto i111;
                    }
                }
            }
            else
            {
                system("cls");
                cout<<"choix eronne"<<endl;
                goto i11;
            }
        }
        case 2:system("cls");
               i12:cout<<"                                    ****mode utilisateur****"<<endl<<"1 :afficher la liste des participants"<<endl<<"2 :afficher les groupes"<<endl<<"0 :sortir"<<endl;
               cin>>c;
               system("cls");
               switch (c)
               {
                    case 1:g.affichage();goto i12;
                    case 2:system("cls");g.affichagegrp();goto i12;
                    case 0:system("cls");goto i1;
                    default:system("cls");cout<<"choix eronne"<<endl;goto i12;
               }
        case 0:{g.enregistrer();
                tour.save();
                fin.save();
                ofstream blockof("block.txt",ios::trunc);
                blockof<<block;
                blockof.close();
                return 0;
                }
        default:system("cls");cout<<"choix errone"<<endl;goto i1;
        }
}
else if(block==1)
{
 cout<<"1 :mode administrateur"<<endl<<"2 :mode utilisateur"<<endl<<"0 :sortir"<<endl;
    cin>>c;
    switch (c)
    {
        case 1:
        {
            password(passwd);
            system("cls");
            i21:cout<<"1 :entrer le mot de passe"<<endl<<"0 :sortir"<<endl;
            cin>>c;
            if(c==0)
            {
                system("cls");
                goto i1;
            }
            else if(c==1)
            {
                cout<<"******mot de passe******"<<endl;
                cin>>pass;
                cout<<"************************"<<endl;
                if(pass!=passwd)
                {
                    system("cls");
                    cout<<"mot de passe eronne"<<endl;
                    goto i21;
                }
                else
                {
                    system("cls");
                    i211:cout<<"                                   ***mode administrateur***"<<endl;
                    cout<<"1 :modifier joueur"<<endl<<"2 :eliminer joueur"<<endl<<"3 :afficher la liste de joueurs"<<endl;
                    cout<<"4 :afficher les parties"<<endl<<"5 :changer la date d'une partie"<<endl<<"6 :changer le prix de billet pour une partie"<<endl;
                    cout<<"7 :ajouter des places a une partie"<<endl<<"8 :changer le mot de passe"<<endl;
                    cout<<"9 :passer vers les finales"<<endl<<"10 :reinitialisier le tournoi"<<endl<<"0 :sortir"<<endl;
                    cin>>c;
                    system("cls");
                    switch (c)
                    {
                        case 1:g.affichage();cout<<"saisir l'identifiant du joueur a modifier"<<endl;cin>>id;g.modifier(id);goto i211;
                        case 2:g.affichage();cout<<"saisir l'identifiant du joueur a eliminer"<<endl;cin>>id;g.eliminer(id,block,tour);goto i211;
                        case 3:g.affichage();goto i211;
                        case 4:tour.afficherparties(g);goto i211;
                        case 5:tour.afficherparties(g);cout<<"saisir l'indice du partie a changer la date"<<endl;cin>>id;tour.modifierdate(id-1);goto i211;
                        case 6:tour.afficherparties(g);cout<<"saisir l'indice du partie a changer le prix"<<endl;cin>>id;tour.modifierprix(id-1);goto i211;
                        case 7:tour.afficherparties(g);cout<<"saisir l'indice du partie a changer le nombre de places"<<endl;cin>>id;tour.modifierplaces(id-1);goto i211;
                        case 8:changermdp();goto i211;
                        case 9:{if(tour.getelimin()==16)
                               {
                                   block=2;
                                   fin.initialiser(g);
                                   system("cls");
                                   goto i1;
                               }
                               else
                               {
                                   system("cls");
                                   cout<<"parties qualificatives non terminées"<<endl;
                                   goto i211;
                               }
                        }
                        case 10:g.reinitialiser();block=0;goto i1;
                        case 0:system("cls");goto i1;
                        default:system("cls");cout<<"choix eronne"<<endl;goto i211;
                    }
                }
            }
            else
            {
                system("cls");
                cout<<"choix eronne"<<endl;
                goto i21;
            }
        }
        case 2:system("cls");
               i22:cout<<"                                    ****mode utilisateur****"<<endl<<"TOURNOI COMMENCE"<<endl<<"1 :afficher la liste des participants"<<endl<<"2 :afficher les groupes"<<endl;
               cout<<"3 :afficher les parties"<<endl<<"4 :acheter des billets"<<endl<<"0 :sortir"<<endl;
               cin>>c;
               system("cls");
               switch (c)
               {
                    case 1:g.affichage();goto i22;
                    case 2:system("cls");g.affichagegrp();goto i22;
                    case 3:tour.afficherparties(g);goto i22;
                    case 4:system("cls");tour.afficherparties(g);cout<<"saisir l'indice du jour choisi"<<endl;cin>>id;tour.reserver(id-1);goto i22;
                    case 0:system("cls");goto i1;
                    default:system("cls");cout<<"choix eronne"<<endl;goto i22;
               }
        case 0:{g.enregistrer();
                tour.save();
                fin.save();
                ofstream blockof("block.txt",ios::trunc);
                blockof<<block;
                blockof.close();

                return 0;
        }
        default:system("cls");cout<<"choix errone"<<endl;goto i1;
        }
}
else
{
cout<<"1 :mode administrateur"<<endl<<"2 :mode utilisateur"<<endl<<"0 :sortir"<<endl;
    cin>>c;
    switch (c)
    {
        case 1:
        {
            password(passwd);
            system("cls");
            i31:cout<<"1 :entrer le mot de passe"<<endl<<"0 :sortir"<<endl;
            cin>>c;
            if(c==0)
            {
                system("cls");
                goto i1;
            }
            else if(c==1)
            {
                cout<<"******mot de passe******"<<endl;
                cin>>pass;
                cout<<"************************"<<endl;
                if(pass!=passwd)
                {
                    system("cls");
                    cout<<"mot de passe eronne"<<endl;
                    goto i31;
                }
                else
                {
                    system("cls");
                    i311:cout<<"                                   ***mode administrateur***"<<endl;
                    cout<<"1 :modifier joueur"<<endl<<"2 :afficher la liste de joueurs"<<endl<<"3 :eliminer joueur"<<endl;
                    cout<<"4 :afficher les parties"<<endl<<"5 :changer la date d'une partie"<<endl<<"6 :changer le prix de billet pour une partie"<<endl;
                    cout<<"7 :ajouter des places a une partie"<<endl<<"8 :changer le mot de passe"<<endl;
                    cout<<"9 :reinitialisier le tournoi"<<endl<<"0 :sortir"<<endl;
                    cin>>c;
                    system("cls");
                    switch (c)
                    {
                        case 1:g.affichage();cout<<"saisir l'identifiant du joueur a modifier"<<endl;cin>>id;g.modifier(id);goto i311;
                        case 2:g.affichage();goto i311;
                        case 3:fin.consulter(tour,g);cout<<"saisir l'identifiant du joueur a eliminer"<<endl;cin>>id;g.eliminer(id,block,tour);fin.verif(g,tour);goto i311;
                        case 4:fin.consulter(tour,g);goto i311;
                        case 5:fin.consulter(tour,g);cout<<"saisir l'indice du partie a changer la date"<<endl;cin>>id;fin.modifierdate(id-1,tour);goto i311;
                        case 6:fin.consulter(tour,g);cout<<"saisir l'indice du partie a changer le prix"<<endl;cin>>id;fin.modifierprix(id-1,tour);goto i311;
                        case 7:fin.consulter(tour,g);cout<<"saisir l'indice du partie a changer le nombre de places"<<endl;cin>>id;fin.modifierplaces(id-1,tour);goto i311;
                        case 8:changermdp();goto i311;
                        case 9:g.reinitialiser();block=0;goto i1;
                        case 0:system("cls");goto i1;
                        default:system("cls");cout<<"choix eronne"<<endl;goto i311;
                    }
                }
            }
            else
            {
                system("cls");
                cout<<"choix eronne"<<endl;
                goto i31;
            }
        }
        case 2:system("cls");
               i32:cout<<"                                    ****mode utilisateur****"<<endl<<"FINALES COMMENCé"<<endl<<"1 :afficher la liste des participants"<<endl;
               cout<<"2 :afficher les parties"<<endl<<"3 :acheter des billets"<<endl<<"0 :sortir"<<endl;
               cin>>c;
               system("cls");
               switch (c)
               {
                    case 1:g.affichage();goto i32;
                    case 2:fin.consulter(tour,g);goto i32;
                    case 3:system("cls");fin.consulter(tour,g);cout<<"saisir l'indice du match choisi"<<endl;cin>>id;fin.reserver(id-1,tour);goto i32;
                    case 0:system("cls");goto i1;
                    default:system("cls");cout<<"choix eronne"<<endl;goto i32;
               }
        case 0:{g.enregistrer();
                tour.save();
                fin.save();
                ofstream blockof("block.txt",ios::trunc);
                blockof<<block;
                blockof.close();

                return 0;
        }
        default:system("cls");cout<<"choix errone"<<endl;goto i1;
        }
}
}
