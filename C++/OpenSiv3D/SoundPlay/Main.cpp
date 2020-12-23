#include "AudioPlay.h"

void Main() {

	Window::Resize(Size(1920, 1080));

	//サウンドファイルの読み込み wav
	const Audio audio_wav(U"beat.wav");
	
	//サウンドファイルの読み込み wmp3
	const Audio audio_mp3(U"sound.mp3");
	

	AudioPlay play(audio_wav);
	play.audio_play6();

}