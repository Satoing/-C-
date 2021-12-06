#include "background.h"

background::background(int space,ACL_Color bgcolor,ACL_Color linecolor):
_space(space),_bgcolor(bgcolor),_linecolor(linecolor){
    int num_x=winWidth/_space;
    int num_y=winHeight/_space;
    POINT p[]={{0,0},{0,winHeight},{winWidth,winHeight},{winWidth,0}};
    beginPaint();
    clearDevice();
        setBrushColor(_bgcolor);
        setPenColor(_bgcolor);
        polygon(p,4);
        setPenColor(_linecolor);
        for(int i=0;i<num_y;i++){
            line(0,i*_space,winWidth,i*_space);
        }
        for(int i=0;i<num_x;i++){
            line(i*space,0,i*_space,winHeight);
        }
    endPaint();
}
void background::paintbg(){
    int num_x=winWidth/_space;
    int num_y=winHeight/_space;
    POINT p[]={{0,0},{0,winHeight},{winWidth,winHeight},{winWidth,0}};
    beginPaint();
        setBrushColor(_bgcolor);
        setPenColor(_bgcolor);
        polygon(p,4);
        setPenColor(_linecolor);
        for(int i=0;i<num_y;i++){
            line(0,i*_space,winWidth,i*_space);
        }
        for(int i=0;i<num_x;i++){
            line(i*_space,0,i*_space,winHeight);
        }
    endPaint();
}