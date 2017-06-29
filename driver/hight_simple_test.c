/*
 * hight_simple_test.c: hight simple test application
 *
 */

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "HIGHT_TOP_AXI4_LITE.h"

int main()
{
	u32 dataBuf[2] = {0};

    init_platform();

//    print("--Starting HIGHT Test Applications--\n\r");

//    xil_printf("0. Plain Data : %08x%08x\n\r", dataBuf[0], dataBuf[1]);

    HIGHT_TOP_setKey(0x00112233, 0x44556677, 0x8899aabb, 0xccddeeff);
    HIGHT_TOP_setInputData(dataBuf[0], dataBuf[1]);
    HIGHT_TOP_setControl(0x00000000); // set op = encryption
    HIGHT_TOP_setControl(0x00000001); // start

    while(!HIGHT_TOP_getStatus()); // waiting done

    HIGHT_TOP_getOutputData(dataBuf);

//    xil_printf("1. Encrypted Data : %08x%08x\n\r", dataBuf[0], dataBuf[1]);

    HIGHT_TOP_setInputData(dataBuf[0], dataBuf[1]);
    HIGHT_TOP_setControl(0x00000000); // clear control
    HIGHT_TOP_setControl(0x00000002); // set op = decryption
    HIGHT_TOP_setControl(0x00000003); // start

    HIGHT_TOP_getOutputData(dataBuf);

//    xil_printf("2. Encrypted Data : %08x%08x\n\r", dataBuf[0], dataBuf[1]);

//    print("--Hight Test Application Complete--\n\r");

    cleanup_platform();
    return 0;
}
