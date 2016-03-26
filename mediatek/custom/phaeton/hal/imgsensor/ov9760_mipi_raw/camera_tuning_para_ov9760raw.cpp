#include <utils/Log.h>
#include <fcntl.h>
#include <math.h>

#include "camera_custom_nvram.h"
#include "camera_custom_sensor.h"
#include "image_sensor.h"
#include "kd_imgsensor_define.h"
#include "camera_AE_PLineTable_ov9760raw.h"
#include "camera_info_ov9760raw.h"
#include "camera_custom_AEPlinetable.h"
#include "camera_custom_tsf_tbl.h"
const NVRAM_CAMERA_ISP_PARAM_STRUCT CAMERA_ISP_DEFAULT_VALUE =
{{
    //Version
    Version: NVRAM_CAMERA_PARA_FILE_VERSION,
    //SensorId
    SensorId: SENSOR_ID,
    ISPComm:{
        {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        }
    },
    ISPPca:{
        #include INCLUDE_FILENAME_ISP_PCA_PARAM
    },
    ISPRegs:{
        #include INCLUDE_FILENAME_ISP_REGS_PARAM
        },
    ISPMfbMixer:{{
        {//00: MFB mixer for ISO 100
            0x00000000, 0x00000000
        },
        {//01: MFB mixer for ISO 200
            0x00000000, 0x00000000
        },
        {//02: MFB mixer for ISO 400
            0x00000000, 0x00000000
        },
        {//03: MFB mixer for ISO 800
            0x00000000, 0x00000000
        },
        {//04: MFB mixer for ISO 1600
            0x00000000, 0x00000000
        },
        {//05: MFB mixer for ISO 2400
            0x00000000, 0x00000000
        },
        {//06: MFB mixer for ISO 3200
            0x00000000, 0x00000000
        }
    }},
    ISPCcmPoly22:{
        62040,    // i4R_AVG
        18067,    // i4R_STD
        108140,    // i4B_AVG
        26975,    // i4B_STD
        {  // i4P00[9]
            4670000, -1924000, -186000, -572000, 3392000, -258000, 114000, -2338000, 4782000
        },
        {  // i4P10[9]
            1040853, -1119416, 78563, -22725, -307964, 329893, 55645, 500559, -553786
        },
        {  // i4P01[9]
            667328, -817215, 149887, -103281, -263338, 367538, 16911, -326899, 309593
        },
        {  // i4P20[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
        },
        {  // i4P11[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
        },
        {  // i4P02[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
        }
    }
}};

const NVRAM_CAMERA_3A_STRUCT CAMERA_3A_NVRAM_DEFAULT_VALUE =
{
    NVRAM_CAMERA_3A_FILE_VERSION, // u4Version
    SENSOR_ID, // SensorId

    // AE NVRAM
    {
        // rDevicesInfo
        {
            1136,    // u4MinGain, 1024 base = 1x
            16384,    // u4MaxGain, 16x
            140,    // u4MiniISOGain, ISOxx  
            32,    // u4GainStepUnit, 1x/8 
            28934,    // u4PreExpUnit 
            30,    // u4PreMaxFrameRate
            28934,    // u4VideoExpUnit  
            30,    // u4VideoMaxFrameRate 
            1024,    // u4Video2PreRatio, 1024 base = 1x 
            28934,    // u4CapExpUnit 
            30,    // u4CapMaxFrameRate
            1024,    // u4Cap2PreRatio, 1024 base = 1x
            24,    // u4LensFno, Fno = 2.8
            235    // u4FocusLength_100x
        },
        // rHistConfig
        {
            2,    // u4HistHighThres
            40,    // u4HistLowThres
            2,    // u4MostBrightRatio
            1,    // u4MostDarkRatio
            160,    // u4CentralHighBound
            20,    // u4CentralLowBound
            {240, 230, 220, 210, 200},    // u4OverExpThres[AE_CCT_STRENGTH_NUM] 
            {75, 108, 128, 148, 170},    // u4HistStretchThres[AE_CCT_STRENGTH_NUM] 
            {18, 22, 26, 30, 34}    // u4BlackLightThres[AE_CCT_STRENGTH_NUM] 
        },
        // rCCTConfig
        {
            TRUE,    // bEnableBlackLight
            TRUE,    // bEnableHistStretch
            FALSE,    // bEnableAntiOverExposure
            TRUE,    // bEnableTimeLPF
            TRUE,    // bEnableCaptureThres
            TRUE,    // bEnableVideoThres
            TRUE,    // bEnableStrobeThres
            48,    // u4AETarget
            0,    // u4StrobeAETarget
            45,    // u4InitIndex
            4,    // u4BackLightWeight
            32,    // u4HistStretchWeight
            4,    // u4AntiOverExpWeight
            2,    // u4BlackLightStrengthIndex
            0,    // u4HistStretchStrengthIndex
            2,    // u4AntiOverExpStrengthIndex
            2,    // u4TimeLPFStrengthIndex
            {1, 3, 5, 7, 8},    // u4LPFConvergeTable[AE_CCT_STRENGTH_NUM] 
            90,    // u4InDoorEV = 9.0, 10 base 
            -15,    // i4BVOffset delta BV = value/10 
            64,    // u4PreviewFlareOffset
            64,    // u4CaptureFlareOffset
            5,    // u4CaptureFlareThres
            64,    // u4VideoFlareOffset
            5,    // u4VideoFlareThres
            64,    // u4StrobeFlareOffset
            2,    // u4StrobeFlareThres
            8,    // u4PrvMaxFlareThres
            0,    // u4PrvMinFlareThres
            8,    // u4VideoMaxFlareThres
            0,    // u4VideoMinFlareThres
            18,    // u4FlatnessThres    // 10 base for flatness condition.
            58    // u4FlatnessStrength
        }
    },
    // AWB NVRAM
    {
        // AWB calibration data
        {
            // rUnitGain (unit gain: 1.0 = 512)
            {
                0,    // i4R
                0,    // i4G
                0    // i4B
            },
            // rGoldenGain (golden sample gain: 1.0 = 512)
            {
                0,    // i4R
                0,    // i4G
                0    // i4B
            },
            // rTuningUnitGain (Tuning sample unit gain: 1.0 = 512)
            {
                0,    // i4R
                0,    // i4G
                0    // i4B
            },
            // rD65Gain (D65 WB gain: 1.0 = 512)
            {
                807,    // i4R
                512,    // i4G
                673    // i4B
            }
        },
        // Original XY coordinate of AWB light source
        {
           // Strobe
            {
                67,    // i4X
                -269    // i4Y
            },
            // Horizon
            {
                -456,    // i4X
                -269    // i4Y
            },
            // A
            {
                -370,    // i4X
                -312    // i4Y
            },
            // TL84
            {
                -240,    // i4X
                -299    // i4Y
            },
            // CWF
            {
                -169,    // i4X
                -421    // i4Y
            },
            // DNP
            {
                -41,    // i4X
                -350    // i4Y
            },
            // D65
            {
                67,    // i4X
                -269    // i4Y
            },
            // DF
            {
                21,    // i4X
                -379    // i4Y
            }
        },
        // Rotated XY coordinate of AWB light source
        {
            // Strobe
            {
                53,    // i4X
                -272    // i4Y
            },
            // Horizon
            {
                -470,    // i4X
                -246    // i4Y
            },
            // A
            {
                -386,    // i4X
                -293    // i4Y
            },
            // TL84
            {
                -255,    // i4X
                -287    // i4Y
            },
            // CWF
            {
                -190,    // i4X
                -412    // i4Y
            },
            // DNP
            {
                -59,    // i4X
                -348    // i4Y
            },
            // D65
            {
                53,    // i4X
                -272    // i4Y
            },
            // DF
            {
                2,    // i4X
                -380    // i4Y
            }
        },
        // AWB gain of AWB light source
        {
            // Strobe 
            {
                807,    // i4R
                512,    // i4G
                673    // i4B
            },
            // Horizon 
            {
                512,    // i4R
                659,    // i4G
                1758    // i4B
            },
            // A 
            {
                512,    // i4R
                554,    // i4G
                1393    // i4B
            },
            // TL84 
            {
                555,    // i4R
                512,    // i4G
                1063    // i4B
            },
            // CWF 
            {
                719,    // i4R
                512,    // i4G
                1138    // i4B
            },
            // DNP 
            {
                778,    // i4R
                512,    // i4G
                870    // i4B
            },
            // D65 
            {
                807,    // i4R
                512,    // i4G
                673    // i4B
            },
            // DF 
            {
                880,    // i4R
                512,    // i4G
                831    // i4B
            }
        },
        // Rotation matrix parameter
        {
            3,    // i4RotationAngle
            256,    // i4Cos
            13    // i4Sin
        },
        // Daylight locus parameter
        {
            -141,    // i4SlopeNumerator
            128    // i4SlopeDenominator
        },
        // AWB light area
        {
            // Strobe:FIXME
            {
            0,    // i4RightBound
            0,    // i4LeftBound
            0,    // i4UpperBound
            0    // i4LowerBound
            },
            // Tungsten
            {
            -305,    // i4RightBound
            -955,    // i4LeftBound
            -219,    // i4UpperBound
            -319    // i4LowerBound
            },
            // Warm fluorescent
            {
            -305,    // i4RightBound
            -955,    // i4LeftBound
            -319,    // i4UpperBound
            -439    // i4LowerBound
            },
            // Fluorescent
            {
            -109,    // i4RightBound
            -305,    // i4LeftBound
            -205,    // i4UpperBound
            -349    // i4LowerBound
            },
            // CWF
            {
            -109,    // i4RightBound
            -305,    // i4LeftBound
            -349,    // i4UpperBound
            -462    // i4LowerBound
            },
            // Daylight
            {
            118,    // i4RightBound
            -109,    // i4LeftBound
            -192,    // i4UpperBound
            -373    // i4LowerBound
            },
            // Shade
            {
            438,    // i4RightBound
            118,    // i4LeftBound
            -192,    // i4UpperBound
            -373    // i4LowerBound
            },
            // Daylight Fluorescent
            {
            118,    // i4RightBound
            -109,    // i4LeftBound
            -373,    // i4UpperBound
            -462    // i4LowerBound
            }
        },
        // PWB light area
        {
            // Reference area
            {
            438,    // i4RightBound
            -955,    // i4LeftBound
            0,    // i4UpperBound
            -462    // i4LowerBound
            },
            // Daylight
            {
            133,    // i4RightBound
            -109,    // i4LeftBound
            -192,    // i4UpperBound
            -373    // i4LowerBound
            },
            // Cloudy daylight
            {
            233,    // i4RightBound
            58,    // i4LeftBound
            -192,    // i4UpperBound
            -373    // i4LowerBound
            },
            // Shade
            {
            333,    // i4RightBound
            58,    // i4LeftBound
            -192,    // i4UpperBound
            -373    // i4LowerBound
            },
            // Twilight
            {
            -109,    // i4RightBound
            -269,    // i4LeftBound
            -192,    // i4UpperBound
            -373    // i4LowerBound
            },
            // Fluorescent
            {
            103,    // i4RightBound
            -355,    // i4LeftBound
            -222,    // i4UpperBound
            -462    // i4LowerBound
            },
            // Warm fluorescent
            {
            -286,    // i4RightBound
            -486,    // i4LeftBound
            -222,    // i4UpperBound
            -462    // i4LowerBound
            },
            // Incandescent
            {
            -286,    // i4RightBound
            -486,    // i4LeftBound
            -192,    // i4UpperBound
            -373    // i4LowerBound
            },
            // Gray World
            {
            5000,    // i4RightBound
            -5000,    // i4LeftBound
            5000,    // i4UpperBound
            -5000    // i4LowerBound
            }
        },
        // PWB default gain	
        {
            // Daylight
            {
            776,    // i4R
            512,    // i4G
            723    // i4B
            },
            // Cloudy daylight
            {
            921,    // i4R
            512,    // i4G
            598    // i4B
            },
            // Shade
            {
            982,    // i4R
            512,    // i4G
            557    // i4B
            },
            // Twilight
            {
            600,    // i4R
            512,    // i4G
            962    // i4B
            },
            // Fluorescent
            {
            708,    // i4R
            512,    // i4G
            949    // i4B
            },
            // Warm fluorescent
            {
            507,    // i4R
            512,    // i4G
            1372    // i4B
            },
            // Incandescent
            {
            466,    // i4R
            512,    // i4G
            1272    // i4B
            },
            // Gray World
            {
            512,    // i4R
            512,    // i4G
            512    // i4B
            }
        },
        // AWB preference color	
        {
            // Tungsten
            {
            0,    // i4SliderValue
            6725    // i4OffsetThr
            },
            // Warm fluorescent	
            {
            0,    // i4SliderValue
            5883    // i4OffsetThr
            },
            // Shade
            {
            0,    // i4SliderValue
            1750    // i4OffsetThr
            },
            // Daylight WB gain
            {
            864,    // i4R
            512,    // i4G
            839    // i4B
            },
            // Preference gain: strobe
            {
            512,    // i4R
            512,    // i4G
            512    // i4B
            },
            // Preference gain: tungsten
            {
            512,    // i4R
            512,    // i4G
            512    // i4B
            },
            // Preference gain: warm fluorescent
            {
            512,    // i4R
            512,    // i4G
            512    // i4B
            },
            // Preference gain: fluorescent
            {
            512,    // i4R
            512,    // i4G
            512    // i4B
            },
            // Preference gain: CWF
            {
            512,    // i4R
            512,    // i4G
            512    // i4B
            },
            // Preference gain: daylight
            {
            512,    // i4R
            512,    // i4G
            512    // i4B
            },
            // Preference gain: shade
            {
            512,    // i4R
            512,    // i4G
            512    // i4B
            },
            // Preference gain: daylight fluorescent
            {
            512,    // i4R
            512,    // i4G
            512    // i4B
            }
        },
        {// CCT estimation
            {// CCT
                2300,    // i4CCT[0]
                2850,    // i4CCT[1]
                4100,    // i4CCT[2]
                5100,    // i4CCT[3]
                6500    // i4CCT[4]
            },
            {// Rotated X coordinate
                -523,    // i4RotatedXCoordinate[0]
                -439,    // i4RotatedXCoordinate[1]
                -308,    // i4RotatedXCoordinate[2]
                -112,    // i4RotatedXCoordinate[3]
                0    // i4RotatedXCoordinate[4]
            }
        }
    },
    {0}
};

#include INCLUDE_FILENAME_ISP_LSC_PARAM
//};  //  namespace

const CAMERA_TSF_TBL_STRUCT CAMERA_TSF_DEFAULT_VALUE =
{
    #include INCLUDE_FILENAME_TSF_PARA
    #include INCLUDE_FILENAME_TSF_DATA
};


typedef NSFeature::RAWSensorInfo<SENSOR_ID> SensorInfoSingleton_T;


namespace NSFeature {
template <>
UINT32
SensorInfoSingleton_T::
impGetDefaultData(CAMERA_DATA_TYPE_ENUM const CameraDataType, VOID*const pDataBuf, UINT32 const size) const
{
    UINT32 dataSize[CAMERA_DATA_TYPE_NUM] = {sizeof(NVRAM_CAMERA_ISP_PARAM_STRUCT),
                                             sizeof(NVRAM_CAMERA_3A_STRUCT),
                                             sizeof(NVRAM_CAMERA_SHADING_STRUCT),
                                             sizeof(NVRAM_LENS_PARA_STRUCT),
                                             sizeof(AE_PLINETABLE_T),
                                             0,
                                             sizeof(CAMERA_TSF_TBL_STRUCT)};

    if (CameraDataType > CAMERA_DATA_TSF_TABLE || NULL == pDataBuf || (size < dataSize[CameraDataType]))
    {
        return 1;
    }

    switch(CameraDataType)
    {
        case CAMERA_NVRAM_DATA_ISP:
            memcpy(pDataBuf,&CAMERA_ISP_DEFAULT_VALUE,sizeof(NVRAM_CAMERA_ISP_PARAM_STRUCT));
            break;
        case CAMERA_NVRAM_DATA_3A:
            memcpy(pDataBuf,&CAMERA_3A_NVRAM_DEFAULT_VALUE,sizeof(NVRAM_CAMERA_3A_STRUCT));
            break;
        case CAMERA_NVRAM_DATA_SHADING:
            memcpy(pDataBuf,&CAMERA_SHADING_DEFAULT_VALUE,sizeof(NVRAM_CAMERA_SHADING_STRUCT));
            break;
        case CAMERA_DATA_AE_PLINETABLE:
            memcpy(pDataBuf,&g_PlineTableMapping,sizeof(AE_PLINETABLE_T));
            break;
        case CAMERA_DATA_TSF_TABLE:
            memcpy(pDataBuf,&CAMERA_TSF_DEFAULT_VALUE,sizeof(CAMERA_TSF_TBL_STRUCT));
            break;
        default:
            break;
    }
    return 0;
}}; // NSFeature


