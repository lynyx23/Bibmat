#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MatrixFunctions.h"

using namespace std;

void initMatrix(Matrix &m) {
    m.mat=new int*[m.n];
    for(int i=0;i<m.n;i++) {
        m.mat[i]=new int[m.m];
        for(int j=0;j<m.m;j++) {
            m.mat[i][j]=0;
        }
    }
}

bool isInMatrix(Matrix m, int x, int y) {
    if((m.stanga<x && m.stanga+m.width>x) && (m.sus<y && m.sus+m.height>y))
        return true;
    return false;
}

void int_gprint_check(char text[], char temp[], int temp_size, int lower_limit, int upper_limit) {
    memset(temp,'\0',temp_size);
    if(strlen(text)<lower_limit) {
        strcpy(temp,text);
    }
    else {
        if(strlen(text)<upper_limit) {
            strncpy(temp,text,2);
            strcat(temp,".");
            strcat(temp,text+strlen(text)-1);
        }
    }
}

void draw_matrix_in_window(Matrix &m, int WINDOW_WIDTH, int WINDOW_HEIGHT) {
    m.width=520;
    m.height=520;
    m.latura=m.width/max(m.n,m.m);
    if(m.m!=m.n) {
        m.width=m.latura*m.m;
        m.height=m.latura*m.n;
    }
    m.stanga=(WINDOW_WIDTH-m.width)/2;
    m.sus=(WINDOW_HEIGHT-m.height)/2;
    setcolor(WHITE);
    for(int i=1; i<=m.n; i++) {
        for(int j=1; j<=m.m; j++) {
            rectangle(m.stanga+m.latura*(j-1),m.sus+m.latura*(i-1),m.stanga+m.latura*j,m.sus+m.latura*i);

            int colt_staga_x=m.stanga+m.latura*(j-1);
            int colt_staga_y=m.sus+m.latura*(i-1);

            setfillstyle(SOLID_FILL,DARKGRAY);
            bar(m.stanga+m.latura*(j-1)+1,m.sus+m.latura*(i-1)+1,m.stanga+m.latura*j-1,m.sus+m.latura*i-1);

            char cell_text[6]="";
            char g_text[6]="";
            memset(cell_text,'\0',6);
            memset(g_text,'\0',6);
            itoa(m.mat[i-1][j-1],cell_text,10);
            int_gprint_check(cell_text,g_text,6,6,10);

            setcolor(WHITE);
            settextstyle(4,HORIZ_DIR,3);
            outtextxy(colt_staga_x+(m.latura-textwidth(g_text))/2,colt_staga_y+(m.latura-textheight(g_text))/2,g_text);
        }
    }
}

void redraw_red_cell(int i, int j, Matrix m) {
    setcolor(RED);
    rectangle(m.stanga+m.latura*(j-1),m.sus+m.latura*(i-1),m.stanga+m.latura*j,m.sus+m.latura*i);
    setfillstyle(SOLID_FILL,getbkcolor());
    floodfill(m.stanga+m.latura*(j-1)+1,m.sus+m.latura*(i-1)+1,RED);
}

void gwindow_read_int(int &value, int string_size, int max_string_size, int max_int_size, int min_int_size, int x, int y) {
    value=0;
    char* text=(char*) malloc(string_size);
    memset(text,'\0',string_size);
    int it=0;
    bool stop_read=false;
    do {
        if(textwidth(text)==0) {
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(x-textwidth("0"),y,x+textwidth("0"),y+textheight("0"));
        }
        else {
            setfillstyle(SOLID_FILL, getbkcolor());
            bar(x-textwidth(text),y,x+textwidth(text),y+textheight(text));
        }
        setcolor(WHITE);
        outtextxy(x-textwidth(text)/2,y,text);
        char c=getch();
        switch(c) {
            case 8: //Backspace
            {
                if(strlen(text)>0) {
                    int n=strlen(text);
                    strcpy(text+n-1,text+n);
                    it--;
                    setfillstyle(SOLID_FILL, RED);
                    bar(x-textwidth(text)/2,y,x+textwidth(text),y+textheight(text));
                }
                break;
            }
            case 13: //Enter
            {
                if(strlen(text)) {
                    stop_read=true;
                    value=atoi(text);
                }
                break;
            }
            case 32: //Space
            {
                if(strlen(text)) {
                    stop_read=true;
                    value=atoi(text);
                }
                break;
            }
            default:
            {
                if(strlen(text)<max_string_size) {
                    if((c>='0' && c<='9' || c=='-') && c-'0'<max_int_size && c-'0'>min_int_size) {
                        text[it++]=c;
                    }
                }
                break;
            }
        }
        clearmouseclick(WM_LBUTTONDOWN);
    } while(!stop_read);
    return;
}

void gwindow_matrix_cell_read(Matrix &m, int &last_i, int &last_j, int &current_i, int &current_j, int mx, int my) {
    if(current_i && current_j) {
        setcolor(WHITE);
        rectangle(m.stanga+m.latura*(last_j-1),m.sus+m.latura*(last_i-1),m.stanga+m.latura*last_j,m.sus+m.latura*last_i);
    }
    current_i=(my-m.sus)/m.latura+1;
    current_j=(mx-m.stanga)/m.latura+1;
    last_i=current_i;
    last_j=current_j;

    setcolor(RED);
    rectangle(m.stanga+m.latura*(current_j-1),m.sus+m.latura*(current_i-1),m.stanga+m.latura*current_j,m.sus+m.latura*current_i);

    char cell_text[11]="";
    int cell_text_it=0;
    char* g_text=(char*) malloc(11);
    memset(g_text,'\0',11);
    bool stop_read=false;
    do {
        redraw_red_cell(current_i,current_j,m);

        int colt_staga_x=m.stanga+m.latura*(current_j-1);
        int colt_staga_y=m.sus+m.latura*(current_i-1);
        setcolor(WHITE);
        settextstyle(4,HORIZ_DIR,3);
        if(strlen(cell_text)) {
            outtextxy(colt_staga_x+(m.latura-textwidth(g_text))/2,colt_staga_y+(m.latura-textheight(g_text))/2,g_text);
        }
        else {
            outtextxy(colt_staga_x+(m.latura-textwidth("0"))/2,colt_staga_y+(m.latura-textheight("0"))/2,"0");
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
                        int_gprint_check(cell_text,g_text,11,6,10);
                    }
                    break;
                }

            }
            case 13: //Enter
            {
                stop_read=true;
                m.mat[current_i-1][current_j-1]=atoi(cell_text);
                setcolor(WHITE);
                rectangle(m.stanga+m.latura*(last_j-1),m.sus+m.latura*(last_i-1),m.stanga+m.latura*last_j,m.sus+m.latura*last_i);
                break;
            }
            case 32: //Space
            {
                stop_read=true;
                m.mat[current_i-1][current_j-1]=atoi(cell_text);
                setcolor(WHITE);
                rectangle(m.stanga+m.latura*(last_j-1),m.sus+m.latura*(last_i-1),m.stanga+m.latura*last_j,m.sus+m.latura*last_i);
                break;
            }
            default:
            {
                if(strlen(cell_text)<10) {
                    if((c>='0' && c<='9') || c=='-') {
                        cell_text[cell_text_it++]=c;
                        memset(g_text,'\0',6);
                        int_gprint_check(cell_text,g_text,11,5,10);
                    }
                }
                break;
            }
        }
    } while(!stop_read);
}

void Design_Matrix() {
//    settextstyle(10,HORIZ_DIR,5);
    setcolor(CYAN);
    rectangle(1150,20,1580,880);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    floodfill(1151,21,CYAN);

    setcolor(LIGHTGRAY);
    rectangle(75,730,1150-75,880);
    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    floodfill(76,731,LIGHTGRAY);

}

void Animation_Redraw_Cell(int COLOR, int i, int j, Matrix m) {
    char cell_text[12]="";
    itoa(m.mat[i-1][j-1],cell_text,10);

    setfillstyle(SOLID_FILL,COLOR);
    bar(m.stanga+m.latura*(j-1)+1,m.sus+m.latura*(i-1)+1,m.stanga+m.latura*j-1,m.sus+m.latura*i-1);

    int colt_staga_x=m.stanga+m.latura*(j-1);
    int colt_staga_y=m.sus+m.latura*(i-1);
    setcolor(WHITE);
    settextstyle(4,HORIZ_DIR,3);
    setbkcolor(COLOR);
    outtextxy(colt_staga_x+(m.latura-textwidth(cell_text))/2,colt_staga_y+(m.latura-textheight(cell_text))/2,cell_text);
    setbkcolor(DARKGRAY);
}
