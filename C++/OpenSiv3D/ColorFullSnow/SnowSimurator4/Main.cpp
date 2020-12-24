//#include "SnowParticle.h"
#include "Sound.h"
#include <vector>
void Main()
{
	Window::Resize(Size(1920, 1080));
	Scene::SetBackground(ColorF(0.0, 0.0, 0.0));
	
	// サウンドファイルの読み込み wav
	const Audio audio_wav(U"beat.wav");

	//サウンドファイルの読み込み wmp3
	const Audio audio_mp3(U"sound.mp3");


	Sound play(audio_wav);
	play.audioPlay();

}

