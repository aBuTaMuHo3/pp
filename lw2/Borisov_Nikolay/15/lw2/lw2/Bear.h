#pragma once
class Bear
{
public:
	Bear(BeeHive & hive);
	void Awake();
	static DWORD WINAPI Loop(LPVOID data);
	~Bear();
private:
	BeeHive & m_hive;
};

