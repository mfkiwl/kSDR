#include "ViewModel.h"

ViewModel::ViewModel(Config* config) {
	this->config = config;
	centerFrequency = config->startFrequency;
	filterWidth = config->defaultFilterWidth;
	volume = config->volume;


	//from xml
	waterfallMin = config->waterfallMin;
	waterfallMax = config->waterfallMax;
	ratio = config->spectreRatio;
	minDb = config->spectreMin;
	spectreSpeed = config->spectreSpeed;
	hackRFModel.lnaGain = config->hackrf.lnaGain;
	hackRFModel.vgaGain = config->hackrf.vgaGain;
	hackRFModel.enableAmp = config->hackrf.rxAmp;
	filterWidth = config->filterWidth;
}

ViewModel::~ViewModel() {
	config->waterfallMin = waterfallMin;
	config->waterfallMax = waterfallMax;
	config->spectreRatio = ratio;
	config->spectreMin = minDb;
	config->spectreSpeed = spectreSpeed;
	config->startFrequency = centerFrequency;
	config->volume = volume;
	config->filterWidth = filterWidth;

	config->hackrf.lnaGain = hackRFModel.lnaGain;
	config->hackrf.vgaGain = hackRFModel.vgaGain;
	config->hackrf.rxAmp = hackRFModel.enableAmp;
}

void ViewModel::setBufferAvailable(int readAvailableBufferCount) {
	bufferAvailable = (float)readAvailableBufferCount / (config->inputSamplerate / config->inputSamplerateDivider);
}