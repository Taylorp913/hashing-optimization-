/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/Taylor/Documents/GitHub/hashing-optimization-/MD5_Real/IIround.v";
static int ng1[] = {32, 0};



static int sp_I(char *t1, char *t2)
{
    char t9[8];
    char t23[8];
    char t51[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;
    char *t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    char *t55;
    char *t56;
    char *t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    char *t65;

LAB0:    t0 = 1;
    xsi_set_current_line(38, ng0);

LAB2:    xsi_set_current_line(39, ng0);
    t3 = (t1 + 3800);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t1 + 3640);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t10 = (t1 + 3960);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memset(t9, 0, 8);
    t13 = (t9 + 4);
    t14 = (t12 + 4);
    t15 = *((unsigned int *)t12);
    t16 = (~(t15));
    *((unsigned int *)t9) = t16;
    *((unsigned int *)t13) = 0;
    if (*((unsigned int *)t14) != 0)
        goto LAB4;

LAB3:    t21 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t21 & 4294967295U);
    t22 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t22 & 4294967295U);
    t24 = *((unsigned int *)t8);
    t25 = *((unsigned int *)t9);
    t26 = (t24 | t25);
    *((unsigned int *)t23) = t26;
    t27 = (t8 + 4);
    t28 = (t9 + 4);
    t29 = (t23 + 4);
    t30 = *((unsigned int *)t27);
    t31 = *((unsigned int *)t28);
    t32 = (t30 | t31);
    *((unsigned int *)t29) = t32;
    t33 = *((unsigned int *)t29);
    t34 = (t33 != 0);
    if (t34 == 1)
        goto LAB5;

LAB6:
LAB7:    t52 = *((unsigned int *)t5);
    t53 = *((unsigned int *)t23);
    t54 = (t52 ^ t53);
    *((unsigned int *)t51) = t54;
    t55 = (t5 + 4);
    t56 = (t23 + 4);
    t57 = (t51 + 4);
    t58 = *((unsigned int *)t55);
    t59 = *((unsigned int *)t56);
    t60 = (t58 | t59);
    *((unsigned int *)t57) = t60;
    t61 = *((unsigned int *)t57);
    t62 = (t61 != 0);
    if (t62 == 1)
        goto LAB8;

LAB9:
LAB10:    t65 = (t1 + 3480);
    xsi_vlogvar_assign_value(t65, t51, 0, 0, 32);
    t0 = 0;

LAB1:    return t0;
LAB4:    t17 = *((unsigned int *)t9);
    t18 = *((unsigned int *)t14);
    *((unsigned int *)t9) = (t17 | t18);
    t19 = *((unsigned int *)t13);
    t20 = *((unsigned int *)t14);
    *((unsigned int *)t13) = (t19 | t20);
    goto LAB3;

LAB5:    t35 = *((unsigned int *)t23);
    t36 = *((unsigned int *)t29);
    *((unsigned int *)t23) = (t35 | t36);
    t37 = (t8 + 4);
    t38 = (t9 + 4);
    t39 = *((unsigned int *)t37);
    t40 = (~(t39));
    t41 = *((unsigned int *)t8);
    t42 = (t41 & t40);
    t43 = *((unsigned int *)t38);
    t44 = (~(t43));
    t45 = *((unsigned int *)t9);
    t46 = (t45 & t44);
    t47 = (~(t42));
    t48 = (~(t46));
    t49 = *((unsigned int *)t29);
    *((unsigned int *)t29) = (t49 & t47);
    t50 = *((unsigned int *)t29);
    *((unsigned int *)t29) = (t50 & t48);
    goto LAB7;

LAB8:    t63 = *((unsigned int *)t51);
    t64 = *((unsigned int *)t57);
    *((unsigned int *)t51) = (t63 | t64);
    goto LAB10;

}

static void Cont_31_0(char *t0)
{
    char t24[8];
    char t28[8];
    char t31[8];
    char t33[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    int t20;
    char *t21;
    char *t22;
    char *t23;
    char *t25;
    char *t26;
    char *t27;
    char *t29;
    char *t30;
    char *t32;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;

LAB0:    t1 = (t0 + 4880U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(31, ng0);
    t2 = (t0 + 1480U);
    t3 = *((char **)t2);
    t2 = (t0 + 1640U);
    t4 = *((char **)t2);
    t2 = (t0 + 1800U);
    t5 = *((char **)t2);
    t2 = (t0 + 1960U);
    t6 = *((char **)t2);
    t2 = (t0 + 4688);
    t7 = (t0 + 848);
    t8 = xsi_create_subprogram_invocation(t2, 0, t0, t7, 0, 0);
    t9 = (t0 + 3640);
    xsi_vlogvar_assign_value(t9, t4, 0, 0, 32);
    t10 = (t0 + 3800);
    xsi_vlogvar_assign_value(t10, t5, 0, 0, 32);
    t11 = (t0 + 3960);
    xsi_vlogvar_assign_value(t11, t6, 0, 0, 32);

LAB4:    t12 = (t0 + 4784);
    t13 = *((char **)t12);
    t14 = (t13 + 80U);
    t15 = *((char **)t14);
    t16 = (t15 + 272U);
    t17 = *((char **)t16);
    t18 = (t17 + 0U);
    t19 = *((char **)t18);
    t20 = ((int  (*)(char *, char *))t19)(t0, t13);
    if (t20 != 0)
        goto LAB6;

LAB5:    t13 = (t0 + 4784);
    t21 = *((char **)t13);
    t13 = (t0 + 3480);
    t22 = (t13 + 56U);
    t23 = *((char **)t22);
    memcpy(t24, t23, 8);
    t25 = (t0 + 848);
    t26 = (t0 + 4688);
    t27 = 0;
    xsi_delete_subprogram_invocation(t25, t21, t0, t26, t27);
    memset(t28, 0, 8);
    xsi_vlog_unsigned_add(t28, 32, t3, 32, t24, 32);
    t29 = (t0 + 2120U);
    t30 = *((char **)t29);
    memset(t31, 0, 8);
    xsi_vlog_unsigned_add(t31, 32, t28, 32, t30, 32);
    t29 = (t0 + 2280U);
    t32 = *((char **)t29);
    memset(t33, 0, 8);
    xsi_vlog_unsigned_add(t33, 32, t31, 32, t32, 32);
    t29 = (t0 + 6072);
    t34 = (t29 + 56U);
    t35 = *((char **)t34);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    memcpy(t37, t33, 8);
    xsi_driver_vfirst_trans(t29, 0, 31);
    t38 = (t0 + 5944);
    *((int *)t38) = 1;

LAB1:    return;
LAB6:    t12 = (t0 + 4880U);
    *((char **)t12) = &&LAB4;
    goto LAB1;

}

static void Cont_32_1(char *t0)
{
    char t5[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;

LAB0:    t1 = (t0 + 5128U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(32, ng0);
    t2 = (t0 + 2760U);
    t3 = *((char **)t2);
    t2 = (t0 + 2440U);
    t4 = *((char **)t2);
    memset(t5, 0, 8);
    xsi_vlog_unsigned_lshift(t5, 32, t3, 32, t4, 32);
    t2 = (t0 + 6136);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t5, 8);
    xsi_driver_vfirst_trans(t2, 0, 31);
    t10 = (t0 + 5960);
    *((int *)t10) = 1;

LAB1:    return;
}

static void Cont_33_2(char *t0)
{
    char t6[8];
    char t7[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;

LAB0:    t1 = (t0 + 5376U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(33, ng0);
    t2 = (t0 + 2760U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 2440U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    xsi_vlog_unsigned_minus(t6, 32, t2, 32, t5, 32);
    memset(t7, 0, 8);
    xsi_vlog_unsigned_rshift(t7, 32, t3, 32, t6, 32);
    t4 = (t0 + 6200);
    t8 = (t4 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t7, 8);
    xsi_driver_vfirst_trans(t4, 0, 31);
    t12 = (t0 + 5976);
    *((int *)t12) = 1;

LAB1:    return;
}

static void Cont_34_3(char *t0)
{
    char t6[8];
    char t33[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;

LAB0:    t1 = (t0 + 5624U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(34, ng0);
    t2 = (t0 + 1640U);
    t3 = *((char **)t2);
    t2 = (t0 + 2920U);
    t4 = *((char **)t2);
    t2 = (t0 + 3080U);
    t5 = *((char **)t2);
    t7 = *((unsigned int *)t4);
    t8 = *((unsigned int *)t5);
    t9 = (t7 | t8);
    *((unsigned int *)t6) = t9;
    t2 = (t4 + 4);
    t10 = (t5 + 4);
    t11 = (t6 + 4);
    t12 = *((unsigned int *)t2);
    t13 = *((unsigned int *)t10);
    t14 = (t12 | t13);
    *((unsigned int *)t11) = t14;
    t15 = *((unsigned int *)t11);
    t16 = (t15 != 0);
    if (t16 == 1)
        goto LAB4;

LAB5:
LAB6:    memset(t33, 0, 8);
    xsi_vlog_unsigned_add(t33, 32, t3, 32, t6, 32);
    t34 = (t0 + 6264);
    t35 = (t34 + 56U);
    t36 = *((char **)t35);
    t37 = (t36 + 56U);
    t38 = *((char **)t37);
    memcpy(t38, t33, 8);
    xsi_driver_vfirst_trans(t34, 0, 31);
    t39 = (t0 + 5992);
    *((int *)t39) = 1;

LAB1:    return;
LAB4:    t17 = *((unsigned int *)t6);
    t18 = *((unsigned int *)t11);
    *((unsigned int *)t6) = (t17 | t18);
    t19 = (t4 + 4);
    t20 = (t5 + 4);
    t21 = *((unsigned int *)t19);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = *((unsigned int *)t20);
    t26 = (~(t25));
    t27 = *((unsigned int *)t5);
    t28 = (t27 & t26);
    t29 = (~(t24));
    t30 = (~(t28));
    t31 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t31 & t29);
    t32 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t32 & t30);
    goto LAB6;

}


extern void work_m_00000000001421803573_1068452009_init()
{
	static char *pe[] = {(void *)Cont_31_0,(void *)Cont_32_1,(void *)Cont_33_2,(void *)Cont_34_3};
	static char *se[] = {(void *)sp_I};
	xsi_register_didat("work_m_00000000001421803573_1068452009", "isim/MD5_Test_isim_beh.exe.sim/work/m_00000000001421803573_1068452009.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
