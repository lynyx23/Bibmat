#include <graphics.h>
#include <winbgim.h>
#include "Button.h"

using namespace std;

void Button_Setup(Button &b, int x, int y, char text[]) {
    b.left=x;
    b.top=y;
    b.right=x+textwidth(text);
    b.bottom=y+textheight(text);
}

bool isOnButton(Button b, int x, int y) {
    if((b.left<=x && b.right>=x) && (b.top<=y && b.bottom>=y))
        return true;
    return false;
}
