/*
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp drill15_GUI.cpp `fltk-config --ldflags --use-images` -o a2.out
*/

#include "./../GUI/Graph.h"
#include "./../GUI/Simple_window.h"

#include <iostream>
#include <string>
#include <stdlib.h>

double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

using namespace Graph_lib;

int main(){

    const int xmax = 600;
    const int ymax = 600;

    Point t1(0,0);
    Simple_window win(t1,xmax, ymax, "Function Graphs");

    win.set_label("1 = = 20 pixels");

    Axis xa {Axis::x, Point {100,300}, 400, 20, "x axis"};
    xa.set_color(Color::red);
    win.attach(xa);

    Axis ya {Axis::y, Point {300, 450}, 400, 20, "y axis"};
    ya.set_color(Color::red);
    win.attach(ya);

    const int r_min = -10;
    const int r_max = 11;

    const int num_points = 400;

    const int x_scale = 20;
    const int y_scale = 20;

    const int x_orig = xmax/2;
    const int y_orig = ymax/2;
    const Point orig(x_orig,y_orig);

    Function f1 {one, r_min, r_max, orig, num_points, x_scale, y_scale};
    Function f2 {slope, r_min, r_max,orig, num_points,x_scale,y_scale};
    Function f3 {square, r_min, r_max, orig, num_points, x_scale, y_scale};
    Function f4(cos,r_min,r_max,orig,num_points,x_scale,y_scale);
    Function f5(sloping_cos,r_min,r_max,orig,num_points,x_scale,y_scale);

    f4.set_color(Color::blue);

    win.attach(f1);
    win.attach(f2);
    win.attach(f3);
    win.attach(f4);
    win.attach(f5);

    Text ts2(Point(100,y_orig+4*y_scale),"x/2");
    win.attach(ts2);

    win.wait_for_button();
    return 0;
}