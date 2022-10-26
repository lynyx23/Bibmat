#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MatrixFunctions.h"
#include "Button.h"

using namespace std;

///=====================================================
///                    SUMA ELEM MATRICE
///=====================================================
void Animation_Matrix_Cell_Sum(Matrix m, bool &has_ran) {
    has_ran=true;
    int current_i=0,current_j=0,last_i=0,last_j=0;
    int offset_x=0,offset_y=0;
    int left_limit=85,right_limit=865,start_y=735+textheight("0");
    long long sum=0;
    for(current_i=1;current_i<=m.n;current_i++) {
        int offset1=0;
        for(current_j=1;current_j<=m.m;current_j++) {
            if(last_i && last_j) {
                Animation_Redraw_Cell(GREEN,last_i,last_j,m);
            }
            Animation_Redraw_Cell(RED,current_i,current_j,m);

            int text_x1=85;
            int text_y1=735;

            setfillstyle(SOLID_FILL,LIGHTMAGENTA);
            bar(text_x1,text_y1,text_x1+offset1,text_y1+textheight("0"));

            settextstyle(4,HORIZ_DIR,2);
            setbkcolor(LIGHTMAGENTA);
            char text1[]="Adunam elementul din celula de la linia ";
            char text2[2]="";
            itoa(current_i,text2,10);
            char text3[]=" si coloana ";
            char text4[2]="";
            itoa(current_j,text4,10);
            outtextxy(text_x1,text_y1,text1);
            offset1+=textwidth(text1);
            outtextxy(text_x1+offset1,text_y1,text2);
            offset1+=textwidth(text2);
            outtextxy(text_x1+offset1,text_y1,text3);
            offset1+=textwidth(text3);
            outtextxy(text_x1+offset1,text_y1,text4);
            offset1+=textwidth(text4);
            outtextxy(text_x1+offset1,text_y1,":");
            offset1=0;
            setbkcolor(DARKGRAY);

            char text_plus[]=" + ";
            char text_plus_left[]="+ ";
            char text_plus_right[]=" +";
            char text_egal[]=" = ";
            char text_egal_left[]="= ";
            char text_egal_right[]=" =";
            char text_number[11]="";
            itoa(m.mat[current_i-1][current_j-1],text_number,10);
            sum+=m.mat[current_i-1][current_j-1];
            setbkcolor(LIGHTMAGENTA);
            if(left_limit+offset_x+textwidth(text_number)<=right_limit) {
                outtextxy(left_limit+offset_x,start_y+offset_y,text_number);
                offset_x+=textwidth(text_number);
                if(left_limit+offset_x+textwidth(text_plus)<=right_limit) {
                    if(current_i==m.n && current_j==m.m) {
                        outtextxy(left_limit+offset_x,start_y+offset_y,text_egal);
                        offset_x+=textwidth(text_egal);
                    }
                    else {
                        outtextxy(left_limit+offset_x,start_y+offset_y,text_plus);
                        offset_x+=textwidth(text_plus);
                    }
                }
                else {
                    if(current_i==m.n && current_j==m.m) {
                        offset_x=0;
                        offset_y+=textheight("0");
                        outtextxy(left_limit+offset_x,start_y+offset_y,text_egal_left);
                        offset_x+=textwidth(text_egal_left);
                    }
                    else {
                        offset_x=0;
                        offset_y+=textheight("0");
                        outtextxy(left_limit+offset_x,start_y+offset_y,text_plus_left);
                        offset_x+=textwidth(text_plus_left);
                    }
                }
            }
            else {
                offset_x=0;
                offset_y+=textheight("0");
                outtextxy(left_limit+offset_x,start_y+offset_y,text_number);
                offset_x+=textwidth(text_number);
                if(current_i==m.n && current_j==m.m) {
                    outtextxy(left_limit+offset_x,start_y+offset_y,text_egal);
                    offset_x+=textwidth(text_egal);
                }
                else {
                    outtextxy(left_limit+offset_x,start_y+offset_y,text_plus);
                    offset_x+=textwidth(text_plus);
                }
            }
            setbkcolor(DARKGRAY);
            delay(1000);
            last_i=current_i;
            last_j=current_j;
        }
    }
    Animation_Redraw_Cell(GREEN,last_i,last_j,m);
    char nr[12]="";
    itoa(sum,nr,10);
    if(left_limit+offset_x<right_limit) {
        setbkcolor(LIGHTMAGENTA);
        settextstyle(4,HORIZ_DIR,2);
        setcolor(WHITE);
        outtextxy(left_limit+offset_x,start_y+offset_y,nr);
        setbkcolor(DARKGRAY);
    }
}

void Window_Matrix_Cell_Sum() {
    int G_WINDOW_WIDTH=1600;
    int G_WINDOW_HEIGHT=900;
    int M_WINDOW_WIDTH=1150;
    int M_WINDOW_HEIGHT=900;

    closegraph();
    initwindow(G_WINDOW_WIDTH, G_WINDOW_HEIGHT, "BibMat", 150, 50);
    cleardevice();
    setfillstyle(SOLID_FILL,DARKGRAY);
    floodfill(1,1,WHITE);
    setbkcolor(DARKGRAY);

    Matrix m;

    char titlu_matrici[]="Introduceti dimensiunea matricei:";
    settextstyle(4,HORIZ_DIR,5);
    setcolor(WHITE);
    outtextxy(G_WINDOW_WIDTH/2-textwidth(titlu_matrici)/2,100,titlu_matrici);

    gwindow_read_int(m.n,2,1,6,0,G_WINDOW_WIDTH/2-50,G_WINDOW_HEIGHT/2);
    gwindow_read_int(m.m,2,1,6,0,G_WINDOW_WIDTH/2+50,G_WINDOW_HEIGHT/2);

    char text_confirma[]="Confirma";
    outtextxy((G_WINDOW_WIDTH-textwidth(text_confirma))/2-200,650,text_confirma);
    Button confirma;
    Button_Setup(confirma,(G_WINDOW_WIDTH-textwidth(text_confirma))/2-200,650,text_confirma);

    char text_anuleaza[]="Anuleaza";
    outtextxy((G_WINDOW_WIDTH-textwidth(text_anuleaza))/2+200,650,text_anuleaza);
    Button anuleaza;
    Button_Setup(anuleaza,(G_WINDOW_WIDTH-textwidth(text_anuleaza))/2+200,650,text_anuleaza);

    initMatrix(m);
    while(1) {
        if(ismouseclick(WM_LBUTTONDOWN)) {
            int mx=mousex();
            int my=mousey();
            if(isOnButton(anuleaza,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                gwindow_read_int(m.n,2,1,6,0,G_WINDOW_WIDTH/2-50,G_WINDOW_HEIGHT/2);
                gwindow_read_int(m.m,2,1,6,0,G_WINDOW_WIDTH/2+50,G_WINDOW_HEIGHT/2);
                delete m.mat;
                initMatrix(m);
            }
            if(isOnButton(confirma,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                draw_matrix_in_window(m,M_WINDOW_WIDTH-400,M_WINDOW_HEIGHT-200);
                Design_Matrix();
                int last_i=0, last_j=0,current_i=0,current_j=0;

                setcolor(WHITE);
                setbkcolor(BLACK);
                settextstyle(10,HORIZ_DIR,5);

                char text_run[]="RUN";
                outtextxy(1165,50,text_run);
                Button run;
                Button_Setup(run,1165,50,text_run);

                char text_code[]="CODE";
                outtextxy(1305,50,text_code);
                Button code;
                Button_Setup(code,1305,50,text_code);

                char text_back[]="BACK";
                outtextxy(1465,50,text_back);
                Button b_back;
                Button_Setup(b_back,1465,50,text_back);

                char text_cread[]="CONSOLE READ";
                outtextxy(1225,100,text_cread);
                Button cread;
                Button_Setup(cread,1225,100,text_cread);

                setbkcolor(DARKGRAY);

                bool code_toggle=false;
                bool has_ran=false;
                while(1) {
                    if(ismouseclick(WM_LBUTTONDOWN)) {
                        clearmouseclick(WM_LBUTTONDOWN);
                        int mx=mousex();
                        int my=mousey();
                        if(isInMatrix(m,mx,my)) {
                            gwindow_matrix_cell_read(m,last_i,last_j,current_i,current_j,mx,my);
                        }
                        else {
                            if(current_i && current_j) {
                                setcolor(WHITE);
                                rectangle(m.stanga+m.latura*(last_j-1),m.sus+m.latura*(last_i-1),m.stanga+m.latura*last_j,m.sus+m.latura*last_i);
                            }
                            current_i=current_j=0;
                        }
                        if(isOnButton(run,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            if(has_ran) {
                                setcolor(LIGHTGRAY);
                                rectangle(75,730,1150-75,880);
                                setfillstyle(SOLID_FILL,LIGHTMAGENTA);
                                floodfill(76,731,LIGHTGRAY);
                                draw_matrix_in_window(m,M_WINDOW_WIDTH-400,M_WINDOW_HEIGHT-200);
                                has_ran=false;
                            }
                            Animation_Matrix_Cell_Sum(m,has_ran);
                        }
                        if(isOnButton(b_back,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            return;
                        }
                        if(isOnButton(cread,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            for(int i=0;i<m.n;i++) {
                                for(int j=0;j<m.m;j++) {
                                    cin>>m.mat[i][j];
                                }
                            }
                            draw_matrix_in_window(m,M_WINDOW_WIDTH-400,M_WINDOW_HEIGHT-200);
                        }
                    }
                }
            }
            else {
                clearmouseclick(WM_LBUTTONDOWN);
            }
        }
    }
    //return;
}

///=====================================================
///                DIFERENTA ELEM MATRICE
///=====================================================
void Animation_Matrix_Cell_Sub(Matrix m, bool &has_ran) {
    has_ran=true;
    int current_i=0,current_j=0,last_i=0,last_j=0;
    int offset_x=0,offset_y=0;
    int left_limit=85,right_limit=865,start_y=735+textheight("0");
    long long diff=0;
    for(current_i=1;current_i<=m.n;current_i++) {
        int offset1=0;
        for(current_j=1;current_j<=m.m;current_j++) {
            if(last_i && last_j) {
                Animation_Redraw_Cell(GREEN,last_i,last_j,m);
            }
            Animation_Redraw_Cell(RED,current_i,current_j,m);

            int text_x1=85;
            int text_y1=735;

            setfillstyle(SOLID_FILL,LIGHTMAGENTA);
            bar(text_x1,text_y1,text_x1+offset1,text_y1+textheight("0"));

            settextstyle(4,HORIZ_DIR,2);
            setbkcolor(LIGHTMAGENTA);
            char text1[]="Scadem elementul din celula de la linia ";
            char text2[2]="";
            itoa(current_i,text2,10);
            char text3[]=" si coloana ";
            char text4[2]="";
            itoa(current_j,text4,10);
            outtextxy(text_x1,text_y1,text1);
            offset1+=textwidth(text1);
            outtextxy(text_x1+offset1,text_y1,text2);
            offset1+=textwidth(text2);
            outtextxy(text_x1+offset1,text_y1,text3);
            offset1+=textwidth(text3);
            outtextxy(text_x1+offset1,text_y1,text4);
            offset1+=textwidth(text4);
            outtextxy(text_x1+offset1,text_y1,":");
            offset1=0;
            setbkcolor(DARKGRAY);

            char text_minus[]=" - ";
            char text_minus_left[]="- ";
            char text_minus_right[]=" -";
            char text_egal[]=" = ";
            char text_egal_left[]="= ";
            char text_egal_right[]=" =";
            char text_number[11]="";
            itoa(m.mat[current_i-1][current_j-1],text_number,10);
            diff-=m.mat[current_i-1][current_j-1];
            setbkcolor(LIGHTMAGENTA);

            if(current_i==1 && current_j==1 && m.mat[0][0]) {
                outtextxy(left_limit,start_y+offset_y,text_minus_left);
                offset_x+=textwidth(text_minus_left);
            }

            if(left_limit+offset_x+textwidth(text_number)<=right_limit) {
                outtextxy(left_limit+offset_x,start_y+offset_y,text_number);
                offset_x+=textwidth(text_number);
                if(left_limit+offset_x+textwidth(text_minus)<=right_limit) {
                    if(current_i==m.n && current_j==m.m) {
                        outtextxy(left_limit+offset_x,start_y+offset_y,text_egal);
                        offset_x+=textwidth(text_egal);
                    }
                    else {
                        outtextxy(left_limit+offset_x,start_y+offset_y,text_minus);
                        offset_x+=textwidth(text_minus);
                    }
                }
                else {
                    if(current_i==m.n && current_j==m.m) {
                        offset_x=0;
                        offset_y+=textheight("0");
                        outtextxy(left_limit+offset_x,start_y+offset_y,text_egal_left);
                        offset_x+=textwidth(text_egal_left);
                    }
                    else {
                        offset_x=0;
                        offset_y+=textheight("0");
                        outtextxy(left_limit+offset_x,start_y+offset_y,text_minus_left);
                        offset_x+=textwidth(text_minus_left);
                    }
                }
            }
            else {
                offset_x=0;
                offset_y+=textheight("0");
                outtextxy(left_limit+offset_x,start_y+offset_y,text_number);
                offset_x+=textwidth(text_number);
                if(current_i==m.n && current_j==m.m) {
                    outtextxy(left_limit+offset_x,start_y+offset_y,text_egal);
                    offset_x+=textwidth(text_egal);
                }
                else {
                    outtextxy(left_limit+offset_x,start_y+offset_y,text_minus);
                    offset_x+=textwidth(text_minus);
                }
            }
            setbkcolor(DARKGRAY);
            delay(1000);
            last_i=current_i;
            last_j=current_j;
        }
    }
    Animation_Redraw_Cell(GREEN,last_i,last_j,m);
    char nr[12]="";
    itoa(diff,nr,10);
    if(left_limit+offset_x<right_limit) {
        setbkcolor(LIGHTMAGENTA);
        settextstyle(4,HORIZ_DIR,2);
        setcolor(WHITE);
        outtextxy(left_limit+offset_x,start_y+offset_y,nr);
        setbkcolor(DARKGRAY);
    }
}

void Window_Matrix_Cell_Sub() {
    int G_WINDOW_WIDTH=1600;
    int G_WINDOW_HEIGHT=900;
    int M_WINDOW_WIDTH=1150;
    int M_WINDOW_HEIGHT=900;

    closegraph();
    initwindow(G_WINDOW_WIDTH, G_WINDOW_HEIGHT, "BibMat", 150, 50);
    cleardevice();
    setfillstyle(SOLID_FILL,DARKGRAY);
    floodfill(1,1,WHITE);
    setbkcolor(DARKGRAY);

    char titlu_matrici[]="Introduceti dimensiunea matricei:";
    settextstyle(4,HORIZ_DIR,5);
    setcolor(WHITE);
    outtextxy(G_WINDOW_WIDTH/2-textwidth(titlu_matrici)/2,100,titlu_matrici);

    Matrix m;

    gwindow_read_int(m.n,2,1,6,0,G_WINDOW_WIDTH/2-50,G_WINDOW_HEIGHT/2);
    gwindow_read_int(m.m,2,1,6,0,G_WINDOW_WIDTH/2+50,G_WINDOW_HEIGHT/2);

    char text_confirma[]="Confirma";
    outtextxy((G_WINDOW_WIDTH-textwidth(text_confirma))/2-200,650,text_confirma);
    Button confirma;
    Button_Setup(confirma,(G_WINDOW_WIDTH-textwidth(text_confirma))/2-200,650,text_confirma);

    char text_anuleaza[]="Anuleaza";
    outtextxy((G_WINDOW_WIDTH-textwidth(text_anuleaza))/2+200,650,text_anuleaza);
    Button anuleaza;
    Button_Setup(anuleaza,(G_WINDOW_WIDTH-textwidth(text_anuleaza))/2+200,650,text_anuleaza);

    initMatrix(m);
    while(1) {
        if(ismouseclick(WM_LBUTTONDOWN)) {
            int mx=mousex();
            int my=mousey();
            if(isOnButton(anuleaza,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                gwindow_read_int(m.n,2,1,6,0,G_WINDOW_WIDTH/2-50,G_WINDOW_HEIGHT/2);
                gwindow_read_int(m.m,2,1,6,0,G_WINDOW_WIDTH/2+50,G_WINDOW_HEIGHT/2);
                delete m.mat;
                initMatrix(m);
            }
            if(isOnButton(confirma,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                draw_matrix_in_window(m,M_WINDOW_WIDTH-400,M_WINDOW_HEIGHT-200);
                Design_Matrix();
                int last_i=0, last_j=0,current_i=0,current_j=0;

                setcolor(WHITE);
                setbkcolor(BLACK);
                settextstyle(10,HORIZ_DIR,5);

                char text_run[]="RUN";
                outtextxy(1165,50,text_run);
                Button run;
                Button_Setup(run,1165,50,text_run);

                char text_code[]="CODE";
                outtextxy(1305,50,text_code);
                Button code;
                Button_Setup(code,1305,50,text_code);

                char text_back[]="BACK";
                outtextxy(1465,50,text_back);
                Button b_back;
                Button_Setup(b_back,1465,50,text_back);

                char text_cread[]="CONSOLE READ";
                outtextxy(1225,100,text_cread);
                Button cread;
                Button_Setup(cread,1225,100,text_cread);

                setbkcolor(DARKGRAY);

                bool code_toggle=false;
                bool has_ran=false;
                while(1) {
                    if(ismouseclick(WM_LBUTTONDOWN)) {
                        clearmouseclick(WM_LBUTTONDOWN);
                        int mx=mousex();
                        int my=mousey();
                        if(isInMatrix(m,mx,my)) {
                            gwindow_matrix_cell_read(m,last_i,last_j,current_i,current_j,mx,my);
                        }
                        else {
                            if(current_i && current_j) {
                                setcolor(WHITE);
                                rectangle(m.stanga+m.latura*(last_j-1),m.sus+m.latura*(last_i-1),m.stanga+m.latura*last_j,m.sus+m.latura*last_i);
                            }
                            current_i=current_j=0;
                        }
                        if(isOnButton(run,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            if(has_ran) {
                                setcolor(LIGHTGRAY);
                                rectangle(75,730,1150-75,880);
                                setfillstyle(SOLID_FILL,LIGHTMAGENTA);
                                floodfill(76,731,LIGHTGRAY);
                                draw_matrix_in_window(m,M_WINDOW_WIDTH-400,M_WINDOW_HEIGHT-200);
                                has_ran=false;
                            }
                            Animation_Matrix_Cell_Sub(m,has_ran);
                        }
                        if(isOnButton(b_back,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            return;
                        }
                        if(isOnButton(cread,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            for(int i=0;i<m.n;i++) {
                                for(int j=0;j<m.m;j++) {
                                    cin>>m.mat[i][j];
                                }
                            }
                            draw_matrix_in_window(m,M_WINDOW_WIDTH-400,M_WINDOW_HEIGHT-200);
                        }
                    }
                }
            }
            else {
                clearmouseclick(WM_LBUTTONDOWN);
            }
        }
    }
    //return;
}

///=====================================================
///        SUMA ELEM DIAGONALA PRINCIPALA MATRICE
///=====================================================
void Animation_Matrix_First_Diag_Sum(Matrix m, bool &has_ran) {
    has_ran=true;
    int current_i=0,current_j=0,last_i=0,last_j=0;
    int offset_x=0,offset_y=0;
    int left_limit=85,right_limit=865,start_y=735+textheight("0");
    long long sum=0;
    for(current_i=1;current_i<=m.n;current_i++) {
        current_j=current_i;
        int offset1=0;
        if(last_i && last_j) {
            Animation_Redraw_Cell(GREEN,last_i,last_j,m);
        }
        Animation_Redraw_Cell(RED,current_i,current_j,m);

        int text_x1=85;
        int text_y1=735;

        setfillstyle(SOLID_FILL,LIGHTMAGENTA);
        bar(text_x1,text_y1,text_x1+offset1,text_y1+textheight("0"));

        settextstyle(4,HORIZ_DIR,2);
        setbkcolor(LIGHTMAGENTA);
        char text1[]="Adunam elementul din celula de la linia ";
        char text2[2]="";
        itoa(current_i,text2,10);
        char text3[]=" si coloana ";
        char text4[2]="";
        itoa(current_j,text4,10);
        outtextxy(text_x1,text_y1,text1);
        offset1+=textwidth(text1);
        outtextxy(text_x1+offset1,text_y1,text2);
        offset1+=textwidth(text2);
        outtextxy(text_x1+offset1,text_y1,text3);
        offset1+=textwidth(text3);
        outtextxy(text_x1+offset1,text_y1,text4);
        offset1+=textwidth(text4);
        outtextxy(text_x1+offset1,text_y1,":");
        offset1=0;
        setbkcolor(DARKGRAY);

        char text_plus[]=" + ";
        char text_plus_left[]="+ ";
        char text_plus_right[]=" +";
        char text_egal[]=" = ";
        char text_egal_left[]="= ";
        char text_egal_right[]=" =";
        char text_number[11]="";
        itoa(m.mat[current_i-1][current_j-1],text_number,10);
        sum+=m.mat[current_i-1][current_j-1];
        setbkcolor(LIGHTMAGENTA);
        if(left_limit+offset_x+textwidth(text_number)<=right_limit) {
            outtextxy(left_limit+offset_x,start_y+offset_y,text_number);
            offset_x+=textwidth(text_number);
            if(left_limit+offset_x+textwidth(text_plus)<=right_limit) {
                if(current_i==m.n && current_j==m.m) {
                    outtextxy(left_limit+offset_x,start_y+offset_y,text_egal);
                    offset_x+=textwidth(text_egal);
                }
                else {
                    outtextxy(left_limit+offset_x,start_y+offset_y,text_plus);
                    offset_x+=textwidth(text_plus);
                }
            }
            else {
                if(current_i==m.n && current_j==m.m) {
                    offset_x=0;
                    offset_y+=textheight("0");
                    outtextxy(left_limit+offset_x,start_y+offset_y,text_egal_left);
                    offset_x+=textwidth(text_egal_left);
                }
                else {
                    offset_x=0;
                    offset_y+=textheight("0");
                    outtextxy(left_limit+offset_x,start_y+offset_y,text_plus_left);
                    offset_x+=textwidth(text_plus_left);
                }
            }
        }
        else {
            offset_x=0;
            offset_y+=textheight("0");
            outtextxy(left_limit+offset_x,start_y+offset_y,text_number);
            offset_x+=textwidth(text_number);
            if(current_i==m.n && current_j==m.m) {
                outtextxy(left_limit+offset_x,start_y+offset_y,text_egal);
                offset_x+=textwidth(text_egal);
            }
            else {
                outtextxy(left_limit+offset_x,start_y+offset_y,text_plus);
                offset_x+=textwidth(text_plus);
            }
        }
        setbkcolor(DARKGRAY);
        delay(1000);
        last_i=current_i;
        last_j=current_j;
    }
    Animation_Redraw_Cell(GREEN,last_i,last_j,m);
    char nr[12]="";
    itoa(sum,nr,10);
    if(left_limit+offset_x<right_limit) {
        setbkcolor(LIGHTMAGENTA);
        settextstyle(4,HORIZ_DIR,2);
        setcolor(WHITE);
        outtextxy(left_limit+offset_x,start_y+offset_y,nr);
        setbkcolor(DARKGRAY);
    }
}

void Window_Matrix_First_Diag_Sum() {
    int G_WINDOW_WIDTH=1600;
    int G_WINDOW_HEIGHT=900;
    int M_WINDOW_WIDTH=1150;
    int M_WINDOW_HEIGHT=900;

    closegraph();
    initwindow(G_WINDOW_WIDTH, G_WINDOW_HEIGHT, "BibMat", 150, 50);
    cleardevice();
    setfillstyle(SOLID_FILL,DARKGRAY);
    floodfill(1,1,WHITE);
    setbkcolor(DARKGRAY);

    char titlu_matrici[]="Introduceti dimensiunea matricei patratice:";
    settextstyle(4,HORIZ_DIR,5);
    setcolor(WHITE);
    outtextxy(G_WINDOW_WIDTH/2-textwidth(titlu_matrici)/2,100,titlu_matrici);

    Matrix m;

    gwindow_read_int(m.n,2,1,6,0,G_WINDOW_WIDTH/2-50,G_WINDOW_HEIGHT/2);
    m.m=m.n;
    char m_m_text[2]="";
    itoa(m.m,m_m_text,10);
    outtextxy(G_WINDOW_WIDTH/2-textwidth(m_m_text)/2+50,G_WINDOW_HEIGHT/2,m_m_text);

    char text_confirma[]="Confirma";
    outtextxy((G_WINDOW_WIDTH-textwidth(text_confirma))/2-200,650,text_confirma);
    Button confirma;
    Button_Setup(confirma,(G_WINDOW_WIDTH-textwidth(text_confirma))/2-200,650,text_confirma);

    char text_anuleaza[]="Anuleaza";
    outtextxy((G_WINDOW_WIDTH-textwidth(text_anuleaza))/2+200,650,text_anuleaza);
    Button anuleaza;
    Button_Setup(anuleaza,(G_WINDOW_WIDTH-textwidth(text_anuleaza))/2+200,650,text_anuleaza);

    initMatrix(m);
    while(1) {
        if(ismouseclick(WM_LBUTTONDOWN)) {
            int mx=mousex();
            int my=mousey();
            if(isOnButton(anuleaza,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                gwindow_read_int(m.n,2,1,6,0,G_WINDOW_WIDTH/2-50,G_WINDOW_HEIGHT/2);
                m.m=m.n;
                itoa(m.m,m_m_text,10);
                outtextxy(G_WINDOW_WIDTH/2-textwidth(m_m_text)/2+50,G_WINDOW_HEIGHT/2,m_m_text);
                delete m.mat;
                initMatrix(m);
            }
            if(isOnButton(confirma,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                draw_matrix_in_window(m,M_WINDOW_WIDTH-400,M_WINDOW_HEIGHT-200);
                Design_Matrix();
                int last_i=0, last_j=0,current_i=0,current_j=0;

                setcolor(WHITE);
                setbkcolor(BLACK);
                settextstyle(10,HORIZ_DIR,5);

                char text_run[]="RUN";
                outtextxy(1165,50,text_run);
                Button run;
                Button_Setup(run,1165,50,text_run);

                char text_code[]="CODE";
                outtextxy(1305,50,text_code);
                Button code;
                Button_Setup(code,1305,50,text_code);

                char text_back[]="BACK";
                outtextxy(1465,50,text_back);
                Button b_back;
                Button_Setup(b_back,1465,50,text_back);

                char text_cread[]="CONSOLE READ";
                outtextxy(1225,100,text_cread);
                Button cread;
                Button_Setup(cread,1225,100,text_cread);

                setbkcolor(DARKGRAY);

                bool code_toggle=false;
                bool has_ran=false;
                while(1) {
                    if(ismouseclick(WM_LBUTTONDOWN)) {
                        clearmouseclick(WM_LBUTTONDOWN);
                        int mx=mousex();
                        int my=mousey();
                        if(isInMatrix(m,mx,my)) {
                            gwindow_matrix_cell_read(m,last_i,last_j,current_i,current_j,mx,my);
                        }
                        else {
                            if(current_i && current_j) {
                                setcolor(WHITE);
                                rectangle(m.stanga+m.latura*(last_j-1),m.sus+m.latura*(last_i-1),m.stanga+m.latura*last_j,m.sus+m.latura*last_i);
                            }
                            current_i=current_j=0;
                        }
                        if(isOnButton(run,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            if(has_ran) {
                                setcolor(LIGHTGRAY);
                                rectangle(75,730,1150-75,880);
                                setfillstyle(SOLID_FILL,LIGHTMAGENTA);
                                floodfill(76,731,LIGHTGRAY);
                                draw_matrix_in_window(m,M_WINDOW_WIDTH-400,M_WINDOW_HEIGHT-200);
                                has_ran=false;
                            }
                            Animation_Matrix_First_Diag_Sum(m,has_ran);
                        }
                        if(isOnButton(b_back,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            return;
                        }
                        if(isOnButton(cread,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            for(int i=0;i<m.n;i++) {
                                for(int j=0;j<m.m;j++) {
                                    cin>>m.mat[i][j];
                                }
                            }
                            draw_matrix_in_window(m,M_WINDOW_WIDTH-400,M_WINDOW_HEIGHT-200);
                        }
                    }
                }
            }
            else {
                clearmouseclick(WM_LBUTTONDOWN);
            }
        }
    }
    //return;
}

///=====================================================
///        SUMA ELEM DIAGONALA SECUNDARA MATRICE
///=====================================================
void Animation_Matrix_Second_Diag_Sum(Matrix m, bool &has_ran) {
    has_ran=true;
    int current_i=0,current_j=0,last_i=0,last_j=0;
    int offset_x=0,offset_y=0;
    int left_limit=85,right_limit=865,start_y=735+textheight("0");
    long long sum=0;
    for(current_i=1;current_i<=m.n;current_i++) {
        current_j=m.m-current_i+1;
        int offset1=0;
        if(last_i && last_j) {
            Animation_Redraw_Cell(GREEN,last_i,last_j,m);
        }
        Animation_Redraw_Cell(RED,current_i,current_j,m);

        int text_x1=85;
        int text_y1=735;

        setfillstyle(SOLID_FILL,LIGHTMAGENTA);
        bar(text_x1,text_y1,text_x1+offset1,text_y1+textheight("0"));

        settextstyle(4,HORIZ_DIR,2);
        setbkcolor(LIGHTMAGENTA);
        char text1[]="Adunam elementul din celula de la linia ";
        char text2[2]="";
        itoa(current_i,text2,10);
        char text3[]=" si coloana ";
        char text4[2]="";
        itoa(current_j,text4,10);
        outtextxy(text_x1,text_y1,text1);
        offset1+=textwidth(text1);
        outtextxy(text_x1+offset1,text_y1,text2);
        offset1+=textwidth(text2);
        outtextxy(text_x1+offset1,text_y1,text3);
        offset1+=textwidth(text3);
        outtextxy(text_x1+offset1,text_y1,text4);
        offset1+=textwidth(text4);
        outtextxy(text_x1+offset1,text_y1,":");
        offset1=0;
        setbkcolor(DARKGRAY);

        char text_plus[]=" + ";
        char text_plus_left[]="+ ";
        char text_plus_right[]=" +";
        char text_egal[]=" = ";
        char text_egal_left[]="= ";
        char text_egal_right[]=" =";
        char text_number[11]="";
        itoa(m.mat[current_i-1][current_j-1],text_number,10);
        sum+=m.mat[current_i-1][current_j-1];
        setbkcolor(LIGHTMAGENTA);
        if(left_limit+offset_x+textwidth(text_number)<=right_limit) {
            outtextxy(left_limit+offset_x,start_y+offset_y,text_number);
            offset_x+=textwidth(text_number);
            if(left_limit+offset_x+textwidth(text_plus)<=right_limit) {
                if(current_i==m.n) {
                    outtextxy(left_limit+offset_x,start_y+offset_y,text_egal);
                    offset_x+=textwidth(text_egal);
                }
                else {
                    outtextxy(left_limit+offset_x,start_y+offset_y,text_plus);
                    offset_x+=textwidth(text_plus);
                }
            }
            else {
                if(current_i==m.n) {
                    offset_x=0;
                    offset_y+=textheight("0");
                    outtextxy(left_limit+offset_x,start_y+offset_y,text_egal_left);
                    offset_x+=textwidth(text_egal_left);
                }
                else {
                    offset_x=0;
                    offset_y+=textheight("0");
                    outtextxy(left_limit+offset_x,start_y+offset_y,text_plus_left);
                    offset_x+=textwidth(text_plus_left);
                }
            }
        }
        else {
            offset_x=0;
            offset_y+=textheight("0");
            outtextxy(left_limit+offset_x,start_y+offset_y,text_number);
            offset_x+=textwidth(text_number);
            if(current_i==m.n) {
                outtextxy(left_limit+offset_x,start_y+offset_y,text_egal);
                offset_x+=textwidth(text_egal);
            }
            else {
                outtextxy(left_limit+offset_x,start_y+offset_y,text_plus);
                offset_x+=textwidth(text_plus);
            }
        }
        setbkcolor(DARKGRAY);
        delay(1000);
        last_i=current_i;
        last_j=current_j;
    }
    Animation_Redraw_Cell(GREEN,last_i,last_j,m);
    char nr[12]="";
    itoa(sum,nr,10);
    if(left_limit+offset_x<right_limit) {
        setbkcolor(LIGHTMAGENTA);
        settextstyle(4,HORIZ_DIR,2);
        setcolor(WHITE);
        outtextxy(left_limit+offset_x,start_y+offset_y,nr);
        setbkcolor(DARKGRAY);
    }
}

void Window_Matrix_Second_Diag_Sum() {
    int G_WINDOW_WIDTH=1600;
    int G_WINDOW_HEIGHT=900;
    int M_WINDOW_WIDTH=1150;
    int M_WINDOW_HEIGHT=900;

    closegraph();
    initwindow(G_WINDOW_WIDTH, G_WINDOW_HEIGHT, "BibMat", 150, 50);
    cleardevice();
    setfillstyle(SOLID_FILL,DARKGRAY);
    floodfill(1,1,WHITE);
    setbkcolor(DARKGRAY);

    char titlu_matrici[]="Introduceti dimensiunea matricei patratice:";
    settextstyle(4,HORIZ_DIR,5);
    setcolor(WHITE);
    outtextxy(G_WINDOW_WIDTH/2-textwidth(titlu_matrici)/2,100,titlu_matrici);

    Matrix m;

    gwindow_read_int(m.n,2,1,6,0,G_WINDOW_WIDTH/2-50,G_WINDOW_HEIGHT/2);
    m.m=m.n;
    char m_m_text[2]="";
    itoa(m.m,m_m_text,10);
    outtextxy(G_WINDOW_WIDTH/2-textwidth(m_m_text)/2+50,G_WINDOW_HEIGHT/2,m_m_text);

    char text_confirma[]="Confirma";
    outtextxy((G_WINDOW_WIDTH-textwidth(text_confirma))/2-200,650,text_confirma);
    Button confirma;
    Button_Setup(confirma,(G_WINDOW_WIDTH-textwidth(text_confirma))/2-200,650,text_confirma);

    char text_anuleaza[]="Anuleaza";
    outtextxy((G_WINDOW_WIDTH-textwidth(text_anuleaza))/2+200,650,text_anuleaza);
    Button anuleaza;
    Button_Setup(anuleaza,(G_WINDOW_WIDTH-textwidth(text_anuleaza))/2+200,650,text_anuleaza);

    initMatrix(m);
    while(1) {
        if(ismouseclick(WM_LBUTTONDOWN)) {
            int mx=mousex();
            int my=mousey();
            if(isOnButton(anuleaza,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                gwindow_read_int(m.n,2,1,6,0,G_WINDOW_WIDTH/2-50,G_WINDOW_HEIGHT/2);
                m.m=m.n;
                itoa(m.m,m_m_text,10);
                outtextxy(G_WINDOW_WIDTH/2-textwidth(m_m_text)/2+50,G_WINDOW_HEIGHT/2,m_m_text);
                delete m.mat;
                initMatrix(m);
            }
            if(isOnButton(confirma,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                draw_matrix_in_window(m,M_WINDOW_WIDTH-400,M_WINDOW_HEIGHT-200);
                Design_Matrix();
                int last_i=0, last_j=0,current_i=0,current_j=0;

                setcolor(WHITE);
                setbkcolor(BLACK);
                settextstyle(10,HORIZ_DIR,5);

                char text_run[]="RUN";
                outtextxy(1165,50,text_run);
                Button run;
                Button_Setup(run,1165,50,text_run);

                char text_code[]="CODE";
                outtextxy(1305,50,text_code);
                Button code;
                Button_Setup(code,1305,50,text_code);

                char text_back[]="BACK";
                outtextxy(1465,50,text_back);
                Button b_back;
                Button_Setup(b_back,1465,50,text_back);

                char text_cread[]="CONSOLE READ";
                outtextxy(1225,100,text_cread);
                Button cread;
                Button_Setup(cread,1225,100,text_cread);

                setbkcolor(DARKGRAY);

                bool code_toggle=false;
                bool has_ran=false;
                while(1) {
                    if(ismouseclick(WM_LBUTTONDOWN)) {
                        clearmouseclick(WM_LBUTTONDOWN);
                        int mx=mousex();
                        int my=mousey();
                        if(isInMatrix(m,mx,my)) {
                            gwindow_matrix_cell_read(m,last_i,last_j,current_i,current_j,mx,my);
                        }
                        else {
                            if(current_i && current_j) {
                                setcolor(WHITE);
                                rectangle(m.stanga+m.latura*(last_j-1),m.sus+m.latura*(last_i-1),m.stanga+m.latura*last_j,m.sus+m.latura*last_i);
                            }
                            current_i=current_j=0;
                        }
                        if(isOnButton(run,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            if(has_ran) {
                                setcolor(LIGHTGRAY);
                                rectangle(75,730,1150-75,880);
                                setfillstyle(SOLID_FILL,LIGHTMAGENTA);
                                floodfill(76,731,LIGHTGRAY);
                                draw_matrix_in_window(m,M_WINDOW_WIDTH-400,M_WINDOW_HEIGHT-200);
                                has_ran=false;
                            }
                            Animation_Matrix_Second_Diag_Sum(m,has_ran);
                        }
                        if(isOnButton(b_back,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            return;
                        }
                        if(isOnButton(cread,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            for(int i=0;i<m.n;i++) {
                                for(int j=0;j<m.m;j++) {
                                    cin>>m.mat[i][j];
                                }
                            }
                            draw_matrix_in_window(m,M_WINDOW_WIDTH-400,M_WINDOW_HEIGHT-200);
                        }
                    }
                }
            }
            else {
                clearmouseclick(WM_LBUTTONDOWN);
            }
        }
    }
    //return;
}


///========================================================
///       SUMA ELEM SUB DIAGONALA PRINCIPALA MATRICE
///========================================================
void Animation_Matrix_Under_First_Diag_Sum(Matrix m, bool &has_ran) {
    has_ran=true;
    int current_i=0,current_j=0,last_i=0,last_j=0;
    int offset_x=0,offset_y=0;
    int left_limit=85,right_limit=865,start_y=735+textheight("0");
    long long sum=0;

    for(int i=1;i<=m.n;i++) {
        Animation_Redraw_Cell(LIGHTRED,i,i,m);
    }

    for(current_i=1;current_i<=m.n;current_i++) {
        int offset1=0;
        for(current_j=1;current_j<current_i;current_j++) {
            if(last_i && last_j) {
                Animation_Redraw_Cell(GREEN,last_i,last_j,m);
            }
            Animation_Redraw_Cell(RED,current_i,current_j,m);

            int text_x1=85;
            int text_y1=735;

            setfillstyle(SOLID_FILL,LIGHTMAGENTA);
            bar(text_x1,text_y1,text_x1+offset1,text_y1+textheight("0"));

            settextstyle(4,HORIZ_DIR,2);
            setbkcolor(LIGHTMAGENTA);
            char text1[]="Adunam elementul din celula de la linia ";
            char text2[2]="";
            itoa(current_i,text2,10);
            char text3[]=" si coloana ";
            char text4[2]="";
            itoa(current_j,text4,10);
            outtextxy(text_x1,text_y1,text1);
            offset1+=textwidth(text1);
            outtextxy(text_x1+offset1,text_y1,text2);
            offset1+=textwidth(text2);
            outtextxy(text_x1+offset1,text_y1,text3);
            offset1+=textwidth(text3);
            outtextxy(text_x1+offset1,text_y1,text4);
            offset1+=textwidth(text4);
            outtextxy(text_x1+offset1,text_y1,":");
            offset1=0;
            setbkcolor(DARKGRAY);

            char text_plus[]=" + ";
            char text_plus_left[]="+ ";
            char text_plus_right[]=" +";
            char text_egal[]=" = ";
            char text_egal_left[]="= ";
            char text_egal_right[]=" =";
            char text_number[11]="";
            itoa(m.mat[current_i-1][current_j-1],text_number,10);
            sum+=m.mat[current_i-1][current_j-1];
            setbkcolor(LIGHTMAGENTA);
            if(left_limit+offset_x+textwidth(text_number)<=right_limit) {
                outtextxy(left_limit+offset_x,start_y+offset_y,text_number);
                offset_x+=textwidth(text_number);
                if(left_limit+offset_x+textwidth(text_plus)<=right_limit) {
                    if(current_i==m.n && current_j==m.m-1) {
                        outtextxy(left_limit+offset_x,start_y+offset_y,text_egal);
                        offset_x+=textwidth(text_egal);
                    }
                    else {
                        outtextxy(left_limit+offset_x,start_y+offset_y,text_plus);
                        offset_x+=textwidth(text_plus);
                    }
                }
                else {
                    if(current_i==m.n && current_j==m.m-1) {
                        offset_x=0;
                        offset_y+=textheight("0");
                        outtextxy(left_limit+offset_x,start_y+offset_y,text_egal_left);
                        offset_x+=textwidth(text_egal_left);
                    }
                    else {
                        offset_x=0;
                        offset_y+=textheight("0");
                        outtextxy(left_limit+offset_x,start_y+offset_y,text_plus_left);
                        offset_x+=textwidth(text_plus_left);
                    }
                }
            }
            else {
                offset_x=0;
                offset_y+=textheight("0");
                outtextxy(left_limit+offset_x,start_y+offset_y,text_number);
                offset_x+=textwidth(text_number);
                if(current_i==m.n && current_j==m.m-1) {
                    outtextxy(left_limit+offset_x,start_y+offset_y,text_egal);
                    offset_x+=textwidth(text_egal);
                }
                else {
                    outtextxy(left_limit+offset_x,start_y+offset_y,text_plus);
                    offset_x+=textwidth(text_plus);
                }
            }
            setbkcolor(DARKGRAY);
            delay(1000);
            last_i=current_i;
            last_j=current_j;
        }
    }
    Animation_Redraw_Cell(GREEN,last_i,last_j,m);
    char nr[12]="";
    itoa(sum,nr,10);
    if(left_limit+offset_x<right_limit) {
        setbkcolor(LIGHTMAGENTA);
        settextstyle(4,HORIZ_DIR,2);
        setcolor(WHITE);
        outtextxy(left_limit+offset_x,start_y+offset_y,nr);
        setbkcolor(DARKGRAY);
    }
}

void Window_Matrix_Under_First_Diag_Sum() {
    int G_WINDOW_WIDTH=1600;
    int G_WINDOW_HEIGHT=900;
    int M_WINDOW_WIDTH=1150;
    int M_WINDOW_HEIGHT=900;

    closegraph();
    initwindow(G_WINDOW_WIDTH, G_WINDOW_HEIGHT, "BibMat", 150, 50);
    cleardevice();
    setfillstyle(SOLID_FILL,DARKGRAY);
    floodfill(1,1,WHITE);
    setbkcolor(DARKGRAY);

    char titlu_matrici[]="Introduceti dimensiunea matricei patratice:";
    settextstyle(4,HORIZ_DIR,5);
    setcolor(WHITE);
    outtextxy(G_WINDOW_WIDTH/2-textwidth(titlu_matrici)/2,100,titlu_matrici);

    Matrix m;

    gwindow_read_int(m.n,2,1,6,0,G_WINDOW_WIDTH/2-50,G_WINDOW_HEIGHT/2);
    m.m=m.n;
    char m_m_text[2]="";
    itoa(m.m,m_m_text,10);
    outtextxy(G_WINDOW_WIDTH/2-textwidth(m_m_text)/2+50,G_WINDOW_HEIGHT/2,m_m_text);

    char text_confirma[]="Confirma";
    outtextxy((G_WINDOW_WIDTH-textwidth(text_confirma))/2-200,650,text_confirma);
    Button confirma;
    Button_Setup(confirma,(G_WINDOW_WIDTH-textwidth(text_confirma))/2-200,650,text_confirma);

    char text_anuleaza[]="Anuleaza";
    outtextxy((G_WINDOW_WIDTH-textwidth(text_anuleaza))/2+200,650,text_anuleaza);
    Button anuleaza;
    Button_Setup(anuleaza,(G_WINDOW_WIDTH-textwidth(text_anuleaza))/2+200,650,text_anuleaza);

    initMatrix(m);
    while(1) {
        if(ismouseclick(WM_LBUTTONDOWN)) {
            int mx=mousex();
            int my=mousey();
            if(isOnButton(anuleaza,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                gwindow_read_int(m.n,2,1,6,0,G_WINDOW_WIDTH/2-50,G_WINDOW_HEIGHT/2);
                m.m=m.n;
                itoa(m.m,m_m_text,10);
                outtextxy(G_WINDOW_WIDTH/2-textwidth(m_m_text)/2+50,G_WINDOW_HEIGHT/2,m_m_text);
                delete m.mat;
                initMatrix(m);
            }
            if(isOnButton(confirma,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                draw_matrix_in_window(m,M_WINDOW_WIDTH-400,M_WINDOW_HEIGHT-200);
                Design_Matrix();
                int last_i=0, last_j=0,current_i=0,current_j=0;

                setcolor(WHITE);
                setbkcolor(BLACK);
                settextstyle(10,HORIZ_DIR,5);

                char text_run[]="RUN";
                outtextxy(1165,50,text_run);
                Button run;
                Button_Setup(run,1165,50,text_run);

                char text_code[]="CODE";
                outtextxy(1305,50,text_code);
                Button code;
                Button_Setup(code,1305,50,text_code);

                char text_back[]="BACK";
                outtextxy(1465,50,text_back);
                Button b_back;
                Button_Setup(b_back,1465,50,text_back);

                char text_cread[]="CONSOLE READ";
                outtextxy(1225,100,text_cread);
                Button cread;
                Button_Setup(cread,1225,100,text_cread);

                setbkcolor(DARKGRAY);

                bool code_toggle=false;
                bool has_ran=false;
                while(1) {
                    if(ismouseclick(WM_LBUTTONDOWN)) {
                        clearmouseclick(WM_LBUTTONDOWN);
                        int mx=mousex();
                        int my=mousey();
                        if(isInMatrix(m,mx,my)) {
                            gwindow_matrix_cell_read(m,last_i,last_j,current_i,current_j,mx,my);
                        }
                        else {
                            if(current_i && current_j) {
                                setcolor(WHITE);
                                rectangle(m.stanga+m.latura*(last_j-1),m.sus+m.latura*(last_i-1),m.stanga+m.latura*last_j,m.sus+m.latura*last_i);
                            }
                            current_i=current_j=0;
                        }
                        if(isOnButton(run,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            if(has_ran) {
                                setcolor(LIGHTGRAY);
                                rectangle(75,730,1150-75,880);
                                setfillstyle(SOLID_FILL,LIGHTMAGENTA);
                                floodfill(76,731,LIGHTGRAY);
                                draw_matrix_in_window(m,M_WINDOW_WIDTH-400,M_WINDOW_HEIGHT-200);
                                has_ran=false;
                            }
                            Animation_Matrix_Under_First_Diag_Sum(m,has_ran);
                        }
                        if(isOnButton(b_back,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            return;
                        }
                        if(isOnButton(cread,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            for(int i=0;i<m.n;i++) {
                                for(int j=0;j<m.m;j++) {
                                    cin>>m.mat[i][j];
                                }
                            }
                            draw_matrix_in_window(m,M_WINDOW_WIDTH-400,M_WINDOW_HEIGHT-200);
                        }
                    }
                }
            }
            else {
                clearmouseclick(WM_LBUTTONDOWN);
            }
        }
    }
    //return;
}

///========================================================
///       SUMA ELEM SUB DIAGONALA SECUNDARA MATRICE
///========================================================
void Animation_Matrix_Under_Second_Diag_Sum(Matrix m, bool &has_ran) {
    has_ran=true;
    int current_i=0,current_j=0,last_i=0,last_j=0;
    int offset_x=0,offset_y=0;
    int left_limit=85,right_limit=865,start_y=735+textheight("0");
    long long sum=0;

    for(int i=1;i<=m.n;i++) {
        Animation_Redraw_Cell(LIGHTRED,i,m.n-i+1,m);
    }

    for(current_i=1;current_i<=m.n;current_i++) {
        int offset1=0;
        for(current_j=m.m;current_j>=1;current_j--) {
            if(current_i+current_j==m.n+1) {
                break;
            }
            if(last_i && last_j) {
                Animation_Redraw_Cell(GREEN,last_i,last_j,m);
            }
            Animation_Redraw_Cell(RED,current_i,current_j,m);

            int text_x1=85;
            int text_y1=735;

            setfillstyle(SOLID_FILL,LIGHTMAGENTA);
            bar(text_x1,text_y1,text_x1+offset1,text_y1+textheight("0"));

            settextstyle(4,HORIZ_DIR,2);
            setbkcolor(LIGHTMAGENTA);
            char text1[]="Adunam elementul din celula de la linia ";
            char text2[2]="";
            itoa(current_i,text2,10);
            char text3[]=" si coloana ";
            char text4[2]="";
            itoa(current_j,text4,10);
            outtextxy(text_x1,text_y1,text1);
            offset1+=textwidth(text1);
            outtextxy(text_x1+offset1,text_y1,text2);
            offset1+=textwidth(text2);
            outtextxy(text_x1+offset1,text_y1,text3);
            offset1+=textwidth(text3);
            outtextxy(text_x1+offset1,text_y1,text4);
            offset1+=textwidth(text4);
            outtextxy(text_x1+offset1,text_y1,":");
            offset1=0;
            setbkcolor(DARKGRAY);

            char text_plus[]=" + ";
            char text_plus_left[]="+ ";
            char text_plus_right[]=" +";
            char text_egal[]=" = ";
            char text_egal_left[]="= ";
            char text_egal_right[]=" =";
            char text_number[11]="";
            itoa(m.mat[current_i-1][current_j-1],text_number,10);
            sum+=m.mat[current_i-1][current_j-1];
            setbkcolor(LIGHTMAGENTA);
            if(left_limit+offset_x+textwidth(text_number)<=right_limit) {
                outtextxy(left_limit+offset_x,start_y+offset_y,text_number);
                offset_x+=textwidth(text_number);
                if(left_limit+offset_x+textwidth(text_plus)<=right_limit) {
                    if(current_i==m.n && current_j==2) {
                        outtextxy(left_limit+offset_x,start_y+offset_y,text_egal);
                        offset_x+=textwidth(text_egal);
                    }
                    else {
                        outtextxy(left_limit+offset_x,start_y+offset_y,text_plus);
                        offset_x+=textwidth(text_plus);
                    }
                }
                else {
                    if(current_i==m.n && current_j==2) {
                        offset_x=0;
                        offset_y+=textheight("0");
                        outtextxy(left_limit+offset_x,start_y+offset_y,text_egal_left);
                        offset_x+=textwidth(text_egal_left);
                    }
                    else {
                        offset_x=0;
                        offset_y+=textheight("0");
                        outtextxy(left_limit+offset_x,start_y+offset_y,text_plus_left);
                        offset_x+=textwidth(text_plus_left);
                    }
                }
            }
            else {
                offset_x=0;
                offset_y+=textheight("0");
                outtextxy(left_limit+offset_x,start_y+offset_y,text_number);
                offset_x+=textwidth(text_number);
                if(current_i==m.n && current_j==2) {
                    outtextxy(left_limit+offset_x,start_y+offset_y,text_egal);
                    offset_x+=textwidth(text_egal);
                }
                else {
                    outtextxy(left_limit+offset_x,start_y+offset_y,text_plus);
                    offset_x+=textwidth(text_plus);
                }
            }
            setbkcolor(DARKGRAY);
            delay(1000);
            last_i=current_i;
            last_j=current_j;
        }
    }
    Animation_Redraw_Cell(GREEN,last_i,last_j,m);
    char nr[12]="";
    itoa(sum,nr,10);
    if(left_limit+offset_x<right_limit) {
        setbkcolor(LIGHTMAGENTA);
        settextstyle(4,HORIZ_DIR,2);
        setcolor(WHITE);
        outtextxy(left_limit+offset_x,start_y+offset_y,nr);
        setbkcolor(DARKGRAY);
    }
}

void Window_Matrix_Under_Second_Diag_Sum() {
    int G_WINDOW_WIDTH=1600;
    int G_WINDOW_HEIGHT=900;
    int M_WINDOW_WIDTH=1150;
    int M_WINDOW_HEIGHT=900;

    closegraph();
    initwindow(G_WINDOW_WIDTH, G_WINDOW_HEIGHT, "BibMat", 150, 50);
    cleardevice();
    setfillstyle(SOLID_FILL,DARKGRAY);
    floodfill(1,1,WHITE);
    setbkcolor(DARKGRAY);

    char titlu_matrici[]="Introduceti dimensiunea matricei patratice:";
    settextstyle(4,HORIZ_DIR,5);
    setcolor(WHITE);
    outtextxy(G_WINDOW_WIDTH/2-textwidth(titlu_matrici)/2,100,titlu_matrici);

    Matrix m;

    gwindow_read_int(m.n,2,1,6,0,G_WINDOW_WIDTH/2-50,G_WINDOW_HEIGHT/2);
    m.m=m.n;
    char m_m_text[2]="";
    itoa(m.m,m_m_text,10);
    outtextxy(G_WINDOW_WIDTH/2-textwidth(m_m_text)/2+50,G_WINDOW_HEIGHT/2,m_m_text);

    char text_confirma[]="Confirma";
    outtextxy((G_WINDOW_WIDTH-textwidth(text_confirma))/2-200,650,text_confirma);
    Button confirma;
    Button_Setup(confirma,(G_WINDOW_WIDTH-textwidth(text_confirma))/2-200,650,text_confirma);

    char text_anuleaza[]="Anuleaza";
    outtextxy((G_WINDOW_WIDTH-textwidth(text_anuleaza))/2+200,650,text_anuleaza);
    Button anuleaza;
    Button_Setup(anuleaza,(G_WINDOW_WIDTH-textwidth(text_anuleaza))/2+200,650,text_anuleaza);

    initMatrix(m);
    while(1) {
        if(ismouseclick(WM_LBUTTONDOWN)) {
            int mx=mousex();
            int my=mousey();
            if(isOnButton(anuleaza,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                gwindow_read_int(m.n,2,1,6,0,G_WINDOW_WIDTH/2-50,G_WINDOW_HEIGHT/2);
                m.m=m.n;
                itoa(m.m,m_m_text,10);
                outtextxy(G_WINDOW_WIDTH/2-textwidth(m_m_text)/2+50,G_WINDOW_HEIGHT/2,m_m_text);
                delete m.mat;
                initMatrix(m);
            }
            if(isOnButton(confirma,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                draw_matrix_in_window(m,M_WINDOW_WIDTH-400,M_WINDOW_HEIGHT-200);
                Design_Matrix();
                int last_i=0, last_j=0,current_i=0,current_j=0;

                setcolor(WHITE);
                setbkcolor(BLACK);
                settextstyle(10,HORIZ_DIR,5);

                char text_run[]="RUN";
                outtextxy(1165,50,text_run);
                Button run;
                Button_Setup(run,1165,50,text_run);

                char text_code[]="CODE";
                outtextxy(1305,50,text_code);
                Button code;
                Button_Setup(code,1305,50,text_code);

                char text_back[]="BACK";
                outtextxy(1465,50,text_back);
                Button b_back;
                Button_Setup(b_back,1465,50,text_back);

                char text_cread[]="CONSOLE READ";
                outtextxy(1225,100,text_cread);
                Button cread;
                Button_Setup(cread,1225,100,text_cread);

                setbkcolor(DARKGRAY);

                bool code_toggle=false;
                bool has_ran=false;
                while(1) {
                    if(ismouseclick(WM_LBUTTONDOWN)) {
                        clearmouseclick(WM_LBUTTONDOWN);
                        int mx=mousex();
                        int my=mousey();
                        if(isInMatrix(m,mx,my)) {
                            gwindow_matrix_cell_read(m,last_i,last_j,current_i,current_j,mx,my);
                        }
                        else {
                            if(current_i && current_j) {
                                setcolor(WHITE);
                                rectangle(m.stanga+m.latura*(last_j-1),m.sus+m.latura*(last_i-1),m.stanga+m.latura*last_j,m.sus+m.latura*last_i);
                            }
                            current_i=current_j=0;
                        }
                        if(isOnButton(run,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            if(has_ran) {
                                setcolor(LIGHTGRAY);
                                rectangle(75,730,1150-75,880);
                                setfillstyle(SOLID_FILL,LIGHTMAGENTA);
                                floodfill(76,731,LIGHTGRAY);
                                draw_matrix_in_window(m,M_WINDOW_WIDTH-400,M_WINDOW_HEIGHT-200);
                                has_ran=false;
                            }
                            Animation_Matrix_Under_Second_Diag_Sum(m,has_ran);
                        }
                        if(isOnButton(b_back,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            return;
                        }
                        if(isOnButton(cread,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            for(int i=0;i<m.n;i++) {
                                for(int j=0;j<m.m;j++) {
                                    cin>>m.mat[i][j];
                                }
                            }
                            draw_matrix_in_window(m,M_WINDOW_WIDTH-400,M_WINDOW_HEIGHT-200);
                        }
                    }
                }
            }
            else {
                clearmouseclick(WM_LBUTTONDOWN);
            }
        }
    }
    //return;
}

///========================================================
///                   INMULTIRE MATRICE
///========================================================
void Animation_Matrix_Cell_Mul(Matrix m1, Matrix m2, Matrix &m3, bool &has_ran, int window1, int &window2) {
    has_ran=true;

    m3.n=m1.n;
    m3.m=m2.m;
    initMatrix(m3);

    setcolor(LIGHTGRAY);
    rectangle(30,730,1150-40,880);
    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    floodfill(31,731,LIGHTGRAY);

    window2=initwindow(600,600,"Matrice Rezultat",1920-600,250);
    int offset1=0;
    int current_i1=0,current_j1=0,last_i1=0,last_j1=0;
    int current_i2=0,current_j2=0,last_i2=0,last_j2=0;
    int current_i3=0,current_j3=0,last_i3=0,last_j3=0;
    int offset_x=0,offset_y=0;
    int left_limit=45,right_limit=1090,start_y=740+textheight("0");
    int sum=0;

    setcurrentwindow(window2);
    setbkcolor(DARKGRAY);
    setfillstyle(SOLID_FILL,DARKGRAY);
    floodfill(1,1,WHITE);
    draw_matrix_in_window(m3,600,600);

    for(current_i1=1;current_i1<=m1.n;current_i1++) {
        setcurrentwindow(window1);
        draw_matrix_in_window(m2,1700,700);
        offset_x=0;
        offset_y=0;
        for(current_j2=1;current_j2<=m2.m;current_j2++) {
            setcolor(LIGHTGRAY);
            rectangle(30,730,1150-40,880);
            setfillstyle(SOLID_FILL,LIGHTMAGENTA);
            floodfill(31,731,LIGHTGRAY);
            offset_x=0;
            offset_y=0;
            for(current_i2=1;current_i2<=m2.n;current_i2++) {
                setcurrentwindow(window2);
                Animation_Redraw_Cell(RED,current_i1,current_j2,m3);

                setcurrentwindow(window1);
                Animation_Redraw_Cell(RED,current_i1,current_i2,m1);
                Animation_Redraw_Cell(RED,current_i2,current_j2,m2);

                int text_x1=45;
                int text_y1=735;

                setfillstyle(SOLID_FILL,LIGHTMAGENTA);
                bar(text_x1,text_y1,text_x1+offset1,text_y1+textheight("0"));

                settextstyle(4,HORIZ_DIR,2);
                setbkcolor(LIGHTMAGENTA);
                char text1[]="Inmultim elementul [";
                char text2[2]="";
                itoa(current_i1,text2,10);
                char text3[]="] [";
                char text4[2]="";
                itoa(current_i2,text4,10);
                char text5[]="] din M1, cu elementul [";
                char text6[2]="";
                itoa(current_i2,text6,10);
                char text7[2]="";
                itoa(current_j2,text7,10);

                outtextxy(text_x1,text_y1,text1);
                offset1+=textwidth(text1);
                outtextxy(text_x1+offset1,text_y1,text2);
                offset1+=textwidth(text2);
                outtextxy(text_x1+offset1,text_y1,text3);
                offset1+=textwidth(text3);
                outtextxy(text_x1+offset1,text_y1,text4);
                offset1+=textwidth(text4);
                outtextxy(text_x1+offset1,text_y1,text5);
                offset1+=textwidth(text5);
                outtextxy(text_x1+offset1,text_y1,text6);
                offset1+=textwidth(text6);
                outtextxy(text_x1+offset1,text_y1,text3);
                offset1+=textwidth(text3);
                outtextxy(text_x1+offset1,text_y1,text7);
                offset1+=textwidth(text7);
                outtextxy(text_x1+offset1,text_y1,"] din M2:");
                offset1=0;
                setbkcolor(DARKGRAY);

                char text_plus[]=" + ";
                char text_plus_left[]="+ ";
                char text_plus_right[]=" +";
                char text_mul[]=" × ";
                char text_egal[]=" = ";
                char text_egal_left[]="= ";
                char text_egal_right[]=" =";
                char text_number1[11]="";
                char text_number2[11]="";
                itoa(m1.mat[current_i1-1][current_i2-1],text_number1,10);
                itoa(m2.mat[current_i2-1][current_j2-1],text_number2,10);
                char text_number[25]="";
                memset(text_number,'\0',25);
                strcat(text_number,text_number1);
                strcat(text_number,text_mul);
                strcat(text_number,text_number2);

                sum+=m1.mat[current_i1-1][current_i2-1]*m2.mat[current_i2-1][current_j2-1];
                setbkcolor(LIGHTMAGENTA);
                if(left_limit+offset_x+textwidth(text_number)<=right_limit) {
                    outtextxy(left_limit+offset_x,start_y+offset_y,text_number);
                    offset_x+=textwidth(text_number);
                    if(left_limit+offset_x+textwidth(text_plus)<=right_limit) {
                        if(current_i2==m1.m) {
                            outtextxy(left_limit+offset_x,start_y+offset_y,text_egal);
                            offset_x+=textwidth(text_egal);
                            char nr[12]="";
                            itoa(sum,nr,10);
                            if(left_limit+offset_x+textwidth(nr)<=right_limit) {
                                setbkcolor(LIGHTMAGENTA);
                                settextstyle(4,HORIZ_DIR,2);
                                setcolor(WHITE);
                                outtextxy(left_limit+offset_x,start_y+offset_y,nr);
                                setbkcolor(DARKGRAY);
                            }
                            m3.mat[current_i1-1][current_j2-1]=sum;
                            setcurrentwindow(window2);
                            Animation_Redraw_Cell(RED,current_i1,current_j2,m3);
                            setcurrentwindow(window1);
                            sum=0;
                        }
                        else {
                            outtextxy(left_limit+offset_x,start_y+offset_y,text_plus);
                            offset_x+=textwidth(text_plus);
                        }
                    }
                    else {
                        if(current_i2==m1.m) {
                            offset_x=0;
                            offset_y+=textheight("0");
                            outtextxy(left_limit+offset_x,start_y+offset_y,text_egal_left);
                            offset_x+=textwidth(text_egal_left);
                            char nr[12]="";
                            itoa(sum,nr,10);
                            if(left_limit+offset_x+textwidth(nr)<=right_limit) {
                                setbkcolor(LIGHTMAGENTA);
                                settextstyle(4,HORIZ_DIR,2);
                                setcolor(WHITE);
                                outtextxy(left_limit+offset_x,start_y+offset_y,nr);
                                setbkcolor(DARKGRAY);
                            }
                            m3.mat[current_i1-1][current_j2-1]=sum;
                            setcurrentwindow(window2);
                            Animation_Redraw_Cell(RED,current_i1,current_j2,m3);
                            setcurrentwindow(window1);
                            sum=0;
                        }
                        else {
                            offset_x=0;
                            offset_y+=textheight("0");
                            outtextxy(left_limit+offset_x,start_y+offset_y,text_plus_left);
                            offset_x+=textwidth(text_plus_left);
                        }
                    }
                }
                else {
                    offset_x=0;
                    offset_y+=textheight("0");
                    outtextxy(left_limit+offset_x,start_y+offset_y,text_number);
                    offset_x+=textwidth(text_number);
                    if(current_i2==m1.m) {
                        outtextxy(left_limit+offset_x,start_y+offset_y,text_egal);
                        offset_x+=textwidth(text_egal);
                        char nr[12]="";
                        itoa(sum,nr,10);
                        if(left_limit+offset_x+textwidth(nr)<=right_limit) {
                            setbkcolor(LIGHTMAGENTA);
                            settextstyle(4,HORIZ_DIR,2);
                            setcolor(WHITE);
                            outtextxy(left_limit+offset_x,start_y+offset_y,nr);
                            setbkcolor(DARKGRAY);
                        }
                        m3.mat[current_i1-1][current_j2-1]=sum;
                        setcurrentwindow(window2);
                        Animation_Redraw_Cell(RED,current_i1,current_j2,m3);
                        setcurrentwindow(window1);
                        sum=0;
                    }
                    else {
                        outtextxy(left_limit+offset_x,start_y+offset_y,text_plus);
                        offset_x+=textwidth(text_plus);
                    }
                }
                setbkcolor(DARKGRAY);

                delay(1500);
                setcurrentwindow(window2);
                Animation_Redraw_Cell(GREEN,current_i1,current_j2,m3);
                setcurrentwindow(window1);
                Animation_Redraw_Cell(GREEN,current_i1,current_i2,m1);
                Animation_Redraw_Cell(GREEN,current_i2,current_j2,m2);
            }
            //delay(250);
        }
    }
}

void Window_Matrix_Mul() {
    int G_WINDOW_WIDTH=1600;
    int G_WINDOW_HEIGHT=900;
    int M_WINDOW_WIDTH=1150;
    int M_WINDOW_HEIGHT=900;

    closegraph();
    int window1=initwindow(G_WINDOW_WIDTH, G_WINDOW_HEIGHT, "BibMat", 0, 50),window2=0;
    cleardevice();
    setfillstyle(SOLID_FILL,DARKGRAY);
    floodfill(1,1,WHITE);
    setbkcolor(DARKGRAY);

    char titlu_matrici[]="Introduceti dimensiunea matricelor:";
    settextstyle(4,HORIZ_DIR,5);
    setcolor(WHITE);
    outtextxy(G_WINDOW_WIDTH/2-textwidth(titlu_matrici)/2,100,titlu_matrici);

    Matrix m1,m2,m3;

    gwindow_read_int(m1.n,2,1,6,0,G_WINDOW_WIDTH/2-200,G_WINDOW_HEIGHT/2);
    gwindow_read_int(m1.m,2,1,6,0,G_WINDOW_WIDTH/2-100,G_WINDOW_HEIGHT/2);
    m2.n=m1.m;
    char m2_n_text[2]="";
    itoa(m2.n,m2_n_text,10);
    outtextxy(G_WINDOW_WIDTH/2-textwidth(m2_n_text)/2+100,G_WINDOW_HEIGHT/2,m2_n_text);
    gwindow_read_int(m2.m,2,1,6,0,G_WINDOW_WIDTH/2+200,G_WINDOW_HEIGHT/2);

    char text_confirma[]="Confirma";
    outtextxy((G_WINDOW_WIDTH-textwidth(text_confirma))/2-200,650,text_confirma);
    Button confirma;
    Button_Setup(confirma,(G_WINDOW_WIDTH-textwidth(text_confirma))/2-200,650,text_confirma);

    char text_anuleaza[]="Anuleaza";
    outtextxy((G_WINDOW_WIDTH-textwidth(text_anuleaza))/2+200,650,text_anuleaza);
    Button anuleaza;
    Button_Setup(anuleaza,(G_WINDOW_WIDTH-textwidth(text_anuleaza))/2+200,650,text_anuleaza);

    initMatrix(m1);
    initMatrix(m2);
    while(1) {
        if(ismouseclick(WM_LBUTTONDOWN)) {
            int mx=mousex();
            int my=mousey();
            if(isOnButton(anuleaza,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                gwindow_read_int(m1.n,2,1,6,0,G_WINDOW_WIDTH/2-200,G_WINDOW_HEIGHT/2);
                gwindow_read_int(m1.m,2,1,6,0,G_WINDOW_WIDTH/2-100,G_WINDOW_HEIGHT/2);
                m2.n=m1.m;
                itoa(m2.n,m2_n_text,10);
                outtextxy(G_WINDOW_WIDTH/2-textwidth(m2_n_text)/2+100,G_WINDOW_HEIGHT/2,m2_n_text);
                gwindow_read_int(m2.m,2,1,6,0,G_WINDOW_WIDTH/2+200,G_WINDOW_HEIGHT/2);
            }
            if(isOnButton(confirma,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                draw_matrix_in_window(m1,590,M_WINDOW_HEIGHT-200);
                draw_matrix_in_window(m2,1700,M_WINDOW_HEIGHT-200);
                Design_Matrix();
                int last_i1=0, last_j1=0,current_i1=0,current_j1=0;
                int last_i2=0, last_j2=0,current_i2=0,current_j2=0;

                setcolor(WHITE);
                setbkcolor(BLACK);
                settextstyle(10,HORIZ_DIR,5);

                char text_run[]="RUN";
                outtextxy(1165,50,text_run);
                Button run;
                Button_Setup(run,1165,50,text_run);

                char text_code[]="CODE";
                outtextxy(1305,50,text_code);
                Button code;
                Button_Setup(code,1305,50,text_code);

                char text_back[]="BACK";
                outtextxy(1465,50,text_back);
                Button b_back;
                Button_Setup(b_back,1465,50,text_back);

                char text_cread[]="CONSOLE READ";
                outtextxy(1225,100,text_cread);
                Button cread;
                Button_Setup(cread,1225,100,text_cread);

                setbkcolor(DARKGRAY);

                bool code_toggle=false;
                bool has_ran=false;
                while(1) {
                    if(ismouseclick(WM_LBUTTONDOWN)) {
                        clearmouseclick(WM_LBUTTONDOWN);
                        int mx=mousex();
                        int my=mousey();
                        if(isInMatrix(m1,mx,my)) {
                            gwindow_matrix_cell_read(m1,last_i1,last_j1,current_i1,current_j1,mx,my);
                        }
                        else {
                            if(current_i1 && current_j1) {
                                setcolor(WHITE);
                                rectangle(m1.stanga+m1.latura*(last_j1-1),m1.sus+m1.latura*(last_i1-1),m1.stanga+m1.latura*last_j1,m1.sus+m1.latura*last_i1);
                            }
                            current_i1=current_j1=0;
                        }
                        if(isInMatrix(m2,mx,my)) {
                            gwindow_matrix_cell_read(m2,last_i2,last_j2,current_i2,current_j2,mx,my);
                        }
                        else {
                            if(current_i2 && current_j2) {
                                setcolor(WHITE);
                                rectangle(m2.stanga+m2.latura*(last_j2-1),m2.sus+m2.latura*(last_i2-1),m2.stanga+m2.latura*last_j2,m2.sus+m2.latura*last_i2);
                            }
                            current_i2=current_j2=0;
                        }
                        if(isOnButton(run,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            if(has_ran) {
                                setcolor(LIGHTGRAY);
                                rectangle(30,730,1150-40,880);
                                setfillstyle(SOLID_FILL,LIGHTMAGENTA);
                                floodfill(31,731,LIGHTGRAY);
                                draw_matrix_in_window(m1,590,M_WINDOW_HEIGHT-200);
                                draw_matrix_in_window(m2,1700,M_WINDOW_HEIGHT-200);
                                has_ran=false;
                            }
                            Animation_Matrix_Cell_Mul(m1,m2,m3,has_ran,window1,window2);
                        }
                        if(isOnButton(b_back,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            if(!window2) {
                                setcurrentwindow(window2);
                                closegraph();
                            }
                            return;
                        }
                        if(isOnButton(cread,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            for(int i=0;i<m1.n;i++) {
                                for(int j=0;j<m1.m;j++) {
                                    cin>>m1.mat[i][j];
                                }
                            }
                            for(int i=0;i<m2.n;i++) {
                                for(int j=0;j<m2.m;j++) {
                                    cin>>m2.mat[i][j];
                                }
                            }
                            draw_matrix_in_window(m1,590,M_WINDOW_HEIGHT-200);
                            draw_matrix_in_window(m2,1700,M_WINDOW_HEIGHT-200);
                        }
                    }
                }
            }
            else {
                clearmouseclick(WM_LBUTTONDOWN);
            }
        }
    }
    //return;
}

///========================================================
///                 TRANSPUSA UNEI MATRICE
///========================================================
void Animation_Matrix_Trans(Matrix m1, Matrix m2, bool &has_ran) {
    has_ran=true;

    setcolor(LIGHTGRAY);
    rectangle(30,730,1150-40,880);
    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    floodfill(31,731,LIGHTGRAY);

    int offset1=0;
    int current_i=0,current_j=0,last_i=0,last_j=0;

    for(current_i=1;current_i<=m1.n;current_i++) {
        for(current_j=1;current_j<=m1.m;current_j++) {
            Animation_Redraw_Cell(RED,current_i,current_j,m1);
            m2.mat[current_j-1][current_i-1]=m1.mat[current_i-1][current_j-1];
            Animation_Redraw_Cell(RED,current_j,current_i,m2);

            int text_x1=45;
            int text_y1=800;

            setfillstyle(SOLID_FILL,LIGHTMAGENTA);
            bar(text_x1,text_y1,text_x1+offset1,text_y1+textheight("0"));

            settextstyle(4,HORIZ_DIR,2);
            setbkcolor(LIGHTMAGENTA);
            char text1[]="Celula [";
            char text2[2]="";
            itoa(current_i,text2,10);
            char text3[]="] [";
            char text4[2]="";
            itoa(current_j,text4,10);
            char text5[]="] din M1, devine celula [";

            outtextxy(text_x1,text_y1,text1);
            offset1+=textwidth(text1);
            outtextxy(text_x1+offset1,text_y1,text2);
            offset1+=textwidth(text2);
            outtextxy(text_x1+offset1,text_y1,text3);
            offset1+=textwidth(text3);
            outtextxy(text_x1+offset1,text_y1,text4);
            offset1+=textwidth(text4);
            outtextxy(text_x1+offset1,text_y1,text5);
            offset1+=textwidth(text5);
            outtextxy(text_x1+offset1,text_y1,text4);
            offset1+=textwidth(text4);
            outtextxy(text_x1+offset1,text_y1,text3);
            offset1+=textwidth(text3);
            outtextxy(text_x1+offset1,text_y1,text2);
            offset1+=textwidth(text2);
            outtextxy(text_x1+offset1,text_y1,"] din M2");
            offset1=0;
            setbkcolor(DARKGRAY);

            delay(1000);
            Animation_Redraw_Cell(GREEN,current_i,current_j,m1);
            Animation_Redraw_Cell(GREEN,current_j,current_i,m2);
        }
    }
}

void Window_Matrix_Trans() {
    int G_WINDOW_WIDTH=1600;
    int G_WINDOW_HEIGHT=900;
    int M_WINDOW_WIDTH=1150;
    int M_WINDOW_HEIGHT=900;

    closegraph();
    initwindow(G_WINDOW_WIDTH, G_WINDOW_HEIGHT, "BibMat", 150, 50);
    cleardevice();
    setfillstyle(SOLID_FILL,DARKGRAY);
    floodfill(1,1,WHITE);
    setbkcolor(DARKGRAY);

    char titlu_matrici[]="Introduceti dimensiunea matricei:";
    settextstyle(4,HORIZ_DIR,5);
    setcolor(WHITE);
    outtextxy(G_WINDOW_WIDTH/2-textwidth(titlu_matrici)/2,100,titlu_matrici);

    Matrix m1,m2,m3;

    gwindow_read_int(m1.n,2,1,6,0,G_WINDOW_WIDTH/2-200,G_WINDOW_HEIGHT/2);
    gwindow_read_int(m1.m,2,1,6,0,G_WINDOW_WIDTH/2-100,G_WINDOW_HEIGHT/2);
    m2.n=m1.m;
    char m2_n_text[2]="";
    itoa(m2.n,m2_n_text,10);
    outtextxy(G_WINDOW_WIDTH/2-textwidth(m2_n_text)/2+100,G_WINDOW_HEIGHT/2,m2_n_text);
    m2.m=m1.n;
    char m2_m_text[2]="";
    itoa(m2.m,m2_m_text,10);
    outtextxy(G_WINDOW_WIDTH/2-textwidth(m2_m_text)/2+200,G_WINDOW_HEIGHT/2,m2_m_text);

    char text_confirma[]="Confirma";
    outtextxy((G_WINDOW_WIDTH-textwidth(text_confirma))/2-200,650,text_confirma);
    Button confirma;
    Button_Setup(confirma,(G_WINDOW_WIDTH-textwidth(text_confirma))/2-200,650,text_confirma);

    char text_anuleaza[]="Anuleaza";
    outtextxy((G_WINDOW_WIDTH-textwidth(text_anuleaza))/2+200,650,text_anuleaza);
    Button anuleaza;
    Button_Setup(anuleaza,(G_WINDOW_WIDTH-textwidth(text_anuleaza))/2+200,650,text_anuleaza);

    initMatrix(m1);
    initMatrix(m2);
    while(1) {
        if(ismouseclick(WM_LBUTTONDOWN)) {
            int mx=mousex();
            int my=mousey();
            if(isOnButton(anuleaza,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                gwindow_read_int(m1.n,2,1,6,0,G_WINDOW_WIDTH/2-200,G_WINDOW_HEIGHT/2);
                gwindow_read_int(m1.m,2,1,6,0,G_WINDOW_WIDTH/2-100,G_WINDOW_HEIGHT/2);
                m2.n=m1.m;
                itoa(m2.n,m2_n_text,10);
                outtextxy(G_WINDOW_WIDTH/2-textwidth(m2_n_text)/2+100,G_WINDOW_HEIGHT/2,m2_n_text);
                m2.m=m1.n;
                itoa(m2.m,m2_m_text,10);
                outtextxy(G_WINDOW_WIDTH/2-textwidth(m2_m_text)/2+200,G_WINDOW_HEIGHT/2,m2_m_text);
            }
            if(isOnButton(confirma,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                draw_matrix_in_window(m1,590,M_WINDOW_HEIGHT-200);
                draw_matrix_in_window(m2,1700,M_WINDOW_HEIGHT-200);

                setbkcolor(DARKGRAY);
                setcolor(WHITE);
                settextstyle(4,HORIZ_DIR,6);
                outtextxy(m2.stanga+m2.width+textwidth("t"),m2.sus,"t");

                Design_Matrix();
                int last_i1=0, last_j1=0,current_i1=0,current_j1=0;
                int last_i2=0, last_j2=0,current_i2=0,current_j2=0;

                setcolor(WHITE);
                setbkcolor(BLACK);
                settextstyle(10,HORIZ_DIR,5);

                char text_run[]="RUN";
                outtextxy(1165,50,text_run);
                Button run;
                Button_Setup(run,1165,50,text_run);

                char text_code[]="CODE";
                outtextxy(1305,50,text_code);
                Button code;
                Button_Setup(code,1305,50,text_code);

                char text_back[]="BACK";
                outtextxy(1465,50,text_back);
                Button b_back;
                Button_Setup(b_back,1465,50,text_back);

                char text_cread[]="CONSOLE READ";
                outtextxy(1225,100,text_cread);
                Button cread;
                Button_Setup(cread,1225,100,text_cread);

                setbkcolor(DARKGRAY);

                bool code_toggle=false;
                bool has_ran=false;
                while(1) {
                    if(ismouseclick(WM_LBUTTONDOWN)) {
                        clearmouseclick(WM_LBUTTONDOWN);
                        int mx=mousex();
                        int my=mousey();
                        if(isInMatrix(m1,mx,my)) {
                            gwindow_matrix_cell_read(m1,last_i1,last_j1,current_i1,current_j1,mx,my);
                        }
                        else {
                            if(current_i1 && current_j1) {
                                setcolor(WHITE);
                                rectangle(m1.stanga+m1.latura*(last_j1-1),m1.sus+m1.latura*(last_i1-1),m1.stanga+m1.latura*last_j1,m1.sus+m1.latura*last_i1);
                            }
                            current_i1=current_j1=0;
                        }
                        if(isOnButton(run,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            if(has_ran) {
                                setcolor(LIGHTGRAY);
                                rectangle(30,730,1150-40,880);
                                setfillstyle(SOLID_FILL,LIGHTMAGENTA);
                                floodfill(31,731,LIGHTGRAY);
                                draw_matrix_in_window(m1,590,M_WINDOW_HEIGHT-200);
                                draw_matrix_in_window(m2,1700,M_WINDOW_HEIGHT-200);
                                has_ran=false;
                            }
                            Animation_Matrix_Trans(m1,m2,has_ran);
                        }
                        if(isOnButton(b_back,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            return;
                        }
                        if(isOnButton(cread,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            for(int i=0;i<m1.n;i++) {
                                for(int j=0;j<m1.m;j++) {
                                    cin>>m1.mat[i][j];
                                }
                            }
                            draw_matrix_in_window(m1,590,M_WINDOW_HEIGHT-200);
                        }
                    }
                }
            }
            else {
                clearmouseclick(WM_LBUTTONDOWN);
            }
        }
    }
    //return;
}

///========================================================
///           RIDICAREA LA PUTERE A UNEI MATRICE
///========================================================
void Animation_Matrix_Pow(Matrix m1, Matrix m2, Matrix &m3, bool &has_ran, int window1, int &window2, int iterantions) {
    has_ran=true;

    Matrix m=m1;

    m2.mat=m1.mat;
    draw_matrix_in_window(m2,1700,700);

    m3.n=m1.n;
    m3.m=m2.m;
    initMatrix(m3);

    setcolor(LIGHTGRAY);
    rectangle(30,730,1150-40,880);
    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    floodfill(31,731,LIGHTGRAY);

    window2=initwindow(600,600,"Matrice Rezultat",1920-600,250);
    for(int k=0;k<iterantions;k++) {
        if(k) {
            m1.mat=m3.mat;
            m2.mat=m.mat;
            initMatrix(m3);
        }
        int offset1=0;
        int current_i1=0,current_j1=0,last_i1=0,last_j1=0;
        int current_i2=0,current_j2=0,last_i2=0,last_j2=0;
        int current_i3=0,current_j3=0,last_i3=0,last_j3=0;
        int offset_x=0,offset_y=0;
        int left_limit=45,right_limit=1090,start_y=740+textheight("0");
        int sum=0;

        setcurrentwindow(window2);
        setbkcolor(DARKGRAY);
        setfillstyle(SOLID_FILL,DARKGRAY);
        floodfill(1,1,WHITE);
        draw_matrix_in_window(m3,600,600);

        setfillstyle(SOLID_FILL,DARKGRAY);
        bar(0,0,textwidth("Puterea 10"),textheight("0"));
        setcolor(WHITE);
        settextstyle(4,HORIZ_DIR,2);
        char temp[3]="";
        memset(temp,'\0',3);
        itoa(k+2,temp,10);
        outtextxy(0,0,"Puterea ");
        outtextxy(textwidth("Puterea "),0,temp);

        for(current_i1=1;current_i1<=m1.n;current_i1++) {
            setcurrentwindow(window1);
            draw_matrix_in_window(m2,1700,700);
            offset_x=0;
            offset_y=0;
            for(current_j2=1;current_j2<=m2.m;current_j2++) {
                setcolor(LIGHTGRAY);
                rectangle(30,730,1150-40,880);
                setfillstyle(SOLID_FILL,LIGHTMAGENTA);
                floodfill(31,731,LIGHTGRAY);
                offset_x=0;
                offset_y=0;
                for(current_i2=1;current_i2<=m2.n;current_i2++) {
                    setcurrentwindow(window2);
                    Animation_Redraw_Cell(RED,current_i1,current_j2,m3);

                    setcurrentwindow(window1);
                    Animation_Redraw_Cell(RED,current_i1,current_i2,m1);
                    Animation_Redraw_Cell(RED,current_i2,current_j2,m2);

                    int text_x1=45;
                    int text_y1=735;

                    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
                    bar(text_x1,text_y1,text_x1+offset1,text_y1+textheight("0"));

                    settextstyle(4,HORIZ_DIR,2);
                    setbkcolor(LIGHTMAGENTA);
                    char text1[]="Inmultim elementul [";
                    char text2[2]="";
                    itoa(current_i1,text2,10);
                    char text3[]="] [";
                    char text4[2]="";
                    itoa(current_i2,text4,10);
                    char text5[]="] din M1, cu elementul [";
                    char text6[2]="";
                    itoa(current_i2,text6,10);
                    char text7[2]="";
                    itoa(current_j2,text7,10);

                    outtextxy(text_x1,text_y1,text1);
                    offset1+=textwidth(text1);
                    outtextxy(text_x1+offset1,text_y1,text2);
                    offset1+=textwidth(text2);
                    outtextxy(text_x1+offset1,text_y1,text3);
                    offset1+=textwidth(text3);
                    outtextxy(text_x1+offset1,text_y1,text4);
                    offset1+=textwidth(text4);
                    outtextxy(text_x1+offset1,text_y1,text5);
                    offset1+=textwidth(text5);
                    outtextxy(text_x1+offset1,text_y1,text6);
                    offset1+=textwidth(text6);
                    outtextxy(text_x1+offset1,text_y1,text3);
                    offset1+=textwidth(text3);
                    outtextxy(text_x1+offset1,text_y1,text7);
                    offset1+=textwidth(text7);
                    outtextxy(text_x1+offset1,text_y1,"] din M2:");
                    offset1=0;
                    setbkcolor(DARKGRAY);

                    char text_plus[]=" + ";
                    char text_plus_left[]="+ ";
                    char text_plus_right[]=" +";
                    char text_mul[]=" × ";
                    char text_egal[]=" = ";
                    char text_egal_left[]="= ";
                    char text_egal_right[]=" =";
                    char text_number1[11]="";
                    char text_number2[11]="";
                    itoa(m1.mat[current_i1-1][current_i2-1],text_number1,10);
                    itoa(m2.mat[current_i2-1][current_j2-1],text_number2,10);
                    char text_number[25]="";
                    memset(text_number,'\0',25);
                    strcat(text_number,text_number1);
                    strcat(text_number,text_mul);
                    strcat(text_number,text_number2);

                    sum+=m1.mat[current_i1-1][current_i2-1]*m2.mat[current_i2-1][current_j2-1];
                    setbkcolor(LIGHTMAGENTA);
                    if(left_limit+offset_x+textwidth(text_number)<=right_limit) {
                        outtextxy(left_limit+offset_x,start_y+offset_y,text_number);
                        offset_x+=textwidth(text_number);
                        if(left_limit+offset_x+textwidth(text_plus)<=right_limit) {
                            if(current_i2==m1.m) {
                                outtextxy(left_limit+offset_x,start_y+offset_y,text_egal);
                                offset_x+=textwidth(text_egal);
                                char nr[12]="";
                                itoa(sum,nr,10);
                                if(left_limit+offset_x+textwidth(nr)<=right_limit) {
                                    setbkcolor(LIGHTMAGENTA);
                                    settextstyle(4,HORIZ_DIR,2);
                                    setcolor(WHITE);
                                    outtextxy(left_limit+offset_x,start_y+offset_y,nr);
                                    setbkcolor(DARKGRAY);
                                }
                                m3.mat[current_i1-1][current_j2-1]=sum;
                                setcurrentwindow(window2);
                                Animation_Redraw_Cell(RED,current_i1,current_j2,m3);
                                setcurrentwindow(window1);
                                sum=0;
                            }
                            else {
                                outtextxy(left_limit+offset_x,start_y+offset_y,text_plus);
                                offset_x+=textwidth(text_plus);
                            }
                        }
                        else {
                            if(current_i2==m1.m) {
                                offset_x=0;
                                offset_y+=textheight("0");
                                outtextxy(left_limit+offset_x,start_y+offset_y,text_egal_left);
                                offset_x+=textwidth(text_egal_left);
                                char nr[12]="";
                                itoa(sum,nr,10);
                                if(left_limit+offset_x+textwidth(nr)<=right_limit) {
                                    setbkcolor(LIGHTMAGENTA);
                                    settextstyle(4,HORIZ_DIR,2);
                                    setcolor(WHITE);
                                    outtextxy(left_limit+offset_x,start_y+offset_y,nr);
                                    setbkcolor(DARKGRAY);
                                }
                                m3.mat[current_i1-1][current_j2-1]=sum;
                                setcurrentwindow(window2);
                                Animation_Redraw_Cell(RED,current_i1,current_j2,m3);
                                setcurrentwindow(window1);
                                sum=0;
                            }
                            else {
                                offset_x=0;
                                offset_y+=textheight("0");
                                outtextxy(left_limit+offset_x,start_y+offset_y,text_plus_left);
                                offset_x+=textwidth(text_plus_left);
                            }
                        }
                    }
                    else {
                        offset_x=0;
                        offset_y+=textheight("0");
                        outtextxy(left_limit+offset_x,start_y+offset_y,text_number);
                        offset_x+=textwidth(text_number);
                        if(current_i2==m1.m) {
                            outtextxy(left_limit+offset_x,start_y+offset_y,text_egal);
                            offset_x+=textwidth(text_egal);
                            char nr[12]="";
                            itoa(sum,nr,10);
                            if(left_limit+offset_x+textwidth(nr)<=right_limit) {
                                setbkcolor(LIGHTMAGENTA);
                                settextstyle(4,HORIZ_DIR,2);
                                setcolor(WHITE);
                                outtextxy(left_limit+offset_x,start_y+offset_y,nr);
                                setbkcolor(DARKGRAY);
                            }
                            m3.mat[current_i1-1][current_j2-1]=sum;
                            setcurrentwindow(window2);
                            Animation_Redraw_Cell(RED,current_i1,current_j2,m3);
                            setcurrentwindow(window1);
                            sum=0;
                        }
                        else {
                            outtextxy(left_limit+offset_x,start_y+offset_y,text_plus);
                            offset_x+=textwidth(text_plus);
                        }
                    }
                    setbkcolor(DARKGRAY);

                    delay(800);
                    setcurrentwindow(window2);
                    Animation_Redraw_Cell(GREEN,current_i1,current_j2,m3);
                    setcurrentwindow(window1);
                    Animation_Redraw_Cell(GREEN,current_i1,current_i2,m1);
                    Animation_Redraw_Cell(GREEN,current_i2,current_j2,m2);
                }
                //delay(250);
            }
        }
    }
}

void Window_Matrix_Pow() {
    int G_WINDOW_WIDTH=1600;
    int G_WINDOW_HEIGHT=900;
    int M_WINDOW_WIDTH=1150;
    int M_WINDOW_HEIGHT=900;

    closegraph();
    int window1=initwindow(G_WINDOW_WIDTH, G_WINDOW_HEIGHT, "BibMat", 0, 50),window2=0;
    cleardevice();
    setfillstyle(SOLID_FILL,DARKGRAY);
    floodfill(1,1,WHITE);
    setbkcolor(DARKGRAY);

    char titlu_matrici[]="Introduceti dimensiunea matricei si puterea:";
    settextstyle(4,HORIZ_DIR,5);
    setcolor(WHITE);
    outtextxy(G_WINDOW_WIDTH/2-textwidth(titlu_matrici)/2,100,titlu_matrici);

    Matrix m1,m2,m3;
    int iterations;

    gwindow_read_int(m1.n,2,1,6,0,G_WINDOW_WIDTH/2-180,G_WINDOW_HEIGHT/2);
    m1.m=m1.n;
    char m1_m_text[2]="";
    itoa(m1.m,m1_m_text,10);
    outtextxy(G_WINDOW_WIDTH/2-textwidth(m1_m_text)/2-80,G_WINDOW_HEIGHT/2,m1_m_text);
    m2.n=m1.n;
    m2.m=m1.n;
    gwindow_read_int(iterations,3,2,100,0,G_WINDOW_WIDTH/2+80,G_WINDOW_HEIGHT/2);

    char text_confirma[]="Confirma";
    outtextxy((G_WINDOW_WIDTH-textwidth(text_confirma))/2-200,650,text_confirma);
    Button confirma;
    Button_Setup(confirma,(G_WINDOW_WIDTH-textwidth(text_confirma))/2-200,650,text_confirma);

    char text_anuleaza[]="Anuleaza";
    outtextxy((G_WINDOW_WIDTH-textwidth(text_anuleaza))/2+200,650,text_anuleaza);
    Button anuleaza;
    Button_Setup(anuleaza,(G_WINDOW_WIDTH-textwidth(text_anuleaza))/2+200,650,text_anuleaza);

    initMatrix(m1);
    initMatrix(m2);
    while(1) {
        if(ismouseclick(WM_LBUTTONDOWN)) {
            int mx=mousex();
            int my=mousey();
            if(isOnButton(anuleaza,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                gwindow_read_int(m1.n,2,1,6,0,G_WINDOW_WIDTH/2-50,G_WINDOW_HEIGHT/2);
                m1.m=m1.n;
                itoa(m1.m,m1_m_text,10);
                outtextxy(G_WINDOW_WIDTH/2-textwidth(m1_m_text)/2+50,G_WINDOW_HEIGHT/2,m1_m_text);
                m2.n=m1.n;
                m2.m=m1.n;
                gwindow_read_int(iterations,3,2,100,0,G_WINDOW_WIDTH/2+50,G_WINDOW_HEIGHT/2);
            }
            if(isOnButton(confirma,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                draw_matrix_in_window(m1,590,M_WINDOW_HEIGHT-200);
                draw_matrix_in_window(m2,1700,M_WINDOW_HEIGHT-200);
                Design_Matrix();
                int last_i1=0, last_j1=0,current_i1=0,current_j1=0;
                int last_i2=0, last_j2=0,current_i2=0,current_j2=0;

                setcolor(WHITE);
                setbkcolor(BLACK);
                settextstyle(10,HORIZ_DIR,5);

                char text_run[]="RUN";
                outtextxy(1165,50,text_run);
                Button run;
                Button_Setup(run,1165,50,text_run);

                char text_code[]="CODE";
                outtextxy(1305,50,text_code);
                Button code;
                Button_Setup(code,1305,50,text_code);

                char text_back[]="BACK";
                outtextxy(1465,50,text_back);
                Button b_back;
                Button_Setup(b_back,1465,50,text_back);

                char text_cread[]="CONSOLE READ";
                outtextxy(1225,100,text_cread);
                Button cread;
                Button_Setup(cread,1225,100,text_cread);

                setbkcolor(DARKGRAY);

                bool code_toggle=false;
                bool has_ran=false;
                while(1) {
                    if(ismouseclick(WM_LBUTTONDOWN)) {
                        clearmouseclick(WM_LBUTTONDOWN);
                        int mx=mousex();
                        int my=mousey();
                        if(isInMatrix(m1,mx,my)) {
                            gwindow_matrix_cell_read(m1,last_i1,last_j1,current_i1,current_j1,mx,my);
                        }
                        else {
                            if(current_i1 && current_j1) {
                                setcolor(WHITE);
                                rectangle(m1.stanga+m1.latura*(last_j1-1),m1.sus+m1.latura*(last_i1-1),m1.stanga+m1.latura*last_j1,m1.sus+m1.latura*last_i1);
                            }
                            current_i1=current_j1=0;
                        }
//                        if(isInMatrix(m2,mx,my)) {
//                            gwindow_matrix_cell_read(m2,last_i2,last_j2,current_i2,current_j2,mx,my);
//                        }
//                        else {
//                            if(current_i2 && current_j2) {
//                                setcolor(WHITE);
//                                rectangle(m2.stanga+m2.latura*(last_j2-1),m2.sus+m2.latura*(last_i2-1),m2.stanga+m2.latura*last_j2,m2.sus+m2.latura*last_i2);
//                            }
//                            current_i2=current_j2=0;
//                        }
                        if(isOnButton(run,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            if(has_ran) {
                                setcolor(LIGHTGRAY);
                                rectangle(30,730,1150-40,880);
                                setfillstyle(SOLID_FILL,LIGHTMAGENTA);
                                floodfill(31,731,LIGHTGRAY);
                                draw_matrix_in_window(m1,590,M_WINDOW_HEIGHT-200);
                                draw_matrix_in_window(m2,1700,M_WINDOW_HEIGHT-200);
                                has_ran=false;
                            }
                            Animation_Matrix_Pow(m1,m2,m3,has_ran,window1,window2,iterations);
                        }
                        if(isOnButton(b_back,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            if(!window2) {
                                setcurrentwindow(window2);
                                closegraph();
                            }
                            return;
                        }
                        if(isOnButton(cread,mx,my)) {
                            clearmouseclick(WM_LBUTTONDOWN);
                            for(int i=0;i<m1.n;i++) {
                                for(int j=0;j<m1.m;j++) {
                                    cin>>m1.mat[i][j];
                                }
                            }
                            for(int i=0;i<m2.n;i++) {
                                for(int j=0;j<m2.m;j++) {
                                    cin>>m2.mat[i][j];
                                }
                            }
                            draw_matrix_in_window(m1,590,M_WINDOW_HEIGHT-200);
                            draw_matrix_in_window(m2,1700,M_WINDOW_HEIGHT-200);
                        }
                    }
                }
            }
            else {
                clearmouseclick(WM_LBUTTONDOWN);
            }
        }
    }
    //return;
}
