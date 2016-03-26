#ifndef _CUST_BATTERY_METER_TABLE_H
#define _CUST_BATTERY_METER_TABLE_H

#include <mach/mt_typedefs.h>

// ============================================================
// define
// ============================================================
#define BAT_NTC_10 1
#define BAT_NTC_47 0

#if (BAT_NTC_10 == 1)
#define RBAT_PULL_UP_R             16900	
//lenovo liaohj modify for hw register ajust to 30000 2013-11-22
#define RBAT_PULL_DOWN_R		   30000	
#endif

#if (BAT_NTC_47 == 1)
#define RBAT_PULL_UP_R             61900	
#define RBAT_PULL_DOWN_R		  100000	
#endif
#define RBAT_PULL_UP_VOLT          1800



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
//lenovo_sw liaohj modify for use stellap ntc registers 2013-10-28
#if 1
BATT_TEMPERATURE Batt_Temperature_Table[] = {
	{-20,67790},
	{-15,53460},
	{-10,42450},
	{ -5,33930},
	{  0,27280},
	{  5,22070},
	{ 10,17960},
	{ 15,14700},
	{ 20,12090},
	{ 25,10000},
	{ 30,8312},
	{ 35,6942},
	{ 40,5826},
	{ 45,4911},
	{ 50,4158},
	{ 55,3536},
	{ 60,3019}	
};
#else
#if (BAT_NTC_10 == 1)
    BATT_TEMPERATURE Batt_Temperature_Table[] = {
        {-20,67790},
        {-15,53460},
        {-10,42450},
        { -5,33930},
        {  0,27280},
        {  5,22070},
        { 10,17960},
        { 15,14700},
        { 20,12090},
        { 25,10000},
        { 30,8312},
        { 35,6942},
        { 40,5826},
        { 45,4911},
        { 50,4158},
        { 55,3536},
        { 60,3019}
    };
#endif

#if (BAT_NTC_47 == 1)
    BATT_TEMPERATURE Batt_Temperature_Table[] = {
        {-20,483954},
        {-15,360850},
        {-10,271697},
        { -5,206463},
        {  0,158214},
        {  5,122259},
        { 10,95227},
        { 15,74730},
        { 20,59065},
        { 25,47000},
        { 30,37643},
        { 35,30334},
        { 40,24591},
        { 45,20048},
        { 50,16433},
        { 55,13539},
        { 60,11210}        
    };
#endif
#endif

// T0 -10C
BATTERY_PROFILE_STRUC battery_profile_t0[] =
{
{	0	,	4328	},
{	2	,	4310	},
{	3	,	4287	},
{	5	,	4266	},
{	7	,	4247	},
{	9	,	4227	},
{	10	,	4208	},
{	12	,	4190	},
{	14	,	4171	},
{	15	,	4153	},
{	17	,	4135	},
{	19	,	4117	},
{	20	,	4099	},
{	22	,	4081	},
{	24	,	4064	},
{	25	,	4046	},
{	27	,	4025	},
{	29	,	4004	},
{	31	,	3984	},
{	32	,	3967	},
{	34	,	3951	},
{	36	,	3937	},
{	37	,	3924	},
{	39	,	3911	},
{	41	,	3899	},
{	43	,	3887	},
{	44	,	3877	},
{	46	,	3867	},
{	48	,	3858	},
{	49	,	3849	},
{	51	,	3840	},
{	53	,	3832	},
{	54	,	3824	},
{	56	,	3817	},
{	58	,	3811	},
{	60	,	3805	},
{	61	,	3799	},
{	63	,	3793	},
{	65	,	3788	},
{	66	,	3782	},
{	68	,	3778	},
{	70	,	3774	},
{	71	,	3768	},
{	73	,	3763	},
{	75	,	3757	},
{	77	,	3749	},
{	78	,	3741	},
{	80	,	3731	},
{	82	,	3722	},
{	83	,	3714	},
{	85	,	3707	},
{	87	,	3701	},
{	88	,	3696	},
{	90	,	3691	},
{	92	,	3682	},
{	94	,	3663	},
{	95	,	3631	},
{	96	,	3623	},
{	96	,	3618	},
{	97	,	3615	},
{	97	,	3612	},
{	97	,	3611	},
{	98	,	3609	},
{	98	,	3607	},
{	98	,	3605	},
{	98	,	3603	},
{	99	,	3600	},
{	99	,	3599	},
{	99	,	3597	},
{	99	,	3595	},
{	99	,	3594	},
{	100	,	3591	},
{	100	,	3590	},
{	100	,	3588	},
{	100	,	3588	},
{	100	,	3588	},
{	100	,	3588	},
{	100	,	3588	},
{	100	,	3588	},
{	100	,	3588	},
{	100	,	3588	}
};      
        
// T1 0C 
BATTERY_PROFILE_STRUC battery_profile_t1[] =
{
{	0	,	4271	},
{	2	,	4261	},
{	3	,	4240	},
{	5	,	4220	},
{	7	,	4201	},
{	9	,	4183	},
{	10	,	4171	},
{	12	,	4151	},
{	14	,	4134	},
{	15	,	4117	},
{	17	,	4101	},
{	19	,	4084	},
{	21	,	4066	},
{	22	,	4050	},
{	24	,	4036	},
{	26	,	4020	},
{	27	,	4003	},
{	29	,	3981	},
{	31	,	3969	},
{	33	,	3952	},
{	34	,	3932	},
{	36	,	3918	},
{	38	,	3907	},
{	39	,	3888	},
{	41	,	3879	},
{	43	,	3871	},
{	45	,	3860	},
{	46	,	3852	},
{	48	,	3840	},
{	50	,	3833	},
{	51	,	3825	},
{	53	,	3820	},
{	55	,	3814	},
{	57	,	3807	},
{	58	,	3801	},
{	60	,	3800	},
{	62	,	3794	},
{	63	,	3785	},
{	65	,	3783	},
{	67	,	3779	},
{	68	,	3773	},
{	70	,	3774	},
{	72	,	3765	},
{	74	,	3763	},
{	75	,	3756	},
{	77	,	3746	},
{	79	,	3734	},
{	80	,	3722	},
{	82	,	3713	},
{	84	,	3704	},
{	86	,	3696	},
{	87	,	3691	},
{	89	,	3692	},
{	91	,	3684	},
{	92	,	3677	},
{	94	,	3656	},
{	96	,	3608	},
{	97	,	3565	},
{	98	,	3549	},
{	98	,	3533	},
{	99	,	3520	},
{	99	,	3477	},
{	100	,	3453	},
{	100	,	3437	},
{	100	,	3426	},
{	100	,	3417	},
{	100	,	3417	},
{	100	,	3417	},
{	100	,	3417	},
{	100	,	3417	},
{	100	,	3417	},
{	100	,	3417	},
{	100	,	3417	},
{	100	,	3417	},
{	100	,	3417	},
{	100	,	3417	},
{	100	,	3417	},
{	100	,	3417	},
{	100	,	3417	},
{	100	,	3417	},
{	100	,	3417	}
};           

// T2 25C
BATTERY_PROFILE_STRUC battery_profile_t2[] =
{
{	0	,	4334	},
{	2	,	4310	},
{	3	,	4290	},
{	5	,	4271	},
{	7	,	4252	},
{	8	,	4234	},
{	10	,	4216	},
{	11	,	4198	},
{	13	,	4180	},
{	15	,	4162	},
{	16	,	4145	},
{	18	,	4128	},
{	20	,	4111	},
{	21	,	4094	},
{	23	,	4078	},
{	25	,	4062	},
{	26	,	4048	},
{	28	,	4032	},
{	30	,	4017	},
{	31	,	4004	},
{	33	,	3990	},
{	34	,	3977	},
{	36	,	3965	},
{	38	,	3951	},
{	39	,	3937	},
{	41	,	3921	},
{	43	,	3902	},
{	44	,	3885	},
{	46	,	3871	},
{	48	,	3859	},
{	49	,	3849	},
{	51	,	3841	},
{	53	,	3833	},
{	54	,	3826	},
{	56	,	3819	},
{	57	,	3813	},
{	59	,	3807	},
{	61	,	3801	},
{	62	,	3796	},
{	64	,	3791	},
{	66	,	3786	},
{	67	,	3782	},
{	69	,	3777	},
{	71	,	3773	},
{	72	,	3770	},
{	74	,	3765	},
{	76	,	3760	},
{	77	,	3753	},
{	79	,	3745	},
{	80	,	3738	},
{	82	,	3730	},
{	84	,	3717	},
{	85	,	3704	},
{	87	,	3688	},
{	89	,	3683	},
{	90	,	3681	},
{	92	,	3679	},
{	94	,	3677	},
{	95	,	3669	},
{	97	,	3624	},
{	98	,	3535	},
{	100	,	3390	},
{	100	,	3292	},
{	100	,	3275	},
{	100	,	3267	},
{	100	,	3264	},
{	100	,	3263	},
{	100	,	3261	},
{	100	,	3260	},
{	100	,	3259	},
{	100	,	3258	},
{	100	,	3258	},
{	100	,	3257	},
{	100	,	3257	},
{	100	,	3257	},
{	100	,	3257	},
{	100	,	3257	},
{	100	,	3257	},
{	100	,	3257	},
{	100	,	3257	},
{	100	,	3257	}
};     

// T3 50C
BATTERY_PROFILE_STRUC battery_profile_t3[] =
{
{	0	,	4319	},
{	2	,	4299	},
{	3	,	4280	},
{	5	,	4261	},
{	7	,	4242	},
{	8	,	4225	},
{	10	,	4206	},
{	12	,	4188	},
{	13	,	4171	},
{	15	,	4154	},
{	17	,	4136	},
{	18	,	4119	},
{	20	,	4102	},
{	22	,	4086	},
{	23	,	4070	},
{	25	,	4054	},
{	26	,	4039	},
{	28	,	4025	},
{	30	,	4011	},
{	31	,	3997	},
{	33	,	3983	},
{	35	,	3970	},
{	36	,	3958	},
{	38	,	3947	},
{	40	,	3934	},
{	41	,	3919	},
{	43	,	3900	},
{	45	,	3880	},
{	46	,	3866	},
{	48	,	3855	},
{	50	,	3846	},
{	51	,	3838	},
{	53	,	3830	},
{	55	,	3823	},
{	56	,	3816	},
{	58	,	3810	},
{	60	,	3803	},
{	61	,	3798	},
{	63	,	3792	},
{	65	,	3787	},
{	66	,	3782	},
{	68	,	3778	},
{	69	,	3773	},
{	71	,	3765	},
{	73	,	3754	},
{	74	,	3748	},
{	76	,	3742	},
{	78	,	3736	},
{	79	,	3727	},
{	81	,	3721	},
{	83	,	3712	},
{	84	,	3698	},
{	86	,	3685	},
{	88	,	3671	},
{	89	,	3669	},
{	91	,	3666	},
{	93	,	3664	},
{	94	,	3660	},
{	96	,	3644	},
{	98	,	3583	},
{	99	,	3483	},
{	100	,	3308	},
{	100	,	3266	},
{	100	,	3259	},
{	100	,	3257	},
{	100	,	3255	},
{	100	,	3253	},
{	100	,	3253	},
{	100	,	3253	},
{	100	,	3252	},
{	100	,	3251	},
{	100	,	3251	},
{	100	,	3250	},
{	100	,	3250	},
{	100	,	3250	},
{	100	,	3250	},
{	100	,	3250	},
{	100	,	3250	},
{	100	,	3250	},
{	100	,	3250	},
{	100	,	3250	}
};           

// battery profile for actual temperature. The size should be the same as T1, T2 and T3
BATTERY_PROFILE_STRUC battery_profile_temperature[] =
{
  {0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },  
	{0  , 0 }, 
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },  
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 }
};    

// ============================================================
// <Rbat, Battery_Voltage> Table
// ============================================================
// T0 -10C
R_PROFILE_STRUC r_profile_t0[] =
{
{	358	,	4328	},
{	313	,	4310	},
{	648	,	4287	},
{	710	,	4266	},
{	710	,	4247	},
{	705	,	4227	},
{	705	,	4208	},
{	705	,	4190	},
{	705	,	4171	},
{	705	,	4153	},
{	705	,	4135	},
{	703	,	4117	},
{	700	,	4099	},
{	695	,	4081	},
{	695	,	4064	},
{	690	,	4046	},
{	683	,	4025	},
{	673	,	4004	},
{	663	,	3984	},
{	658	,	3967	},
{	650	,	3951	},
{	648	,	3937	},
{	645	,	3924	},
{	643	,	3911	},
{	640	,	3899	},
{	640	,	3887	},
{	643	,	3877	},
{	643	,	3867	},
{	643	,	3858	},
{	645	,	3849	},
{	645	,	3840	},
{	648	,	3832	},
{	650	,	3824	},
{	655	,	3817	},
{	658	,	3811	},
{	663	,	3805	},
{	665	,	3799	},
{	670	,	3793	},
{	675	,	3788	},
{	680	,	3782	},
{	690	,	3778	},
{	698	,	3774	},
{	700	,	3768	},
{	710	,	3763	},
{	718	,	3757	},
{	728	,	3749	},
{	743	,	3741	},
{	750	,	3731	},
{	760	,	3722	},
{	773	,	3714	},
{	788	,	3707	},
{	813	,	3701	},
{	840	,	3696	},
{	885	,	3691	},
{	940	,	3682	},
{	1010	,	3663	},
{	1078	,	3631	},
{	1058	,	3623	},
{	1045	,	3618	},
{	1040	,	3615	},
{	1033	,	3612	},
{	1030	,	3611	},
{	1025	,	3609	},
{	1018	,	3607	},
{	1018	,	3605	},
{	1013	,	3603	},
{	1005	,	3600	},
{	1000	,	3599	},
{	995	,	3597	},
{	993	,	3595	},
{	990	,	3594	},
{	980	,	3591	},
{	978	,	3590	},
{	975	,	3588	},
{	975	,	3588	},
{	975	,	3588	},
{	975	,	3588	},
{	975	,	3588	},
{	975	,	3588	},
{	975	,	3588	},
{	975	,	3588	}
};      

// T1 0C
R_PROFILE_STRUC r_profile_t1[] =
{
{	260	,	4271	},
{	443	,	4261	},
{	565	,	4240	},
{	575	,	4220	},
{	563	,	4201	},
{	400	,	4183	},
{	585	,	4171	},
{	583	,	4151	},
{	413	,	4134	},
{	418	,	4117	},
{	550	,	4101	},
{	423	,	4084	},
{	420	,	4066	},
{	563	,	4050	},
{	608	,	4036	},
{	435	,	4020	},
{	573	,	4003	},
{	593	,	3981	},
{	605	,	3969	},
{	590	,	3952	},
{	573	,	3932	},
{	578	,	3918	},
{	570	,	3907	},
{	550	,	3888	},
{	553	,	3879	},
{	573	,	3871	},
{	560	,	3860	},
{	563	,	3852	},
{	558	,	3840	},
{	560	,	3833	},
{	555	,	3825	},
{	565	,	3820	},
{	385	,	3814	},
{	385	,	3807	},
{	563	,	3801	},
{	578	,	3800	},
{	580	,	3794	},
{	568	,	3785	},
{	585	,	3783	},
{	590	,	3779	},
{	588	,	3773	},
{	603	,	3774	},
{	593	,	3765	},
{	593	,	3763	},
{	600	,	3756	},
{	598	,	3746	},
{	600	,	3734	},
{	600	,	3722	},
{	610	,	3713	},
{	613	,	3704	},
{	608	,	3696	},
{	620	,	3691	},
{	650	,	3692	},
{	670	,	3684	},
{	718	,	3677	},
{	790	,	3656	},
{	855	,	3608	},
{	915	,	3565	},
{	878	,	3549	},
{	835	,	3533	},
{	803	,	3520	},
{	710	,	3477	},
{	633	,	3453	},
{	595	,	3437	},
{	568	,	3426	},
{	545	,	3417	},
{	545	,	3417	},
{	545	,	3417	},
{	545	,	3417	},
{	545	,	3417	},
{	545	,	3417	},
{	545	,	3417	},
{	545	,	3417	},
{	545	,	3417	},
{	545	,	3417	},
{	545	,	3417	},
{	545	,	3417	},
{	545	,	3417	},
{	545	,	3417	},
{	545	,	3417	},
{	548	,	3417	}
};     

// T2 25C
R_PROFILE_STRUC r_profile_t2[] =
{
{	158	,	4334	},
{	148	,	4310	},
{	150	,	4290	},
{	153	,	4271	},
{	153	,	4252	},
{	155	,	4234	},
{	158	,	4216	},
{	158	,	4198	},
{	160	,	4180	},
{	160	,	4162	},
{	160	,	4145	},
{	160	,	4128	},
{	160	,	4111	},
{	160	,	4094	},
{	163	,	4078	},
{	160	,	4062	},
{	168	,	4048	},
{	170	,	4032	},
{	175	,	4017	},
{	183	,	4004	},
{	188	,	3990	},
{	195	,	3977	},
{	203	,	3965	},
{	205	,	3951	},
{	205	,	3937	},
{	200	,	3921	},
{	185	,	3902	},
{	173	,	3885	},
{	163	,	3871	},
{	160	,	3859	},
{	158	,	3849	},
{	158	,	3841	},
{	160	,	3833	},
{	163	,	3826	},
{	163	,	3819	},
{	165	,	3813	},
{	165	,	3807	},
{	165	,	3801	},
{	168	,	3796	},
{	170	,	3791	},
{	170	,	3786	},
{	173	,	3782	},
{	168	,	3777	},
{	168	,	3773	},
{	170	,	3770	},
{	168	,	3765	},
{	165	,	3760	},
{	160	,	3753	},
{	155	,	3745	},
{	153	,	3738	},
{	155	,	3730	},
{	153	,	3717	},
{	155	,	3704	},
{	155	,	3688	},
{	155	,	3683	},
{	158	,	3681	},
{	165	,	3679	},
{	178	,	3677	},
{	195	,	3669	},
{	198	,	3624	},
{	208	,	3535	},
{	233	,	3390	},
{	230	,	3292	},
{	190	,	3275	},
{	170	,	3267	},
{	160	,	3264	},
{	158	,	3263	},
{	158	,	3261	},
{	155	,	3260	},
{	153	,	3259	},
{	150	,	3258	},
{	150	,	3258	},
{	150	,	3257	},
{	150	,	3257	},
{	153	,	3257	},
{	153	,	3257	},
{	153	,	3257	},
{	153	,	3257	},
{	153	,	3257	},
{	153	,	3257	},
{	153	,	3257	}
}; 

// T3 50C
R_PROFILE_STRUC r_profile_t3[] =
{
{	138	,	4319	},
{	125	,	4299	},
{	128	,	4280	},
{	130	,	4261	},
{	130	,	4242	},
{	130	,	4225	},
{	130	,	4206	},
{	130	,	4188	},
{	133	,	4171	},
{	133	,	4154	},
{	133	,	4136	},
{	135	,	4119	},
{	138	,	4102	},
{	143	,	4086	},
{	143	,	4070	},
{	143	,	4054	},
{	145	,	4039	},
{	150	,	4025	},
{	150	,	4011	},
{	153	,	3997	},
{	153	,	3983	},
{	155	,	3970	},
{	160	,	3958	},
{	170	,	3947	},
{	175	,	3934	},
{	175	,	3919	},
{	165	,	3900	},
{	150	,	3880	},
{	143	,	3866	},
{	143	,	3855	},
{	143	,	3846	},
{	140	,	3838	},
{	140	,	3830	},
{	140	,	3823	},
{	140	,	3816	},
{	140	,	3810	},
{	140	,	3803	},
{	143	,	3798	},
{	143	,	3792	},
{	145	,	3787	},
{	148	,	3782	},
{	150	,	3778	},
{	150	,	3773	},
{	148	,	3765	},
{	143	,	3754	},
{	145	,	3748	},
{	148	,	3742	},
{	150	,	3736	},
{	145	,	3727	},
{	148	,	3721	},
{	150	,	3712	},
{	148	,	3698	},
{	153	,	3685	},
{	155	,	3671	},
{	158	,	3669	},
{	160	,	3666	},
{	165	,	3664	},
{	170	,	3660	},
{	173	,	3644	},
{	175	,	3583	},
{	178	,	3483	},
{	185	,	3308	},
{	165	,	3266	},
{	148	,	3259	},
{	145	,	3257	},
{	140	,	3255	},
{	135	,	3253	},
{	138	,	3253	},
{	135	,	3253	},
{	133	,	3252	},
{	130	,	3251	},
{	130	,	3251	},
{	130	,	3250	},
{	130	,	3250	},
{	133	,	3250	},
{	133	,	3250	},
{	133	,	3250	},
{	133	,	3250	},
{	133	,	3250	},
{	133	,	3250	},
{	133	,	3250	}
}; 

// r-table profile for actual temperature. The size should be the same as T1, T2 and T3
R_PROFILE_STRUC r_profile_temperature[] =
{
  {0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },  
	{0  , 0 }, 
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },  
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 }
};    

// ============================================================
// function prototype
// ============================================================
int fgauge_get_saddles(void);
BATTERY_PROFILE_STRUC_P fgauge_get_profile(kal_uint32 temperature);

int fgauge_get_saddles_r_table(void);
R_PROFILE_STRUC_P fgauge_get_profile_r_table(kal_uint32 temperature);

#endif	//#ifndef _CUST_BATTERY_METER_TABLE_H

