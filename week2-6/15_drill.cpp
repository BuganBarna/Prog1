#include "Graph.h"
#include "Simple_window.h"

/* g++ 15_drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` */

double one(double x) {return 1;}
double slope(double x) {return x/2;}
double square(double x) {return x*x;}
double sloping_cos(double x) {return cos(x)+slope(x);}


int main()
{
	const int width=600;
	const int height=600;

	const int x_origo=width/2;
	const int y_origo=height/2;
	const int x_scale=20;
	const int y_scale=20;

	const Point origo(x_origo,y_origo);

	const int range_min=-10;
	const int range_max=11;

	Simple_window win{Point{100,100},width,height,"Function graphs"};

	Axis x(Axis::x,Point{300,300},400,400/20,"1==20 pixels");
	Axis y(Axis::y,Point{300,300},400,400/20,"1==20 pixels");

	x.set_color(Color::red);
	y.set_color(Color::red);

	win.attach(x);
	win.attach(y);

	Function func_one(one,range_min,range_max,origo,400,x_scale,y_scale);
	win.attach(func_one);

	Function func_slope(slope,range_min,range_max,origo,400,x_scale,y_scale);
	win.attach(func_slope);

	Function func_sloping_cos(sloping_cos,range_min,range_max,origo,400,x_scale,y_scale);
	win.attach(func_sloping_cos);

	Function func_square(square,range_min,range_max,origo,400,x_scale,y_scale);
	win.attach(func_square);

	Function func_cos(cos,range_min,range_max,origo,400,x_scale,y_scale);
	func_cos.set_color(Color::blue);
	win.attach(func_cos);

	Text p(Point{100,390},"x/2");
	win.attach(p);


	win.wait_for_button();
}