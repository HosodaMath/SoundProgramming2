#include "AudioPlay.h"

AudioPlay::AudioPlay(Audio init_audio)
{
	audio_data = init_audio;
}

//これは1回きりの再生
void AudioPlay::one_play()
{

	//オーディオ再生(このままだとループ再生しない)
	audio_data.play();

	while (System::Update()) {

	}


}

//1時停止と巻き戻しの機能を追加
void AudioPlay::audio_play1()
{
	while (System::Update()) {
		
		//playボタンの追加
		if (SimpleGUI::Button(U"Play", Vec2(20, 20), 100)) {
			audio_data.play();
		}

		//pauseボタンの追加
		if (SimpleGUI::Button(U"Pause", Vec2(120, 20), 100)) {
			audio_data.pause();
		}

		//stopボタンの追加
		if (SimpleGUI::Button(U"Stop", Vec2(220, 20), 100)) {
			audio_data.stop();
		
		}
	}
}

//音量設定の追加
void AudioPlay::audio_play2()
{	
	//デフォルトでは1.0
	double volume = 1.0;

	while (System::Update()) {

		//playボタンの追加
		if (SimpleGUI::Button(U"Play", Vec2(20, 20), 100)) {
			audio_data.play();
		}

		//pauseボタンの追加
		if (SimpleGUI::Button(U"Pause", Vec2(120, 20), 100)) {
			audio_data.pause();
		}

		//stopボタンの追加
		if (SimpleGUI::Button(U"Stop", Vec2(220, 20), 100)) {
			audio_data.stop();

		}

		//音量のボリュームを変える
		if (SimpleGUI::Slider(volume, Vec2(320, 20))) {
			audio_data.setVolume(volume);
		}
	}

}

//再生スピードを変える
void AudioPlay::audio_play3()
{
	//デフォルトでは1.0
	double volume = 1.0;

	double speed = 1.0;

	while (System::Update()) {

		//playボタンの追加
		if (SimpleGUI::Button(U"Play", Vec2(20, 20), 100)) {
			audio_data.play();
		}

		//pauseボタンの追加
		if (SimpleGUI::Button(U"Pause", Vec2(120, 20), 100)) {
			audio_data.pause();
		}

		//stopボタンの追加
		if (SimpleGUI::Button(U"Stop", Vec2(220, 20), 100)) {
			audio_data.stop();

		}

		//音量のボリュームを変える
		if (SimpleGUI::Slider(volume, Vec2(330, 20))) {
			audio_data.setVolume(volume);
		}

		//再生スピードを変える
		if (SimpleGUI::Slider(U"{:.2f}"_fmt(speed), speed, 0.1, 2.0, Vec2(460, 20))) {
			audio_data.setSpeed(speed);
		}
	}
}

//再生位置の取得
void AudioPlay::audio_play4()
{

	//デフォルトでは1.0
	double volume = 1.0;

	double speed = 1.0;

	while (System::Update()) {

		//playボタンの追加
		if (SimpleGUI::Button(U"Play", Vec2(20, 200), 100)) {
			audio_data.play();
		}

		//pauseボタンの追加
		if (SimpleGUI::Button(U"Pause", Vec2(120, 200), 100)) {
			audio_data.pause();
		}

		//stopボタンの追加
		if (SimpleGUI::Button(U"Stop", Vec2(220, 200), 100)) {
			audio_data.stop();

		}

		//音量のボリュームを変える
		if (SimpleGUI::Slider(volume, Vec2(330, 200))) {
			audio_data.setVolume(volume);
		}

		//再生スピードを変える
		if (SimpleGUI::Slider(U"{:.2f}"_fmt(speed), speed, 0.1, 2.0, Vec2(460, 200))) {
			audio_data.setSpeed(speed);
		}

		ClearPrint();

		//オーディオの合計再生時間(秒).lengthSec() 合計再生サンプル .samples()
		Print << U"曲全体の長さ: オーディオの合計再生時間は{:.1f}sec 合計再生サンプル数は{} samples"_fmt(audio_data.lengthSec(), audio_data.samples());


		//現在の再生位置(秒).popSec 現在の再生位置(サンプル数).popSample
		Print << U"現在の曲の長さ: 現在のオーディオ再生位置は{:.1f}sec 現在の再生位置は{} samples"_fmt(audio_data.posSec(), audio_data.posSample());
	
		//バッファ送信済みサンプル位置.streamPosSample()
		Print << U"現在のバッファ送信済み位置 stream: {} samples"_fmt(audio_data.streamPosSample());
	}
}

//再生位置の変更 and loop
void AudioPlay::audio_play5()
{
	//デフォルトでは1.0
	double volume = 1.0;

	double speed = 1.0;

	audio_data.setLoop(true);

	if(audio_data.isLoop() == true){

		while (System::Update()) {

			//playボタンの追加
			if (SimpleGUI::Button(U"Play", Vec2(20, 200), 100)) {
				audio_data.play();
			}

			//pauseボタンの追加
			if (SimpleGUI::Button(U"Pause", Vec2(120, 200), 100)) {
				audio_data.pause();
			}

			//stopボタンの追加
			if (SimpleGUI::Button(U"Stop", Vec2(220, 200), 100)) {
				audio_data.stop();

			}

			//音量のボリュームを変える
			if (SimpleGUI::Slider(volume, Vec2(330, 200))) {
				audio_data.setVolume(volume);
			}

			//再生スピードを変える
			if (SimpleGUI::Slider(U"{:.2f}"_fmt(speed), speed, 0.1, 2.0, Vec2(460, 200))) {
				audio_data.setSpeed(speed);
			}

			//再生位置の変更  .setPosSample() or .setPosSec()
			//再生位置の変更 0に設定
			if (SimpleGUI::Button(U"再生位置を０に変更", Vec2(20, 300))) {
				audio_data.setPosSample(0);
			}



			ClearPrint();

			//オーディオの合計再生時間(秒).lengthSec() 合計再生サンプル .samples()
			Print << U"曲全体の長さ: オーディオの合計再生時間は{:.1f}sec 合計再生サンプル数は{} samples"_fmt(audio_data.lengthSec(), audio_data.samples());


			//現在の再生位置(秒).popSec 現在の再生位置(サンプル数).popSample
			Print << U"現在の曲の長さ: 現在のオーディオ再生位置は{:.1f}sec 現在の再生位置は{} samples"_fmt(audio_data.posSec(), audio_data.posSample());

			//バッファ送信済みサンプル位置.streamPosSample()
			Print << U"現在のバッファ送信済み位置 stream: {} samples"_fmt(audio_data.streamPosSample());
		}
	}
}

//簡単なビジュアライザー
void AudioPlay::audio_play6()
{

	//デフォルトでは1.0
	double volume = 1.0;

	double speed = 1.0;

	audio_data.setLoop(true);

	if (audio_data.isLoop() == true) {

		while (System::Update()) {

			//playボタンの追加
			if (SimpleGUI::Button(U"Play", Vec2(20, 200), 100)) {
				audio_data.play();
			}

			//pauseボタンの追加
			if (SimpleGUI::Button(U"Pause", Vec2(120, 200), 100)) {
				audio_data.pause();
			}

			//stopボタンの追加
			if (SimpleGUI::Button(U"Stop", Vec2(220, 200), 100)) {
				audio_data.stop();

			}

			//音量のボリュームを変える
			if (SimpleGUI::Slider(volume, Vec2(330, 200))) {
				audio_data.setVolume(volume);
			}

			//再生スピードを変える
			if (SimpleGUI::Slider(U"{:.2f}"_fmt(speed), speed, 0.1, 2.0, Vec2(460, 200))) {
				audio_data.setSpeed(speed);
			}

			//再生位置の変更  .setPosSample() or .setPosSec()
			//再生位置の変更 0に設定
			if (SimpleGUI::Button(U"再生位置を０に変更", Vec2(20, 300))) {
				audio_data.setPosSample(0);
			}

			Scene::SetBackground(ColorF(abs(sin(audio_data.posSec())), abs(cos(audio_data.posSec())), 0.5));


			ClearPrint();

			//オーディオの合計再生時間(秒).lengthSec() 合計再生サンプル .samples()
			Print << U"曲全体の長さ: オーディオの合計再生時間は{:.1f}sec 合計再生サンプル数は{} samples"_fmt(audio_data.lengthSec(), audio_data.samples());


			//現在の再生位置(秒).popSec 現在の再生位置(サンプル数).popSample
			Print << U"現在の曲の長さ: 現在のオーディオ再生位置は{:.1f}sec 現在の再生位置は{} samples"_fmt(audio_data.posSec(), audio_data.posSample());

			//バッファ送信済みサンプル位置.streamPosSample()
			Print << U"現在のバッファ送信済み位置 stream: {} samples"_fmt(audio_data.streamPosSample());
		}
	}
}


