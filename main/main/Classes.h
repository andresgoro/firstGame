#include <SFML/Graphics.hpp>

using namespace sf;


class Player{
	
public:
		float dx,dy;
		float currentFrame;
		int top;
		int ground;
		float offset_x;
		float offset_y;
		
		FloatRect rect;
		Sprite spr;
		
		bool topReached;
		bool onGround;
		bool collision_y_passed;
		int position;
		int destination;
		
		Player(Texture & txt);
		void update(float time);	
		void create_hero(float time);
		void Collision_x();
		void Collision_y();
		void info();
};


