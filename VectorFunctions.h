#ifndef VECTORFUNCTIONS_H
#define VECTORFUNCTIONS_H

#include "Button.h"

struct Repere_Vector
{
    int stanga,sus,width,height,latura,dimensiune;
};

void Button_Setup_XY(Button &b, int left, int top, int right, int bottom);
void initVector(int n, int* &Vector);
bool isInVector(Repere_Vector v, int x, int y);
void draw_vector_in_window(Repere_Vector &v, int Vector[], int n);
void redraw_red_cell_vector(int i, Repere_Vector v);
void gwindow_vector_cell_read(Repere_Vector v, int vec[], int &last_i, int &current_i, int mx, int my);
void Design();
void Organizare();
void Draw_vector_in_window(Repere_Vector &v, int x, int y);

#endif // VECTORFUNCTIONS_H
