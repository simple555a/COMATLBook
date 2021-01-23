// Video.cpp - Implementation of interface IVideo

#include "Video.h"
#include "Vcr.h"

IVideo::IVideo()
{
	m_pActualVideo = new CVcr;
}

IVideo::~IVideo()
{
	delete m_pActualVideo;

}

long IVideo::GetSignalValue()
{
	return m_pActualVideo->GetSignalValue();
}

