#include "Simple_window.h"
#include "Graph.h"

/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

int main()
{
	using namespace Graph_lib;

	Point tl{100,100};

	Simple_window win{tl,600,400, "My"};

	Point origo {300, 200};

	Axis x {Axis::x, Point{80,350}, 300, 10, "x"};
	Axis y {Axis::y, Point{80,350}, 300, 10, "y"};

	y.set_color(Color::cyan);
	y.label.set_color(Color::dark_red);

	win.set_label("My 2.0");

	Function sine{sin,0,10,Point{80,150},100,50,50};
	win.set_label("My 3.0");

	sine.set_color(Color::yellow);

	win.set_label("My 4.0");

	Polygon poly;
	poly.add(Point{200,100});
	poly.add(Point{250,50});
	poly.add(Point{300,100});

	poly.set_color(Color::blue);
	poly.set_style(Line_style::dash);


	Rectangle teglalap{Point{400,250},100,60};

	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	poly_rect.add(Point{50,75});

	teglalap.set_fill_color(Color::red);
	poly_rect.set_style(Line_style(Line_style::dash,2));
	poly.set_style(Line_style(Line_style::dash,4));
	poly.set_fill_color(Color::green);
	poly_rect.set_fill_color(Color::yellow);

	win.set_label("My 5.0");

	Text szoveg{Point{150,250},"Hello,graphical world!"};

	szoveg.set_font(Font::times_bold);
	szoveg.set_font_size(15);


	Image kep{Point{100,50},"kep.jpg"};

	//kep.move(100,150);

	Circle kor{Point{100,200},60};
	Ellipse e {Point{100,200},75,25};
	e.set_color(Color::dark_red);
	Mark m{Point{100,200},'x'};

	ostringstream oss;

	oss<<"sreen size: "<<x_max()<<"*"<<y_max()<<"*window size: "<<win.x_max()<<"*"<<win.y_max();	

	Text sizes{Point{90,40},oss.str()};

	Image cal(Point{220,220},"matrix.gif");
	cal.set_mask(Point{40,40},200,150);

	win.attach(kep);
	win.attach(sizes);
	win.attach(cal);
	win.attach(kor);
	win.attach(e);
	win.attach(m);
	win.attach(szoveg);
	win.attach(poly_rect);
	win.attach(teglalap);
	win.attach(poly);
	win.attach(sine);
	win.attach(x);
	win.attach(y);



	win.wait_for_button();
}