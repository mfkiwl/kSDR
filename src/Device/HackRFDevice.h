#pragma once

#include "hackrf\hackrf.h"
#include "DeviceN.h"
#include "string"
#include "../CircleBufferNew.h"

constexpr bool DEBUG = true;

class HackRFDevice : public DeviceN {
	private:

		hackrf_device* device = NULL;

		static int rx_callback(hackrf_transfer* transfer);

		CircleBufferNew<uint8_t>* bufferForSpec;
		CircleBufferNew<uint8_t>* bufferForProc;

	public:

		void setFreq(uint64_t frequency);
		void setLnaGain(uint32_t gain);
		void setVgaGain(uint32_t gain);
		void setBaseband(int baseband);
		void enableAmp(uint8_t amp);

		HackRFDevice(Config* config) : DeviceN(config) {
			bufferForSpec = new CircleBufferNew<uint8_t>(config->circleBufferLen);
			bufferForProc = new CircleBufferNew<uint8_t>(config->circleBufferLen);
		};

		~HackRFDevice();

		void setSampleRate(int sampleRate);

		Result start();
		void stop();

		CircleBufferNew<uint8_t>* getBufferForSpec();
		CircleBufferNew<uint8_t>* getBufferForProc();

		float prepareData(uint8_t val);
};