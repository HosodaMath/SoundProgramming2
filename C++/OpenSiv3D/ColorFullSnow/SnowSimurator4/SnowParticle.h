#pragma once
# include <Siv3D.hpp> 
class SnowParticle
{
private:
	Vec2 snow_location;
	Vec2 snow_velocity;
	double radius;
public:
	SnowParticle();
	void snow_render(double r, double g, double b, double alpha);
	void snow_step();

};

