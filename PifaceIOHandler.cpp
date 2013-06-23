#include "PifaceIOHandler.h"

extern "C" {
#include <libpiface-1.0/pfio.h>
}

#include <opendnp3/TimeTransaction.h>

#include <iostream>
#include <chrono>

using namespace opendnp3;

void PifaceIOHandler::DoOperate(const ControlRelayOutputBlock& arCommand, char aIndex)
{
	char value = 0;
	if(arCommand.GetCode() == CC_LATCH_ON) value = 1;
	pfio_digital_write(aIndex, value);
}

CommandStatus PifaceIOHandler::ValidateCROB(const opendnp3::ControlRelayOutputBlock& arCommand, size_t aIndex)
{
	if(aIndex < 8) {
		if(arCommand.GetCode() == CC_LATCH_ON || arCommand.GetCode() == CC_LATCH_OFF) return CS_SUCCESS;
		else return CS_NOT_SUPPORTED;
	}
	else return CS_NOT_SUPPORTED;
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
		TimeTransaction tx(apObserver);
		tx.Update(Binary(isSwitchOn(data, 0), BQ_ONLINE), 0);
		tx.Update(Binary(isSwitchOn(data, 1), BQ_ONLINE), 1);
		tx.Update(Binary(isSwitchOn(data, 2), BQ_ONLINE), 2);
		tx.Update(Binary(isSwitchOn(data, 3), BQ_ONLINE), 3);
	}
}

CommandStatus PifaceIOHandler::Select(const ControlRelayOutputBlock& arCommand, size_t aIndex)
{
	return ValidateCROB(arCommand, aIndex);
}

CommandStatus PifaceIOHandler::Operate(const ControlRelayOutputBlock& arCommand, size_t aIndex)
{
	CommandStatus validation = ValidateCROB(arCommand, aIndex);
	if(validation == CS_SUCCESS) DoOperate(arCommand, static_cast<char>(aIndex));
	return validation;
}

CommandStatus PifaceIOHandler::DirectOperate(const ControlRelayOutputBlock& arCommand, size_t aIndex)
{
	CommandStatus validation = ValidateCROB(arCommand, aIndex);
	if(validation == CS_SUCCESS) DoOperate(arCommand, static_cast<char>(aIndex));
	return validation;
}
