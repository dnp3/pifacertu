
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


PifaceIOHandler::PifaceIOHandler()
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
