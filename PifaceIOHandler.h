
#ifndef __PIFACE_IO_HANDLER_H_
#define __PIFACE_IO_HANDLER_H_

#include <opendnp3/outstation/ICommandHandler.h>
#include <asiodnp3/IOutstation.h>

class PifaceIOHandler final : public opendnp3::ICommandHandler
{

private:

	void Start() override {}
	void End() override {}

	void DoOperate(const opendnp3::ControlRelayOutputBlock& command, uint8_t index);
	opendnp3::CommandStatus ValidateCROB(const opendnp3::ControlRelayOutputBlock& command, uint16_t index);

	static bool isSwitchOn(int data, int num);

public:

	PifaceIOHandler();
	~PifaceIOHandler();

	void ReadMeasurements(asiodnp3::IOutstation* pOutstation);

	opendnp3::CommandStatus Select(const opendnp3::ControlRelayOutputBlock& command, uint16_t index);
	opendnp3::CommandStatus Operate(const opendnp3::ControlRelayOutputBlock& command, uint16_t index);


	opendnp3::CommandStatus Select(const opendnp3::AnalogOutputInt16& command, uint16_t index) override { return opendnp3::CommandStatus::NOT_SUPPORTED; }
	opendnp3::CommandStatus Operate(const opendnp3::AnalogOutputInt16& command, uint16_t index) override { return opendnp3::CommandStatus::NOT_SUPPORTED; }

	opendnp3::CommandStatus Select(const opendnp3::AnalogOutputInt32& command, uint16_t index) override { return opendnp3::CommandStatus::NOT_SUPPORTED; }
	opendnp3::CommandStatus Operate(const opendnp3::AnalogOutputInt32& command, uint16_t index)  override { return opendnp3::CommandStatus::NOT_SUPPORTED; }

	opendnp3::CommandStatus Select(const opendnp3::AnalogOutputFloat32& command, uint16_t index) override { return opendnp3::CommandStatus::NOT_SUPPORTED; }
	opendnp3::CommandStatus Operate(const opendnp3::AnalogOutputFloat32& command, uint16_t index) override { return opendnp3::CommandStatus::NOT_SUPPORTED; }

	opendnp3::CommandStatus Select(const opendnp3::AnalogOutputDouble64& command, uint16_t index) override { return opendnp3::CommandStatus::NOT_SUPPORTED; }
	opendnp3::CommandStatus Operate(const opendnp3::AnalogOutputDouble64& command, uint16_t index) override { return opendnp3::CommandStatus::NOT_SUPPORTED; }


};

#endif

