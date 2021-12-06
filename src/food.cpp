#include "food.h"
Food::Food(Color color,int x,int y,int size):
_color(color),_x(x),_y(y),_size(size){
    switch (_color){
        case blue:
            _Color=RGB(128,198,229);
            break;
        case purple:
            _Color=RGB(81,79,147);
            break;
        case yellow:
            _Color=RGB(230,218,122);
            break;
        case green:
            _Color=RGB(173,200,95);
            break;
        case red:
            _Color=RGB(221,91,65);
            break;
        case pink:
            _Color=RGB(230,140,161);
            break;
    }
}