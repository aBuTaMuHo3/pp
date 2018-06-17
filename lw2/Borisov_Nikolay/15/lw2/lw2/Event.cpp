#include "stdafx.h"
#include "Event.h"


Event::Event(bool status)
{
	m_event = CreateEvent(NULL, TRUE, status, NULL);
}

Event::~Event()
{
	CloseHandle(m_event);
}

void Event::Start()
{
	SetEvent(m_event);
}

void Event::End()
{
	ResetEvent(m_event);
}

void Event::Wait()
{
	WaitForSingleObject(m_event, INFINITE);
}