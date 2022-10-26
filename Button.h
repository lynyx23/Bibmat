#ifndef BUTTON_H
#define BUTTON_H

struct Button{
    int left,top,right,bottom;
};

void Button_Setup(Button &b, int x, int y, char text[]);
bool isOnButton(Button b, int x, int y);

#endif // BUTTON_H
