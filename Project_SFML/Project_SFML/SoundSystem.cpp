#include "framework.h"
#include "SoundSystem.h"

SoundSystem::SoundSystem()
{
	Init();
}

SoundSystem::SoundSystem(const char* soundPath, bool loop)
{
	this->soundPath = soundPath;
	this->loop = loop;
	Init();
}

SoundSystem::~SoundSystem()
{
	SAFE_DELETE(sound);
	SAFE_DELETE(soundBuffer);
}

void SoundSystem::Init()
{
	soundBuffer = new SoundBuffer();
	sound = new Sound;
	if (!soundBuffer->loadFromFile(soundPath))
	{
		cout << "not loaded sound\n";
	}
	sound->setBuffer(*soundBuffer);
	sound->play();
	sound->setVolume(20);
	sound->setLoop(loop);
}

void SoundSystem::SetVolume(const float& volume)
{
	sound->setVolume(volume);
}

void SoundSystem::VolumeDown()
{
	if (sound->getVolume() >= 5.f)
	{
		sound->setVolume(sound->getVolume() - soundDistance);
	}
}

void SoundSystem::VolumeUp()
{
	if (sound->getVolume() <= 100.f)
	{
		sound->setVolume(sound->getVolume() + soundDistance);
	}
}

void SoundSystem::Play()
{
	sound->play();
}

void SoundSystem::Pause()
{
	sound->pause();
}

void SoundSystem::Stop()
{
	sound->stop();
}
