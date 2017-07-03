

/***************************** Include Files *******************************/
#include "HIGHT_TOP_AXI4_LITE.h"
#include "xparameters.h"

/************************** Function Definitions ***************************/


/*********************** Register control level ******************************/

void HIGHT_TOP_setKey(u32 key0, u32 key1, u32 key2, u32 key3)
{
	HIGHT_TOP_AXI4_LITE_mWriteReg(XPAR_HIGHT_TOP_AXI4_LITE_0_S_AXI_BASEADDR, HIGHT_TOP_AXI4_LITE_S_AXI_SLV_REG0_OFFSET, key0);
	HIGHT_TOP_AXI4_LITE_mWriteReg(XPAR_HIGHT_TOP_AXI4_LITE_0_S_AXI_BASEADDR, HIGHT_TOP_AXI4_LITE_S_AXI_SLV_REG1_OFFSET, key1);
	HIGHT_TOP_AXI4_LITE_mWriteReg(XPAR_HIGHT_TOP_AXI4_LITE_0_S_AXI_BASEADDR, HIGHT_TOP_AXI4_LITE_S_AXI_SLV_REG2_OFFSET, key2);
	HIGHT_TOP_AXI4_LITE_mWriteReg(XPAR_HIGHT_TOP_AXI4_LITE_0_S_AXI_BASEADDR, HIGHT_TOP_AXI4_LITE_S_AXI_SLV_REG3_OFFSET, key3);
}

void HIGHT_TOP_setInputData(u32 data0, u32 data1)
{
	HIGHT_TOP_AXI4_LITE_mWriteReg(XPAR_HIGHT_TOP_AXI4_LITE_0_S_AXI_BASEADDR, HIGHT_TOP_AXI4_LITE_S_AXI_SLV_REG4_OFFSET, data0);
	HIGHT_TOP_AXI4_LITE_mWriteReg(XPAR_HIGHT_TOP_AXI4_LITE_0_S_AXI_BASEADDR, HIGHT_TOP_AXI4_LITE_S_AXI_SLV_REG5_OFFSET, data1);
}

void HIGHT_TOP_setControl(u32 ctrl) // [1]:operation(0:encryption, 1:decryption), [0]:start
{
	HIGHT_TOP_AXI4_LITE_mWriteReg(XPAR_HIGHT_TOP_AXI4_LITE_0_S_AXI_BASEADDR, HIGHT_TOP_AXI4_LITE_S_AXI_SLV_REG8_OFFSET, ctrl);
}

void HIGHT_TOP_getOutputData(u32 data[])
{
	data[0] = (u32)HIGHT_TOP_AXI4_LITE_mReadReg(XPAR_HIGHT_TOP_AXI4_LITE_0_S_AXI_BASEADDR, HIGHT_TOP_AXI4_LITE_S_AXI_SLV_REG6_OFFSET);
	data[1] = (u32)HIGHT_TOP_AXI4_LITE_mReadReg(XPAR_HIGHT_TOP_AXI4_LITE_0_S_AXI_BASEADDR, HIGHT_TOP_AXI4_LITE_S_AXI_SLV_REG7_OFFSET);
}

u32 HIGHT_TOP_getStatus()
{
	return (u32)HIGHT_TOP_AXI4_LITE_mReadReg(XPAR_HIGHT_TOP_AXI4_LITE_0_S_AXI_BASEADDR, HIGHT_TOP_AXI4_LITE_S_AXI_SLV_REG9_OFFSET);
}

/*********************** API Level ******************************/

void HIGHT_TOP_doEncyption(u32 key[], u32 plainData[], u32 encryptedData[]);
void HIGHT_TOP_doDecryption(u32 key[], u32 encryptedData[], u32 plainData[]);
