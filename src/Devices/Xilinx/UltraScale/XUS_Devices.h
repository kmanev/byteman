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

#ifndef XILINXULTRASCALEDEVICES_H
#define XILINXULTRASCALEDEVICES_H

#include<cstring>//strcpy

enum XUS_DEVICE_ENUM    ///< Enumeration of recognized Xilinx UltraScale devices and boards.
{
    XUS_DEVICE_NULL = 0,
    //XUS Kintex
    XUS_DEVICE_XCKU025,
    XUS_DEVICE_XCKU035,
    XUS_DEVICE_XCKU040,
    XUS_DEVICE_XCKU060,
    XUS_DEVICE_XCKU085,
    XUS_DEVICE_XCKU095,
    XUS_DEVICE_XCKU115,
    //XUS Virtex
    XUS_DEVICE_XCVU065,
    XUS_DEVICE_XCVU080,
    XUS_DEVICE_XCVU095,
    XUS_DEVICE_XCVU125,
    XUS_DEVICE_XCVU160,
    XUS_DEVICE_XCVU190,
    XUS_DEVICE_XCVU440,
	
    XUS_DEVICE_MAX
};
  
#define TODO 0
//Functions how to build devices
#define XUS_PARTNAME(value) {initializedResourceStringPartName = partName = value;}
#define XUS_SLRFROMROW(slrID,value) {SLRinfo[slrID].fromRow = value;}
#define XUS_SLRTOROW(slrID,value) {SLRinfo[slrID].toRow = value;}
#define XUS_ROWNUM(value) {numberOfRows = value;}
#define XUS_SLRNUM(value) {numberOfSLRs = value;}
#define XUS_IDCODE(slrID,value) {SLRinfo[slrID].IDCODE = value;}
#define XUS_STRING(rowID,value) {strcpy(resourceString[rowID],value);}
#define XUS_STRING_CAT(x,y)  {XUS_STRING(y, x##STRING##y);}
#define XUS_STRING_CAT_2(x)  {XUS_STRING_CAT(x,0);  XUS_STRING_CAT(x,1);}
#define XUS_STRING_CAT_3(x)  {XUS_STRING_CAT_2(x);  XUS_STRING_CAT(x,2);}
#define XUS_STRING_CAT_4(x)  {XUS_STRING_CAT_3(x);  XUS_STRING_CAT(x,3);}
#define XUS_STRING_CAT_5(x)  {XUS_STRING_CAT_4(x);  XUS_STRING_CAT(x,4);}
#define XUS_STRING_CAT_6(x)  {XUS_STRING_CAT_5(x);  XUS_STRING_CAT(x,5);}
#define XUS_STRING_CAT_7(x)  {XUS_STRING_CAT_6(x);  XUS_STRING_CAT(x,6);}
#define XUS_STRING_CAT_8(x)  {XUS_STRING_CAT_7(x);  XUS_STRING_CAT(x,7);}
#define XUS_STRING_CAT_9(x)  {XUS_STRING_CAT_8(x);  XUS_STRING_CAT(x,8);}
#define XUS_STRING_CAT_10(x) {XUS_STRING_CAT_9(x);  XUS_STRING_CAT(x,9);}
#define XUS_STRING_CAT_11(x) {XUS_STRING_CAT_10(x); XUS_STRING_CAT(x,10);}
#define XUS_STRING_CAT_12(x) {XUS_STRING_CAT_11(x); XUS_STRING_CAT(x,11);}
#define XUS_STRING_CAT_13(x) {XUS_STRING_CAT_12(x); XUS_STRING_CAT(x,12);}
#define XUS_STRING_CAT_14(x) {XUS_STRING_CAT_13(x); XUS_STRING_CAT(x,13);}
#define XUS_STRING_CAT_15(x) {XUS_STRING_CAT_14(x); XUS_STRING_CAT(x,14);}

#define XUS_SETUP_SLR_EXPANDED(slrID,idcodeVal,fromRowVal,toRowVal) {XUS_IDCODE(slrID,idcodeVal);XUS_SLRFROMROW(slrID,fromRowVal);XUS_SLRTOROW(slrID,toRowVal);}
#define XUS_SETUP_SLR0(prefix) {XUS_SETUP_SLR_EXPANDED(0, prefix##IDCODE, prefix##SLR0_START, prefix##SLR0_END);}
#define XUS_SETUP_SLR(slrID, prefix) {XUS_SETUP_SLR_EXPANDED(slrID, prefix##IDCODE##slrID, prefix##SLR##slrID##_START, prefix##SLR##slrID##_END);}
#define XUS_SETUP_SLRs_2(prefix) {XUS_SETUP_SLR0(prefix); XUS_SETUP_SLR(1,prefix);}
#define XUS_SETUP_SLRs_3(prefix) {XUS_SETUP_SLRs_2(prefix); XUS_SETUP_SLR(2,prefix);}
#define XUS_SETUP_DEVICE(prefix) {                                                                \
    XUS_PARTNAME(prefix##NAME);                                                                   \
    XUS_SLRNUM(prefix##SLRNUM);                                                                   \
    XUS_ROWNUM(prefix##ROWNUM);                                                                   \
    XUS_SLRFROMROW(0,0);                                                                          \
    XUS_SLRTOROW(0,prefix##ROWNUM-1);                                                             \
    XUS_IDCODE(0,prefix##IDCODE);                                                                 \
}


//Xilinx UltraScale Kintex
	
	//XCKU025 is weird, vivado shows it as 3 rows, but the bitstreams have 5 rows! So we add 4th and 5th rows full of unused resources?
    #define XCKU025_NAME "xcku025"
    #define XCKU025_SLRNUM 1
    #define XCKU025_ROWNUM 5
    #define XCKU025_IDCODE 0x3824093
    #define XCKU025_STRING0 "abGIMGIAGIMGEMGIMGIBGIMGENGIMGIMGIMGEMGIMGICGIMGFMGIMGIAGIMGEMGIMGIBGIMGENGIMGIMGIMGEMGIMGICGIMGFcbGIMGIMGEMGIMGIMGEMGIAGIMGENGIMGIMGEMGIMGIMGEMGIBGIMGFMGIMGEMGIMGEMGILGICGILGdeHJKHJDHJKHJOHJKHJKHJOHf\x01"
    #define XCKU025_STRING1 "abGIMGIAGIMGEMGIMGIBGIMGENGIMGIMGIMGEMGIMGICGIMGFMGIMGIAGIMGEMGIMGIBGIMGENGIMGIMGIMGEMGIMGICGIMGFcbGIMGIMGEMGIMGIMGEMGIAGIMGENGIMGIMGEMGIMGIMGEMGIBGIMGFMGIMGEMGIMGEMGILGICGILGdgHJKHJDHJKHJOHJKHJKHJOHf\x01"
    #define XCKU025_STRING2 "abGIMGIAGIMGEMGIMGIBGIMGENGIMGIMGIMGEMGIMGICGIMGFMGIMGIAGIMGEMGIMGIBGIMGENGIMGIMGIMGEMGIMGICGIMGFabGIMGIMGEMGIMGIMGEMGIAGIMGENGIMGIMGEMGIMGIMGEMGIBGIMGFMGIMGEMGIMGEMGILGICGILGdhHJKHJDHJKHJOHJKHJKHJOHf\x01"
    #define XCKU025_STRING3 "05644642644674644642644674644644644674644642644634644642644674644642644674644644644674644642644630564464467464464467464264467464464467464464467464264463464467464467464464264463164464264464464464464464\x01"
    #define XCKU025_STRING4 XCKU035_STRING3
    #define XCKU025() {                                                                           \
        XUS_SETUP_DEVICE(XCKU025_);                                                               \
        XUS_STRING_CAT_5(XCKU025_);                                                               \
    }
	
	//XCKU035 is a software-limitted version of XCKU040
    #define XCKU035_NAME "xcku035"
    #define XCKU035_SLRNUM 1
    #define XCKU035_ROWNUM 5
    #define XCKU035_IDCODE 0x3823093
    #define XCKU035_STRING0 XCKU025_STRING0
    #define XCKU035_STRING1 XCKU025_STRING1
    #define XCKU035_STRING2 XCKU025_STRING2
    #define XCKU035_STRING3 "abGIMGIAGIMGEMGIMGIBGIMGENGIMGIMGIMGEMGIMGICGIMGFMGIMGIAGIMGEMGIMGIBGIMGENGIMGIMGIMGEMGIMGICGIMGFabGIMGIMGEMGIMGIMGEMGIAGIMGENGIMGIMGEMGIMGIMGEMGIBGIMGFMGIMGEMGIMGEMGILGICGILGdeHJKHJDHJKHJOHJKHJKHJOHf\x01"
    #define XCKU035_STRING4 XCKU035_STRING3
    #define XCKU035() {                                                                           \
        XUS_SETUP_DEVICE(XCKU035_);                                                               \
        XUS_STRING_CAT_5(XCKU035_);                                                               \
    }
	
    #define XCKU040_NAME "xcku040"
    #define XCKU040_SLRNUM 1
    #define XCKU040_ROWNUM 5
    #define XCKU040_IDCODE 0x3822093
    #define XCKU040_STRING0 XCKU035_STRING0
    #define XCKU040_STRING1 XCKU035_STRING1
    #define XCKU040_STRING2 XCKU035_STRING2
    #define XCKU040_STRING3 XCKU035_STRING3
    #define XCKU040_STRING4 XCKU035_STRING4
    #define XCKU040() {                                                                           \
        XUS_SETUP_DEVICE(XCKU040_);                                                               \
        XUS_STRING_CAT_5(XCKU040_);                                                               \
    }
	
    #define XCKU060_NAME "xcku060"
    #define XCKU060_SLRNUM 1
    #define XCKU060_ROWNUM 5
    #define XCKU060_IDCODE 0x3919093
    #define XCKU060_STRING0 "abGIMGIAGIMGEMGIPGIBGIMGENGIMGEMGIMGEMGIPGICGIMGFMGIMGIAGIMGEMGIPGIBGIMGENGIMGIMGIMGEMGIPGICGIMGFabGIMGIAGIMGEMGIPGIBGIMGENGIMGEMGIMGEMGIPGICGIMGFMGIMGIAGIMGEMGIPGIBGIMGENGIMGIMGIMGEMGIPGICGIMGFcbGIMGIAGIMGEMGIPGIBGIMGENGIMGEMGIMGEMGIPGICGIMGFMGILGILGICGIPGICGILGdeHJKHJDHJKHJQHJKHJKHJOHf\x01"
    #define XCKU060_STRING1 "abGIMGIAGIMGEMGIMGIBGIMGENGIMGEMGIMGEMGIMGICGIMGFMGIMGIAGIMGEMGIMGIBGIMGENGIMGIMGIMGEMGIMGICGIMGFabGIMGIAGIMGEMGIMGIBGIMGENGIMGEMGIMGEMGIMGICGIMGFMGIMGIAGIMGEMGIMGIBGIMGENGIMGIMGIMGEMGIMGICGIMGFcbGIMGIAGIMGEMGIMGIBGIMGENGIMGEMGIMGEMGIMGICGIMGFMGILGILGIBGIMGIAGILGdgHJKHJDHJKHJOHJKHJKHJOHf\x01"
    #define XCKU060_STRING2 "0iGIMGIAGIMGEMGIMGIBGIMGENGIMGEMGIMGEMGIMGICGIMGFMGIMGIAGIMGEMGIMGIBGIMGENGIMGIMGIMGEMGIMGICGIMGFabGIMGIAGIMGEMGIMGIBGIMGENGIMGEMGIMGEMGIMGICGIMGFMGIMGIAGIMGEMGIMGIBGIMGENGIMGIMGIMGEMGIMGICGIMGFabGIMGIAGIMGEMGIMGIBGIMGENGIMGEMGIMGEMGIMGICGIMGFMGILGILGIBGIMGIAGILGdhHJKHJDHJKHJOHJKHJKHJOHf\x01"
    #define XCKU060_STRING3 "0iGIMGIAGIMGEMGIMGIBGIMGENGIMGEMGIMGEMGIMGICGIMGFMGIMGIAGIMGEMGIMGIBGIMGENGIMGIMGIMGEMGIMGICGIMGFabGIMGIAGIMGEMGIMGIBGIMGENGIMGEMGIMGEMGIMGICGIMGFMGIMGIAGIMGEMGIMGIBGIMGENGIMGIMGIMGEMGIMGICGIMGFabGIMGIAGIMGEMGIMGIBGIMGENGIMGEMGIMGEMGIMGICGIMGFMGILGILGIBGIMGIAGILGdeHJKHJDHJKHJOHJKHJKHJOHf\x01"
    #define XCKU060_STRING4 "0iGIMGIAGIMGEMGIPGIBGIMGENGIMGEMGIMGEMGIPGICGIMGFMGIMGIAGIMGEMGIPGIBGIMGENGIMGIMGIMGEMGIPGICGIMGFabGIMGIAGIMGEMGIPGIBGIMGENGIMGEMGIMGEMGIPGICGIMGFMGIMGIAGIMGEMGIPGIBGIMGENGIMGIMGIMGEMGIPGICGIMGFabGIMGIAGIMGEMGIPGIBGIMGENGIMGEMGIMGEMGIPGICGIMGFMGILGILGICGIPGICGILGdeHJKHJDHJKHJQHJKHJKHJOHf\x01"
    #define XCKU060() {                                                                           \
        XUS_SETUP_DEVICE(XCKU060_);                                                               \
        XUS_STRING_CAT_5(XCKU060_);                                                               \
    }
	
	//XCKU085 is a software-limitted version of XCKU115 with one die missing a row
    #define XCKU085_NAME "xcku085"
    #define XCKU085_SLRNUM 2
    #define XCKU085_ROWNUM 9
    #define XCKU085_IDCODE 0x380F093
    #define XCKU085_IDCODE1 0x3802093
    #define XCKU085_SLR0_START 0
    #define XCKU085_STRING0 XCKU060_STRING0
    #define XCKU085_STRING1 XCKU060_STRING1
    #define XCKU085_STRING2 XCKU060_STRING2
    #define XCKU085_STRING3 XCKU060_STRING3
    #define XCKU085_STRING4 XCKU060_STRING4
    #define XCKU085_SLR0_END 4
    #define XCKU085_SLR1_START 5
    #define XCKU085_STRING5 XCKU085_STRING0
    #define XCKU085_STRING6 XCKU085_STRING1
    #define XCKU085_STRING7 XCKU085_STRING2
    #define XCKU085_STRING8 XCKU085_STRING3
    #define XCKU085_SLR1_END 8
    #define XCKU085() {                                                                           \
        XUS_SETUP_DEVICE(XCKU085_);                                                               \
        XUS_SETUP_SLRs_2(XCKU085_);                                                               \
        XUS_STRING_CAT_9(XCKU085_);                                                               \
    }
	
	//XCKU095 is a software-limitted version of XCVU095
    #define XCKU095_NAME "xcku095"
    #define XCKU095_SLRNUM 1
    #define XCKU095_ROWNUM 8
    #define XCKU095_IDCODE 0x3844093
    #define XCKU095_STRING0 "jGIMGILGILGILGIMGICGILGdkGILGILGIAGILGILGIBGIMGFMGILGIAGILGIMGILGILGIBGILGINGILGICGILGILGIMGILGIAGIMGFabGILGIAGILGIMGILGILGIBGILGINGILGICGILGILGIMGILGIAGIMGFcbGILGIAGILGIMGILGILGIBGILGINGILGICGILGILGIMGILGIAGIMGFMGILGILGIBGIMGIAGILGdeHJKHJDHJKHJOHJKHJKHJOHf\x01"
    #define XCKU095_STRING1 "jGIMGILGILGILGIMGICGILGdlGILGILGIAGILGILGIBGIMGFMGILGIAGILGIMGILGILGIBGILGINGILGICGILGILGIMGILGIAGIMGFabGILGIAGILGIMGILGILGIBGILGINGILGICGILGILGIMGILGIAGIMGFabGILGIAGILGIMGILGILGIBGILGINGILGICGILGILGIMGILGIAGIMGFMGILGILGIBGIMGIAGILGdgHJKHJDHJKHJOHJKHJKHJOHf\x01"
    #define XCKU095_STRING2 "jGIMGILGILGILGIMGICGILGdkGILGILGIAGILGILGIBGIMGFMGILGIAGILGIMGILGILGIBGILGINGILGICGILGILGIMGILGIAGIMGFabGILGIAGILGIMGILGILGIBGILGINGILGICGILGILGIMGILGIAGIMGFabGILGIAGILGIMGILGILGIBGILGINGILGICGILGILGIMGILGIAGIMGFMGILGILGIBGIMGIAGILGdhHJKHJDHJKHJOHJKHJKHJOHf\x01"
    #define XCKU095_STRING3 "jGIMGILGILGILGIMGICGILGdlGILGILGIAGILGILGIBGIMGFMGILGIAGILGIMGILGILGIBGILGINGILGICGILGILGIMGILGIAGIMGFabGILGIAGILGIMGILGILGIBGILGINGILGICGILGILGIMGILGIAGIMGFabGILGIAGILGIMGILGILGIBGILGINGILGICGILGILGIMGILGIAGIMGFMGILGILGIBGIMGIAGILGdkHJKHJDHJKHJOHJKHJKHJOHf\x01"
    #define XCKU095_STRING4 "jGIMGILGILGILGIMGICGILGdkGILGILGIAGILGILGIBGIMGFMGILGIAGILGIMGILGILGIBGILGINGILGICGILGILGIMGILGIAGIMGFabGILGIAGILGIMGILGILGIBGILGINGILGICGILGILGIMGILGIAGIMGFabGILGIAGILGIMGILGILGIBGILGINGILGICGILGILGIMGILGIAGIMGFMGILGILGIBGIMGIAGILGdeHJKHJDHJKHJOHJKHJKHJOHf\x01"
    #define XCKU095_STRING5 "jGIMGILGILGILGIMGICGILGdlGILGILGIAGILGILGIBGIMGFMGILGIAGILGIMGILGILGIBGILGINGILGICGILGILGIMGILGIAGIMGFabGILGIAGILGIMGILGILGIBGILGINGILGICGILGILGIMGILGIAGIMGFabGILGIAGILGIMGILGILGIBGILGINGILGICGILGILGIMGILGIAGIMGFMGILGILGIBGIMGIAGILGdeHJKHJDHJKHJOHJKHJKHJOHf\x01"
    #define XCKU095_STRING6 "jGIMGILGILGILGIMGICGILGdkGILGILGIAGILGILGIBGIMGFMGILGIAGILGIMGILGILGIBGILGINGILGICGILGILGIMGILGIAGIMGFabGILGIAGILGIMGILGILGIBGILGINGILGICGILGILGIMGILGIAGIMGFabGILGIAGILGIMGILGILGIBGILGINGILGICGILGILGIMGILGIAGIMGFMGILGILGIBGIMGIAGILGdkHJKHJDHJKHJOHJKHJKHJOHf\x01"
    #define XCKU095_STRING7 XCKU095_STRING5
    #define XCKU095() {                                                                           \
        XUS_SETUP_DEVICE(XCKU095_);                                                               \
        XUS_STRING_CAT_8(XCKU095_);                                                               \
    }
	
	//made of 2 XCKU060 dies
    #define XCKU115_NAME "xcku115"
    #define XCKU115_SLRNUM 2
    #define XCKU115_ROWNUM 10
    #define XCKU115_IDCODE 0x390D093
    #define XCKU115_IDCODE1 0x3902093
    #define XCKU115_SLR0_START 0
    #define XCKU115_STRING0 XCKU060_STRING0
    #define XCKU115_STRING1 XCKU060_STRING1
    #define XCKU115_STRING2 XCKU060_STRING2
    #define XCKU115_STRING3 XCKU060_STRING3
    #define XCKU115_STRING4 XCKU060_STRING4
    #define XCKU115_SLR0_END 4
    #define XCKU115_SLR1_START 5
	#define XCKU115_STRING5 XCKU060_STRING0
    #define XCKU115_STRING6 XCKU060_STRING1
    #define XCKU115_STRING7 XCKU060_STRING2
    #define XCKU115_STRING8 XCKU060_STRING3
    #define XCKU115_STRING9 XCKU060_STRING4
    #define XCKU115_SLR1_END 9
	#define XCKU115() {                                                                           \
        XUS_SETUP_DEVICE(XCKU115_);                                                               \
        XUS_SETUP_SLRs_2(XCKU115_);                                                               \
        XUS_STRING_CAT_10(XCKU115_);                                                              \
    }


//Xilinx UltraScale Virtex
    #define XCVU065_NAME "xcvu065"
    #define XCVU065_SLRNUM 1
    #define XCVU065_ROWNUM 5
    #define XCVU065_IDCODE 0x3939093
    #define XCVU065_STRING0 "jGIMGILGILGILGIPGICGILGdkGIMGIMGIMGIPGICGIMGFMGILGICGILGIPGILGIAGIMGINGIMGIBGILGIPGILGICGIMGFabGILGICGILGIPGILGIAGIMGINGIMGIBGILGIPGILGICGIMGFMGILGICGILGIPGILGIAGIMGINGIMGIBGILGIPGILGICGIMGFcbGILGICGILGIPGILGIAGIMGINGIMGIBGILGIPGILGICGIMGFMGILGILGICGIPGICGILGdeHJKHJDHJKHJQHJKHJKHJOHf\x01"
    #define XCVU065_STRING1 "jGIMGILGILGILGIMGICGILGdlGIMGIMGIMGIMGICGIMGFMGILGICGILGIMGILGIAGIMGINGIMGIBGILGIMGILGICGIMGFabGILGICGILGIMGILGIAGIMGINGIMGIBGILGIMGILGICGIMGFMGILGICGILGIMGILGIAGIMGINGIMGIBGILGIMGILGICGIMGFabGILGICGILGIMGILGIAGIMGINGIMGIBGILGIMGILGICGIMGFMGILGILGIBGIMGIAGILGdgHJKHJDHJKHJOHJKHJKHJOHf\x01"
    #define XCVU065_STRING2 "jGIMGILGILGILGIMGICGILGdkGIMGIMGIMGIMGICGIMGFMGILGICGILGIMGILGIAGIMGINGIMGIBGILGIMGILGICGIMGFabGILGICGILGIMGILGIAGIMGINGIMGIBGILGIMGILGICGIMGFMGILGICGILGIMGILGIAGIMGINGIMGIBGILGIMGILGICGIMGFabGILGICGILGIMGILGIAGIMGINGIMGIBGILGIMGILGICGIMGFMGILGILGIBGIMGIAGILGdhHJKHJDHJKHJOHJKHJKHJOHf\x01"
    #define XCVU065_STRING3 "jGIMGILGILGILGIMGICGILGdlGIMGIMGIMGIMGICGIMGFMGILGICGILGIMGILGIAGIMGINGIMGIBGILGIMGILGICGIMGFabGILGICGILGIMGILGIAGIMGINGIMGIBGILGIMGILGICGIMGFMGILGICGILGIMGILGIAGIMGINGIMGIBGILGIMGILGICGIMGFabGILGICGILGIMGILGIAGIMGINGIMGIBGILGIMGILGICGIMGFMGILGILGIBGIMGIAGILGdkHJKHJDHJKHJOHJKHJKHJOHf\x01"
    #define XCVU065_STRING4 "jGIMGILGILGILGIPGICGILGdlGIMGIMGIMGIPGICGIMGFMGILGICGILGIPGILGIAGIMGINGIMGIBGILGIPGILGICGIMGFabGILGICGILGIPGILGIAGIMGINGIMGIBGILGIPGILGICGIMGFMGILGICGILGIPGILGIAGIMGINGIMGIBGILGIPGILGICGIMGFabGILGICGILGIPGILGIAGIMGINGIMGIBGILGIPGILGICGIMGFMGILGILGICGIPGICGILGdeHJKHJDHJKHJQHJKHJKHJOHf\x01"
    #define XCVU065() {                                                                           \
        XUS_SETUP_DEVICE(XCVU065_);                                                               \
        XUS_STRING_CAT_5(XCVU065_);                                                               \
    }
	
	//XCVU080 is a software-limitted version of XCVU095
    #define XCVU080_NAME "xcvu080"
    #define XCVU080_SLRNUM 1
    #define XCVU080_ROWNUM 8
    #define XCVU080_IDCODE 0x3843093
    #define XCVU080_STRING0 XCKU095_STRING0
    #define XCVU080_STRING1 XCKU095_STRING1
    #define XCVU080_STRING2 XCKU095_STRING2
    #define XCVU080_STRING3 XCKU095_STRING3
    #define XCVU080_STRING4 XCKU095_STRING4
    #define XCVU080_STRING5 XCKU095_STRING5
    #define XCVU080_STRING6 XCKU095_STRING6
    #define XCVU080_STRING7 XCKU095_STRING7
    #define XCVU080() {                                                                           \
        XUS_SETUP_DEVICE(XCVU080_);                                                               \
        XUS_STRING_CAT_8(XCVU080_);                                                               \
    }
	
    #define XCVU095_NAME "xcvu095"
    #define XCVU095_SLRNUM 1
    #define XCVU095_ROWNUM 8
    #define XCVU095_IDCODE 0x3842093
    #define XCVU095_STRING0 XCKU095_STRING0
    #define XCVU095_STRING1 XCKU095_STRING1
    #define XCVU095_STRING2 XCKU095_STRING2
    #define XCVU095_STRING3 XCKU095_STRING3
    #define XCVU095_STRING4 XCKU095_STRING4
    #define XCVU095_STRING5 XCKU095_STRING5
    #define XCVU095_STRING6 XCKU095_STRING6
    #define XCVU095_STRING7 XCKU095_STRING7
    #define XCVU095() {                                                                           \
        XUS_SETUP_DEVICE(XCVU095_);                                                               \
        XUS_STRING_CAT_8(XCVU095_);                                                               \
    }
	
	//Made of 2 XCVU065 dies
    #define XCVU125_NAME "xcvu125"
    #define XCVU125_SLRNUM 2
    #define XCVU125_ROWNUM 10
    #define XCVU125_IDCODE 0x392D093
    #define XCVU125_IDCODE1 0x3922093
    #define XCVU125_SLR0_START 0
    #define XCVU125_STRING0 XCVU065_STRING0
    #define XCVU125_STRING1 XCVU065_STRING1
    #define XCVU125_STRING2 XCVU065_STRING2
    #define XCVU125_STRING3 XCVU065_STRING3
    #define XCVU125_STRING4 XCVU065_STRING4
    #define XCVU125_SLR0_END 4
	#define XCVU125_SLR1_START 5
	#define XCVU125_STRING5 XCVU065_STRING0
    #define XCVU125_STRING6 XCVU065_STRING1
    #define XCVU125_STRING7 XCVU065_STRING2
    #define XCVU125_STRING8 XCVU065_STRING3
    #define XCVU125_STRING9 XCVU065_STRING4
    #define XCVU125_SLR1_END 9
    #define XCVU125() {                                                                           \
        XUS_SETUP_DEVICE(XCVU125_);                                                               \
        XUS_SETUP_SLRs_2(XCVU125_);                                                               \
        XUS_STRING_CAT_10(XCVU125_);                                                              \
    }
	
	//XCVU160 is a software-limitted version of XCVU190 with one die missing a row
    #define XCVU160_NAME "xcvu160"
    #define XCVU160_SLRNUM 3
    #define XCVU160_ROWNUM 14
    #define XCVU160_IDCODE 0x3933093
    #define XCVU160_IDCODE1 0x3922093
    #define XCVU160_IDCODE2 0x3924093
    #define XCVU160_SLR1_START 0
    #define XCVU160_STRING0 XCVU065_STRING1
    #define XCVU160_STRING1 XCVU065_STRING2
    #define XCVU160_STRING2 XCVU065_STRING3
    #define XCVU160_STRING3 XCVU065_STRING4
    #define XCVU160_SLR1_END 3
    #define XCVU160_SLR0_START 4
	#define XCVU160_STRING4 XCVU065_STRING0
    #define XCVU160_STRING5 XCVU065_STRING1
    #define XCVU160_STRING6 XCVU065_STRING2
    #define XCVU160_STRING7 XCVU065_STRING3
    #define XCVU160_STRING8 XCVU065_STRING4
    #define XCVU160_SLR0_END 8
	#define XCVU160_SLR2_START 9
	#define XCVU160_STRING9 XCVU065_STRING0
    #define XCVU160_STRING10 XCVU065_STRING1 
    #define XCVU160_STRING11 XCVU065_STRING2 
    #define XCVU160_STRING12 XCVU065_STRING3 
    #define XCVU160_STRING13 XCVU065_STRING4 
    #define XCVU160_SLR2_END 13
	#define XCVU160() {                                                                           \
        XUS_SETUP_DEVICE(XCVU160_);                                                               \
        XUS_SETUP_SLRs_3(XCVU160_);                                                               \
        XUS_STRING_CAT_14(XCVU160_);                                                              \
    }
	
	//Made of 3 XCVU065 dies
    #define XCVU190_NAME "xcvu190"
    #define XCVU190_SLRNUM 3
    #define XCVU190_ROWNUM 15
    #define XCVU190_IDCODE 0x3931093
    #define XCVU190_IDCODE1 0x3922093
    #define XCVU190_IDCODE2 0x3924093
	#define XCVU190_SLR1_START 0
    #define XCVU190_STRING0 XCVU065_STRING0
    #define XCVU190_STRING1 XCVU065_STRING1
    #define XCVU190_STRING2 XCVU065_STRING2
    #define XCVU190_STRING3 XCVU065_STRING3
    #define XCVU190_STRING4 XCVU065_STRING4
    #define XCVU190_SLR1_END 4
    #define XCVU190_SLR0_START 5
	#define XCVU190_STRING5 XCVU065_STRING0
    #define XCVU190_STRING6 XCVU065_STRING1
    #define XCVU190_STRING7 XCVU065_STRING2
    #define XCVU190_STRING8 XCVU065_STRING3
    #define XCVU190_STRING9 XCVU065_STRING4
    #define XCVU190_SLR0_END 9
	#define XCVU190_SLR2_START 10
	#define XCVU190_STRING10 XCVU065_STRING0 
    #define XCVU190_STRING11 XCVU065_STRING1 
    #define XCVU190_STRING12 XCVU065_STRING2 
    #define XCVU190_STRING13 XCVU065_STRING3 
    #define XCVU190_STRING14 XCVU065_STRING4 
    #define XCVU190_SLR2_END 14
	#define XCVU190() {                                                                           \
        XUS_SETUP_DEVICE(XCVU190_);                                                               \
        XUS_SETUP_SLRs_3(XCVU190_);                                                               \
        XUS_STRING_CAT_15(XCVU190_);                                                              \
    }
	
    #define XCVU440_NAME "xcvu440"
    #define XCVU440_SLRNUM 3
    #define XCVU440_ROWNUM 15
    #define XCVU440_IDCODE 0x396D093
    #define XCVU440_IDCODE1 0x3962093
    #define XCVU440_IDCODE2 0x3964093
	#define XCVU440_SLR1_START 0
    #define XCVU440_STRING0 "abGIMGILGIAGIPGILGILGIMGILGILGINGILGILGIMGILGILGIPGILGILGIBGIMGFMGIMGILGICGIPGILGILGIMGILGILGINGILGILGIMGILGILGIPGILGILGIMGILGILGIMGFMGIMGILGICGIPGILGILGIMGILGILGINGILGILGIMGILGILGIPGILGILGIMGILGILGIMGFMGIMGILGICGIPGILGILGIMGILGILGINGILGILGIMGILGILGIPGILGILGIMGILGILGIMGFMGIMGILGIAGIPGILGILGIMGILGILGINGILGILGIMGILGILGIPGILGILGIBGIMGFMGIMGILGICGIPGILGILGIMGILGILGINGILGILGIMGILGILGIPGILGILGIMGILGILGIMGFMGIMGILGICGIPGILGILGIMGILGILGINGILGILGIMGILGILGIPGILGILGIMGILGILGIMGFcbGIMGILGIAGIPGILGILGIMGILGILGINGILGILGIMGILGILGIPGILGILGIBGIMGFMGILGILGICGIPGICGILGdeHJKHJDHJKHJQHJKHJKHJOHf\x01"
    #define XCVU440_STRING1 "abGIMGILGIAGIMGILGILGIMGILGILGINGILGILGIMGILGILGIMGILGILGIBGIMGFMGIMGILGICGIMGILGILGIMGILGILGINGILGILGIMGILGILGIMGILGILGIMGILGILGIMGFMGIMGILGICGIMGILGILGIMGILGILGINGILGILGIMGILGILGIMGILGILGIMGILGILGIMGFMGIMGILGICGIMGILGILGIMGILGILGINGILGILGIMGILGILGIMGILGILGIMGILGILGIMGFMGIMGILGIAGIMGILGILGIMGILGILGINGILGILGIMGILGILGIMGILGILGIBGIMGFMGIMGILGICGIMGILGILGIMGILGILGINGILGILGIMGILGILGIMGILGILGIMGILGILGIMGFMGIMGILGICGIMGILGILGIMGILGILGINGILGILGIMGILGILGIMGILGILGIMGILGILGIMGFabGIMGILGIAGIMGILGILGIMGILGILGINGILGILGIMGILGILGIMGILGILGIBGIMGFMGILGILGIBGIMGIAGILGdgHJKHJDHJKHJOHJKHJKHJOHf\x01"
    #define XCVU440_STRING2 "abGIMGILGIAGIMGILGILGIMGILGILGINGILGILGIMGILGILGIMGILGILGIBGIMGFMGIMGILGICGIMGILGILGIMGILGILGINGILGILGIMGILGILGIMGILGILGIMGILGILGIMGFMGIMGILGICGIMGILGILGIMGILGILGINGILGILGIMGILGILGIMGILGILGIMGILGILGIMGFMGIMGILGICGIMGILGILGIMGILGILGINGILGILGIMGILGILGIMGILGILGIMGILGILGIMGFMGIMGILGIAGIMGILGILGIMGILGILGINGILGILGIMGILGILGIMGILGILGIBGIMGFMGIMGILGICGIMGILGILGIMGILGILGINGILGILGIMGILGILGIMGILGILGIMGILGILGIMGFMGIMGILGICGIMGILGILGIMGILGILGINGILGILGIMGILGILGIMGILGILGIMGILGILGIMGFabGIMGILGIAGIMGILGILGIMGILGILGINGILGILGIMGILGILGIMGILGILGIBGIMGFMGILGILGIBGIMGIAGILGdhHJKHJDHJKHJOHJKHJKHJOHf\x01"
    #define XCVU440_STRING3 "abGIMGILGIAGIMGILGILGIMGILGILGINGILGILGIMGILGILGIMGILGILGIBGIMGFMGIMGILGICGIMGILGILGIMGILGILGINGILGILGIMGILGILGIMGILGILGIMGILGILGIMGFMGIMGILGICGIMGILGILGIMGILGILGINGILGILGIMGILGILGIMGILGILGIMGILGILGIMGFMGIMGILGICGIMGILGILGIMGILGILGINGILGILGIMGILGILGIMGILGILGIMGILGILGIMGFMGIMGILGIAGIMGILGILGIMGILGILGINGILGILGIMGILGILGIMGILGILGIBGIMGFMGIMGILGICGIMGILGILGIMGILGILGINGILGILGIMGILGILGIMGILGILGIMGILGILGIMGFMGIMGILGICGIMGILGILGIMGILGILGINGILGILGIMGILGILGIMGILGILGIMGILGILGIMGFabGIMGILGIAGIMGILGILGIMGILGILGINGILGILGIMGILGILGIMGILGILGIBGIMGFMGILGILGIBGIMGIAGILGdlHJKHJDHJKHJOHJKHJKHJOHf\x01"
    #define XCVU440_STRING4 "abGIMGILGIAGIPGILGILGIMGILGILGINGILGILGIMGILGILGIPGILGILGIBGIMGFMGIMGILGICGIPGILGILGIMGILGILGINGILGILGIMGILGILGIPGILGILGIMGILGILGIMGFMGIMGILGICGIPGILGILGIMGILGILGINGILGILGIMGILGILGIPGILGILGIMGILGILGIMGFMGIMGILGICGIPGILGILGIMGILGILGINGILGILGIMGILGILGIPGILGILGIMGILGILGIMGFMGIMGILGIAGIPGILGILGIMGILGILGINGILGILGIMGILGILGIPGILGILGIBGIMGFMGIMGILGICGIPGILGILGIMGILGILGINGILGILGIMGILGILGIPGILGILGIMGILGILGIMGFMGIMGILGICGIPGILGILGIMGILGILGINGILGILGIMGILGILGIPGILGILGIMGILGILGIMGFabGIMGILGIAGIPGILGILGIMGILGILGINGILGILGIMGILGILGIPGILGILGIBGIMGFMGILGILGICGIPGICGILGdeHJKHJDHJKHJQHJKHJKHJOHf\x01"
    #define XCVU440_SLR1_END 4
    #define XCVU440_SLR0_START 5
	#define XCVU440_STRING5 XCVU440_STRING0
    #define XCVU440_STRING6 XCVU440_STRING1
    #define XCVU440_STRING7 XCVU440_STRING2
    #define XCVU440_STRING8 XCVU440_STRING3
    #define XCVU440_STRING9 XCVU440_STRING4
    #define XCVU440_SLR0_END 9
	#define XCVU440_SLR2_START 10
	#define XCVU440_STRING10 XCVU440_STRING0 
    #define XCVU440_STRING11 XCVU440_STRING1 
    #define XCVU440_STRING12 XCVU440_STRING2 
    #define XCVU440_STRING13 XCVU440_STRING3 
    #define XCVU440_STRING14 XCVU440_STRING4 
    #define XCVU440_SLR2_END 14
	#define XCVU440() {                                                                           \
        XUS_SETUP_DEVICE(XCVU440_);                                                               \
        XUS_SETUP_SLRs_3(XCVU440_);                                                               \
        XUS_STRING_CAT_15(XCVU440_);                                                              \
    }

#endif // XILINXULTRASCALEDEVICES_H
