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
	
	for (auto& i : effectSound)
	{
		SAFE_DELETE(i.second);
	}
	effectSound.clear();

	for (auto& i : effectSoundBuffer)
	{
		SAFE_DELETE(i.second);
	}
	effectSoundBuffer.clear();
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
	sound->setVolume(20);
	sound->setLoop(loop);

	//TODO :¹è°æÀ½¾Ç play
	//sound->play();
}

void SoundSystem::AddEffectSound(const char* soundPath, const string& soundName)
{
	effectSound[soundName] = new Sound();
	effectSoundBuffer[soundName] = new SoundBuffer;

	if (!effectSoundBuffer[soundName]->loadFromFile(soundPath))
	{
		cout << soundName << " is not loaded\n";
	}

	effectSound[soundName]->setBuffer(*effectSoundBuffer[soundName]);
	effectSound[soundName]->setVolume(5.f);
	effectSound[soundName]->setLoop(false);
}

void SoundSystem::SetVolume(const float& volume)
{
	sound->setVolume(volume);
}

void SoundSystem::VolumeDown()
{
	if (sound->getVolume() > 5.f)
	{
		sound->setVolume(sound->getVolume() - soundDistance);
	}
}

void SoundSystem::VolumeUp()
{
	if (sound->getVolume() < 100.f)
	{
		sound->setVolume(sound->getVolume() + soundDistance);
	}
}

void SoundSystem::Play()
{
	sound->play();
}

void SoundSystem::EffectPlay(const string& soundName)
{
	effectSound[soundName]->play();
}

void SoundSystem::Pause()
{
	sound->pause();
}

void SoundSystem::Stop()
{
	sound->stop();
}
