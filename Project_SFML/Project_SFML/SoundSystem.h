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

private:

	void Init();

public:

	void SetVolume(const float& volume);
	void VolumeDown();
	void VolumeUp();
	void Play();
	void Pause();
	void Stop();

};

