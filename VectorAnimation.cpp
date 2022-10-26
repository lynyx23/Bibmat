#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Button.h"
#include "VectorFunctions.h"
#include "VectorAnimation.h"

using namespace std;

void AfisareCodSuma()
{
    settextstyle(8,0,2);
    setbkcolor(LIGHTGRAY);
    setcolor(BLACK);
    outtextxy(990,170,"int SumaV (int n, vector[])");
    outtextxy(990,200,"{");
    outtextxy(1010,230,"int Suma=0;");
    outtextxy(1010,270,"for(int i=0; i<n; i++)");
    outtextxy(1010,300,"Suma+=vector[i];");
    outtextxy(990,330,"return Suma;");
    outtextxy(990,360,"}");

    outtextxy(990,400,"int main ()");
    outtextxy(990,430,"{");
    outtextxy(1010,460,"int n, vector[12];");
    outtextxy(1010,490,"cin>>n;");
    outtextxy(1010,520,"for(int i=0; i<n; i++)");
    outtextxy(1010,550,"cin>>vector[i];");
    outtextxy(1010,580,"cout<<SumaV(n,vector);");
    outtextxy(1010,620,"return 0;");
    outtextxy(990,640,"}");
}

void Animation_Suma(int DimVect,Repere_Vector v,int Vector[13])
{
    int stg=80,Sus=200;
    char rezulat[10]="";
    int suma=0;
    for(int i=1;i<=DimVect;i++)
    {
        char pozitie[13]="";
        itoa(i,pozitie,10);
        suma+=Vector[i-1];
        char c[6]="";
        itoa(Vector[i-1],c,10);
        setfillstyle(SOLID_FILL,RED);
        floodfill(v.stanga+v.latura*(i-1)+1,v.sus+1,WHITE);

        setbkcolor(CYAN);
        settextstyle(EUROPEAN_FONT,HORIZ_DIR,4);
        if(i<DimVect) {
            outtextxy(stg,Sus,c);
            stg+=textwidth(c);
            outtextxy(stg,Sus," + ");
            stg+=textwidth(" + ");
        }
        else {
            outtextxy(stg,Sus,c);
            stg+=textwidth(c);
            outtextxy(stg,Sus," = ");
            stg+=textwidth(" = ");
        }
        if(stg>=750){
            stg=80;
            Sus=250;
        }

        setbkcolor(LIGHTMAGENTA);
        settextstyle(8,0,3);
        outtextxy(80,470,"ADUNAM IN SUMA  ");
        outtextxy(300,470,c);
        outtextxy(80,520,"ELEMENTUL DIN CASUTA ");
        outtextxy(400,520,pozitie);
        delay(3000);
        setfillstyle(SOLID_FILL,GREEN);
        floodfill(v.stanga+v.latura*(i-1)+1,v.sus+1,WHITE);
    }
    setbkcolor(CYAN);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,4);
    itoa(suma,rezulat,10);
    outtextxy(stg,Sus,rezulat);
}

void AfisareSuma()
{
    rectangle(70,180,800,400);
    setfillstyle(SOLID_FILL,CYAN);
    floodfill(71,181,WHITE);

    rectangle(70,450,800,600);
    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    floodfill(71,451,WHITE);

}

void AfisareCodScadere()
{
    settextstyle(8,0,2);
    setbkcolor(LIGHTGRAY);
    setcolor(BLACK);
    outtextxy(990,170,"int ScadereV (int n, vector[])");
    outtextxy(990,200,"{");
    outtextxy(1010,230,"int Scadere=0;");
    outtextxy(1010,270,"for(int i=0; i<n; i++)");
    outtextxy(1010,300,"Scadere-=vector[i];");
    outtextxy(990,330,"return Scadere;");
    outtextxy(990,360,"}");

    outtextxy(990,400,"int main ()");
    outtextxy(990,430,"{");
    outtextxy(1010,460,"int n, vector[12];");
    outtextxy(1010,490,"cin>>n;");
    outtextxy(1010,520,"for(int i=0; i<n; i++)");
    outtextxy(1010,550,"cin>>vector[i];");
    outtextxy(1010,580,"cout<<ScadereV(n,vector);");
    outtextxy(1010,610,"return 0;");
    outtextxy(990,640,"}");
}

void Animation_Scadere(int DimVect,Repere_Vector v,int Vector[13])
{
    int stg=80,Sus=200;
    char rezulat[10]="";
    int scadere=0;
    for(int i=1;i<=DimVect;i++)
    {
        char pozitie[13]="";
        itoa(i,pozitie,10);
        scadere-=Vector[i];
        char c[6]="";
        itoa(Vector[i],c,10);
        setfillstyle(SOLID_FILL,RED);
        floodfill(v.stanga+v.latura*(i-1)+1,v.sus+1,WHITE);

        setbkcolor(CYAN);
        settextstyle(EUROPEAN_FONT,HORIZ_DIR,4);
        if(i<DimVect) {
            outtextxy(stg,Sus,c);
            stg+=textwidth(c);
            outtextxy(stg,Sus," - ");
            stg+=textwidth(" - ");
        }
        else {
            outtextxy(stg,Sus,c);
            stg+=textwidth(c);
            outtextxy(stg,Sus," = ");
            stg+=textwidth(" = ");
        }
        if(stg>=750){
            stg=80;
            Sus=250;
        }

        setbkcolor(LIGHTMAGENTA);
        settextstyle(8,0,3);
        outtextxy(80,470,"SCADEM IN CONTINUARE  ");
        outtextxy(400,470,c);
        outtextxy(80,520,"ELEMENTUL DIN CASUTA ");
        outtextxy(400,520,pozitie);
        delay(3000);
        setfillstyle(SOLID_FILL,GREEN);
        floodfill(v.stanga+v.latura*(i-1)+1,v.sus+1,WHITE);
    }
    setbkcolor(CYAN);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,4);
    itoa(scadere,rezulat,10);
    outtextxy(stg,Sus,rezulat);
}

void AfisareScadere()
{
    rectangle(70,180,800,400);
    setfillstyle(SOLID_FILL,CYAN);
    floodfill(71,181,WHITE);

    rectangle(70,450,800,600);
    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    floodfill(71,451,WHITE);

}

void AfisareCodProdus()
{
    settextstyle(8,0,2);
    setbkcolor(LIGHTGRAY);
    setcolor(BLACK);
    outtextxy(990,170,"int ProdusV (int n, vector[])");
    outtextxy(990,200,"{");
    outtextxy(1010,230,"int Produs=1;");
    outtextxy(1010,270,"for(int i=0; i<n; i++)");
    outtextxy(1010,300,"Produs*=vector[i];");
    outtextxy(990,330,"return Produs;");
    outtextxy(990,360,"}");

    outtextxy(990,400,"int main ()");
    outtextxy(990,430,"{");
    outtextxy(1010,460,"int n, vector[12];");
    outtextxy(1010,490,"cin>>n;");
    outtextxy(1010,520,"for(int i=0; i<n; i++)");
    outtextxy(1010,550,"cin>>vector[i];");
    outtextxy(1010,580,"cout<<ProdusV(n,vector);");
    outtextxy(1010,610,"return 0;");
    outtextxy(990,640,"}");
}

void Animation_Produs(int DimVect,Repere_Vector v,int Vector[13])
{
    int stg=80,Sus=200;
    char rezultat[10]="";
    int produs=1;
    for(int i=1;i<=DimVect;i++)
    {
        char pozitie[13]="";
        itoa(i,pozitie,10);
        produs*=Vector[i];
        char c[6]="";
        itoa(Vector[i],c,10);
        setfillstyle(SOLID_FILL,RED);
        floodfill(v.stanga+v.latura*(i-1)+1,v.sus+1,WHITE);

        setbkcolor(CYAN);
        settextstyle(EUROPEAN_FONT,HORIZ_DIR,4);
        if(i<DimVect) {
            outtextxy(stg,Sus,c);
            stg+=textwidth(c);
            outtextxy(stg,Sus," * ");
            stg+=textwidth(" * ");
        }
        else {
            outtextxy(stg,Sus,c);
            stg+=textwidth(c);
            outtextxy(stg,Sus," = ");
            stg+=textwidth(" = ");
        }
        if(stg>=750){
            stg=80;
            Sus=250;
        }

        setbkcolor(LIGHTMAGENTA);
        settextstyle(8,0,3);
        outtextxy(80,470,"INMULTIM PRODUSUL CU  ");
        outtextxy(400,470,c);
        outtextxy(80,520,"ELEMENTUL DIN CASUTA ");
        outtextxy(400,520,pozitie);
        delay(3000);
        setfillstyle(SOLID_FILL,GREEN);
        floodfill(v.stanga+v.latura*(i-1)+1,v.sus+1,WHITE);
    }
    setbkcolor(CYAN);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,4);
    itoa(produs,rezultat,10);
    outtextxy(stg,Sus,rezultat);
}

void AfisareProdus()
{
    rectangle(70,180,800,400);
    setfillstyle(SOLID_FILL,CYAN);
    floodfill(71,181,WHITE);

    rectangle(70,450,800,600);
    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    floodfill(71,451,WHITE);

}

void draw_scalar()
{
    setbkcolor(GREEN);
    settextstyle(8,0,3);
    outtextxy(45,150,"Voaloare Scalar:");
    setbkcolor(BLACK);
    rectangle(320,130,390,200);
}

void AfisareCod_Scalar()
{
    settextstyle(8,0,2);
    setbkcolor(LIGHTGRAY);
    setcolor(BLACK);
    outtextxy(970,110, "#include <iostream>");
    outtextxy(970,130, "using namesapce std;");
    outtextxy(960,170,"void ScV (int n, vector[]),int Sc)");
    outtextxy(960,200,"{");
    outtextxy(1010,230,"for(int i=0; i<n; i++)");
    outtextxy(1030,270,"v[i]=v[i]*Scalar;");
    outtextxy(960,300,"}");

    outtextxy(960,340,"int main ()");
    outtextxy(960,370,"{");
    outtextxy(1010,400,"int n, vector[12],int Scalar;");
    outtextxy(1010,430,"cin>>n;");
    outtextxy(1010,460,"cin>>Scalar;");
    outtextxy(1010,490,"for(int i=0; i<n; i++)");
    outtextxy(1030,520,"cin>>vector[i];");
    outtextxy(990,550,"ScalarV(n,vector,Scalar);");
    outtextxy(990,580,"for(int i=0; i<n; i++)");
    outtextxy(1010,610,"cout<<v[i]<<" " ");
    outtextxy(990,640,"return 0;");
    outtextxy(960,650,"}");

}

void Animation_Scalar(int DimVect,Repere_Vector v,int Vector[13],int scalar)
{
    Draw_vector_in_window(v,40,250);
    int produs=1;
    char Scalar[10]="";
    itoa(scalar,Scalar,10);
    for(int i=0; i<DimVect; i++)
    {
       produs=Vector[i]*scalar;
        char valoare[13]="";
        char rezultat[13]="";
        char pozitie[13]="";
        itoa(produs,rezultat,10);
        itoa(Vector[i],valoare,10);
        itoa(i+1,pozitie,10);
        setfillstyle(SOLID_FILL,RED);
        floodfill(40+70*i+1,30+1,WHITE);
        floodfill(321,131,WHITE);
        setbkcolor(DARKGRAY);
        settextstyle(EUROPEAN_FONT,HORIZ_DIR,3);
        outtextxy(40+70*i+(70-textwidth(rezultat))/2,250+(70-textheight(rezultat))/2,rezultat);

        settextstyle(8,0,3);
        setbkcolor(LIGHTMAGENTA);
        outtextxy(80,420,"INMULTIM ELEMENTUL DIN CASUTA");
        outtextxy(530,420,pozitie);
        outtextxy(570,420,"CU SCALARUL");
        outtextxy(80,480,"ADAUGAM REZULTATUL IN NOUL VECTOR");
        delay(3000);
        setfillstyle(SOLID_FILL,GREEN);
        floodfill(40+70*i+1,30+1,WHITE);

    }
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(40+70*4+1,130+1,WHITE);

}

void Afisare_Scalar()
{
    rectangle(70,400,800,550);
    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    floodfill(71,401,WHITE);

}

void draw_salvare_valoare() // la fel ca la stanga
{
    setbkcolor(LIGHTRED);
   // bar(40,130,290,200);
    //setbkcolor(LIGHTGRAY);
    settextstyle(8,0,3);
    outtextxy(45,150,"Valoare Salvata:");
    setbkcolor(BLACK);
    rectangle(320,130,390,200);
}

void AfisareCod_Shifare_Stanga()
{
    settextstyle(8,0,2);
    setbkcolor(LIGHTGRAY);
    setcolor(BLACK);
    outtextxy(970,110, "#include <iostream>");
    outtextxy(970,130, "using namesapce std;");
    outtextxy(990,170,"void ShiftStg (int n, vector[])");
    outtextxy(990,200,"{");
    outtextxy(1010,230,"int aux=vector[0];");
    outtextxy(1010,270,"for(int i=0; i<n-1; i++)");
    outtextxy(1010,300,"vector[i]=vector[i+1];");
    outtextxy(990,330,"vector[n-1]=aux;");
    outtextxy(990,360,"}");

    outtextxy(990,390,"int main ()");
    outtextxy(990,420,"{");
    outtextxy(1010,430,"int n, vector[12];");
    outtextxy(1010,460,"cin>>n;");
    outtextxy(1010,490,"for(int i=0; i<n; i++)");
    outtextxy(1010,520,"cin>>vector[i];");
    outtextxy(1010,550,"ShiftStg(n,vector);");
    outtextxy(1010,580,"for(int i=0; i<n; i++)");
    outtextxy(1010,610,"cout<<vector[i]<<' '; ");
    outtextxy(1010,640,"return 0;");
    outtextxy(990,650,"}");
}

void Animation_Shifare_Stanga(int DimVect,Repere_Vector v,int Vector[13])
{
    Draw_vector_in_window(v,40,250);
    char PrimaPozitie[10]="";
    itoa(Vector[0],PrimaPozitie,10);
    setbkcolor(DARKGRAY);
    outtextxy(40+70*4+(70-textwidth(PrimaPozitie))/2,130+(70-textheight(PrimaPozitie))/2,PrimaPozitie);
    for(int i=1; i<DimVect; i++)
    {
        char valoare[13]="";
        char pozitie[13]="";
        char pozitie1[13]="";
        itoa(Vector[i],valoare,10);
        itoa(i,pozitie1,10);
        itoa(i+1,pozitie,10);
        setfillstyle(SOLID_FILL,RED);
        floodfill(40+70*i+1,30+1,WHITE);
        setbkcolor(DARKGRAY);
        settextstyle(EUROPEAN_FONT,HORIZ_DIR,3);
        outtextxy(40+70*(i-1)+(70-textwidth(valoare))/2,250+(70-textheight(valoare))/2,valoare);

        settextstyle(8,0,3);
        setbkcolor(LIGHTMAGENTA);
        outtextxy(80,420,"ELEMENTUL DIN CASUTA");
        outtextxy(400,420,pozitie);
        outtextxy(420,420,"SE MUTA CU O POZITIE");
        outtextxy(80,450,"LA STANGA");
        outtextxy(80,480,"ADAUGAM NUMARUL IN NOUL VECTOR PE POZITIA");
        outtextxy(700,480,pozitie1);

        delay(3000);
        setfillstyle(SOLID_FILL,GREEN);
        floodfill(40+70*i+1,30+1,WHITE);

    }
    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    bar(70,400,800,550);
    settextstyle(8,0,3);
    setbkcolor(LIGHTMAGENTA);
    outtextxy(80,450,"ADAUGAM VALOAREA SALVATA PE ULTIMA POZITIE");
    outtextxy(80,480,"DIN NOUL VECTOR");
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(40+70*4+1,130+1,WHITE);
    setbkcolor(DARKGRAY);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,3);
    outtextxy(40+70*(v.dimensiune-1)+(70-textwidth(PrimaPozitie))/2,250+(70-textheight(PrimaPozitie))/2,PrimaPozitie);

}

void Afisare_Shifare_Stanga()
{
    rectangle(70,400,800,550);
    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    floodfill(71,401,WHITE);

}

void AfisareCod_Shifare_Dreapta()
{
    settextstyle(8,0,2);
    setbkcolor(LIGHTGRAY);
    setcolor(BLACK);
    outtextxy(970,110, "#include <iostream>");
    outtextxy(970,130, "using namesapce std;");
    outtextxy(990,170,"void ShiftDrp (int n, vector[])");
    outtextxy(990,200,"{");
    outtextxy(1010,230,"int aux=vector[n-1];");
    outtextxy(1010,270,"for(int i=n-2; i>=0; i--)");
    outtextxy(1010,300,"vector[i+1]=vector[i];");
    outtextxy(990,330,"vector[0]=aux;");
    outtextxy(990,360,"}");

    outtextxy(990,390,"int main ()");
    outtextxy(990,420,"{");
    outtextxy(1010,430,"int n, vector[12];");
    outtextxy(1010,460,"cin>>n;");
    outtextxy(1010,490,"for(int i=0; i<n; i++)");
    outtextxy(1010,520,"cin>>vector[i];");
    outtextxy(1010,550,"ShiftDrp(n,vector);");
    outtextxy(1010,580,"for(int i=0; i<n; i++)");
    outtextxy(1010,610,"cout<<vector[i]<<' '; ");
    outtextxy(1010,640,"return 0;");
    outtextxy(990,650,"}");
}

void Animation_Shifare_Dreapta(int DimVect,Repere_Vector v,int Vector[13])
{
    Draw_vector_in_window(v,40,250);
    char UltimaPozitie[10]="";
    itoa(Vector[DimVect-1],UltimaPozitie,10);
    setbkcolor(DARKGRAY);
    outtextxy(40+70*4+(70-textwidth(UltimaPozitie))/2,130+(70-textheight(UltimaPozitie))/2,UltimaPozitie);
    for(int i=DimVect-2; i>=0; i--)
    {
        char valoare[13]="";
        char pozitie[13]="";
        char pozitie1[13]="";
        itoa(Vector[i],valoare,10);
        itoa(i+2,pozitie1,10);
        itoa(i+1,pozitie,10);
        setfillstyle(SOLID_FILL,RED);
        floodfill(40+70*i+1,30+1,WHITE);
        setbkcolor(DARKGRAY);
        settextstyle(EUROPEAN_FONT,HORIZ_DIR,3);
        outtextxy(40+70*(i+1)+(70-textwidth(valoare))/2,250+(70-textheight(valoare))/2,valoare);

        settextstyle(8,0,3);
        setbkcolor(LIGHTMAGENTA);
        outtextxy(80,420,"ELEMENTUL DIN CASUTA");
        outtextxy(400,420,pozitie);
        outtextxy(420,420,"SE MUTA CU O POZITIE");
        outtextxy(80,450,"LA DREAPTA");
        outtextxy(80,480,"ADAUGAM NUMARUL IN NOUL VECTOR PE POZITIA");
        outtextxy(700,480,pozitie1);

        delay(3000);
        setfillstyle(SOLID_FILL,GREEN);
        floodfill(40+70*i+1,30+1,WHITE);

    }
    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    bar(70,400,800,550);
    settextstyle(8,0,3);
    setbkcolor(LIGHTMAGENTA);
    outtextxy(80,450,"ADAUGAM VALOAREA SALVATA PE PRIMA POZITIE");
    outtextxy(80,480,"DIN NOUL VECTOR");
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(40+70*4+1,130+1,WHITE);
    setbkcolor(DARKGRAY);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,3);
    outtextxy(40+(70-textwidth(UltimaPozitie))/2,250+(70-textheight(UltimaPozitie))/2,UltimaPozitie);

}

void Afisare_Shifare_Dreapta() //la fel ca la stanga
{
    rectangle(70,400,800,550);
    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    floodfill(71,401,WHITE);

}

void draw_salvare_valori()
{
    setbkcolor(LIGHTRED);
   // bar(40,130,290,200);
    //setbkcolor(LIGHTGRAY);
    settextstyle(8,0,3);
    outtextxy(45,150,"Prima Valoare:");
    outtextxy(45,250,"A doua Valoare:");
    setbkcolor(BLACK);
    rectangle(320,130,390,200);
    rectangle(320,230,390,300);
}

void AfisareCod_Sortare_Crescator()
{
    settextstyle(8,0,2);
    setbkcolor(LIGHTGRAY);
    setcolor(BLACK);
    outtextxy(970,110, "int n, vector[13]");
    outtextxy(970,130, "cin>>n;");
    outtextxy(970,160,"// citire vector[] cu n elemente");
    outtextxy(970,190,"bool sortat;");
    outtextxy(970,220,"do");
    outtextxy(970,260,"{");
    outtextxy(1010,290,"sortat = true;");
    outtextxy(1010,320,"for(int i=0; i<n-1; i++)");
    outtextxy(1040,350,"if(vector[i]>vector[i+1])");
    outtextxy(1040,380,"{");
    outtextxy(1070,420,"int aux=vector[i];");
    outtextxy(1070,450,"vector[i]=vector[i+1];");
    outtextxy(1070,480,"vector[i+1]=aux;");
    outtextxy(1070,510,"sortat=true;");
    outtextxy(1040,540,"}");
    outtextxy(970,570,"}");
    outtextxy(970,600,"while(!sortat);");
}

void Redraw_Casuta(int color,int stg,int sus,int stgplus,int susplus)
{
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,color);
    bar(stg+1,sus+1,stgplus-1,susplus-1);
}

void Animation_Sortare_Crescator(int DimVect,Repere_Vector v,int Vector[13])
{
    bool sortat;
    do
    {
         sortat = true;
        for(int i = 0 ; i < DimVect - 1 ; i ++){

            char pozitie1[13]="";
            char pozitie2[13]="";
            char valoare1[13]="";
            char valoare2[13]="";
            itoa(i+1,pozitie1,10);
            itoa(i+2,pozitie2,10);
            itoa(Vector[i],valoare1,10);
            itoa(Vector[i+1],valoare2,10);

            setfillstyle(SOLID_FILL,RED);
            floodfill(40+70*i+1,30+1,WHITE);
            setfillstyle(SOLID_FILL,RED);
            floodfill(40+70*(i+1)+1,30+1,WHITE);

            Redraw_Casuta(DARKGRAY,40+70*4,130,40+70*5,200);
            Redraw_Casuta(DARKGRAY,40+70*4,230,40+70*5,300);
            setbkcolor(DARKGRAY);
            settextstyle(4,HORIZ_DIR,3);
            outtextxy(40+70*4+(70-textwidth(valoare1))/2,130+(70-textheight(valoare1))/2,valoare1);
            outtextxy(40+70*4+(70-textwidth(valoare2))/2,230+(70-textheight(valoare2))/2,valoare2);
            settextstyle(8,0,3);
            setbkcolor(LIGHTMAGENTA);
            outtextxy(75,420,"SALVAM VALORILE DIN CASUTELE EVIDENTIATE");
            outtextxy(75,450,"CU ROSU");
            delay(5000);
            Redraw_Casuta(LIGHTMAGENTA,70,400,800,550);
            setbkcolor(LIGHTMAGENTA);
            outtextxy(80,420,"COMPARAM CELE DOUA VALORI");
            Redraw_Casuta(LIGHTMAGENTA,70,400,800,550);
            delay(5000);
            if(Vector[i] > Vector[i+1])
            {
                settextstyle(8,0,3);
                setbkcolor(LIGHTMAGENTA);
                outtextxy(80,420,valoare1);
                outtextxy(textwidth(valoare1)+100,420,"ESTE MAI MARE CA");
                outtextxy(textwidth(valoare1)+350,420,valoare2);
                delay(5000);
                Redraw_Casuta(LIGHTMAGENTA,70,400,800,550);
                Redraw_Casuta(BLACK,40+70*i,30,40+70*(i+1),100);
                delay(3000);
                settextstyle(8,0,3);
                setbkcolor(LIGHTMAGENTA);
                outtextxy(80,420,valoare1);
                outtextxy(textwidth(valoare1)+100,420,"ESTE INLOCUIT CU");
                outtextxy(textwidth(valoare1)+350,420,valoare2);
                setfillstyle(SOLID_FILL,MAGENTA);
                floodfill(40+70*4+1,231,WHITE);
                setbkcolor(BLACK);
                settextstyle(4,HORIZ_DIR,3);
                outtextxy(40+70*i+(70-textwidth(valoare2))/2,30+(70-textheight(valoare2))/2,valoare2);
                delay(5000);

                Redraw_Casuta(LIGHTMAGENTA,70,400,800,550);
                Redraw_Casuta(BLACK,40+70*(i+1),30,40+70*(i+2),100);
                delay(3000);
                settextstyle(8,0,3);
                setbkcolor(LIGHTMAGENTA);
                outtextxy(80,420,valoare2);
                outtextxy(textwidth(valoare2)+100,420,"ESTE INLOCUIT CU");
                outtextxy(textwidth(valoare2)+350,420,valoare1);
                setfillstyle(SOLID_FILL,MAGENTA);
                floodfill(40+70*4+1,131,WHITE);
                setbkcolor(BLACK);
                settextstyle(4,HORIZ_DIR,3);
                outtextxy(40+70*(i+1)+(70-textwidth(valoare1))/2,30+(70-textheight(valoare1))/2,valoare1);
                delay(5000);

                int aux = Vector[i];
                Vector[i] = Vector[i+1];
                Vector[i+1] = aux;
                sortat = false;
            }
            else{

                Redraw_Casuta(LIGHTMAGENTA,70,400,800,550);
                settextstyle(8,0,3);
                setbkcolor(LIGHTMAGENTA);
                outtextxy(80,420,"CELE DOUA VALORI RESPECTA CONDITIA");
                delay(3000);
                setfillstyle(SOLID_FILL,BLACK);
                floodfill(40+70*i+1,31,WHITE);

                setfillstyle(SOLID_FILL,BLACK);
                floodfill(40+70*(i+1)+1,31,WHITE);
            }
        }
}while(!sortat);
for(int i=0;i<DimVect;i++)
{
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(40+70*i+1,31,WHITE);
}
Redraw_Casuta(LIGHTMAGENTA,70,400,800,550);
settextstyle(8,0,3);
setbkcolor(LIGHTMAGENTA);
outtextxy(80,420,"VECTORUL ESTE SORTAT CRESCATOR");
}

void Afisare_Sortare_Crescator()
{
    rectangle(70,400,800,550);
    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    floodfill(71,401,WHITE);

}

void AfisareCod_Sortare_Descrescator()
{
    settextstyle(8,0,2);
    setbkcolor(LIGHTGRAY);
    setcolor(BLACK);
    outtextxy(970,110, "int n, vector[13]");
    outtextxy(970,130, "cin>>n;");
    outtextxy(970,160,"// citire vector[] cu n elemente");
    outtextxy(970,190,"bool sortat;");
    outtextxy(970,220,"do");
    outtextxy(970,260,"{");
    outtextxy(1010,290,"sortat = true;");
    outtextxy(1010,320,"for(int i=0; i<n-1; i++)");
    outtextxy(1040,350,"if(vector[i]<vector[i+1])");
    outtextxy(1040,380,"{");
    outtextxy(1070,420,"int aux=vector[i];");
    outtextxy(1070,450,"vector[i]=vector[i+1];");
    outtextxy(1070,480,"vector[i+1]=aux;");
    outtextxy(1070,510,"sortat=true;");
    outtextxy(1040,540,"}");
    outtextxy(970,570,"}");
    outtextxy(970,600,"while(!sortat);");
}

void Animation_Sortare_Descrescator(int DimVect,Repere_Vector v,int Vector[13])
{
    bool sortat;
    do
    {
         sortat = true;
        for(int i = 0 ; i < DimVect - 1 ; i ++){

            char pozitie1[13]="";
            char pozitie2[13]="";
            char valoare1[13]="";
            char valoare2[13]="";
            itoa(i+1,pozitie1,10);
            itoa(i+2,pozitie2,10);
            itoa(Vector[i],valoare1,10);
            itoa(Vector[i+1],valoare2,10);

            setfillstyle(SOLID_FILL,RED);
            floodfill(40+70*i+1,30+1,WHITE);
            setfillstyle(SOLID_FILL,RED);
            floodfill(40+70*(i+1)+1,30+1,WHITE);

            Redraw_Casuta(DARKGRAY,40+70*4,130,40+70*5,200);
            Redraw_Casuta(DARKGRAY,40+70*4,230,40+70*5,300);
            setbkcolor(DARKGRAY);
            settextstyle(4,HORIZ_DIR,3);
            outtextxy(40+70*4+(70-textwidth(valoare1))/2,130+(70-textheight(valoare1))/2,valoare1);
            outtextxy(40+70*4+(70-textwidth(valoare2))/2,230+(70-textheight(valoare2))/2,valoare2);
            settextstyle(8,0,3);
            setbkcolor(LIGHTMAGENTA);
            outtextxy(75,420,"SALVAM VALORILE DIN CASUTELE EVIDENTIATE");
            outtextxy(75,450,"CU ROSU");
            delay(5000);
            Redraw_Casuta(LIGHTMAGENTA,70,400,800,550);
            setbkcolor(LIGHTMAGENTA);
            outtextxy(80,420,"COMPARAM CELE DOUA VALORI");
            Redraw_Casuta(LIGHTMAGENTA,70,400,800,550);
            delay(5000);
            if(Vector[i] < Vector[i+1])
            {
                settextstyle(8,0,3);
                setbkcolor(LIGHTMAGENTA);
                outtextxy(80,420,valoare1);
                outtextxy(textwidth(valoare1)+100,420,"ESTE MAI MIC CA");
                outtextxy(textwidth(valoare1)+350,420,valoare2);
                delay(5000);
                Redraw_Casuta(LIGHTMAGENTA,70,400,800,550);
                Redraw_Casuta(BLACK,40+70*i,30,40+70*(i+1),100);
                delay(3000);
                settextstyle(8,0,3);
                setbkcolor(LIGHTMAGENTA);
                outtextxy(80,420,valoare1);
                outtextxy(textwidth(valoare1)+100,420,"ESTE INLOCUIT CU");
                outtextxy(textwidth(valoare1)+350,420,valoare2);
                setfillstyle(SOLID_FILL,MAGENTA);
                floodfill(40+70*4+1,231,WHITE);
                setbkcolor(BLACK);
                settextstyle(4,HORIZ_DIR,3);
                outtextxy(40+70*i+(70-textwidth(valoare2))/2,30+(70-textheight(valoare2))/2,valoare2);
                delay(5000);

                Redraw_Casuta(LIGHTMAGENTA,70,400,800,550);
                Redraw_Casuta(BLACK,40+70*(i+1),30,40+70*(i+2),100);
                delay(3000);
                settextstyle(8,0,3);
                setbkcolor(LIGHTMAGENTA);
                outtextxy(80,420,valoare2);
                outtextxy(textwidth(valoare2)+100,420,"ESTE INLOCUIT CU");
                outtextxy(textwidth(valoare2)+350,420,valoare1);
                setfillstyle(SOLID_FILL,CYAN);
                floodfill(40+70*4+1,131,WHITE);
                setbkcolor(BLACK);
                settextstyle(4,HORIZ_DIR,3);
                outtextxy(40+70*(i+1)+(70-textwidth(valoare1))/2,30+(70-textheight(valoare1))/2,valoare1);
                delay(5000);

                int aux = Vector[i];
                Vector[i] = Vector[i+1];
                Vector[i+1] = aux;
                sortat = false;
            }
            else{

                Redraw_Casuta(LIGHTMAGENTA,70,400,800,550);
                settextstyle(8,0,3);
                setbkcolor(LIGHTMAGENTA);
                outtextxy(80,420,"CELE DOUA VALORI RESPECTA CONDITIA");
                delay(3000);
                setfillstyle(SOLID_FILL,BLACK);
                floodfill(40+70*i+1,31,WHITE);

                setfillstyle(SOLID_FILL,BLACK);
                floodfill(40+70*(i+1)+1,31,WHITE);
            }
        }
}while(!sortat);
for(int i=0;i<DimVect;i++)
{
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(40+70*i+1,31,WHITE);
}
Redraw_Casuta(LIGHTMAGENTA,70,400,800,550);
settextstyle(8,0,3);
setbkcolor(LIGHTMAGENTA);
outtextxy(80,420,"VECTORUL ESTE SORTAT DESCRESCATOR");
}

void Afisare_Sortare_Descrescator()
{
    rectangle(70,400,800,550);
    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    floodfill(71,401,WHITE);

}

void Window_Vector_Sortare_Descrescator() {
    closegraph();
    initwindow(1400, 700, "BibMat", 150, 50);
    cleardevice();
    setfillstyle(SOLID_FILL,DARKGRAY);
    floodfill(1,1,WHITE);
    setbkcolor(DARKGRAY);

    int Last_i, Current_i,Scalar=0;

    char titlu_vector[]="Introduceti dimensiunea vectorului:";
    settextstyle(4,HORIZ_DIR,5);
    outtextxy(1400/2-textwidth(titlu_vector)/2,150,titlu_vector);

    int ok=0;
    int vector_size;
    char text_vector_size[10]="";
    int vector_size_it=0;
    bool stop_read=false;
    do {
        if(textwidth(text_vector_size)==0) {
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(1400/2-textwidth("0"),300,1400/2+textwidth("0"),300+textheight("0"));
        }
        else {
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(1400/2-textwidth(text_vector_size),300,1400/2+textwidth(text_vector_size),300+textheight(text_vector_size));
        }
        setcolor(WHITE);
        outtextxy(1400/2-textwidth(text_vector_size)/2,300,text_vector_size);
        char c=getch();
        switch(c) {
            case 8: //Backspace
            {
                if(strlen(text_vector_size)>0) {
                    int n=strlen(text_vector_size);
                    strcpy(text_vector_size+n-1,text_vector_size+n);
                    vector_size_it--;
                }
                break;
            }
            case 13: //Enter
            {
                if(strlen(text_vector_size)) {
                    stop_read=true;
                    vector_size=atoi(text_vector_size);
                    cout<<vector_size;
                }
                break;
            }
            default:
            {
                if(strlen(text_vector_size)<2) {
                    if(c>='0' && c<='9') {
                        text_vector_size[vector_size_it++]=c;
                    }
                }
                break;
            }
        }
        clearmouseclick(WM_LBUTTONDOWN);
    } while(!stop_read);

    char text_confirma[]="Confirma";
    outtextxy(1400/2-textwidth(text_confirma)/2,400,text_confirma);
    Button confirma;
    Button_Setup(confirma,1400/2-textwidth(text_confirma)/2,400,text_confirma);

    Repere_Vector v;
    if(ok==0)
    {
        v.dimensiune=vector_size;
        ok=1;
    }
    cout<<" "<<v.dimensiune<<"";
    int* Vector;
    initVector(vector_size,Vector);

    ///loop pt buton confirma
    while(1) {
        if(ismouseclick(WM_LBUTTONDOWN)) {
            int mx=mousex();
            int my=mousey();
            if(isOnButton(confirma,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                setbkcolor(DARKGRAY);

                draw_vector_in_window(v,Vector,vector_size);

                draw_salvare_valori();

                Afisare_Sortare_Descrescator();

               // AfisareCod();

                Design();

                Organizare();

                //setbkcolor(DARKGRAY);
                setcolor(WHITE);

                char text_run[]="RUN";
                outtextxy(1000,50,text_run);
                Button run;
                Button_Setup(run,1000,50,text_run);

                char text_code[]="CODE";
                outtextxy(1120,50,text_code);
                Button code;
                Button_Setup(code,1120,50,text_code);
                bool code_toggle=false;

                char text_back[]="BACK";
                outtextxy(1260,50,text_back);
                Button b_back;
                Button_Setup(b_back,1260,50,text_back);

              //  char text_pause[]="PAUSE";
              //  outtextxy(600,350,text_pause);
              //  Button pause;
              //  Button_Setup(pause,600,350,text_pause);

                int last_i=0,current_i=0;

                ///loop pt vector/butoane interfata
                while(1) {
                    if(ismouseclick(WM_LBUTTONDOWN)) {
                        int mx=mousex();
                        int my=mousey();
                        if(isInVector(v,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            if(current_i) {
                                setcolor(WHITE);
                                rectangle(v.stanga+v.latura*last_i,v.sus,v.stanga+v.latura*(last_i+1),v.sus+v.latura);
                            }
                            current_i=(mx-v.stanga)/v.latura;
                            setcolor(RED);
                            rectangle(v.stanga+v.latura*current_i,v.sus,v.stanga+v.latura*(current_i+1),v.sus+v.latura);
                            last_i=current_i;
                            char cell_text[10]="";
                            int cell_text_it=0;
                            bool stop_read=false;
                            do {
                                int colt_staga_x=v.stanga+v.latura*last_i;
                                redraw_red_cell_vector(current_i,v);
                                setcolor(WHITE);
                                settextstyle(4,HORIZ_DIR,3);
                                outtextxy(colt_staga_x+(v.latura-textwidth(cell_text))/2,v.sus+(v.latura-textheight(cell_text))/2,cell_text);
                                char c=getch();
                                switch(c) {
                                    case 8: //Backspace
                                        {
                                            if(strlen(cell_text)>0) {
                                                int n=strlen(cell_text);
                                                strcpy(cell_text+n-1,cell_text+n);
                                                vector_size_it--;
                                            }
                                            break;
                                        }
                                    case 13: //Enter
                                        {
                                            stop_read=true;
                                            int value=atoi(cell_text);
                                            Vector[current_i]=value;
                                            cout<<Vector[current_i]<<'\n';
                                            setcolor(WHITE);
                                            rectangle(v.stanga+v.latura*current_i,v.sus,v.stanga+v.latura*(current_i+1),v.sus+v.latura);
                                            break;
                                        }
                                    default:
                                        {
                                            if(strlen(cell_text)<7) {
                                                if(c>='0' && c<='9') {
                                                    cell_text[cell_text_it++]=c;
                                                }
                                            }
                                            break;
                                        }
                                }
                            } while(!stop_read);
                        }
                        else {
                            if(current_i) {
                                setcolor(WHITE);
                                rectangle(v.stanga+v.latura*last_i,v.sus,v.stanga+v.latura*(last_i+1),v.sus+v.latura);
                            }
                            current_i=0;
                        }
                        ///aici adaugi alte if-uri pt butoane
                        if(isOnButton(run,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            Animation_Sortare_Crescator(v.dimensiune,v,Vector);
                        }
                        if(isOnButton(code,mx,my)){
                            clearmouseclick(WM_LBUTTONDOWN);
                            if(!code_toggle) {
                                code_toggle=!code_toggle;
                                AfisareCod_Sortare_Crescator();
                            }
                            else {
                                code_toggle=!code_toggle;
                                setfillstyle(SOLID_FILL,LIGHTGRAY);
                                bar(950,110,1380,680);
                            }
                        }
                    }
                }
            }
        }
    }
}

void Window_Vector_Sortare_Crescator() {
    closegraph();
    initwindow(1400, 700, "BibMat", 150, 50);
    cleardevice();
    setfillstyle(SOLID_FILL,DARKGRAY);
    floodfill(1,1,WHITE);
    setbkcolor(DARKGRAY);

    int Last_i, Current_i;

    char titlu_vector[]="Introduceti dimensiunea vectorului:";
    settextstyle(4,HORIZ_DIR,5);
    outtextxy(1400/2-textwidth(titlu_vector)/2,150,titlu_vector);

    int ok=0;
    int vector_size;
    char text_vector_size[10]="";
    int vector_size_it=0;
    bool stop_read=false;
    do {
        if(textwidth(text_vector_size)==0) {
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(1400/2-textwidth("0"),300,1400/2+textwidth("0"),300+textheight("0"));
        }
        else {
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(1400/2-textwidth(text_vector_size),300,1400/2+textwidth(text_vector_size),300+textheight(text_vector_size));
        }
        setcolor(WHITE);
        outtextxy(1400/2-textwidth(text_vector_size)/2,300,text_vector_size);
        char c=getch();
        switch(c) {
            case 8: //Backspace
            {
                if(strlen(text_vector_size)>0) {
                    int n=strlen(text_vector_size);
                    strcpy(text_vector_size+n-1,text_vector_size+n);
                    vector_size_it--;
                }
                break;
            }
            case 13: //Enter
            {
                if(strlen(text_vector_size)) {
                    stop_read=true;
                    vector_size=atoi(text_vector_size);
                    cout<<vector_size;
                }
                break;
            }
            default:
            {
                if(strlen(text_vector_size)<2) {
                    if(c>='0' && c<='9') {
                        text_vector_size[vector_size_it++]=c;
                    }
                }
                break;
            }
        }
        clearmouseclick(WM_LBUTTONDOWN);
    } while(!stop_read);

    char text_confirma[]="Confirma";
    outtextxy(1400/2-textwidth(text_confirma)/2,400,text_confirma);
    Button confirma;
    Button_Setup(confirma,1400/2-textwidth(text_confirma)/2,400,text_confirma);

    Repere_Vector v;
    if(ok==0)
    {
        v.dimensiune=vector_size;
        ok=1;
    }
    cout<<" "<<v.dimensiune<<"";
    int* Vector;
    initVector(vector_size,Vector);

    ///loop pt buton confirma
    while(1) {
        if(ismouseclick(WM_LBUTTONDOWN)) {
            int mx=mousex();
            int my=mousey();
            if(isOnButton(confirma,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                setbkcolor(DARKGRAY);

                draw_vector_in_window(v,Vector,vector_size);

                draw_salvare_valori();

                Afisare_Sortare_Crescator();

               // AfisareCod();

                Design();

                Organizare();

                //setbkcolor(DARKGRAY);
                setcolor(WHITE);

                char text_run[]="RUN";
                outtextxy(1000,50,text_run);
                Button run;
                Button_Setup(run,1000,50,text_run);

                char text_code[]="CODE";
                outtextxy(1120,50,text_code);
                Button code;
                Button_Setup(code,1120,50,text_code);
                bool code_toggle=false;

                char text_back[]="BACK";
                outtextxy(1260,50,text_back);
                Button b_back;
                Button_Setup(b_back,1260,50,text_back);

              //  char text_pause[]="PAUSE";
              //  outtextxy(600,350,text_pause);
              //  Button pause;
              //  Button_Setup(pause,600,350,text_pause);

                int last_i=0,current_i=0;

                ///loop pt vector/butoane interfata
                while(1) {
                    if(ismouseclick(WM_LBUTTONDOWN)) {
                        int mx=mousex();
                        int my=mousey();
                        if(isInVector(v,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            if(current_i) {
                                setcolor(WHITE);
                                rectangle(v.stanga+v.latura*last_i,v.sus,v.stanga+v.latura*(last_i+1),v.sus+v.latura);
                            }
                            current_i=(mx-v.stanga)/v.latura;
                            setcolor(RED);
                            rectangle(v.stanga+v.latura*current_i,v.sus,v.stanga+v.latura*(current_i+1),v.sus+v.latura);
                            last_i=current_i;
                            char cell_text[10]="";
                            int cell_text_it=0;
                            bool stop_read=false;
                            do {
                                int colt_staga_x=v.stanga+v.latura*last_i;
                                redraw_red_cell_vector(current_i,v);
                                setcolor(WHITE);
                                settextstyle(4,HORIZ_DIR,3);
                                outtextxy(colt_staga_x+(v.latura-textwidth(cell_text))/2,v.sus+(v.latura-textheight(cell_text))/2,cell_text);
                                char c=getch();
                                switch(c) {
                                    case 8: //Backspace
                                        {
                                            if(strlen(cell_text)>0) {
                                                int n=strlen(cell_text);
                                                strcpy(cell_text+n-1,cell_text+n);
                                                vector_size_it--;
                                            }
                                            break;
                                        }
                                    case 13: //Enter
                                        {
                                            stop_read=true;
                                            int value=atoi(cell_text);
                                            Vector[current_i]=value;
                                            cout<<Vector[current_i]<<'\n';
                                            setcolor(WHITE);
                                            rectangle(v.stanga+v.latura*current_i,v.sus,v.stanga+v.latura*(current_i+1),v.sus+v.latura);
                                            break;
                                        }
                                    default:
                                        {
                                            if(strlen(cell_text)<7) {
                                                if(c>='0' && c<='9') {
                                                    cell_text[cell_text_it++]=c;
                                                }
                                            }
                                            break;
                                        }
                                }
                            } while(!stop_read);
                        }
                        else {
                            if(current_i) {
                                setcolor(WHITE);
                                rectangle(v.stanga+v.latura*last_i,v.sus,v.stanga+v.latura*(last_i+1),v.sus+v.latura);
                            }
                            current_i=0;
                        }
                        ///aici adaugi alte if-uri pt butoane
                        if(isOnButton(run,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            Animation_Sortare_Crescator(v.dimensiune,v,Vector);
                        }
                        if(isOnButton(code,mx,my)){
                            clearmouseclick(WM_LBUTTONDOWN);
                            if(!code_toggle) {
                                code_toggle=!code_toggle;
                                AfisareCod_Sortare_Crescator();
                            }
                            else {
                                code_toggle=!code_toggle;
                                setfillstyle(SOLID_FILL,LIGHTGRAY);
                                bar(950,110,1380,680);
                            }
                        }
                        if(isOnButton(b_back,mx,my)){

                        }
                    }
                }
            }
        }
    }
}

void Window_Vector_Shiftare_Dreapta() {
    closegraph();
    initwindow(1400, 700, "BibMat", 150, 50);
    cleardevice();
    setfillstyle(SOLID_FILL,DARKGRAY);
    floodfill(1,1,WHITE);
    setbkcolor(DARKGRAY);
    int Last_i, Current_i,Scalar=0;

    char titlu_vector[]="Introduceti dimensiunea vectorului:";
    settextstyle(4,HORIZ_DIR,5);
    outtextxy(1400/2-textwidth(titlu_vector)/2,150,titlu_vector);

    int ok=0;
    int vector_size;
    char text_vector_size[10]="";
    int vector_size_it=0;
    bool stop_read=false;
    do {
        if(textwidth(text_vector_size)==0) {
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(1400/2-textwidth("0"),300,1400/2+textwidth("0"),300+textheight("0"));
        }
        else {
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(1400/2-textwidth(text_vector_size),300,1400/2+textwidth(text_vector_size),300+textheight(text_vector_size));
        }
        setcolor(WHITE);
        outtextxy(1400/2-textwidth(text_vector_size)/2,300,text_vector_size);
        char c=getch();
        switch(c) {
            case 8: //Backspace
            {
                if(strlen(text_vector_size)>0) {
                    int n=strlen(text_vector_size);
                    strcpy(text_vector_size+n-1,text_vector_size+n);
                    vector_size_it--;
                }
                break;
            }
            case 13: //Enter
            {
                if(strlen(text_vector_size)) {
                    stop_read=true;
                    vector_size=atoi(text_vector_size);
                    cout<<vector_size;
                }
                break;
            }
            default:
            {
                if(strlen(text_vector_size)<2) {
                    if(c>='0' && c<='9') {
                        text_vector_size[vector_size_it++]=c;
                    }
                }
                break;
            }
        }
        clearmouseclick(WM_LBUTTONDOWN);
    } while(!stop_read);

    char text_confirma[]="Confirma";
    outtextxy(1400/2-textwidth(text_confirma)/2,400,text_confirma);
    Button confirma;
    Button_Setup(confirma,1400/2-textwidth(text_confirma)/2,400,text_confirma);

    Repere_Vector v;
    if(ok==0)
    {
        v.dimensiune=vector_size;
        ok=1;
    }
    cout<<" "<<v.dimensiune<<"";
    int* Vector;
    initVector(vector_size,Vector);

    ///loop pt buton confirma
    while(1) {
        if(ismouseclick(WM_LBUTTONDOWN)) {
            int mx=mousex();
            int my=mousey();
            if(isOnButton(confirma,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                setbkcolor(DARKGRAY);

                draw_vector_in_window(v,Vector,vector_size);

                draw_salvare_valoare();

                Afisare_Shifare_Dreapta();

               // AfisareCod();

                Design();

                Organizare();

                //setbkcolor(DARKGRAY);
                setcolor(WHITE);

                char text_run[]="RUN";
                outtextxy(1000,50,text_run);
                Button run;
                Button_Setup(run,1000,50,text_run);

                char text_code[]="CODE";
                outtextxy(1120,50,text_code);
                Button code;
                Button_Setup(code,1120,50,text_code);
                bool code_toggle=false;

                char text_back[]="BACK";
                outtextxy(1260,50,text_back);
                Button b_back;
                Button_Setup(b_back,1260,50,text_back);

              //  char text_pause[]="PAUSE";
              //  outtextxy(600,350,text_pause);
              //  Button pause;
              //  Button_Setup(pause,600,350,text_pause);

                int last_i=0,current_i=0;

                ///loop pt vector/butoane interfata
                while(1) {
                    if(ismouseclick(WM_LBUTTONDOWN)) {
                        int mx=mousex();
                        int my=mousey();
                        if(isInVector(v,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            if(current_i) {
                                setcolor(WHITE);
                                rectangle(v.stanga+v.latura*last_i,v.sus,v.stanga+v.latura*(last_i+1),v.sus+v.latura);
                            }
                            current_i=(mx-v.stanga)/v.latura;
                            setcolor(RED);
                            rectangle(v.stanga+v.latura*current_i,v.sus,v.stanga+v.latura*(current_i+1),v.sus+v.latura);
                            last_i=current_i;
                            char cell_text[10]="";
                            int cell_text_it=0;
                            bool stop_read=false;
                            do {
                                int colt_staga_x=v.stanga+v.latura*last_i;
                                redraw_red_cell_vector(current_i,v);
                                setcolor(WHITE);
                                settextstyle(4,HORIZ_DIR,3);
                                outtextxy(colt_staga_x+(v.latura-textwidth(cell_text))/2,v.sus+(v.latura-textheight(cell_text))/2,cell_text);
                                char c=getch();
                                switch(c) {
                                    case 8: //Backspace
                                        {
                                            if(strlen(cell_text)>0) {
                                                int n=strlen(cell_text);
                                                strcpy(cell_text+n-1,cell_text+n);
                                                vector_size_it--;
                                            }
                                            break;
                                        }
                                    case 13: //Enter
                                        {
                                            stop_read=true;
                                            int value=atoi(cell_text);
                                            Vector[current_i]=value;
                                            cout<<Vector[current_i]<<'\n';
                                            setcolor(WHITE);
                                            rectangle(v.stanga+v.latura*current_i,v.sus,v.stanga+v.latura*(current_i+1),v.sus+v.latura);
                                            break;
                                        }
                                    default:
                                        {
                                            if(strlen(cell_text)<7) {
                                                if(c>='0' && c<='9') {
                                                    cell_text[cell_text_it++]=c;
                                                }
                                            }
                                            break;
                                        }
                                }
                            } while(!stop_read);
                        }
                        else {
                            if(current_i) {
                                setcolor(WHITE);
                                rectangle(v.stanga+v.latura*last_i,v.sus,v.stanga+v.latura*(last_i+1),v.sus+v.latura);
                            }
                            current_i=0;
                        }
                        ///aici adaugi alte if-uri pt butoane
                        if(isOnButton(run,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            Animation_Shifare_Dreapta(v.dimensiune,v,Vector);
                        }
                        if(isOnButton(code,mx,my)){
                            clearmouseclick(WM_LBUTTONDOWN);
                            if(!code_toggle) {
                                code_toggle=!code_toggle;
                                AfisareCod_Shifare_Dreapta();
                            }
                            else {
                                code_toggle=!code_toggle;
                                setfillstyle(SOLID_FILL,LIGHTGRAY);
                                bar(950,110,1380,680);
                            }
                        }
                    }
                }
            }
        }
    }
}

void Window_Vector_Shiftare_Stanga() {
    closegraph();
    initwindow(1400, 700, "BibMat", 150, 50);
    cleardevice();
    setfillstyle(SOLID_FILL,DARKGRAY);
    floodfill(1,1,WHITE);
    setbkcolor(DARKGRAY);

    int Last_i, Current_i,Scalar=0;

    char titlu_vector[]="Introduceti dimensiunea vectorului:";
    settextstyle(4,HORIZ_DIR,5);
    outtextxy(1400/2-textwidth(titlu_vector)/2,150,titlu_vector);

    int ok=0;
    int vector_size;
    char text_vector_size[10]="";
    int vector_size_it=0;
    bool stop_read=false;
    do {
        if(textwidth(text_vector_size)==0) {
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(1400/2-textwidth("0"),300,1400/2+textwidth("0"),300+textheight("0"));
        }
        else {
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(1400/2-textwidth(text_vector_size),300,1400/2+textwidth(text_vector_size),300+textheight(text_vector_size));
        }
        setcolor(WHITE);
        outtextxy(1400/2-textwidth(text_vector_size)/2,300,text_vector_size);
        char c=getch();
        switch(c) {
            case 8: //Backspace
            {
                if(strlen(text_vector_size)>0) {
                    int n=strlen(text_vector_size);
                    strcpy(text_vector_size+n-1,text_vector_size+n);
                    vector_size_it--;
                }
                break;
            }
            case 13: //Enter
            {
                if(strlen(text_vector_size)) {
                    stop_read=true;
                    vector_size=atoi(text_vector_size);
                    cout<<vector_size;
                }
                break;
            }
            default:
            {
                if(strlen(text_vector_size)<2) {
                    if(c>='0' && c<='9') {
                        text_vector_size[vector_size_it++]=c;
                    }
                }
                break;
            }
        }
        clearmouseclick(WM_LBUTTONDOWN);
    } while(!stop_read);

    char text_confirma[]="Confirma";
    outtextxy(1400/2-textwidth(text_confirma)/2,400,text_confirma);
    Button confirma;
    Button_Setup(confirma,1400/2-textwidth(text_confirma)/2,400,text_confirma);

    Repere_Vector v;
    if(ok==0)
    {
        v.dimensiune=vector_size;
        ok=1;
    }
    cout<<" "<<v.dimensiune<<"";
    int* Vector;
    initVector(vector_size,Vector);

    ///loop pt buton confirma
    while(1) {
        if(ismouseclick(WM_LBUTTONDOWN)) {
            int mx=mousex();
            int my=mousey();
            if(isOnButton(confirma,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                setbkcolor(DARKGRAY);

                draw_vector_in_window(v,Vector,vector_size);

                draw_salvare_valoare();

                Afisare_Shifare_Stanga();

               // AfisareCod();

                Design();

                Organizare();

                //setbkcolor(DARKGRAY);
                setcolor(WHITE);

                char text_run[]="RUN";
                outtextxy(1000,50,text_run);
                Button run;
                Button_Setup(run,1000,50,text_run);

                char text_code[]="CODE";
                outtextxy(1120,50,text_code);
                Button code;
                Button_Setup(code,1120,50,text_code);
                bool code_toggle=false;

                char text_back[]="BACK";
                outtextxy(1260,50,text_back);
                Button b_back;
                Button_Setup(b_back,1260,50,text_back);

              //  char text_pause[]="PAUSE";
              //  outtextxy(600,350,text_pause);
              //  Button pause;
              //  Button_Setup(pause,600,350,text_pause);

                int last_i=0,current_i=0;

                ///loop pt vector/butoane interfata
                while(1) {
                    if(ismouseclick(WM_LBUTTONDOWN)) {
                        int mx=mousex();
                        int my=mousey();
                        if(isInVector(v,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            if(current_i) {
                                setcolor(WHITE);
                                rectangle(v.stanga+v.latura*last_i,v.sus,v.stanga+v.latura*(last_i+1),v.sus+v.latura);
                            }
                            current_i=(mx-v.stanga)/v.latura;
                            setcolor(RED);
                            rectangle(v.stanga+v.latura*current_i,v.sus,v.stanga+v.latura*(current_i+1),v.sus+v.latura);
                            last_i=current_i;
                            char cell_text[10]="";
                            int cell_text_it=0;
                            bool stop_read=false;
                            do {
                                int colt_staga_x=v.stanga+v.latura*last_i;
                                redraw_red_cell_vector(current_i,v);
                                setcolor(WHITE);
                                settextstyle(4,HORIZ_DIR,3);
                                outtextxy(colt_staga_x+(v.latura-textwidth(cell_text))/2,v.sus+(v.latura-textheight(cell_text))/2,cell_text);
                                char c=getch();
                                switch(c) {
                                    case 8: //Backspace
                                        {
                                            if(strlen(cell_text)>0) {
                                                int n=strlen(cell_text);
                                                strcpy(cell_text+n-1,cell_text+n);
                                                vector_size_it--;
                                            }
                                            break;
                                        }
                                    case 13: //Enter
                                        {
                                            stop_read=true;
                                            int value=atoi(cell_text);
                                            Vector[current_i]=value;
                                            cout<<Vector[current_i]<<'\n';
                                            setcolor(WHITE);
                                            rectangle(v.stanga+v.latura*current_i,v.sus,v.stanga+v.latura*(current_i+1),v.sus+v.latura);
                                            break;
                                        }
                                    default:
                                        {
                                            if(strlen(cell_text)<7) {
                                                if(c>='0' && c<='9') {
                                                    cell_text[cell_text_it++]=c;
                                                }
                                            }
                                            break;
                                        }
                                }
                            } while(!stop_read);
                        }
                        else {
                            if(current_i) {
                                setcolor(WHITE);
                                rectangle(v.stanga+v.latura*last_i,v.sus,v.stanga+v.latura*(last_i+1),v.sus+v.latura);
                            }
                            current_i=0;
                        }
                        ///aici adaugi alte if-uri pt butoane
                        if(isOnButton(run,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            Animation_Shifare_Stanga(v.dimensiune,v,Vector);
                        }
                        if(isOnButton(code,mx,my)){
                            clearmouseclick(WM_LBUTTONDOWN);
                            if(!code_toggle) {
                                code_toggle=!code_toggle;
                                AfisareCod_Shifare_Stanga();
                            }
                            else {
                                code_toggle=!code_toggle;
                                setfillstyle(SOLID_FILL,LIGHTGRAY);
                                bar(950,110,1380,680);
                            }
                        }
                    }
                }
            }
        }
    }
}

void Window_Vector_Scalar() {
    closegraph();
    initwindow(1400, 700, "BibMat", 150, 50);
    cleardevice();
    setfillstyle(SOLID_FILL,DARKGRAY);
    floodfill(1,1,WHITE);
    setbkcolor(DARKGRAY);

    int Last_i, Current_i,Scalar=0;

    char titlu_vector[]="Introduceti dimensiunea vectorului:";
    settextstyle(4,HORIZ_DIR,5);
    outtextxy(1400/2-textwidth(titlu_vector)/2,150,titlu_vector);

    int ok=0;
    int vector_size;
    char text_vector_size[10]="";
    int vector_size_it=0;
    bool stop_read=false;
    do {
        if(textwidth(text_vector_size)==0) {
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(1400/2-textwidth("0"),300,1400/2+textwidth("0"),300+textheight("0"));
        }
        else {
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(1400/2-textwidth(text_vector_size),300,1400/2+textwidth(text_vector_size),300+textheight(text_vector_size));
        }
        setcolor(WHITE);
        outtextxy(1400/2-textwidth(text_vector_size)/2,300,text_vector_size);
        char c=getch();
        switch(c) {
            case 8: //Backspace
            {
                if(strlen(text_vector_size)>0) {
                    int n=strlen(text_vector_size);
                    strcpy(text_vector_size+n-1,text_vector_size+n);
                    vector_size_it--;
                }
                break;
            }
            case 13: //Enter
            {
                if(strlen(text_vector_size)) {
                    stop_read=true;
                    vector_size=atoi(text_vector_size);
                    cout<<vector_size;
                }
                break;
            }
            default:
            {
                if(strlen(text_vector_size)<2) {
                    if(c>='0' && c<='9') {
                        text_vector_size[vector_size_it++]=c;
                    }
                }
                break;
            }
        }
        clearmouseclick(WM_LBUTTONDOWN);
    } while(!stop_read);

    char text_confirma[]="Confirma";
    outtextxy(1400/2-textwidth(text_confirma)/2,400,text_confirma);
    Button confirma;
    Button_Setup(confirma,1400/2-textwidth(text_confirma)/2,400,text_confirma);

    Repere_Vector v;
    if(ok==0)
    {
        v.dimensiune=vector_size;
        ok=1;
    }
    cout<<" "<<v.dimensiune<<"";
    int* Vector;
    initVector(vector_size,Vector);

    ///loop pt buton confirma
    while(1) {
        if(ismouseclick(WM_LBUTTONDOWN)) {
            int mx=mousex();
            int my=mousey();
            if(isOnButton(confirma,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                setbkcolor(DARKGRAY);

                draw_vector_in_window(v,Vector,vector_size);
                draw_scalar();

                Afisare_Scalar();

               // AfisareCod();

                Design();

                Organizare();

                //setbkcolor(DARKGRAY);
                setcolor(WHITE);

                char text_run[]="RUN";
                outtextxy(1000,50,text_run);
                Button run;
                Button_Setup(run,1000,50,text_run);

                char text_code[]="CODE";
                outtextxy(1120,50,text_code);
                Button code;
                Button_Setup(code,1120,50,text_code);
                bool code_toggle=false;

                char text_back[]="BACK";
                outtextxy(1260,50,text_back);
                Button b_back;
                Button_Setup(b_back,1260,50,text_back);

                Button scalar;
                Button_Setup_XY(scalar,320,130,390,200);
                int scalar_value=0;

                int last_i=0,current_i=0;

                ///loop pt vector/butoane interfata
                while(1) {
                    if(ismouseclick(WM_LBUTTONDOWN)) {
                        int mx=mousex();
                        int my=mousey();
                        if(isInVector(v,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            if(current_i) {
                                setcolor(WHITE);
                                rectangle(v.stanga+v.latura*last_i,v.sus,v.stanga+v.latura*(last_i+1),v.sus+v.latura);
                            }
                            current_i=(mx-v.stanga)/v.latura;
                            setcolor(RED);
                            rectangle(v.stanga+v.latura*current_i,v.sus,v.stanga+v.latura*(current_i+1),v.sus+v.latura);
                            last_i=current_i;
                            char cell_text[10]="";
                            int cell_text_it=0;
                            bool stop_read=false;
                            do {
                                int colt_staga_x=v.stanga+v.latura*last_i;
                                redraw_red_cell_vector(current_i,v);
                                setcolor(WHITE);
                                settextstyle(4,HORIZ_DIR,3);
                                outtextxy(colt_staga_x+(v.latura-textwidth(cell_text))/2,v.sus+(v.latura-textheight(cell_text))/2,cell_text);
                                char c=getch();
                                switch(c) {
                                    case 8: //Backspace
                                        {
                                            if(strlen(cell_text)>0) {
                                                int n=strlen(cell_text);
                                                strcpy(cell_text+n-1,cell_text+n);
                                                vector_size_it--;
                                            }
                                            break;
                                        }
                                    case 13: //Enter
                                        {
                                            stop_read=true;
                                            int value=atoi(cell_text);
                                            Vector[current_i]=value;
                                            cout<<Vector[current_i]<<'\n';
                                            setcolor(WHITE);
                                            rectangle(v.stanga+v.latura*current_i,v.sus,v.stanga+v.latura*(current_i+1),v.sus+v.latura);
                                            break;
                                        }
                                    default:
                                        {
                                            if(strlen(cell_text)<7) {
                                                if(c>='0' && c<='9') {
                                                    cell_text[cell_text_it++]=c;
                                                }
                                            }
                                            break;
                                        }
                                }
                            } while(!stop_read);
                        }
                        else {
                            if(current_i) {
                                setcolor(WHITE);
                                rectangle(v.stanga+v.latura*last_i,v.sus,v.stanga+v.latura*(last_i+1),v.sus+v.latura);
                            }
                            current_i=0;
                        }
                        ///aici adaugi alte if-uri pt butoane
                        if(isOnButton(run,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            Animation_Scalar(v.dimensiune,v,Vector,scalar_value);
                        }
                        if(isOnButton(code,mx,my)){
                            clearmouseclick(WM_LBUTTONDOWN);
                            if(!code_toggle) {
                                code_toggle=!code_toggle;
                                AfisareCod_Scalar();
                            }
                            else {
                                code_toggle=!code_toggle;
                                setfillstyle(SOLID_FILL,LIGHTGRAY);
                                bar(950,110,1380,680);
                            }
                        }
                        if(isOnButton(scalar,mx,my)) {
                            setbkcolor(DARKGRAY);
                            setcolor(RED);
                            rectangle(320,130,390,200);
                            setfillstyle(SOLID_FILL,getbkcolor());
                            floodfill(321,131,RED);

                            char scalar_text[10]="";
                            int scalar_text_it=0;
                            bool stop_read1=false;

                            int latura=scalar.bottom-scalar.top;

                            do {
                                clearmouseclick(WM_LBUTTONDOWN);
                                setcolor(RED);
                                rectangle(320,130,390,200);
                                setfillstyle(SOLID_FILL,getbkcolor());
                                floodfill(321,131,RED);

                                setcolor(WHITE);
                                settextstyle(4,HORIZ_DIR,3);
                                outtextxy(scalar.left+(latura-textwidth(scalar_text))/2,scalar.top+(latura-textheight(scalar_text))/2,scalar_text);
                                char c=getch();
                                switch(c) {
                                    case 8: //Backspace
                                        {
                                            if(strlen(scalar_text)>0) {
                                                int n=strlen(scalar_text);
                                                strcpy(scalar_text+n-1,scalar_text+n);
                                                scalar_text_it--;
                                            }
                                            break;
                                        }
                                    case 13: //Enter
                                        {
                                            stop_read1=true;
                                            scalar_value=atoi(scalar_text);
                                            cout<<scalar_value<<'\n';
                                            setcolor(WHITE);
                                            rectangle(320,130,390,200);
                                            break;
                                        }
                                    default:
                                        {
                                            if(strlen(scalar_text)<7) {
                                                if(c>='0' && c<='9') {
                                                    scalar_text[scalar_text_it++]=c;
                                                }
                                            }
                                            break;
                                        }
                                }
                            } while(!stop_read1);
                        }
                    }
                }
            }
        }
    }
}

void Window_Vector_Produs() {
    closegraph();
    initwindow(1400, 700, "BibMat", 150, 50);
    cleardevice();
    setfillstyle(SOLID_FILL,DARKGRAY);
    floodfill(1,1,WHITE);
    setbkcolor(DARKGRAY);

    char titlu_vector[]="Introduceti dimensiunea vectorului:";
    settextstyle(4,HORIZ_DIR,5);
    outtextxy(1400/2-textwidth(titlu_vector)/2,150,titlu_vector);

    int ok=0;
    int vector_size;
    char text_vector_size[10]="";
    int vector_size_it=0;
    bool stop_read=false;
    do {
        if(textwidth(text_vector_size)==0) {
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(1400/2-textwidth("0"),300,1400/2+textwidth("0"),300+textheight("0"));
        }
        else {
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(1400/2-textwidth(text_vector_size),300,1400/2+textwidth(text_vector_size),300+textheight(text_vector_size));
        }
        setcolor(WHITE);
        outtextxy(1400/2-textwidth(text_vector_size)/2,300,text_vector_size);
        char c=getch();
        switch(c) {
            case 8: //Backspace
            {
                if(strlen(text_vector_size)>0) {
                    int n=strlen(text_vector_size);
                    strcpy(text_vector_size+n-1,text_vector_size+n);
                    vector_size_it--;
                }
                break;
            }
            case 13: //Enter
            {
                if(strlen(text_vector_size)) {
                    stop_read=true;
                    vector_size=atoi(text_vector_size);
                    //cout<<vector_size;
                }
                break;
            }
            default:
            {
                if(strlen(text_vector_size)<2) {
                    if(c>='0' && c<='9') {
                        text_vector_size[vector_size_it++]=c;
                    }
                }
                break;
            }
        }
        clearmouseclick(WM_LBUTTONDOWN);
    } while(!stop_read);

    char text_confirma[]="Confirma";
    outtextxy(1400/2-textwidth(text_confirma)/2,400,text_confirma);
    Button confirma;
    Button_Setup(confirma,1400/2-textwidth(text_confirma)/2,400,text_confirma);

    Repere_Vector v;
    if(ok==0)
    {
        v.dimensiune=vector_size;
        ok=1;
    }
    //cout<<" "<<v.dimensiune<<"";
    int* Vector;
    initVector(vector_size,Vector);

    ///loop pt buton confirma
    while(1) {
        if(ismouseclick(WM_LBUTTONDOWN)) {
            int mx=mousex();
            int my=mousey();
            if(isOnButton(confirma,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                setbkcolor(DARKGRAY);

                draw_vector_in_window(v,Vector,vector_size);

               // AfisareCod();

                Design();

                Organizare();

                setcolor(WHITE);
                setbkcolor(BLACK);
                settextstyle(10,HORIZ_DIR,5);

                char text_run[]="RUN";
                outtextxy(1000,50,text_run);
                Button run;
                Button_Setup(run,1000,50,text_run);

                char text_code[]="CODE";
                outtextxy(1120,50,text_code);
                Button code;
                Button_Setup(code,1120,50,text_code);
                bool code_toggle=false;

                char text_back[]="BACK";
                outtextxy(1260,50,text_back);
                Button b_back;
                Button_Setup(b_back,1260,50,text_back);

                char text_cread[]="CONSOLE READ";
                outtextxy(1020,100,text_cread);
                Button cread;
                Button_Setup(cread,1020,100,text_cread);

           		setbkcolor(DARKGRAY);

                AfisareProdus();

                bool close_loop=false;
//                bool code_toggle=false;
                int last_i=0,current_i=0;

                ///loop pt vector/butoane interfata
                while(1) {
                    if(ismouseclick(WM_LBUTTONDOWN)) {
                        int mx=mousex();
                        int my=mousey();
                        if(isInVector(v,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            gwindow_vector_cell_read(v,Vector,last_i,current_i,mx,my);
                        }
                        else {
                            if(current_i) {
                                setcolor(WHITE);
                                rectangle(v.stanga+v.latura*last_i,v.sus,v.stanga+v.latura*(last_i+1),v.sus+v.latura);
                            }
                            current_i=0;
                        }
                        ///aici adaugi alte if-uri pt butoane

                        if(isOnButton(run,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            Animation_Produs(v.dimensiune,v,Vector);
                        }
                        if(isOnButton(code,mx,my)){
                            clearmouseclick(WM_LBUTTONDOWN);
                            if(!code_toggle) {
                                code_toggle=!code_toggle;
                                AfisareCodProdus();
                            }
                            else {
                                code_toggle=!code_toggle;
                                setfillstyle(SOLID_FILL,LIGHTGRAY);
                                bar(950,110,1380,680);
                            }
                        }
                        if(isOnButton(cread,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            for(int i=1;i<=vector_size;i++) {
                                cin>>Vector[i];
                            }
                            draw_vector_in_window(v,Vector,vector_size);
                        }
                    }
                }
            }
        }
    }
}

void Window_Vector_Scadere() {
    closegraph();
    initwindow(1400, 700, "BibMat", 150, 50);
    cleardevice();
    setfillstyle(SOLID_FILL,DARKGRAY);
    floodfill(1,1,WHITE);
    setbkcolor(DARKGRAY);

    char titlu_vector[]="Introduceti dimensiunea vectorului:";
    settextstyle(4,HORIZ_DIR,5);
    outtextxy(1400/2-textwidth(titlu_vector)/2,150,titlu_vector);

    int ok=0;
    int vector_size;
    char text_vector_size[10]="";
    int vector_size_it=0;
    bool stop_read=false;
    do {
        if(textwidth(text_vector_size)==0) {
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(1400/2-textwidth("0"),300,1400/2+textwidth("0"),300+textheight("0"));
        }
        else {
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(1400/2-textwidth(text_vector_size),300,1400/2+textwidth(text_vector_size),300+textheight(text_vector_size));
        }
        setcolor(WHITE);
        outtextxy(1400/2-textwidth(text_vector_size)/2,300,text_vector_size);
        char c=getch();
        switch(c) {
            case 8: //Backspace
            {
                if(strlen(text_vector_size)>0) {
                    int n=strlen(text_vector_size);
                    strcpy(text_vector_size+n-1,text_vector_size+n);
                    vector_size_it--;
                }
                break;
            }
            case 13: //Enter
            {
                if(strlen(text_vector_size)) {
                    stop_read=true;
                    vector_size=atoi(text_vector_size);
                    //cout<<vector_size;
                }
                break;
            }
            default:
            {
                if(strlen(text_vector_size)<2) {
                    if(c>='0' && c<='9') {
                        text_vector_size[vector_size_it++]=c;
                    }
                }
                break;
            }
        }
        clearmouseclick(WM_LBUTTONDOWN);
    } while(!stop_read);

    char text_confirma[]="Confirma";
    outtextxy(1400/2-textwidth(text_confirma)/2,400,text_confirma);
    Button confirma;
    Button_Setup(confirma,1400/2-textwidth(text_confirma)/2,400,text_confirma);

    Repere_Vector v;
    if(ok==0)
    {
        v.dimensiune=vector_size;
        ok=1;
    }
    //cout<<" "<<v.dimensiune<<"";
    int* Vector;
    initVector(vector_size,Vector);

    ///loop pt buton confirma
    while(1) {
        if(ismouseclick(WM_LBUTTONDOWN)) {
            int mx=mousex();
            int my=mousey();
            if(isOnButton(confirma,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                setbkcolor(DARKGRAY);

                draw_vector_in_window(v,Vector,vector_size);

               // AfisareCod();

                Design();

                Organizare();

                setcolor(WHITE);
                setbkcolor(BLACK);
                settextstyle(10,HORIZ_DIR,5);

                char text_run[]="RUN";
                outtextxy(1000,50,text_run);
                Button run;
                Button_Setup(run,1000,50,text_run);

                char text_code[]="CODE";
                outtextxy(1120,50,text_code);
                Button code;
                Button_Setup(code,1120,50,text_code);
                bool code_toggle=false;

                char text_back[]="BACK";
                outtextxy(1260,50,text_back);
                Button b_back;
                Button_Setup(b_back,1260,50,text_back);

                char text_cread[]="CONSOLE READ";
                outtextxy(1020,100,text_cread);
                Button cread;
                Button_Setup(cread,1020,100,text_cread);

           		setbkcolor(DARKGRAY);

                AfisareScadere();

                bool close_loop=false;
//                bool code_toggle=false;
                int last_i=0,current_i=0;

                ///loop pt vector/butoane interfata
                while(1) {
                    if(ismouseclick(WM_LBUTTONDOWN)) {
                        int mx=mousex();
                        int my=mousey();
                        if(isInVector(v,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            gwindow_vector_cell_read(v,Vector,last_i,current_i,mx,my);
                        }
                        else {
                            if(current_i) {
                                setcolor(WHITE);
                                rectangle(v.stanga+v.latura*last_i,v.sus,v.stanga+v.latura*(last_i+1),v.sus+v.latura);
                            }
                            current_i=0;
                        }
                        ///aici adaugi alte if-uri pt butoane

                        if(isOnButton(run,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            Animation_Scadere(v.dimensiune,v,Vector);
                        }
                        if(isOnButton(code,mx,my)){
                            clearmouseclick(WM_LBUTTONDOWN);
                            if(!code_toggle) {
                                code_toggle=!code_toggle;
                                AfisareCodScadere();
                            }
                            else {
                                code_toggle=!code_toggle;
                                setfillstyle(SOLID_FILL,LIGHTGRAY);
                                bar(950,110,1380,680);
                            }
                        }
                        if(isOnButton(cread,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            for(int i=1;i<=vector_size;i++) {
                                cin>>Vector[i];
                            }
                            draw_vector_in_window(v,Vector,vector_size);
                        }
                    }
                }
            }
        }
    }
}

void Window_Vector_Suma() {
    closegraph();
    initwindow(1400, 700, "BibMat", 150, 50);
    cleardevice();
    setfillstyle(SOLID_FILL,DARKGRAY);
    floodfill(1,1,WHITE);
    setbkcolor(DARKGRAY);

    char titlu_vector[]="Introduceti dimensiunea vectorului:";
    settextstyle(4,HORIZ_DIR,5);
    outtextxy(1400/2-textwidth(titlu_vector)/2,150,titlu_vector);

    int ok=0;
    int vector_size;
    char text_vector_size[10]="";
    int vector_size_it=0;
    bool stop_read=false;
    do {
        if(textwidth(text_vector_size)==0) {
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(1400/2-textwidth("0"),300,1400/2+textwidth("0"),300+textheight("0"));
        }
        else {
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(1400/2-textwidth(text_vector_size),300,1400/2+textwidth(text_vector_size),300+textheight(text_vector_size));
        }
        setcolor(WHITE);
        outtextxy(1400/2-textwidth(text_vector_size)/2,300,text_vector_size);
        char c=getch();
        switch(c) {
            case 8: //Backspace
            {
                if(strlen(text_vector_size)>0) {
                    int n=strlen(text_vector_size);
                    strcpy(text_vector_size+n-1,text_vector_size+n);
                    vector_size_it--;
                }
                break;
            }
            case 13: //Enter
            {
                if(strlen(text_vector_size)) {
                    stop_read=true;
                    vector_size=atoi(text_vector_size);
                    //cout<<vector_size;
                }
                break;
            }
            default:
            {
                if(strlen(text_vector_size)<2) {
                    if(c>='0' && c<='9') {
                        text_vector_size[vector_size_it++]=c;
                    }
                }
                break;
            }
        }
        clearmouseclick(WM_LBUTTONDOWN);
    } while(!stop_read);

    char text_confirma[]="Confirma";
    outtextxy(1400/2-textwidth(text_confirma)/2,400,text_confirma);
    Button confirma;
    Button_Setup(confirma,1400/2-textwidth(text_confirma)/2,400,text_confirma);

    Repere_Vector v;
    if(ok==0)
    {
        v.dimensiune=vector_size;
        ok=1;
    }
    //cout<<" "<<v.dimensiune<<"";
    int* Vector;
    initVector(vector_size,Vector);

    ///loop pt buton confirma
    while(1) {
        if(ismouseclick(WM_LBUTTONDOWN)) {
            int mx=mousex();
            int my=mousey();
            if(isOnButton(confirma,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                setbkcolor(DARKGRAY);

                draw_vector_in_window(v,Vector,vector_size);

               // AfisareCod();

                Design();

                Organizare();

                setcolor(WHITE);
                setbkcolor(BLACK);
                settextstyle(10,HORIZ_DIR,5);

                char text_run[]="RUN";
                outtextxy(1000,50,text_run);
                Button run;
                Button_Setup(run,1000,50,text_run);

                char text_code[]="CODE";
                outtextxy(1120,50,text_code);
                Button code;
                Button_Setup(code,1120,50,text_code);
                bool code_toggle=false;

                char text_back[]="BACK";
                outtextxy(1260,50,text_back);
                Button b_back;
                Button_Setup(b_back,1260,50,text_back);

                char text_cread[]="CONSOLE READ";
                outtextxy(1020,100,text_cread);
                Button cread;
                Button_Setup(cread,1020,100,text_cread);

           		setbkcolor(DARKGRAY);

                AfisareSuma();

                bool close_loop=false;
//                bool code_toggle=false;
                int last_i=0,current_i=0;

                ///loop pt vector/butoane interfata
                while(1) {
                    if(ismouseclick(WM_LBUTTONDOWN)) {
                        int mx=mousex();
                        int my=mousey();
                        if(isInVector(v,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            gwindow_vector_cell_read(v,Vector,last_i,current_i,mx,my);
                        }
                        else {
                            if(current_i) {
                                setcolor(WHITE);
                                rectangle(v.stanga+v.latura*last_i,v.sus,v.stanga+v.latura*(last_i+1),v.sus+v.latura);
                            }
                            current_i=0;
                        }
                        ///aici adaugi alte if-uri pt butoane

                        if(isOnButton(run,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            Animation_Suma(v.dimensiune,v,Vector);
                        }
                        if(isOnButton(code,mx,my)){
                            clearmouseclick(WM_LBUTTONDOWN);
                            if(!code_toggle) {
                                code_toggle=!code_toggle;
                                AfisareCodSuma();
                            }
                            else {
                                code_toggle=!code_toggle;
                                setfillstyle(SOLID_FILL,LIGHTGRAY);
                                bar(950,110,1380,680);
                            }
                        }
                        if(isOnButton(cread,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            for(int i=1;i<=vector_size;i++) {
                                cin>>Vector[i];
                            }
                            draw_vector_in_window(v,Vector,vector_size);
                        }
                    }
                }
            }
        }
    }
}
