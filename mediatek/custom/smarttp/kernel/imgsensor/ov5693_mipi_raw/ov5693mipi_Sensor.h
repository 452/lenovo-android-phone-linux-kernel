/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 */




/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   OV5693mipi_Sensor.h
 *
 * Project:
 * --------
 *   ALPS
 *
 * Description:
 * ------------
 *   CMOS sensor header file
 *
 ****************************************************************************/
#ifndef _OV5693MIPI_SENSOR_H
#define _OV5693MIPI_SENSOR_H

#define OV5693MIPI_FACTORY_START_ADDR 0
#define OV5693MIPI_ENGINEER_START_ADDR 10
 
typedef enum OV5693MIPI_group_enum
{
  OV5693MIPI_PRE_GAIN = 0,
  OV5693MIPI_CMMCLK_CURRENT,
  OV5693MIPI_FRAME_RATE_LIMITATION,
  OV5693MIPI_REGISTER_EDITOR,
  OV5693MIPI_GROUP_TOTAL_NUMS
} OV5693MIPI_FACTORY_GROUP_ENUM;

typedef enum OV5693MIPI_register_index
{
  OV5693MIPI_SENSOR_BASEGAIN = OV5693MIPI_FACTORY_START_ADDR,
  OV5693MIPI_PRE_GAIN_R_INDEX,
  OV5693MIPI_PRE_GAIN_Gr_INDEX,
  OV5693MIPI_PRE_GAIN_Gb_INDEX,
  OV5693MIPI_PRE_GAIN_B_INDEX,
  OV5693MIPI_FACTORY_END_ADDR
} OV5693MIPI_FACTORY_REGISTER_INDEX;

typedef enum OV5693MIPI_engineer_index
{
  OV5693MIPI_CMMCLK_CURRENT_INDEX = OV5693MIPI_ENGINEER_START_ADDR,
  OV5693MIPI_ENGINEER_END
} OV5693MIPI_FACTORY_ENGINEER_INDEX;

typedef struct _sensor_data_struct
{
  SENSOR_REG_STRUCT reg[OV5693MIPI_ENGINEER_END];
  SENSOR_REG_STRUCT cct[OV5693MIPI_FACTORY_END_ADDR];
} sensor_data_struct;


#define VIDEO_720P
//#define VIDEO_1080P

/* SENSOR PREVIEW/CAPTURE VT CLOCK */
#define OV5693MIPI_PREVIEW_CLK                      160000000
#define OV5693MIPI_CAPTURE_CLK                      160000000
#define OV5693MIPI_VIDEO_CLK                        160000000


/* Data Format */
#define OV5693MIPI_COLOR_FORMAT                     SENSOR_OUTPUT_FORMAT_RAW_B


#define OV5693MIPI_MIN_ANALOG_GAIN                  1   /* 1x */
#define OV5693MIPI_MAX_ANALOG_GAIN                  32  /* 32x */

#define OV5693MIPI_FULL_START_X                    (2)
#define OV5693MIPI_FULL_START_Y                    (2)
#define OV5693MIPI_IMAGE_SENSOR_FULL_WIDTH         (2560)
#define OV5693MIPI_IMAGE_SENSOR_FULL_HEIGHT        (1920)

#define OV5693MIPI_PV_START_X                      (2)
#define OV5693MIPI_PV_START_Y                      (2)
#define OV5693MIPI_IMAGE_SENSOR_PV_WIDTH           (1280)//(2560)
#define OV5693MIPI_IMAGE_SENSOR_PV_HEIGHT          (960)//(1920)


#ifdef VIDEO_720P
    #define OV5693MIPI_VIDEO_START_X                   (2)
    #define OV5693MIPI_VIDEO_START_Y                   (2)
    #define OV5693MIPI_IMAGE_SENSOR_VIDEO_WIDTH        (1280 - 8)
    #define OV5693MIPI_IMAGE_SENSOR_VIDEO_HEIGHT       (720 - 6)
#elif defined VIDEO_1080P
    #define OV5693MIPI_VIDEO_START_X                   (2)
    #define OV5693MIPI_VIDEO_START_Y                   (2)
    #define OV5693MIPI_IMAGE_SENSOR_VIDEO_WIDTH        (1920 - 8)
    #define OV5693MIPI_IMAGE_SENSOR_VIDEO_HEIGHT       (1080 - 6)
#else
    #define OV5693MIPI_VIDEO_START_X                   (2)
    #define OV5693MIPI_VIDEO_START_Y                   (2)
    #define OV5693MIPI_IMAGE_SENSOR_VIDEO_WIDTH        (2560)
    #define OV5693MIPI_IMAGE_SENSOR_VIDEO_HEIGHT       (1920)
#endif


/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
#define OV5693MIPI_FULL_PERIOD_PIXEL_NUMS          (2688) /* 30 fps */
#define OV5693MIPI_FULL_PERIOD_LINE_NUMS           (1984)

#define OV5693MIPI_PV_PERIOD_PIXEL_NUMS            (2688) /* 30 fps */
#define OV5693MIPI_PV_PERIOD_LINE_NUMS             (1984)

#ifdef VIDEO_720P
	#define OV5693MIPI_VIDEO_PERIOD_PIXEL_NUMS         (3504) /* 30 fps */
	#define OV5693MIPI_VIDEO_PERIOD_LINE_NUMS          (1520)
#elif defined VIDEO_1080P
	#define OV5693MIPI_VIDEO_PERIOD_PIXEL_NUMS         (2688) /* 30 fps */
	#define OV5693MIPI_VIDEO_PERIOD_LINE_NUMS          (1984)
#else
	#define OV5693MIPI_VIDEO_PERIOD_PIXEL_NUMS         (2688) /* 30 fps */
	#define OV5693MIPI_VIDEO_PERIOD_LINE_NUMS          (1984)
#endif

/* SENSOR READ/WRITE ID */
#define OV5693MIPI_WRITE_ID (0x20)
#define OV5693MIPI_READ_ID  (0x21)

/* FRAME RATE UNIT */
#define OV5693MIPI_FPS(x)                          (10 * (x))


/* EXPORT FUNCTIONS */
UINT32 OV5693MIPIOpen(void);
UINT32 OV5693MIPIControl(MSDK_SCENARIO_ID_ENUM ScenarioId, MSDK_SENSOR_EXPOSURE_WINDOW_STRUCT *pImageWindow, MSDK_SENSOR_CONFIG_STRUCT *pSensorConfigData);
UINT32 OV5693MIPIFeatureControl(MSDK_SENSOR_FEATURE_ENUM FeatureId, UINT8 *pFeaturePara,UINT32 *pFeatureParaLen);
UINT32 OV5693MIPIGetInfo(MSDK_SCENARIO_ID_ENUM ScenarioId, MSDK_SENSOR_INFO_STRUCT *pSensorInfo, MSDK_SENSOR_CONFIG_STRUCT *pSensorConfigData);
UINT32 OV5693MIPIGetResolution(MSDK_SENSOR_RESOLUTION_INFO_STRUCT *pSensorResolution);
UINT32 OV5693MIPIClose(void);

#define Sleep(ms) mdelay(ms)

#endif 
