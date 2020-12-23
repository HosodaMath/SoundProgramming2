#pragma once
#include <Siv3D.hpp>
class AudioPlay
{

private:
	Audio audio_data;

public:
	AudioPlay(Audio init_audio);
	void one_play();
	void audio_play1();
	void audio_play2();
	void audio_play3();
	void audio_play4();
	void audio_play5();
	//簡単なビジュアライザー(背景色の変更)
	void audio_play6();
};

