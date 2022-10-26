#ifndef VECTORANIMATIONS_H
#define VECTORANIMATIONS_H

#include "VectorFunctions.h"

void AfisareCodSuma();
void Animation_Suma(int DimVect,Repere_Vector v,int Vector[13]);
void AfisareSuma();
void AfisareCodScadere();
void Animation_Scadere(int DimVect,Repere_Vector v,int Vector[13]);
void AfisareScadere();
void AfisareCodProdus();
void Animation_Produs(int DimVect,Repere_Vector v,int Vector[13]);
void AfisareProdus();
void draw_scalar();
void AfisareCod_Scalar();
void Animation_Scalar(int DimVect,Repere_Vector v,int Vector[13],int scalar);
void Afisare_Scalar();
void draw_salvare_valoare();
void AfisareCod_Shifare_Stanga();
void Animation_Shifare_Stanga(int DimVect,Repere_Vector v,int Vector[13]);
void Afisare_Shifare_Stanga();
void AfisareCod_Shifare_Dreapta();
void Animation_Shifare_Dreapta(int DimVect,Repere_Vector v,int Vector[13]);
void Afisare_Shifare_Dreapta();
void draw_salvare_valori();
void AfisareCod_Sortare_Crescator();
void Redraw_Casuta(int color,int stg,int sus,int stgplus,int susplus);
void Animation_Sortare_Crescator(int DimVect,Repere_Vector v,int Vector[13]);
void Afisare_Sortare_Crescator();
void AfisareCod_Sortare_Descrescator();
void Animation_Sortare_Descrescator(int DimVect,Repere_Vector v,int Vector[13]);
void Afisare_Sortare_Descrescator();
void Window_Vector_Sortare_Descrescator();
void Window_Vector_Sortare_Crescator();
void Window_Vector_Shiftare_Dreapta();
void Window_Vector_Shiftare_Stanga();
void Window_Vector_Scalar();
void Window_Vector_Produs();
void Window_Vector_Scadere();
void Window_Vector_Suma();

#endif // VECTORANIMATIONS_H
