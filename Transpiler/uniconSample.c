/*ICONC*/
/*
 * Tue Jul 13 00:55:41 2021
 * This file was produced by
 *   iconc: Unicon Version 13.2 (iconc).  December 20, 2020
 */
/*
 * command-line:
 *
 * iconc -U1 -fs -o uniconSample -A /tmp/uni15125592 
 *   /tmp/uni13211504-iconc /tmp/uni13870814-iconc 
 */
#include "uniconSample.h"

static B_IProc(2) init_op_tbl[OpTblSz] = {
   {T_Proc, 11, O0v_neqv, 2, -1, 0, 0, {{4, "~==="}}},
   {T_Proc, 11, O0t_lexlt, 2, -1, 0, 0, {{2, "<<"}}},
   {T_Proc, 11, O0i_numeq, 2, -1, 0, 0, {{1, "="}}},
   {T_Proc, 11, O0y_tabmat, 1, -1, 0, 0, {{1, "="}}},
   {T_Proc, 11, O17_diff, 2, -1, 0, 0, {{2, "--"}}},
   {T_Proc, 11, O0m_numlt, 2, -1, 0, 0, {{1, "<"}}},
   {T_Proc, 11, O14_sect, 3, -1, 0, 0, {{3, "[:]"}}},
   {T_Proc, 11, O05_minus, 2, -1, 0, 0, {{1, "-"}}},
   {T_Proc, 11, O08_neg, 1, -1, 0, 0, {{1, "-"}}},
   {T_Proc, 11, O1a_nonnull, 1, -1, 0, 0, {{1, "\\"}}},
   {T_Proc, 11, O1d_conj, 2, -1, 0, 0, {{1, "&"}}},
   {T_Proc, 11, O04_divide, 2, -1, 0, 0, {{1, "/"}}},
   {T_Proc, 11, O1b_null, 1, -1, 0, 0, {{1, "/"}}},
   {T_Proc, 11, O0a_plus, 2, -1, 0, 0, {{1, "+"}}},
   {T_Proc, 11, O09_number, 1, -1, 0, 0, {{1, "+"}}},
   {T_Proc, 11, O0j_numge, 2, -1, 0, 0, {{2, ">="}}},
   {T_Proc, 11, O03_rcvbk, 2, -1, 0, 0, {{3, "<<@"}}},
   {T_Proc, 11, O07_mult, 2, -1, 0, 0, {{1, "*"}}},
   {T_Proc, 11, O0x_size, 1, -1, 0, 0, {{1, "*"}}},
   {T_Proc, 11, O0e_rswap, 2, -1, 0, 0, {{3, "<->"}}},
   {T_Proc, 11, O0h_lconcat, 2, -1, 0, 0, {{3, "|||"}}},
   {T_Proc, 11, O0u_eqv, 2, -1, 0, 0, {{3, "==="}}},
   {T_Proc, 11, O00_snd, 2, -1, 0, 0, {{2, "@>"}}},
   {T_Proc, 11, O0q_lexge, 2, -1, 0, 0, {{3, ">>="}}},
   {T_Proc, 11, O0l_numle, 2, -1, 0, 0, {{2, "<="}}},
   {T_Proc, 11, O01_sndbk, 2, -1, 0, 0, {{3, "@>>"}}},
   {T_Proc, 11, O11_llist, -1, -1, 0, 0, {{5, "[...]"}}},
   {T_Proc, 11, O0b_powr, 2, -1, 0, 0, {{1, "^"}}},
   {T_Proc, 11, O0w_refresh, 1, -1, 0, 0, {{1, "^"}}},
   {T_Proc, 11, O06_mod, 2, -1, 0, 0, {{1, "%"}}},
   {T_Proc, 11, O0p_lexne, 2, -1, 0, 0, {{3, "~=="}}},
   {T_Proc, 11, O1c_value, 1, -1, 0, 0, {{1, "."}}},
   {T_Proc, 11, O18_inter, 2, -1, 0, 0, {{2, "**"}}},
   {T_Proc, 11, O15_subsc, 2, -1, 0, 0, {{2, "[]"}}},
   {T_Proc, 11, O0d_rasgn, 2, -1, 0, 0, {{2, "<-"}}},
   {T_Proc, 11, O16_compl, 1, -1, 0, 0, {{1, "~"}}},
   {T_Proc, 11, O19_union, 2, -1, 0, 0, {{2, "++"}}},
   {T_Proc, 11, O0s_lexle, 2, -1, 0, 0, {{3, "<<="}}},
   {T_Proc, 11, O0k_numgt, 2, -1, 0, 0, {{1, ">"}}},
   {T_Proc, 11, O0f_swap, 2, -1, 0, 0, {{3, ":=:"}}},
   {T_Proc, 11, O0z_toby, 3, -1, 0, 0, {{3, "..."}}},
   {T_Proc, 11, O10_to, 2, -1, 0, 0, {{3, "..."}}},
   {T_Proc, 11, O0g_cater, 2, -1, 0, 0, {{2, "||"}}},
   {T_Proc, 11, O12_bang, 1, -1, 0, 0, {{1, "!"}}},
   {T_Proc, 11, O13_random, 1, -1, 0, 0, {{1, "?"}}},
   {T_Proc, 11, O0r_lexgt, 2, -1, 0, 0, {{2, ">>"}}},
   {T_Proc, 11, O0o_lexeq, 2, -1, 0, 0, {{2, "=="}}},
   {T_Proc, 11, O0n_numne, 2, -1, 0, 0, {{2, "~="}}},
   {T_Proc, 11, O0c_asgn, 2, -1, 0, 0, {{2, ":="}}},
   {T_Proc, 11, O02_rcv, 2, -1, 0, 0, {{2, "<@"}}}
   };
/*
 * unreachable functions:
 *
 *    Ainitialize
 *    A
 *    A_initially
 *
 * 3 of 4 functions are unreachable.
 */


static struct {word dword; union block *vword;} init_globals[NGlobals] = {
   {D_Proc, (union block *)&BF7w_Fence}, 
   {D_Proc, (union block *)&BF6u_getgr}, 
   {D_Proc, (union block *)&BF5o_hardlink}, 
   {D_Proc, (union block *)&BF0m_args}, 
   {D_Proc, (union block *)&BF02_integer}, 
   {D_Proc, (union block *)&BF3m_DrawString}, 
   {D_Proc, (union block *)&BF2o_read}, 
   {D_Proc, (union block *)&BP004_Ainitialize},
   {D_Proc, (union block *)&BF7q_pattern_boolmethodcall}, 
   {D_Proc, (union block *)&BF2t_system}, 
   {D_Proc, (union block *)&BF3i_DrawPoint}, 
   {D_Proc, (union block *)&BF48_ReadImage}, 
   {D_Proc, (union block *)&BF6e_getpgrp}, 
   {D_Proc, (union block *)&BF2q_remove}, 
   {D_Proc, (union block *)&BF3e_DrawCircle}, 
   {D_Proc, (union block *)&BF52_PushTranslate}, 
   {D_Proc, (union block *)&BF25_classname}, 
   {D_Proc, (union block *)&BF30_kbhit}, 
   {D_Proc, (union block *)&BF1m_detab}, 
   {D_Proc, (union block *)&BF5l_sys_errstr}, 
   {D_Proc, (union block *)&BF3s_FillPolygon}, 
   {D_Proc, (union block *)&BF3x_GotoXY}, 
   {D_Proc, (union block *)&BF6n_lstat}, 
   {D_Proc, (union block *)&BF7l_Succeed}, 
   {D_Proc, (union block *)&BF1h_Attrib}, 
   {D_Proc, (union block *)&BF0t_ior}, 
   {D_Proc, (union block *)&BF1s_right}, 
   {D_Proc, (union block *)&BF4y_Translate}, 
   {D_Proc, (union block *)&BF4q_WinSaveDialog}, 
   {D_Proc, (union block *)&BF5h_dblimits}, 
   {D_Proc, (union block *)&BF6b_getegid}, 
   {D_Proc, (union block *)&BF5z_flock}, 
   {D_Proc, (union block *)&BF6t_getpw}, 
   {D_Proc, (union block *)&BF22_pop}, 
   {D_Proc, (union block *)&BF3p_Fg}, 
   {D_Proc, (union block *)&BF43_Pattern}, 
   {D_Proc, (union block *)&BF72_syswrite}, 
   {D_Proc, (union block *)&BF20_delete}, 
   {D_Proc, (union block *)&BF0b_acos}, 
   {D_Proc, (union block *)&BF06_proc}, 
   {D_Proc, (union block *)&BF7h_Tab}, 
   {D_Proc, (union block *)&BF1b_lock}, 
   {D_Proc, (union block *)&BF7u_pattern_setcur}, 
   {D_Proc, (union block *)&BF50_PopMatrix}, 
   {D_Proc, (union block *)&BF58_Texcoord}, 
   {D_Proc, (union block *)&BF24_insert}, 
   {D_Proc, (union block *)&BF29_methods_fromstr}, 
   {D_Proc, (union block *)&BF0i_atan}, 
   {D_Proc, (union block *)&BF0j_log}, 
   {D_Proc, (union block *)&BF5s_trap}, 
   {D_Proc, (union block *)&BF3v_FreeColor}, 
   {D_Proc, (union block *)&BF5f_dbdriver}, 
   {D_Proc, (union block *)&BF3f_DrawCurve}, 
   {D_Proc, (union block *)&BF45_Pixel}, 
   {D_Proc, (union block *)&BF7g_Rpos}, 
   {D_Proc, (union block *)&BF4c_WAttrib}, 
   {D_Proc, (union block *)&BF1y_match}, 
   {D_Proc, (union block *)&BF6p_send}, 
   {D_Proc, (union block *)&BF6c_setuid}, 
   {D_Proc, (union block *)&BF3a_ColorValue}, 
   {D_Proc, (union block *)&BF4j_WinScrollBar}, 
   {D_Proc, (union block *)&BF5u_chmod}, 
   {D_Proc, (union block *)&BF3l_DrawSegment}, 
   {D_Proc, (union block *)&BF5x_mkdir}, 
   {D_Proc, (union block *)&BF7v_pattern_assign_immediate}, 
   {D_Proc, (union block *)&BF7s_pattern_concat}, 
   {D_Proc, (union block *)&BF7e_Len}, 
   {D_Proc, (union block *)&BF09_cos}, 
   {D_Proc, (union block *)&BF69_geteuid}, 
   {D_Proc, (union block *)&BF38_Clone}, 
   {D_Proc, (union block *)&BF7a_NotAny}, 
   {D_Proc, (union block *)&BF7i_Rtab}, 
   {D_Proc, (union block *)&BF2y_getch}, 
   {D_Proc, (union block *)&BF4e_WFlush}, 
   {D_Proc, (union block *)&BF1u_any}, 
   {D_Proc, (union block *)&BF35_Alert}, 
   {D_Proc, (union block *)&BF3c_Couple}, 
   {D_Proc, (union block *)&BF54_PushScale}, 
   {D_Proc, (union block *)&BF1o_left}, 
   {D_Proc, (union block *)&BF3o_Event}, 
   {D_Proc, (union block *)&BF1n_entab}, 
   {D_Proc, (union block *)&BF71_ready}, 
   {D_Proc, (union block *)&BR007_posix_passwd},
   {D_Proc, (union block *)&BF0n_char}, 
   {D_Proc, (union block *)&BF7n_pattern_stringfunccall}, 
   {D_Proc, (union block *)&BF4z_Scale}, 
   {D_Proc, (union block *)&BF60_fcntl}, 
   {D_Proc, (union block *)&BF1a_mutex}, 
   {D_Proc, (union block *)&BF14_sort}, 
   {D_Proc, (union block *)&BF4g_WinAssociate}, 
   {D_Proc, (union block *)&BF67_exec}, 
   {D_Proc, (union block *)&BF2c_member}, 
   {D_Proc, (union block *)&BF5y_truncate}, 
   {D_Proc, (union block *)&BF7c_Nspan}, 
   {D_Proc, (union block *)&BF32_delay}, 
   {D_Proc, (union block *)&BF0o_collect}, 
   {D_Proc, (union block *)&BF1f_spawn}, 
   {D_Proc, (union block *)&BF3g_DrawImage}, 
   {D_Proc, (union block *)&BF4p_WinSelectDialog}, 
   {D_Proc, (union block *)&BF6v_gethost}, 
   {D_Proc, (union block *)&BF13_serial}, 
   {D_Proc, (union block *)&BF6x_setpwent}, 
   {D_Proc, (union block *)&BF6o_stat}, 
   {D_Proc, (union block *)&BF10_name}, 
   {D_Proc, (union block *)&BF7m_Bal}, 
   {D_Proc, (union block *)&BF2w_write}, 
   {D_Proc, (union block *)&BF40_PaletteChars}, 
   {D_Proc, (union block *)&BF6r_fetch}, 
   {D_Proc, (union block *)&BF26_membernames}, 
   {D_Proc, (union block *)&BF1q_repl}, 
   {D_Proc, (union block *)&BF6z_sethostent}, 
   {D_Proc, (union block *)&BF3y_Lower}, 
   {D_Proc, (union block *)&BF4f_WriteImage}, 
   {D_Proc, (union block *)&BF1v_bal}, 
   {D_Proc, (union block *)&BF5j_sql}, 
   {D_Proc, (union block *)&BF3q_FillArc}, 
   {D_Proc, (union block *)&BF63_filepair}, 
   {D_Proc, (union block *)&BF2x_writes}, 
   {D_Proc, (union block *)&BF36_Bg}, 
   {D_Proc, (union block *)&BF5a_MultMatrix}, 
   {D_Proc, (union block *)&BF4r_DrawTorus}, 
   {D_Proc, (union block *)&BF57_Texture}, 
   {D_Proc, (union block *)&BF07_loadfunc}, 
   {D_Proc, (union block *)&BF3j_DrawPolygon}, 
   {D_Proc, (union block *)&BF4i_WinButton}, 
   {D_Proc, (union block *)&BF0z_ord}, 
   {D_Proc, (union block *)&BP000_A_initially},
   {D_Proc, (union block *)&BF1l_center}, 
   {D_Proc, (union block *)&BF4s_DrawCube}, 
   {D_Proc, (union block *)&BF53_PushRotate}, 
   {D_Proc, (union block *)&BF0u_ixor}, 
   {D_Proc, (union block *)&BF11_runerr}, 
   {D_Proc, (union block *)&BF6d_setgid}, 
   {D_Proc, (union block *)&BR00b_posix_hostent},
   {D_Proc, (union block *)&BF5i_dbproduct}, 
   {D_Proc, (union block *)&BF5c_WindowContents}, 
   {D_Proc, (union block *)&BF0s_iand}, 
   {D_Proc, (union block *)&BF0v_icom}, 
   {D_Proc, (union block *)&BF1e_condvar}, 
   {D_Proc, (union block *)&BF7o_pattern_stringmethodcall}, 
   {D_Proc, (union block *)&BF5b_Refresh}, 
   {D_Proc, (union block *)&BF77_pattern_match}, 
   {D_Proc, (union block *)&BF3t_FillRectangle}, 
   {D_Proc, (union block *)&BF59_Normals}, 
   {D_Proc, (union block *)&BF4m_WinColorDialog}, 
   {D_Proc, (union block *)&BF01_cset}, 
   {D_Proc, (union block *)&BF5n_getpid}, 
   {D_Proc, (union block *)&BF5e_dbcolumns}, 
   {D_Proc, (union block *)&BF6m_getrusage}, 
   {D_Proc, (union block *)&BF68_getuid}, 
   {D_Proc, (union block *)&BF0g_dtor}, 
   {D_Proc, (union block *)&BF4b_Uncouple}, 
   {D_Proc, (union block *)&BF03_real}, 
   {D_Proc, (union block *)&BF2i_constructor}, 
   {D_Proc, (union block *)&BF1i_move}, 
   {D_Proc, (union block *)&BF3w_GotoRC}, 
   {D_Proc, (union block *)&BF42_PaletteKey}, 
   {D_Proc, (union block *)&BF2m_getenv}, 
   {D_Proc, (union block *)&BF4u_DrawCylinder}, 
   {D_Proc, (union block *)&BF2b_list}, 
   {D_Proc, (union block *)&BF1x_many}, 
   {D_Proc, (union block *)&BF5q_readlink}, 
   {D_Proc, (union block *)&BR008_posix_group},
   {D_Proc, (union block *)&BF5w_rmdir}, 
   {D_Proc, (union block *)&BF1j_pos}, 
   {D_Proc, (union block *)&BF2v_stop}, 
   {D_Proc, (union block *)&BF2k_close}, 
   {D_Proc, (union block *)&BF0e_exp}, 
   {D_Proc, (union block *)&BF2f_put}, 
   {D_Proc, (union block *)&BF6i_wait}, 
   {D_Proc, (union block *)&BF5g_dbkeys}, 
   {D_Proc, (union block *)&BF7x_pattern_assign_onmatch}, 
   {D_Proc, (union block *)&BF6s_select}, 
   {D_Proc, (union block *)&BF4l_WinEditRegion}, 
   {D_Proc, (union block *)&BF33_flush}, 
   {D_Proc, (union block *)&BF2h_table}, 
   {D_Proc, (union block *)&BF55_IdentityMatrix}, 
   {D_Proc, (union block *)&BF7f_Pos}, 
   {D_Proc, (union block *)&BF7b_Span}, 
   {D_Proc, (union block *)&BF62_ioctl}, 
   {D_Proc, (union block *)&BF2d_pull}, 
   {D_Proc, (union block *)&BF79_Break}, 
   {D_Proc, (union block *)&BF0p_copy}, 
   {D_Proc, (union block *)&BF47_Raise}, 
   {D_Proc, (union block *)&BF5p_symlink}, 
   {D_Proc, (union block *)&BP005_main},
   {D_Proc, (union block *)&BR001_A__methods},
   {D_Proc, (union block *)&BF5d_WSection}, 
   {D_Proc, (union block *)&BF2z_getche}, 
   {D_Proc, (union block *)&BF4w_Eye}, 
   {D_Proc, (union block *)&BF75_StopAudio}, 
   {D_Proc, (union block *)&BF4d_WDefault}, 
   {D_Proc, (union block *)&BF1t_trim}, 
   {D_Proc, (union block *)&BF2j_array}, 
   {D_Proc, (union block *)&BF7d_Breakx}, 
   {D_Proc, (union block *)&BF4t_DrawSphere}, 
   {D_Proc, (union block *)&BF6a_getgid}, 
   {D_Proc, (union block *)&BF7r_pattern_unevalvar}, 
   {D_Proc, (union block *)&BF3r_FillCircle}, 
   {D_Proc, (union block *)&BF44_Pending}, 
   {D_Proc, (union block *)&BF5t_chown}, 
   {D_Proc, (union block *)&BF1p_map}, 
   {D_Proc, (union block *)&BR00c_posix_servent},
   {D_Proc, (union block *)&BF28_methods}, 
   {D_Proc, (union block *)&BF70_setservent}, 
   {D_Proc, (union block *)&BF17_variable}, 
   {D_Proc, (union block *)&BF4n_WinFontDialog}, 
   {D_Proc, (union block *)&BF0y_ishift}, 
   {D_Proc, (union block *)&BF6q_receive}, 
   {D_Proc, (union block *)&BR009_posix_timeval},
   {D_Proc, (union block *)&BF5r_kill}, 
   {D_Proc, (union block *)&BF1d_unlock}, 
   {D_Proc, (union block *)&BF3n_EraseArea}, 
   {D_Proc, (union block *)&BF12_seq}, 
   {D_Proc, (union block *)&BR006_posix_stat},
   {D_Proc, (union block *)&BF78_Any}, 
   {D_Proc, (union block *)&BF3h_DrawLine}, 
   {D_Proc, (union block *)&BF6g_crypt}, 
   {D_Proc, (union block *)&BF2g_set}, 
   {D_Proc, (union block *)&BF0a_tan}, 
   {D_Proc, (union block *)&BF51_PushMatrix}, 
   {D_Proc, (union block *)&BF66_fdup}, 
   {D_Proc, (union block *)&BF74_PlayAudio}, 
   {D_Proc, (union block *)&BF05_numeric}, 
   {D_Proc, (union block *)&BF3d_DrawArc}, 
   {D_Proc, (union block *)&BF7p_pattern_boolfunccall}, 
   {D_Proc, (union block *)&BF0q_display}, 
   {D_Proc, (union block *)&BF21_get}, 
   {D_Proc, (union block *)&BF1z_upto}, 
   {D_Proc, (union block *)&BF23_key}, 
   {D_Proc, (union block *)&BF1g_signal}, 
   {D_Proc, (union block *)&BR002_A__mdw_inst_mdw},
   {D_Proc, (union block *)&BF3k_DrawRectangle}, 
   {D_Proc, (union block *)&BF39_Color}, 
   {D_Proc, (union block *)&BF5k_dbtables}, 
   {D_Proc, (union block *)&BF0x_image}, 
   {D_Proc, (union block *)&BF0l_min}, 
   {D_Proc, (union block *)&BF0w_pindex_image}, 
   {D_Proc, (union block *)&BF1r_reverse}, 
   {D_Proc, (union block *)&BF3b_CopyArea}, 
   {D_Proc, (union block *)&BF4k_WinMenuBar}, 
   {D_Proc, (union block *)&BF0c_asin}, 
   {D_Proc, (union block *)&BF2r_rename}, 
   {D_Proc, (union block *)&BF15_sortf}, 
   {D_Proc, (union block *)&BF56_MatrixMode}, 
   {D_Proc, (union block *)&BF76_VAttrib}, 
   {D_Proc, (union block *)&BF1k_tab}, 
   {D_Proc, (union block *)&BF7y_Abort}, 
   {D_Proc, (union block *)&BF37_Clip}, 
   {D_Proc, (union block *)&BF2l_exit}, 
   {D_Proc, (union block *)&BF65_fork}, 
   {D_Proc, (union block *)&BF08_sin}, 
   {D_Proc, (union block *)&BF7z_Rem}, 
   {D_Proc, (union block *)&BF31_chdir}, 
   {D_Proc, (union block *)&BF5m_getppid}, 
   {D_Proc, (union block *)&BF6k_gtime}, 
   {D_Proc, (union block *)&BF6f_setpgrp}, 
   {D_Proc, (union block *)&BF6l_gettimeofday}, 
   {D_Proc, (union block *)&BF0k_max}, 
   {D_Proc, (union block *)&BF2n_open}, 
   {D_Proc, (union block *)&BF4x_Rotate}, 
   {D_Proc, (union block *)&BF18_fieldnames}, 
   {D_Proc, (union block *)&BF1c_trylock}, 
   {D_Proc, (union block *)&BR00d_posix_lock},
   {D_Proc, (union block *)&BF34_Active}, 
   {D_Proc, (union block *)&BF19_cofail}, 
   {D_Proc, (union block *)&BF2u_where}, 
   {D_Proc, (union block *)&BF2s_seek}, 
   {D_Proc, (union block *)&BR00a_posix_rusage},
   {D_Proc, (union block *)&BF4o_WinOpenDialog}, 
   {D_Proc, (union block *)&BF2a_oprec}, 
   {D_Proc, (union block *)&BF64_pipe}, 
   {D_Proc, (union block *)&BF2p_reads}, 
   {D_Proc, (union block *)&BF0h_rtod}, 
   {D_Proc, (union block *)&BF73_setenv}, 
   {D_Proc, (union block *)&BF0f_sqrt}, 
   {D_Null},
   {D_Proc, (union block *)&BF0r_errorclear}, 
   {D_Proc, (union block *)&BF1w_find}, 
   {D_Proc, (union block *)&BF7t_pattern_alternate}, 
   {D_Proc, (union block *)&BF7j_Arb}, 
   {D_Proc, (union block *)&BF6h_umask}, 
   {D_Proc, (union block *)&BF61_utime}, 
   {D_Proc, (union block *)&BF16_type}, 
   {D_Proc, (union block *)&BF7k_Arbno}, 
   {D_Proc, (union block *)&BF0d_atanh}, 
   {D_Proc, (union block *)&BF5v_chroot}, 
   {D_Proc, (union block *)&BF27_methodnames}, 
   {D_Proc, (union block *)&BF3u_Font}, 
   {D_Proc, (union block *)&BF46_QueryPointer}, 
   {D_Proc, (union block *)&BF00_abs}, 
   {D_Proc, (union block *)&BF6w_getserv}, 
   {D_Proc, (union block *)&BF49_WSync}, 
   {D_Proc, (union block *)&BF6j_ctime}, 
   {D_Proc, (union block *)&BF04_string}, 
   {D_Proc, (union block *)&BP003_A},
   {D_Proc, (union block *)&BF4v_DrawDisk}, 
   {D_Proc, (union block *)&BF80_Fail}, 
   {D_Proc, (union block *)&BF41_PaletteColor}, 
   {D_Proc, (union block *)&BF4a_TextWidth}, 
   {D_Proc, (union block *)&BR00e_posix_message},
   {D_Proc, (union block *)&BF3z_NewColor}, 
   {D_Proc, (union block *)&BF4h_WinPlayMedia}, 
   {D_Proc, (union block *)&BF6y_setgrent}, 
   {D_Proc, (union block *)&BF2e_push}, 
   };

struct sdescrip init_gnames[NGlobals] = {
   {5, "Fence"},
   {5, "getgr"},
   {8, "hardlink"},
   {4, "args"},
   {7, "integer"},
   {10, "DrawString"},
   {4, "read"},
   {11, "Ainitialize"},
   {22, "pattern_boolmethodcall"},
   {6, "system"},
   {9, "DrawPoint"},
   {9, "ReadImage"},
   {7, "getpgrp"},
   {6, "remove"},
   {10, "DrawCircle"},
   {13, "PushTranslate"},
   {9, "classname"},
   {5, "kbhit"},
   {5, "detab"},
   {10, "sys_errstr"},
   {11, "FillPolygon"},
   {6, "GotoXY"},
   {5, "lstat"},
   {7, "Succeed"},
   {6, "Attrib"},
   {3, "ior"},
   {5, "right"},
   {9, "Translate"},
   {13, "WinSaveDialog"},
   {8, "dblimits"},
   {7, "getegid"},
   {5, "flock"},
   {5, "getpw"},
   {3, "pop"},
   {2, "Fg"},
   {7, "Pattern"},
   {8, "syswrite"},
   {6, "delete"},
   {4, "acos"},
   {4, "proc"},
   {3, "Tab"},
   {4, "lock"},
   {14, "pattern_setcur"},
   {9, "PopMatrix"},
   {8, "Texcoord"},
   {6, "insert"},
   {15, "methods_fromstr"},
   {4, "atan"},
   {3, "log"},
   {4, "trap"},
   {9, "FreeColor"},
   {8, "dbdriver"},
   {9, "DrawCurve"},
   {5, "Pixel"},
   {4, "Rpos"},
   {7, "WAttrib"},
   {5, "match"},
   {4, "send"},
   {6, "setuid"},
   {10, "ColorValue"},
   {12, "WinScrollBar"},
   {5, "chmod"},
   {11, "DrawSegment"},
   {5, "mkdir"},
   {24, "pattern_assign_immediate"},
   {14, "pattern_concat"},
   {3, "Len"},
   {3, "cos"},
   {7, "geteuid"},
   {5, "Clone"},
   {6, "NotAny"},
   {4, "Rtab"},
   {5, "getch"},
   {6, "WFlush"},
   {3, "any"},
   {5, "Alert"},
   {6, "Couple"},
   {9, "PushScale"},
   {4, "left"},
   {5, "Event"},
   {5, "entab"},
   {5, "ready"},
   {12, "posix_passwd"},
   {4, "char"},
   {22, "pattern_stringfunccall"},
   {5, "Scale"},
   {5, "fcntl"},
   {5, "mutex"},
   {4, "sort"},
   {12, "WinAssociate"},
   {4, "exec"},
   {6, "member"},
   {8, "truncate"},
   {5, "Nspan"},
   {5, "delay"},
   {7, "collect"},
   {5, "spawn"},
   {9, "DrawImage"},
   {15, "WinSelectDialog"},
   {7, "gethost"},
   {6, "serial"},
   {8, "setpwent"},
   {4, "stat"},
   {4, "name"},
   {3, "Bal"},
   {5, "write"},
   {12, "PaletteChars"},
   {5, "fetch"},
   {11, "membernames"},
   {4, "repl"},
   {10, "sethostent"},
   {5, "Lower"},
   {10, "WriteImage"},
   {3, "bal"},
   {3, "sql"},
   {7, "FillArc"},
   {8, "filepair"},
   {6, "writes"},
   {2, "Bg"},
   {10, "MultMatrix"},
   {9, "DrawTorus"},
   {7, "Texture"},
   {8, "loadfunc"},
   {11, "DrawPolygon"},
   {9, "WinButton"},
   {3, "ord"},
   {11, "A_initially"},
   {6, "center"},
   {8, "DrawCube"},
   {10, "PushRotate"},
   {4, "ixor"},
   {6, "runerr"},
   {6, "setgid"},
   {13, "posix_hostent"},
   {9, "dbproduct"},
   {14, "WindowContents"},
   {4, "iand"},
   {4, "icom"},
   {7, "condvar"},
   {24, "pattern_stringmethodcall"},
   {7, "Refresh"},
   {13, "pattern_match"},
   {13, "FillRectangle"},
   {7, "Normals"},
   {14, "WinColorDialog"},
   {4, "cset"},
   {6, "getpid"},
   {9, "dbcolumns"},
   {9, "getrusage"},
   {6, "getuid"},
   {4, "dtor"},
   {8, "Uncouple"},
   {4, "real"},
   {11, "constructor"},
   {4, "move"},
   {6, "GotoRC"},
   {10, "PaletteKey"},
   {6, "getenv"},
   {12, "DrawCylinder"},
   {4, "list"},
   {4, "many"},
   {8, "readlink"},
   {11, "posix_group"},
   {5, "rmdir"},
   {3, "pos"},
   {4, "stop"},
   {5, "close"},
   {3, "exp"},
   {3, "put"},
   {4, "wait"},
   {6, "dbkeys"},
   {22, "pattern_assign_onmatch"},
   {6, "select"},
   {13, "WinEditRegion"},
   {5, "flush"},
   {5, "table"},
   {14, "IdentityMatrix"},
   {3, "Pos"},
   {4, "Span"},
   {5, "ioctl"},
   {4, "pull"},
   {5, "Break"},
   {4, "copy"},
   {5, "Raise"},
   {7, "symlink"},
   {4, "main"},
   {10, "A__methods"},
   {8, "WSection"},
   {6, "getche"},
   {3, "Eye"},
   {9, "StopAudio"},
   {8, "WDefault"},
   {4, "trim"},
   {5, "array"},
   {6, "Breakx"},
   {10, "DrawSphere"},
   {6, "getgid"},
   {17, "pattern_unevalvar"},
   {10, "FillCircle"},
   {7, "Pending"},
   {5, "chown"},
   {3, "map"},
   {13, "posix_servent"},
   {7, "methods"},
   {10, "setservent"},
   {8, "variable"},
   {13, "WinFontDialog"},
   {6, "ishift"},
   {7, "receive"},
   {13, "posix_timeval"},
   {4, "kill"},
   {6, "unlock"},
   {9, "EraseArea"},
   {3, "seq"},
   {10, "posix_stat"},
   {3, "Any"},
   {8, "DrawLine"},
   {5, "crypt"},
   {3, "set"},
   {3, "tan"},
   {10, "PushMatrix"},
   {4, "fdup"},
   {9, "PlayAudio"},
   {7, "numeric"},
   {7, "DrawArc"},
   {20, "pattern_boolfunccall"},
   {7, "display"},
   {3, "get"},
   {4, "upto"},
   {3, "key"},
   {6, "signal"},
   {15, "A__mdw_inst_mdw"},
   {13, "DrawRectangle"},
   {5, "Color"},
   {8, "dbtables"},
   {5, "image"},
   {3, "min"},
   {12, "pindex_image"},
   {7, "reverse"},
   {8, "CopyArea"},
   {10, "WinMenuBar"},
   {4, "asin"},
   {6, "rename"},
   {5, "sortf"},
   {10, "MatrixMode"},
   {7, "VAttrib"},
   {3, "tab"},
   {5, "Abort"},
   {4, "Clip"},
   {4, "exit"},
   {4, "fork"},
   {3, "sin"},
   {3, "Rem"},
   {5, "chdir"},
   {7, "getppid"},
   {5, "gtime"},
   {7, "setpgrp"},
   {12, "gettimeofday"},
   {3, "max"},
   {4, "open"},
   {6, "Rotate"},
   {10, "fieldnames"},
   {7, "trylock"},
   {10, "posix_lock"},
   {6, "Active"},
   {6, "cofail"},
   {5, "where"},
   {4, "seek"},
   {12, "posix_rusage"},
   {13, "WinOpenDialog"},
   {5, "oprec"},
   {4, "pipe"},
   {5, "reads"},
   {4, "rtod"},
   {6, "setenv"},
   {4, "sqrt"},
   {8, "A__oprec"},
   {10, "errorclear"},
   {4, "find"},
   {17, "pattern_alternate"},
   {3, "Arb"},
   {5, "umask"},
   {5, "utime"},
   {4, "type"},
   {5, "Arbno"},
   {5, "atanh"},
   {6, "chroot"},
   {11, "methodnames"},
   {4, "Font"},
   {12, "QueryPointer"},
   {3, "abs"},
   {7, "getserv"},
   {5, "WSync"},
   {5, "ctime"},
   {6, "string"},
   {1, "A"},
   {8, "DrawDisk"},
   {4, "Fail"},
   {12, "PaletteColor"},
   {9, "TextWidth"},
   {13, "posix_message"},
   {8, "NewColor"},
   {12, "WinPlayMedia"},
   {8, "setgrent"},
   {4, "push"},
   };

struct b_proc *builtins[NGlobals] = {
   (struct b_proc *)&BF7w_Fence,
   (struct b_proc *)&BF6u_getgr,
   (struct b_proc *)&BF5o_hardlink,
   (struct b_proc *)&BF0m_args,
   (struct b_proc *)&BF02_integer,
   (struct b_proc *)&BF3m_DrawString,
   (struct b_proc *)&BF2o_read,
   0,
   (struct b_proc *)&BF7q_pattern_boolmethodcall,
   (struct b_proc *)&BF2t_system,
   (struct b_proc *)&BF3i_DrawPoint,
   (struct b_proc *)&BF48_ReadImage,
   (struct b_proc *)&BF6e_getpgrp,
   (struct b_proc *)&BF2q_remove,
   (struct b_proc *)&BF3e_DrawCircle,
   (struct b_proc *)&BF52_PushTranslate,
   (struct b_proc *)&BF25_classname,
   (struct b_proc *)&BF30_kbhit,
   (struct b_proc *)&BF1m_detab,
   (struct b_proc *)&BF5l_sys_errstr,
   (struct b_proc *)&BF3s_FillPolygon,
   (struct b_proc *)&BF3x_GotoXY,
   (struct b_proc *)&BF6n_lstat,
   (struct b_proc *)&BF7l_Succeed,
   (struct b_proc *)&BF1h_Attrib,
   (struct b_proc *)&BF0t_ior,
   (struct b_proc *)&BF1s_right,
   (struct b_proc *)&BF4y_Translate,
   (struct b_proc *)&BF4q_WinSaveDialog,
   (struct b_proc *)&BF5h_dblimits,
   (struct b_proc *)&BF6b_getegid,
   (struct b_proc *)&BF5z_flock,
   (struct b_proc *)&BF6t_getpw,
   (struct b_proc *)&BF22_pop,
   (struct b_proc *)&BF3p_Fg,
   (struct b_proc *)&BF43_Pattern,
   (struct b_proc *)&BF72_syswrite,
   (struct b_proc *)&BF20_delete,
   (struct b_proc *)&BF0b_acos,
   (struct b_proc *)&BF06_proc,
   (struct b_proc *)&BF7h_Tab,
   (struct b_proc *)&BF1b_lock,
   (struct b_proc *)&BF7u_pattern_setcur,
   (struct b_proc *)&BF50_PopMatrix,
   (struct b_proc *)&BF58_Texcoord,
   (struct b_proc *)&BF24_insert,
   (struct b_proc *)&BF29_methods_fromstr,
   (struct b_proc *)&BF0i_atan,
   (struct b_proc *)&BF0j_log,
   (struct b_proc *)&BF5s_trap,
   (struct b_proc *)&BF3v_FreeColor,
   (struct b_proc *)&BF5f_dbdriver,
   (struct b_proc *)&BF3f_DrawCurve,
   (struct b_proc *)&BF45_Pixel,
   (struct b_proc *)&BF7g_Rpos,
   (struct b_proc *)&BF4c_WAttrib,
   (struct b_proc *)&BF1y_match,
   (struct b_proc *)&BF6p_send,
   (struct b_proc *)&BF6c_setuid,
   (struct b_proc *)&BF3a_ColorValue,
   (struct b_proc *)&BF4j_WinScrollBar,
   (struct b_proc *)&BF5u_chmod,
   (struct b_proc *)&BF3l_DrawSegment,
   (struct b_proc *)&BF5x_mkdir,
   (struct b_proc *)&BF7v_pattern_assign_immediate,
   (struct b_proc *)&BF7s_pattern_concat,
   (struct b_proc *)&BF7e_Len,
   (struct b_proc *)&BF09_cos,
   (struct b_proc *)&BF69_geteuid,
   (struct b_proc *)&BF38_Clone,
   (struct b_proc *)&BF7a_NotAny,
   (struct b_proc *)&BF7i_Rtab,
   (struct b_proc *)&BF2y_getch,
   (struct b_proc *)&BF4e_WFlush,
   (struct b_proc *)&BF1u_any,
   (struct b_proc *)&BF35_Alert,
   (struct b_proc *)&BF3c_Couple,
   (struct b_proc *)&BF54_PushScale,
   (struct b_proc *)&BF1o_left,
   (struct b_proc *)&BF3o_Event,
   (struct b_proc *)&BF1n_entab,
   (struct b_proc *)&BF71_ready,
   0,
   (struct b_proc *)&BF0n_char,
   (struct b_proc *)&BF7n_pattern_stringfunccall,
   (struct b_proc *)&BF4z_Scale,
   (struct b_proc *)&BF60_fcntl,
   (struct b_proc *)&BF1a_mutex,
   (struct b_proc *)&BF14_sort,
   (struct b_proc *)&BF4g_WinAssociate,
   (struct b_proc *)&BF67_exec,
   (struct b_proc *)&BF2c_member,
   (struct b_proc *)&BF5y_truncate,
   (struct b_proc *)&BF7c_Nspan,
   (struct b_proc *)&BF32_delay,
   (struct b_proc *)&BF0o_collect,
   (struct b_proc *)&BF1f_spawn,
   (struct b_proc *)&BF3g_DrawImage,
   (struct b_proc *)&BF4p_WinSelectDialog,
   (struct b_proc *)&BF6v_gethost,
   (struct b_proc *)&BF13_serial,
   (struct b_proc *)&BF6x_setpwent,
   (struct b_proc *)&BF6o_stat,
   (struct b_proc *)&BF10_name,
   (struct b_proc *)&BF7m_Bal,
   (struct b_proc *)&BF2w_write,
   (struct b_proc *)&BF40_PaletteChars,
   (struct b_proc *)&BF6r_fetch,
   (struct b_proc *)&BF26_membernames,
   (struct b_proc *)&BF1q_repl,
   (struct b_proc *)&BF6z_sethostent,
   (struct b_proc *)&BF3y_Lower,
   (struct b_proc *)&BF4f_WriteImage,
   (struct b_proc *)&BF1v_bal,
   (struct b_proc *)&BF5j_sql,
   (struct b_proc *)&BF3q_FillArc,
   (struct b_proc *)&BF63_filepair,
   (struct b_proc *)&BF2x_writes,
   (struct b_proc *)&BF36_Bg,
   (struct b_proc *)&BF5a_MultMatrix,
   (struct b_proc *)&BF4r_DrawTorus,
   (struct b_proc *)&BF57_Texture,
   (struct b_proc *)&BF07_loadfunc,
   (struct b_proc *)&BF3j_DrawPolygon,
   (struct b_proc *)&BF4i_WinButton,
   (struct b_proc *)&BF0z_ord,
   0,
   (struct b_proc *)&BF1l_center,
   (struct b_proc *)&BF4s_DrawCube,
   (struct b_proc *)&BF53_PushRotate,
   (struct b_proc *)&BF0u_ixor,
   (struct b_proc *)&BF11_runerr,
   (struct b_proc *)&BF6d_setgid,
   0,
   (struct b_proc *)&BF5i_dbproduct,
   (struct b_proc *)&BF5c_WindowContents,
   (struct b_proc *)&BF0s_iand,
   (struct b_proc *)&BF0v_icom,
   (struct b_proc *)&BF1e_condvar,
   (struct b_proc *)&BF7o_pattern_stringmethodcall,
   (struct b_proc *)&BF5b_Refresh,
   (struct b_proc *)&BF77_pattern_match,
   (struct b_proc *)&BF3t_FillRectangle,
   (struct b_proc *)&BF59_Normals,
   (struct b_proc *)&BF4m_WinColorDialog,
   (struct b_proc *)&BF01_cset,
   (struct b_proc *)&BF5n_getpid,
   (struct b_proc *)&BF5e_dbcolumns,
   (struct b_proc *)&BF6m_getrusage,
   (struct b_proc *)&BF68_getuid,
   (struct b_proc *)&BF0g_dtor,
   (struct b_proc *)&BF4b_Uncouple,
   (struct b_proc *)&BF03_real,
   (struct b_proc *)&BF2i_constructor,
   (struct b_proc *)&BF1i_move,
   (struct b_proc *)&BF3w_GotoRC,
   (struct b_proc *)&BF42_PaletteKey,
   (struct b_proc *)&BF2m_getenv,
   (struct b_proc *)&BF4u_DrawCylinder,
   (struct b_proc *)&BF2b_list,
   (struct b_proc *)&BF1x_many,
   (struct b_proc *)&BF5q_readlink,
   0,
   (struct b_proc *)&BF5w_rmdir,
   (struct b_proc *)&BF1j_pos,
   (struct b_proc *)&BF2v_stop,
   (struct b_proc *)&BF2k_close,
   (struct b_proc *)&BF0e_exp,
   (struct b_proc *)&BF2f_put,
   (struct b_proc *)&BF6i_wait,
   (struct b_proc *)&BF5g_dbkeys,
   (struct b_proc *)&BF7x_pattern_assign_onmatch,
   (struct b_proc *)&BF6s_select,
   (struct b_proc *)&BF4l_WinEditRegion,
   (struct b_proc *)&BF33_flush,
   (struct b_proc *)&BF2h_table,
   (struct b_proc *)&BF55_IdentityMatrix,
   (struct b_proc *)&BF7f_Pos,
   (struct b_proc *)&BF7b_Span,
   (struct b_proc *)&BF62_ioctl,
   (struct b_proc *)&BF2d_pull,
   (struct b_proc *)&BF79_Break,
   (struct b_proc *)&BF0p_copy,
   (struct b_proc *)&BF47_Raise,
   (struct b_proc *)&BF5p_symlink,
   0,
   0,
   (struct b_proc *)&BF5d_WSection,
   (struct b_proc *)&BF2z_getche,
   (struct b_proc *)&BF4w_Eye,
   (struct b_proc *)&BF75_StopAudio,
   (struct b_proc *)&BF4d_WDefault,
   (struct b_proc *)&BF1t_trim,
   (struct b_proc *)&BF2j_array,
   (struct b_proc *)&BF7d_Breakx,
   (struct b_proc *)&BF4t_DrawSphere,
   (struct b_proc *)&BF6a_getgid,
   (struct b_proc *)&BF7r_pattern_unevalvar,
   (struct b_proc *)&BF3r_FillCircle,
   (struct b_proc *)&BF44_Pending,
   (struct b_proc *)&BF5t_chown,
   (struct b_proc *)&BF1p_map,
   0,
   (struct b_proc *)&BF28_methods,
   (struct b_proc *)&BF70_setservent,
   (struct b_proc *)&BF17_variable,
   (struct b_proc *)&BF4n_WinFontDialog,
   (struct b_proc *)&BF0y_ishift,
   (struct b_proc *)&BF6q_receive,
   0,
   (struct b_proc *)&BF5r_kill,
   (struct b_proc *)&BF1d_unlock,
   (struct b_proc *)&BF3n_EraseArea,
   (struct b_proc *)&BF12_seq,
   0,
   (struct b_proc *)&BF78_Any,
   (struct b_proc *)&BF3h_DrawLine,
   (struct b_proc *)&BF6g_crypt,
   (struct b_proc *)&BF2g_set,
   (struct b_proc *)&BF0a_tan,
   (struct b_proc *)&BF51_PushMatrix,
   (struct b_proc *)&BF66_fdup,
   (struct b_proc *)&BF74_PlayAudio,
   (struct b_proc *)&BF05_numeric,
   (struct b_proc *)&BF3d_DrawArc,
   (struct b_proc *)&BF7p_pattern_boolfunccall,
   (struct b_proc *)&BF0q_display,
   (struct b_proc *)&BF21_get,
   (struct b_proc *)&BF1z_upto,
   (struct b_proc *)&BF23_key,
   (struct b_proc *)&BF1g_signal,
   0,
   (struct b_proc *)&BF3k_DrawRectangle,
   (struct b_proc *)&BF39_Color,
   (struct b_proc *)&BF5k_dbtables,
   (struct b_proc *)&BF0x_image,
   (struct b_proc *)&BF0l_min,
   (struct b_proc *)&BF0w_pindex_image,
   (struct b_proc *)&BF1r_reverse,
   (struct b_proc *)&BF3b_CopyArea,
   (struct b_proc *)&BF4k_WinMenuBar,
   (struct b_proc *)&BF0c_asin,
   (struct b_proc *)&BF2r_rename,
   (struct b_proc *)&BF15_sortf,
   (struct b_proc *)&BF56_MatrixMode,
   (struct b_proc *)&BF76_VAttrib,
   (struct b_proc *)&BF1k_tab,
   (struct b_proc *)&BF7y_Abort,
   (struct b_proc *)&BF37_Clip,
   (struct b_proc *)&BF2l_exit,
   (struct b_proc *)&BF65_fork,
   (struct b_proc *)&BF08_sin,
   (struct b_proc *)&BF7z_Rem,
   (struct b_proc *)&BF31_chdir,
   (struct b_proc *)&BF5m_getppid,
   (struct b_proc *)&BF6k_gtime,
   (struct b_proc *)&BF6f_setpgrp,
   (struct b_proc *)&BF6l_gettimeofday,
   (struct b_proc *)&BF0k_max,
   (struct b_proc *)&BF2n_open,
   (struct b_proc *)&BF4x_Rotate,
   (struct b_proc *)&BF18_fieldnames,
   (struct b_proc *)&BF1c_trylock,
   0,
   (struct b_proc *)&BF34_Active,
   (struct b_proc *)&BF19_cofail,
   (struct b_proc *)&BF2u_where,
   (struct b_proc *)&BF2s_seek,
   0,
   (struct b_proc *)&BF4o_WinOpenDialog,
   (struct b_proc *)&BF2a_oprec,
   (struct b_proc *)&BF64_pipe,
   (struct b_proc *)&BF2p_reads,
   (struct b_proc *)&BF0h_rtod,
   (struct b_proc *)&BF73_setenv,
   (struct b_proc *)&BF0f_sqrt,
   0,
   (struct b_proc *)&BF0r_errorclear,
   (struct b_proc *)&BF1w_find,
   (struct b_proc *)&BF7t_pattern_alternate,
   (struct b_proc *)&BF7j_Arb,
   (struct b_proc *)&BF6h_umask,
   (struct b_proc *)&BF61_utime,
   (struct b_proc *)&BF16_type,
   (struct b_proc *)&BF7k_Arbno,
   (struct b_proc *)&BF0d_atanh,
   (struct b_proc *)&BF5v_chroot,
   (struct b_proc *)&BF27_methodnames,
   (struct b_proc *)&BF3u_Font,
   (struct b_proc *)&BF46_QueryPointer,
   (struct b_proc *)&BF00_abs,
   (struct b_proc *)&BF6w_getserv,
   (struct b_proc *)&BF49_WSync,
   (struct b_proc *)&BF6j_ctime,
   (struct b_proc *)&BF04_string,
   0,
   (struct b_proc *)&BF4v_DrawDisk,
   (struct b_proc *)&BF80_Fail,
   (struct b_proc *)&BF41_PaletteColor,
   (struct b_proc *)&BF4a_TextWidth,
   0,
   (struct b_proc *)&BF3z_NewColor,
   (struct b_proc *)&BF4h_WinPlayMedia,
   (struct b_proc *)&BF6y_setgrent,
   (struct b_proc *)&BF2e_push,
   };

int main(argc, argv)
int argc;
char **argv;
   {
   struct {
      struct tend_desc *previous;
      int num;
      struct descrip arg_lst;
      } t;

   dynrec_start_set(DYNREC_START);
   op_tbl = (struct b_proc *)init_op_tbl;
   globals = (dptr)init_globals;
   eglobals = &globals[305];
   gnames = (dptr)init_gnames;
   egnames = &gnames[305];
   estatics = &statics[0];
   debug_info = 0;
   line_info = 0;
   err_conv = 0;
   largeints = 0;
   init(*argv, &argc, argv, 0);

   t.arg_lst = nulldesc;
   t.num = 1;
   t.previous = NULL;
   tend = (struct tend_desc *)&t;
   /* main() takes no arguments: construct no list */

   P005_main(1, &t.arg_lst, &trashcan, (continuation)NULL);
   
   c_exit(EXIT_SUCCESS);
   }

static int P005_main(r_nargs, r_args, r_rslt, r_s_cont)
int r_nargs;
dptr r_args;
dptr r_rslt;
continuation r_s_cont;
{
   struct PF005_main r_f;
   register int r_signal;
   int i;

   CURTSTATE_AND_CE();
   r_f.old_pfp = pfp;
   pfp = (struct p_frame *)&r_f;
   r_f.old_argp = glbl_argp;
   r_f.rslt = r_rslt;
   r_f.succ_cont = r_s_cont;
#ifdef PatternType
   r_f.pattern_cache = NULL;
#endif

   for (i = 0; i < 0; ++i)
      r_f.t.d[i] = nulldesc;
   glbl_argp = &r_f.t.d[0];
   r_f.t.num = 0;
   r_f.t.previous = tend;
   tend = (struct tend_desc *)&r_f.t;

   Poll();
   Poll();
   tend = r_f.t.previous;
   pfp = r_f.old_pfp;
   glbl_argp = r_f.old_argp;
   return A_Resume;
   }

static int P004_Ainitialize(r_nargs, r_args, r_rslt, r_s_cont)
int r_nargs;
dptr r_args;
dptr r_rslt;
continuation r_s_cont;
{
   struct PF004_Ainitialize r_f;
   register int r_signal;
   int i;
   static int first_time = 1;
   CURTSTATE_AND_CE();
   r_f.old_pfp = pfp;
   pfp = (struct p_frame *)&r_f;
   r_f.old_argp = glbl_argp;
   r_f.rslt = r_rslt;
   r_f.succ_cont = r_s_cont;
#ifdef PatternType
   r_f.pattern_cache = NULL;
#endif

   for (i = 0; i < 0; ++i)
      r_f.t.d[i] = nulldesc;
   glbl_argp = &r_f.t.d[0];
   r_f.t.num = 0;
   r_f.t.previous = tend;
   tend = (struct tend_desc *)&r_f.t;

   /*
    * unreachable function.
    */
   }

static int P003_A(r_nargs, r_args, r_rslt, r_s_cont)
int r_nargs;
dptr r_args;
dptr r_rslt;
continuation r_s_cont;
{
   struct PF003_A r_f;
   register int r_signal;
   int i;
   static int first_time = 1;
   CURTSTATE_AND_CE();
   r_f.old_pfp = pfp;
   pfp = (struct p_frame *)&r_f;
   r_f.old_argp = glbl_argp;
   r_f.rslt = r_rslt;
   r_f.succ_cont = r_s_cont;
#ifdef PatternType
   r_f.pattern_cache = NULL;
#endif

   for (i = 0; i < 2; ++i)
      r_f.t.d[i] = nulldesc;
   glbl_argp = &r_f.t.d[2];
   r_f.t.num = 2;
   r_f.t.previous = tend;
   tend = (struct tend_desc *)&r_f.t;

   /*
    * unreachable function.
    */
   }

static int P000_A_initially(r_nargs, r_args, r_rslt, r_s_cont)
int r_nargs;
dptr r_args;
dptr r_rslt;
continuation r_s_cont;
{
   struct PF000_A_initially r_f;
   register int r_signal;
   int i;

   CURTSTATE_AND_CE();
   r_f.old_pfp = pfp;
   pfp = (struct p_frame *)&r_f;
   r_f.old_argp = glbl_argp;
   r_f.rslt = r_rslt;
   r_f.succ_cont = r_s_cont;
#ifdef PatternType
   r_f.pattern_cache = NULL;
#endif

   for (i = 0; i < 0; ++i)
      r_f.t.d[i] = nulldesc;
   for (i = 0; i < 1; ++i)
      if (i < r_nargs)
         deref(&r_args[i], &r_f.t.d[i + 0]);
      else
         r_f.t.d[i + 0] = nulldesc;
   glbl_argp = &r_f.t.d[0];
   r_f.t.num = 1;
   r_f.t.previous = tend;
   tend = (struct tend_desc *)&r_f.t;

   /*
    * unreachable function.
    */
   }

static int R001_A__methods(r_nargs, r_args, r_rslt, r_s_cont)
int r_nargs;
dptr r_args;
dptr r_rslt;
continuation r_s_cont;
   {
   register int i;
   register struct b_record *rp;
   CURTSTATE();

   rp = alcrecd(1, (union block *)&BR001_A__methods);
   if (rp == NULL) {
      err_msg(307, NULL);
      }
   for (i = 0; i >= 0; i--)
      if (i < r_nargs)
         deref(&r_args[i], &rp->fields[i]);
      else
         rp->fields[i] = nulldesc;
   r_rslt->vword.bptr = (union block *)rp;
   r_rslt->dword = D_Record;
   return A_Continue;
   }

static int R002_A__mdw_inst_mdw(r_nargs, r_args, r_rslt, r_s_cont)
int r_nargs;
dptr r_args;
dptr r_rslt;
continuation r_s_cont;
   {
   register int i;
   register struct b_record *rp;
   CURTSTATE();

   rp = alcrecd(0, (union block *)&BR002_A__mdw_inst_mdw);
   if (rp == NULL) {
      err_msg(307, NULL);
      }
   for (i = -1; i >= 0; i--)
      if (i < r_nargs)
         deref(&r_args[i], &rp->fields[i]);
      else
         rp->fields[i] = nulldesc;
   r_rslt->vword.bptr = (union block *)rp;
   r_rslt->dword = D_Record;
   return A_Continue;
   }

static int R006_posix_stat(r_nargs, r_args, r_rslt, r_s_cont)
int r_nargs;
dptr r_args;
dptr r_rslt;
continuation r_s_cont;
   {
   register int i;
   register struct b_record *rp;
   CURTSTATE();

   rp = alcrecd(14, (union block *)&BR006_posix_stat);
   if (rp == NULL) {
      err_msg(307, NULL);
      }
   for (i = 13; i >= 0; i--)
      if (i < r_nargs)
         deref(&r_args[i], &rp->fields[i]);
      else
         rp->fields[i] = nulldesc;
   r_rslt->vword.bptr = (union block *)rp;
   r_rslt->dword = D_Record;
   return A_Continue;
   }

static int R007_posix_passwd(r_nargs, r_args, r_rslt, r_s_cont)
int r_nargs;
dptr r_args;
dptr r_rslt;
continuation r_s_cont;
   {
   register int i;
   register struct b_record *rp;
   CURTSTATE();

   rp = alcrecd(7, (union block *)&BR007_posix_passwd);
   if (rp == NULL) {
      err_msg(307, NULL);
      }
   for (i = 6; i >= 0; i--)
      if (i < r_nargs)
         deref(&r_args[i], &rp->fields[i]);
      else
         rp->fields[i] = nulldesc;
   r_rslt->vword.bptr = (union block *)rp;
   r_rslt->dword = D_Record;
   return A_Continue;
   }

static int R008_posix_group(r_nargs, r_args, r_rslt, r_s_cont)
int r_nargs;
dptr r_args;
dptr r_rslt;
continuation r_s_cont;
   {
   register int i;
   register struct b_record *rp;
   CURTSTATE();

   rp = alcrecd(4, (union block *)&BR008_posix_group);
   if (rp == NULL) {
      err_msg(307, NULL);
      }
   for (i = 3; i >= 0; i--)
      if (i < r_nargs)
         deref(&r_args[i], &rp->fields[i]);
      else
         rp->fields[i] = nulldesc;
   r_rslt->vword.bptr = (union block *)rp;
   r_rslt->dword = D_Record;
   return A_Continue;
   }

static int R009_posix_timeval(r_nargs, r_args, r_rslt, r_s_cont)
int r_nargs;
dptr r_args;
dptr r_rslt;
continuation r_s_cont;
   {
   register int i;
   register struct b_record *rp;
   CURTSTATE();

   rp = alcrecd(2, (union block *)&BR009_posix_timeval);
   if (rp == NULL) {
      err_msg(307, NULL);
      }
   for (i = 1; i >= 0; i--)
      if (i < r_nargs)
         deref(&r_args[i], &rp->fields[i]);
      else
         rp->fields[i] = nulldesc;
   r_rslt->vword.bptr = (union block *)rp;
   r_rslt->dword = D_Record;
   return A_Continue;
   }

static int R00a_posix_rusage(r_nargs, r_args, r_rslt, r_s_cont)
int r_nargs;
dptr r_args;
dptr r_rslt;
continuation r_s_cont;
   {
   register int i;
   register struct b_record *rp;
   CURTSTATE();

   rp = alcrecd(9, (union block *)&BR00a_posix_rusage);
   if (rp == NULL) {
      err_msg(307, NULL);
      }
   for (i = 8; i >= 0; i--)
      if (i < r_nargs)
         deref(&r_args[i], &rp->fields[i]);
      else
         rp->fields[i] = nulldesc;
   r_rslt->vword.bptr = (union block *)rp;
   r_rslt->dword = D_Record;
   return A_Continue;
   }

static int R00b_posix_hostent(r_nargs, r_args, r_rslt, r_s_cont)
int r_nargs;
dptr r_args;
dptr r_rslt;
continuation r_s_cont;
   {
   register int i;
   register struct b_record *rp;
   CURTSTATE();

   rp = alcrecd(3, (union block *)&BR00b_posix_hostent);
   if (rp == NULL) {
      err_msg(307, NULL);
      }
   for (i = 2; i >= 0; i--)
      if (i < r_nargs)
         deref(&r_args[i], &rp->fields[i]);
      else
         rp->fields[i] = nulldesc;
   r_rslt->vword.bptr = (union block *)rp;
   r_rslt->dword = D_Record;
   return A_Continue;
   }

static int R00c_posix_servent(r_nargs, r_args, r_rslt, r_s_cont)
int r_nargs;
dptr r_args;
dptr r_rslt;
continuation r_s_cont;
   {
   register int i;
   register struct b_record *rp;
   CURTSTATE();

   rp = alcrecd(4, (union block *)&BR00c_posix_servent);
   if (rp == NULL) {
      err_msg(307, NULL);
      }
   for (i = 3; i >= 0; i--)
      if (i < r_nargs)
         deref(&r_args[i], &rp->fields[i]);
      else
         rp->fields[i] = nulldesc;
   r_rslt->vword.bptr = (union block *)rp;
   r_rslt->dword = D_Record;
   return A_Continue;
   }

static int R00d_posix_lock(r_nargs, r_args, r_rslt, r_s_cont)
int r_nargs;
dptr r_args;
dptr r_rslt;
continuation r_s_cont;
   {
   register int i;
   register struct b_record *rp;
   CURTSTATE();

   rp = alcrecd(2, (union block *)&BR00d_posix_lock);
   if (rp == NULL) {
      err_msg(307, NULL);
      }
   for (i = 1; i >= 0; i--)
      if (i < r_nargs)
         deref(&r_args[i], &rp->fields[i]);
      else
         rp->fields[i] = nulldesc;
   r_rslt->vword.bptr = (union block *)rp;
   r_rslt->dword = D_Record;
   return A_Continue;
   }

static int R00e_posix_message(r_nargs, r_args, r_rslt, r_s_cont)
int r_nargs;
dptr r_args;
dptr r_rslt;
continuation r_s_cont;
   {
   register int i;
   register struct b_record *rp;
   CURTSTATE();

   rp = alcrecd(2, (union block *)&BR00e_posix_message);
   if (rp == NULL) {
      err_msg(307, NULL);
      }
   for (i = 1; i >= 0; i--)
      if (i < r_nargs)
         deref(&r_args[i], &rp->fields[i]);
      else
         rp->fields[i] = nulldesc;
   r_rslt->vword.bptr = (union block *)rp;
   r_rslt->dword = D_Record;
   return A_Continue;
   }
