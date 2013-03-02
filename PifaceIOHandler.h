
#ifndef __PIFACE_IO_HANDLER_H_
#define __PIFACE_IO_HANDLER_H_

#include <opendnp3/ICommandHandler.h>

using namespace opendnp3;

class PifaceIOHandler : public opendnp3::ICommandHandler
{

private:

	void DoOperate(const opendnp3::ControlRelayOutputBlock& arCommand, size_t aIndex);

public:

	PifaceIOHandler();
	~PifaceIOHandler();

	void ReadMeasurements(opendnp3::IDataObserver* apObserver);

	opendnp3::CommandStatus Select(const opendnp3::ControlRelayOutputBlock& arCommand, size_t aIndex);		
	opendnp3::CommandStatus Operate(const opendnp3::ControlRelayOutputBlock& arCommand, size_t aIndex);
	opendnp3::CommandStatus DirectOperate(const opendnp3::ControlRelayOutputBlock& arCommand, size_t aIndex);

	opendnp3::CommandStatus Select(const opendnp3::AnalogOutputInt16& arCommand, size_t aIndex) { return opendnp3::CS_NOT_SUPPORTED; }
	opendnp3::CommandStatus Operate(const opendnp3::AnalogOutputInt16& arCommand, size_t aIndex) { return opendnp3::CS_NOT_SUPPORTED; }
	opendnp3::CommandStatus DirectOperate(const opendnp3::AnalogOutputInt16& arCommand, size_t aIndex) { return opendnp3::CS_NOT_SUPPORTED; }
	opendnp3::CommandStatus Select(const opendnp3::AnalogOutputInt32& arCommand, size_t aIndex) { return opendnp3::CS_NOT_SUPPORTED; }
	opendnp3::CommandStatus Operate(const opendnp3::AnalogOutputInt32& arCommand, size_t aIndex)  { return opendnp3::CS_NOT_SUPPORTED; }
	opendnp3::CommandStatus DirectOperate(const opendnp3::AnalogOutputInt32& arCommand, size_t aIndex)  { return opendnp3::CS_NOT_SUPPORTED; }
	opendnp3::CommandStatus Select(const opendnp3::AnalogOutputFloat32& arCommand, size_t aIndex) { return opendnp3::CS_NOT_SUPPORTED; }
	opendnp3::CommandStatus Operate(const opendnp3::AnalogOutputFloat32& arCommand, size_t aIndex) { return opendnp3::CS_NOT_SUPPORTED; }
	opendnp3::CommandStatus DirectOperate(const opendnp3::AnalogOutputFloat32& arCommand, size_t aIndex)  { return opendnp3::CS_NOT_SUPPORTED; }
	opendnp3::CommandStatus Select(const opendnp3::AnalogOutputDouble64& arCommand, size_t aIndex) { return opendnp3::CS_NOT_SUPPORTED; }
	opendnp3::CommandStatus Operate(const opendnp3::AnalogOutputDouble64& arCommand, size_t aIndex) { return opendnp3::CS_NOT_SUPPORTED; }
	opendnp3::CommandStatus DirectOperate(const opendnp3::AnalogOutputDouble64& arCommand, size_t aIndex) { return opendnp3::CS_NOT_SUPPORTED; }

};

#endif

