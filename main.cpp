#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include "MatrixAnimations.h"
#include "VectorAnimation.h"
#include "Button.h"

using namespace std;

void Draw_Menu(int color,int stg,int sus,int stgplus,int susplus)
{
    setfillstyle(SOLID_FILL,color);
    bar(stg,sus,stgplus,susplus);
}

void Window_Vectori() {
   //cleardevice();

    Draw_Menu(DARKGRAY,0,0,500,600);
    settextstyle(8,0,8);
    setbkcolor(DARKGRAY);
    outtextxy(80,250,"VECTORI");

    Draw_Menu(LIGHTGRAY,50,480,200,550);
    settextstyle(8,0,4);
    setbkcolor(LIGHTGRAY);
    outtextxy(80,500,"BACK");

    Draw_Menu(LIGHTBLUE,500,0,900,600);
    Draw_Menu(BLUE,580,30,800,100);
    settextstyle(8,0,5);
    setbkcolor(BLUE);
    outtextxy(590,45,"OPERATII");
    settextstyle(8,0,4);
    setbkcolor(BROWN);
    setcolor(BLACK);
    outtextxy(520,200,"ADUNARE");
    outtextxy(700,200,"SCADERE");
    setbkcolor(CYAN);
    outtextxy(520,300,"PRODUS");
    outtextxy(700,300,"SCALAR");
    setbkcolor(YELLOW);
    settextstyle(8,0,3);
    outtextxy(520,400,"BUBBLE SORT-CRESCATOR");
    outtextxy(520,450,"BUBBLE SORT-DESCRESCATOR");
    outtextxy(520,500,"SHIFTARE-DREAPTA");
    outtextxy(520,550,"SHIFTARE-STANGA");


    Button B_adunareV,B_scadereV,B_produs,B_scalar,B_bubbleC,B_bubbleD,B_shiftD,B_shiftS;
    Button_Setup(B_adunareV,520,200,"ADUNARE");
    Button_Setup(B_scadereV,700,200,"SCADERE");
    Button_Setup(B_produs,520,300,"PRODUS");
    Button_Setup(B_scalar,700,300,"SCALAR");
    Button_Setup(B_bubbleC,520,400,"BUBBLE SORT-CRESCATOR");
    Button_Setup(B_bubbleD,520,450,"BUBBLE SORT-DESCRESCATOR");
    Button_Setup(B_shiftD,520,500,"SHIFTARE-DREAPTA");
    Button_Setup(B_shiftS,520,550,"SHIFTARE-STANGA");


    while(1) {
        if(ismouseclick(WM_LBUTTONDOWN)) {
            int mx=mousex();
            int my=mousey();
            clearmouseclick(WM_LBUTTONDOWN);
            if(isOnButton(B_adunareV,mx,my)) {
                cleardevice();
                Window_Vector_Suma();
            }
            if(isOnButton(B_scadereV,mx,my))
            {
                cleardevice();
                Window_Vector_Scadere();

            }
            if(isOnButton(B_produs,mx,my)){
                cleardevice();
                Window_Vector_Produs();

            }
            if(isOnButton(B_scalar,mx,my)){
                cleardevice();
                Window_Vector_Scalar();

            }
            if(isOnButton(B_bubbleC,mx,my)){
                cleardevice();
                Window_Vector_Sortare_Crescator();

            }
            if(isOnButton(B_bubbleD,mx,my)){
                cleardevice();
                Window_Vector_Sortare_Descrescator();
            }
            if(isOnButton(B_shiftD,mx,my)){
                cleardevice();
                Window_Vector_Shiftare_Dreapta();
            }
            if(isOnButton(B_shiftS,mx,my)){
                cleardevice();
                Window_Vector_Shiftare_Stanga();
            }
            else {
                clearmouseclick(WM_LBUTTONDOWN);
            }
        }
    }
}

void Window_Matrici() {
    cleardevice();
    Draw_Menu(DARKGRAY,0,0,500,600);
    settextstyle(8,0,8);
    setbkcolor(DARKGRAY);
    outtextxy(80,250,"VECTORI");

    Draw_Menu(LIGHTGRAY,50,480,200,550);
    settextstyle(8,0,4);
    setbkcolor(LIGHTGRAY);
    outtextxy(80,500,"BACK");

    Draw_Menu(LIGHTBLUE,500,0,900,600);
    Draw_Menu(BLUE,580,30,800,100);
    settextstyle(8,0,5);
    setbkcolor(BLUE);
    outtextxy(590,45,"OPERATII");
    setbkcolor(BROWN);
    settextstyle(8,0,2);
    setcolor(BLACK);
    outtextxy(520,130,"ADUNARE-ELEMENTE");
    outtextxy(520,170,"SCADERE-ELEMENTE");
    outtextxy(520,210,"Adunare- diagonala principala");
    outtextxy(520,250,"Adunare- diagonala secundara");
    outtextxy(520,300,"Adunare- sub principala");
    outtextxy(520,350,"Adunare- sub secundara");
    setbkcolor(CYAN);
    outtextxy(520,400,"INMULTIREA MATRICELOR");
    outtextxy(520,450,"RIDICAREA LA PUTERE");
    outtextxy(520,500,"DETERMINANTUL");
    outtextxy(520,550,"TRANSPUSA");
    //outtextxy(700,550,"INVERSA");

    Button B_adunare1,B_scadereM,B_adunare2,B_adunare3,B_adunare4,B_adunare5,B_inmultire,B_ridicare,B_det,B_tr,B_inversa;
    Button_Setup(B_adunare1,520,130,"ADUNARE-ELEMENTE");
    Button_Setup(B_scadereM,520,170,"SCADERE-ELEMENTE");
    Button_Setup(B_adunare2,520,210,"Adunare- diagonala principala");
    Button_Setup(B_adunare3,520,250,"Adunare- diagonala secundara");
    Button_Setup(B_adunare4,520,300,"Adunare- sub principala");
    Button_Setup(B_adunare5,520,350,"Adunare- sub secundara");
    Button_Setup(B_inmultire,520,400,"INMULTIREA MATRICELOR");
    Button_Setup(B_ridicare,520,450,"RIDICAREA LA PUTERE");
    Button_Setup(B_det,520,500,"DETERMINANTUL");
    Button_Setup(B_tr,520,550,"TRANSPUSA");
    //Button_Setup(B_inversa,700,550,"INVERSA");

    while(1) {
        if(ismouseclick(WM_LBUTTONDOWN)) {
            int mx=mousex();
            int my=mousey();
            if(isOnButton(B_adunare1,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                Window_Matrix_Cell_Sum();
                break;
            }
            if(isOnButton(B_scadereM,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                Window_Matrix_Cell_Sub();
                break;
            }
            if(isOnButton(B_adunare2,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                Window_Matrix_First_Diag_Sum();
                break;
            }
            if(isOnButton(B_adunare3,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                Window_Matrix_Second_Diag_Sum();
                break;
            }
            if(isOnButton(B_adunare4,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                Window_Matrix_Under_First_Diag_Sum();
                break;
            }
            if(isOnButton(B_adunare5,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                Window_Matrix_Under_Second_Diag_Sum();
                break;
            }
            if(isOnButton(B_inmultire,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                Window_Matrix_Mul();
                break;
            }
            if(isOnButton(B_ridicare,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                Window_Matrix_Pow();
                break;
            }
            if(isOnButton(B_tr,mx,my)) {
                clearmouseclick(WM_LBUTTONDOWN);
                Window_Matrix_Trans();
                break;
            }
        }
    }
    cout<<"MERGE";
}


void Window_Start()
{
    Draw_Menu(CYAN,0,0,500,600);
    settextstyle(8,0,8);
    setbkcolor(CYAN);
    outtextxy(110,250,"BibMat");

    Draw_Menu(BROWN,500,0,900,600);
    Draw_Menu(MAGENTA,600,100,800,200);
    Draw_Menu(MAGENTA,600,400,800,500);
    Draw_Menu(LIGHTGRAY,50,480,200,550);

    settextstyle(8,0,4);
    setbkcolor(LIGHTGRAY);
    outtextxy(80,500,"BACK");


    settextstyle(8,0,5);
    setbkcolor(MAGENTA);
    outtextxy(610,130,"VECTORI");
    outtextxy(610,430,"MATRICI");
    Button B_vector,B_matrice,B_back;
    Button_Setup(B_vector,610,130,"VECTORI");
    Button_Setup(B_matrice,610,430,"MATRICI");
    Button_Setup(B_back,80,500,"BACK");

        while(1) {
        if(ismouseclick(WM_LBUTTONDOWN)) {
            int mx=mousex();
            int my=mousey();
            clearmouseclick(WM_LBUTTONDOWN);
            if(isOnButton(B_vector,mx,my)) {
                cleardevice();
                Window_Vectori();
                return;
            }
            else if(isOnButton(B_matrice,mx,my)) {
                cleardevice();
                Window_Matrici();
                getch();
            }
            else {
                clearmouseclick(WM_LBUTTONDOWN);
            }
        }
    }

}


void Initial_Window()
{
    for(int i=3;i<=10;i++)
    {
        settextstyle(8,0,i);
        outtextxy(200,200,"BibMat");
        delay(200);
    }
    Draw_Menu(LIGHTBLUE,50,400,220,500);
    Draw_Menu(LIGHTBLUE,610,400,780,500);
    settextstyle(8,0,5);
    setbkcolor(LIGHTBLUE);
    outtextxy(80,425,"EXIT");
    outtextxy(630,425,"START");

    Button B_start,B_exit;
    Button_Setup(B_exit,80,425,"EXIT");
    Button_Setup(B_start,630,425,"START");
      while(1) {
        if(ismouseclick(WM_LBUTTONDOWN)) {
            int mx=mousex();
            int my=mousey();
            clearmouseclick(WM_LBUTTONDOWN);
            if(isOnButton(B_start,mx,my)) {
                cleardevice();
                Window_Start();
                return;
            }
            else if(isOnButton(B_exit,mx,my)) {
                closegraph();
                exit(0);
            }
            else {
                clearmouseclick(WM_LBUTTONDOWN);
            }
        }
    }

}


int main ()
{
    initwindow(900,600, "BibMat", 150,50);
    Initial_Window();
    getch();
    closegraph();

    return 0;
}
