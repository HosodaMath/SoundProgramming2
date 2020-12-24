#pragma once
# include <Siv3D.hpp> 
#include "SnowParticle.h"
class Sound
{
private:
	Audio audio_data;
public:
	Sound(Audio init_audio);
	void audioPlay();

};

