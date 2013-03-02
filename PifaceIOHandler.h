
#ifndef __PIFACE_IO_HANDLER_H_
#define __PIFACE_IO_HANDLER_H_

using namespace opendnp3;

class PifaceIOHandler : public ICommandHandler
{

private:

	void DoOperate(const ControlRelayOutputBlock& arCommand, size_t aIndex);	

public:

	PifaceIOHandler();
	~PifaceIOHandler();
	
	CommandStatus Select(const ControlRelayOutputBlock& arCommand, size_t aIndex);		
	CommandStatus Operate(const ControlRelayOutputBlock& arCommand, size_t aIndex);
	CommandStatus DirectOperate(const ControlRelayOutputBlock& arCommand, size_t aIndex);

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

#endif

