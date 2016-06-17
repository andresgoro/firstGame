

#include <SFML/Graphics.hpp>


using namespace sf;

const int map_height = 15;
const int map_weidth = 33;

extern String map_mass[map_height] = {
"                                                               ",
"                                                               ",
"                                                               ",
"                                                               ",
"                                                               ",
"                                                               ",
"B                                                               ",
"B    BBBBB                              BBBB                         ",
"B                             BBBB                              ",
"B                BBBB                                           ",
"B            BBBB                                              ",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"                                                               ",
"                                                               ",
"                                                               ",
};


void map_cr(RenderWindow * window , Player  p1 ){
	
	
	RectangleShape map_rectangle;
	Vector2f vec(32,32);
	map_rectangle.setSize(vec);
	
	
	
	for(int i = 0; i < map_height; i++)
		for(int f = 0; f < map_weidth  ; f++){
		     
			if(map_mass[i][f] == 'B') map_rectangle.setFillColor(Color::Black);
			
			if(map_mass[i][f] == '0') map_rectangle.setFillColor(Color::Blue);
			
			if(map_mass[i][f] == ' ') map_rectangle.setFillColor(Color::White);

			if(map_mass[i][f] == 'L') map_rectangle.setFillColor(Color::Blue);

			if(map_mass[i][f] == 'R') map_rectangle.setFillColor(Color::Red);

			map_rectangle.setPosition( 32*f , 32*i );

			window->draw(map_rectangle);
		}
     
}

