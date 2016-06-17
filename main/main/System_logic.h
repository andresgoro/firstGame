#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;
extern String map_mass[];
int popo = 0;								// test popo lol( for cathing da faking irors)


void Player::Collision_x(){
      
	for(int i = rect.top/32  ; i < (rect.top + rect.height )/32 -1  ; i++)						 // checking left side 
		for(int j = rect.left/32; j < rect.left/32; j++){
			if(map_mass[i][j] == 'B'){
				if(dx < 0 && dy == 0 )  {rect.left = j*32 + rect.width; cout << "left" << popo << popo++ << endl;}
				}
			
		}
	
	for(int i = rect.top/32 ; i < (rect.top + rect.height) /32 -1 ; i++)						// checking right side 
		for(int j = (rect.left + rect.width )/32; j < (rect.left + rect.width )/32; j++){
			if(map_mass[i][j] == 'B'){
				if(dx > 0 && dy == 0)  {rect.left = j*32 - rect.width; topReached = true; cout << "right jumping" << popo << popo++ << endl;}
			}
		}

}

void Player::Collision_y(){
    if(dy > 0){
	for(int i = rect.top/32; i <= rect.top/32 ; i++ )										// checking top collision
		for (int j = rect.left /32 ; j <= ( rect.left + rect.width ) / 32; j ++)
			if(map_mass[i][j] == 'B'){
				topReached = true;
				cout << "LOLADAK" <<endl;
			}
	}
		for(int i = (rect.top + rect.height)/32; i <(rect.top + rect.height)/32; i++){		//checking bottom collision
			collision_y_passed = false;
			for(int j = (rect.left+(rect.width/2)) /32; j <(rect.left+(rect.width/2)) /32; j++)
				if(map_mass[i][j] == 'B'){
					cout << "ground reaced " << popo << popo ++ << endl;
					ground = i * 32 - rect.height;
					collision_y_passed = true;
				}
		      
		   else if(!collision_y_passed && dy == 0 && !topReached){
			    topReached = true;
				dy = 25;
		   }
		  
		}

}

void Player::update(float time){
	
	top = ground - 100;
	
	/*rect.left += dx * time;																	//tutorial version of jumping
	if(!onGround) dy=dy-speed*time;
	rect.top -= dy * time  ;
	onGround = false;
	if(rect.top > ground){ rect.top=ground; dy=0; onGround = true;}*/
    
	
	rect.left += dx * time ;																   // My version of jumping
	 
	Collision_x();

	Collision_y();
	
	if(!topReached && dy > 0 ){
		 rect.top -= dy * time * speed ;
		 
		 if(rect.top <= top){ topReached = true;}
		 }
	
	if( topReached ){
		rect.top += dy * time * speed;
		if(!collision_y_passed) ground = 291;
		if(rect.top >= ground){
		  onGround = true;
		  dy=0;
		  topReached = false;

		}
	}
	
	
	
		if( position == 1 ) {
			spr.setPosition( rect.left , rect.top );
		dx = 0;
	}
	
	   /* if(position == 2) {
			
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
		*/
}

