#include "Sound.h"
const int SnowMax = 300;

Sound::Sound(Audio init_audio) {
	audio_data = init_audio;
}

void Sound::audioPlay()
{

	//�f�t�H���g�ł�1.0
	double volume = 1.0;

	double speed = 1.0;

	audio_data.setLoop(true);

	if (audio_data.isLoop() == true) {

		std::vector<SnowParticle> snow_data;
		for (int count = 0; count < SnowMax; count++) {
			SnowParticle data;
			snow_data.push_back(data);
		}

		while (System::Update())
		{	

			//play�{�^���̒ǉ�
			if (SimpleGUI::Button(U"Play", Vec2(20, 200), 100)) {
				audio_data.play();
			}

			//pause�{�^���̒ǉ�
			if (SimpleGUI::Button(U"Pause", Vec2(120, 200), 100)) {
				audio_data.pause();
			}

			//stop�{�^���̒ǉ�
			if (SimpleGUI::Button(U"Stop", Vec2(220, 200), 100)) {
				audio_data.stop();

			}

			//���ʂ̃{�����[����ς���
			if (SimpleGUI::Slider(volume, Vec2(330, 200))) {
				audio_data.setVolume(volume);
			}

			//�Đ��X�s�[�h��ς���
			if (SimpleGUI::Slider(U"{:.2f}"_fmt(speed), speed, 0.1, 2.0, Vec2(460, 200))) {
				audio_data.setSpeed(speed);
			}

			//�Đ��ʒu�̕ύX  .setPosSample() or .setPosSec()
			//�Đ��ʒu�̕ύX 0�ɐݒ�
			if (SimpleGUI::Button(U"�Đ��ʒu���O�ɕύX", Vec2(20, 300))) {
				audio_data.setPosSample(0);
			}

			

			for (auto count : step(SnowMax)) {
				snow_data[count].snow_render(abs(sin(audio_data.posSec())), abs(cos(audio_data.posSec())), volume, 1.0);
				snow_data[count].snow_step();
			}
			
		}
		

	}
}
