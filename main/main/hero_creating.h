#include <SFML/Graphics.hpp>
using namespace sf;

void Player::create_hero(float time){

	/*if(currentFrame > 6 ) currentFrame -=6;

	currentFrame += speed * time;
	if(dx>0)spr.setTextureRect(IntRect(75*int(currentFrame),0,111,71));
	if(dx<0)spr.setTextureRect(IntRect(80*int(currentFrame)+80,0,-70,182));
   
	spr.setPosition(rect.left,rect.top);
	dx=0;*/


	if(position == 1) {
		Texture td;
		td.loadFromFile("pictures\\standing.png");
		spr.setTexture(td);
		spr.setPosition(rect.left,rect.top);
	}
	
	if(position == 2) {
			
			Texture ts;
			ts.loadFromFile("pictures\\standing.png");

			spr.setTexture(ts);
			
			if(currentFrame > 10 ) currentFrame -=10;

			currentFrame += speed * time;
			if(dx>0)spr.setTextureRect(IntRect(75*int(currentFrame),0,43,57));
			if(dx<0)spr.setTextureRect(IntRect(80*int(currentFrame)+80,0,-70,182));
   
			spr.setPosition(rect.left,rect.top);
			dx=0;
			position = 1;
	}


}


Player::Player(Texture &image){
			
			ground = 291;
			
			top = ground - 100;
			
			spr.setTexture(image);
			spr.setPosition(150, 250);
			
			rect=FloatRect(100,300,33,61);
			
			dx=dy=0;
			
			currentFrame=0;
			
			onGround = true;
			
			rect.top=ground;
			rect.left = 100;
			
			topReached = false;
			
			collision_y_passed = false;

			offset_x = 0;
			offset_y = 0;

			
}

void Player::info(){

	cout << " top : " << top << endl;
	cout << "top reached " << topReached << endl;
	cout << " rect left position : " << rect.left/32 << endl;
	cout << " rect top position : " << rect.top/32 << endl;
	cout << " ground : " << ground << endl;
	cout << " dx : " << dx << endl;
	cout << " dy : " << dy << endl;
	cout << " on Ground : " << onGround << endl;
	cout << endl << endl << endl << endl;
}