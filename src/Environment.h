#pragma once

#include "Config.h"
#include "Device/DeviceController.h"
#include "FlowingFFTSpectre.h"
#include "CircleBufferWriterThread.h"
#include "SoundCard.h"
#include "SoundProcessorThread.h"
#include "ViewModel.h"
#include "CircleBufferNew.h"
#include "Buffer.h"

class Environment {
	private:

		FFTData* fftData;

		Config* config = nullptr;
		DeviceController* deviceController = nullptr;

		//����� ��� �������� I Q
		//CircleBufferNew<uint8_t>* IQBufForSoundProc = nullptr;
		//CircleBufferNew<uint8_t>* IQBufForSpectre = nullptr;

		//CircleBuffer* IQSourceBuffer2 = nullptr;
		CircleBufferNew<float>* soundBuffer = nullptr;

		SpectreHandler* specHandler = nullptr;

		SoundProcessorThread* soundProcessor = nullptr;

		CircleBufferWriterThread* circleBufferWriterThread = nullptr;

		SoundCard* soundCard = nullptr;

		ViewModel* viewModel = nullptr;

		FlowingSpectre* flowingSpec = nullptr;

		ReceiverLogic* receiverLogic = nullptr;

	public:

		std::atomic_bool reloading = false;

		Environment();
		//void initReceivers();
		~Environment();
		void cleanUp();
		Config* getConfig();
		DeviceController* getDeviceController();
		void startProcessing();
		void stopProcessing();
		void makeReload();
		void reload();
		SpectreHandler* getFFTSpectreHandler();
		SoundProcessorThread* getSoundProcessor();
		void init();
		SoundCard* getSoundCard();
		ViewModel* getViewModel();
		ReceiverLogic* getReceiverLogic();
		FlowingSpectre* getFlowingSpectre();
};