#pragma once
class BeeHive
{
public:
	BeeHive();
	size_t CountBeesInHive();
	void AddHoney();
	bool EmptyHive();
	~BeeHive();
private:
	size_t m_honeyCapacity;
	size_t m_currentHoney;
	size_t m_beesInHive;
};

