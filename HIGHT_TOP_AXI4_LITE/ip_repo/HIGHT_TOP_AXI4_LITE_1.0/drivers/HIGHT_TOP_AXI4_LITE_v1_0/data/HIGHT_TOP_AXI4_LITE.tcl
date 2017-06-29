

proc generate {drv_handle} {
	xdefine_include_file $drv_handle "xparameters.h" "HIGHT_TOP_AXI4_LITE" "NUM_INSTANCES" "DEVICE_ID"  "C_S_AXI_BASEADDR" "C_S_AXI_HIGHADDR"
}
