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
#include "MatrixFunctions.h"

using namespace std;

void Button_Setup_XY(Button &b, int left, int top, int right, int bottom) {
    b.left=left;
    b.top=top;
    b.right=right;
    b.bottom=bottom;
}

void initVector(int n, int* &Vector) {
    Vector=new int[n+1];
    for(int i=1;i<=n;i++) {
        Vector[i]=0;
        }
    }

bool isInVector(Repere_Vector v, int x, int y) {
    if((v.stanga<x && v.stanga+v.latura*v.dimensiune>x) && (v.sus<y && v.sus+v.latura>y))
        return true;
    return false;
}
void draw_vector_in_window(Repere_Vector &v, int Vector[], int n)
{
    int i;
    v.width=400; v.height=200;
    v.stanga=40;
    v.sus=30;
    v.latura=70;
    setcolor(WHITE);
    for (i=0; i<v.dimensiune; i++)
    {
        rectangle(v.stanga+v.latura*i,v.sus,v.stanga+v.latura*(i+1),v.sus+v.latura);

        char cell_text[11]="";
        char* g_text=(char*) malloc(11);
        memset(g_text,'\0',11);
        memset(cell_text,'\0',11);
        itoa(Vector[i+1],cell_text,10);
        int_gprint_check(cell_text,g_text,11,3,10);

        int colt_staga_x=v.stanga+v.latura*i;
        setcolor(WHITE);
        settextstyle(4,HORIZ_DIR,3);
        outtextxy(colt_staga_x+(v.latura-textwidth(g_text))/2,v.sus+(v.latura-textheight(g_text))/2,g_text);
    }
}

void redraw_red_cell_vector(int i, Repere_Vector v) {
    setcolor(RED);
    rectangle(v.stanga+v.latura*i,v.sus,v.stanga+v.latura*(i+1),v.sus+v.latura);
    setfillstyle(SOLID_FILL,getbkcolor());
    floodfill(v.stanga+v.latura*i+1,v.sus+1,RED);
}

void gwindow_vector_cell_read(Repere_Vector v, int vec[], int &last_i, int &current_i, int mx, int my) {
    if(current_i) {
        setcolor(WHITE);
        rectangle(v.stanga+v.latura*last_i,v.sus,v.stanga+v.latura*(last_i+1),v.sus+v.latura);
    }
    current_i=(mx-v.stanga)/v.latura;
    setcolor(RED);
    rectangle(v.stanga+v.latura*current_i,v.sus,v.stanga+v.latura*(current_i+1),v.sus+v.latura);
    last_i=current_i;

    char cell_text[11]="";
    int cell_text_it=0;
    char* g_text=(char*) malloc(11);
    memset(g_text,'\0',11);
    bool stop_read=false;
    do {
        redraw_red_cell_vector(current_i,v);

        int colt_staga_x=v.stanga+v.latura*last_i;
        setcolor(WHITE);
        settextstyle(4,HORIZ_DIR,3);
        if(strlen(cell_text)) {
            outtextxy(colt_staga_x+(v.latura-textwidth(g_text))/2,v.sus+(v.latura-textheight(g_text))/2,g_text);
        }
        else {
            outtextxy(colt_staga_x+(v.latura-textwidth("0"))/2,v.sus+(v.latura-textheight("0"))/2,"0");
        }

        char c=getch();
        switch(c) {
            case 8: //Backspace
            {
                if(strlen(cell_text)>0) {
                    int n=strlen(cell_text);
                    strcpy(cell_text+n-1,cell_text+n);
                    cell_text_it--;

                    if(strlen(cell_text)<10) {
                        memset(g_text,'\0',11);
                        int_gprint_check(cell_text,g_text,11,4,10);
                    }
                    break;
                }

            }
            case 13: //Enter
            {
                stop_read=true;
                int value=atoi(cell_text);
                vec[current_i]=atoi(cell_text);
                setcolor(WHITE);
                rectangle(v.stanga+v.latura*last_i,v.sus,v.stanga+v.latura*(last_i+1),v.sus+v.latura);
                break;
            }
            case 32: //Space
            {
                stop_read=true;
                int value=atoi(cell_text);
                vec[current_i]=atoi(cell_text);
                setcolor(WHITE);
                rectangle(v.stanga+v.latura*last_i,v.sus,v.stanga+v.latura*(last_i+1),v.sus+v.latura);
                break;
            }
            default:
            {
                if(strlen(cell_text)<10) {
                    if(c>='0' && c<='9' || c=='-') {
                        cell_text[cell_text_it++]=c;
                        memset(g_text,'\0',6);
                        int_gprint_check(cell_text,g_text,11,4,10);
                    }
                }
                break;
            }
        }
    } while(!stop_read);
}

void Design()
{
    settextstyle(10,HORIZ_DIR,5);

    line(950,670,950,30);

    rectangle(1000,30,1130,100);
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    floodfill(1001,31,WHITE);

    rectangle(1220,30,1350,100);
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    floodfill(1221,31,WHITE);
}

void Organizare()
{
    setcolor(CYAN);
    rectangle(950,20,1380,680);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    floodfill(951,21,CYAN);
}

void Draw_vector_in_window(Repere_Vector &v, int x, int y)
{
    int i;
    v.width=400; v.height=200;
    v.stanga=x;
    v.sus=y;
    v.latura=70;
    setcolor(WHITE);
    for (i=0; i<v.dimensiune; i++)
    {
        rectangle(v.stanga+v.latura*i,v.sus,v.stanga+v.latura*(i+1),v.sus+v.latura);
    }
}
