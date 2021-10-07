/*ICONC*/
/*
 * Tue Jul 13 00:55:41 2021
 * This file was produced by
 *   iconc: Unicon Version 13.2 (iconc).  December 20, 2020
 */
#define COMPILER 1
#include "/usr/lib/x86_64-linux-gnu/unicon/rt/include/rt.h"

int O0v_neqv (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0t_lexlt (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0i_numeq (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0y_tabmat (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O17_diff (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0m_numlt (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O14_sect (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O05_minus (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O08_neg (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O1a_nonnull (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O1d_conj (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O04_divide (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O1b_null (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0a_plus (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O09_number (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0j_numge (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O03_rcvbk (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O07_mult (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0x_size (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0e_rswap (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0h_lconcat (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0u_eqv (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O00_snd (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0q_lexge (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0l_numle (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O01_sndbk (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O11_llist (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0b_powr (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0w_refresh (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O06_mod (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0p_lexne (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O1c_value (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O18_inter (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O15_subsc (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0d_rasgn (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O16_compl (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O19_union (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0s_lexle (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0k_numgt (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0f_swap (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0z_toby (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O10_to (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0g_cater (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O12_bang (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O13_random (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0r_lexgt (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0o_lexeq (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0n_numne (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O0c_asgn (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
int O02_rcv (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
#define OpTblSz 50
int op_tbl_sz = OpTblSz;

int F7w_Fence (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7w_Fence = {T_Proc, 11, F7w_Fence, 1, -1, 0, 0, {{5, "Fence"}}};

int F6u_getgr (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6u_getgr = {T_Proc, 11, F6u_getgr, 1, -1, 0, 0, {{5, "getgr"}}};

int F5o_hardlink (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5o_hardlink = {T_Proc, 11, F5o_hardlink, 2, -1, 0, 0, {{8, "hardlink"}}};

int F0m_args (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0m_args = {T_Proc, 11, F0m_args, 2, -1, 0, 0, {{4, "args"}}};

int F02_integer (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF02_integer = {T_Proc, 11, F02_integer, 1, -1, 0, 0, {{7, "integer"}}};

int F3m_DrawString (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3m_DrawString = {T_Proc, 11, F3m_DrawString, -1, -1, 0, 0, {{10, "DrawString"}}};

int F2o_read (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2o_read = {T_Proc, 11, F2o_read, 1, -1, 0, 0, {{4, "read"}}};

static int P004_Ainitialize (int r_nargs, dptr r_args,dptr r_rslt, continuation r_s_cont);
B_IProc(1) BP004_Ainitialize = {T_Proc, 11, P004_Ainitialize, 0, 0, 0, 0, {
   {11, "Ainitialize"},
   }};

int F7q_pattern_boolmethodcall (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7q_pattern_boolmethodcall = {T_Proc, 11, F7q_pattern_boolmethodcall, 1, -1, 0, 0, {{22, "pattern_boolmethodcall"}}};

int F2t_system (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2t_system = {T_Proc, 11, F2t_system, 5, -1, 0, 0, {{6, "system"}}};

int F3i_DrawPoint (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3i_DrawPoint = {T_Proc, 11, F3i_DrawPoint, -1, -1, 0, 0, {{9, "DrawPoint"}}};

int F48_ReadImage (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF48_ReadImage = {T_Proc, 11, F48_ReadImage, -1, -1, 0, 0, {{9, "ReadImage"}}};

int F6e_getpgrp (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6e_getpgrp = {T_Proc, 11, F6e_getpgrp, 0, -1, 0, 0, {{7, "getpgrp"}}};

int F2q_remove (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2q_remove = {T_Proc, 11, F2q_remove, 1, -1, 0, 0, {{6, "remove"}}};

int F3e_DrawCircle (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3e_DrawCircle = {T_Proc, 11, F3e_DrawCircle, -1, -1, 0, 0, {{10, "DrawCircle"}}};

int F52_PushTranslate (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF52_PushTranslate = {T_Proc, 11, F52_PushTranslate, -1, -1, 0, 0, {{13, "PushTranslate"}}};

int F25_classname (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF25_classname = {T_Proc, 11, F25_classname, 1, -1, 0, 0, {{9, "classname"}}};

int F30_kbhit (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF30_kbhit = {T_Proc, 11, F30_kbhit, 0, -1, 0, 0, {{5, "kbhit"}}};

int F1m_detab (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1m_detab = {T_Proc, 11, F1m_detab, -2, -1, 0, 0, {{5, "detab"}}};

int F5l_sys_errstr (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5l_sys_errstr = {T_Proc, 11, F5l_sys_errstr, 1, -1, 0, 0, {{10, "sys_errstr"}}};

int F3s_FillPolygon (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3s_FillPolygon = {T_Proc, 11, F3s_FillPolygon, -1, -1, 0, 0, {{11, "FillPolygon"}}};

int F3x_GotoXY (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3x_GotoXY = {T_Proc, 11, F3x_GotoXY, -1, -1, 0, 0, {{6, "GotoXY"}}};

int F6n_lstat (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6n_lstat = {T_Proc, 11, F6n_lstat, 1, -1, 0, 0, {{5, "lstat"}}};

int F7l_Succeed (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7l_Succeed = {T_Proc, 11, F7l_Succeed, 0, -1, 0, 0, {{7, "Succeed"}}};

int F1h_Attrib (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1h_Attrib = {T_Proc, 11, F1h_Attrib, -1, -1, 0, 0, {{6, "Attrib"}}};

int F0t_ior (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0t_ior = {T_Proc, 11, F0t_ior, 2, -1, 0, 0, {{3, "ior"}}};

int F1s_right (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1s_right = {T_Proc, 11, F1s_right, 3, -1, 0, 0, {{5, "right"}}};

int F4y_Translate (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4y_Translate = {T_Proc, 11, F4y_Translate, -1, -1, 0, 0, {{9, "Translate"}}};

int F4q_WinSaveDialog (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4q_WinSaveDialog = {T_Proc, 11, F4q_WinSaveDialog, -1, -1, 0, 0, {{13, "WinSaveDialog"}}};

int F5h_dblimits (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5h_dblimits = {T_Proc, 11, F5h_dblimits, 1, -1, 0, 0, {{8, "dblimits"}}};

int F6b_getegid (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6b_getegid = {T_Proc, 11, F6b_getegid, 0, -1, 0, 0, {{7, "getegid"}}};

int F5z_flock (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5z_flock = {T_Proc, 11, F5z_flock, 2, -1, 0, 0, {{5, "flock"}}};

int F6t_getpw (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6t_getpw = {T_Proc, 11, F6t_getpw, 1, -1, 0, 0, {{5, "getpw"}}};

int F22_pop (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF22_pop = {T_Proc, 11, F22_pop, 2, -1, 0, 0, {{3, "pop"}}};

int F3p_Fg (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3p_Fg = {T_Proc, 11, F3p_Fg, -1, -1, 0, 0, {{2, "Fg"}}};

int F43_Pattern (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF43_Pattern = {T_Proc, 11, F43_Pattern, -1, -1, 0, 0, {{7, "Pattern"}}};

int F72_syswrite (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF72_syswrite = {T_Proc, 11, F72_syswrite, 2, -1, 0, 0, {{8, "syswrite"}}};

int F20_delete (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF20_delete = {T_Proc, 11, F20_delete, -2, -1, 0, 0, {{6, "delete"}}};

int F0b_acos (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0b_acos = {T_Proc, 11, F0b_acos, 1, -1, 0, 0, {{4, "acos"}}};

int F06_proc (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF06_proc = {T_Proc, 11, F06_proc, 2, -1, 0, 0, {{4, "proc"}}};

int F7h_Tab (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7h_Tab = {T_Proc, 11, F7h_Tab, 1, -1, 0, 0, {{3, "Tab"}}};

int F1b_lock (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1b_lock = {T_Proc, 11, F1b_lock, -1, -1, 0, 0, {{4, "lock"}}};

int F7u_pattern_setcur (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7u_pattern_setcur = {T_Proc, 11, F7u_pattern_setcur, 1, -1, 0, 0, {{14, "pattern_setcur"}}};

int F50_PopMatrix (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF50_PopMatrix = {T_Proc, 11, F50_PopMatrix, -1, -1, 0, 0, {{9, "PopMatrix"}}};

int F58_Texcoord (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF58_Texcoord = {T_Proc, 11, F58_Texcoord, -1, -1, 0, 0, {{8, "Texcoord"}}};

int F24_insert (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF24_insert = {T_Proc, 11, F24_insert, -2, -1, 0, 0, {{6, "insert"}}};

int F29_methods_fromstr (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF29_methods_fromstr = {T_Proc, 11, F29_methods_fromstr, 1, -1, 0, 0, {{15, "methods_fromstr"}}};

int F0i_atan (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0i_atan = {T_Proc, 11, F0i_atan, 2, -1, 0, 0, {{4, "atan"}}};

int F0j_log (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0j_log = {T_Proc, 11, F0j_log, 2, -1, 0, 0, {{3, "log"}}};

int F5s_trap (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5s_trap = {T_Proc, 11, F5s_trap, 2, -1, 0, 0, {{4, "trap"}}};

int F3v_FreeColor (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3v_FreeColor = {T_Proc, 11, F3v_FreeColor, -1, -1, 0, 0, {{9, "FreeColor"}}};

int F5f_dbdriver (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5f_dbdriver = {T_Proc, 11, F5f_dbdriver, 1, -1, 0, 0, {{8, "dbdriver"}}};

int F3f_DrawCurve (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3f_DrawCurve = {T_Proc, 11, F3f_DrawCurve, -1, -1, 0, 0, {{9, "DrawCurve"}}};

int F45_Pixel (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF45_Pixel = {T_Proc, 11, F45_Pixel, -1, -1, 0, 0, {{5, "Pixel"}}};

int F7g_Rpos (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7g_Rpos = {T_Proc, 11, F7g_Rpos, 1, -1, 0, 0, {{4, "Rpos"}}};

int F4c_WAttrib (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4c_WAttrib = {T_Proc, 11, F4c_WAttrib, -1, -1, 0, 0, {{7, "WAttrib"}}};

int F1y_match (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1y_match = {T_Proc, 11, F1y_match, 4, -1, 0, 0, {{5, "match"}}};

int F6p_send (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6p_send = {T_Proc, 11, F6p_send, 4, -1, 0, 0, {{4, "send"}}};

int F6c_setuid (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6c_setuid = {T_Proc, 11, F6c_setuid, 1, -1, 0, 0, {{6, "setuid"}}};

int F3a_ColorValue (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3a_ColorValue = {T_Proc, 11, F3a_ColorValue, -1, -1, 0, 0, {{10, "ColorValue"}}};

int F4j_WinScrollBar (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4j_WinScrollBar = {T_Proc, 11, F4j_WinScrollBar, -1, -1, 0, 0, {{12, "WinScrollBar"}}};

int F5u_chmod (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5u_chmod = {T_Proc, 11, F5u_chmod, 2, -1, 0, 0, {{5, "chmod"}}};

int F3l_DrawSegment (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3l_DrawSegment = {T_Proc, 11, F3l_DrawSegment, -1, -1, 0, 0, {{11, "DrawSegment"}}};

int F5x_mkdir (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5x_mkdir = {T_Proc, 11, F5x_mkdir, 2, -1, 0, 0, {{5, "mkdir"}}};

int F7v_pattern_assign_immediate (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7v_pattern_assign_immediate = {T_Proc, 11, F7v_pattern_assign_immediate, 2, -1, 0, 0, {{24, "pattern_assign_immediate"}}};

int F7s_pattern_concat (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7s_pattern_concat = {T_Proc, 11, F7s_pattern_concat, 2, -1, 0, 0, {{14, "pattern_concat"}}};

int F7e_Len (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7e_Len = {T_Proc, 11, F7e_Len, 1, -1, 0, 0, {{3, "Len"}}};

int F09_cos (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF09_cos = {T_Proc, 11, F09_cos, 1, -1, 0, 0, {{3, "cos"}}};

int F69_geteuid (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF69_geteuid = {T_Proc, 11, F69_geteuid, 0, -1, 0, 0, {{7, "geteuid"}}};

int F38_Clone (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF38_Clone = {T_Proc, 11, F38_Clone, -1, -1, 0, 0, {{5, "Clone"}}};

int F7a_NotAny (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7a_NotAny = {T_Proc, 11, F7a_NotAny, 1, -1, 0, 0, {{6, "NotAny"}}};

int F7i_Rtab (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7i_Rtab = {T_Proc, 11, F7i_Rtab, 1, -1, 0, 0, {{4, "Rtab"}}};

int F2y_getch (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2y_getch = {T_Proc, 11, F2y_getch, 0, -1, 0, 0, {{5, "getch"}}};

int F4e_WFlush (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4e_WFlush = {T_Proc, 11, F4e_WFlush, -1, -1, 0, 0, {{6, "WFlush"}}};

int F1u_any (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1u_any = {T_Proc, 11, F1u_any, 4, -1, 0, 0, {{3, "any"}}};

int F35_Alert (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF35_Alert = {T_Proc, 11, F35_Alert, -1, -1, 0, 0, {{5, "Alert"}}};

int F3c_Couple (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3c_Couple = {T_Proc, 11, F3c_Couple, 2, -1, 0, 0, {{6, "Couple"}}};

int F54_PushScale (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF54_PushScale = {T_Proc, 11, F54_PushScale, -1, -1, 0, 0, {{9, "PushScale"}}};

int F1o_left (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1o_left = {T_Proc, 11, F1o_left, 3, -1, 0, 0, {{4, "left"}}};

int F3o_Event (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3o_Event = {T_Proc, 11, F3o_Event, -1, -1, 0, 0, {{5, "Event"}}};

int F1n_entab (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1n_entab = {T_Proc, 11, F1n_entab, -2, -1, 0, 0, {{5, "entab"}}};

int F71_ready (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF71_ready = {T_Proc, 11, F71_ready, 2, -1, 0, 0, {{5, "ready"}}};

static int R007_posix_passwd (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(8) BR007_posix_passwd = {T_Proc, 25, R007_posix_passwd, 7, -2, 3, 1, {
   {12, "posix_passwd"},
   {4, "name"},
   {6, "passwd"},
   {3, "uid"},
   {3, "gid"},
   {5, "gecos"},
   {3, "dir"},
   {5, "shell"},
   }};

int F0n_char (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0n_char = {T_Proc, 11, F0n_char, 1, -1, 0, 0, {{4, "char"}}};

int F7n_pattern_stringfunccall (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7n_pattern_stringfunccall = {T_Proc, 11, F7n_pattern_stringfunccall, 1, -1, 0, 0, {{22, "pattern_stringfunccall"}}};

int F4z_Scale (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4z_Scale = {T_Proc, 11, F4z_Scale, -1, -1, 0, 0, {{5, "Scale"}}};

int F60_fcntl (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF60_fcntl = {T_Proc, 11, F60_fcntl, 3, -1, 0, 0, {{5, "fcntl"}}};

int F1a_mutex (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1a_mutex = {T_Proc, 11, F1a_mutex, -1, -1, 0, 0, {{5, "mutex"}}};

int F14_sort (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF14_sort = {T_Proc, 11, F14_sort, 2, -1, 0, 0, {{4, "sort"}}};

int F4g_WinAssociate (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4g_WinAssociate = {T_Proc, 11, F4g_WinAssociate, 1, -1, 0, 0, {{12, "WinAssociate"}}};

int F67_exec (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF67_exec = {T_Proc, 11, F67_exec, -2, -1, 0, 0, {{4, "exec"}}};

int F2c_member (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2c_member = {T_Proc, 11, F2c_member, -2, -1, 0, 0, {{6, "member"}}};

int F5y_truncate (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5y_truncate = {T_Proc, 11, F5y_truncate, 2, -1, 0, 0, {{8, "truncate"}}};

int F7c_Nspan (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7c_Nspan = {T_Proc, 11, F7c_Nspan, 1, -1, 0, 0, {{5, "Nspan"}}};

int F32_delay (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF32_delay = {T_Proc, 11, F32_delay, 1, -1, 0, 0, {{5, "delay"}}};

int F0o_collect (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0o_collect = {T_Proc, 11, F0o_collect, 2, -1, 0, 0, {{7, "collect"}}};

int F1f_spawn (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1f_spawn = {T_Proc, 11, F1f_spawn, -1, -1, 0, 0, {{5, "spawn"}}};

int F3g_DrawImage (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3g_DrawImage = {T_Proc, 11, F3g_DrawImage, -1, -1, 0, 0, {{9, "DrawImage"}}};

int F4p_WinSelectDialog (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4p_WinSelectDialog = {T_Proc, 11, F4p_WinSelectDialog, -1, -1, 0, 0, {{15, "WinSelectDialog"}}};

int F6v_gethost (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6v_gethost = {T_Proc, 11, F6v_gethost, 2, -1, 0, 0, {{7, "gethost"}}};

int F13_serial (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF13_serial = {T_Proc, 11, F13_serial, 1, -1, 0, 0, {{6, "serial"}}};

int F6x_setpwent (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6x_setpwent = {T_Proc, 11, F6x_setpwent, 0, -1, 0, 0, {{8, "setpwent"}}};

int F6o_stat (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6o_stat = {T_Proc, 11, F6o_stat, 1, -1, 0, 0, {{4, "stat"}}};

int F10_name (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF10_name = {T_Proc, 11, F10_name, 1, -1, 0, 0, {{4, "name"}}};

int F7m_Bal (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7m_Bal = {T_Proc, 11, F7m_Bal, 0, -1, 0, 0, {{3, "Bal"}}};

int F2w_write (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2w_write = {T_Proc, 11, F2w_write, -1, -1, 0, 0, {{5, "write"}}};

int F40_PaletteChars (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF40_PaletteChars = {T_Proc, 11, F40_PaletteChars, -1, -1, 0, 0, {{12, "PaletteChars"}}};

int F6r_fetch (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6r_fetch = {T_Proc, 11, F6r_fetch, 2, -1, 0, 0, {{5, "fetch"}}};

int F26_membernames (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF26_membernames = {T_Proc, 11, F26_membernames, 1, -1, 0, 0, {{11, "membernames"}}};

int F1q_repl (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1q_repl = {T_Proc, 11, F1q_repl, 2, -1, 0, 0, {{4, "repl"}}};

int F6z_sethostent (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6z_sethostent = {T_Proc, 11, F6z_sethostent, 1, -1, 0, 0, {{10, "sethostent"}}};

int F3y_Lower (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3y_Lower = {T_Proc, 11, F3y_Lower, -1, -1, 0, 0, {{5, "Lower"}}};

int F4f_WriteImage (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4f_WriteImage = {T_Proc, 11, F4f_WriteImage, -1, -1, 0, 0, {{10, "WriteImage"}}};

int F1v_bal (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1v_bal = {T_Proc, 11, F1v_bal, 6, -1, 0, 0, {{3, "bal"}}};

int F5j_sql (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5j_sql = {T_Proc, 11, F5j_sql, 2, -1, 0, 0, {{3, "sql"}}};

int F3q_FillArc (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3q_FillArc = {T_Proc, 11, F3q_FillArc, -1, -1, 0, 0, {{7, "FillArc"}}};

int F63_filepair (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF63_filepair = {T_Proc, 11, F63_filepair, 0, -1, 0, 0, {{8, "filepair"}}};

int F2x_writes (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2x_writes = {T_Proc, 11, F2x_writes, -1, -1, 0, 0, {{6, "writes"}}};

int F36_Bg (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF36_Bg = {T_Proc, 11, F36_Bg, -1, -1, 0, 0, {{2, "Bg"}}};

int F5a_MultMatrix (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5a_MultMatrix = {T_Proc, 11, F5a_MultMatrix, -1, -1, 0, 0, {{10, "MultMatrix"}}};

int F4r_DrawTorus (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4r_DrawTorus = {T_Proc, 11, F4r_DrawTorus, -1, -1, 0, 0, {{9, "DrawTorus"}}};

int F57_Texture (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF57_Texture = {T_Proc, 11, F57_Texture, -1, -1, 0, 0, {{7, "Texture"}}};

int F07_loadfunc (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF07_loadfunc = {T_Proc, 11, F07_loadfunc, 2, -1, 0, 0, {{8, "loadfunc"}}};

int F3j_DrawPolygon (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3j_DrawPolygon = {T_Proc, 11, F3j_DrawPolygon, -1, -1, 0, 0, {{11, "DrawPolygon"}}};

int F4i_WinButton (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4i_WinButton = {T_Proc, 11, F4i_WinButton, -1, -1, 0, 0, {{9, "WinButton"}}};

int F0z_ord (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0z_ord = {T_Proc, 11, F0z_ord, 1, -1, 0, 0, {{3, "ord"}}};

static int P000_A_initially (int r_nargs, dptr r_args,dptr r_rslt, continuation r_s_cont);
B_IProc(2) BP000_A_initially = {T_Proc, 13, P000_A_initially, 1, 0, 0, 0, {
   {11, "A_initially"},
   {4, "self"},
   }};

int F1l_center (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1l_center = {T_Proc, 11, F1l_center, 3, -1, 0, 0, {{6, "center"}}};

int F4s_DrawCube (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4s_DrawCube = {T_Proc, 11, F4s_DrawCube, -1, -1, 0, 0, {{8, "DrawCube"}}};

int F53_PushRotate (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF53_PushRotate = {T_Proc, 11, F53_PushRotate, -1, -1, 0, 0, {{10, "PushRotate"}}};

int F0u_ixor (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0u_ixor = {T_Proc, 11, F0u_ixor, 2, -1, 0, 0, {{4, "ixor"}}};

int F11_runerr (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF11_runerr = {T_Proc, 11, F11_runerr, -2, -1, 0, 0, {{6, "runerr"}}};

int F6d_setgid (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6d_setgid = {T_Proc, 11, F6d_setgid, 1, -1, 0, 0, {{6, "setgid"}}};

static int R00b_posix_hostent (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(4) BR00b_posix_hostent = {T_Proc, 17, R00b_posix_hostent, 3, -2, 7, 1, {
   {13, "posix_hostent"},
   {4, "name"},
   {7, "aliases"},
   {9, "addresses"},
   }};

int F5i_dbproduct (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5i_dbproduct = {T_Proc, 11, F5i_dbproduct, 1, -1, 0, 0, {{9, "dbproduct"}}};

int F5c_WindowContents (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5c_WindowContents = {T_Proc, 11, F5c_WindowContents, -1, -1, 0, 0, {{14, "WindowContents"}}};

int F0s_iand (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0s_iand = {T_Proc, 11, F0s_iand, 2, -1, 0, 0, {{4, "iand"}}};

int F0v_icom (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0v_icom = {T_Proc, 11, F0v_icom, 1, -1, 0, 0, {{4, "icom"}}};

int F1e_condvar (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1e_condvar = {T_Proc, 11, F1e_condvar, -1, -1, 0, 0, {{7, "condvar"}}};

int F7o_pattern_stringmethodcall (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7o_pattern_stringmethodcall = {T_Proc, 11, F7o_pattern_stringmethodcall, 1, -1, 0, 0, {{24, "pattern_stringmethodcall"}}};

int F5b_Refresh (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5b_Refresh = {T_Proc, 11, F5b_Refresh, -1, -1, 0, 0, {{7, "Refresh"}}};

int F77_pattern_match (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF77_pattern_match = {T_Proc, 11, F77_pattern_match, 2, -1, 0, 0, {{13, "pattern_match"}}};

int F3t_FillRectangle (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3t_FillRectangle = {T_Proc, 11, F3t_FillRectangle, -1, -1, 0, 0, {{13, "FillRectangle"}}};

int F59_Normals (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF59_Normals = {T_Proc, 11, F59_Normals, -1, -1, 0, 0, {{7, "Normals"}}};

int F4m_WinColorDialog (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4m_WinColorDialog = {T_Proc, 11, F4m_WinColorDialog, -1, -1, 0, 0, {{14, "WinColorDialog"}}};

int F01_cset (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF01_cset = {T_Proc, 11, F01_cset, 1, -1, 0, 0, {{4, "cset"}}};

int F5n_getpid (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5n_getpid = {T_Proc, 11, F5n_getpid, 0, -1, 0, 0, {{6, "getpid"}}};

int F5e_dbcolumns (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5e_dbcolumns = {T_Proc, 11, F5e_dbcolumns, 2, -1, 0, 0, {{9, "dbcolumns"}}};

int F6m_getrusage (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6m_getrusage = {T_Proc, 11, F6m_getrusage, 1, -1, 0, 0, {{9, "getrusage"}}};

int F68_getuid (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF68_getuid = {T_Proc, 11, F68_getuid, 0, -1, 0, 0, {{6, "getuid"}}};

int F0g_dtor (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0g_dtor = {T_Proc, 11, F0g_dtor, 1, -1, 0, 0, {{4, "dtor"}}};

int F4b_Uncouple (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4b_Uncouple = {T_Proc, 11, F4b_Uncouple, 1, -1, 0, 0, {{8, "Uncouple"}}};

int F03_real (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF03_real = {T_Proc, 11, F03_real, 1, -1, 0, 0, {{4, "real"}}};

int F2i_constructor (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2i_constructor = {T_Proc, 11, F2i_constructor, -2, -1, 0, 0, {{11, "constructor"}}};

int F1i_move (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1i_move = {T_Proc, 11, F1i_move, 1, -1, 0, 0, {{4, "move"}}};

int F3w_GotoRC (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3w_GotoRC = {T_Proc, 11, F3w_GotoRC, -1, -1, 0, 0, {{6, "GotoRC"}}};

int F42_PaletteKey (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF42_PaletteKey = {T_Proc, 11, F42_PaletteKey, -1, -1, 0, 0, {{10, "PaletteKey"}}};

int F2m_getenv (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2m_getenv = {T_Proc, 11, F2m_getenv, 1, -1, 0, 0, {{6, "getenv"}}};

int F4u_DrawCylinder (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4u_DrawCylinder = {T_Proc, 11, F4u_DrawCylinder, -1, -1, 0, 0, {{12, "DrawCylinder"}}};

int F2b_list (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2b_list = {T_Proc, 11, F2b_list, 2, -1, 0, 0, {{4, "list"}}};

int F1x_many (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1x_many = {T_Proc, 11, F1x_many, 4, -1, 0, 0, {{4, "many"}}};

int F5q_readlink (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5q_readlink = {T_Proc, 11, F5q_readlink, 1, -1, 0, 0, {{8, "readlink"}}};

static int R008_posix_group (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(5) BR008_posix_group = {T_Proc, 19, R008_posix_group, 4, -2, 4, 1, {
   {11, "posix_group"},
   {4, "name"},
   {6, "passwd"},
   {3, "gid"},
   {7, "members"},
   }};

int F5w_rmdir (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5w_rmdir = {T_Proc, 11, F5w_rmdir, 1, -1, 0, 0, {{5, "rmdir"}}};

int F1j_pos (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1j_pos = {T_Proc, 11, F1j_pos, 1, -1, 0, 0, {{3, "pos"}}};

int F2v_stop (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2v_stop = {T_Proc, 11, F2v_stop, -1, -1, 0, 0, {{4, "stop"}}};

int F2k_close (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2k_close = {T_Proc, 11, F2k_close, 1, -1, 0, 0, {{5, "close"}}};

int F0e_exp (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0e_exp = {T_Proc, 11, F0e_exp, 1, -1, 0, 0, {{3, "exp"}}};

int F2f_put (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2f_put = {T_Proc, 11, F2f_put, -2, -1, 0, 0, {{3, "put"}}};

int F6i_wait (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6i_wait = {T_Proc, 11, F6i_wait, 2, -1, 0, 0, {{4, "wait"}}};

int F5g_dbkeys (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5g_dbkeys = {T_Proc, 11, F5g_dbkeys, 2, -1, 0, 0, {{6, "dbkeys"}}};

int F7x_pattern_assign_onmatch (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7x_pattern_assign_onmatch = {T_Proc, 11, F7x_pattern_assign_onmatch, 2, -1, 0, 0, {{22, "pattern_assign_onmatch"}}};

int F6s_select (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6s_select = {T_Proc, 11, F6s_select, -1, -1, 0, 0, {{6, "select"}}};

int F4l_WinEditRegion (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4l_WinEditRegion = {T_Proc, 11, F4l_WinEditRegion, -1, -1, 0, 0, {{13, "WinEditRegion"}}};

int F33_flush (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF33_flush = {T_Proc, 11, F33_flush, 1, -1, 0, 0, {{5, "flush"}}};

int F2h_table (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2h_table = {T_Proc, 11, F2h_table, -1, -1, 0, 0, {{5, "table"}}};

int F55_IdentityMatrix (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF55_IdentityMatrix = {T_Proc, 11, F55_IdentityMatrix, -1, -1, 0, 0, {{14, "IdentityMatrix"}}};

int F7f_Pos (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7f_Pos = {T_Proc, 11, F7f_Pos, 1, -1, 0, 0, {{3, "Pos"}}};

int F7b_Span (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7b_Span = {T_Proc, 11, F7b_Span, 1, -1, 0, 0, {{4, "Span"}}};

int F62_ioctl (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF62_ioctl = {T_Proc, 11, F62_ioctl, 3, -1, 0, 0, {{5, "ioctl"}}};

int F2d_pull (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2d_pull = {T_Proc, 11, F2d_pull, 2, -1, 0, 0, {{4, "pull"}}};

int F79_Break (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF79_Break = {T_Proc, 11, F79_Break, 1, -1, 0, 0, {{5, "Break"}}};

int F0p_copy (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0p_copy = {T_Proc, 11, F0p_copy, 1, -1, 0, 0, {{4, "copy"}}};

int F47_Raise (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF47_Raise = {T_Proc, 11, F47_Raise, -1, -1, 0, 0, {{5, "Raise"}}};

int F5p_symlink (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5p_symlink = {T_Proc, 11, F5p_symlink, 2, -1, 0, 0, {{7, "symlink"}}};

static int P005_main (int r_nargs, dptr r_args,dptr r_rslt, continuation r_s_cont);
B_IProc(1) BP005_main = {T_Proc, 11, P005_main, 0, 0, 0, 0, {
   {4, "main"},
   }};

static int R001_A__methods (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(2) BR001_A__methods = {T_Proc, 13, R001_A__methods, 1, -2, 0, 1, {
   {10, "A__methods"},
   {9, "initially"},
   }};

int F5d_WSection (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5d_WSection = {T_Proc, 11, F5d_WSection, -1, -1, 0, 0, {{8, "WSection"}}};

int F2z_getche (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2z_getche = {T_Proc, 11, F2z_getche, 0, -1, 0, 0, {{6, "getche"}}};

int F4w_Eye (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4w_Eye = {T_Proc, 11, F4w_Eye, -1, -1, 0, 0, {{3, "Eye"}}};

int F75_StopAudio (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF75_StopAudio = {T_Proc, 11, F75_StopAudio, 1, -1, 0, 0, {{9, "StopAudio"}}};

int F4d_WDefault (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4d_WDefault = {T_Proc, 11, F4d_WDefault, -1, -1, 0, 0, {{8, "WDefault"}}};

int F1t_trim (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1t_trim = {T_Proc, 11, F1t_trim, 3, -1, 0, 0, {{4, "trim"}}};

int F2j_array (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2j_array = {T_Proc, 11, F2j_array, -1, -1, 0, 0, {{5, "array"}}};

int F7d_Breakx (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7d_Breakx = {T_Proc, 11, F7d_Breakx, 1, -1, 0, 0, {{6, "Breakx"}}};

int F4t_DrawSphere (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4t_DrawSphere = {T_Proc, 11, F4t_DrawSphere, -1, -1, 0, 0, {{10, "DrawSphere"}}};

int F6a_getgid (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6a_getgid = {T_Proc, 11, F6a_getgid, 0, -1, 0, 0, {{6, "getgid"}}};

int F7r_pattern_unevalvar (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7r_pattern_unevalvar = {T_Proc, 11, F7r_pattern_unevalvar, 1, -1, 0, 0, {{17, "pattern_unevalvar"}}};

int F3r_FillCircle (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3r_FillCircle = {T_Proc, 11, F3r_FillCircle, -1, -1, 0, 0, {{10, "FillCircle"}}};

int F44_Pending (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF44_Pending = {T_Proc, 11, F44_Pending, -1, -1, 0, 0, {{7, "Pending"}}};

int F5t_chown (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5t_chown = {T_Proc, 11, F5t_chown, 3, -1, 0, 0, {{5, "chown"}}};

int F1p_map (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1p_map = {T_Proc, 11, F1p_map, 3, -1, 0, 0, {{3, "map"}}};

static int R00c_posix_servent (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(5) BR00c_posix_servent = {T_Proc, 19, R00c_posix_servent, 4, -2, 8, 1, {
   {13, "posix_servent"},
   {4, "name"},
   {7, "aliases"},
   {4, "port"},
   {5, "proto"},
   }};

int F28_methods (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF28_methods = {T_Proc, 11, F28_methods, 1, -1, 0, 0, {{7, "methods"}}};

int F70_setservent (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF70_setservent = {T_Proc, 11, F70_setservent, 1, -1, 0, 0, {{10, "setservent"}}};

int F17_variable (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF17_variable = {T_Proc, 11, F17_variable, 1, -1, 0, 0, {{8, "variable"}}};

int F4n_WinFontDialog (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4n_WinFontDialog = {T_Proc, 11, F4n_WinFontDialog, -1, -1, 0, 0, {{13, "WinFontDialog"}}};

int F0y_ishift (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0y_ishift = {T_Proc, 11, F0y_ishift, 2, -1, 0, 0, {{6, "ishift"}}};

int F6q_receive (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6q_receive = {T_Proc, 11, F6q_receive, 1, -1, 0, 0, {{7, "receive"}}};

static int R009_posix_timeval (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(3) BR009_posix_timeval = {T_Proc, 15, R009_posix_timeval, 2, -2, 5, 1, {
   {13, "posix_timeval"},
   {3, "sec"},
   {4, "usec"},
   }};

int F5r_kill (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5r_kill = {T_Proc, 11, F5r_kill, 2, -1, 0, 0, {{4, "kill"}}};

int F1d_unlock (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1d_unlock = {T_Proc, 11, F1d_unlock, -1, -1, 0, 0, {{6, "unlock"}}};

int F3n_EraseArea (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3n_EraseArea = {T_Proc, 11, F3n_EraseArea, -1, -1, 0, 0, {{9, "EraseArea"}}};

int F12_seq (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF12_seq = {T_Proc, 11, F12_seq, 2, -1, 0, 0, {{3, "seq"}}};

static int R006_posix_stat (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(15) BR006_posix_stat = {T_Proc, 39, R006_posix_stat, 14, -2, 2, 1, {
   {10, "posix_stat"},
   {3, "dev"},
   {3, "ino"},
   {4, "mode"},
   {5, "nlink"},
   {3, "uid"},
   {3, "gid"},
   {4, "rdev"},
   {4, "size"},
   {5, "atime"},
   {5, "mtime"},
   {5, "ctime"},
   {7, "blksize"},
   {6, "blocks"},
   {7, "symlink"},
   }};

int F78_Any (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF78_Any = {T_Proc, 11, F78_Any, 1, -1, 0, 0, {{3, "Any"}}};

int F3h_DrawLine (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3h_DrawLine = {T_Proc, 11, F3h_DrawLine, -1, -1, 0, 0, {{8, "DrawLine"}}};

int F6g_crypt (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6g_crypt = {T_Proc, 11, F6g_crypt, 2, -1, 0, 0, {{5, "crypt"}}};

int F2g_set (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2g_set = {T_Proc, 11, F2g_set, -1, -1, 0, 0, {{3, "set"}}};

int F0a_tan (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0a_tan = {T_Proc, 11, F0a_tan, 1, -1, 0, 0, {{3, "tan"}}};

int F51_PushMatrix (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF51_PushMatrix = {T_Proc, 11, F51_PushMatrix, -1, -1, 0, 0, {{10, "PushMatrix"}}};

int F66_fdup (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF66_fdup = {T_Proc, 11, F66_fdup, 2, -1, 0, 0, {{4, "fdup"}}};

int F74_PlayAudio (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF74_PlayAudio = {T_Proc, 11, F74_PlayAudio, 1, -1, 0, 0, {{9, "PlayAudio"}}};

int F05_numeric (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF05_numeric = {T_Proc, 11, F05_numeric, 1, -1, 0, 0, {{7, "numeric"}}};

int F3d_DrawArc (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3d_DrawArc = {T_Proc, 11, F3d_DrawArc, -1, -1, 0, 0, {{7, "DrawArc"}}};

int F7p_pattern_boolfunccall (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7p_pattern_boolfunccall = {T_Proc, 11, F7p_pattern_boolfunccall, 1, -1, 0, 0, {{20, "pattern_boolfunccall"}}};

int F0q_display (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0q_display = {T_Proc, 11, F0q_display, 2, -1, 0, 0, {{7, "display"}}};

int F21_get (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF21_get = {T_Proc, 11, F21_get, 2, -1, 0, 0, {{3, "get"}}};

int F1z_upto (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1z_upto = {T_Proc, 11, F1z_upto, 4, -1, 0, 0, {{4, "upto"}}};

int F23_key (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF23_key = {T_Proc, 11, F23_key, 1, -1, 0, 0, {{3, "key"}}};

int F1g_signal (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1g_signal = {T_Proc, 11, F1g_signal, -1, -1, 0, 0, {{6, "signal"}}};

static int R002_A__mdw_inst_mdw (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BR002_A__mdw_inst_mdw = {T_Proc, 11, R002_A__mdw_inst_mdw, 0, -2, 1, 1, {
   {15, "A__mdw_inst_mdw"},
   }};

int F3k_DrawRectangle (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3k_DrawRectangle = {T_Proc, 11, F3k_DrawRectangle, -1, -1, 0, 0, {{13, "DrawRectangle"}}};

int F39_Color (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF39_Color = {T_Proc, 11, F39_Color, -1, -1, 0, 0, {{5, "Color"}}};

int F5k_dbtables (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5k_dbtables = {T_Proc, 11, F5k_dbtables, 1, -1, 0, 0, {{8, "dbtables"}}};

int F0x_image (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0x_image = {T_Proc, 11, F0x_image, 1, -1, 0, 0, {{5, "image"}}};

int F0l_min (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0l_min = {T_Proc, 11, F0l_min, -1, -1, 0, 0, {{3, "min"}}};

int F0w_pindex_image (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0w_pindex_image = {T_Proc, 11, F0w_pindex_image, 2, -1, 0, 0, {{12, "pindex_image"}}};

int F1r_reverse (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1r_reverse = {T_Proc, 11, F1r_reverse, 1, -1, 0, 0, {{7, "reverse"}}};

int F3b_CopyArea (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3b_CopyArea = {T_Proc, 11, F3b_CopyArea, -1, -1, 0, 0, {{8, "CopyArea"}}};

int F4k_WinMenuBar (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4k_WinMenuBar = {T_Proc, 11, F4k_WinMenuBar, -1, -1, 0, 0, {{10, "WinMenuBar"}}};

int F0c_asin (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0c_asin = {T_Proc, 11, F0c_asin, 1, -1, 0, 0, {{4, "asin"}}};

int F2r_rename (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2r_rename = {T_Proc, 11, F2r_rename, 2, -1, 0, 0, {{6, "rename"}}};

int F15_sortf (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF15_sortf = {T_Proc, 11, F15_sortf, 2, -1, 0, 0, {{5, "sortf"}}};

int F56_MatrixMode (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF56_MatrixMode = {T_Proc, 11, F56_MatrixMode, -1, -1, 0, 0, {{10, "MatrixMode"}}};

int F76_VAttrib (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF76_VAttrib = {T_Proc, 11, F76_VAttrib, -1, -1, 0, 0, {{7, "VAttrib"}}};

int F1k_tab (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1k_tab = {T_Proc, 11, F1k_tab, 1, -1, 0, 0, {{3, "tab"}}};

int F7y_Abort (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7y_Abort = {T_Proc, 11, F7y_Abort, 0, -1, 0, 0, {{5, "Abort"}}};

int F37_Clip (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF37_Clip = {T_Proc, 11, F37_Clip, -1, -1, 0, 0, {{4, "Clip"}}};

int F2l_exit (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2l_exit = {T_Proc, 11, F2l_exit, 1, -1, 0, 0, {{4, "exit"}}};

int F65_fork (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF65_fork = {T_Proc, 11, F65_fork, 0, -1, 0, 0, {{4, "fork"}}};

int F08_sin (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF08_sin = {T_Proc, 11, F08_sin, 1, -1, 0, 0, {{3, "sin"}}};

int F7z_Rem (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7z_Rem = {T_Proc, 11, F7z_Rem, 0, -1, 0, 0, {{3, "Rem"}}};

int F31_chdir (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF31_chdir = {T_Proc, 11, F31_chdir, 1, -1, 0, 0, {{5, "chdir"}}};

int F5m_getppid (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5m_getppid = {T_Proc, 11, F5m_getppid, 0, -1, 0, 0, {{7, "getppid"}}};

int F6k_gtime (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6k_gtime = {T_Proc, 11, F6k_gtime, 1, -1, 0, 0, {{5, "gtime"}}};

int F6f_setpgrp (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6f_setpgrp = {T_Proc, 11, F6f_setpgrp, 0, -1, 0, 0, {{7, "setpgrp"}}};

int F6l_gettimeofday (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6l_gettimeofday = {T_Proc, 11, F6l_gettimeofday, 0, -1, 0, 0, {{12, "gettimeofday"}}};

int F0k_max (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0k_max = {T_Proc, 11, F0k_max, -1, -1, 0, 0, {{3, "max"}}};

int F2n_open (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2n_open = {T_Proc, 11, F2n_open, -3, -1, 0, 0, {{4, "open"}}};

int F4x_Rotate (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4x_Rotate = {T_Proc, 11, F4x_Rotate, -1, -1, 0, 0, {{6, "Rotate"}}};

int F18_fieldnames (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF18_fieldnames = {T_Proc, 11, F18_fieldnames, 1, -1, 0, 0, {{10, "fieldnames"}}};

int F1c_trylock (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1c_trylock = {T_Proc, 11, F1c_trylock, -1, -1, 0, 0, {{7, "trylock"}}};

static int R00d_posix_lock (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(3) BR00d_posix_lock = {T_Proc, 15, R00d_posix_lock, 2, -2, 9, 1, {
   {10, "posix_lock"},
   {5, "value"},
   {3, "pid"},
   }};

int F34_Active (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF34_Active = {T_Proc, 11, F34_Active, 0, -1, 0, 0, {{6, "Active"}}};

int F19_cofail (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF19_cofail = {T_Proc, 11, F19_cofail, 1, -1, 0, 0, {{6, "cofail"}}};

int F2u_where (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2u_where = {T_Proc, 11, F2u_where, 1, -1, 0, 0, {{5, "where"}}};

int F2s_seek (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2s_seek = {T_Proc, 11, F2s_seek, 2, -1, 0, 0, {{4, "seek"}}};

static int R00a_posix_rusage (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(10) BR00a_posix_rusage = {T_Proc, 29, R00a_posix_rusage, 9, -2, 6, 1, {
   {12, "posix_rusage"},
   {5, "utime"},
   {5, "stime"},
   {6, "maxrss"},
   {6, "minflt"},
   {6, "majflt"},
   {7, "inblock"},
   {7, "oublock"},
   {5, "nvcsw"},
   {6, "nivcsw"},
   }};

int F4o_WinOpenDialog (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4o_WinOpenDialog = {T_Proc, 11, F4o_WinOpenDialog, -1, -1, 0, 0, {{13, "WinOpenDialog"}}};

int F2a_oprec (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2a_oprec = {T_Proc, 11, F2a_oprec, 1, -1, 0, 0, {{5, "oprec"}}};

int F64_pipe (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF64_pipe = {T_Proc, 11, F64_pipe, 0, -1, 0, 0, {{4, "pipe"}}};

int F2p_reads (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2p_reads = {T_Proc, 11, F2p_reads, 2, -1, 0, 0, {{5, "reads"}}};

int F0h_rtod (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0h_rtod = {T_Proc, 11, F0h_rtod, 1, -1, 0, 0, {{4, "rtod"}}};

int F73_setenv (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF73_setenv = {T_Proc, 11, F73_setenv, 2, -1, 0, 0, {{6, "setenv"}}};

int F0f_sqrt (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0f_sqrt = {T_Proc, 11, F0f_sqrt, 1, -1, 0, 0, {{4, "sqrt"}}};

int F0r_errorclear (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0r_errorclear = {T_Proc, 11, F0r_errorclear, 0, -1, 0, 0, {{10, "errorclear"}}};

int F1w_find (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF1w_find = {T_Proc, 11, F1w_find, 4, -1, 0, 0, {{4, "find"}}};

int F7t_pattern_alternate (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7t_pattern_alternate = {T_Proc, 11, F7t_pattern_alternate, 2, -1, 0, 0, {{17, "pattern_alternate"}}};

int F7j_Arb (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7j_Arb = {T_Proc, 11, F7j_Arb, 0, -1, 0, 0, {{3, "Arb"}}};

int F6h_umask (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6h_umask = {T_Proc, 11, F6h_umask, 1, -1, 0, 0, {{5, "umask"}}};

int F61_utime (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF61_utime = {T_Proc, 11, F61_utime, 3, -1, 0, 0, {{5, "utime"}}};

int F16_type (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF16_type = {T_Proc, 11, F16_type, 1, -1, 0, 0, {{4, "type"}}};

int F7k_Arbno (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF7k_Arbno = {T_Proc, 11, F7k_Arbno, 1, -1, 0, 0, {{5, "Arbno"}}};

int F0d_atanh (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF0d_atanh = {T_Proc, 11, F0d_atanh, 1, -1, 0, 0, {{5, "atanh"}}};

int F5v_chroot (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF5v_chroot = {T_Proc, 11, F5v_chroot, 1, -1, 0, 0, {{6, "chroot"}}};

int F27_methodnames (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF27_methodnames = {T_Proc, 11, F27_methodnames, 2, -1, 0, 0, {{11, "methodnames"}}};

int F3u_Font (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3u_Font = {T_Proc, 11, F3u_Font, -1, -1, 0, 0, {{4, "Font"}}};

int F46_QueryPointer (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF46_QueryPointer = {T_Proc, 11, F46_QueryPointer, 1, -1, 0, 0, {{12, "QueryPointer"}}};

int F00_abs (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF00_abs = {T_Proc, 11, F00_abs, 1, -1, 0, 0, {{3, "abs"}}};

int F6w_getserv (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6w_getserv = {T_Proc, 11, F6w_getserv, 2, -1, 0, 0, {{7, "getserv"}}};

int F49_WSync (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF49_WSync = {T_Proc, 11, F49_WSync, 1, -1, 0, 0, {{5, "WSync"}}};

int F6j_ctime (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6j_ctime = {T_Proc, 11, F6j_ctime, 1, -1, 0, 0, {{5, "ctime"}}};

int F04_string (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF04_string = {T_Proc, 11, F04_string, -1, -1, 0, 0, {{6, "string"}}};

static int P003_A (int r_nargs, dptr r_args,dptr r_rslt, continuation r_s_cont);
B_IProc(3) BP003_A = {T_Proc, 15, P003_A, 0, 2, 0, 0, {
   {1, "A"},
   {4, "self"},
   {5, "clone"},
   }};

int F4v_DrawDisk (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4v_DrawDisk = {T_Proc, 11, F4v_DrawDisk, -1, -1, 0, 0, {{8, "DrawDisk"}}};

int F80_Fail (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF80_Fail = {T_Proc, 11, F80_Fail, 0, -1, 0, 0, {{4, "Fail"}}};

int F41_PaletteColor (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF41_PaletteColor = {T_Proc, 11, F41_PaletteColor, -1, -1, 0, 0, {{12, "PaletteColor"}}};

int F4a_TextWidth (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4a_TextWidth = {T_Proc, 11, F4a_TextWidth, -1, -1, 0, 0, {{9, "TextWidth"}}};

static int R00e_posix_message (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(3) BR00e_posix_message = {T_Proc, 15, R00e_posix_message, 2, -2, 10, 1, {
   {13, "posix_message"},
   {4, "addr"},
   {3, "msg"},
   }};

int F3z_NewColor (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF3z_NewColor = {T_Proc, 11, F3z_NewColor, -1, -1, 0, 0, {{8, "NewColor"}}};

int F4h_WinPlayMedia (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF4h_WinPlayMedia = {T_Proc, 11, F4h_WinPlayMedia, -1, -1, 0, 0, {{12, "WinPlayMedia"}}};

int F6y_setgrent (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF6y_setgrent = {T_Proc, 11, F6y_setgrent, 0, -1, 0, 0, {{8, "setgrent"}}};

int F2e_push (int r_nargs, dptr r_args, dptr r_rslt, continuation r_s_cont);
B_IProc(1) BF2e_push = {T_Proc, 11, F2e_push, -2, -1, 0, 0, {{4, "push"}}};

#define NGlobals 305
int n_globals = NGlobals;

int n_statics = 0;
struct descrip statics[1];


struct PF005_main {
   struct p_frame *old_pfp;
   dptr old_argp;
   dptr rslt;
   continuation succ_cont;
#ifdef PatternType
   struct b_table *pattern_cache;
#endif
   struct {
      struct tend_desc *previous;
      int num;
      struct descrip d[1];
      } t;
   };

struct PF004_Ainitialize {
   struct p_frame *old_pfp;
   dptr old_argp;
   dptr rslt;
   continuation succ_cont;
#ifdef PatternType
   struct b_table *pattern_cache;
#endif
   struct {
      struct tend_desc *previous;
      int num;
      struct descrip d[1];
      } t;
   };

struct PF003_A {
   struct p_frame *old_pfp;
   dptr old_argp;
   dptr rslt;
   continuation succ_cont;
#ifdef PatternType
   struct b_table *pattern_cache;
#endif
   struct {
      struct tend_desc *previous;
      int num;
      struct descrip d[2];
      } t;
   };

struct PF000_A_initially {
   struct p_frame *old_pfp;
   dptr old_argp;
   dptr rslt;
   continuation succ_cont;
#ifdef PatternType
   struct b_table *pattern_cache;
#endif
   struct {
      struct tend_desc *previous;
      int num;
      struct descrip d[1];
      } t;
   };
/* mdw: sync recnum between iconc and rtl */
#define DYNREC_START 11
