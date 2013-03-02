
#include "PifaceIOHandler.h"

extern "C" {
#include <libpiface-1.0/pfio.h>
}

#include <iostream>

using namespace opendnp3;

void PifaceIOHandler::DoOperate(const ControlRelayOutputBlock& arCommand, size_t aIndex)
{
	char value = 0;
	if(arCommand.GetCode() == CC_LATCH_ON) value = 1;
	pfio_digital_write(0, value);
}

bool PifaceIOHandler::isSwitchOn(int data, int num)
{
	int mask = 1 << num; // 255 is all off, switch 0 is lowest bit
	bool ret = ((data & mask) == 0);
	return ret;
}


PifaceIOHandler::PifaceIOHandler() : lastData(0)
{
	int result = pfio_init();
	if(result < 0)
	{
		std::cerr << "Unable to initialize piface" << std::endl;
		exit(result);
	}
}

PifaceIOHandler::~PifaceIOHandler()
{
	pfio_deinit();
}

void PifaceIOHandler::ReadMeasurements(IDataObserver* apObserver)
{
	int data = pfio_read_input();
	if(lastData != data)
	{
		lastData = data;
		Transaction t(apObserver);
		apObserver->Update(Binary(isSwitchOn(data, 0)), 0);
		apObserver->Update(Binary(isSwitchOn(data, 1)), 1);
		apObserver->Update(Binary(isSwitchOn(data, 2)), 2);
		apObserver->Update(Binary(isSwitchOn(data, 3)), 3);
	}
}

CommandStatus PifaceIOHandler::Select(const ControlRelayOutputBlock& arCommand, size_t aIndex)
{
	if(aIndex < 4) return CS_SUCCESS;
	else return CS_NOT_SUPPORTED;
}

CommandStatus PifaceIOHandler::Operate(const ControlRelayOutputBlock& arCommand, size_t aIndex)
{
	if(aIndex < 4) {
		Operate(arCommand, aIndex);
		return CS_SUCCESS;
	}
	else return CS_NOT_SUPPORTED;
}

CommandStatus PifaceIOHandler::DirectOperate(const ControlRelayOutputBlock& arCommand, size_t aIndex)
{
	if(aIndex < 4) {
		return CS_SUCCESS;
	}
	else return CS_NOT_SUPPORTED;
}
