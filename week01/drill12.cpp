#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

#include <string>
#include <iostream>
using namespace Graph_lib:

int main(){
    try{

        Point t1 {100, 100};

        Simple_window_win {t1, 640, 400, "My window"};

        win.wait_for_button(); //vár addig amíg megnyomja a gombot

        //12.7.3
        Axis xa {Axis::x, Point {20, 300}, 200, 10, "x axis"}; //egy x-et rajzolok ki

        win.attach(xa);
        win.set_label("Axis");
        win.wait_for_button();

        Axis ya {Axis::y, Point {20, 200}, 200, 10, "y axis"};
        ya.set_color(Color::cyan); //cyan színű lesz az y tengely
        win.attach(ya);
        win.set_label("y axis");
        win.wait_for_button();

        Function sine {sin, 0 , 100, Point{20, 150}, 1000, 50, 50}; //szinusz függvény kirajzolása
        win.attach(sine);
        win.set_label("Sine function");
        win.wait_for_button();

        Polygon poly; //ábrázolni fogunk, (háromszöget most?)
        poly.add(Point{300,200});
        poly.add(Point{350,100});
        poly.add(Point{400,200});

        poly.set_color{Color::red};
        poly.set_style{Line_style::dash};
        win.attach(poly);
        win.set_label("Draw polygon");
        win.wait_for_button();

        Rectangle r {Point{200, 200}, 100, 50}; //négyszöget rajzolunk
        win.attach(r);

        Closed_polyline poly_rect; //másik megoldás a négyszögre
        poly_rect.add(Point{100, 50});
        poly_rect.add(Point{200, 50});
        poly_rect.add(Point{200, 100});
        poly_rect.add(Point{50, 75});

        win.set_label("Draw rectangle");
        win.wait_for_button();

    } catch (exception& e) {
        cerr << "exception: " << e.what()<< '\n';
        return 1; 
    } catch (...) {
        cerr << "error\n";
        return 2;
    }
}