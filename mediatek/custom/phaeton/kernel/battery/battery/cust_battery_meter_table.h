#ifndef _CUST_BATTERY_METER_TABLE_H
#define _CUST_BATTERY_METER_TABLE_H

#include <mach/mt_typedefs.h>

// ============================================================
// define
// ============================================================
#define RBAT_PULL_UP_R             16900
#define RBAT_PULL_DOWN_R             27000
#define RBAT_PULL_UP_VOLT             1800



// ============================================================
// ENUM
// ============================================================

// ============================================================
// structure
// ============================================================

// ============================================================
// typedef
// ============================================================
typedef struct _BATTERY_PROFILE_STRUC
{
    kal_int32 percentage;
    kal_int32 voltage;
} BATTERY_PROFILE_STRUC, *BATTERY_PROFILE_STRUC_P;

typedef struct _R_PROFILE_STRUC
{
    kal_int32 resistance; // Ohm
    kal_int32 voltage;
} R_PROFILE_STRUC, *R_PROFILE_STRUC_P;

typedef enum
{
    T1_0C,
    T2_25C,
    T3_50C
} PROFILE_TEMPERATURE;

// ============================================================
// External Variables
// ============================================================

// ============================================================
// External function
// ============================================================

// ============================================================
// <DOD, Battery_Voltage> Table
// ============================================================
BATT_TEMPERATURE Batt_Temperature_Table[] = {
{-20, 67790},
{-15, 53460},
{-10, 42450},
{-5, 33930},
{0, 27280},
{5, 22070},
{10, 17960},
{15, 14700},
{20, 12090},
{25, 10000},
{30, 8312},
{35, 6942},
{40, 5826},
{45, 4911},
{50, 4158},
{55, 3536},
{60, 3019}
};

// T0 -10C
BATTERY_PROFILE_STRUC battery_profile_t0[] =
{
{0, 4336},
{1, 4322},
{3, 4305},
{4, 4286},
{6, 4268},
{7, 4252},
{8, 4235},
{10, 4219},
{11, 4202},
{13, 4187},
{14, 4171},
{16, 4156},
{17, 4140},
{18, 4125},
{20, 4110},
{21, 4094},
{23, 4079},
{24, 4066},
{25, 4052},
{27, 4037},
{28, 4020},
{30, 4001},
{31, 3984},
{32, 3970},
{34, 3958},
{35, 3947},
{37, 3936},
{38, 3926},
{39, 3916},
{41, 3906},
{42, 3896},
{44, 3887},
{45, 3877},
{47, 3869},
{48, 3860},
{49, 3852},
{51, 3844},
{52, 3837},
{54, 3831},
{55, 3824},
{56, 3817},
{58, 3812},
{59, 3806},
{61, 3801},
{62, 3795},
{63, 3790},
{65, 3786},
{66, 3782},
{68, 3778},
{69, 3776},
{70, 3773},
{72, 3770},
{73, 3767},
{75, 3764},
{76, 3761},
{78, 3757},
{79, 3753},
{80, 3749},
{82, 3744},
{83, 3738},
{85, 3732},
{86, 3725},
{87, 3719},
{89, 3712},
{90, 3706},
{92, 3700},
{93, 3694},
{94, 3689},
{96, 3682},
{97, 3674},
{98, 3666},
{99, 3661},
{99, 3657},
{100, 3652},
{100, 3652},
{100, 3652},
{100, 3652},
{100, 3652},
{100, 3652},
{100, 3652},
{100, 3652}
};

// T1 0C
BATTERY_PROFILE_STRUC battery_profile_t1[] =
{
{0, 4347},
{1, 4326},
{3, 4309},
{4, 4292},
{5, 4276},
{7, 4259},
{8, 4244},
{9, 4228},
{11, 4213},
{12, 4197},
{14, 4182},
{15, 4168},
{16, 4153},
{18, 4138},
{19, 4124},
{20, 4110},
{22, 4096},
{23, 4082},
{24, 4070},
{26, 4058},
{27, 4043},
{28, 4027},
{30, 4012},
{31, 3998},
{33, 3985},
{34, 3974},
{35, 3962},
{37, 3950},
{38, 3938},
{39, 3925},
{41, 3913},
{42, 3901},
{43, 3890},
{45, 3880},
{46, 3870},
{47, 3861},
{49, 3853},
{50, 3845},
{52, 3838},
{53, 3832},
{54, 3826},
{56, 3820},
{57, 3814},
{58, 3809},
{60, 3805},
{61, 3800},
{62, 3796},
{64, 3792},
{65, 3788},
{66, 3785},
{68, 3781},
{69, 3778},
{70, 3776},
{72, 3773},
{73, 3771},
{75, 3769},
{76, 3766},
{77, 3764},
{79, 3759},
{80, 3755},
{81, 3749},
{83, 3742},
{84, 3734},
{85, 3725},
{87, 3716},
{88, 3704},
{89, 3697},
{91, 3693},
{92, 3689},
{94, 3685},
{95, 3679},
{96, 3666},
{98, 3615},
{99, 3529},
{100, 3529},
{100, 3529},
{100, 3529},
{100, 3529},
{100, 3529},
{100, 3529},
{100, 3529}
};

// T2 25C
BATTERY_PROFILE_STRUC battery_profile_t2[] =
{
{0, 4335},
{1, 4315},
{3, 4297},
{4, 4281},
{5, 4265},
{7, 4249},
{8, 4234},
{9, 4218},
{11, 4203},
{12, 4188},
{14, 4173},
{15, 4159},
{16, 4144},
{18, 4129},
{19, 4116},
{20, 4101},
{22, 4088},
{23, 4074},
{24, 4061},
{26, 4048},
{27, 4035},
{28, 4023},
{30, 4010},
{31, 3999},
{32, 3988},
{34, 3977},
{35, 3966},
{36, 3956},
{38, 3945},
{39, 3934},
{41, 3922},
{42, 3908},
{43, 3894},
{45, 3880},
{46, 3869},
{47, 3859},
{49, 3851},
{50, 3844},
{51, 3836},
{53, 3830},
{54, 3824},
{55, 3818},
{57, 3813},
{58, 3808},
{59, 3803},
{61, 3798},
{62, 3794},
{64, 3790},
{65, 3786},
{66, 3782},
{68, 3779},
{69, 3775},
{70, 3772},
{72, 3769},
{73, 3766},
{74, 3763},
{76, 3759},
{77, 3754},
{78, 3747},
{80, 3742},
{81, 3737},
{82, 3730},
{84, 3721},
{85, 3713},
{86, 3704},
{88, 3691},
{89, 3687},
{91, 3685},
{92, 3682},
{93, 3680},
{95, 3675},
{96, 3651},
{97, 3588},
{99, 3496},
{100, 3496},
{100, 3496},
{100, 3496},
{100, 3496},
{100, 3496},
{100, 3496},
{100, 3496}
};

// T3 50C
BATTERY_PROFILE_STRUC battery_profile_t3[] =
{
{0, 4341},
{1, 4317},
{3, 4301},
{4, 4286},
{5, 4271},
{7, 4255},
{8, 4240},
{9, 4225},
{11, 4210},
{12, 4194},
{14, 4180},
{15, 4165},
{16, 4150},
{18, 4135},
{19, 4121},
{20, 4106},
{22, 4093},
{23, 4079},
{24, 4065},
{26, 4052},
{27, 4040},
{28, 4027},
{30, 4014},
{31, 4003},
{32, 3991},
{34, 3981},
{35, 3969},
{36, 3959},
{38, 3949},
{39, 3939},
{41, 3928},
{42, 3917},
{43, 3902},
{45, 3885},
{46, 3872},
{47, 3862},
{49, 3853},
{50, 3846},
{51, 3838},
{53, 3832},
{54, 3825},
{55, 3819},
{57, 3813},
{58, 3808},
{59, 3802},
{61, 3798},
{62, 3793},
{64, 3788},
{65, 3784},
{66, 3780},
{68, 3777},
{69, 3773},
{70, 3769},
{72, 3762},
{73, 3752},
{74, 3747},
{76, 3742},
{77, 3736},
{78, 3730},
{80, 3724},
{81, 3719},
{82, 3713},
{84, 3704},
{85, 3695},
{86, 3686},
{88, 3674},
{89, 3670},
{91, 3668},
{92, 3666},
{93, 3664},
{95, 3657},
{96, 3626},
{97, 3563},
{99, 3473},
{100, 3473},
{100, 3473},
{100, 3473},
{100, 3473},
{100, 3473},
{100, 3473},
{100, 3473}
};

// battery profile for actual temperature. The size should be the same as T1, T2 and T3
BATTERY_PROFILE_STRUC battery_profile_temperature[] =
{
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0}
};

// ============================================================
// <Rbat, Battery_Voltage> Table
// ============================================================
// T0 -10C
R_PROFILE_STRUC r_profile_t0[] =
{
{150, 4336},
{150, 4322},
{333, 4305},
{533, 4286},
{593, 4268},
{590, 4252},
{588, 4235},
{590, 4219},
{585, 4202},
{588, 4187},
{583, 4171},
{585, 4156},
{580, 4140},
{578, 4125},
{580, 4110},
{573, 4094},
{570, 4079},
{573, 4066},
{575, 4052},
{575, 4037},
{570, 4020},
{563, 4001},
{555, 3984},
{555, 3970},
{555, 3958},
{555, 3947},
{553, 3936},
{553, 3926},
{553, 3916},
{553, 3906},
{553, 3896},
{553, 3887},
{553, 3877},
{555, 3869},
{553, 3860},
{553, 3852},
{555, 3844},
{558, 3837},
{565, 3831},
{563, 3824},
{568, 3817},
{573, 3812},
{575, 3806},
{580, 3801},
{580, 3795},
{580, 3790},
{588, 3786},
{593, 3782},
{598, 3778},
{603, 3776},
{608, 3773},
{615, 3770},
{623, 3767},
{633, 3764},
{643, 3761},
{655, 3757},
{670, 3753},
{688, 3749},
{710, 3744},
{728, 3738},
{753, 3732},
{775, 3725},
{800, 3719},
{825, 3712},
{855, 3706},
{893, 3700},
{933, 3694},
{985, 3689},
{1048, 3682},
{1145, 3674},
{1165, 3666},
{1153, 3661},
{1143, 3657},
{1130, 3652},
{1130, 3652},
{1130, 3652},
{1130, 3652},
{1130, 3652},
{1130, 3652},
{1130, 3652},
{1130, 3652}
};

// T1 0C
R_PROFILE_STRUC r_profile_t1[] =
{
{243, 4347},
{243, 4326},
{263, 4309},
{263, 4292},
{265, 4276},
{265, 4259},
{268, 4244},
{270, 4228},
{273, 4213},
{273, 4197},
{275, 4182},
{278, 4168},
{280, 4153},
{280, 4138},
{285, 4124},
{285, 4110},
{288, 4096},
{290, 4082},
{293, 4070},
{298, 4058},
{298, 4043},
{298, 4027},
{298, 4012},
{298, 3998},
{295, 3985},
{278, 3974},
{280, 3962},
{278, 3950},
{273, 3938},
{268, 3925},
{263, 3913},
{258, 3901},
{253, 3890},
{250, 3880},
{248, 3870},
{245, 3861},
{245, 3853},
{245, 3845},
{243, 3838},
{245, 3832},
{248, 3826},
{248, 3820},
{245, 3814},
{248, 3809},
{250, 3805},
{250, 3800},
{253, 3796},
{253, 3792},
{253, 3788},
{255, 3785},
{255, 3781},
{255, 3778},
{258, 3776},
{258, 3773},
{258, 3771},
{260, 3769},
{263, 3766},
{268, 3764},
{268, 3759},
{270, 3755},
{270, 3749},
{275, 3742},
{275, 3734},
{278, 3725},
{288, 3716},
{293, 3704},
{300, 3697},
{313, 3693},
{330, 3689},
{353, 3685},
{385, 3679},
{433, 3666},
{458, 3615},
{518, 3529},
{823, 3529},
{823, 3529},
{823, 3529},
{823, 3529},
{823, 3529},
{823, 3529},
{823, 3529}
};

// T2 25C
R_PROFILE_STRUC r_profile_t2[] =
{
{125, 4335},
{125, 4315},
{125, 4297},
{128, 4281},
{128, 4265},
{128, 4249},
{130, 4234},
{128, 4218},
{130, 4203},
{130, 4188},
{133, 4173},
{135, 4159},
{135, 4144},
{138, 4129},
{143, 4116},
{143, 4101},
{145, 4088},
{145, 4074},
{148, 4061},
{148, 4048},
{150, 4035},
{155, 4023},
{155, 4010},
{158, 3999},
{160, 3988},
{165, 3977},
{170, 3966},
{175, 3956},
{178, 3945},
{178, 3934},
{173, 3922},
{165, 3908},
{155, 3894},
{145, 3880},
{140, 3869},
{135, 3859},
{135, 3851},
{135, 3844},
{130, 3836},
{133, 3830},
{133, 3824},
{135, 3818},
{138, 3813},
{138, 3808},
{140, 3803},
{140, 3798},
{140, 3794},
{140, 3790},
{140, 3786},
{138, 3782},
{140, 3779},
{138, 3775},
{135, 3772},
{138, 3769},
{135, 3766},
{138, 3763},
{138, 3759},
{133, 3754},
{130, 3747},
{130, 3742},
{130, 3737},
{133, 3730},
{133, 3721},
{135, 3713},
{138, 3704},
{135, 3691},
{138, 3687},
{140, 3685},
{143, 3682},
{150, 3680},
{160, 3675},
{160, 3651},
{163, 3588},
{180, 3496},
{593, 3496},
{593, 3496},
{593, 3496},
{593, 3496},
{593, 3496},
{593, 3496},
{593, 3496}
};

// T3 50C
R_PROFILE_STRUC r_profile_t3[] =
{
{103, 4341},
{103, 4317},
{103, 4301},
{105, 4286},
{105, 4271},
{105, 4255},
{105, 4240},
{105, 4225},
{108, 4210},
{105, 4194},
{108, 4180},
{108, 4165},
{108, 4150},
{108, 4135},
{108, 4121},
{105, 4106},
{110, 4093},
{110, 4079},
{108, 4065},
{110, 4052},
{113, 4040},
{110, 4027},
{110, 4014},
{113, 4003},
{113, 3991},
{118, 3981},
{115, 3969},
{120, 3959},
{123, 3949},
{128, 3939},
{130, 3928},
{133, 3917},
{128, 3902},
{113, 3885},
{108, 3872},
{108, 3862},
{105, 3853},
{108, 3846},
{103, 3838},
{105, 3832},
{105, 3825},
{105, 3819},
{105, 3813},
{108, 3808},
{105, 3802},
{108, 3798},
{108, 3793},
{108, 3788},
{108, 3784},
{110, 3780},
{113, 3777},
{113, 3773},
{115, 3769},
{110, 3762},
{103, 3752},
{108, 3747},
{108, 3742},
{108, 3736},
{105, 3730},
{105, 3724},
{108, 3719},
{108, 3713},
{108, 3704},
{108, 3695},
{110, 3686},
{103, 3674},
{103, 3670},
{108, 3668},
{110, 3666},
{120, 3664},
{128, 3657},
{118, 3626},
{120, 3563},
{133, 3473},
{528, 3473},
{528, 3473},
{528, 3473},
{528, 3473},
{528, 3473},
{528, 3473},
{528, 3473}
};

// r-table profile for actual temperature. The size should be the same as T1, T2 and T3
R_PROFILE_STRUC r_profile_temperature[] =
{
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0},
{0, 0}
};
// ============================================================
// function prototype
// ============================================================
int fgauge_get_saddles(void);
BATTERY_PROFILE_STRUC_P fgauge_get_profile(kal_uint32 temperature);

int fgauge_get_saddles_r_table(void);
R_PROFILE_STRUC_P fgauge_get_profile_r_table(kal_uint32 temperature);

#endif	//#ifndef _CUST_BATTERY_METER_TABLE_H
 