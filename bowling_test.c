#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <uvsqgraphics.h>
#define LF LARGEUR_FENETRE
#define HF HAUTEUR_FENETRE
  
int bx;
int ISpressed;
int NbJeu;
int NbLancer;
int NbLancerJoueur2;
int Score;
int ScoreJoueur2;
int ScoreLancer;
int BestScore;
int Multijoueur;
int Joueur2;
int PartieEnCours;
int Diff, DiffBot;
int Ordinateur;
int CouleurBoule, CouleurBouleJoueur2;
int RangeeUneQuilleUne, RangeeUneQuilleDeux, RangeeUneQuilleTrois, RangeeUneQuilleQuatre;
int RangeeDeuxQuilleUne, RangeeDeuxQuilleDeux, RangeeDeuxQuilleTrois;
int RangeeTroisQuilleUne, RangeeTroisQuilleDeux;
int RangeeQuatreQuilleUne;
int StrikeSpare;
int StrikeSpareJoueur2;
int FaitStrike, FaitSpare, BonusEnCours, PasDeBonus;
int EcranPrincipal, EcranScore, EcranBot, EcranCredits, EcranParametres, initEcranPrincipal, initBouton, initEcranScore, initEcranBot, initEcranCredits, initEcranParametres;
float getBX, getBY, getX, coefD, k, tX, grandX;
POINT P11;
  
//boule
  
void boule(int dx, int dy, int rayon) {
    POINT P1;
    P1.x = dx; P1.y = dy;
    if (!Joueur2)
    {
    if (CouleurBoule == 0)
    {
    draw_fill_circle(P1, rayon, blue);
    }
    else if (CouleurBoule == 1)
    {
    draw_fill_circle(P1, rayon, green);
    }
    else if (CouleurBoule == 2)
    {
    draw_fill_circle(P1, rayon, orange);
    }
    else if (CouleurBoule == 3)
    {
    draw_fill_circle(P1, rayon, pink);
    }
    else if (CouleurBoule == 4)
    {
    draw_fill_circle(P1, rayon, violet);
    }
    else if (CouleurBoule == 5)
    {
    draw_fill_circle(P1, rayon, red);
    }
    }
    else
    {
    if (CouleurBouleJoueur2 == 0)
    {
    draw_fill_circle(P1, rayon, blue);
    }
    else if (CouleurBouleJoueur2 == 1)
    {
    draw_fill_circle(P1, rayon, green);
    }
    else if (CouleurBouleJoueur2 == 2)
    {
    draw_fill_circle(P1, rayon, orange);
    }
    else if (CouleurBouleJoueur2 == 3)
    {
    draw_fill_circle(P1, rayon, pink);
    }
    else if (CouleurBouleJoueur2 == 4)
    {
    draw_fill_circle(P1, rayon, violet);
    }
    else if (CouleurBouleJoueur2 == 5)
    {
    draw_fill_circle(P1, rayon, red);
    }
    }
}
  
void effboule(int dx, int dy) {
    POINT P1;
    P1.x = dx; P1.y = dy;
    draw_fill_circle(P1, 40, burlywood);
}
  
void effboulerayon(int dx, int dy, int rayon) {
    POINT P1;
    P1.x = dx; P1.y = dy;
    draw_fill_circle(P1, rayon, burlywood);
}
  
 //quille
    
void quille(int x,int y)
{
int by,cy;
by = y + 85;
cy = y + 140;
POINT P1, P2;
P1.x = x; P1.y = y+5;
draw_fill_circle(P1,16.5, peru);
P1.x = x; P1.y = y;
P2.x = x; P2.y = by;
draw_fill_ellipse(P1, P2, 15, noir);
P1.x = x; P1.y = by;
P2.x = x; P2.y = cy;
draw_fill_ellipse(P1, P2, 7.5, noir);
P1.x = x; P1.y = y;
P2.x = x; P2.y = by;
draw_fill_ellipse(P1, P2, 13, blanc);
P1.x = x; P1.y = by;
P2.x = x; P2.y = cy;
draw_fill_ellipse(P1, P2, 5.5, blanc);
P1.x = x-5; P1.y = by-3;
P2.x = x+5; P2.y = by-3;
draw_line(P1, P2, rouge);
P1.x = x-13; P1.y = by-2;
P2.x = x+13; P2.y = by-2;
draw_line(P1, P2, rouge);
P1.x = x-12; P1.y = by-1;
P2.x = x+12; P2.y = by-1;
draw_line(P1, P2, rouge);
P1.x = x-12; P1.y = by;
P2.x = x+12; P2.y = by;
draw_line(P1, P2, rouge);
P1.x = x-11; P1.y = by+1;
P2.x = x-5; P2.y = by+1;
draw_line(P1, P2, rouge);
P1.x = x+5; P1.y = by+1;
P2.x = x+11; P2.y = by+1;
draw_line(P1, P2, rouge);
P1.x = x-2; P1.y = by+5;
P2.x = x+2; P2.y = by+5;
draw_line(P1, P2, rouge);
P1.x = x-8; P1.y = by+6;
P2.x = x+8; P2.y = by+6;
draw_line(P1, P2, rouge);
P1.x = x-8; P1.y = by+7;
P2.x = x+8; P2.y = by+7;
draw_line(P1, P2, rouge);
P1.x = x-9; P1.y = by+8;
P2.x = x+9; P2.y = by+8;
draw_line(P1, P2, rouge);
P1.x = x-9; P1.y = by+9;
P2.x = x-2; P2.y = by+9;
draw_line(P1, P2, rouge);
P1.x = x+2; P1.y = by+9;
P2.x = x+9; P2.y = by+9;
draw_line(P1, P2, rouge);
}
  
void GrosseQuille(int x,int y)
{
int by,cy;
by = y + 175;
cy = y + 275;
POINT P1, P2;
P1.x = x; P1.y = y+10;
draw_fill_circle(P1,33, peru);
P1.x = x; P1.y = y;
P2.x = x; P2.y = by;
draw_fill_ellipse(P1, P2, 30, noir);
P1.x = x; P1.y = by;
P2.x = x; P2.y = cy;
draw_fill_ellipse(P1, P2, 15, noir);
P1.x = x; P1.y = y;
P2.x = x; P2.y = by;
draw_fill_ellipse(P1, P2, 26, blanc);
P1.x = x; P1.y = by;
P2.x = x; P2.y = cy;
draw_fill_ellipse(P1, P2, 11, blanc);
P1.x = x-20; P1.y = by-6;
P2.x = x+20; P2.y = by-6;
draw_line(P1, P2, rouge);
P1.x = x-28; P1.y = by-5;
P2.x = x+28; P2.y = by-5;
draw_line(P1, P2, rouge);
P1.x = x-27; P1.y = by-4;
P2.x = x+27; P2.y = by-4;
draw_line(P1, P2, rouge);
P1.x = x-26; P1.y = by-3;
P2.x = x+26; P2.y = by-3;
draw_line(P1, P2, rouge);
P1.x = x-25; P1.y = by-2;
P2.x = x+25; P2.y = by-2;
draw_line(P1, P2, rouge);
P1.x = x-25; P1.y = by-1;
P2.x = x+25; P2.y = by-1;
draw_line(P1, P2, rouge);
P1.x = x-24; P1.y = by;
P2.x = x+24; P2.y = by;
draw_line(P1, P2, rouge);
P1.x = x-23; P1.y = by+1;
P2.x = x+23; P2.y = by+1;
draw_line(P1, P2, rouge);
P1.x = x-22; P1.y = by+2;
P2.x = x-20; P2.y = by+2;
draw_line(P1, P2, rouge);
P1.x = x+20; P1.y = by+2;
P2.x = x+22; P2.y = by+2;
draw_line(P1, P2, rouge);
P1.x = x-8; P1.y = by+10;
P2.x = x+8; P2.y = by+10;
draw_line(P1, P2, rouge);
P1.x = x-17; P1.y = by+11;
P2.x = x+17; P2.y = by+11;
draw_line(P1, P2, rouge);
P1.x = x-17; P1.y = by+12;
P2.x = x+17; P2.y = by+12;
draw_line(P1, P2, rouge);
P1.x = x-17; P1.y = by+13;
P2.x = x+17; P2.y = by+13;
draw_line(P1, P2, rouge);
P1.x = x-18; P1.y = by+14;
P2.x = x+18; P2.y = by+14;
draw_line(P1, P2, rouge);
P1.x = x-18; P1.y = by+15;
P2.x = x+18; P2.y = by+15;
draw_line(P1, P2, rouge);
P1.x = x-19; P1.y = by+16;
P2.x = x+19; P2.y = by+16;
draw_line(P1, P2, rouge);
P1.x = x-19; P1.y = by+17;
P2.x = x+19; P2.y = by+17;
draw_line(P1, P2, rouge);
P1.x = x-19; P1.y = by+18;
P2.x = x-8; P2.y = by+18;
draw_line(P1, P2, rouge);
P1.x = x+8; P1.y = by+18;
P2.x = x+19; P2.y = by+18;
draw_line(P1, P2, rouge);
}
  
 //supprimer quille
    
void SupprQuille(int x,int y)
{
int by,cy;
by = y + 85;
cy = y + 140;
POINT P1, P2;
P1.x = x; P1.y = y;
P2.x = x; P2.y = by;
draw_fill_ellipse(P1, P2, 15, burlywood);
P1.x = x; P1.y = by;
P2.x = x; P2.y = cy;
draw_fill_ellipse(P1, P2, 7.5, burlywood);
P1.x = x; P1.y = y;
P2.x = x; P2.y = by;
draw_fill_ellipse(P1, P2, 13, burlywood);
P1.x = x; P1.y = by;
P2.x = x; P2.y = cy;
draw_fill_ellipse(P1, P2, 5.5, burlywood);
P1.x = x; P1.y = y+5;
draw_fill_circle(P1,16.5, burlywood);
}
   
//actualiser le fichier
  
void ActualiserData()
{
FILE* fichier = NULL;
  
fichier = fopen("data.bowling", "w");
fprintf(fichier, "%d\n%d\n%d\n%d\n%d", BestScore, Diff, DiffBot, CouleurBoule, CouleurBouleJoueur2);
fclose(fichier);
}
  
//ombre boule
  
void OmbreBoule()
{
    POINT P1;
P1.x = 1300; P1.y = 400;
if (!Joueur2)
{
if (CouleurBoule == 0)
    {
    draw_fill_circle(P1,11,blue);
    }
    else if (CouleurBoule == 1)
    {
    draw_fill_circle(P1,11,green);
    }
    else if (CouleurBoule == 2)
    {
    draw_fill_circle(P1,11,orange);
    }
    else if (CouleurBoule == 3)
    {
    draw_fill_circle(P1,11,pink);
    }
    else if (CouleurBoule == 4)
    {
    draw_fill_circle(P1,11,violet);
    }
    else if (CouleurBoule == 5)
    {
    draw_fill_circle(P1,11,red);
    }
}
else
{
    if (CouleurBouleJoueur2 == 0)
    {
    draw_fill_circle(P1,11,blue);
    }
    else if (CouleurBouleJoueur2 == 1)
    {
    draw_fill_circle(P1,11,green);
    }
    else if (CouleurBouleJoueur2 == 2)
    {
    draw_fill_circle(P1,11,orange);
    }
    else if (CouleurBouleJoueur2 == 3)
    {
    draw_fill_circle(P1,11,pink);
    }
    else if (CouleurBouleJoueur2 == 4)
    {
    draw_fill_circle(P1,11,violet);
    }
    else if (CouleurBouleJoueur2 == 5)
    {
    draw_fill_circle(P1,11,red);
    }   
}
}
  
void SupprOmbreBoule()
{
    POINT P1;
P1.x = 1300; P1.y = 400;
draw_fill_circle(P1,11,burlywood);
}
   
//actualiser fond noir
  
void fondNoir()
{
POINT p1, p2;
p1.x = 331; p1.y = 601;
p2.x = 871; p2.y = 750;
draw_fill_rectangle(p1,p2,noir);
}
  
 //ombre
    
 void ombres(int x,int y)
{
   
POINT P1;
P1.x = x; P1.y = y;
draw_fill_circle(P1,10, white);
   
}
  
void SupprOmbres(int x,int y)
{
   
POINT P1;
P1.x = x; P1.y = y;
draw_fill_circle(P1,10, burlywood);
   
}
 
// afficher gouttiere
 
void AfficherGouttiere()
{
    POINT p1, p2,p3;
    p1.x = 330; p1.y = 600;
p2.x = 225; p2.y = 0;
p3.x = 400; p3.y = 600;
draw_fill_triangle(p1,p2,p3, darkgray);
p1.x = 145; p1.y = 0;
p2.x = 330; p2.y = 600;
p3.x = 225; p3.y = 0;
draw_fill_triangle(p1,p2,p3, darkgray);
p1.x = 225; p1.y = 0;
p2.x = 400; p2.y = 600;
draw_line(p1, p2, black);
p1.x = 145; p1.y = 0;
p2.x = 330; p2.y = 600;
draw_line(p1, p2, black);
   
p1.x = 800; p1.y = 600;
p2.x = 1050; p2.y = 0;
p3.x = 870; p3.y = 600;
draw_fill_triangle(p1,p2,p3, darkgray);
p1.x = 970; p1.y = 0;
p2.x = 800; p2.y = 600;
p3.x = 1050; p3.y = 0;
draw_fill_triangle(p1,p2,p3, darkgray);
p1.x = 1050; p1.y = 0;
p2.x = 870; p2.y = 600;
draw_line(p1, p2, black);
p1.x = 970; p1.y = 0;
p2.x = 800; p2.y = 600;
draw_line(p1, p2, black);
}
 
  // triangle noirs sur la piste
  
 void TrianglePiste(COULEUR coul)
 {
 POINT p1, p2,p3;
  
p1.x =600; p1.y =300;
p2.x = 580;  p2.y = 290;
p3.x = 620; p3.y = 290;
draw_fill_triangle(p1,p2,p3,coul);
 
p1.x =545; p1.y =280;
p2.x = 525;  p2.y = 270;
p3.x = 565; p3.y = 270;
draw_fill_triangle(p1,p2,p3,coul);
 
p1.x =655; p1.y =280;
p2.x = 635;  p2.y = 270;
p3.x = 675; p3.y = 270;
draw_fill_triangle(p1,p2,p3,coul);
 
p1.x =490; p1.y =260;
p2.x = 470;  p2.y = 250;
p3.x = 510; p3.y = 250;
draw_fill_triangle(p1,p2,p3,coul);
 
p1.x =710; p1.y =260;
p2.x = 690;  p2.y = 250;
p3.x = 730; p3.y = 250;
draw_fill_triangle(p1,p2,p3,coul);
 
p1.x =435; p1.y =240;
p2.x = 415;  p2.y = 230;
p3.x = 455; p3.y = 230;
draw_fill_triangle(p1,p2,p3,coul);
 
p1.x =765; p1.y =240;
p2.x = 745;  p2.y = 230;
p3.x = 785; p3.y = 230;
draw_fill_triangle(p1,p2,p3,coul);
}
 
void piste(int x, int y)
   {
 int ax, bx, cx, dx, ex, ay, by, cy, dy;
 ax = x + 175;
 bx = x + 750;
 cx = x + 575;
 dx = x + 106;
 ex = x + 646;
 ay = y + 600;
 by = y + 601;
 cy = y + 826;
 dy = y + 1100;
 POINT p1, p2, p3;
p1.x = x; p1.y = y;
p2.x = ax; p2.y = ay;
p3.x = bx; p3.y = y;
draw_fill_triangle(p1,p2,p3, burlywood);
p1.x = ax; p1.y = ay;
p2.x = cx; p2.y = by;
p3.x = bx; p3.y = y;
draw_fill_triangle(p1,p2,p3, burlywood);
   
AfficherGouttiere();
   
p1.x = dx; p1.y = by;
p2.x = ex; p2.y = dy;
draw_fill_rectangle(p1,p2,noir);
   
p1.x = dx; p1.y = cy;
p2.x = ex; p2.y = dy;
draw_fill_rectangle(p1,p2,darkslategray);
 
 }
  
//Actualiser les quilles
  
void ActualiserQuilles()
{
   //actualisation de la piste pour eviter les ghosting bleu  
  POINT p1, p2,p3;
   p1.x =400; p1.y =600;
   p2.x =225; p2.y=0;
   p3.x =800; p3.y=0;
draw_fill_triangle(p1,p2,p3,burlywood);
  
 p1.x =800; p1.y =600;
   p2.x =425; p2.y=0;
   p3.x =970; p3.y=0;
draw_fill_triangle(p1,p2,p3,burlywood);
  
// triangle noirs sur la piste
TrianglePiste(noir);
  
  AfficherGouttiere();    
 //ombre de la balle, afficher si pas spare ou strike sinon cacher
if (!StrikeSpare)
{
OmbreBoule();
}
else
{
SupprOmbreBoule();
}
  
//on actualise les quilles tombées
  
//rangée quatre
  
if (RangeeQuatreQuilleUne)
{ 
    SupprOmbres(1300,600);
    SupprQuille(600,410);
}
 
attendre(50); 
  
//rangée trois
  
if (RangeeTroisQuilleUne)
{ 
    SupprOmbres(1275,650);
    SupprQuille(550,460);
}
if (RangeeTroisQuilleDeux)
{ 
    SupprOmbres(1325,650);
    SupprQuille(650,460);
}
 
attendre(50);
 
//rangée deux
  
if (RangeeDeuxQuilleUne)
{ 
    SupprOmbres(1250,700);
    SupprQuille(500,510);
}
  
if (RangeeDeuxQuilleDeux)
{ 
    SupprOmbres(1300,700);
    SupprQuille(600,510);
}
  
if (RangeeDeuxQuilleTrois)
{ 
    SupprOmbres(1350,700);
    SupprQuille(700,510);
}
 
fondNoir();
attendre(50);
  
//rangée du fond (rangée une)
  
if (RangeeUneQuilleUne)
{
    SupprOmbres(1225,750);
    SupprQuille(450,550);
}
if (RangeeUneQuilleDeux)
{
    SupprOmbres(1275,750);
    SupprQuille(550,550);
}
if (RangeeUneQuilleTrois)
{ 
    SupprOmbres(1325,750);
    SupprQuille(650,550);
}
  
if (RangeeUneQuilleQuatre)
{ 
    SupprOmbres(1375,750);
    SupprQuille(750,550);
}
 
fondNoir();
 
//on actualise les quilles debouts
  
//rangée du fond (rangée une)
  
if (!RangeeUneQuilleUne)
{ 
    ombres(1225,750);
    quille(450,550);
}
  
if (!RangeeUneQuilleDeux)
{ 
    ombres(1275,750);
    quille(550,550);
}
  
if (!RangeeUneQuilleTrois)
{ 
    ombres(1325,750);
    quille(650,550);
}
  
if (!RangeeUneQuilleQuatre)
{ 
    ombres(1375,750);
    quille(750,550);
}
  
//rangée deux
  
if (!RangeeDeuxQuilleUne)
{ 
    ombres(1250,700);
    quille(500,510);
}
  
if (!RangeeDeuxQuilleDeux)
{ 
    ombres(1300,700);
    quille(600,510);
}
  
if (!RangeeDeuxQuilleTrois)
{ 
    ombres(1350,700);
    quille(700,510);
}
  
//rangée trois
  
if (!RangeeTroisQuilleUne)
{ 
    ombres(1275,650);
    quille(550,460);
}
if (!RangeeTroisQuilleDeux)
{ 
    ombres(1325,650);
    quille(650,460);
}
  
//rangée quatre
  
if (!RangeeQuatreQuilleUne)
{ 
    ombres(1300,600);
    quille(600,410);
}
  
}
 
//chargement piste et graphisme
  
void ChargementInit()
{ 
       
 POINT P1, P2;
    
fill_screen(white);
P1.x = 0; P1.y = 601;
P2.x = 1400; P2.y = 1200;
draw_fill_rectangle(P1,P2,darkslategray);
P1.x = 0; P1.y = 0;
P2.x = 1400; P2.y = 600;
draw_fill_rectangle(P1,P2,navajowhite);
 
  //remplir piste 
 piste(225,0); 
   
 //piste sur les côtés
 POINT p1, p2,p3;
//couleurs des pistes décors(droite)
p1.x = 1000; p1.y = 601;
p2.x = 1198; p2.y = 95;
p3.x = 1198; p3.y = 285;
draw_fill_triangle(p1,p2,p3,darkgray);
  
p1.x = 1000; p1.y = 601;
p2.x = 1198; p2.y = 285;
p3.x = 1070; p3.y = 601;
draw_fill_triangle(p1,p2,p3,darkgray);
  
p1.x = 1070; p1.y = 601;
p2.x = 1198; p2.y = 285;
p3.x = 1198; p3.y = 823;
draw_fill_triangle(p1,p2,p3,burlywood);
 
//couleurs des pistes décors(gauche)
p1.x =200; p1.y =601;
p2.x = 0;  p2.y = 0;
p3.x =130; p3.y =601;
draw_fill_triangle(p1,p2,p3,darkgray);
  
p1.x =130; p1.y =601;
p2.x = 0;  p2.y = 227;
p3.x = 0;  p3.y = 0;
draw_fill_triangle(p1,p2,p3,darkgray);
  
p1.x =130; p1.y =601;
p2.x = 0;  p2.y = 227;
p3.x = 0; p3.y = 823;
draw_fill_triangle(p1,p2,p3,burlywood);
  
//traits gouttières décor droit
p1.x =1000; p1.y = 601;
p2.x =1198; p2.y = 95;
draw_line(p1,p2,noir);
  
p1.x = 1070; p1.y = 601;
p2.x = 1198; p2.y = 285;
draw_line(p1,p2,noir);
//traits gouttières décor gauche
p1.x =200; p1.y =601;
p2.x = 0;  p2.y = 0;
draw_line(p1,p2,noir);
  
p1.x =130; p1.y =601;
p2.x = -80;  p2.y = 0;
draw_line(p1,p2,noir);
  
  
// triangle noirs sur la piste
TrianglePiste(noir);
  
// carré piste droite et gauche
p1.x = 0; p1.y = 823;
p2.x = 200; p2.y =601;
draw_fill_rectangle(p1,p2,noir);
  
p1.x = 1000; p1.y = 823;
p2.x = 1198; p2.y =601;
draw_fill_rectangle(p1,p2,noir);
 
quille(65,550);
quille(7,510);
quille(1140,550);
quille(1198,510);
 
 //Tableau rouge de droite  
P1.x = 1200; P1.y = 0;
P2.x = 1400; P2.y = 1000;
draw_fill_rectangle(P1,P2,moccasin);
  
 //trait pour le jeu vu du haut
     
p1.x=1210;  p1.y=200;
p2.x=1390;  p2.y=800;
draw_fill_rectangle(p1,p2,burlywood);
   
 ActualiserQuilles();
    
 //écriture en bleu
   
 POINT a1,a2;
  char *a_ecrire = "BOWLING";
     
    a2.x = 473; 
    a2.y = 939;
    aff_pol(a_ecrire,55,a2,black);
      
         a1.x = 470; 
    a1.y = 940;
    aff_pol(a_ecrire,55,a1,blanc);
     
 POINT A1, A2, A3, A4, A5, A6;
     
     char *b_ecrire = "MEILLEUR";
    A2.x = 1230; 
    A2.y = 85;
    aff_pol(b_ecrire,30,A2,lightslategray); 
        
         char *c_ecrire = "SCORE";
    A3.x = 1240; 
    A3.y = 860;
    aff_pol(c_ecrire,35,A3,lightslategray); 
      
    A1.x = 1250; 
    A1.y = 50;
    aff_pol(c_ecrire,30,A1,lightslategray);
      
    A6.x = 1240; 
    A6.y = 170;
    aff_int(BestScore,60,A6,lightslategray);
        
      
    char *lancer = "LANCER :   /2";
    A4.x = 350; 
    A4.y = 850;
    aff_pol(lancer,17,A4,black);  
      
    char *jeu = "JEU :    /10";
    A5.x = 750; 
    A5.y = 850;
    aff_pol(jeu,17,A5,black); 
}
void AfficherScore()
{
    POINT A6, A7, A8, p1, p2;
    p1.x = 1220; p1.y = 865;
    p2.x = 1400; p2.y = 970;
    draw_fill_rectangle(p1,p2,moccasin);
    if (!Multijoueur)
    {
    A6.x = 1240; 
    A6.y = 950;
    aff_int(Score,60,A6,lightslategray);
    }
    else
    {
    char *j1 = "J1";
    char *j2 = "J2";
    A6.x = 1240; 
    A6.y = 960;
    if (CouleurBoule == 0)
    {
    aff_pol(j1,35,A6,blue);
    }
    else if (CouleurBoule == 1)
    {
    aff_pol(j1,35,A6,green);
    }
    else if (CouleurBoule == 2)
    {
    aff_pol(j1,35,A6,orange);
    }
    else if (CouleurBoule == 3)
    {
    aff_pol(j1,35,A6,pink);
    }
    else if (CouleurBoule == 4)
    {
    aff_pol(j1,35,A6,violet);
    }
    else if (CouleurBoule == 5)
    {
    aff_pol(j1,35,A6,red);
    }
    A6.x = 1240; 
    A6.y = 910;
    if (CouleurBouleJoueur2 == 0)
    {
    aff_pol(j2,35,A6,blue); 
    }
    else if (CouleurBouleJoueur2 == 1)
    {
    aff_pol(j2,35,A6,green); 
    }
    else if (CouleurBouleJoueur2 == 2)
    {
    aff_pol(j2,35,A6,orange); 
    }
    else if (CouleurBouleJoueur2 == 3)
    {
    aff_pol(j2,35,A6,pink); 
    }
    else if (CouleurBouleJoueur2 == 4)
    {
    aff_pol(j2,35,A6,violet); 
    }
    else if (CouleurBouleJoueur2 == 5)
    {
    aff_pol(j2,35,A6,red); 
    }
    A6.x = 1290; 
    A6.y = 970;
    aff_int(Score,45,A6,lightslategray);
    A6.x = 1290; 
    A6.y = 920;
    aff_int(ScoreJoueur2,45,A6,lightslategray);
    }
    if (NbJeu <= 10)
    {
    p1.x = 435; p1.y = 830;
    p2.x = 447; p2.y = 850;
    draw_fill_rectangle(p1,p2,darkslategray);
    A7.x = 437; 
    A7.y = 850;
    aff_int(NbLancer,17,A7,black);
    p1.x = 795; p1.y = 830;
    p2.x = 807; p2.y = 850;
    draw_fill_rectangle(p1,p2,darkslategray);
    A8.x = 797; 
    A8.y = 850;
    aff_int(NbJeu,17,A8,black);
    }
}
 
//menu choix adversaire
//Afficher menu principal
  
void AfficherMenu()
{
while (EcranPrincipal)
{
    if (!initEcranPrincipal)
    {
    fill_screen(black);
    POINT p1, p2, p3;
    p1.x = 50; p1.y = 500;
    p2.x = 1350; p2.y = 500;
    p3.x = 200; p3.y = 800;
    draw_fill_triangle(p1,p3,p2, burlywood);
    p1.x = 1350; p1.y = 500;
    p2.x = 1200; p2.y = 800;
    p3.x = 200; p3.y = 800;
    draw_fill_triangle(p1,p3,p2, burlywood);
    POINT T1,T2;
    char *Titre = "BOWLING";
    char *Menu1 = "UN JOUEUR";
    char *Menu2 = "DEUX JOUEURS";
    char *Menu3 = "QUITTER";
    char *Menu4 = "PARAMETRES";
    char *reprendre = "REPRENDRE";
    char *Menu5 = "FINIR LA PARTIE";
    char *MenuTitre = "MENU PRINCIPAL";
    char *MenuTitre2 = "MENU PAUSE";
    char *MeilleurScore = "MEILLEUR SCORE :";
    T1.x = 175; 
    T1.y = 29*hauteur_texte(Titre,20);
    T2.x = 180; 
    T2.y = 28.9*hauteur_texte(Titre,20);
    aff_pol(Titre,150,T2,black);
    aff_pol(Titre,150,T1,white);
    GrosseQuille(1200,600);
    p1.x = 1050; p1.y = 590;
    draw_fill_circle(p1,60, peru);
    boule(1050,620,80);
    p1.x = 5; p1.y = 940;
    p2.x = 145; p2.y = 990;
    draw_fill_rectangle(p1,p2,lightslategray);
    char *Menu = "CREDITS";
    p1.x = 25; 
    p1.y = 980;
    aff_pol(Menu,22,p1,white);
    if (!PartieEnCours)
    {
    T1.x = 645; 
    T1.y = 565;
    T2.x = 646; 
    T2.y = 564;
    aff_pol(MeilleurScore,20,T2,black);
    aff_pol(MeilleurScore,20,T1,white);
    T1.x = 845; 
    T1.y = 565;
    T2.x = 846; 
    T2.y = 564;
    aff_int(BestScore,20,T2,black);
    aff_int(BestScore,20,T1,white);
    p1.x = 300; p1.y = 300;
    p2.x = 650; p2.y = 400;
    draw_fill_rectangle(p1,p2,burlywood);
    draw_rectangle(p1,p2,blanc);
    p1.x = 750; p1.y = 300;
    p2.x = 1100; p2.y = 400;
    draw_fill_rectangle(p1,p2,burlywood);
    draw_rectangle(p1,p2,blanc);
    p1.x = 750; p1.y = 100;
    p2.x = 1100; p2.y = 200;
    draw_fill_rectangle(p1,p2,peru);
    draw_rectangle(p1,p2,blanc);
    p1.x = 300; p1.y = 100;
    p2.x = 650; p2.y = 200;
    draw_fill_rectangle(p1,p2,burlywood);
    draw_rectangle(p1,p2,blanc);
    T1.x = 215; 
    T1.y = 22.5*hauteur_texte(Titre,20);
    T2.x = 217.5; 
    T2.y = 22.45*hauteur_texte(Titre,20);
    aff_pol(MenuTitre,45,T2,black);
    aff_pol(MenuTitre,45,T1,white);
    T1.x = 360; 
    T1.y = 375;
    aff_pol(Menu1,40,T1,white);
    T1.x = 770;  
    T1.y = 375;
    aff_pol(Menu2,40,T1,white);
    T1.x = 835;  
    T1.y = 175;
    aff_pol(Menu3,40,T1,white);
    T1.x = 345;  
    T1.y = 175;
    aff_pol(Menu4,40,T1,white);
    }
    else if (PartieEnCours)
    {
    if (Multijoueur)
    {
    p1.x = 1050; p1.y = 590;
    draw_fill_circle(p1,60, peru);
    p1.x = 1120; p1.y = 600;
    draw_fill_circle(p1,60, peru);
    Joueur2 = 1;
    boule(1120,630,80);
    Joueur2 = 0;
    boule(1050,620,80);
    }
    p1.x = 750; p1.y = 100;
    p2.x = 1100; p2.y = 200;
    draw_fill_rectangle(p1,p2,peru);
    draw_rectangle(p1,p2,blanc);
    p1.x = 300; p1.y = 100;
    p2.x = 650; p2.y = 200;
    draw_fill_rectangle(p1,p2,burlywood);
    draw_rectangle(p1,p2,blanc);
    p1.x = 300; p1.y = 300;
    p2.x = 650; p2.y = 400;
    draw_fill_rectangle(p1,p2,burlywood);
    draw_rectangle(p1,p2,blanc);
    p1.x = 750; p1.y = 300;
    p2.x = 1100; p2.y = 400;
    draw_fill_rectangle(p1,p2,burlywood);
    draw_rectangle(p1,p2,blanc);
    T1.x = 215; 
    T1.y = 22.5*hauteur_texte(Titre,20);
    T2.x = 217.5; 
    T2.y = 22.45*hauteur_texte(Titre,20);
    aff_pol(MenuTitre2,45,T2,black);
    aff_pol(MenuTitre2,45,T1,white);
    T1.x = 355;  
    T1.y = 375;
    aff_pol(reprendre,40,T1,white);
    T1.x = 835;  
    T1.y = 175;
    aff_pol(Menu3,40,T1,white);
    T1.x = 345;  
    T1.y = 175;
    aff_pol(Menu4,40,T1,white);
    T1.x = 760;  
    T1.y = 375;
    aff_pol(Menu5,40,T1,white);
    }
    initEcranPrincipal = 1;
    }
    POINT P5;
    P5 = get_clic();
    if (!PartieEnCours)
    {
    if (P5.x <= 1100 && P5.x >= 750 && P5.y <= 200 && P5.y >= 100)
    {
        attendre(100);
        exit(0);
    }
    else if (P5.x <= 650 && P5.x >= 300 && P5.y <= 400 && P5.y >= 300)
    {
        attendre(100);
        EcranPrincipal = 0;
        initEcranPrincipal = 0;
        Joueur2 = 0;
        Multijoueur = 0;
        ChargementInit();
        PartieEnCours = 1;
        AfficherScore();
        P11.x = -1;
        P11.y = -1;
        ISpressed = 0;
    }
    else if (P5.x <= 1100 && P5.x >= 750 && P5.y <= 400 && P5.y >= 300)
    {
        attendre(100);
        EcranPrincipal = 0;
        initEcranPrincipal = 0;
        EcranBot = 1;
    }
    else if (P5.x <= 650 && P5.x >= 300 && P5.y <= 200 && P5.y >= 100)
    {
        attendre(100);
        EcranPrincipal = 0;
        initEcranPrincipal = 0;
        EcranParametres = 1;
    }
    else if (P5.x <= 1130 && P5.x >= 970 && P5.y <= 700 && P5.y >= 540)
    {
        if (!Joueur2)
        {
        CouleurBoule = alea_int(6);
        while (CouleurBoule == CouleurBouleJoueur2)
        {
            CouleurBoule = alea_int(6);
        }
        }
        else
        {
        CouleurBouleJoueur2 = alea_int(6);
        while (CouleurBoule == CouleurBouleJoueur2)
        {
            CouleurBouleJoueur2 = alea_int(6);
        }   
        }
        boule(1050,620,80);
        ActualiserData();
    } 
    else if (P5.x <= 145 && P5.x >= 5 && P5.y <= 990 && P5.y >= 940)
    {
    attendre(100);
    EcranPrincipal = 0;
    initEcranPrincipal = 0;
    EcranCredits = 1;
    } 
    }
    else if (PartieEnCours)
    {
    if (P5.x <= 1100 && P5.x >= 750 && P5.y <= 200 && P5.y >= 100)
    {
        attendre(100);
        exit(0);
    }
    else if (P5.x <= 650 && P5.x >= 300 && P5.y <= 200 && P5.y >= 100)
    {
        attendre(100);
        EcranPrincipal = 0;
        initEcranPrincipal = 0;
        EcranParametres = 1;
    }   
    else if (P5.x <= 650 && P5.x >= 300 && P5.y <= 400 && P5.y >= 300)
    {
        attendre(100);
        ChargementInit();
        ISpressed = 0;
        P11.x = -1;
        P11.y = -1;
        EcranPrincipal = 0;
        initBouton = 0;
        initEcranPrincipal = 0;
        AfficherScore();
    }     
    else if (P5.x <= 1100 && P5.x >= 750 && P5.y <= 400 && P5.y >= 300)
    {
        attendre(100);
        EcranPrincipal = 1;
        initBouton = 0;
        initEcranPrincipal = 0;
        ISpressed = 1;
        PartieEnCours = 0;
        NbJeu = 1;
        NbLancer = 1;
        Ordinateur = 0;
        StrikeSpare = 0;
        StrikeSpareJoueur2 = 0;
        Score = 0;
        ScoreJoueur2 = 0;
        Multijoueur = 0;
        RangeeUneQuilleUne = 0;
        RangeeUneQuilleDeux = 0;
        RangeeUneQuilleTrois = 0;
        RangeeUneQuilleQuatre = 0;
        RangeeDeuxQuilleUne = 0;
        RangeeDeuxQuilleDeux = 0;
        RangeeDeuxQuilleTrois = 0;
        RangeeTroisQuilleUne = 0;
        RangeeTroisQuilleDeux = 0;
        RangeeQuatreQuilleUne = 0;
        Joueur2 = 0;
        AfficherMenu();
    } 
    else if (P5.x <= 1130 && P5.x >= 970 && P5.y <= 700 && P5.y >= 540)
    {
        if (!Joueur2)
        {
        CouleurBoule = alea_int(6);
        while (CouleurBoule == CouleurBouleJoueur2)
        {
            CouleurBoule = alea_int(6);
        }
        }
        else
        {
        CouleurBouleJoueur2 = alea_int(6);
        while (CouleurBoule == CouleurBouleJoueur2)
        {
            CouleurBouleJoueur2 = alea_int(6);
        }   
        }
        boule(1050,620,80);
        ActualiserData();
    }  
    else if (P5.x <= 1200 && P5.x >= 1130 && P5.y <= 710 && P5.y >= 550)
    {
        Joueur2 = 1;
        if (!Joueur2)
        {
        CouleurBoule = alea_int(6);
        while (CouleurBoule == CouleurBouleJoueur2)
        {
            CouleurBoule = alea_int(6);
        }
        }
        else
        {
        CouleurBouleJoueur2 = alea_int(6);
        while (CouleurBoule == CouleurBouleJoueur2)
        {
            CouleurBouleJoueur2 = alea_int(6);
        }   
        }
        boule(1120,630,80);
        Joueur2 = 0;
        boule(1050,620,80);
        ActualiserData();
    }  
    else if (P5.x <= 145 && P5.x >= 5 && P5.y <= 990 && P5.y >= 940)
    {
    attendre(100);
    EcranPrincipal = 0;
    initEcranPrincipal = 0;
    EcranCredits = 1;
    } 
    }
}
while (EcranBot)
{
    if (!initEcranBot)
    {
    fill_screen(black);
    POINT p1, p2, p3;
    p1.x = 50; p1.y = 500;
    p2.x = 1350; p2.y = 500;
    p3.x = 200; p3.y = 800;
    draw_fill_triangle(p1,p3,p2, burlywood);
    p1.x = 1350; p1.y = 500;
    p2.x = 1200; p2.y = 800;
    p3.x = 200; p3.y = 800;
    draw_fill_triangle(p1,p3,p2, burlywood);
    p1.x = 5; p1.y = 940;
    p2.x = 145; p2.y = 990;
    draw_fill_rectangle(p1,p2,lightslategray);
    char *Menu = "RETOUR";
    p1.x = 30; 
    p1.y = 980;
    aff_pol(Menu,22,p1,white);
    POINT T1,T2;
    char *Titre = "BOWLING";
    char *Adversaire = "JOUEUR";
    char *Bot = "ORDINATEUR";
    char *MenuTitre2 = "TYPE D'ADVERSAIRE - 2 joueurs";
    char *Type = "CONTRE QUI VOULEZ-VOUS JOUER ?";
    T1.x = 175; 
    T1.y = 29*hauteur_texte(Titre,20);
    T2.x = 180; 
    T2.y = 28.9*hauteur_texte(Titre,20);
    aff_pol(Titre,150,T2,black);
    aff_pol(Titre,150,T1,white);
    T1.x = 215; 
    T1.y = 22.5*hauteur_texte(Titre,20);
    T2.x = 217.5; 
    T2.y = 22.45*hauteur_texte(Titre,20);
    aff_pol(MenuTitre2,45,T2,black);
    aff_pol(MenuTitre2,45,T1,white);
    GrosseQuille(1200,600);
    p1.x = 1050; p1.y = 590;
    draw_fill_circle(p1,60, peru);
    p1.x = 1120; p1.y = 600;
    draw_fill_circle(p1,60, peru);
    Joueur2 = 1;
    boule(1120,630,80);
    Joueur2 = 0;
    boule(1050,620,80);
    T1.x = 325; 
    T1.y = 375;
    aff_pol(Type,40,T1,white);
    p1.x = 750; p1.y = 100;
    p2.x = 1100; p2.y = 200;
    draw_fill_rectangle(p1,p2,burlywood);
    draw_rectangle(p1,p2,blanc);
    p1.x = 300; p1.y = 100;
    p2.x = 650; p2.y = 200;
    draw_fill_rectangle(p1,p2,burlywood);
    draw_rectangle(p1,p2,blanc);
    T1.x = 795;  
    T1.y = 175;
    aff_pol(Bot,40,T1,white);
    T1.x = 400;  
    T1.y = 175;
    aff_pol(Adversaire,40,T1,white);
    initEcranBot = 1;
    }
    POINT P5;
    P5 = get_clic();
    if (P5.x <= 1100 && P5.x >= 750 && P5.y <= 200 && P5.y >= 100)
    {
        attendre(100);
        EcranBot = 0;
        initEcranBot = 0;
        Multijoueur = 1;
        Joueur2 = 0;
        Ordinateur = 1;
        ChargementInit();
        PartieEnCours = 1;
        AfficherScore();
        P11.x = -1;
        P11.y = -1;
        ISpressed = 0;
    }
    else if (P5.x <= 650 && P5.x >= 300 && P5.y <= 200 && P5.y >= 100)
    {
        attendre(100);
        EcranBot = 0;
        initEcranBot = 0;
        Multijoueur = 1;
        Joueur2 = 0;
        ChargementInit();
        PartieEnCours = 1;
        AfficherScore();
        P11.x = -1;
        P11.y = -1;
        ISpressed = 0;
    }
    else if (P5.x <= 1130 && P5.x >= 970 && P5.y <= 700 && P5.y >= 540)
    {
        if (!Joueur2)
        {
        CouleurBoule = alea_int(6);
        while (CouleurBoule == CouleurBouleJoueur2)
        {
            CouleurBoule = alea_int(6);
        }
        }
        else
        {
        CouleurBouleJoueur2 = alea_int(6);
        while (CouleurBoule == CouleurBouleJoueur2)
        {
            CouleurBouleJoueur2 = alea_int(6);
        }   
        }
        boule(1050,620,80);
        ActualiserData();
    } 
    else if (P5.x <= 1200 && P5.x >= 1130 && P5.y <= 710 && P5.y >= 550)
    {
        Joueur2 = 1;
        if (!Joueur2)
        {
        CouleurBoule = alea_int(6);
        while (CouleurBoule == CouleurBouleJoueur2)
        {
            CouleurBoule = alea_int(6);
        }
        }
        else
        {
        CouleurBouleJoueur2 = alea_int(6);
        while (CouleurBoule == CouleurBouleJoueur2)
        {
            CouleurBouleJoueur2 = alea_int(6);
        }   
        }
        boule(1120,630,80);
        Joueur2 = 0;
        boule(1050,620,80);
        ActualiserData();
    } 
    else if (P5.x <= 145 && P5.x >= 5 && P5.y <= 990 && P5.y >= 940)
    {
    attendre(100);
    EcranBot = 0;
    initEcranBot = 0;
    EcranPrincipal = 1;
    AfficherMenu();
    } 
}
while (EcranCredits)
{
    if (!initEcranCredits)
    {
    fill_screen(black);
    POINT p1, p2, p3;
    p1.x = 50; p1.y = 500;
    p2.x = 1350; p2.y = 500;
    p3.x = 200; p3.y = 800;
    draw_fill_triangle(p1,p3,p2, burlywood);
    p1.x = 1350; p1.y = 500;
    p2.x = 1200; p2.y = 800;
    p3.x = 200; p3.y = 800;
    draw_fill_triangle(p1,p3,p2, burlywood);
    p1.x = 5; p1.y = 940;
    p2.x = 145; p2.y = 990;
    draw_fill_rectangle(p1,p2,lightslategray);
    char *Menu = "RETOUR";
    p1.x = 30; 
    p1.y = 980;
    aff_pol(Menu,22,p1,white);
    POINT T1,T2;
    char *Titre = "BOWLING";
    char *Liste = "Aurelien HEMIDY, Theophile MOLINATTI et Thomas MOREAUX";
    char *MenuTitre2 = "CREDITS";
    char *Type = "JEU IMAGINE ET DEVELOPPE PAR :";
    T1.x = 175; 
    T1.y = 29*hauteur_texte(Titre,20);
    T2.x = 180; 
    T2.y = 28.9*hauteur_texte(Titre,20);
    aff_pol(Titre,150,T2,black);
    aff_pol(Titre,150,T1,white);
    T1.x = 215; 
    T1.y = 22.5*hauteur_texte(Titre,20);
    T2.x = 217.5; 
    T2.y = 22.45*hauteur_texte(Titre,20);
    aff_pol(MenuTitre2,45,T2,black);
    aff_pol(MenuTitre2,45,T1,white);
    GrosseQuille(1200,600);
    if (Multijoueur)
    {
    p1.x = 1050; p1.y = 590;
    draw_fill_circle(p1,60, peru);
    p1.x = 1120; p1.y = 600;
    draw_fill_circle(p1,60, peru);
    Joueur2 = 1;
    boule(1120,630,80);
    Joueur2 = 0;
    boule(1050,620,80);
    }
    else
    {
    p1.x = 1050; p1.y = 590;
    draw_fill_circle(p1,60, peru);
    boule(1050,620,80);
    }
    T1.x = 325; 
    T1.y = 375;
    aff_pol(Type,40,T1,white);
    T1.x = 80;  
    T1.y = 275;
    aff_pol(Liste,40,T1,white);
    initEcranCredits = 1;
    }
    POINT P5;
    P5 = get_clic();
    if (P5.x <= 1130 && P5.x >= 970 && P5.y <= 700 && P5.y >= 540)
    {
        if (!Joueur2)
        {
        CouleurBoule = alea_int(6);
        while (CouleurBoule == CouleurBouleJoueur2)
        {
            CouleurBoule = alea_int(6);
        }
        }
        else
        {
        CouleurBouleJoueur2 = alea_int(6);
        while (CouleurBoule == CouleurBouleJoueur2)
        {
            CouleurBouleJoueur2 = alea_int(6);
        }   
        }
        boule(1050,620,80);
        ActualiserData();
    } 
    else if (P5.x <= 1200 && P5.x >= 1130 && P5.y <= 710 && P5.y >= 550 && Multijoueur)
    {
        Joueur2 = 1;
        if (!Joueur2)
        {
        CouleurBoule = alea_int(6);
        while (CouleurBoule == CouleurBouleJoueur2)
        {
            CouleurBoule = alea_int(6);
        }
        }
        else
        {
        CouleurBouleJoueur2 = alea_int(6);
        while (CouleurBoule == CouleurBouleJoueur2)
        {
            CouleurBouleJoueur2 = alea_int(6);
        }   
        }
        boule(1120,630,80);
        Joueur2 = 0;
        boule(1050,620,80);
        ActualiserData();
    } 
    else if (P5.x <= 145 && P5.x >= 5 && P5.y <= 990 && P5.y >= 940)
    {
    attendre(100);
    EcranCredits = 0;
    initEcranCredits = 0;
    EcranPrincipal = 1;
    AfficherMenu();
    }
} 
while (EcranParametres)
{
    if (!initEcranParametres)
    {
    fill_screen(black);
    POINT p1, p2, p3;
    p1.x = 50; p1.y = 500;
    p2.x = 1350; p2.y = 500;
    p3.x = 200; p3.y = 800;
    draw_fill_triangle(p1,p3,p2, burlywood);
    p1.x = 1350; p1.y = 500;
    p2.x = 1200; p2.y = 800;
    p3.x = 200; p3.y = 800;
    draw_fill_triangle(p1,p3,p2, burlywood);
    p1.x = 5; p1.y = 940;
    p2.x = 145; p2.y = 990;
    draw_fill_rectangle(p1,p2,lightslategray);
    char *Menu = "RETOUR";
    p1.x = 30; 
    p1.y = 980;
    aff_pol(Menu,22,p1,white);
    POINT T1,T2;
    char *Titre = "BOWLING";
    char *MenuTitre2 = "PARAMETRES";
    char *Par1 = "COULEUR DU JOUEUR 1";
    char *Par2 = "COULEUR DU JOUEUR 2";
    char *Par3 = "VITESSE DE LA FLECHE";
    char *Par4 = "NIVEAU DE L'ORDINATEUR";
    char *ParFleche1 = "LENTE";
    char *ParFleche2 = "MOYENNE";
    char *ParFleche3 = "RAPIDE";
    char *ParBot1 = "DEBUTANT";
    char *ParBot2 = "AMATEUR";
    char *ParBot3 = "PRO";
    char *ParCouleur0 = "BLEU";
    char *ParCouleur1 = "VERT";
    char *ParCouleur2 = "ORANGE";
    char *ParCouleur3 = "ROSE";
    char *ParCouleur4 = "VIOLET";
    char *ParCouleur5 = "ROUGE";
    T1.x = 175; 
    T1.y = 29*hauteur_texte(Titre,20);
    T2.x = 180; 
    T2.y = 28.9*hauteur_texte(Titre,20);
    aff_pol(Titre,150,T2,black);
    aff_pol(Titre,150,T1,white);
    T1.x = 215; 
    T1.y = 22.5*hauteur_texte(Titre,20);
    T2.x = 217.5; 
    T2.y = 22.45*hauteur_texte(Titre,20);
    aff_pol(MenuTitre2,45,T2,black);
    aff_pol(MenuTitre2,45,T1,white);
    GrosseQuille(1200,600);
    if (Multijoueur)
    {
    p1.x = 1050; p1.y = 590;
    draw_fill_circle(p1,60, peru);
    p1.x = 1120; p1.y = 600;
    draw_fill_circle(p1,60, peru);
    Joueur2 = 1;
    boule(1120,630,80);
    Joueur2 = 0;
    boule(1050,620,80);
    }
    else
    {
    p1.x = 1050; p1.y = 590;
    draw_fill_circle(p1,60, peru);
    boule(1050,620,80);
    }
    p1.x = 750; p1.y = 100;
    p2.x = 1100; p2.y = 200;
    draw_fill_rectangle(p1,p2,burlywood);
    draw_rectangle(p1,p2,blanc);
    p1.x = 300; p1.y = 100;
    p2.x = 650; p2.y = 200;
    draw_fill_rectangle(p1,p2,burlywood);
    draw_rectangle(p1,p2,blanc);
    p1.x = 300; p1.y = 300;
    p2.x = 650; p2.y = 400;
    draw_fill_rectangle(p1,p2,burlywood);
    draw_rectangle(p1,p2,blanc);
    p1.x = 750; p1.y = 300;
    p2.x = 1100; p2.y = 400;
    draw_fill_rectangle(p1,p2,burlywood);
    draw_rectangle(p1,p2,blanc);
    T1.x = 310;  
    T1.y = 455;
    aff_pol(Par1,27,T1,white);
    T1.x = 760;  
    T1.y = 455;
    aff_pol(Par2,27,T1,white);
    T1.x = 315;  
    T1.y = 255;
    aff_pol(Par3,27,T1,white);
    T1.x = 745;  
    T1.y = 255;
    aff_pol(Par4,27,T1,white);
    if (CouleurBoule == 0)
    {
    T1.x = 420;  
    T1.y = 375;
    aff_pol(ParCouleur0,40,T1,blue);
    }
    else if (CouleurBoule == 1)
    {
    T1.x = 420;  
    T1.y = 375;
    aff_pol(ParCouleur1,40,T1,green);
    }
    else if (CouleurBoule == 2)
    {
    T1.x = 400;  
    T1.y = 375;
    aff_pol(ParCouleur2,40,T1,orange);
    }
    else if (CouleurBoule == 3)
    {
    T1.x = 420;  
    T1.y = 375;
    aff_pol(ParCouleur3,40,T1,pink);
    }
    else if (CouleurBoule == 4)
    {
    T1.x = 410;  
    T1.y = 375;
    aff_pol(ParCouleur4,40,T1,violet);
    }
    else if (CouleurBoule == 5)
    {
    T1.x = 410;  
    T1.y = 375;
    aff_pol(ParCouleur5,40,T1,red);
    }
    if (CouleurBouleJoueur2 == 0)
    {
    T1.x = 870;  
    T1.y = 375;
    aff_pol(ParCouleur0,40,T1,blue);
    }
    else if (CouleurBouleJoueur2 == 1)
    {
    T1.x = 870;  
    T1.y = 375;
    aff_pol(ParCouleur1,40,T1,green);
    }
    else if (CouleurBouleJoueur2 == 2)
    {
    T1.x = 850;  
    T1.y = 375;
    aff_pol(ParCouleur2,40,T1,orange);
    }
    else if (CouleurBouleJoueur2 == 3)
    {
    T1.x = 870;  
    T1.y = 375;
    aff_pol(ParCouleur3,40,T1,pink);
    }
    else if (CouleurBouleJoueur2 == 4)
    {
    T1.x = 860;  
    T1.y = 375;
    aff_pol(ParCouleur4,40,T1,violet);
    }
    else if (CouleurBouleJoueur2 == 5)
    {
    T1.x = 860;  
    T1.y = 375;
    aff_pol(ParCouleur5,40,T1,red);
    }
    if (Diff == 1)
    {
        T1.x = 415;  
        T1.y = 175;
        aff_pol(ParFleche1,40,T1,green);
    }
    else if (Diff == 2)
    {
        T1.x = 380;  
        T1.y = 175;
        aff_pol(ParFleche2,40,T1,darkorange);
    }
    else if (Diff == 3)
    {
        T1.x = 405;  
        T1.y = 175;
        aff_pol(ParFleche3,40,T1,red);
    }
    if (DiffBot == 1)
    {
        T1.x = 820;  
        T1.y = 175;
        aff_pol(ParBot1,40,T1,green);
    }
    else if (DiffBot == 2)
    {
        T1.x = 830;  
        T1.y = 175;
        aff_pol(ParBot2,40,T1,darkorange);
    }
    else if (DiffBot == 3)
    {
        T1.x = 885;  
        T1.y = 175;
        aff_pol(ParBot3,40,T1,red);
    }
    initEcranParametres = 1;
    }
    POINT P5;
    P5 = get_clic();
    if (P5.x <= 1100 && P5.x >= 750 && P5.y <= 200 && P5.y >= 100)
    {
        attendre(100);
        char *ParBot1 = "DEBUTANT";
        char *ParBot2 = "AMATEUR";
        char *ParBot3 = "PRO";
        POINT T1,p1,p2;
        if (DiffBot == 2)
        {
            p1.x = 750; p1.y = 100;
            p2.x = 1100; p2.y = 200;
            draw_fill_rectangle(p1,p2,burlywood);
            draw_rectangle(p1,p2,blanc);
            T1.x = 885;  
            T1.y = 175;
            aff_pol(ParBot3,40,T1,red);
            DiffBot = 3;
        }
        else if (DiffBot == 3)
        {
            p1.x = 750; p1.y = 100;
            p2.x = 1100; p2.y = 200;
            draw_fill_rectangle(p1,p2,burlywood);
            draw_rectangle(p1,p2,blanc);
            T1.x = 820;  
            T1.y = 175;
            aff_pol(ParBot1,40,T1,green);
            DiffBot = 1;
        }
        else if (DiffBot == 1)
        {
            p1.x = 750; p1.y = 100;
            p2.x = 1100; p2.y = 200;
            draw_fill_rectangle(p1,p2,burlywood);
            draw_rectangle(p1,p2,blanc);
            T1.x = 830;  
            T1.y = 175;
            aff_pol(ParBot2,40,T1,darkorange);
            DiffBot = 2;
        }
        ActualiserData();
    }   
    else if (P5.x <= 650 && P5.x >= 300 && P5.y <= 400 && P5.y >= 300)
    {
        attendre(100);
        char *ParCouleur0 = "BLEU";
        char *ParCouleur1 = "VERT";
        char *ParCouleur2 = "ORANGE";
        char *ParCouleur3 = "ROSE";
        char *ParCouleur4 = "VIOLET";
        char *ParCouleur5 = "ROUGE";
        POINT T1,p1,p2;
        CouleurBoule = alea_int(6);
        while (CouleurBoule == CouleurBouleJoueur2)
        {
            CouleurBoule = alea_int(6);
        }
        boule(1050,620,80);
        p1.x = 300; p1.y = 300;
        p2.x = 650; p2.y = 400;
        draw_fill_rectangle(p1,p2,burlywood);
        draw_rectangle(p1,p2,blanc);
        if (CouleurBoule == 0)
        {
        T1.x = 420;  
        T1.y = 375;
        aff_pol(ParCouleur0,40,T1,blue);
        }
        else if (CouleurBoule == 1)
        {
        T1.x = 420;  
        T1.y = 375;
        aff_pol(ParCouleur1,40,T1,green);
        }
        else if (CouleurBoule == 2)
        {
        T1.x = 400;  
        T1.y = 375;
        aff_pol(ParCouleur2,40,T1,orange);
        }
        else if (CouleurBoule == 3)
        {
        T1.x = 420;  
        T1.y = 375;
        aff_pol(ParCouleur3,40,T1,pink);
        }
        else if (CouleurBoule == 4)
        {
        T1.x = 410;  
        T1.y = 375;
        aff_pol(ParCouleur4,40,T1,violet);
        }
        else if (CouleurBoule == 5)
        {
        T1.x = 410;  
        T1.y = 375;
        aff_pol(ParCouleur5,40,T1,red);
        }
        ActualiserData();
         
    }    
    else if (P5.x <= 1100 && P5.x >= 750 && P5.y <= 400 && P5.y >= 300)
    {
        attendre(100);
        char *ParCouleur0 = "BLEU";
        char *ParCouleur1 = "VERT";
        char *ParCouleur2 = "ORANGE";
        char *ParCouleur3 = "ROSE";
        char *ParCouleur4 = "VIOLET";
        char *ParCouleur5 = "ROUGE";
        POINT T1,p1,p2;
        CouleurBouleJoueur2 = alea_int(6);
        while (CouleurBoule == CouleurBouleJoueur2)
        {
            CouleurBouleJoueur2 = alea_int(6);
        }
        Joueur2 = 1;
        boule(1120,630,80);
        Joueur2 = 0;
        boule(1050,620,80);
        p1.x = 750; p1.y = 300;
        p2.x = 1100; p2.y = 400;
        draw_fill_rectangle(p1,p2,burlywood);
        draw_rectangle(p1,p2,blanc);
        if (CouleurBouleJoueur2 == 0)
        {
        T1.x = 870;  
        T1.y = 375;
        aff_pol(ParCouleur0,40,T1,blue);
        }
        else if (CouleurBouleJoueur2 == 1)
        {
        T1.x = 870;  
        T1.y = 375;
        aff_pol(ParCouleur1,40,T1,green);
        }
        else if (CouleurBouleJoueur2 == 2)
        {
        T1.x = 850;  
        T1.y = 375;
        aff_pol(ParCouleur2,40,T1,orange);
        }
        else if (CouleurBouleJoueur2 == 3)
        {
        T1.x = 870;  
        T1.y = 375;
        aff_pol(ParCouleur3,40,T1,pink);
        }
        else if (CouleurBouleJoueur2 == 4)
        {
        T1.x = 860;  
        T1.y = 375;
        aff_pol(ParCouleur4,40,T1,violet);
        }
        else if (CouleurBouleJoueur2 == 5)
        {
        T1.x = 860;  
        T1.y = 375;
        aff_pol(ParCouleur5,40,T1,red);
        }
        ActualiserData();
         
    } 
    else if (P5.x <= 650 && P5.x >= 300 && P5.y <= 200 && P5.y >= 100)
    {
        attendre(100);
        char *ParFleche1 = "LENTE";
        char *ParFleche2 = "MOYENNE";
        char *ParFleche3 = "RAPIDE";
        POINT T1,p1,p2;
        if (Diff == 2)
        {
            p1.x = 300; p1.y = 100;
            p2.x = 650; p2.y = 200;
            draw_fill_rectangle(p1,p2,burlywood);
            draw_rectangle(p1,p2,blanc);
            T1.x = 405;  
            T1.y = 175;
            aff_pol(ParFleche3,40,T1,red);
            Diff = 3;
        }
        else if (Diff == 3)
        {
            p1.x = 300; p1.y = 100;
            p2.x = 650; p2.y = 200;
            draw_fill_rectangle(p1,p2,burlywood);
            draw_rectangle(p1,p2,blanc);
            T1.x = 415;  
            T1.y = 175;
            aff_pol(ParFleche1,40,T1,green);
            Diff = 1;
        }
        else if (Diff == 1)
        {
            p1.x = 300; p1.y = 100;
            p2.x = 650; p2.y = 200;
            draw_fill_rectangle(p1,p2,burlywood);
            draw_rectangle(p1,p2,blanc);
            T1.x = 380;  
            T1.y = 175;
            aff_pol(ParFleche2,40,T1,darkorange);
            Diff = 2;
        }
        ActualiserData();
    }
    else if (P5.x <= 145 && P5.x >= 5 && P5.y <= 990 && P5.y >= 940)
    {
    attendre(100);
    EcranParametres = 0;
    initEcranParametres = 0;
    EcranPrincipal = 1;
    AfficherMenu();
    } 
}       
}
 
// Score de fin 
  
void AfficherScoreFin()
{
while (EcranScore)
{
    if (!initEcranScore)
    {
    fill_screen(black);
    POINT p1, p2, p3;
    if (!Multijoueur)
    {
    p1.x = 200; p1.y = 500;
    p2.x = 1200; p2.y = 500;
    p3.x = 350; p3.y = 800;
    draw_fill_triangle(p1,p3,p2, burlywood);
    p1.x = 1200; p1.y = 500;
    p2.x = 1050; p2.y = 800;
    p3.x = 350; p3.y = 800;
    draw_fill_triangle(p1,p3,p2, burlywood);        
    }
    else
    {
    p1.x = 50; p1.y = 500;
    p2.x = 1350; p2.y = 500;
    p3.x = 200; p3.y = 800;
    draw_fill_triangle(p1,p3,p2, burlywood);
    p1.x = 1350; p1.y = 500;
    p2.x = 1200; p2.y = 800;
    p3.x = 200; p3.y = 800;
    draw_fill_triangle(p1,p3,p2, burlywood);        
    }
    POINT T1,T2;
    char *Titre = "BOWLING";
    char *Continuer = "CONTINUER";
    char *Quitter = "QUITTER";
    char *MenuTitre2 = "SCORE FINAL";
    char *MeilleurScore = "MEILLEUR SCORE :";
    char *NewMeilleurScore = "! NOUVEAU MEILLEUR SCORE !";
    char *SeparationScore = "-";
    char *Joueur1 = "J1";
    char *JoueurDeux = "J2";
    char *J1GAGNE = "JOUEUR 1 GAGNE LA PARTIE";
    char *J2GAGNE = "JOUEUR 2 GAGNE LA PARTIE";
    char *EGALITE = "MATCH NUL";
    if (!Multijoueur)
    {
    T1.x = 420; 
    T1.y = 29*hauteur_texte(Titre,20);
    T2.x = 425; 
    T2.y = 28.9*hauteur_texte(Titre,20);
    aff_int(Score,150,T2,black);
    aff_int(Score,150,T1,white);
    GrosseQuille(975,600);
    p1.x = 825; p1.y = 590;
    draw_fill_circle(p1,60, peru);
    boule(825,620,80);
    p1.x = 750; p1.y = 100;
    p2.x = 1100; p2.y = 200;
    draw_fill_rectangle(p1,p2,peru);
    draw_rectangle(p1,p2,blanc);
    p1.x = 300; p1.y = 100;
    p2.x = 650; p2.y = 200;
    draw_fill_rectangle(p1,p2,burlywood);
    draw_rectangle(p1,p2,blanc);
    T1.x = 415; 
    T1.y = 22.5*hauteur_texte(Titre,20);
    T2.x = 417.5; 
    T2.y = 22.45*hauteur_texte(Titre,20);
    aff_pol(MenuTitre2,45,T2,black);
    aff_pol(MenuTitre2,45,T1,white);
    T1.x = 835;  
    T1.y = 175;
    aff_pol(Quitter,40,T1,white);
    T1.x = 355;  
    T1.y = 175;
    aff_pol(Continuer,40,T1,white);
    }
    else
    {
    p1.x = 1050; p1.y = 590;
    draw_fill_circle(p1,60, peru);
    p1.x = 1120; p1.y = 600;
    draw_fill_circle(p1,60, peru);
    T1.x = 190; 
    T1.y = 29*hauteur_texte(Titre,20);
    T2.x = 195; 
    T2.y = 28.9*hauteur_texte(Titre,20);
    aff_int(Score,150,T2,black);
    aff_int(Score,150,T1,white);
    T2.x = 155; 
    T2.y = 24.3*hauteur_texte(Titre,20);
    if (CouleurBoule == 0)
    {
    aff_pol(Joueur1,35,T2,blue);
    }
    else if (CouleurBoule == 1)
    {
    aff_pol(Joueur1,35,T2,vert);
    }
    else if (CouleurBoule == 2)
    {
    aff_pol(Joueur1,35,T2,orange);
    }
    else if (CouleurBoule == 3)
    {
    aff_pol(Joueur1,35,T2,pink);
    }
    else if (CouleurBoule == 4)
    {
    aff_pol(Joueur1,35,T2,violet);
    }
    else if (CouleurBoule == 5)
    {
    aff_pol(Joueur1,35,T2,red);
    }
    T1.x = 500; 
    T1.y = 29*hauteur_texte(Titre,20);
    T2.x = 505; 
    T2.y = 28.9*hauteur_texte(Titre,20);
    aff_pol(SeparationScore,150,T2,black);
    aff_pol(SeparationScore,150,T1,white);
    T1.x = 610; 
    T1.y = 29*hauteur_texte(Titre,20);
    T2.x = 615; 
    T2.y = 28.9*hauteur_texte(Titre,20);
    aff_int(ScoreJoueur2,150,T2,black);
    aff_int(ScoreJoueur2,150,T1,white);
    T2.x = 575; 
    T2.y = 24.3*hauteur_texte(Titre,20);
    if (CouleurBouleJoueur2 == 0)
    {
    aff_pol(JoueurDeux,35,T2,blue);
    }
    else if (CouleurBouleJoueur2 == 1)
    {
    aff_pol(JoueurDeux,35,T2,vert);
    }
    else if (CouleurBouleJoueur2 == 2)
    {
    aff_pol(JoueurDeux,35,T2,orange);
    }
    else if (CouleurBouleJoueur2 == 3)
    {
    aff_pol(JoueurDeux,35,T2,pink);
    }
    else if (CouleurBouleJoueur2 == 4)
    {
    aff_pol(JoueurDeux,35,T2,violet);
    }
    else if (CouleurBouleJoueur2 == 5)
    {
    aff_pol(JoueurDeux,35,T2,red);
    }
        if (Score < ScoreJoueur2)
        {
            Joueur2 = 1;
            T1.x = 215; 
            T1.y = 22.5*hauteur_texte(Titre,20);
            T2.x = 217.5; 
            T2.y = 22.45*hauteur_texte(Titre,20);
            aff_pol(J2GAGNE,45,T2,black);
            aff_pol(J2GAGNE,45,T1,white);
        }
        else if (Score > ScoreJoueur2)
        {
            T1.x = 215; 
            T1.y = 22.5*hauteur_texte(Titre,20);
            T2.x = 217.5; 
            T2.y = 22.45*hauteur_texte(Titre,20);
            aff_pol(J1GAGNE,45,T2,black);
            aff_pol(J1GAGNE,45,T1,white);
        }
        else if (Score == ScoreJoueur2)
        {
            T1.x = 215; 
            T1.y = 22.5*hauteur_texte(Titre,20);
            T2.x = 217.5; 
            T2.y = 22.45*hauteur_texte(Titre,20);
            aff_pol(EGALITE,45,T2,black);
            aff_pol(EGALITE,45,T1,white);
        }
    GrosseQuille(1200,600);
    if (Joueur2 == 1)
    {
    Joueur2 = 0;
    boule(1120,630,80);
    Joueur2 = 1;
    boule(1050,620,80);
    }
    else
    {
    Joueur2 =1;
    boule(1120,630,80);
    Joueur2 = 0;
    boule(1050,620,80);
    }
    p1.x = 1050; p1.y = 590;
    draw_fill_circle(p1,60, peru);
    boule(1050,620,80);
    p1.x = 750; p1.y = 100;
    p2.x = 1100; p2.y = 200;
    draw_fill_rectangle(p1,p2,peru);
    draw_rectangle(p1,p2,blanc);
    p1.x = 300; p1.y = 100;
    p2.x = 650; p2.y = 200;
    draw_fill_rectangle(p1,p2,burlywood);
    draw_rectangle(p1,p2,blanc);
    T1.x = 835;  
    T1.y = 175;
    aff_pol(Quitter,40,T1,white);
    T1.x = 355;  
    T1.y = 175;
    aff_pol(Continuer,40,T1,white);
    }
    if (Score > BestScore || ScoreJoueur2 > BestScore)
    {
        if (ScoreJoueur2 < Score)
        {
        BestScore = Score;
        }
        else
        {
        BestScore = ScoreJoueur2;
        }
        ActualiserData();
        T1.x = 400; 
        T1.y = 375;
        aff_pol(NewMeilleurScore,40,T1,white);
    }
    else
    {
        T1.x = 460; 
        T1.y = 375;
        aff_pol(MeilleurScore,40,T1,white);
        T1.x = 860; 
        T1.y = 375;
        aff_int(BestScore,40,T1,white);
    }
    initEcranScore = 1;
    }
    POINT P5;
    P5 = get_clic();
    if (P5.x <= 1100 && P5.x >= 750 && P5.y <= 200 && P5.y >= 100)
    {
        attendre(100);
        exit(0);
    }
    else if (P5.x <= 650 && P5.x >= 300 && P5.y <= 200 && P5.y >= 100)
    {
        attendre(100);
        EcranPrincipal = 1;
        EcranScore = 0;
        initBouton = 0;
        initEcranPrincipal = 0;
        ISpressed = 1;
        PartieEnCours = 0;
        NbJeu = 1;
        NbLancer = 1;
        StrikeSpare = 0;
        StrikeSpareJoueur2 = 0;
        Score = 0;
        ScoreJoueur2 = 0;
        Ordinateur = 0;
        Multijoueur = 0;
        RangeeUneQuilleUne = 0;
        RangeeUneQuilleDeux = 0;
        RangeeUneQuilleTrois = 0;
        RangeeUneQuilleQuatre = 0;
        RangeeDeuxQuilleUne = 0;
        RangeeDeuxQuilleDeux = 0;
        RangeeDeuxQuilleTrois = 0;
        RangeeTroisQuilleUne = 0;
        RangeeTroisQuilleDeux = 0;
        RangeeQuatreQuilleUne = 0;
        Joueur2 = 0;
        initEcranScore = 0;
        AfficherMenu();
    }
}   
}
 
//bouton menu
  
void boutonMenu()
{
if (!initBouton)
{
POINT p1, p2;
p1.x = 5; p1.y = 940;
p2.x = 145; p2.y = 990;
draw_fill_rectangle(p1,p2,navajowhite);
char *Menu = "MENU";
p1.x = 35; 
p1.y = 983;
aff_pol(Menu,27,p1,lightslategray);
initBouton = 1;
}
if (P11.x <= 145 && P11.x >= 5 && P11.y <= 990 && P11.y >= 940)
{
    ISpressed = 1;
    attendre(100);
    EcranPrincipal = 1;
    AfficherMenu();
}
} 
  
 //fleche 
void flecheopti(int x, int y)
{
  
    int by, alle, compteur;
      
    if (!Joueur2 || !Ordinateur)
    {
    alle = 1;
    bx = 690;
    ISpressed = 0;
    P11.x = -1;
    P11.y = -1;
    }
  
    POINT P1, P2;
    OmbreBoule();
  
    while (alle == 1)
    {
        for (compteur = 0 ; compteur < 20 ; compteur++)
        {
            bx = bx - 10;
            by = y + 150;
            P1.x = x; P1.y = y;
            P2.x = bx; P2.y = by;
            draw_line(P1, P2, black);
            boule(600, 40, 40);
            if (Diff == 1)
            {
                attendre(225);
            }
            else if (Diff == 2)
            {
                attendre(75);
            }
            else if (Diff == 3)
            {
                attendre(25);
            }
            P1.x = x; P1.y = y;
            P2.x = bx; P2.y = by;
            draw_line(P1, P2, burlywood);
            boule(600, 40, 40);
            P11 = get_clic();
            if (!Joueur2 || !Ordinateur)
            {
            boutonMenu();
            }
            if (P11.x != -1 && P11.y != -1 && ISpressed != 1 && EcranPrincipal != 1)
            {
                getBX = bx;
                getX = x;
                ISpressed = 1;
            }
            if (ISpressed == 1)
            {
                if (getBX != getX)
                {
                coefD = (by-y)/(getBX-x);
                k = -coefD*x+y;
                grandX = 370-k;
                tX = grandX/coefD;
                P1.x = x; P1.y = y;
                P2.x = tX; P2.y = 370;
                if (!Joueur2)
                {
                    if (CouleurBoule == 0)
                    {
                    draw_line(P1, P2, blue);
                    }
                    else if (CouleurBoule == 1)
                    {
                    draw_line(P1, P2, green);
                    }
                    else if (CouleurBoule == 2)
                    {
                    draw_line(P1, P2, orange);
                    }
                    else if (CouleurBoule == 3)
                    {
                    draw_line(P1, P2, pink);
                    }
                    else if (CouleurBoule == 4)
                    {
                    draw_line(P1, P2, violet);
                    }
                    else if (CouleurBoule == 5)
                    {
                    draw_line(P1, P2, red);
                    }
                }
                else
                {
                    if (CouleurBouleJoueur2 == 0)
                    {
                    draw_line(P1, P2, blue);
                    }
                    else if (CouleurBouleJoueur2 == 1)
                    {
                    draw_line(P1, P2, green);
                    }
                    else if (CouleurBouleJoueur2 == 2)
                    {
                    draw_line(P1, P2, orange);
                    }
                    else if (CouleurBouleJoueur2 == 3)
                    {
                    draw_line(P1, P2, pink); 
                    }
                    else if (CouleurBouleJoueur2 == 4)
                    {
                    draw_line(P1, P2, violet); 
                    }
                    else if (CouleurBouleJoueur2 == 5)
                    {
                    draw_line(P1, P2, red);
                    }
                }
                compteur = 20;
                }
                else
                {
                P1.x = x; P1.y = y;
                P2.x = getBX; P2.y = 370;
                if (!Joueur2)
                {
                    if (CouleurBoule == 0)
                    {
                    draw_line(P1, P2, blue);
                    }
                    else if (CouleurBoule == 1)
                    {
                    draw_line(P1, P2, green);
                    }
                    else if (CouleurBoule == 2)
                    {
                    draw_line(P1, P2, orange);
                    }
                    else if (CouleurBoule == 3)
                    {
                    draw_line(P1, P2, pink);
                    }
                    else if (CouleurBoule == 4)
                    {
                    draw_line(P1, P2, violet);
                    }
                    else if (CouleurBoule == 5)
                    {
                    draw_line(P1, P2, red);
                    }
                }
                else
                {
                    if (CouleurBouleJoueur2 == 0)
                    {
                    draw_line(P1, P2, blue);
                    }
                    else if (CouleurBouleJoueur2 == 1)
                    {
                    draw_line(P1, P2, green);
                    }
                    else if (CouleurBouleJoueur2 == 2)
                    {
                    draw_line(P1, P2, orange);
                    }
                    else if (CouleurBouleJoueur2 == 3)
                    {
                    draw_line(P1, P2, pink); 
                    }
                    else if (CouleurBouleJoueur2 == 4)
                    {
                    draw_line(P1, P2, violet); 
                    }
                    else if (CouleurBouleJoueur2 == 5)
                    {
                    draw_line(P1, P2, red);
                    }
                }
                compteur = 20;  
                }
            }
        }
        alle = 0;
    }
    while (alle == 0)
    {
        for (compteur = 0 ; compteur < 20 ; compteur++)
        {
            bx = bx + 10;
            by = y + 150;
            P1.x = x; P1.y = y;
            P2.x = bx; P2.y = by;
            draw_line(P1, P2, black);
            boule(600, 40, 40);
            if (Diff == 1)
            {
                attendre(225);
            }
            else if (Diff == 2)
            {
                attendre(75);
            }
            else if (Diff == 3)
            {
                attendre(25);
            }
            P1.x = x; P1.y = y;
            P2.x = bx; P2.y = by;
            draw_line(P1, P2, burlywood);
            boule(600, 40, 40);
            P11 = get_clic();
            if (!Joueur2 || !Ordinateur)
            {
            boutonMenu();
            }
            if (P11.x != -1 && P11.y != -1 && ISpressed != 1 && EcranPrincipal != 1)
            {
                getBX = bx;
                getX = x;
                ISpressed = 1;
            }
            if (ISpressed == 1)
            {
                if (getBX != getX)
                {
                coefD = (by-y)/(getBX-x);
                k = -coefD*x+y;
                grandX = 370-k;
                tX = grandX/coefD;
                P1.x = x; P1.y = y;
                P2.x = tX; P2.y = 370;
                if (!Joueur2)
                {
                    if (CouleurBoule == 0)
                    {
                    draw_line(P1, P2, blue);
                    }
                    else if (CouleurBoule == 1)
                    {
                    draw_line(P1, P2, green);
                    }
                    else if (CouleurBoule == 2)
                    {
                    draw_line(P1, P2, orange);
                    }
                    else if (CouleurBoule == 3)
                    {
                    draw_line(P1, P2, pink);
                    }
                    else if (CouleurBoule == 4)
                    {
                    draw_line(P1, P2, violet);
                    }
                    else if (CouleurBoule == 5)
                    {
                    draw_line(P1, P2, red);
                    }
                }
                else
                {
                    if (CouleurBouleJoueur2 == 0)
                    {
                    draw_line(P1, P2, blue);
                    }
                    else if (CouleurBouleJoueur2 == 1)
                    {
                    draw_line(P1, P2, green);
                    }
                    else if (CouleurBouleJoueur2 == 2)
                    {
                    draw_line(P1, P2, orange);
                    }
                    else if (CouleurBouleJoueur2 == 3)
                    {
                    draw_line(P1, P2, pink); 
                    }
                    else if (CouleurBouleJoueur2 == 4)
                    {
                    draw_line(P1, P2, violet); 
                    }
                    else if (CouleurBouleJoueur2 == 5)
                    {
                    draw_line(P1, P2, red);
                    }
                }
                compteur = 20;
                }
                else
                {
                P1.x = x; P1.y = y;
                P2.x = getBX; P2.y = 370;
                if (!Joueur2)
                {
                    if (CouleurBoule == 0)
                    {
                    draw_line(P1, P2, blue);
                    }
                    else if (CouleurBoule == 1)
                    {
                    draw_line(P1, P2, green);
                    }
                    else if (CouleurBoule == 2)
                    {
                    draw_line(P1, P2, orange);
                    }
                    else if (CouleurBoule == 3)
                    {
                    draw_line(P1, P2, pink);
                    }
                    else if (CouleurBoule == 4)
                    {
                    draw_line(P1, P2, violet);
                    }
                    else if (CouleurBoule == 5)
                    {
                    draw_line(P1, P2, red);
                    }
                }
                else
                {
                    if (CouleurBouleJoueur2 == 0)
                    {
                    draw_line(P1, P2, blue);
                    }
                    else if (CouleurBouleJoueur2 == 1)
                    {
                    draw_line(P1, P2, green);
                    }
                    else if (CouleurBouleJoueur2 == 2)
                    {
                    draw_line(P1, P2, orange);
                    }
                    else if (CouleurBouleJoueur2 == 3)
                    {
                    draw_line(P1, P2, pink); 
                    }
                    else if (CouleurBouleJoueur2 == 4)
                    {
                    draw_line(P1, P2, violet); 
                    }
                    else if (CouleurBouleJoueur2 == 5)
                    {
                    draw_line(P1, P2, red);
                    }
                }
                compteur = 20;  
                }
            }
        }
        alle = 1;
    }
    if (ISpressed == 1)
    {
    attendre(50);
    if (getBX != getX)
    {
    P1.x = x; P1.y = y;
    P2.x = tX; P2.y = 370;
    draw_line(P1, P2, burlywood);
    }
    else
    {
    P1.x = x; P1.y = y;
    P2.x = getBX; P2.y = 370;
    draw_line(P1, P2, burlywood);
    }
    }
    effboule(600, 40);
    SupprOmbreBoule();
}
  
//boule qui part
  
void MouvBoule(int NbSaut)
{
int sautBOULE, compteur;
  
sautBOULE = 40;
 
TrianglePiste(burlywood);
for (compteur = 0 ; compteur < NbSaut ; compteur++)
        {
            sautBOULE = sautBOULE+7;
            grandX = sautBOULE-k;
            tX = grandX/coefD;
            if (getBX != getX)
            {
            boule(tX, sautBOULE, 40);
            attendre(25);
            effboulerayon(tX, sautBOULE, 40);
            }
            else
            {
            boule(getBX, sautBOULE, 40);
            attendre(25);
            effboulerayon(getBX, sautBOULE, 40);    
            }
        }
    TrianglePiste(noir);
}
  
//Le main
  
int main () {  
 EcranPrincipal = 1;
 initBouton = 0;
  
//chargement des parametres enregistrés
  
FILE* fichier = NULL;
  
    fichier = fopen("data.bowling", "r+");
  
    if (fichier != NULL)
    {
        printf("Chargement des données de jeu via data.bowling...\n");
        if (fscanf(fichier, "%d\n%d\n%d\n%d\n%d", &BestScore, &Diff, &DiffBot, &CouleurBoule, &CouleurBouleJoueur2)) {};
        if (BestScore >= 0 && BestScore <= 300 && Diff <=3 && Diff >= 1 && CouleurBoule <= 5 && CouleurBoule >= 0 && CouleurBouleJoueur2 <= 5 && CouleurBouleJoueur2 >= 0 && DiffBot <=3 && DiffBot >= 1)
        {
        printf("Chargement réussi.\n\n");
        }
        else
        {
        Diff = 2;
        DiffBot = 1;
        BestScore = 127;
        CouleurBoule = 0;
        CouleurBouleJoueur2 = 5;
        printf("Erreur lors du chargement, les valeurs par défaut ont été appliquées.\nFichier réinitialisé.\n\n");
        ActualiserData();
        }
        fclose(fichier);
    }
    else
    {
        printf("----------\nATTENTION \n----------\n\nFichier de données data.bowling introuvable !\nCréation du fichier et application des paramètres et meilleur score par défaut. \nLe fichier a bien été crée.\n\n\n");
        Diff = 2;
        DiffBot = 1;
        BestScore = 127;
        CouleurBoule = 0;
        CouleurBouleJoueur2 = 5;
        ActualiserData();
    }
  
//ecran principal de selection
  
init_graphics (1400,1000);
  
AfficherMenu();
  
  //jeu (mouvements) 
PartieEnCours = 1;
NbJeu = 1;
NbLancer = 1;
StrikeSpare = 0;
initEcranPrincipal = 0;
AfficherScore();
 
while (PartieEnCours)
{
if (Ordinateur && Joueur2)
    {
    P11.x = -1;
    P11.y = -1;
    if (DiffBot == 1)
    {
    getBX = alea_int(141)+520;
    }
    else if (DiffBot == 2)
    {
    getBX = alea_int(81)+550;   
    }
    else if (DiffBot == 3)
    {
    getBX = alea_int(26)+590;   
    }
    getX = 600;
    coefD = 150/(getBX-getX);
    k = -coefD*640;
    grandX = 370-k;
    tX = grandX/coefD;
    ISpressed = 1;
    }
 boutonMenu();
 flecheopti(600,40);
if (ISpressed && NbJeu <= 10)
{
if (getBX == getX)
{
    tX = getBX;
}
if (tX <= 460)
{
    MouvBoule(45);
    ScoreLancer = 0;
}
else if (tX > 460 && tX <= 480)
{
    MouvBoule(70);
    if (!RangeeUneQuilleUne)
    {
    RangeeUneQuilleUne = 1;
    ScoreLancer = 1;
    }
    else
    {
    ScoreLancer = 0;
    }
}
else if (tX > 480 && tX <= 500)
{
  MouvBoule(55);
  if (!RangeeUneQuilleUne && !RangeeDeuxQuilleUne)
    {
    RangeeUneQuilleUne = 1;
    RangeeDeuxQuilleUne = 1;
    ScoreLancer = 2;
    }
    else if (!RangeeDeuxQuilleUne && RangeeUneQuilleUne)
    {
    RangeeDeuxQuilleUne = 1;
    ScoreLancer = 1;  
    }
    else
    {
    ScoreLancer = 0;
    }
}
else if (tX > 500 && tX <= 540)
{
  MouvBoule(50);
  if (!RangeeUneQuilleUne && !RangeeUneQuilleDeux && !RangeeDeuxQuilleUne && !RangeeTroisQuilleUne)
  {
  RangeeUneQuilleUne = 1;
  RangeeUneQuilleDeux = 1;
  RangeeDeuxQuilleUne = 1;
  RangeeTroisQuilleUne = 1;
  ScoreLancer = 4;
}
    else if (RangeeUneQuilleUne && !RangeeUneQuilleDeux && !RangeeDeuxQuilleUne && !RangeeTroisQuilleUne)
    {
        RangeeUneQuilleDeux = 1;
        RangeeDeuxQuilleUne = 1;
        RangeeTroisQuilleUne = 1;
        ScoreLancer = 3;
    }
    else if (RangeeUneQuilleUne && !RangeeUneQuilleDeux && RangeeDeuxQuilleUne && !RangeeTroisQuilleUne)
    {
        RangeeUneQuilleDeux = 1;
        RangeeTroisQuilleUne = 1;
        ScoreLancer = 2;
    }
    else
    {
    ScoreLancer = 0;
    }
 
}
else if (tX > 540 && tX <= 590)
{
  MouvBoule(47);
  if (!RangeeUneQuilleUne && !RangeeUneQuilleDeux && !RangeeDeuxQuilleUne && !RangeeDeuxQuilleDeux && !RangeeTroisQuilleUne && !RangeeQuatreQuilleUne)
  {
  RangeeUneQuilleUne = 1;
  RangeeUneQuilleDeux = 1;
  RangeeDeuxQuilleUne = 1;
  RangeeDeuxQuilleDeux = 1;
  RangeeTroisQuilleUne = 1;
  RangeeQuatreQuilleUne = 1;
  ScoreLancer = 6;
}
    else if (RangeeUneQuilleUne && !RangeeUneQuilleDeux && !RangeeDeuxQuilleUne && !RangeeDeuxQuilleDeux && !RangeeTroisQuilleUne && !RangeeQuatreQuilleUne)
    {
        RangeeUneQuilleDeux = 1;
        RangeeDeuxQuilleUne = 1;
        RangeeDeuxQuilleDeux = 1;
        RangeeTroisQuilleUne = 1;
        RangeeQuatreQuilleUne = 1;
        ScoreLancer = 5;
    }
    else if (!RangeeUneQuilleUne && !RangeeUneQuilleDeux && !RangeeDeuxQuilleUne && RangeeDeuxQuilleDeux && !RangeeTroisQuilleUne && RangeeQuatreQuilleUne)
  {
  RangeeUneQuilleUne = 1;
  RangeeUneQuilleDeux = 1;
  RangeeDeuxQuilleUne = 1;
  RangeeTroisQuilleUne = 1;
  ScoreLancer = 4;
    }
    else if (RangeeUneQuilleUne && !RangeeUneQuilleDeux && RangeeDeuxQuilleUne && !RangeeDeuxQuilleDeux && !RangeeTroisQuilleUne && !RangeeQuatreQuilleUne)
    {
        RangeeUneQuilleDeux = 1;
        RangeeDeuxQuilleDeux = 1;
        RangeeTroisQuilleUne = 1;
        RangeeQuatreQuilleUne = 1;
        ScoreLancer = 4;
    }
    else if (RangeeUneQuilleUne && RangeeUneQuilleDeux && RangeeDeuxQuilleUne && !RangeeDeuxQuilleDeux && RangeeTroisQuilleUne && !RangeeQuatreQuilleUne)
    {
        RangeeDeuxQuilleDeux = 1;
        RangeeQuatreQuilleUne = 1;
        ScoreLancer = 2;
    }
    else
    {
    ScoreLancer = 0;
    }
 
}
else if (tX > 590 && tX <= 600)
{
  MouvBoule(47);
  if (!RangeeUneQuilleUne && !RangeeUneQuilleDeux && !RangeeUneQuilleTrois && !RangeeUneQuilleQuatre && !RangeeDeuxQuilleUne && !RangeeDeuxQuilleDeux && !RangeeDeuxQuilleTrois && !RangeeTroisQuilleUne && !RangeeTroisQuilleDeux && !RangeeQuatreQuilleUne)
    {
    RangeeUneQuilleUne = 1;
    RangeeUneQuilleDeux = 1;
    RangeeUneQuilleTrois = 1;
    RangeeUneQuilleQuatre = 1;
    RangeeDeuxQuilleUne = 1;
    RangeeDeuxQuilleDeux = 1;
    RangeeDeuxQuilleTrois = 1;
    RangeeTroisQuilleUne = 1;
    RangeeTroisQuilleDeux = 1;
    RangeeQuatreQuilleUne = 1;
    ScoreLancer = 10;
    }
    else if (RangeeUneQuilleUne && !RangeeUneQuilleDeux && !RangeeUneQuilleTrois && !RangeeUneQuilleQuatre && !RangeeDeuxQuilleUne && !RangeeDeuxQuilleDeux && !RangeeDeuxQuilleTrois && !RangeeTroisQuilleUne && !RangeeTroisQuilleDeux && !RangeeQuatreQuilleUne)
    {
    RangeeUneQuilleDeux = 1;
    RangeeUneQuilleTrois = 1;
    RangeeUneQuilleQuatre = 1;
    RangeeDeuxQuilleUne = 1;
    RangeeDeuxQuilleDeux = 1;
    RangeeDeuxQuilleTrois = 1;
    RangeeTroisQuilleUne = 1;
    RangeeTroisQuilleDeux = 1;
    RangeeQuatreQuilleUne = 1;
    ScoreLancer = 9;
    }
    else if (RangeeUneQuilleUne && !RangeeUneQuilleDeux && !RangeeUneQuilleTrois && !RangeeUneQuilleQuatre && RangeeDeuxQuilleUne && !RangeeDeuxQuilleDeux && !RangeeDeuxQuilleTrois && !RangeeTroisQuilleUne && !RangeeTroisQuilleDeux && !RangeeQuatreQuilleUne)
    {
    RangeeUneQuilleDeux = 1;
    RangeeUneQuilleTrois = 1;
    RangeeUneQuilleQuatre = 1;
    RangeeDeuxQuilleDeux = 1;
    RangeeDeuxQuilleTrois = 1;
    RangeeTroisQuilleUne = 1;
    RangeeTroisQuilleDeux = 1;
    RangeeQuatreQuilleUne = 1;
    ScoreLancer = 8;
    }
    else if (RangeeUneQuilleUne && RangeeUneQuilleDeux && !RangeeUneQuilleTrois && !RangeeUneQuilleQuatre && RangeeDeuxQuilleUne && !RangeeDeuxQuilleDeux && !RangeeDeuxQuilleTrois && RangeeTroisQuilleUne && !RangeeTroisQuilleDeux && !RangeeQuatreQuilleUne)
    {
    RangeeUneQuilleTrois = 1;
    RangeeUneQuilleQuatre = 1;
    RangeeDeuxQuilleDeux = 1;
    RangeeDeuxQuilleTrois = 1;
    RangeeTroisQuilleDeux = 1;
    RangeeQuatreQuilleUne = 1;
    ScoreLancer = 6;
    }
    else if (RangeeUneQuilleUne && RangeeUneQuilleDeux && !RangeeUneQuilleTrois && !RangeeUneQuilleQuatre && RangeeDeuxQuilleUne && RangeeDeuxQuilleDeux && !RangeeDeuxQuilleTrois && RangeeTroisQuilleUne && !RangeeTroisQuilleDeux && RangeeQuatreQuilleUne)
    {
    RangeeUneQuilleTrois = 1;
    RangeeUneQuilleQuatre = 1;
    RangeeDeuxQuilleTrois = 1;
    RangeeTroisQuilleDeux = 1;
    ScoreLancer = 4;
    }
    else if (!RangeeUneQuilleUne && !RangeeUneQuilleDeux && !RangeeUneQuilleTrois && RangeeUneQuilleQuatre && !RangeeDeuxQuilleUne && !RangeeDeuxQuilleDeux && !RangeeDeuxQuilleTrois && !RangeeTroisQuilleUne && !RangeeTroisQuilleDeux && !RangeeQuatreQuilleUne)
    {
    RangeeUneQuilleUne = 1;
    RangeeUneQuilleDeux = 1;
    RangeeUneQuilleTrois = 1;
    RangeeDeuxQuilleUne = 1;
    RangeeDeuxQuilleDeux = 1;
    RangeeDeuxQuilleTrois = 1;
    RangeeTroisQuilleUne = 1;
    RangeeTroisQuilleDeux = 1;
    RangeeQuatreQuilleUne = 1;
    ScoreLancer = 9;
    }
    else if (!RangeeUneQuilleUne && !RangeeUneQuilleDeux && !RangeeUneQuilleTrois && RangeeUneQuilleQuatre && !RangeeDeuxQuilleUne && !RangeeDeuxQuilleDeux && RangeeDeuxQuilleTrois && !RangeeTroisQuilleUne && !RangeeTroisQuilleDeux && !RangeeQuatreQuilleUne)
    {
    RangeeUneQuilleUne = 1;
    RangeeUneQuilleDeux = 1;
    RangeeUneQuilleTrois = 1;
    RangeeDeuxQuilleUne = 1;
    RangeeDeuxQuilleDeux = 1;
    RangeeTroisQuilleUne = 1;
    RangeeTroisQuilleDeux = 1;
    RangeeQuatreQuilleUne = 1;
    ScoreLancer = 8;
    }
    else if (!RangeeUneQuilleUne && !RangeeUneQuilleDeux && RangeeUneQuilleTrois && RangeeUneQuilleQuatre && !RangeeDeuxQuilleUne && !RangeeDeuxQuilleDeux && RangeeDeuxQuilleTrois && !RangeeTroisQuilleUne && RangeeTroisQuilleDeux && !RangeeQuatreQuilleUne)
    {
    RangeeUneQuilleUne = 1;
    RangeeUneQuilleDeux = 1;
    RangeeDeuxQuilleUne = 1;
    RangeeDeuxQuilleDeux = 1;
    RangeeTroisQuilleUne = 1;
    RangeeQuatreQuilleUne = 1;
    ScoreLancer = 6;
    }
    else if (!RangeeUneQuilleUne && !RangeeUneQuilleDeux && RangeeUneQuilleTrois && RangeeUneQuilleQuatre && !RangeeDeuxQuilleUne && RangeeDeuxQuilleDeux && RangeeDeuxQuilleTrois && !RangeeTroisQuilleUne && RangeeTroisQuilleDeux && RangeeQuatreQuilleUne)
    {
    RangeeUneQuilleUne = 1;
    RangeeUneQuilleDeux = 1;
    RangeeDeuxQuilleUne = 1;
    RangeeTroisQuilleUne = 1;
    ScoreLancer = 4;
    }
}
else if (tX > 600 && tX <= 650)
{
  MouvBoule(47);
  if (!RangeeUneQuilleTrois && !RangeeUneQuilleQuatre && !RangeeDeuxQuilleTrois && !RangeeTroisQuilleDeux && !RangeeQuatreQuilleUne && !RangeeDeuxQuilleDeux)
  {
  RangeeUneQuilleTrois = 1;
  RangeeUneQuilleQuatre = 1;
  RangeeDeuxQuilleDeux = 1;
  RangeeDeuxQuilleTrois = 1;
  RangeeTroisQuilleDeux = 1;
  RangeeQuatreQuilleUne = 1;
  ScoreLancer = 6;
}
    else if (!RangeeUneQuilleTrois && RangeeUneQuilleQuatre && !RangeeDeuxQuilleTrois && !RangeeTroisQuilleDeux && !RangeeQuatreQuilleUne && !RangeeDeuxQuilleDeux)
    {
    RangeeUneQuilleTrois = 1;
    RangeeDeuxQuilleDeux = 1;
    RangeeDeuxQuilleTrois = 1;
    RangeeTroisQuilleDeux = 1;
    RangeeQuatreQuilleUne = 1;
        ScoreLancer = 5;
    }
    else if (!RangeeUneQuilleTrois && !RangeeUneQuilleQuatre && !RangeeDeuxQuilleTrois && !RangeeTroisQuilleDeux && RangeeQuatreQuilleUne && RangeeDeuxQuilleDeux)
    {
    RangeeUneQuilleTrois = 1;
    RangeeUneQuilleQuatre = 1;
    RangeeDeuxQuilleTrois = 1;
    RangeeTroisQuilleDeux = 1;
        ScoreLancer = 4;
    }
    else if (!RangeeUneQuilleTrois && RangeeUneQuilleQuatre && RangeeDeuxQuilleTrois && !RangeeTroisQuilleDeux && !RangeeQuatreQuilleUne && !RangeeDeuxQuilleDeux)
    {
    RangeeUneQuilleTrois = 1;
    RangeeDeuxQuilleDeux = 1;
    RangeeTroisQuilleDeux = 1;
    RangeeQuatreQuilleUne = 1;
    ScoreLancer = 4;
    }
    else if (RangeeUneQuilleTrois && RangeeUneQuilleQuatre && RangeeDeuxQuilleTrois && RangeeTroisQuilleDeux && !RangeeQuatreQuilleUne && !RangeeDeuxQuilleDeux)
    {
    RangeeDeuxQuilleDeux = 1;
    RangeeQuatreQuilleUne = 1;
    ScoreLancer = 2;
    }
    else
    {
    ScoreLancer = 0;
    }
 
}
else if (tX > 650 && tX <= 690)
{
  MouvBoule(50);
  if (!RangeeUneQuilleTrois && !RangeeUneQuilleQuatre && !RangeeDeuxQuilleTrois && !RangeeTroisQuilleDeux)
  {
  RangeeUneQuilleTrois = 1;
  RangeeUneQuilleQuatre = 1;
  RangeeDeuxQuilleTrois = 1;
  RangeeTroisQuilleDeux = 1;
  ScoreLancer = 4;
}
    else if (!RangeeUneQuilleTrois && RangeeUneQuilleQuatre && !RangeeDeuxQuilleTrois && !RangeeTroisQuilleDeux)
    {
      RangeeUneQuilleTrois = 1;
      RangeeDeuxQuilleTrois = 1;
      RangeeTroisQuilleDeux = 1;
        ScoreLancer = 3;
    }
    else if (!RangeeUneQuilleTrois && RangeeUneQuilleQuatre && RangeeDeuxQuilleTrois && !RangeeTroisQuilleDeux)
    {
        RangeeUneQuilleTrois = 1;
        RangeeTroisQuilleDeux = 1;
        ScoreLancer = 2;
    }
    else
    {
    ScoreLancer = 0;
    }
 
}
else if (tX > 690 && tX <= 710)
{
  MouvBoule(60);
  if (!RangeeUneQuilleQuatre && !RangeeDeuxQuilleTrois)
    {
    RangeeUneQuilleQuatre = 1;
    RangeeDeuxQuilleTrois = 1;
    ScoreLancer = 2;
    }
    else if (!RangeeDeuxQuilleTrois && RangeeUneQuilleQuatre)
    {
    RangeeDeuxQuilleTrois = 1;
    ScoreLancer = 1;  
    }
    else
    {
    ScoreLancer = 0;
    }
}
else if (tX > 710 && tX <= 740)
{
    MouvBoule(70);
    if (!RangeeUneQuilleQuatre)
    {
    RangeeUneQuilleQuatre = 1;
    ScoreLancer = 1;
    }
    else
    {
    ScoreLancer = 0;
    }
}
else if (tX >= 740)
{
    MouvBoule(55);
    ScoreLancer = 0;
}
ActualiserQuilles();
if (StrikeSpare && !Joueur2)
    {
    Score = Score+ScoreLancer*2;
    StrikeSpare = StrikeSpare-1;
    if (StrikeSpare == 0)
    {
    BonusEnCours = 1;
    }
    }
else if (StrikeSpareJoueur2 && Joueur2)
{
    ScoreJoueur2 = ScoreJoueur2+ScoreLancer*2;
    StrikeSpareJoueur2 = StrikeSpareJoueur2-1;
    if (StrikeSpareJoueur2 == 0)
    {
    BonusEnCours = 1;
    }
}
else
{
    if (!Joueur2)
    {
    Score = Score+ScoreLancer;
    }
    else
    {
    ScoreJoueur2 = ScoreJoueur2+ScoreLancer;
    }
}  
ISpressed = 0;
if (RangeeUneQuilleUne && RangeeUneQuilleDeux && RangeeUneQuilleTrois && RangeeUneQuilleQuatre && RangeeDeuxQuilleUne && RangeeDeuxQuilleDeux && RangeeDeuxQuilleTrois && RangeeTroisQuilleUne && RangeeTroisQuilleDeux && RangeeQuatreQuilleUne)
{
    if (NbLancer == 1)
    {
        if (!Joueur2)
        {
        StrikeSpare = StrikeSpare+2;
        if (StrikeSpare == 2)
        {
        PasDeBonus = 1; 
        }
        }
        else
        {
        StrikeSpareJoueur2 = StrikeSpareJoueur2+2;
        if (StrikeSpareJoueur2 == 2)
        {
        PasDeBonus = 1; 
        }   
        }
        FaitStrike = 1;
    }
    else if (NbLancer == 2 && ScoreLancer != 10)
    {
        if (!Joueur2)
        {
        StrikeSpare = StrikeSpare+1;
        if (StrikeSpare == 1)
        {
        PasDeBonus = 1; 
        }
        }
        else
        {
        StrikeSpareJoueur2 = StrikeSpareJoueur2+1;
        if (StrikeSpareJoueur2 == 1)
        {
        PasDeBonus = 1; 
        }       
        }
        FaitSpare = 1;
    }
    else if (NbLancer == 2 && ScoreLancer == 10)
    {
        if (!Joueur2)
        {
        StrikeSpare = StrikeSpare+2;
        if (StrikeSpare == 2)
        {
        PasDeBonus = 1; 
        }
        }
        else
        {
        StrikeSpareJoueur2 = StrikeSpareJoueur2+2;
        if (StrikeSpareJoueur2 == 2)
        {
        PasDeBonus = 1; 
        }       
        }
        FaitStrike = 1;
    }
    NbLancer = 1;
    if (Multijoueur)
    {
    if (Joueur2)
    {
    NbJeu = NbJeu+1;
    }
    }
    else
    {
    NbJeu = NbJeu+1;    
    }
    RangeeUneQuilleUne = 0;
    RangeeUneQuilleDeux = 0;
    RangeeUneQuilleTrois = 0;
    RangeeUneQuilleQuatre = 0;
    RangeeDeuxQuilleUne = 0;
    RangeeDeuxQuilleDeux = 0;
    RangeeDeuxQuilleTrois = 0;
    RangeeTroisQuilleUne = 0;
    RangeeTroisQuilleDeux = 0;
    RangeeQuatreQuilleUne = 0;
    ActualiserQuilles();
    if (Multijoueur && !Joueur2)
    {
        Joueur2 = 1;
    }
    else
    {
    Joueur2 = 0;
    }
}
else if (NbLancer == 2)
{
    NbLancer = 1;
    if (Multijoueur)
    {
    if (Joueur2)
    {
    NbJeu = NbJeu+1;
    }
    }
    else
    {
    NbJeu = NbJeu+1;    
    }
    RangeeUneQuilleUne = 0;
    RangeeUneQuilleDeux = 0;
    RangeeUneQuilleTrois = 0;
    RangeeUneQuilleQuatre = 0;
    RangeeDeuxQuilleUne = 0;
    RangeeDeuxQuilleDeux = 0;
    RangeeDeuxQuilleTrois = 0;
    RangeeTroisQuilleUne = 0;
    RangeeTroisQuilleDeux = 0;
    RangeeQuatreQuilleUne = 0;
    ActualiserQuilles();
    if (Multijoueur && !Joueur2)
    {
        Joueur2 = 1;
    }
    else
    {
    Joueur2 = 0;
    }
}  
else if (NbLancer == 1)
{
    NbLancer = 2;
}
if (NbJeu <= 10)
{
    POINT a1,a2;
    char *bowling = "BOWLING";
    char *plus = "+";
    a1.x = 300; a1.y = 850;
    a2.x = 1050; a2.y = 1000;
    draw_fill_rectangle(a1, a2, darkslategray);
    if (FaitStrike)
    {
    POINT a1,a2;
    char *a_ecrire = "STRIKE";
    a2.x = 468; a2.y = 992;
    aff_pol(a_ecrire,75,a2,black);
    a1.x = 465; a1.y = 995;
    aff_pol(a_ecrire,75,a1,blanc);
    FaitStrike = 0; 
    }
    else if (FaitSpare)
    {
    POINT a1,a2;
    char *a_ecrire = "SPARE";
    a2.x = 468; a2.y = 992;
    aff_pol(a_ecrire,75,a2,black);
    a1.x = 465; a1.y = 995;
    aff_pol(a_ecrire,75,a1,blanc);
    FaitSpare = 0;  
    }
    else if (!FaitSpare && !FaitStrike && ScoreLancer < 10 && ScoreLancer >= 2)
    {
    POINT a1,a2;
    char *a_ecrire = "QUILLES TOMBEES";
    a1.x = 308; a1.y = 982;
    aff_int(ScoreLancer, 55, a1, noir);
    a1.x = 305; a1.y = 985;
    aff_int(ScoreLancer, 55, a1, blanc);
    a2.x = 358; a2.y = 982;
    aff_pol(a_ecrire,55,a2,black);
    a1.x = 355; a1.y = 985;
    aff_pol(a_ecrire,55,a1,blanc);
    }
    else if (!FaitSpare && !FaitStrike && ScoreLancer == 1)
    {
    POINT a1,a2;
    char *a_ecrire = "QUILLE TOMBEE";
    a1.x = 348; a1.y = 982;
    aff_int(ScoreLancer, 55, a1, noir);
    a1.x = 345; a1.y = 985;
    aff_int(ScoreLancer, 55, a1, blanc);
    a2.x = 398; a2.y = 982;
    aff_pol(a_ecrire,55,a2,black);
    a1.x = 395; a1.y = 985;
    aff_pol(a_ecrire,55,a1,blanc);
    }
    else if (!FaitSpare && !FaitStrike && ScoreLancer == 0)
    {
    POINT a1,a2;
    char *a_ecrire = "TIR MANQUE";
    a2.x = 418; a2.y = 982;
    aff_pol(a_ecrire,55,a2,black);
    a1.x = 415; a1.y = 985;
    aff_pol(a_ecrire,55,a1,blanc);
    }
     
    a1.x = 562; a1.y = 913;
    aff_pol(plus,45,a1,noir);
    a1.x = 560; a1.y = 915;
    aff_pol(plus,45,a1,blanc);
    a1.x = 607; a1.y = 913;
    aff_int(ScoreLancer, 45, a1, noir);
    a1.x = 605; a1.y = 915;
    aff_int(ScoreLancer, 45, a1, blanc);
    if (!PasDeBonus)
    {
    if (Joueur2)
    {
    if (BonusEnCours == 1 || StrikeSpareJoueur2 != 0)
    {
    char *bonus = "(x2)";
    a1.x = 667; a1.y = 893;
    aff_pol(bonus,20,a1,noir);
    a1.x = 665; a1.y = 895;
    aff_pol(bonus,20,a1,blanc);
    BonusEnCours = 0;
    }
    }
    else
    {
    if (BonusEnCours == 1 || StrikeSpare != 0)
    {
    char *bonus = "(x2)";
    a1.x = 667; a1.y = 893;
    aff_pol(bonus,20,a1,noir);
    a1.x = 665; a1.y = 895;
    aff_pol(bonus,20,a1,blanc); 
    BonusEnCours = 0;
    }   
    }
    }
    PasDeBonus = 0;
    BonusEnCours = 0;
    AfficherScore();
    attendre(1500);
    a1.x = 300; a1.y = 850;
    a2.x = 1050; a2.y = 1000;
    draw_fill_rectangle(a1, a2, darkslategray);
     
    a2.x = 473; 
    a2.y = 939;
    aff_pol(bowling,55,a2,black);
      
         a1.x = 470; 
    a1.y = 940;
    aff_pol(bowling,55,a1,blanc);
}
else
{
    POINT a1,a2;
    a1.x = 300; a1.y = 850;
    a2.x = 1050; a2.y = 1000;
    draw_fill_rectangle(a1, a2, darkslategray);
    char *a_ecrire = "APPLICATION";
    char *b_ecrire = "DES BONUS";
    a2.x = 418; a2.y = 982;
    aff_pol(a_ecrire,55,a2,black);
    a1.x = 415; a1.y = 985;
    aff_pol(a_ecrire,55,a1,blanc);
    a1.x = 437; a1.y = 913;
    aff_pol(b_ecrire, 45, a1, noir);
    a1.x = 435; a1.y = 915;
    aff_pol(b_ecrire, 45, a1, blanc);
    attendre(1500);
    while (StrikeSpare != 0)
    {
        Score = Score+10;
        StrikeSpare = StrikeSpare-1;
        AfficherScore();
        attendre(300);
    }
    while (StrikeSpareJoueur2 != 0)
    {
        ScoreJoueur2 = ScoreJoueur2+10;
        StrikeSpareJoueur2 = StrikeSpareJoueur2-1;
        AfficherScore();
        attendre(300);
    }
    ISpressed = 1;
    EcranScore = 1;
    AfficherScoreFin();
}
}
}
  exit(0);  
}
