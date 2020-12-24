#include "SnowParticle.h"

SnowParticle::SnowParticle()
{
	snow_location = Vec2(Random(0, 1920), 0);
	snow_velocity = Vec2(Random(), Random(1, 12));
	radius = Random(2, 5);
}

void SnowParticle::snow_render(double r, double g, double b, double alpha)
{
	auto color = ColorF(r, g, b, alpha);
	Circle(snow_location.x, snow_location.y, radius).draw(color);
}

void SnowParticle::snow_step()
{
	snow_location += snow_velocity;

	if (snow_location.y > 1080) {
		snow_location.y = 0;
	}
}
