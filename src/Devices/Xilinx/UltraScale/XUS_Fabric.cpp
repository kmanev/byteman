/******************************************************************************
 * Copyright 2022 Kristiyan Manev, Joseph Powell (University of Manchester)
 *
 * Licensed under the Apache License, Version 2.0(the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include<cstdint> //uint
#include<string>

#include "XilinxUltraScale.h"

void XilinxUltraScale::initFabric(){
	setFabricChar(char(0), 0, "EndedLine", true);
	setFabricChar(char(1), XUS_EXTRA_FRAMES_PER_ROW, "EndOfLine", true);
	//The Xilinx US fabric in byteman is encoded in the following letters:

	//A-D are brams
	setFabricChar('A', 4, "BRAM/RCLK_RCLK_BRAM_L_BRAMCLMP_FT");        //"BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL/RCLK_RCLK_BR
	setFabricChar('B', 4, "BRAM/RCLK_RCLK_BRAM_L_AUXCLMP_FT");         //"BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL/RCLK_RCLK_BR
	setFabricChar('C', 4, "BRAM/RCLK_BRAM_L");                         //"BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL/RCLK_BRAM_L"
	setFabricChar('D', 4, "BRAM/RCLK_BRAM_R");                         //"BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL+BRAM+NULL+NULL+NULL+NULL/RCLK_BRAM_R"

	//E-F, R are DSPs
	setFabricChar('E', 4, "DSP/RCLK_DSP_L");                           //"DSP+NULL+NULL+NULL+NULL+DSP+NULL+NULL+NULL+NULL+DSP+NULL+NULL+NULL+NULL+DSP+NULL+NULL+NULL+NULL+DSP+NULL+NULL+NULL+NULL+DSP+NULL+NULL+NULL+NULL+DSP+NULL+NULL+NULL+NULL+DSP+NULL+NULL+NULL+NULL+DSP+NULL+NULL+NULL+NULL+DSP+NULL+NULL+NULL+NULL+DSP+NULL+NULL+NULL+NULL+DSP+NULL+NULL+NULL+NULL/RCLK_DSP_L"
	setFabricChar('F', 6, "DSP/RCLK_DSP_CLKBUF_L");                    //"DSP+NULL+NULL+NULL+NULL+DSP+NULL+NULL+NULL+NULL+DSP+NULL+NULL+NULL+NULL+DSP+NULL+NULL+NULL+NULL+DSP+NULL+NULL+NULL+NULL+DSP+NULL+NULL+NULL+NULL+DSP+NULL+NULL+NULL+NULL+DSP+NULL+NULL+NULL+NULL+DSP+NULL+NULL+NULL+NULL+DSP+NULL+NULL+NULL+NULL+DSP+NULL+NULL+NULL+NULL+DSP+NULL+NULL+NULL+NULL/RCLK_DSP_CLKBUF_L"

	//G-H are interconnect cols with different clock resources
	setFabricChar('G', 58, "INT/RCLK_INT_L");                          //"INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT/RCLK_INT_L"    
	setFabricChar('H', 58, "INT/RCLK_INT_R");                          //"INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT+INT/RCLK_INT_R"

	//I-J are CLEL_R tiles with different clock resources
	setFabricChar('I', 12, "CLEL_R/RCLK_CLEL_R_L");                    //"CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R/RCLK_CLEL_R_L"
	setFabricChar('J', 12, "CLEL_R/RCLK_CLEL_R_R");                    //"CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R+CLEL_R/RCLK_CLEL_R_R"

	//K-L are CLEL_L tiles with different clock resources
	setFabricChar('K', 12, "CLEL_L/RCLK_CLEL_R");                      //"CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L/RCLK_CLEL_R"
	setFabricChar('L', 12, "CLEL_L/RCLK_CLEL_L");                      //"CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L+CLEL_L/RCLK_CLEL_L"

	//M-N are CLE_M tiles with different clock resources
	setFabricChar('M', 12, "CLE_M/RCLK_CLE_M_L");                      //"CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M/RCLK_CLE_M_L"
	setFabricChar('N', 12, "CLE_M/RCLK_CLEM_CLKBUF_L");                //"CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M+CLE_M/RCLK_CLEM_CLKBUF_L"

	//O = CLE_M_R
	setFabricChar('O', 12, "CLE_M_R");                                 //"CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R+CLE_M_R/RCLK_CLE_M_R"

	//P-Q are laguna tiles with different clock resources
	setFabricChar('P', 12, "LAGUNA_TILE/RCLK_RCLK_LAGUNA_L_FT");       //"LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE/RCLK_RCLK_LAGUNA_L_FT"
	setFabricChar('Q', 12, "LAGUNA_TILE/RCLK_RCLK_LAGUNA_R_FT");       //"LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE+LAGUNA_TILE/RCLK_RCLK_LAGUNA_R_FT"

	//a-l are I/O and misc
	setFabricChar('a', 10, "HPIO_L");                                  //"HPIO_L+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+HPIO_L+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL/RCLK_HPIO_L"
	setFabricChar('b', 16, "XIPHY_L");                                 //"XIPHY_L+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL/NULL"
	setFabricChar('c', 10, "HRIO_L");                                  //"HRIO_L+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+HRIO_L+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL/RCLK_HRIO_L"
	setFabricChar('d', 6, "INT_INTERFACE_PCIE_R");                     //"INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R+INT_INTERFACE_PCIE_R/RCLK_INTF_PCIE_R_L"
	setFabricChar('e', 2, "PCIE");                                     //"PCIE+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL/NULL"
	setFabricChar('f', 12, "GTH_R");                                   //"GTH_R+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL/NULL"
	setFabricChar('g', 2, "CFG_CFG");                                  //"CFG_CFG+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL/NULL"
	setFabricChar('h', 2, "CFGIO_IOB");                                //"CFGIO_IOB+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+AMS+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL/RCLK_AMS_CFGIO"
	setFabricChar('i', 16, "GTH_QUAD_LEFT_FT");                        //"GTH_QUAD_LEFT_FT+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL/NULL"
	setFabricChar('j', 12, "GTY_QUAD_LEFT_FT");                        //"GTY_QUAD_LEFT_FT+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL/NULL"
	setFabricChar('k', 2, "ILMAC_ILMAC_FT");                           //"ILMAC_ILMAC_FT+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL/NULL"
	setFabricChar('l', 2, "CMAC_CMAC_FT");                             //"CMAC_CMAC_FT+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL+NULL/NULL"

	//Also in the fabric exist frames that are mapped in bitstreams, but do not physically exist on the device. We encode these as follows:
	setFabricChar('0', 10, "EMPTY10", true);
	setFabricChar('1', 2,  "EMPTY2",  true);
	setFabricChar('2', 4,  "EMPTY4/BRAM",  true);
	setFabricChar('3', 6,  "EMPTY6",  true);
	setFabricChar('4', 12, "EMPTY12", true);
	setFabricChar('5', 16, "EMPTY16", true);
	setFabricChar('6', 58, "EMPTY58", true);
	setFabricChar('7', 4,  "EMPTY4",  true);
}
