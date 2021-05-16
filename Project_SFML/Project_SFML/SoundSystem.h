#pragma once

class SoundSystem final
{
public:
	SoundSystem();
	SoundSystem(const char* soundPath, bool loop = true);
	SoundSystem(const SoundSystem&) = delete;
	SoundSystem& operator=(const SoundSystem&) = delete;
	~SoundSystem();

private:

	string soundPath{};

	Sound* sound = nullptr;
	SoundBuffer* soundBuffer = nullptr;

	const float soundDistance = 5.f;
	float volume = 20;
	bool loop = true;

	map<string, Sound*> effectSound;
	map<string, SoundBuffer*> effectSoundBuffer;

private:

	void Init();

public:

	void AddEffectSound(const char* soundPath, const string& soundName);
	void SetVolume(const float& volume);
	void VolumeDown();
	void VolumeUp();
	void Play();
	void EffectPlay(const string& soundName);
	void Pause();
	void Stop();

};

