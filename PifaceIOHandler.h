
#ifndef __PIFACE_IO_HANDLER_H_
#define __PIFACE_IO_HANDLER_H_

#include <opendnp3/outstation/ICommandHandler.h>
#include <opendnp3/app/ControlRelayOutputBlock.h>
#include <asiodnp3/IOutstation.h>

class PifaceIOHandler : public opendnp3::ICommandHandler
{

private:

	void DoOperate(const opendnp3::ControlRelayOutputBlock& command, uint8_t index);
	opendnp3::CommandStatus ValidateCROB(const opendnp3::ControlRelayOutputBlock& command, uint16_t index);

	static bool isSwitchOn(int data, int num);

	struct pulse {
		uint64_t when;
		bool state;
		opendnp3::ControlRelayOutputBlock crob;
	};
	struct pulse pulse[8];

public:

	PifaceIOHandler();
	~PifaceIOHandler();

	virtual void Start() override {}
	virtual void End() override {}

	void ReadMeasurements(asiodnp3::IOutstation* pOutstation);
	void ProcessPulses();

	opendnp3::CommandStatus Select(const opendnp3::ControlRelayOutputBlock& command, uint16_t index);
	opendnp3::CommandStatus Operate(const opendnp3::ControlRelayOutputBlock& command, uint16_t index, opendnp3::OperateType opType);

	opendnp3::CommandStatus Select(const opendnp3::AnalogOutputInt16& command, uint16_t index) { return opendnp3::CommandStatus::NOT_SUPPORTED; }
	opendnp3::CommandStatus Operate(const opendnp3::AnalogOutputInt16& command, uint16_t index, opendnp3::OperateType opType) { return opendnp3::CommandStatus::NOT_SUPPORTED; }

	opendnp3::CommandStatus Select(const opendnp3::AnalogOutputInt32& command, uint16_t index) { return opendnp3::CommandStatus::NOT_SUPPORTED; }
	opendnp3::CommandStatus Operate(const opendnp3::AnalogOutputInt32& command, uint16_t index, opendnp3::OperateType opType)  { return opendnp3::CommandStatus::NOT_SUPPORTED; }

	opendnp3::CommandStatus Select(const opendnp3::AnalogOutputFloat32& command, uint16_t index) { return opendnp3::CommandStatus::NOT_SUPPORTED; }
	opendnp3::CommandStatus Operate(const opendnp3::AnalogOutputFloat32& command, uint16_t index, opendnp3::OperateType opType) { return opendnp3::CommandStatus::NOT_SUPPORTED; }

	opendnp3::CommandStatus Select(const opendnp3::AnalogOutputDouble64& command, uint16_t index) { return opendnp3::CommandStatus::NOT_SUPPORTED; }
	opendnp3::CommandStatus Operate(const opendnp3::AnalogOutputDouble64& command, uint16_t index, opendnp3::OperateType opType) { return opendnp3::CommandStatus::NOT_SUPPORTED; }

};

#endif

