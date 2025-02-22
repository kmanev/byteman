/******************************************************************************
 * Copyright 2022 Kristiyan Manev (University of Manchester)
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

/**************************************************************************//**
 * @mainpage
 * byteman is a high-throughput bitstream relocation and manipulation tool.
 *
 *
 * A good starting point to explore the code is byteman.cpp where the main()
 * function parses the command line arguments.
 *
 * A list of currently implemented FPGA architectures:
 * - Xilinx Series 7 (XilinxSeries7, which implements a CommonDevice2D and XilinxConfigurationAccessPort)
 * - Xilinx UltraScale (XilinxUltraScale, which implements a CommonDevice2D and XilinxConfigurationAccessPort)
 * - Xilinx UltraScale+ (XilinxUltraScalePlus, which implements a CommonDevice2D and XilinxConfigurationAccessPort)
 *
 *****************************************************************************/

#ifndef BYTEMAN_H
#define BYTEMAN_H

#include<iostream>
#include<string>

#ifdef XS7
	#include "Devices/Xilinx/Series7/XilinxSeries7.h"
#endif

#ifdef XUS
	#include "Devices/Xilinx/UltraScale/XilinxUltraScale.h"
#endif

#ifdef XUSP
	#include "Devices/Xilinx/UltraScalePlus/XilinxUltraScalePlus.h"
#endif



class byteman
{
	public:
		byteman();
		virtual ~byteman();
		#ifdef XS7
			XilinxSeries7 mainXS7, tempXS7;
		#endif //XS7
		
		#ifdef XUS
			XilinxUltraScale mainXUS, tempXUS;
		#endif //XUS
		
		#ifdef XUSP
			XilinxUltraScalePlus mainXUSP, tempXUSP;
		#endif //XUSP
		
		enum class Architecture{
			Unknown,
			Xilinx_Series6,
			Xilinx_Series7,
			Xilinx_UltraScale,
			Xilinx_UltraScalePlus,
			Xilinx_Versal
		} selectedArchitecture = Architecture::Unknown;
		struct SelectedOptions
		{
			bool mainBufferSelected, tempBufferSelected;
			SelectedOptions():mainBufferSelected(false), tempBufferSelected(false){}
		} options;
		//parse
		std::string parseParamsAndRemoveThemFromString(std::string);
		
		void parse(std::string);
		void setArchitecture(std::string);
		void parseAssembly(std::string);
		void parseOutput(std::string);
		void parseMerge(std::string);
		void parseInput(std::string);
		void parseDevice(std::string);
		void parseChange(std::string);
		void parseBlank(std::string);
		void parseRegion(std::string);
		void parseWarn(std::string);
		void parseVerbose(std::string);
		
		
		void help(std::string, int);
		void help(std::string);
		void help();

		void helpAssembly(bool=false);
		void helpOutput(bool=false);
		void helpMerge(bool=false);
		void helpInput(bool=false);
		void helpDevice(bool=false);
		void helpChange(bool=false);
		void helpBlank(bool=false);
		void helpRegion(bool=false);
		void helpWarn(bool=false);
		void helpVerbose(bool=false);
		void helpHelp(bool=false);
		void helpExit(bool=false);
		void helpStdin(bool=false);
		
		#if !defined(NDEBUG)
		void parseTest(std::string);
		#endif
};


#endif //BYTEMAN_H
