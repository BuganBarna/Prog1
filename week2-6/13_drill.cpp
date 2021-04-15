#include "Graph.h"
#include "Simple_window.h"

/* g++ 13_drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o 13_drill `fltk-config --ldflags --use-images` */

int main()
{
	int width=800;
	int height=1000;

	const Point kezdo_p {100,100};

	Simple_window win(kezdo_p,width,height,"13.drill");

	int x_size=win.x_max();
	int y_size=win.y_max();

	int x_grid=100;
	int y_grid=100;

	Lines grid;
		for(int x=x_grid; x<x_size; x+=x_grid)
				grid.add(Point{x,0}, Point{x,800});

		for(int y=y_grid; y<900; y+=y_grid)
				grid.add(Point{0,y}, Point{x_size,y});	

	Vector_ref<Rectangle> rect;		

	for(int i=0; i<8; ++i)
		{
			rect.push_back(new Rectangle{Point{i*100,i*100},100,100});
			rect[i].set_fill_color(Color::red);
			win.attach(rect[i]);
		}		



	Image im1{Point{0,400},"kep.jpg"};
	im1.set_mask(Point{0,0}, 200,200);

	Image im2{Point{600,300},"kep.jpg"};
	im2.set_mask(Point{0,0}, 200,200);

	Image im3{Point{0,600},"kep.jpg"};
	im3.set_mask(Point{0,0}, 200,200);

	win.attach(im1);
	win.attach(im2);
	win.attach(im3);

	Image mozg_im{Point{0,0},"kep.jpg"};
	mozg_im.set_mask(Point{100,100}, 100,100);

	win.attach(mozg_im);

	win.attach(grid);

	int a=0;
	int seged_valtozo=0;
	while(true)
	{
		++a;

		win.wait_for_button();

		if(a<8)
			{
				mozg_im.move(100,0);
				
			}
		else 
			{
				mozg_im.move(-700,100);
				seged_valtozo+=a;
				if(seged_valtozo==64) break;
				a=0;
			}
	}


}