#pragma once
#include "Register.hpp"
#include "MemoryController.hpp"

class CPUController {
private:
    Register16Bit af;
    Register16Bit bc;
    Register16Bit de;
    Register16Bit hl;
    MemoryController memoryController;
    Register16Bit stackPointer;
    uint8_t cpu8BitRegisterMemoryLoad(Register8Bit &r);
    uint8_t cpu8BitRegisterLoad(Register8Bit &r, Register8Bit v);
    uint8_t cpu8BitRegisterMemoryWrite(uint16_t address, Register8Bit v);
    uint8_t cpu8BitRegisterMemoryAddressLoad(Register8Bit &r, uint16_t address);
    uint8_t cpu16BitRegisterMemoryLoad(Register16Bit &r);
    uint8_t cpu8BitRegisterAdd(Register8Bit &r, uint8_t addend, bool useCarry);
    uint8_t cpu8BitRegisterSubtract(Register8Bit &r, uint8_t minuend, bool useCarry);
    uint8_t cpu8BitAnd(uint8_t operand);
    uint8_t cpu8BitOr(uint8_t operand);
    uint8_t cpu8BitXor(uint8_t operand);
    uint8_t cpu8BitCompare(uint8_t operand);
    uint8_t cpu8BitRegisterIncrement(Register8Bit &r);
    uint8_t cpu8BitIncrementMemoryAddress(uint16_t address);
    uint8_t cpu8BitRegisterDecrement(Register8Bit &r);
    uint8_t cpu8BitDecrementMemoryAddress(uint16_t address);
    uint8_t cpu16BitRegisterAdd(Register16Bit &r1, Register16Bit r2);
    uint8_t cpu16BitRegisterIncrement(Register16Bit &r);
    uint8_t cpu16BitRegisterDecrement(Register16Bit &r);
    uint8_t cpu8BitRegisterSwap(Register8Bit &r);
    uint8_t cpu8BitSwapMemoryAddress(uint16_t address);
    uint8_t cpuDDA();
    uint8_t cpu8BitRegisterRLC(Register8Bit &r);
    uint8_t cpu8BitRegisterRL(Register8Bit &r);
    uint8_t cpu8BitRegisterRRC(Register8Bit &r);
    uint8_t cpu8BitRegisterRR(Register8Bit &r);
    uint8_t cpu8BitRegisterRLCMemoryAddress(uint16_t address);
    uint8_t cpu8BitRegisterRLMemoryAddress(uint16_t address);
    uint8_t cpu8BitRegisterRRCMemoryAddress(uint16_t address);
    uint8_t cpu8BitRegisterRRMemoryAddress(uint16_t address);
    uint8_t cpu8BitRegisterSLA(Register8Bit &r);
    uint8_t cpu8BitRegisterSLAMemoryAddress(uint16_t address);
    uint8_t cpu8BitRegisterSRA(Register8Bit &r);
    uint8_t cpu8BitRegisterSRAMemoryAddress(uint16_t address);
    uint8_t cpu8BitRegisterSRL(Register8Bit &r);
    uint8_t cpu8BitRegisterSRLMemoryAddress(uint16_t address);
    uint8_t cpu8BitRegisterBit(Register8Bit &r, uint8_t position);
    uint8_t cpu8BitRegisterBitMemoryAddress(uint16_t address, uint8_t position);
    uint8_t cpu8BitRegisterSet(Register8Bit &r, uint8_t position);
    uint8_t cpu8BitRegisterSetMemoryAddress(uint16_t address, uint8_t position);
    uint8_t cpu8BitRegisterReset(Register8Bit &r, uint8_t position);
    uint8_t cpu8BitRegisterResetMemoryAddress(uint16_t address, uint8_t position);
    uint8_t cpu8BitJump(uint16_t address);
    uint8_t cpu8BitJumpConditional(bool condition);
    uint8_t cpu8BitJumpAddConditional(bool condition);
    uint8_t cpu8BitCall(bool condition);
    uint8_t cpu8BitRestart(uint16_t address);
    uint8_t cpu8BitReturn(bool condition);
    uint8_t cpu8BitReturnEnableInterrupts();
    bool flagZ();
    bool flagN();
    bool flagH();
    bool flagC();
    void setFlagZ();
    void setFlagN();
    void setFlagH();
    void setFlagC();
    void clearFlagZ();
    void clearFlagN();
    void clearFlagH();
    void clearFlagC();
    void clearAllFlags();
    uint16_t popFromStack();
    uint8_t executeExtendedOpCode(uint8_t opCode);
public:
    Register16Bit programCounter;
    bool halted;
    bool disableInterrupts;
    bool pendingDisableInterrupts;
    bool pendingEnableInterrupts;
    CPUController();
    ~CPUController();
    uint8_t executeOpCode(uint8_t opCode);
    void pushIntoStack(uint16_t value);
};