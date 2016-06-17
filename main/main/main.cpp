#include <SFML/Graphics.hpp>
#define speed 0.05
#include "Classes.h"
#include "System_logic.h"
#include "map_creating.h"
#include <iostream>
#include "hero_creating.h"
using namespace sf;
using namespace std;








int main()
{
sf::RenderWindow window(sf::VideoMode(800, 400), "Argonis");

Texture t;
t.loadFromFile("pictures\\standing.png");
Player p1(t);

while (window.isOpen())												// checking game window (opened closed etc.)
{

sf::Event event;

while (window.pollEvent(event))
{

if (event.type == sf::Event::Closed)

window.close();
}


Clock clock;													// used to connect game with time , not with proc.
	float time;
	time=clock.getElapsedTime().asMicroseconds();
	clock.restart();
	time=time/20;


	
if(Keyboard::isKeyPressed(Keyboard::Right))						// right movement
{
	p1.dx+=4;
	p1.position = 1;
	p1.offset_x ++ ;
		
}
if(Keyboard::isKeyPressed(Keyboard::Left))						// LEFT movement
{
	p1.dx=-4;
	p1.position = 1;
	p1.offset_x -- ;
}

if(Keyboard::isKeyPressed(Keyboard::Up))						 // UP movement
{   
	if(p1.onGround){
	p1.dy = 50;
	p1.position = 1;
	p1.onGround = false;
	}
}
if(Keyboard::isKeyPressed(Keyboard::P)){
	p1.info();
}
p1.update(time);	
/*if(Keyboard::isKeyPressed(Keyboard::Down))
{																	// DOWN movement
	p1.dy--;
}*/
														      
window.clear(Color::White);

RenderWindow * pnt = &window;
map_cr(pnt, p1);
window.draw(p1.spr);
window.display();

}
return 0;
}
