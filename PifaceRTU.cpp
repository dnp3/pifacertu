
#include <opendnp3/LogToStdio.h>
#include <opendnp3/DNP3Manager.h>
#include <opendnp3/SlaveStackConfig.h>
#include <opendnp3/IChannel.h>
#include <opendnp3/IOutstation.h>
#include <opendnp3/ICommandHandler.h>

extern "C" {
#include <libpiface-1.0/pfio.h>
}

#include <thread>
#include <chrono>
#include <iostream>

using namespace std;
using namespace opendnp3;

class PifaceCommandHandler : public ICommandHandler {
private:

	void Operate(const ControlRelayOutputBlock& arCommand, size_t aIndex)
	{
		char value = 0;
		if(arCommand.GetCode() == CC_LATCH_ON) value = 1;
		pfio_digital_write(0, value);
	}

public:
		

	CommandStatus Select(const ControlRelayOutputBlock& arCommand, size_t aIndex)
	{
		if(aIndex < 4) return CS_SUCCESS;
		else return CS_NOT_SUPPORTED;
	}
	
	CommandStatus Operate(const ControlRelayOutputBlock& arCommand, size_t aIndex)
	{
		if(aIndex < 4) {
			Operate(arCommand, aIndex);
			return CS_SUCCESS;
		}
		else return CS_NOT_SUPPORTED;
	}
	
	CommandStatus DirectOperate(const ControlRelayOutputBlock& arCommand, size_t aIndex)
	{
		if(aIndex < 4) {
			
			return CS_SUCCESS;
		}
		else return CS_NOT_SUPPORTED;
	}

	CommandStatus Select(const AnalogOutputInt16& arCommand, size_t aIndex) { return CS_NOT_SUPPORTED; }
	CommandStatus Operate(const AnalogOutputInt16& arCommand, size_t aIndex) { return CS_NOT_SUPPORTED; }
	CommandStatus DirectOperate(const AnalogOutputInt16& arCommand, size_t aIndex) { return CS_NOT_SUPPORTED; }
	CommandStatus Select(const AnalogOutputInt32& arCommand, size_t aIndex) { return CS_NOT_SUPPORTED; }
	CommandStatus Operate(const AnalogOutputInt32& arCommand, size_t aIndex)  { return CS_NOT_SUPPORTED; }
	CommandStatus DirectOperate(const AnalogOutputInt32& arCommand, size_t aIndex)  { return CS_NOT_SUPPORTED; }
	CommandStatus Select(const AnalogOutputFloat32& arCommand, size_t aIndex) { return CS_NOT_SUPPORTED; }
	CommandStatus Operate(const AnalogOutputFloat32& arCommand, size_t aIndex) { return CS_NOT_SUPPORTED; }
	CommandStatus DirectOperate(const AnalogOutputFloat32& arCommand, size_t aIndex)  { return CS_NOT_SUPPORTED; }
	CommandStatus Select(const AnalogOutputDouble64& arCommand, size_t aIndex) { return CS_NOT_SUPPORTED; }
	CommandStatus Operate(const AnalogOutputDouble64& arCommand, size_t aIndex) { return CS_NOT_SUPPORTED; }
	CommandStatus DirectOperate(const AnalogOutputDouble64& arCommand, size_t aIndex) { return CS_NOT_SUPPORTED; }

};


int main(int argc, char* argv[])
{
	if(pfio_init() < 0) {
		std::cerr << "Could not initialize piface" << std::endl;
		exit(-1);
	}

	const FilterLevel LOG_LEVEL = LEV_EVENT;
	PifaceCommandHandler cmdHandler;
	DNP3Manager mgr(1);
	auto pServer = mgr.AddTCPServer("tcpserver", LOG_LEVEL, 5000, "0.0.0.0", 20000);

	SlaveStackConfig stackConfig;
	DeviceTemplate device(4, 0, 0, 0, 0);
	stackConfig.device = device;
	
	auto pOutstation = pServer->AddOutstation("outstation", LOG_LEVEL, &cmdHandler, stackConfig);
	auto pDataObserver = pOutstation->GetDataObserver();

	do {
		this_thread::sleep_for( chrono::milliseconds(100) );
	}
	while(true);

	pfio_deinit();

	return 0;
}
