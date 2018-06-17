#pragma once
class Event
{
public:
	Event(bool status);
	~Event();

	void Start();
	void End();
	void Wait();
private:
	HANDLE m_event;
};

