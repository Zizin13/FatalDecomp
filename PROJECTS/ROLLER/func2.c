//-------------------------------------------------------------------------------------------------

int __fastcall draw_smoke(int a1, int a2)
{
  bool v3; // ebx
  int result; // eax
  int v5; // ecx
  float *v6; // ebx
  __int64 v7; // rax
  int v8; // ebp
  float *v9; // esi
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  int v15; // ecx
  int v16; // eax
  double v17; // st7
  double v18; // st7
  double v19; // st7
  int v20; // ebx
  int v21; // [esp+0h] [ebp-34h]
  int v22; // [esp+0h] [ebp-34h]
  int v23; // [esp+4h] [ebp-30h]
  int v24; // [esp+4h] [ebp-30h]
  float *v25; // [esp+8h] [ebp-2Ch]
  int v26; // [esp+10h] [ebp-24h]
  int v27; // [esp+14h] [ebp-20h]
  int v28; // [esp+14h] [ebp-20h]
  int v29; // [esp+1Ch] [ebp-18h]

  v3 = a2 != ViewType[0];
  result = 4 * v3;
  v5 = SelectedView[v3];
  if (!v5 || v5 == 2 || v5 == 7) {
    set_starts(0, a2);
    if (player_type == 2)
      a2 = v3 + 16;
    LODWORD(v7) = 1408 * a2;
    v6 = (float *)&CarSpray[1408 * a2];
    HIDWORD(v7) = 0;
    if (player_type == 2 || (cheat_mode & 0x40) != 0) {
      v7 = -winh;
      LODWORD(v7) = (int)v7 / 2;
      v8 = v7;
    } else {
      v8 = 0;
    }
    v9 = v6;
    v25 = v6 + 352;
    while (1) {
      if (*((int *)v9 + 7) > 0) {
        if (*((_BYTE *)v9 + 40) == 1) {
          v10 = *v9;
          _CHP(v7, HIDWORD(v7));
          v26 = (int)v10;
          v11 = v9[1];
          _CHP(v7, HIDWORD(v7));
          v27 = (int)v11;
          v12 = (double)v26 + v9[3];
          _CHP(v7, HIDWORD(v7));
          v23 = (int)v12;
          v13 = (double)v27 - v9[4];
          _CHP(v7, HIDWORD(v7));
          v21 = (int)v13;
          v14 = v9[6];
          _CHP(v7, HIDWORD(v7));
          LODWORD(v7) = v23;
          v28 = v8 + v27;
          v15 = (int)v14;
          if ((int)v14 <= 0 || v15 >= 100)
            goto LABEL_21;
          CarPol_variable_5 = v23 - v15;
          CarPol_variable_7 = v26 - v15;
          CarPol_variable_8 = v28;
          CarPol_variable_9 = v15 + v26;
          CarPol_variable_4 = v8 + v21;
          CarPol_variable_10 = v28;
          v16 = *((_DWORD *)v9 + 9);
          CarPol_variable_6 = v8 + v21;
          BYTE1(v16) |= 0x20u;
          CarPol_variable_3 = v15 + v23;
          CarPol = v16;
          CarPol_variable_2 = 4;
          if ((v16 & 0x100) == 0) {
          LABEL_20:
            LODWORD(v7) = POLYFLAT(a1, &CarPol);
            goto LABEL_21;
          }
        } else {
          v17 = *v9;
          _CHP(v7, HIDWORD(v7));
          v22 = (int)v17;
          v18 = v9[1];
          _CHP(v7, HIDWORD(v7));
          v24 = (int)v18;
          v19 = v9[6];
          _CHP(v7, HIDWORD(v7));
          v29 = (int)v19;
          LODWORD(v7) = v22;
          v20 = (int)v19;
          HIDWORD(v7) = v8 + v24;
          if ((int)v19 <= 0 || v20 >= 100)
            goto LABEL_21;
          CarPol_variable_3 = v22 + v20;
          CarPol_variable_5 = v22 - v29;
          CarPol_variable_7 = v22 - v29;
          CarPol_variable_8 = v29 + HIDWORD(v7);
          CarPol_variable_9 = v22 + v20;
          CarPol_variable_10 = v29 + HIDWORD(v7);
          *(float *)&v7 = v9[9];
          CarPol_variable_4 = HIDWORD(v7) - v29;
          CarPol = v7;
          CarPol_variable_6 = HIDWORD(v7) - v29;
          CarPol_variable_2 = 4;
          if ((v7 & 0x100) == 0)
            goto LABEL_20;
        }
        LODWORD(v7) = POLYTEX(gfx_size);
      }
    LABEL_21:
      HIDWORD(v7) = v25;
      v9 += 11;
      if (v9 == v25)
        return set_starts(0, v25);
    }
  }
  return result;
}

//-------------------------------------------------------------------------------------------------

int __fastcall test_panel(int a1, char *a2)
{
  int v2; // ecx
  char v3; // dl
  int v4; // ebp
  int v5; // esi
  int v6; // edi
  _BYTE *v7; // esi
  int v8; // eax
  char *v9; // edx
  char v10; // dh
  int v11; // edx
  _BYTE *v12; // ecx
  double v13; // st7
  int i; // esi
  int v15; // edx
  _BYTE *v16; // eax
  int v17; // ebx
  _BYTE *v18; // ecx
  double v19; // st7
  int j; // esi
  int v21; // edx
  _BYTE *v22; // eax
  int v23; // ebx
  int v24; // eax
  int v25; // edi
  int v26; // esi
  int v27; // ebp
  int v28; // eax
  double v29; // st7
  __int64 v30; // rtt
  double v31; // st7
  __int64 v32; // rtt
  int v33; // ecx
  int v34; // ebp
  int v35; // esi
  _BYTE *v36; // esi
  int k; // edi
  int v38; // eax
  long double v39; // st7
  int v40; // ebx
  int v41; // esi
  int v42; // ecx
  int v43; // esi
  int *v44; // eax
  int v45; // esi
  int v46; // ebp
  _BYTE *v47; // edi
  _BYTE *m; // edx
  int v49; // eax
  int v50; // ebx
  int v51; // ebx
  int v52; // esi
  int v53; // edi
  int v54; // ebp
  int v55; // ecx
  int v56; // edx
  int v57; // ebx
  int v58; // edi
  int v59; // ecx
  int v60; // esi
  int v61; // ebp
  int v62; // eax
  int v63; // ecx
  int v64; // ebp
  int v65; // edi
  int v66; // edi
  int v67; // ebp
  int v68; // esi
  int v69; // ecx
  int v70; // ebp
  int v71; // edx
  int v72; // eax
  int v73; // edi
  int v74; // ebx
  int v75; // esi
  int v76; // ebp
  int v77; // esi
  int v78; // ecx
  int v79; // edx
  int v80; // eax
  int v81; // edi
  int v82; // ebx
  int v83; // ecx
  int v84; // edi
  int v85; // esi
  int v86; // ebp
  int v87; // eax
  double v88; // st7
  __int64 v89; // rtt
  double v90; // st7
  __int64 v91; // rtt
  int v92; // ebp
  int v93; // esi
  int v94; // edi
  int v95; // edi
  __int16 v96; // fps
  _BOOL1 v97; // c0
  char v98; // c2
  _BOOL1 v99; // c3
  int v100; // eax
  double v101; // st7
  __int16 v102; // fps
  _BOOL1 v103; // c0
  char v104; // c2
  _BOOL1 v105; // c3
  int v106; // eax
  double v107; // st7
  double v109; // [esp+0h] [ebp-A8h]
  _DWORD v110[3]; // [esp+8h] [ebp-A0h]
  int v111; // [esp+14h] [ebp-94h]
  char *v112; // [esp+18h] [ebp-90h]
  _BYTE *v113; // [esp+1Ch] [ebp-8Ch]
  _BYTE *v114; // [esp+20h] [ebp-88h]
  bool v115; // [esp+24h] [ebp-84h]
  float v116; // [esp+28h] [ebp-80h] BYREF
  float v117; // [esp+2Ch] [ebp-7Ch] BYREF
  float v118; // [esp+30h] [ebp-78h]
  int v119; // [esp+34h] [ebp-74h]
  int v120; // [esp+38h] [ebp-70h]
  int v121; // [esp+3Ch] [ebp-6Ch]
  int v122; // [esp+40h] [ebp-68h]
  int v123; // [esp+44h] [ebp-64h]
  int v124; // [esp+48h] [ebp-60h]
  int v125; // [esp+4Ch] [ebp-5Ch]
  int v126; // [esp+50h] [ebp-58h]
  int v127; // [esp+54h] [ebp-54h]
  int v128; // [esp+58h] [ebp-50h]
  int v129; // [esp+5Ch] [ebp-4Ch]
  int v130; // [esp+60h] [ebp-48h]
  unsigned int v131; // [esp+64h] [ebp-44h]
  unsigned int v132; // [esp+68h] [ebp-40h]
  int v133; // [esp+6Ch] [ebp-3Ch]
  int v134; // [esp+70h] [ebp-38h]
  unsigned int v135; // [esp+74h] [ebp-34h]
  int v136; // [esp+78h] [ebp-30h]
  int v137; // [esp+7Ch] [ebp-2Ch]
  int v138; // [esp+80h] [ebp-28h]
  int v139; // [esp+84h] [ebp-24h]
  int v140; // [esp+88h] [ebp-20h]
  int v141; // [esp+8Ch] [ebp-1Ch]
  int v142; // [esp+90h] [ebp-18h]

  v111 = a1;
  v112 = a2;
  v115 = ViewType[0] != (_DWORD)a2;
  if (winh < 200 || (((unsigned int)&loc_3FFFC + 4) & textures_off) != 0) {
    v123 = scr_size;
    v2 = 308 * (_DWORD)v112;
    v3 = Car_variable_22[308 * (_DWORD)v112];
    scr_size = 64;
    if ((unsigned __int8)v3 >= 8u) {
      v4 = 0;
      v134 = v111 + 1;
      do {
        v5 = winw * (winh - 8) + v134;
        memset(v5, 112, 7);
        v6 = 0;
        v7 = (_BYTE *)(winw + v5);
        do {
          *v7 = 112;
          if ((unsigned __int8)Car_variable_66[v2] > v4)
            memset(v7 + 1, 171, 5);
          v8 = winw;
          ++v6;
          v7[6] = 112;
          v7 += v8;
        } while (v6 < 5);
        memset(v7, 112, 7);
        ++v4;
        v134 += 8;
      } while (v4 < 8);
    }
    if ((textures_off & 0x400) != 0) {
      sprintf(
        &buffer,
        "%3.0f",
        (double)fabs(Car_variable_8[77 * (_DWORD)v112] * func2_c_variable_17 * func2_c_variable_18));
      mini_prt_string(rev_vga, &buffer, winw - 34, winh - 8);
      v9 = &aIkmh[2];
    } else {
      sprintf(&buffer, "%3.0f", (double)fabs(Car_variable_8[77 * (_DWORD)v112] * func2_c_variable_16));
      mini_prt_string(rev_vga, &buffer, winw - 34, winh - 8);
      v9 = aMph;
    }
    mini_prt_string(rev_vga, v9, winw - 18, winh - 8);
    mini_prt_right(rev_vga, &language_buffer_variable_24, winw - 10, winh - 16);
    v10 = Car_variable_30[308 * (_DWORD)v112];
    if (v10 < 0) {
      if (v10 == -1)
        sprintf(&buffer, aN);
      else
        sprintf(&buffer, &aNtr[2]);
    } else {
      sprintf(&buffer, "%1i", v10 + 1);
    }
    mini_prt_string(rev_vga, &buffer, winw - 8, winh - 16);
    mini_prt_string(rev_vga, &aNtr[2], winw - 30, winh - 24);
    v11 = winw + v111 - 24;
    v12 = (_BYTE *)(v11 + winw * (winh - 24));
    v13 = Car_variable_28[77 * (_DWORD)v112] * func2_c_variable_19;
    _CHP(308 * (_DWORD)v112, v11);
    v140 = (int)v13;
    if ((int)v13 > 20)
      v140 = 20;
    for (i = 0; i < 7; ++i) {
      if (i && i != 6) {
        v17 = v140;
        v16 = v12 + 1;
        *v12 = 112;
        v15 = 255;
        v12[21] = 112;
      } else {
        v15 = 112;
        v16 = v12;
        v17 = 22;
      }
      memset(v16, v15, v17);
      v12 += winw;
    }
    do_blip(v115, &aOld[2]);
    mini_prt_string(rev_vga, &aOld[2], winw - 30, winh - 32);
    v18 = (_BYTE *)(winw + v111 - 24 + winw * (winh - 32));
    v19 = (func2_c_variable_20 - Car_variable_9[77 * (_DWORD)v112]) * func2_c_variable_19 * func2_c_variable_21;
    _CHP(308 * (_DWORD)v112, winw);
    v139 = (int)v19;
    if ((int)v19 > 20)
      v139 = 20;
    for (j = 0; j < 7; ++j) {
      if (j && j != 6) {
        v23 = v139;
        v22 = v18 + 1;
        *v18 = 112;
        v21 = 231;
        v18[21] = 112;
      } else {
        v21 = 112;
        v22 = v18;
        v23 = 22;
      }
      memset(v22, v21, v23);
      v18 += winw;
    }
    mini_prt_right(rev_vga, language_buffer_variable_4, winw - 14, 4);
    v24 = Car_variable_31[308 * (_DWORD)v112];
    if (v24 <= 0)
      v24 = 1;
    if (v24 > 99)
      v24 = 99;
    sprintf(&buffer, "%2i", v24);
    mini_prt_string(rev_vga, &buffer, winw - 12, 4);
    if (game_type >= 2) {
      v25 = 1;
      v131 = 308 * (_DWORD)v112;
      v128 = 308 * (_DWORD)v112;
      v26 = 8;
      v27 = 24 * (_DWORD)v112 + 4;
      do {
        sprintf(&buffer, "%s %i", language_buffer_variable_4, v25);
        mini_prt_string(rev_vga, &buffer, 2, v26);
        v28 = Car_variable_31[v128];
        if (v25 < v28) {
          v29 = *(float *)((char *)&trial_times + v27) * func2_c_variable_20;
          _CHP(v28, &buffer);
          buffer_variable_8 = 0;
          LODWORD(v30) = (int)v29;
          HIDWORD(v30) = (int)v29 >> 31;
          buffer_variable_7 = v30 % 10 + 48;
          LODWORD(v30) = (int)v29;
          buffer_variable_6 = (int)(v30 / 10) % 10 + 48;
          buffer_variable_5 = 58;
          buffer_variable_4 = (int)(v30 / 10) / 10 % 10 + 48;
          buffer_variable_3 = (int)(v30 / 10) / 10 / 10 % 6 + 48;
          v141 = (int)(v30 / 10) / 10 / 10 / 6;
          buffer_variable_1 = v141 % 10 + 48;
          buffer_variable_2 = 58;
          buffer = v141 / 10 % 10 + 48;
          mini_prt_string(rev_vga, &buffer, 30, v26);
        }
        if (v25 == Car_variable_31[v131]) {
          v31 = Car_variable_52[v131 / 4] * func2_c_variable_20;
          _CHP(v131, &buffer);
          LODWORD(v32) = (int)v31;
          HIDWORD(v32) = (int)v31 >> 31;
          buffer_variable_7 = v32 % 10 + 48;
          LODWORD(v32) = (int)v31;
          buffer_variable_5 = 58;
          buffer_variable_6 = (int)(v32 / 10) % 10 + 48;
          buffer_variable_4 = (int)(v32 / 10) / 10 % 10 + 48;
          buffer_variable_2 = 58;
          buffer_variable_3 = (int)(v32 / 10) / 10 / 10 % 6 + 48;
          v141 = (int)(v32 / 10) / 10 / 10 / 6;
          buffer_variable_1 = v141 % 10 + 48;
          buffer_variable_8 = 0;
          buffer = v141 / 10 % 10 + 48;
          mini_prt_string(rev_vga, &buffer, 30, v26);
        }
        v27 += 4;
        ++v25;
        v26 += 8;
      } while (v25 < 6);
      scr_size = v123;
    } else {
      mini_prt_right(rev_vga, language_buffer_variable_22, winw - 14, 12);
      sprintf(&buffer, "%2i", (unsigned __int8)Car_variable_32[308 * (_DWORD)v112] + 1);
      mini_prt_string(rev_vga, &buffer, winw - 12, 12);
      mini_prt_right(rev_vga, &language_buffer_variable_23, winw - 14, 20);
      sprintf(&buffer, "%2i", Car_variable_23[308 * (_DWORD)v112]);
      mini_prt_string(rev_vga, &buffer, winw - 12, 20);
      scr_size = v123;
    }
  } else {
    if (showversion) {
      a2 = VersionString;
      prt_string(rev_vga_variable_1, VersionString, 150, 190);
    }
    v33 = 308 * (_DWORD)v112;
    if ((unsigned __int8)Car_variable_22[308 * (_DWORD)v112] >= 8u) {
      v34 = 0;
      v129 = v111 + 1;
      do {
        v35 = v129 + winw * (winh - 8);
        memset(v35, 112, 7);
        v36 = (_BYTE *)(winw + v35);
        for (k = 0; k < 5; ++k) {
          *v36 = 112;
          if ((unsigned __int8)Car_variable_66[v33] > v34)
            memset(v36 + 1, 171, 5);
          v38 = winw;
          v36[6] = 112;
          v36 += v38;
        }
        memset(v36, 112, 7);
        a2 = (char *)(v129 + 8);
        ++v34;
        v129 += 8;
      } while (v34 < 8);
    }
    if (player_type == 2 || (cheat_mode & 0x40) != 0) {
      a2 = (char *)(4 * (winw >> 31));
      v119 = ((winw - (int)&a2[__CFSHL__(winw >> 31, 2)]) >> 2) + 157;
    } else {
      v119 = 157;
    }
    v127 = rev_vga_variable_2;
    v121 = rev_vga_variable_2;
    if ((textures_off & 0x400) != 0)
      v39 = fabs(Car_variable_8[77 * (_DWORD)v112] * func2_c_variable_13) * func2_c_variable_14 * func2_c_variable_15;
    else
      v39 = fabs(Car_variable_8[77 * (_DWORD)v112] * func2_c_variable_13);
    _CHP(308 * (_DWORD)v112, a2);
    v124 = (int)v39;
    v40 = (int)v39;
    v41 = 0;
    v42 = 0;
    v125 = 0;
    do {
      v110[v42] = v40 % 10;
      v125 += *(_DWORD *)(v121 + 12 * (v40 % 10 + 9)) - 1;
      ++v42;
      ++v41;
      v40 /= 10;
    } while (v40 > 0);
    v43 = v41 - 1;
    v138 = v43;
    v126 = winw + v111 + winw * ((155 * scr_size) >> 6) - ((44 * scr_size) >> 6);
    if (v125 > 0) {
      v135 = 4 * v43;
      do {
        v142 = 0;
        v44 = (int *)(v121 + 12 * (v110[v135 / 4] + 9));
        v45 = scr_size;
        v46 = *v44;
        v122 = v44[1];
        v47 = (_BYTE *)v126;
        m = (_BYTE *)(v127 + v44[2]);
        v126 += (scr_size * (v46 - 1)) >> 6;
        if (v122 > 0) {
          do {
            v49 = scr_size;
            v114 = v47;
            v113 = m;
            v50 = 0;
            while (v50 < v46) {
              if (*m)
                *v47 = *m;
              v49 -= 64;
              ++v47;
              for (; v49 <= 0; ++v50) {
                ++m;
                v49 += scr_size;
              }
            }
            v45 -= 64;
            for (m = v113; v45 <= 0; ++v142) {
              m += v46;
              v45 += scr_size;
            }
            v47 = &v114[winw];
          } while (v142 < v122);
        }
        v125 -= v46;
        v135 -= 4;
        --v138;
      } while (v125 > 0);
    }
    if ((textures_off & 0x400) != 0)
      v51 = 32;
    else
      v51 = 33;
    print_block(winw + winw * ((172 * scr_size) >> 6) + v111 - ((25 * scr_size) >> 6), rev_vga_variable_2, v51);
    v52 = rev_vga_variable_4;
    v53 = 0;
    v54 = 54;
    v133 = 308 * (_DWORD)v112;
    v55 = (unsigned __int8)Car_variable_22[308 * (_DWORD)v112];
    while (v53 < Car_variable_23[v133]) {
      if (v55 >= 8) {
        v57 = 8;
        v56 = v52;
      } else {
        v56 = v52;
        v57 = v55;
      }
      print_block(winw * ((v54 * scr_size) >> 6) + v111 + ((8 * scr_size) >> 6), v56, v57);
      v54 += 20;
      ++v53;
    }
    v58 = rev_vga_variable_4;
    if ((unsigned __int8)Car_variable_42[v133] >= 9u) {
      print_block(v111 + winw * ((178 * scr_size) >> 6) + winw - ((144 * scr_size) >> 6), rev_vga_variable_4, 8);
      v63 = (unsigned __int8)Car_variable_42[v133];
      v64 = v111;
      v65 = rev_vga_variable_2;
      print_block(
        winw + v111 + winw * ((178 * scr_size) >> 6) - ((122 * scr_size) >> 6),
        rev_vga_variable_2,
        v63 / 10 + 9);
      print_block(winw + v64 + winw * ((178 * scr_size) >> 6) - ((110 * scr_size) >> 6), v65, v63 % 10 + 9);
    } else {
      v59 = 100;
      v60 = 0;
      v61 = 308 * (_DWORD)v112;
      while (v60 < (unsigned __int8)Car_variable_42[v61]) {
        ++v60;
        v62 = v111 + winw * ((178 * scr_size) >> 6) + winw - ((v59 * scr_size) >> 6);
        v59 += 22;
        print_block(v62, v58, 8);
      }
    }
    v66 = 308 * (_DWORD)v112;
    print_damage(winw + v111 + winw * (scr_size << 7 >> 6) - ((80 * scr_size) >> 6), rev_vga_variable_2, v115);
    v67 = v111;
    print_block(
      v111 + winw * ((181 * scr_size) >> 6) + winw - ((14 * scr_size) >> 6),
      rev_vga_variable_2,
      Car_variable_30[v66] + 3);
    print_block(winw + v67 + winw * ((21 * scr_size) >> 6) - ((67 * scr_size) >> 6), rev_vga_variable_2, 19);
    v68 = rev_vga_variable_2;
    v69 = Car_variable_31[v66];
    v70 = rev_vga_variable_2;
    if (v69 <= 0)
      v69 = 1;
    if (v69 > 99)
      v69 = 99;
    if (v69 >= 10)
      v71 = *(_DWORD *)(12 * (v69 / 10) + rev_vga_variable_2 + 264)
      + *(_DWORD *)(12 * (v69 % 10) + rev_vga_variable_2 + 264)
      - 1;
    else
      v71 = *(_DWORD *)(rev_vga_variable_2 + 12 * v69 + 264);
    v72 = (scr_size * (v71 / 2 + 36)) >> 6;
    v73 = winw + v111 + winw * ((25 * scr_size) >> 6) - v72;
    if (v69 >= 10) {
      v141 = v69 / 10 + 22;
      print_block(winw + v111 + winw * ((25 * scr_size) >> 6) - v72, rev_vga_variable_2, v141);
      v73 += winw * (*(_DWORD *)(v70 + 12 * v141) - 1) / 320;
      v74 = v69 % 10 + 22;
    } else {
      v74 = v69 + 22;
    }
    print_block(v73, v68, v74);
    v75 = v111;
    print_block(winw + v111 + winw * ((5 * scr_size) >> 6) - ((52 * scr_size) >> 6), rev_vga_variable_2, 20);
    v76 = 308 * (_DWORD)v112;
    if (game_type >= 2) {
      v84 = 1;
      v132 = 308 * (_DWORD)v112;
      v130 = 308 * (_DWORD)v112;
      v85 = 8;
      v86 = 24 * (_DWORD)v112 + 4;
      do {
        sprintf(&buffer, "%s %i", language_buffer_variable_4, v84);
        mini_prt_string(rev_vga, &buffer, 8, v85);
        v87 = Car_variable_31[v130];
        if (v84 < v87) {
          v88 = *(float *)((char *)&trial_times + v86) * func2_c_variable_20;
          _CHP(v87, &buffer);
          buffer_variable_8 = 0;
          LODWORD(v89) = (int)v88;
          HIDWORD(v89) = (int)v88 >> 31;
          buffer_variable_7 = v89 % 10 + 48;
          LODWORD(v89) = (int)v88;
          buffer_variable_6 = (int)(v89 / 10) % 10 + 48;
          buffer_variable_5 = 58;
          buffer_variable_4 = (int)(v89 / 10) / 10 % 10 + 48;
          buffer_variable_3 = (int)(v89 / 10) / 10 / 10 % 6 + 48;
          buffer_variable_2 = 58;
          v141 = (int)(v89 / 10) / 10 / 10 / 6;
          buffer_variable_1 = v141 % 10 + 48;
          buffer = v141 / 10 % 10 + 48;
          mini_prt_string(rev_vga, &buffer, 40, v85);
        }
        if (v84 == Car_variable_31[v132]) {
          v90 = Car_variable_52[v132 / 4] * func2_c_variable_20;
          _CHP(v132, &buffer);
          LODWORD(v91) = (int)v90;
          HIDWORD(v91) = (int)v90 >> 31;
          buffer_variable_7 = v91 % 10 + 48;
          LODWORD(v91) = (int)v90;
          buffer_variable_6 = (int)(v91 / 10) % 10 + 48;
          buffer_variable_4 = (int)(v91 / 10) / 10 % 10 + 48;
          buffer_variable_3 = (int)(v91 / 10) / 10 / 10 % 6 + 48;
          v141 = (int)(v91 / 10) / 10 / 10 / 6;
          buffer_variable_1 = v141 % 10 + 48;
          buffer_variable_8 = 0;
          buffer_variable_5 = 58;
          buffer_variable_2 = 58;
          buffer = v141 / 10 % 10 + 48;
          mini_prt_string(rev_vga, &buffer, 40, v85);
        }
        v86 += 4;
        ++v84;
        v85 += 8;
      } while (v84 < 6);
    } else {
      print_block(v75 + winw * ((8 * scr_size) >> 6), rev_vga_variable_2, 21);
      v77 = rev_vga_variable_2;
      v78 = (unsigned __int8)Car_variable_32[v76] + 1;
      v137 = rev_vga_variable_2;
      if (v78 >= 10)
        v79 = *(_DWORD *)(rev_vga_variable_2 + 276) + *(_DWORD *)(rev_vga_variable_2 + 12 * (v78 % 10) + 264) - 1;
      else
        v79 = *(_DWORD *)(rev_vga_variable_2 + 12 * v78 + 264);
      v80 = (scr_size * (59 - v79 / 2)) >> 6;
      v81 = v80 + winw * ((12 * scr_size) >> 6) + v111;
      if (v78 >= 10) {
        print_block(v80 + winw * ((12 * scr_size) >> 6) + v111, rev_vga_variable_2, 23);
        v81 += (scr_size * (*(_DWORD *)(v137 + 276) - 1)) >> 6;
        v82 = v78 % 10 + 22;
      } else {
        v82 = v78 + 22;
      }
      print_block(v81, v77, v82);
      v83 = 308 * (_DWORD)v112;
      print_pos(4, 9, (unsigned __int8)Car_variable_32[308 * (_DWORD)v112] - 1);
      print_pos(4, 42, (unsigned __int8)Car_variable_32[v83] + 1);
    }
    if (replaytype != 2) {
      v92 = SelectedView[v115];
      if (v92 != 2 && v92 != 7) {
        v93 = v119 - 2;
        prt_right(rev_vga_variable_1, &language_buffer, v119 - 2, 4);
        v94 = 77 * (_DWORD)v112;
        ShowATime(*(float *)&Car_variable_54[77 * (_DWORD)v112], v119, 4);
        prt_right(rev_vga_variable_1, language_buffer_variable_1, v93, 14);
        v118 = *(float *)&Car_variable_53[v94];
        if (v118 > (double)func2_c_variable_22)
          v118 = -1.0;
        v95 = v119;
        ShowATime(v118, v119, 14);
        calculate_aheadbehindtime(v112, &v116, &v117, 24);
        v100 = prt_right(rev_vga_variable_1, &language_buffer_variable_2, v95 - 2, 24);
        v97 = v116 < (double)func2_c_variable_23;
        v98 = 0;
        v99 = v116 == func2_c_variable_23;
        LOWORD(v100) = v96;
        if (v116 >= (double)func2_c_variable_23) {
          v101 = v116 * func2_c_variable_24;
          _CHP(v100, &language_buffer_variable_2);
          v120 = (int)v101;
          if ((int)v101 == 1)
            sprintf(&buffer, "1 %s", language_buffer_variable_4);
          else
            sprintf(&buffer, "%2i %s", (int)v101, language_buffer_variable_5);
          prt_string(rev_vga_variable_1, &buffer, v119, 24);
        } else {
          ShowATime(v116, v95, 24);
        }
        v106 = prt_right(rev_vga_variable_1, &language_buffer_variable_3, v119 - 2, 34);
        v103 = v117 < (double)func2_c_variable_23;
        v104 = 0;
        v105 = v117 == func2_c_variable_23;
        LOWORD(v106) = v102;
        if (v117 >= (double)func2_c_variable_23) {
          v107 = v117 * func2_c_variable_24;
          _CHP(v106, &language_buffer_variable_3);
          v136 = (int)v107;
          if ((int)v107 == 1)
            sprintf(&buffer, "1 %s", language_buffer_variable_4);
          else
            sprintf(&buffer, "%2i %s", (int)v107, language_buffer_variable_5);
          prt_string(rev_vga_variable_1, &buffer, v119, 34);
        } else {
          ShowATime(v117, v119, 34);
        }
      }
    }
    if (network_on && players > 1) {
      if (network_mes_mode >= 0)
        HIDWORD(v109) = &driver_names[9 * network_mes_mode];
      else
        HIDWORD(v109) = &language_buffer_variable_61;
      sprintf(&buffer, "%s %s", language_buffer_variable_60, (const char *)HIDWORD(v109));
      prt_string(rev_vga_variable_1, &buffer, 2, winh - 12);
    }
  }
  return showmap(v111, v112);
}

//-------------------------------------------------------------------------------------------------

void __fastcall ZoomString(_BYTE *a1, int a2, int a3, int a4, int a5)
{
  int v6; // esi
  int v7; // esi
  int v8; // edx
  _BYTE *v9; // eax
  int v10; // edx
  double v11; // st7
  double v12; // st7
  double v13; // st7
  _BYTE *v14; // esi
  int v15; // edx
  unsigned __int8 v16; // bl
  double v17; // st7
  int v18; // [esp+4h] [ebp-24h]
  int i; // [esp+10h] [ebp-18h]
  float v21; // [esp+14h] [ebp-14h]
  int v22; // [esp+18h] [ebp-10h]

  if (*(float *)&game_scale[a4] < (double)func2_c_variable_25 && zoom_size[a4]
    || !zoom_size[a4] && *(float *)&game_scale[a4] < (double)func2_c_variable_26) {
    if (player_type == 2 || (cheat_mode & 0x40) != 0)
      zoom_x = 320;
    else
      zoom_x = 160;
    if (zoom_size[a4]) {
      if (intro || player_type == 2) {
        zoom_y = 84;
      } else {
        v6 = SelectedView[a4];
        if (v6 == 1 || v6 == 3)
          zoom_y = 130;
        else
          zoom_y = 52;
      }
    } else if (intro || player_type == 2) {
      zoom_y = 95;
    } else {
      v7 = SelectedView[a4];
      if (v7 == 1 || v7 == 3)
        zoom_y = 130;
      else
        zoom_y = 63;
    }
    for (i = 0; *a1; i = (int)v12) {
      v8 = (unsigned __int8)*a1;
      v9 = a1 + 1;
      v10 = *(unsigned __int8 *)(v8 + a2);
      if (v10 == 255) {
        v11 = func2_c_variable_27;
      } else {
        v10 = (*(_DWORD *)(12 * v10 + a3) + 1) << 6;
        v11 = (double)v10;
      }
      v12 = v11 / *(float *)&game_scale[a4] + (double)i;
      _CHP(v9, v10);
    }
    if (i <= 310) {
      v21 = *(float *)&game_scale[a4];
    } else {
      v13 = (double)((i << 6) / 310);
      i = 310;
      v21 = v13;
    }
    v14 = a1;
    zoom_x -= i / 2;
    v22 = 0;
    do {
      if (*v14) {
        if (*v14 != 10) {
          v15 = (unsigned __int8)*v14;
          v16 = *(_BYTE *)(a2 + v15);
          if (v16 == 0xFF) {
            v17 = func2_c_variable_27 / *(float *)&game_scale[a4] + (double)zoom_x;
            _CHP(4 * a4, v15);
            zoom_x = (int)v17;
          } else {
            v18 = zoom_y;
            zoom_y += *(_DWORD *)(a5 + 4 * v16);
            zoom_letter(a2, v21);
            zoom_y = v18;
          }
        }
      } else {
        v22 = -1;
      }
      ++v14;
    } while (!v22);
  }
}

//-------------------------------------------------------------------------------------------------

void __fastcall ZoomSub(_BYTE *a1, int a2, int a3, int a4, int a5)
{
  double v6; // st7
  double v7; // st7
  _BYTE *v8; // eax
  int v9; // edx
  _BYTE *v10; // eax
  int v11; // edx
  double v12; // st7
  double v13; // st7
  double v14; // st7
  _BYTE *v15; // esi
  int v16; // edx
  unsigned __int8 v17; // bl
  double v18; // st7
  int v19; // [esp+4h] [ebp-24h]
  float v21; // [esp+10h] [ebp-18h]
  int v22; // [esp+14h] [ebp-14h]
  int i; // [esp+18h] [ebp-10h]

  if (*(float *)&game_scale[a4] < (double)func2_c_variable_28) {
    if (player_type == 2 || (cheat_mode & 0x40) != 0)
      zoom_x = 320;
    else
      zoom_x = 160;
    if (zoom_size[a4])
      v6 = func2_c_variable_29;
    else
      v6 = func2_c_variable_28;
    v7 = v6 / *(float *)&game_scale[a4] + (double)zoom_y;
    _CHP(a1, 4 * a4);
    zoom_y = (int)v7;
    for (i = 0; *v8; i = (int)v13) {
      v9 = (unsigned __int8)*v8;
      v10 = v8 + 1;
      v11 = *(unsigned __int8 *)(v9 + a2);
      if (v11 == 255) {
        v12 = func2_c_variable_30;
      } else {
        v11 = (*(_DWORD *)(12 * v11 + a3) + 1) << 6;
        v12 = (double)v11;
      }
      v13 = v12 / *(float *)&game_scale[a4] + (double)i;
      _CHP(v10, v11);
    }
    if (i <= 310) {
      v21 = *(float *)&game_scale[a4];
    } else {
      v14 = (double)((i << 6) / 310);
      i = 310;
      v21 = v14;
    }
    v15 = a1;
    zoom_x -= i / 2;
    v22 = 0;
    do {
      if (*v15) {
        if (*v15 != 10) {
          v16 = (unsigned __int8)*v15;
          v17 = *(_BYTE *)(a2 + v16);
          if (v17 == 0xFF) {
            v18 = func2_c_variable_30 / *(float *)&game_scale[a4] + (double)zoom_x;
            _CHP(4 * a4, v16);
            zoom_x = (int)v18;
          } else {
            v19 = zoom_y;
            zoom_y += *(_DWORD *)(a5 + 4 * v17);
            zoom_letter(a2, v21);
            zoom_y = v19;
          }
        }
      } else {
        v22 = -1;
      }
      ++v15;
    } while (!v22);
  }
}

//-------------------------------------------------------------------------------------------------

int __fastcall zoom_letter(int a1, unsigned __int8 a2, _DWORD *a3, _DWORD *a4, char *a5, float a6)
{
  int v6; // esi
  int result; // eax
  int v8; // ebx
  int v9; // edi
  int v10; // edx
  int v11; // esi
  int v12; // eax
  int v13; // ecx
  int v14; // edx
  _BYTE *j; // eax
  int v16; // ebp
  _BYTE *i; // esi
  int v18; // edx
  _DWORD *v19; // edx
  int v21; // [esp+Ch] [ebp-20h]
  _BYTE *v22; // [esp+10h] [ebp-1Ch]
  _BYTE *v23; // [esp+14h] [ebp-18h]
  int v24; // [esp+18h] [ebp-14h]
  int v25; // [esp+1Ch] [ebp-10h]

  v6 = (unsigned __int8)a5[a2];
  if (v6 == 255) {
    result = (int)a3;
    *a3 += 8;
  } else {
    if (a5 == &ascii_conv3)
      v8 = 64;
    else
      v8 = scr_size;
    v9 = *(_DWORD *)(a1 + 12 * v6);
    v10 = 3 * v6;
    v11 = *(_DWORD *)(a1 + 12 * v6 + 4);
    v12 = *(_DWORD *)(a1 + 4 * v10 + 8) + a1;
    v21 = v11;
    v13 = winw * ((scr_size * *a4) >> 6) + screen_pointer;
    v14 = scr_size * *a3;
    _CHP(v12, v14);
    v24 = v8;
    v16 = 0;
    for (i = (_BYTE *)(v13 + (v14 >> 6)); v16 < v21; i = &v22[winw]) {
      v25 = v8;
      v22 = i;
      v23 = j;
      v18 = 0;
      while (v18 < v9) {
        if (*j)
          *i = *j;
        _CHP(j, v18);
        v25 = (int)((double)v25 - a6);
        ++i;
        for (; v25 <= 0; v25 += v8) {
          ++j;
          ++v18;
        }
      }
      _CHP(j, v18);
      v24 = (int)((double)v24 - a6);
      for (j = v23; v24 <= 0; v24 += v8) {
        ++v16;
        j += v9;
      }
    }
    if (a5 == &ascii_conv3) {
      result = ((int)((double)(v9 << 6) / a6) << 6) / scr_size;
      v19 = a3;
    } else {
      v19 = a3;
      result = (int)((double)(v9 << 6) / a6);
    }
    *v19 += result;
  }
  return result;
}

//-------------------------------------------------------------------------------------------------

int __fastcall print_block(char *a1, int a2, int a3)
{
  int v3; // edi
  int result; // eax
  int v6; // ebp
  char *n; // ebx
  int v8; // ebp
  int v9; // edx
  int j; // eax
  char v11; // cl
  char *v12; // ebx
  char *v13; // esi
  char v14; // cl
  char *v15; // ebx
  _BYTE *v16; // esi
  char v17; // cl
  char *v18; // ebx
  _BYTE *v19; // esi
  char v20; // cl
  char *v21; // ebx
  _BYTE *v22; // esi
  char v23; // cl
  char *v24; // ebx
  _BYTE *v25; // esi
  char v26; // cl
  char *v27; // ebx
  _BYTE *v28; // esi
  char v29; // cl
  char *v30; // ebx
  _BYTE *v31; // esi
  char v32; // cl
  int k; // eax
  char v34; // cl
  int v35; // eax
  int v36; // edx
  int v37; // [esp+0h] [ebp-28h]
  char *v38; // [esp+4h] [ebp-24h]
  char *v39; // [esp+8h] [ebp-20h]
  int v40; // [esp+Ch] [ebp-1Ch]
  int i; // [esp+10h] [ebp-18h]
  int m; // [esp+14h] [ebp-14h]

  v3 = scr_size;
  v37 = *(_DWORD *)(a2 + 12 * a3);
  result = 3 * a3;
  v40 = *(_DWORD *)(a2 + 12 * a3 + 4);
  v6 = scr_size;
  n = (char *)(a2 + *(_DWORD *)(a2 + 12 * a3 + 8));
  if (scr_size == 64) {
    v8 = (v37 - (__CFSHL__(v37 >> 31, 3) + 8 * (v37 >> 31))) >> 3;
    v9 = v37 % 8;
    result = 0;
    for (i = 0; result < v40; i = result) {
      for (j = 0; j < v8; a1 = v31 + 1) {
        v11 = *n;
        v12 = n + 1;
        if (v11)
          *a1 = v11;
        v13 = a1 + 1;
        v14 = *v12;
        v15 = v12 + 1;
        if (v14)
          *v13 = v14;
        v16 = v13 + 1;
        v17 = *v15;
        v18 = v15 + 1;
        if (v17)
          *v16 = v17;
        v19 = v16 + 1;
        v20 = *v18;
        v21 = v18 + 1;
        if (v20)
          *v19 = v20;
        v22 = v19 + 1;
        v23 = *v21;
        v24 = v21 + 1;
        if (v23)
          *v22 = v23;
        v25 = v22 + 1;
        v26 = *v24;
        v27 = v24 + 1;
        if (v26)
          *v25 = v26;
        v28 = v25 + 1;
        v29 = *v27;
        v30 = v27 + 1;
        if (v29)
          *v28 = v29;
        v31 = v28 + 1;
        v32 = *v30;
        n = v30 + 1;
        if (v32)
          *v31 = v32;
        ++j;
      }
      for (k = 0; k < v9; ++a1) {
        v34 = *n++;
        if (v34)
          *a1 = v34;
        ++k;
      }
      a1 += winw - v37;
      result = i + 1;
    }
  } else {
    for (m = 0; v40 > m; a1 = &v39[winw]) {
      v35 = v3;
      v39 = a1;
      v38 = n;
      v36 = 0;
      while (v36 < v37) {
        if (*n)
          *a1 = *n;
        v35 -= 64;
        ++a1;
        for (; v35 <= 0; ++v36) {
          ++n;
          v35 += v3;
        }
      }
      v6 -= 64;
      for (n = v38; v6 <= 0; ++m) {
        n += v37;
        v6 += v3;
      }
      result = winw;
    }
  }
  scr_size = v3;
  return result;
}

//-------------------------------------------------------------------------------------------------

int __fastcall print_damage(unsigned __int8 *a1, int *a2, int a3)
{
  int v3; // esi
  unsigned __int8 *v4; // edi
  int v5; // ecx
  double v6; // st7
  __int16 v7; // fps
  unsigned __int8 *v8; // edx
  _BOOL1 v9; // c0
  char v10; // c2
  _BOOL1 v11; // c3
  int v12; // eax
  double v13; // st7
  int result; // eax
  int v15; // esi
  int j; // eax
  unsigned __int8 v17; // cl
  int v18; // eax
  int v19; // ebx
  unsigned __int8 *v20; // [esp+0h] [ebp-38h]
  int k; // [esp+4h] [ebp-34h]
  int v22; // [esp+8h] [ebp-30h]
  int v23; // [esp+Ch] [ebp-2Ch]
  int v24; // [esp+10h] [ebp-28h]
  int i; // [esp+14h] [ebp-24h]
  int v26; // [esp+18h] [ebp-20h]
  int v27; // [esp+1Ch] [ebp-1Ch]
  unsigned __int8 *v28; // [esp+20h] [ebp-18h]
  unsigned __int8 v29; // [esp+24h] [ebp-14h]

  v3 = scr_size;
  v4 = a1;
  v5 = 77 * ViewType[a3];
  v6 = Car_variable_28[v5] * func2_c_variable_31;
  _CHP(a1, a2);
  v26 = (int)v6;
  v22 = *a2;
  v24 = a2[1];
  v12 = a2[2];
  v23 = v3;
  v8 = (unsigned __int8 *)a2 + v12;
  v9 = Car_variable_9[v5] > 0.0;
  v10 = 0;
  v11 = 0.0 == Car_variable_9[v5];
  LOWORD(v12) = v7;
  if (Car_variable_9[v5] <= 0.0) {
    v27 = 13;
  } else {
    v13 = (func2_c_variable_32 - Car_variable_9[v5]) * func2_c_variable_33 * func2_c_variable_34;
    _CHP(v12, v8);
    v27 = (int)v13;
  }
  result = do_blip(a3, v8);
  if (v3 == 64) {
    v15 = scr_size;
    for (i = 0; i < v24; v4 += winw - v22) {
      for (j = 0; j < v22; ++v4) {
        v17 = *v8++;
        if (v17) {
          if (v17 >= 0x31u) {
            if (v27 >= dam_remap[v17])
              *v4 = v17;
            else
              *v4 = 123;
          } else if (v17 > v26) {
            *v4 = -19;
          } else {
            *v4 = -13;
          }
        }
        ++j;
      }
      result = winw - v22;
      ++i;
    }
  } else {
    result = 0;
    v15 = scr_size;
    for (k = 0; k < v24; v4 = &v28[winw]) {
      v18 = v15;
      v28 = v4;
      v20 = v8;
      v19 = 0;
      while (v19 < v22) {
        v29 = *v8;
        if (*v8) {
          if (*v8 >= 0x31u) {
            if (v27 >= dam_remap[v29])
              *v4 = v29;
            else
              *v4 = 123;
          } else if (v29 > v26) {
            *v4 = -19;
          } else {
            *v4 = -13;
          }
        }
        v18 -= 64;
        ++v4;
        for (; v18 <= 0; ++v19) {
          ++v8;
          v18 += v15;
        }
      }
      v8 = v20;
      for (v23 -= 64; v23 <= 0; ++k) {
        v8 += v22;
        v23 += v15;
      }
      result = k;
    }
  }
  scr_size = v15;
  return result;
}

int __fastcall print_pos(int result, int a2, int a3)
{
  int v3; // ebp

  v3 = result;
  if (a3 >= 0 && a3 < racers) {
    mini_prt_string(rev_vga, (char *)&language_buffer + 64 * a3 + 384, result, a2);
    return mini_prt_right(rev_vga, &driver_names[9 * carorder[a3]], v3 + 70, a2);
  }
  return result;
}

//-------------------------------------------------------------------------------------------------

_DWORD *free_game_memory()
{
  char *v0; // edx
  _DWORD *v1; // eax
  _DWORD *v2; // eax
  int *v3; // edx
  int *v4; // eax

  fre(&building_vga);
  v0 = (char *)&cartex_vga;
  fre(&horizon_vga);
  do {
    v1 = v0;
    v0 += 4;
    fre(v1);
  } while (v0 != (char *)&cartex_vga + 64);
  v2 = fre(&cargen_vga);
  remove_mapsels(v2);
  v3 = &rev_vga;
  fre(&texture_vga);
  do {
    v4 = v3++;
    fre(v4);
  } while (v3 != &rev_vga + 16);
  return fre(&mirbuf);
}

//-------------------------------------------------------------------------------------------------

int readmode()
{
  _BYTE v1[36]; // [esp+0h] [ebp-24h] BYREF

  v1[1] = 15;
  int386(16, (int)v1, (int)v1);
  return v1[0];
}

//-------------------------------------------------------------------------------------------------

void __usercall key_handler(
        int a1@<eax>,
        int a2@<edx>,
        int a3@<ecx>,
        int a4@<ebx>,
        int a5@<ebp>,
        int a6@<edi>,
        int a7@<esi>)
{
  int v7; // eax
  int v8; // ebx
  int v9; // esi
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  ((void(__fastcall *)(int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, int, int, int, _UNKNOWN **, int, int, int))loc_7A9C0)(
    a1,
    a2,
    a4,
    a3,
    (unsigned __int16)__GS__,
    (unsigned __int16)__FS__,
    (unsigned __int16)__ES__,
    (unsigned __int16)__DS__,
    a1,
    a2,
    a3,
    a4,
    &retaddr,
    a5,
    a6,
    a7);
  v7 = 0;
  LOBYTE(v7) = __inbyte(0x60u);
  if (!frontend_on && !intro) {
    zoom_ascii_variable_1 = zoom_ascii_variable_2;
    v8 = zoom_ascii_variable_3;
    v9 = zoom_ascii_variable_2;
    zoom_ascii_variable_2 = zoom_ascii_variable_3;
    zoom_ascii_variable_3 = v7;
    if (v9 == 225 && v8 == 29 && v7 == 69)
      pause_request = -1;
  }
  if ((v7 & 0x80u) == 0) {
    keys[v7] = 1;
    switch (v7) {
      case 'H':
      case 'K':
      case 'M':
      case 'P':
        key_buffer[write_key++] = 0;
        write_key &= 0x3Fu;
        key_buffer[write_key++] = v7;
        goto LABEL_13;
      default:
        key_buffer[write_key++] = v7;
        write_key &= 0x3Fu;
        if (read_key != write_key)
          break;
        --write_key;
      LABEL_13:
        write_key &= 0x3Fu;
        break;
    }
  } else {
    keys[v7 & 0x7F] = 0;
  }
  __outbyte(0x20u, 0x20u);
  __asm { iret }
}

//-------------------------------------------------------------------------------------------------

int __fastcall claim_key_int(int a1, int a2)
{
  prev_int_9 = dos_getvect(9, a2, key_handler);
  prev_int_9_variable_1 = a2;
  return dos_setvect(9);
}

//-------------------------------------------------------------------------------------------------

int fatkbhit()
{
  if (write_key == read_key && !twoparter)
    return read_key ^ write_key;
  else
    return -1;
}

//-------------------------------------------------------------------------------------------------

int fatgetch()
{
  int v0; // edx
  int result; // eax

  v0 = twoparter;
  if (twoparter) {
    result = twoparter;
    v0 = 0;
  } else {
    while (write_key == read_key)
      ;
    result = mapping[(unsigned __int8)key_buffer[read_key++]];
    read_key &= 0x3Fu;
    if (result < 0) {
      v0 = -result;
      result = 0;
    }
  }
  twoparter = v0;
  return result;
}

//-------------------------------------------------------------------------------------------------

int release_key_int()
{
  return dos_setvect(9);
}

//-------------------------------------------------------------------------------------------------

int __fastcall clear_border(int a1, int a2, int a3, int a4)
{
  int v4; // edi
  int v5; // ebp
  int v6; // esi
  int v7; // ebx
  int result; // eax
  int v9; // [esp+0h] [ebp-10h]

  v4 = winx;
  v5 = winy;
  v9 = winw;
  winx = a1;
  winy = a2;
  winw = a3;
  v6 = winh;
  v7 = 0;
  for (winh = 1; v7 < a4; ++winy) {
    copypic(blank_line, (int)screen);
    ++v7;
  }
  result = v9;
  winh = v6;
  winx = v4;
  winy = v5;
  winw = v9;
  return result;
}

//-------------------------------------------------------------------------------------------------

int DisplayFree()
{
  int result; // eax
  int v1; // [esp+0h] [ebp-88h] BYREF
  int v2; // [esp+1Ch] [ebp-6Ch]
  _DWORD v3[7]; // [esp+50h] [ebp-38h] BYREF
  _WORD v4[14]; // [esp+6Ch] [ebp-1Ch] BYREF

  memset(v4, 0, 12);
  v3[0] = 1280;
  v4[0] = __DS__;
  v3[5] = &v1;
  int386x(49, (int)v3, (int)v3, (int)v4);
  printf(aLargestBlockD);
  printf(aTotalFreeD);
  no_mem = 0;
  lots_of_mem = 0;
  if (v2 << 12 >= 4500000) {
    result = printf(aRunning8MegVer);
    gfx_size = 0;
    lots_of_mem = -1;
  } else {
    printf(aRunning4MegVer);
    gfx_size = 1;
    result = v2 << 12;
    if (v2 << 12 < 2000000)
      no_mem = -1;
  }
  return result;
}

//-------------------------------------------------------------------------------------------------

int __fastcall setdirectory(char *a1)
{
  _BYTE *v1; // edi
  char v3; // al
  char v4; // al
  _BYTE *v5; // eax
  _BYTE v7[272]; // [esp+0h] [ebp-110h] BYREF

  v1 = v7;
  do {
    v3 = *a1;
    *v1 = *a1;
    if (!v3)
      break;
    v4 = a1[1];
    a1 += 2;
    v1[1] = v4;
    v1 += 2;
  } while (v4);
  dos_setdrive((v7[0] & 0xDF) - 64, 0);
  v5 = (_BYTE *)strrchr(v7, 92);
  if (*(v5 - 1) == 58)
    ++v5;
  *v5 = 0;
  chdir(v7);
  return chdir(aFatdata);
}

//-------------------------------------------------------------------------------------------------

int FindShades()
{
  int v0; // ecx
  int v1; // edi
  int v2; // esi
  int v3; // ebp
  int v4; // esi
  int v5; // edx
  int v6; // edi
  int v7; // ebx
  int v8; // ecx
  int v9; // eax
  int result; // eax
  int v11; // [esp+0h] [ebp-34h]
  int v12; // [esp+4h] [ebp-30h]
  int v13; // [esp+8h] [ebp-2Ch]
  int v14; // [esp+Ch] [ebp-28h]
  int v15; // [esp+10h] [ebp-24h]
  int v16; // [esp+18h] [ebp-1Ch]

  v12 = 1;
  v11 = 1025;
  v13 = 3;
  do {
    v0 = (unsigned __int8)palette[v13];
    v1 = (unsigned __int8)palette_variable_1[v13];
    v2 = (unsigned __int8)palette_variable_2[v13];
    v16 = v0 / 5;
    v14 = v1 / 5;
    v15 = v2 / 5;
    v3 = v12;
    do {
      v0 -= v16;
      if (v0 < 0)
        v0 = 0;
      v1 -= v14;
      if (v1 < 0)
        v1 = 0;
      v2 -= v15;
      if (v2 < 0)
        v2 = 0;
      v3 += 256;
      TrackScreenXYZ_variable_12[v3] = nearest_colour(v0, v1, v2);
    } while (v3 != v11);
    v4 = (unsigned __int8)palette[v13];
    v5 = (unsigned __int8)palette_variable_1[v13];
    v6 = (unsigned __int8)palette_variable_3 - v4;
    v7 = (unsigned __int8)palette_variable_2[v13];
    if (v6 < -15)
      v6 = -15;
    if (v6 > 15)
      v6 = 15;
    v8 = (unsigned __int8)palette_variable_4 - v5;
    if (v8 < -15)
      v8 = -15;
    if (v8 > 15)
      v8 = 15;
    v9 = (unsigned __int8)palette_variable_5 - v7;
    if (v9 < -15)
      v9 = -15;
    if (v9 > 15)
      v9 = 15;
    result = nearest_colour(v6 + v4, v8 + v5, v9 + v7);
    shade_palette_variable_1[v12++] = result;
    v13 += 3;
    ++v11;
  } while (v12 < 256);
  return result;
}

//-------------------------------------------------------------------------------------------------

int __fastcall nearest_colour(int a1, int a2, int a3)
{
  int v3; // edi
  int v4; // ecx
  int v5; // ebx
  __int64 v6; // rax
  int v7; // esi
  __int64 v8; // rax
  int v9; // eax
  int v14; // [esp+10h] [ebp-14h]

  v3 = 1024;
  v4 = 1;
  v5 = 3;
  v14 = 0;
  do {
    v6 = (unsigned __int8)palette[v5] - a1;
    v7 = abs32((unsigned __int8)palette_variable_1[v5] - a2) + (HIDWORD(v6) ^ v6) - HIDWORD(v6);
    v8 = (unsigned __int8)palette_variable_2[v5] - a3;
    v9 = v7 + (HIDWORD(v8) ^ v8) - HIDWORD(v8);
    if (v9 < v3) {
      v14 = v4;
      v3 = v9;
    }
    ++v4;
    v5 += 3;
  } while (v4 < 256);
  return v14;
}

//-------------------------------------------------------------------------------------------------

int __fastcall select_view(int a1)
{
  int v1; // ebx
  int result; // eax
  int v3; // edx
  int v4; // ebx

  v1 = SelectedView[a1];
  if (v1 == 2 || v1 == 7) {
    if (SVGA_ON)
      scr_size = 128;
    else
      scr_size = 64;
  }
  result = a1;
  v3 = SelectedView[result];
  v4 = Selected_Drives[v3];
  LOBYTE(v3) = Selected_Play[4 * v3];
  DriveView[result] = v4;
  Play_View = v3;
  if (v4 == 5) {
    chaseview[result] = 1;
    DriveView[result] = 2;
  } else if (v4 == 2) {
    chaseview[result] = 0;
  }
  if ((cheat_mode & 0x40) != 0)
    clear_borders = -1;
  return result * 4;
}

//-------------------------------------------------------------------------------------------------

int __fastcall mini_prt_string(int a1, _BYTE *a2)
{
  int v3; // ebp
  int result; // eax

  v3 = 0;
  do {
    if (*a2) {
      if (*a2 != 10)
        result = prt_letter(-1);
    } else {
      v3 = -1;
    }
    ++a2;
  } while (!v3);
  return result;
}

//-------------------------------------------------------------------------------------------------

int __fastcall mini_prt_string_rev(int a1, _BYTE *a2)
{
  int v3; // ebp
  int result; // eax

  v3 = 0;
  do {
    if (*a2) {
      if (*a2 != 10)
        result = prt_letter_rev(-1);
    } else {
      v3 = -1;
    }
    ++a2;
  } while (!v3);
  return result;
}

//-------------------------------------------------------------------------------------------------

char __fastcall mini_prt_right(int a1, _BYTE *a2, int a3, int a4)
{
  _BYTE *i; // esi
  int v6; // eax
  char *v7; // esi
  int v8; // ebp
  char result; // al
  int v10; // [esp+4h] [ebp-14h]

  for (i = a2; *i; ++i) {
    v6 = (unsigned __int8)ascii_conv3[(unsigned __int8)*i];
    if (v6 == 255)
      a3 -= 4;
    else
      a3 -= *(_DWORD *)(a1 + 12 * v6);
  }
  v7 = a2;
  v8 = 0;
  v10 = (scr_size * a4) >> 6;
  do {
    result = *v7;
    if (*v7) {
      if (result != 10) {
        prt_letter(-1);
        result = v10;
      }
    } else {
      v8 = -1;
    }
    ++v7;
  } while (!v8);
  return result;
}

//-------------------------------------------------------------------------------------------------

char __fastcall mini_prt_centre(int a1, _BYTE *a2, int a3, int a4)
{
  _BYTE *i; // esi
  int v6; // eax
  char *v7; // esi
  int v8; // ebp
  char result; // al
  int v10; // [esp+4h] [ebp-14h]

  for (i = a2; *i; ++i) {
    v6 = (unsigned __int8)ascii_conv3[(unsigned __int8)*i];
    if (v6 == 255)
      a3 -= 4;
    else
      a3 -= *(_DWORD *)(a1 + 12 * v6) / 2;
  }
  v7 = a2;
  v8 = 0;
  v10 = (scr_size * a4) >> 6;
  do {
    result = *v7;
    if (*v7) {
      if (result != 10) {
        prt_letter(-1);
        result = v10;
      }
    } else {
      v8 = -1;
    }
    ++v7;
  } while (!v8);
  return result;
}

//-------------------------------------------------------------------------------------------------

char __fastcall prt_right(int a1, char *a2, int a3)
{
  char *v4; // esi
  int v5; // eax
  int v6; // ebp
  char result; // al

  v4 = a2;
  while (*a2) {
    v5 = (unsigned __int8)font6_ascii[(unsigned __int8)*a2++];
    if (v5 == 255)
      a3 -= 4;
    else
      a3 -= *(_DWORD *)(a1 + 12 * v5);
  }
  v6 = 0;
  do {
    result = *v4;
    if (*v4) {
      if (result != 10)
        result = prt_letter(0);
    } else {
      v6 = -1;
    }
    ++v4;
  } while (!v6);
  return result;
}

//-------------------------------------------------------------------------------------------------

int __fastcall prt_string(int a1, _BYTE *a2)
{
  int v3; // ebp
  int result; // eax

  v3 = 0;
  do {
    if (*a2) {
      if (*a2 != 10)
        result = prt_letter(0);
    } else {
      v3 = -1;
    }
    ++a2;
  } while (!v3);
  return result;
}

//-------------------------------------------------------------------------------------------------

int __fastcall prt_letter(int a1, unsigned __int8 a2, _DWORD *a3, _DWORD *a4, int a5)
{
  int v5; // esi
  int v7; // edi
  int v8; // edx
  int *v9; // eax
  int result; // eax
  int v11; // edi
  char *v12; // ebx
  _BYTE *v13; // eax
  int k; // ebp
  int m; // edx
  char v16; // cl
  _BYTE *j; // edx
  int v18; // edi
  _BYTE *v19; // ebp
  int v20; // eax
  int v21; // ebx
  int v22; // [esp+0h] [ebp-28h]
  int v24; // [esp+8h] [ebp-20h]
  int v25; // [esp+Ch] [ebp-1Ch]
  _BYTE *v26; // [esp+10h] [ebp-18h]
  int i; // [esp+14h] [ebp-14h]
  int v28; // [esp+18h] [ebp-10h]

  v5 = scr_size;
  if (a5) {
    v7 = (unsigned __int8)ascii_conv3[a2];
    v8 = 0;
  } else {
    v7 = (unsigned __int8)font6_ascii[a2];
    v8 = font6_offsets[v7];
  }
  v9 = (int *)(a1 + 12 * v7);
  if (scr_size != 64) {
    if (v7 == 255) {
      result = (4 * scr_size) >> 6;
      *a3 += result;
      scr_size = v5;
      return result;
    }
    v28 = *v9;
    v25 = v9[1];
    j = (_BYTE *)(a1 + v9[2]);
    v18 = scr_size;
    v22 = winw * *a4 + *a3 + screen_pointer;
    for (i = 0; i < v25; v22 += winw) {
      v19 = (_BYTE *)v22;
      v26 = j;
      v20 = v5;
      v21 = 0;
      while (v21 < v28) {
        if (*j)
          *v19 = *j;
        v20 -= 64;
        ++v19;
        for (; v20 <= 0; ++v21) {
          ++j;
          v20 += v5;
        }
      }
      v18 -= 64;
      for (j = v26; v18 <= 0; ++i) {
        j += v28;
        v18 += v5;
      }
    }
    result = (v5 * v28) >> 6;
    *a3 += result;
    goto LABEL_27;
  }
  if (v7 == 255) {
    result = (int)a3;
    *a3 += 4;
  LABEL_27:
    scr_size = v5;
    return result;
  }
  v24 = v9[1];
  v11 = *v9;
  v12 = (char *)(a1 + v9[2]);
  v13 = (_BYTE *)(winw * (*a4 + v8) + *a3 + screen_pointer);
  for (k = 0; k < v24; v13 += winw - v11) {
    for (m = 0; m < v11; ++v13) {
      v16 = *v12++;
      if (v16)
        *v13 = v16;
      ++m;
    }
    ++k;
  }
  result = (int)a3;
  *a3 += v11;
  scr_size = 64;
  return result;
}

//-------------------------------------------------------------------------------------------------

int __fastcall prt_letter_rev(int a1, unsigned __int8 a2, _DWORD *a3, _DWORD *a4, int a5)
{
  int v5; // esi
  int v7; // edi
  int v8; // edx
  int *v9; // eax
  int result; // eax
  int v11; // edi
  char *v12; // ebx
  _BYTE *v13; // eax
  int k; // ebp
  int m; // edx
  char v16; // cl
  _BYTE *j; // edx
  int v18; // edi
  _BYTE *v19; // ebp
  int v20; // eax
  int v21; // ebx
  int v22; // [esp+0h] [ebp-28h]
  int v24; // [esp+8h] [ebp-20h]
  int v25; // [esp+Ch] [ebp-1Ch]
  _BYTE *v26; // [esp+10h] [ebp-18h]
  int i; // [esp+14h] [ebp-14h]
  int v28; // [esp+18h] [ebp-10h]

  v5 = scr_size;
  if (a5) {
    v7 = (unsigned __int8)ascii_conv3[a2];
    v8 = 0;
  } else {
    v7 = (unsigned __int8)font6_ascii[a2];
    v8 = font6_offsets[v7];
  }
  v9 = (int *)(a1 + 12 * v7);
  if (scr_size != 64) {
    if (v7 == 255) {
      result = (4 * scr_size) >> 6;
      *a3 -= result;
      scr_size = v5;
      return result;
    }
    v28 = *v9;
    v25 = v9[1];
    j = (_BYTE *)(a1 + v9[2]);
    v18 = scr_size;
    v22 = winw * *a4 + *a3 + screen_pointer;
    for (i = 0; i < v25; v22 += winw) {
      v19 = (_BYTE *)v22;
      v26 = j;
      v20 = v5;
      v21 = 0;
      while (v21 < v28) {
        if (*j)
          *v19 = *j;
        v20 -= 64;
        --v19;
        for (; v20 <= 0; ++v21) {
          ++j;
          v20 += v5;
        }
      }
      v18 -= 64;
      for (j = v26; v18 <= 0; ++i) {
        j += v28;
        v18 += v5;
      }
    }
    result = (v5 * v28) >> 6;
    *a3 -= result;
    goto LABEL_27;
  }
  if (v7 == 255) {
    result = (int)a3;
    *a3 -= 4;
  LABEL_27:
    scr_size = v5;
    return result;
  }
  v24 = v9[1];
  v11 = *v9;
  v12 = (char *)(a1 + v9[2]);
  v13 = (_BYTE *)(winw * (*a4 + v8) + *a3 + screen_pointer);
  for (k = 0; k < v24; v13 += v11 + winw) {
    for (m = 0; m < v11; --v13) {
      v16 = *v12++;
      if (v16)
        *v13 = v16;
      ++m;
    }
    ++k;
  }
  result = (int)a3;
  *a3 -= v11;
  scr_size = 64;
  return result;
}

//-------------------------------------------------------------------------------------------------

int __fastcall prt_stringcol(int a1, _BYTE *a2, int a3, int a4, char a5)
{
  int v6; // ebp
  int result; // eax

  v6 = 0;
  do {
    if (*a2) {
      if (*a2 != 10)
        result = prt_lettercol(a5);
    } else {
      v6 = -1;
    }
    ++a2;
  } while (!v6);
  return result;
}

//-------------------------------------------------------------------------------------------------

char __fastcall prt_rightcol(int a1, _BYTE *a2, int a3, int a4, char a5)
{
  _BYTE *i; // esi
  int v7; // eax
  char *v8; // esi
  int v9; // ebp
  char result; // al

  for (i = a2; *i; ++i) {
    v7 = (unsigned __int8)font6_ascii[(unsigned __int8)*i];
    if (v7 == 255)
      a3 -= 4;
    else
      a3 -= *(_DWORD *)(a1 + 12 * v7);
  }
  v8 = a2;
  v9 = 0;
  do {
    result = *v8;
    if (*v8) {
      if (result != 10)
        result = prt_lettercol(a5);
    } else {
      v9 = -1;
    }
    ++v8;
  } while (!v9);
  return result;
}

//-------------------------------------------------------------------------------------------------

char __fastcall prt_centrecol(int a1, char *a2, int a3, int a4, char a5)
{
  char *v6; // esi
  char *v7; // eax
  char v8; // bl
  int v9; // edx
  int v10; // ebx
  int v11; // ebp
  char result; // al

  v6 = a2;
  v7 = a2;
  v8 = *a2;
  v9 = 0;
  if (v8) {
    do {
      v10 = (unsigned __int8)font6_ascii[(unsigned __int8)*v7++];
      if (v10 == 255)
        v9 += 4;
      else
        v9 += *(_DWORD *)(a1 + 12 * v10);
    } while (*v7);
  }
  v11 = 0;
  do {
    result = *v6;
    if (*v6) {
      if (result != 10)
        result = prt_lettercol(a5);
    } else {
      v11 = -1;
    }
    ++v6;
  } while (!v11);
  return result;
}

//-------------------------------------------------------------------------------------------------

int __fastcall prt_lettercol(int a1, unsigned __int8 a2, _DWORD *a3, _DWORD *a4, char a5)
{
  int v5; // esi
  int v6; // ebx
  int result; // eax
  char *j; // edx
  int v9; // ebp
  char *v10; // edi
  int v11; // eax
  int v12; // ebx
  char v13; // cl
  int v14; // [esp+0h] [ebp-24h]
  int i; // [esp+4h] [ebp-20h]
  char *v17; // [esp+Ch] [ebp-18h]
  int v18; // [esp+10h] [ebp-14h]
  int v19; // [esp+14h] [ebp-10h]

  v5 = scr_size;
  v6 = (unsigned __int8)font6_ascii[a2];
  if (v6 == 255) {
    result = (4 * scr_size) >> 6;
    *a3 += result;
  } else {
    v19 = *(_DWORD *)(a1 + 12 * v6);
    v14 = *(_DWORD *)(a1 + 12 * v6 + 4);
    j = (char *)(a1 + *(_DWORD *)(a1 + 12 * v6 + 8));
    v9 = scr_size;
    v18 = winw * (font6_offsets[v6] + *a4) + *a3 + screen_pointer;
    for (i = 0; i < v14; v18 += winw) {
      v10 = (char *)v18;
      v17 = j;
      v11 = v5;
      v12 = 0;
      while (v12 < v19) {
        v13 = *j;
        if (*j) {
          if (v13 == -113)
            v13 = a5;
          *v10 = v13;
        }
        v11 -= 64;
        ++v10;
        for (; v11 <= 0; ++v12) {
          ++j;
          v11 += v5;
        }
      }
      v9 -= 64;
      for (j = v17; v9 <= 0; ++i) {
        j += v19;
        v9 += v5;
      }
    }
    result = (v5 * v19) >> 6;
    *a3 += result;
  }
  scr_size = v5;
  return result;
}

//-------------------------------------------------------------------------------------------------

char display_paused()
{
  int i; // eax
  char v1; // al
  char v2; // al
  char *v3; // edx
  char v4; // al
  char v5; // al
  char v6; // al
  char v7; // al
  char v8; // al
  int v9; // ebx
  int v10; // eax
  int v11; // edx
  char v12; // al
  char v13; // al
  char v14; // al
  int v15; // edi
  int v16; // esi
  char v17; // al
  char v18; // al
  int v19; // edx
  int v20; // esi
  int v21; // edi
  char v22; // al
  char v23; // al
  int v24; // ebx
  int v25; // esi
  int v26; // edi
  char v27; // al
  char v28; // al
  char v29; // al
  int v30; // ebx
  _BYTE *v31; // edx
  char v32; // al
  int v33; // ebx
  _BYTE *v34; // edx
  char v35; // al
  int v36; // ebx
  _BYTE *v37; // edx
  char v38; // al
  int v39; // ebx
  _BYTE *v40; // edx
  char v41; // al
  char v42; // al
  char v43; // al
  char v44; // al
  char v45; // al
  char v46; // al
  _BYTE *v47; // edx
  char v48; // al
  char v49; // al
  _BYTE *v50; // edx
  char v51; // al
  char v52; // al
  _BYTE *v53; // edx
  char v54; // al
  char v55; // al
  char v56; // al
  _BYTE *v57; // edx
  char v58; // al
  char v59; // al
  _BYTE *v60; // edx
  char v61; // al
  char v62; // al
  _BYTE *v63; // edx
  char v64; // al
  char v65; // al
  _BYTE *v66; // edx
  char v67; // al
  char v68; // al
  _BYTE *v69; // edx
  char v70; // al
  char v71; // al
  _BYTE *v72; // edx
  char v73; // al
  char v74; // al
  _BYTE *v75; // edx
  char v76; // al
  char v77; // al
  _BYTE *v78; // edx
  char v79; // al
  char v80; // al
  _BYTE *v81; // edx
  char v82; // al
  char v83; // al
  _BYTE *v84; // edx
  char v85; // al
  char v86; // al
  _BYTE *v87; // edx
  char v88; // al
  char v89; // al
  _BYTE *v90; // edx
  char v91; // al
  char v92; // al
  _BYTE *v93; // edx
  char v94; // al
  char v95; // al
  _BYTE *v96; // edx
  char v97; // al
  int v98; // eax
  char v99; // al
  char v100; // al
  char *v101; // edx
  char v102; // al
  _DWORD v104[2]; // [esp+0h] [ebp-28h] BYREF
  int v105; // [esp+8h] [ebp-20h]
  int v106; // [esp+Ch] [ebp-1Ch]
  int v107; // [esp+10h] [ebp-18h]
  int v108; // [esp+14h] [ebp-14h]
  int v109; // [esp+18h] [ebp-10h]
  int v110; // [esp+1Ch] [ebp-Ch]
  char *v111; // [esp+20h] [ebp-8h]
  char *v112; // [esp+24h] [ebp-4h]

  LOBYTE(i) = pausewindow;
  switch (pausewindow) {
    case 0:
      blankwindow(0, 0, 320, 200);
      prt_centrecol(rev_vga_variable_1, config_buffer, 160, 16, 171);
      if (req_edit)
        v1 = -125;
      else
        v1 = -113;
      prt_centrecol(rev_vga_variable_1, config_buffer_variable_1, 160, 36, v1);
      if (replaytype == 2) {
        if (req_edit == 1)
          v2 = -113;
        else
          v2 = -125;
        v3 = (char *)&config_buffer_variable_3;
      } else {
        if (req_edit == 1)
          v2 = -113;
        else
          v2 = -125;
        v3 = (char *)&config_buffer_variable_2;
      }
      prt_centrecol(rev_vga_variable_1, v3, 160, 48, v2);
      if (req_edit == 2)
        v4 = -113;
      else
        v4 = -125;
      prt_centrecol(rev_vga_variable_1, config_buffer_variable_4, 160, 60, v4);
      if (req_edit == 3)
        v5 = -113;
      else
        v5 = -125;
      prt_centrecol(rev_vga_variable_1, config_buffer_variable_5, 160, 72, v5);
      if (req_edit == 4)
        v6 = -113;
      else
        v6 = -125;
      prt_centrecol(rev_vga_variable_1, config_buffer_variable_6, 160, 84, v6);
      if (req_edit == 5)
        v7 = -113;
      else
        v7 = -125;
      prt_centrecol(rev_vga_variable_1, config_buffer_variable_9, 160, 96, v7);
      if (req_edit == 6)
        v8 = -113;
      else
        v8 = -125;
      LOBYTE(i) = prt_centrecol(rev_vga_variable_1, config_buffer_variable_10, 160, 108, v8);
      break;
    case 1:
      blankwindow(0, 0, 320, 200);
      if (calibrate_mode) {
        ReadJoys(v104);
        _disable();
        if (v105 < JAXmin)
          JAXmin = v105;
        if (v105 > JAXmax)
          JAXmax = v105;
        if (v106 < JAYmin)
          JAYmin = v106;
        if (v106 > JAYmax)
          JAYmax = v106;
        if (v109 < JBXmin)
          JBXmin = v109;
        if (v109 > JBXmax)
          JBXmax = v109;
        if (v110 < JBYmin)
          JBYmin = v110;
        if (v110 > JBYmax)
          JBYmax = v110;
        if (JAXmin == JAXmax)
          JAXmax = JAXmin + 1;
        if (JAYmin == JAYmax)
          JAYmax = JAYmin + 1;
        if (JBXmin == JBXmax)
          JBXmax = JBXmin + 1;
        if (JBYmin == JBYmax)
          JBYmax = JBYmin + 1;
        _enable();
      }
      prt_centrecol(rev_vga_variable_1, config_buffer_variable_5, 160, 16, 171);
      if (calibrate_select != 1 || calibrate_mode)
        v27 = -125;
      else
        v27 = -113;
      prt_centrecol(rev_vga_variable_1, config_buffer_variable_14, 160, 36, v27);
      if (calibrate_select || calibrate_mode)
        v28 = -125;
      else
        v28 = -113;
      prt_centrecol(rev_vga_variable_1, config_buffer_variable_13, 160, 48, v28);
      if (calibrate_mode)
        v29 = -113;
      else
        v29 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_15, 176, 68, v29);
      if (calibrate_mode) {
        if (x1ok && JAXmax - JAXmin >= 100)
          v30 = 140 * (2 * v105 - JAXmax - JAXmin) / (JAXmax - JAXmin);
        else
          v30 = 0;
        displaycalibrationbar(180, 68, v30);
      } else {
        if (x1ok)
          v31 = &config_buffer_variable_20;
        else
          v31 = &config_buffer_variable_19;
        prt_stringcol(rev_vga_variable_1, v31, 180, 68, 131);
      }
      if (calibrate_mode)
        v32 = -113;
      else
        v32 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_16, 176, 80, v32);
      if (calibrate_mode) {
        if (y1ok && JAYmax - JAYmin >= 100)
          v33 = 140 * (2 * v106 - JAYmax - JAYmin) / (JAYmax - JAYmin);
        else
          v33 = 0;
        displaycalibrationbar(180, 80, v33);
      } else {
        if (y1ok)
          v34 = &config_buffer_variable_20;
        else
          v34 = &config_buffer_variable_19;
        prt_stringcol(rev_vga_variable_1, v34, 180, 80, 131);
      }
      if (calibrate_mode)
        v35 = -113;
      else
        v35 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_17, 176, 92, v35);
      if (calibrate_mode) {
        if (x2ok && JBXmax - JBXmin >= 100)
          v36 = 140 * (2 * v109 - JBXmax - JBXmin) / (JBXmax - JBXmin);
        else
          v36 = 0;
        displaycalibrationbar(180, 92, v36);
      } else {
        if (x2ok)
          v37 = &config_buffer_variable_20;
        else
          v37 = &config_buffer_variable_19;
        prt_stringcol(rev_vga_variable_1, v37, 180, 92, 131);
      }
      if (calibrate_mode)
        v38 = -113;
      else
        v38 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_18, 176, 104, v38);
      if (calibrate_mode) {
        if (y2ok && JBYmax - JBYmin >= 100)
          v39 = 140 * (2 * v110 - JBYmax - JBYmin) / (JBYmax - JBYmin);
        else
          v39 = 0;
        LOBYTE(i) = displaycalibrationbar(180, 104, v39);
      } else {
        if (y2ok)
          v40 = &config_buffer_variable_20;
        else
          v40 = &config_buffer_variable_19;
        LOBYTE(i) = prt_stringcol(rev_vga_variable_1, v40, 180, 104, 131);
      }
      if (calibrate_mode) {
        prt_centrecol(rev_vga_variable_1, config_buffer_variable_21, 160, 124, 143);
        LOBYTE(i) = prt_centrecol(rev_vga_variable_1, config_buffer_variable_22, 160, 136, 143);
      }
      break;
    case 2:
      if (controlrelease) {
        v9 = -1;
        v10 = 0;
        v11 = 0;
        do {
          if (keyname[v11] && keys[v10])
            v9 = 0;
          ++v10;
          ++v11;
        } while (v10 < 128);
        if (v9)
          controlrelease = 0;
      }
      blankwindow(0, 0, 320, 200);
      prt_centrecol(rev_vga_variable_1, config_buffer_variable_6, 160, 16, 171);
      if (control_select != 2 || define_mode)
        v12 = -125;
      else
        v12 = -113;
      prt_centrecol(rev_vga_variable_1, config_buffer_variable_11, 160, 36, v12);
      if (control_select != 1 || define_mode)
        v13 = -125;
      else
        v13 = -113;
      prt_centrecol(rev_vga_variable_1, config_buffer_variable_12, 160, 48, v13);
      if (control_select || define_mode)
        v14 = -125;
      else
        v14 = -113;
      prt_centrecol(rev_vga_variable_1, config_buffer_variable_13, 160, 60, v14);
      if (control_select > 1) {
        v20 = 6;
        v21 = 80;
        v111 = &config_buffer[1280];
        do {
          if (v20 == control_edit)
            v22 = -113;
          else
            v22 = 123;
          prt_rightcol(rev_vga_variable_1, v111, 198, v21, v22);
          if (v20 == control_edit)
            v23 = -113;
          else
            v23 = 123;
          v19 = keyname[(unsigned __int8)userkey[v20]];
          LOBYTE(i) = prt_stringcol(rev_vga_variable_1, (_BYTE *)v19, 200, v21, v23);
          ++v20;
          v21 += 12;
          v111 += 64;
        } while (v20 < 12);
      } else {
        v15 = 80;
        v16 = 0;
        v112 = &config_buffer[896];
        do {
          if (v16 == control_edit)
            v17 = -113;
          else
            v17 = 123;
          prt_rightcol(rev_vga_variable_1, v112, 198, v15, v17);
          if (v16 == control_edit)
            v18 = -113;
          else
            v18 = 123;
          LOBYTE(i) = prt_stringcol(
                        rev_vga_variable_1,
                        (_BYTE *)keyname[(unsigned __int8)userkey[v16++]],
                        200,
                        v15,
                        v18);
          v19 = (int)(v112 + 64);
          v15 += 12;
          v112 += 64;
        } while (v16 < 6);
      }
      if (define_mode) {
        if (!controlrelease) {
          v24 = -1;
          i = 0;
          v19 = 0;
          do {
            if (*(int *)((char *)keyname + v19) && keys[i])
              v24 = i;
            ++i;
            v19 += 4;
          } while (i < 128);
          if (v24 == -1) {
            LOBYTE(i) = ReadJoys(v104);
            if (v104[0])
              v24 = 128;
            if (v104[1])
              v24 = 129;
            if (v107)
              v24 = 130;
            if (v108)
              v24 = 131;
          }
          if (v24 == -1) {
            if (y2ok) {
              i = 100 * (2 * v110 - JBYmax - JBYmin) / (JBYmax - JBYmin);
              v19 = 100 * (2 * v110 - JBYmax - JBYmin) % (JBYmax - JBYmin);
              if (i < -50)
                v24 = 138;
              if (i > 50)
                v24 = 139;
            }
            if (x2ok) {
              i = 100 * (2 * v109 - JBXmax - JBXmin) / (JBXmax - JBXmin);
              v19 = 100 * (2 * v109 - JBXmax - JBXmin) % (JBXmax - JBXmin);
              if (i < -50)
                v24 = 136;
              if (i > 50)
                v24 = 137;
            }
            if (y1ok) {
              i = 100 * (2 * v106 - JAYmax - JAYmin) / (JAYmax - JAYmin);
              v19 = 100 * (2 * v106 - JAYmax - JAYmin) % (JAYmax - JAYmin);
              if (i < -50)
                v24 = 134;
              if (i > 50)
                v24 = 135;
            }
            if (x1ok) {
              i = 100 * (2 * v105 - JAXmax - JAXmin) / (JAXmax - JAXmin);
              v19 = 100 * (2 * v105 - JAXmax - JAXmin) % (JAXmax - JAXmin);
              if (i < -50)
                v24 = 132;
              if (i > 50)
                v24 = 133;
            }
          }
          if (v24 != -1 && (control_edit == 1 || control_edit == 7)) {
            if ((LOBYTE(i) = control_edit, *((_BYTE *)&off_A4108 + control_edit + 3) <= 0x83u) && v24 > 131
              || (LOBYTE(i) = control_edit, *((_BYTE *)&off_A4108 + control_edit + 3) > 0x83u) && v24 <= 131) {
              v24 = -1;
            }
          }
          if (v24 != -1) {
            v19 = control_edit;
            v25 = 0;
            for (i = 0; i < control_edit; ++i) {
              v19 = (unsigned __int8)userkey[i];
              if (v19 == v24)
                v25 = -1;
            }
            if (!v25) {
              i = control_edit + 1;
              v26 = control_select;
              controlrelease = -1;
              *((_BYTE *)&off_A4108 + i + 3) = v24;
              control_edit = i;
              if (v26 == 1) {
                if (i == 6) {
                  define_mode = 0;
                  control_edit = -1;
                  while (1) {
                    i = fatkbhit();
                    if (!i)
                      break;
                    fatgetch();
                  }
                }
              } else if (i == 12) {
                v19 = 0;
                control_edit = -1;
                define_mode = 0;
                while (1) {
                  i = fatkbhit();
                  if (!i)
                    break;
                  fatgetch();
                }
              }
            }
          }
        }
        if (keys_variable_1) {
          define_mode = 0;
          qmemcpy(userkey, &oldkeys, 0xCu);
          qmemcpy(&userkey[12], (char *)&oldkeys + 12, 2u);
          while (fatkbhit())
            fatgetch();
          pausewindow = 0;
          LOBYTE(i) = check_joystick_usage(0, v19);
        }
      }
      break;
    case 3:
      blankwindow(0, 0, 320, 200);
      prt_centrecol(rev_vga_variable_1, config_buffer_variable_9, 160, 12, 171);
      if (graphic_mode == 16)
        v55 = -113;
      else
        v55 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_87, 187, 26, v55);
      if ((((unsigned int)&loc_7FFFE + 2) & textures_off) != 0) {
        if (graphic_mode == 16)
          v56 = -113;
        else
          v56 = -125;
        v57 = &config_buffer_variable_30;
      } else {
        if (graphic_mode == 16)
          v56 = -113;
        else
          v56 = -125;
        v57 = &config_buffer_variable_29;
      }
      prt_stringcol(rev_vga_variable_1, v57, 190, 26, v56);
      sprintf(&buffer, "%s:", config_buffer_variable_50);
      if (graphic_mode == 15)
        v58 = -113;
      else
        v58 = -125;
      prt_rightcol(rev_vga_variable_1, &buffer, 187, 36, v58);
      if (names_on) {
        if (names_on == 2) {
          if (graphic_mode == 15)
            v59 = -113;
          else
            v59 = -125;
          v60 = &config_buffer_variable_32;
        } else {
          if (graphic_mode == 15)
            v59 = -113;
          else
            v59 = -125;
          v60 = &config_buffer_variable_29;
        }
      } else {
        if (graphic_mode == 15)
          v59 = -113;
        else
          v59 = -125;
        v60 = &config_buffer_variable_30;
      }
      prt_stringcol(rev_vga_variable_1, v60, 190, 36, v59);
      if (graphic_mode == 14)
        v61 = -113;
      else
        v61 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_35, 187, 46, v61);
      if ((textures_off & 0x200) != 0) {
        if (graphic_mode == 14)
          v62 = -113;
        else
          v62 = -125;
        v63 = &config_buffer_variable_30;
      } else {
        if (graphic_mode == 14)
          v62 = -113;
        else
          v62 = -125;
        v63 = &config_buffer_variable_29;
      }
      prt_stringcol(rev_vga_variable_1, v63, 190, 46, v62);
      if (graphic_mode == 13)
        v64 = -113;
      else
        v64 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_36, 187, 56, v64);
      if ((textures_off & 0x800) != 0) {
        if (graphic_mode == 13)
          v65 = -113;
        else
          v65 = -125;
        v66 = &config_buffer_variable_30;
      } else {
        if (graphic_mode == 13)
          v65 = -113;
        else
          v65 = -125;
        v66 = &config_buffer_variable_29;
      }
      prt_stringcol(rev_vga_variable_1, v66, 190, 56, v65);
      if (graphic_mode == 12)
        v67 = -113;
      else
        v67 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_38, 187, 66, v67);
      if ((textures_off & 0x10) != 0) {
        if (graphic_mode == 12)
          v68 = -113;
        else
          v68 = -125;
        v69 = &config_buffer_variable_30;
      } else {
        if (graphic_mode == 12)
          v68 = -113;
        else
          v68 = -125;
        v69 = &config_buffer_variable_29;
      }
      prt_stringcol(rev_vga_variable_1, v69, 190, 66, v68);
      if (graphic_mode == 11)
        v70 = -113;
      else
        v70 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_37, 187, 76, v70);
      if ((textures_off & 0x40) != 0) {
        if (graphic_mode == 11)
          v71 = -113;
        else
          v71 = -125;
        v72 = &config_buffer_variable_30;
      } else {
        if (graphic_mode == 11)
          v71 = -113;
        else
          v71 = -125;
        v72 = &config_buffer_variable_29;
      }
      prt_stringcol(rev_vga_variable_1, v72, 190, 76, v71);
      if (graphic_mode == 10)
        v73 = -113;
      else
        v73 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_39, 187, 86, v73);
      if ((textures_off & 4) != 0) {
        if (graphic_mode == 10)
          v74 = -113;
        else
          v74 = -125;
        v75 = &config_buffer_variable_30;
      } else {
        if (graphic_mode == 10)
          v74 = -113;
        else
          v74 = -125;
        v75 = &config_buffer_variable_29;
      }
      prt_stringcol(rev_vga_variable_1, v75, 190, 86, v74);
      if (graphic_mode == 9)
        v76 = -113;
      else
        v76 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_40, 187, 96, v76);
      if ((textures_off & 1) != 0) {
        if (graphic_mode == 9)
          v77 = -113;
        else
          v77 = -125;
        v78 = &config_buffer_variable_30;
      } else {
        if (graphic_mode == 9)
          v77 = -113;
        else
          v77 = -125;
        v78 = &config_buffer_variable_29;
      }
      prt_stringcol(rev_vga_variable_1, v78, 190, 96, v77);
      if (graphic_mode == 8)
        v79 = -113;
      else
        v79 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_41, 187, 106, v79);
      if ((textures_off & 0x80u) == 0) {
        if (graphic_mode == 8)
          v80 = -113;
        else
          v80 = -125;
        v81 = &config_buffer_variable_29;
      } else {
        if (graphic_mode == 8)
          v80 = -113;
        else
          v80 = -125;
        v81 = &config_buffer_variable_30;
      }
      prt_stringcol(rev_vga_variable_1, v81, 190, 106, v80);
      if (graphic_mode == 7)
        v82 = -113;
      else
        v82 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_42, 187, 116, v82);
      if ((textures_off & 2) != 0) {
        if (graphic_mode == 7)
          v83 = -113;
        else
          v83 = -125;
        v84 = &config_buffer_variable_30;
      } else {
        if (graphic_mode == 7)
          v83 = -113;
        else
          v83 = -125;
        v84 = &config_buffer_variable_29;
      }
      prt_stringcol(rev_vga_variable_1, v84, 190, 116, v83);
      if (graphic_mode == 6)
        v85 = -113;
      else
        v85 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_43, 187, 126, v85);
      if ((textures_off & 0x100) != 0) {
        if (graphic_mode == 6)
          v86 = -113;
        else
          v86 = -125;
        v87 = &config_buffer_variable_30;
      } else {
        if (graphic_mode == 6)
          v86 = -113;
        else
          v86 = -125;
        v87 = &config_buffer_variable_29;
      }
      prt_stringcol(rev_vga_variable_1, v87, 190, 126, v86);
      if (graphic_mode == 5)
        v88 = -113;
      else
        v88 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_44, 187, 136, v88);
      if ((textures_off & 8) != 0) {
        if (graphic_mode == 5)
          v89 = -113;
        else
          v89 = -125;
        v90 = &config_buffer_variable_30;
      } else {
        if (graphic_mode == 5)
          v89 = -113;
        else
          v89 = -125;
        v90 = &config_buffer_variable_29;
      }
      prt_stringcol(rev_vga_variable_1, v90, 190, 136, v89);
      if (graphic_mode == 4)
        v91 = -113;
      else
        v91 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_45, 187, 146, v91);
      if ((textures_off & 0x20) != 0) {
        if (graphic_mode == 4)
          v92 = -113;
        else
          v92 = -125;
        v93 = &config_buffer_variable_30;
      } else if ((((unsigned int)&loc_3FFFC + 4) & textures_off) != 0) {
        if (graphic_mode == 4)
          v92 = -113;
        else
          v92 = -125;
        v93 = &config_buffer_variable_47;
      } else {
        if (graphic_mode == 4)
          v92 = -113;
        else
          v92 = -125;
        v93 = &config_buffer_variable_29;
      }
      prt_stringcol(rev_vga_variable_1, v93, 190, 146, v92);
      if (graphic_mode == 3)
        v94 = -113;
      else
        v94 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_46, 187, 156, v94);
      if (view_limit) {
        if (graphic_mode == 3)
          v95 = -113;
        else
          v95 = -125;
        v96 = &config_buffer_variable_47;
      } else {
        if (graphic_mode == 3)
          v95 = -113;
        else
          v95 = -125;
        v96 = &config_buffer_variable_48;
      }
      prt_stringcol(rev_vga_variable_1, v96, 190, 156, v95);
      if (graphic_mode == 2)
        v97 = -113;
      else
        v97 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_49, 187, 166, v97);
      if (SVGA_ON)
        v98 = (100 * req_size - (__CFSHL__((100 * req_size) >> 31, 7) + ((100 * req_size) >> 31 << 7))) >> 7;
      else
        v98 = (100 * req_size - (__CFSHL__((100 * req_size) >> 31, 6) + ((100 * req_size) >> 31 << 6))) >> 6;
      sprintf(&buffer, "%3i %%", v98);
      if (graphic_mode == 2)
        v99 = -113;
      else
        v99 = -125;
      prt_stringcol(rev_vga_variable_1, &buffer, 190, 166, v99);
      if (SVGA_ON) {
        if (graphic_mode == 1)
          v100 = -113;
        else
          v100 = -125;
        v101 = (char *)&config_buffer_variable_8;
      } else {
        if (graphic_mode == 1)
          v100 = -113;
        else
          v100 = -125;
        v101 = (char *)&config_buffer_variable_7;
      }
      prt_centrecol(rev_vga_variable_1, v101, 160, 176, v100);
      if (graphic_mode)
        v102 = -125;
      else
        v102 = -113;
      LOBYTE(i) = prt_rightcol(rev_vga_variable_1, config_buffer_variable_13, 187, 186, v102);
      break;
    case 4:
      blankwindow(0, 0, 320, 200);
      prt_centrecol(rev_vga_variable_1, config_buffer_variable_23, 160, 16, 171);
      if (sound_edit == 1)
        v41 = -113;
      else
        v41 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_24, 172, 48, v41);
      volumebar(48, EngineVolume);
      if (sound_edit == 2)
        v42 = -113;
      else
        v42 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_25, 172, 60, v42);
      volumebar(60, SFXVolume);
      if (sound_edit == 3)
        v43 = -113;
      else
        v43 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_26, 172, 72, v43);
      volumebar(72, SpeechVolume);
      if (sound_edit == 4)
        v44 = -113;
      else
        v44 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_27, 172, 84, v44);
      volumebar(84, MusicVolume);
      if (sound_edit == 5)
        v45 = -113;
      else
        v45 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_28, 172, 96, v45);
      if (allengines) {
        if (sound_edit == 5)
          v46 = -113;
        else
          v46 = -125;
        v47 = &config_buffer_variable_31;
      } else {
        if (sound_edit == 5)
          v46 = -113;
        else
          v46 = -125;
        v47 = &config_buffer_variable_32;
      }
      prt_stringcol(rev_vga_variable_1, v47, 175, 96, v46);
      if (sound_edit == 6)
        v48 = -113;
      else
        v48 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_33, 172, 108, v48);
      if (soundon) {
        if (sound_edit == 6)
          v49 = -113;
        else
          v49 = -125;
        v50 = &config_buffer_variable_29;
      } else if (SoundCard) {
        if (sound_edit == 6)
          v49 = -113;
        else
          v49 = -125;
        v50 = &config_buffer_variable_30;
      } else {
        if (sound_edit == 6)
          v49 = -113;
        else
          v49 = -125;
        v50 = &config_buffer_variable_86;
      }
      prt_stringcol(rev_vga_variable_1, v50, 175, 108, v49);
      if (sound_edit == 7)
        v51 = -113;
      else
        v51 = -125;
      prt_rightcol(rev_vga_variable_1, config_buffer_variable_34, 172, 120, v51);
      if (musicon) {
        if (sound_edit == 7)
          v52 = -113;
        else
          v52 = -125;
        v53 = &config_buffer_variable_29;
      } else if (MusicCard || MusicCD) {
        if (sound_edit == 7)
          v52 = -113;
        else
          v52 = -125;
        v53 = &config_buffer_variable_30;
      } else {
        if (sound_edit == 7)
          v52 = -113;
        else
          v52 = -125;
        v53 = &config_buffer_variable_86;
      }
      prt_stringcol(rev_vga_variable_1, v53, 175, 120, v52);
      if (sound_edit)
        v54 = -125;
      else
        v54 = -113;
      LOBYTE(i) = prt_rightcol(rev_vga_variable_1, config_buffer_variable_13, 172, 132, v54);
      break;
    default:
      return i;
  }
  return i;
}

//-------------------------------------------------------------------------------------------------

void enable_keyboard()
{
  int v0; // eax

  while (1) {
    if (write_key == read_key && !twoparter)
      v0 = read_key ^ write_key;
    else
      v0 = -1;
    if (!v0)
      JUMPOUT(0x183C2);
    fatgetch();
  }
}

//-------------------------------------------------------------------------------------------------

void disable_keyboard()
{
  int v0; // eax

  while (1) {
    if (write_key == read_key && !twoparter)
      v0 = read_key ^ write_key;
    else
      v0 = -1;
    if (!v0)
      JUMPOUT(0x183C2);
    fatgetch();
  }
}

//-------------------------------------------------------------------------------------------------

_DWORD *save_fatal_config()
{
  int v0; // esi
  _DWORD *result; // eax
  _DWORD *v2; // esi
  unsigned int v3; // edi
  unsigned int v4; // eax
  unsigned int v5[7]; // [esp+0h] [ebp-1Ch] BYREF

  v0 = fopen(&aAtfatalIni[2], &aLw[1]);
  fprintf(
    v0,
    "EngineVolume=%d\n",
    4 * ((EngineVolume + 1 - (__CFSHL__((EngineVolume + 1) >> 31, 2) + 4 * ((EngineVolume + 1) >> 31))) >> 2));
  fprintf(
    v0,
    "SFXVolume=%d\n",
    4 * ((SFXVolume + 1 - (__CFSHL__((SFXVolume + 1) >> 31, 2) + 4 * ((SFXVolume + 1) >> 31))) >> 2));
  fprintf(
    v0,
    "SpeechVolume=%d\n",
    4 * ((SpeechVolume + 1 - (__CFSHL__((SpeechVolume + 1) >> 31, 2) + 4 * ((SpeechVolume + 1) >> 31))) >> 2));
  fprintf(
    v0,
    "MusicVolume=%d\n",
    4 * ((MusicVolume + 1 - (__CFSHL__((MusicVolume + 1) >> 31, 2) + 4 * ((MusicVolume + 1) >> 31))) >> 2));
  if (allengines)
    fprintf(v0, "CarE=1\n");
  else
    fprintf(v0, "CarE=0\n");
  if (soundon)
    fprintf(v0, "SfxO=1\n");
  else
    fprintf(v0, "SfxO=0\n");
  if (musicon)
    fprintf(v0, "MusO=1\n");
  else
    fprintf(v0, "MusO=0\n");
  fprintf(v0, "SVGA=%d\n", abs32(game_svga));
  if (game_svga)
    fprintf(v0, "Size=%d\n", game_size);
  else
    fprintf(v0, "Size=%d\n", 2 * game_size);
  fprintf(v0, "View=%i\n", game_view);
  fprintf(v0, "Names=%i\n", abs32(names_on));
  fprintf(v0, "P1left=%i\n", (unsigned __int8)userkey[0]);
  fprintf(v0, "P1right=%i\n", (unsigned __int8)userkey_variable_1);
  fprintf(v0, "P1up=%i\n", (unsigned __int8)userkey_variable_2);
  fprintf(v0, "P1down=%i\n", (unsigned __int8)userkey_variable_3);
  fprintf(v0, "P1upgear=%i\n", (unsigned __int8)userkey_variable_4);
  fprintf(v0, "P1downgear=%i\n", (unsigned __int8)userkey_variable_5);
  fprintf(v0, "P1cheat=%i\n", (unsigned __int8)userkey_variable_12);
  fprintf(v0, "P2left=%i\n", (unsigned __int8)userkey_variable_6);
  fprintf(v0, "P2right=%i\n", (unsigned __int8)userkey_variable_7);
  fprintf(v0, "P2up=%i\n", (unsigned __int8)userkey_variable_8);
  fprintf(v0, "P2down=%i\n", (unsigned __int8)userkey_variable_9);
  fprintf(v0, "P2upgear=%i\n", (unsigned __int8)userkey_variable_10);
  fprintf(v0, "P2downgear=%i\n", (unsigned __int8)userkey_variable_11);
  fprintf(v0, "P2cheat=%i\n", (unsigned __int8)userkey_variable_13);
  fprintf(v0, "Joy1X=%i\n", x1ok != 0);
  fprintf(v0, "Joy1Y=%i\n", y1ok != 0);
  fprintf(v0, "Joy2X=%i\n", x2ok != 0);
  fprintf(v0, "Joy2Y=%i\n", y2ok != 0);
  if (x1ok) {
    fprintf(v0, "Joy1Xmin=%i\n", JAXmin);
    fprintf(v0, "Joy1Xmax=%i\n", JAXmax);
  }
  if (y1ok) {
    fprintf(v0, "Joy1Ymin=%i\n", JAYmin);
    fprintf(v0, "Joy1Ymax=%i\n", JAYmax);
  }
  if (x2ok) {
    fprintf(v0, "Joy2Xmin=%i\n", JBXmin);
    fprintf(v0, "Joy2Xmax=%i\n", JBXmax);
  }
  if (y2ok) {
    fprintf(v0, "Joy2Ymin=%i\n", JBYmin);
    fprintf(v0, "Joy2Ymax=%i\n", JBYmax);
  }
  name_copy((int)&buffer, player_names);
  fprintf(v0, "Nom=%s\n", &buffer);
  fprintf(v0, "Car1=%i\n", Players_Cars[0]);
  if (player_type == 2) {
    name_copy((int)&buffer, player_names_variable_1);
    fprintf(v0, "Han=%s\n", &buffer);
    fprintf(v0, "Car2=%i\n", Players_Cars_variable_1);
  }
  fprintf(v0, "Level=%i\n", level);
  fprintf(v0, "Damage=%i\n", damage_level);
  fprintf(v0, "Detail=%i\n", textures_off);
  if (view_limit)
    fprintf(v0, "Ahead=1\n");
  else
    fprintf(v0, "Ahead=0\n");
  fprintf(v0, "Record=%i\n", replay_record);
  fprintf(v0, "Game=%i\n", game_type);
  fprintf(v0, "Racers=%i\n", competitors);
  fprintf(v0, "Track=%i\n", TrackLoad);
  fprintf(v0, "Players=%i\n", player_type);
  fprintf(v0, "Ariel1=%s\n", &default_names);
  fprintf(v0, "Ariel2=%s\n", "HAL");
  fprintf(v0, "DeSilva1=%s\n", aSlave);
  fprintf(v0, "DeSilva2=%s\n", aZen);
  fprintf(v0, "Pulse1=%s\n", aAsh);
  fprintf(v0, "Pulse2=%s\n", aBishop);
  fprintf(v0, "Global1=%s\n", aVoyager);
  fprintf(v0, "Global2=%s\n", aNomad);
  fprintf(v0, "Million1=%s\n", aBob);
  fprintf(v0, "Million2=%s\n", aVincent);
  fprintf(v0, "Mission1=%s\n", aEddie);
  fprintf(v0, "Mission2=%s\n", aMarvin);
  fprintf(v0, "Zizin1=%s\n", aKryten);
  fprintf(v0, "Zizin2=%s\n", aHolly);
  fprintf(v0, "Reise1=%s\n", aRobby);
  fprintf(v0, "Reise2=%s\n", aGort);
  fprintf(v0, "NetMes1=%s\n", aSlowcoach);
  fprintf(v0, "NetMes2=%s\n", aOutOfMyWay);
  fprintf(v0, "NetMes3=%s\n", aYouDie);
  fprintf(v0, "NetMes4=%s\n", aSucker);
  fprintf(v0, "ComPort=%i\n", serial_port);
  fprintf(v0, "ModemPort=%i\n", modem_port);
  fprintf(v0, "ModemTone=%i\n", modem_tone);
  fprintf(v0, "ModemInit=%s\n", "ATX");
  fprintf(v0, "ModemPhone=%s\n", &modem_phone);
  fprintf(v0, "ModemCall=%i\n", modem_call);
  fprintf(v0, "ModemType=%i\n", current_modem);
  fprintf(v0, "NetSlot=%i\n", network_slot);
  fprintf(v0, "ModemBaud=%i\n", modem_baud);
  fclose(v0);
  result = (_DWORD *)fopen(&aAtfatalIni[2], aRb_2);
  v2 = result;
  if (result) {
    fseek(result, 0, 2);
    v3 = ftell(v2);
    fseek(v2, 0, 0);
    v4 = getbuffer(v3);
    v5[0] = v4;
    if (v4) {
      fread(v4, 1, v3, v2);
      fclose(v2);
      decode(v5[0], v3, 77, 101);
      fopen(&aAtfatalIni[2], &aMwb[1]);
      if (v2) {
        fwrite(v5[0], 1, v3, v2);
        fclose(v2);
      }
      return fre(v5);
    } else {
      fclose(v2);
      return (_DWORD *)remove(&aAtfatalIni[2]);
    }
  }
  return result;
}

//-------------------------------------------------------------------------------------------------

int load_fatal_config()
{
  _DWORD *v0; // eax
  _DWORD *v1; // edi
  int v2; // ebp
  unsigned int v3; // eax
  int i; // eax
  char *v5; // ebx
  char *ConfigVar; // eax
  char v7; // dh
  int v8; // ecx
  char *v9; // ebx
  char *v10; // eax
  char v11; // cl
  char *v12; // ebx
  char *v13; // eax
  char v14; // dl
  char *v15; // ebx
  _BYTE *v16; // eax
  char *v17; // ebx
  char *v18; // eax
  char v19; // dl
  char *v20; // ebx
  _BYTE *v21; // eax
  char *v22; // ebx
  char *v23; // eax
  char v24; // dl
  char *v25; // ebx
  _BYTE *v26; // eax
  char *v27; // ebx
  char *v28; // eax
  char v29; // dl
  char *v30; // ebx
  _BYTE *v31; // eax
  char *v32; // ebx
  char *v33; // eax
  char v34; // dl
  char *v35; // ebx
  _BYTE *v36; // eax
  char *v37; // ebx
  char *v38; // eax
  char v39; // dl
  char *v40; // ebx
  _BYTE *v41; // eax
  char *v42; // ebx
  char *v43; // eax
  char v44; // dl
  char *v45; // ebx
  _BYTE *v46; // eax
  char *v47; // ebx
  char *v48; // eax
  char v49; // dl
  char *v50; // ebx
  _BYTE *v51; // eax
  char *v52; // ebx
  char *v53; // eax
  char v54; // dl
  char *v55; // ebx
  char *v56; // eax
  char v57; // dh
  char *v58; // ebx
  _BYTE *v59; // eax
  char *v60; // ebx
  char *v61; // eax
  char v62; // ch
  const char *v63; // ebx
  char *v64; // eax
  char v65; // dl
  char *v66; // ebx
  char *v67; // eax
  char v68; // dh
  int v70; // [esp+0h] [ebp-24h]
  unsigned int v71; // [esp+4h] [ebp-20h] BYREF
  int v72; // [esp+8h] [ebp-1Ch]

  JAXmin = 10000;
  JAXmax = -10000;
  JAYmin = 10000;
  JAYmax = -10000;
  JBXmin = 10000;
  JBXmax = -10000;
  JBYmin = 10000;
  JBYmax = -10000;
  x1ok = 0;
  y1ok = 0;
  x2ok = 0;
  y2ok = 0;
  bitaccept = 0;
  Joy1used = 0;
  Joy2used = 0;
  fatal_ini_loaded = 0;
  v0 = (_DWORD *)fopen(&aAtfatalIni[2], aRb_2);
  v1 = v0;
  if (v0) {
    fatal_ini_loaded = -1;
    fseek(v0, 0, 2);
    v2 = ftell(v1);
    fseek(v1, 0, 0);
    v3 = getbuffer(v2 + 1);
    v71 = v3;
    if (v3) {
      fread(v3, 1, v2, v1);
      fclose(v1);
      decode(v71, v2, 77, 101);
      for (i = 0; i < v2; ++i) {
        if (*(_BYTE *)(i + v71) == 13)
          *(_BYTE *)(i + v71) = 10;
      }
      *(_BYTE *)(v71 + v2) = 0;
      getconfigvalue(128);
      getconfigvalue(128);
      getconfigvalue(128);
      getconfigvalue(128);
      if (EngineVolume == 128)
        EngineVolume = 127;
      if (SFXVolume == 128)
        SFXVolume = 127;
      if (SpeechVolume == 128)
        SpeechVolume = 127;
      if (MusicVolume == 128)
        MusicVolume = 127;
      getconfigvalue(1);
      if (allengines)
        allengines = -1;
      getconfigvalue(1);
      if (soundon)
        soundon = -1;
      getconfigvalue(1);
      if (musicon)
        musicon = -1;
      getconfigvalue(1);
      if (game_svga == 1)
        game_svga = -1;
      if (no_mem)
        game_svga = 0;
      game_size = 128;
      getconfigvalue(128);
      if (!game_svga)
        game_size /= 2;
      getconfigvalue(8);
      getconfigvalue(2);
      getconfigvalueuc(v71, (int)&aAlp1left[2], userkey, 0, 139);
      getconfigvalueuc(v71, (int)&aIp1right[1], &userkey_variable_1, 0, 139);
      getconfigvalueuc(v71, (int)aP1up, &userkey_variable_2, 0, 139);
      getconfigvalueuc(v71, (int)&aP1down[2], &userkey_variable_3, 0, 139);
      getconfigvalueuc(v71, (int)&aP1upgear[1], &userkey_variable_4, 0, 139);
      getconfigvalueuc(v71, (int)&aBaup1downgear[3], &userkey_variable_5, 0, 139);
      getconfigvalueuc(v71, (int)&aMp1cheat[1], &userkey_variable_12, 0, 139);
      getconfigvalueuc(v71, (int)aP2left, &userkey_variable_6, 0, 139);
      getconfigvalueuc(v71, (int)&aEp2right[1], &userkey_variable_7, 0, 139);
      getconfigvalueuc(v71, (int)aP2up, &userkey_variable_8, 0, 139);
      getconfigvalueuc(v71, (int)aP2down, &userkey_variable_9, 0, 139);
      getconfigvalueuc(v71, (int)&aOp2upgear[1], &userkey_variable_10, 0, 139);
      getconfigvalueuc(v71, (int)&aUsip2downgear[3], &userkey_variable_11, 0, 139);
      getconfigvalueuc(v71, (int)&aEp2cheat[1], &userkey_variable_13, 0, 139);
      getconfigvalue(1);
      x1ok = v70 != 0;
      getconfigvalue(1);
      if (v70)
        y1ok = 2;
      else
        y1ok = 0;
      getconfigvalue(1);
      if (v70)
        x2ok = 4;
      else
        x2ok = 0;
      getconfigvalue(1);
      if (v70)
        y2ok = 8;
      else
        y2ok = 0;
      if (x1ok) {
        JAXmin = 10000;
        JAXmax = -10000;
        getconfigvalue(0x7FFFFFFF);
        JAXmin = 10000;
        v72 = JAXmax;
        getconfigvalue(0x7FFFFFFF);
        JAXmax = v72;
        if (v72 < JAXmin)
          x1ok = 0;
      }
      if (y1ok) {
        JAYmin = 10000;
        JAYmax = -10000;
        getconfigvalue(0x7FFFFFFF);
        JAYmin = 10000;
        v72 = JAYmax;
        getconfigvalue(0x7FFFFFFF);
        JAYmax = v72;
        if (v72 < JAYmin)
          y1ok = 0;
      }
      if (x2ok) {
        JBXmin = 10000;
        JBXmax = -10000;
        getconfigvalue(0x7FFFFFFF);
        JBXmin = 10000;
        v72 = JBXmax;
        getconfigvalue(0x7FFFFFFF);
        JBXmax = v72;
        if (v72 < JBXmin)
          x2ok = 0;
      }
      if (y2ok) {
        JBYmin = 10000;
        JBYmax = -10000;
        getconfigvalue(0x7FFFFFFF);
        JBYmin = 10000;
        v72 = JBYmax;
        getconfigvalue(0x7FFFFFFF);
        JBYmax = v72;
        if (v72 < JBYmin)
          y2ok = 0;
      }
      if (JAXmin == JAXmax)
        JAXmax = JAXmin + 1;
      if (JAYmin == JAYmax)
        JAYmax = JAYmin + 1;
      if (JBXmin == JBXmax)
        JBXmax = JBXmin + 1;
      if (JBYmin == JBYmax)
        JBYmax = JBYmin + 1;
      bitaccept = y2ok | x2ok | y1ok | x1ok;
      v5 = &buffer;
      ConfigVar = (char *)FindConfigVar(v71, aNom, &buffer, 0);
      if (ConfigVar) {
        while (1) {
          v7 = *ConfigVar;
          if (*ConfigVar == 10)
            break;
          ++v5;
          ++ConfigVar;
          *(v5 - 1) = v7;
        }
        *v5 = 0;
      }
      if (!buffer)
        strcpy(&buffer, "HUMAN");
      name_copy((int)player_names, &buffer);
      getconfigvalue(15);
      Players_Cars[0] = 0;
      v72 = level;
      getconfigvalue(5);
      level = v72;
      v72 = damage_level;
      getconfigvalue(2);
      damage_level = v72;
      v72 = textures_off;
      getconfigvalue(0x7FFFFFFF);
      textures_off = v72;
      getconfigvalue(1);
      getconfigvalue(1);
      v72 = game_type;
      getconfigvalue(2);
      game_type = v72;
      v72 = competitors;
      getconfigvalue(16);
      competitors = v72;
      v72 = TrackLoad;
      getconfigvalue(24);
      TrackLoad = v72;
      v8 = 0;
      getconfigvalue(4);
      if (player_type && player_type != 2) {
        v8 = 0;
        player_type = 0;
      }
      if (player_type == 2) {
        v9 = &buffer;
        v10 = (char *)FindConfigVar(v71, aHan, &buffer, 0);
        if (v10) {
          while (1) {
            v11 = *v10;
            if (*v10 == 10)
              break;
            ++v9;
            ++v10;
            *(v9 - 1) = v11;
          }
          *v9 = 0;
        }
        if (!buffer)
          strcpy(&buffer, "PLAYER 2");
        v8 = -1;
        name_copy((int)player_names_variable_1, &buffer);
        v72 = 0;
        getconfigvalue(15);
        Players_Cars_variable_1 = 0;
      }
      if (game_type == 1)
        TrackLoad = 8 * ((TrackLoad - 1 - (__CFSHL__((TrackLoad - 1) >> 31, 3) + 8 * ((TrackLoad - 1) >> 31))) >> 3) + 1;
      v12 = &buffer;
      v13 = (char *)FindConfigVar(v71, &aOy1ariel1[3], &buffer, v8);
      if (v13) {
        while (1) {
          v14 = *v13;
          if (*v13 == 10)
            break;
          ++v12;
          ++v13;
          *(v12 - 1) = v14;
        }
        *v12 = 0;
      }
      if (!buffer)
        strcpy(&buffer, "COMP 1");
      name_copy((int)&default_names, &buffer);
      v15 = &buffer;
      v16 = (_BYTE *)FindConfigVar(v71, &aNariel2[1], &buffer, v8);
      if (v16) {
        while (1) {
          LOBYTE(v8) = *v16;
          if (*v16 == 10)
            break;
          ++v15;
          ++v16;
          *(v15 - 1) = v8;
        }
        *v15 = 0;
      }
      if (!buffer)
        strcpy(&buffer, "COMP 2");
      name_copy((int)"HAL", &buffer);
      v17 = &buffer;
      v18 = (char *)FindConfigVar(v71, &aMdesilva1[1], &buffer, v8);
      if (v18) {
        while (1) {
          v19 = *v18;
          if (*v18 == 10)
            break;
          ++v17;
          ++v18;
          *(v17 - 1) = v19;
        }
        *v17 = 0;
      }
      if (!buffer)
        strcpy(&buffer, "COMP 3");
      name_copy((int)aSlave, &buffer);
      v20 = &buffer;
      v21 = (_BYTE *)FindConfigVar(v71, &aXdesilva2[1], &buffer, v8);
      if (v21) {
        while (1) {
          LOBYTE(v8) = *v21;
          if (*v21 == 10)
            break;
          ++v20;
          ++v21;
          *(v20 - 1) = v8;
        }
        *v20 = 0;
      }
      if (!buffer)
        strcpy(&buffer, "COMP 4");
      name_copy((int)aZen, &buffer);
      v22 = &buffer;
      v23 = (char *)FindConfigVar(v71, &a1pulse1[1], &buffer, v8);
      if (v23) {
        while (1) {
          v24 = *v23;
          if (*v23 == 10)
            break;
          ++v22;
          ++v23;
          *(v22 - 1) = v24;
        }
        *v22 = 0;
      }
      if (!buffer)
        strcpy(&buffer, "COMP 5");
      name_copy((int)aAsh, &buffer);
      v25 = &buffer;
      v26 = (_BYTE *)FindConfigVar(v71, &aApulse2[1], &buffer, v8);
      if (v26) {
        while (1) {
          LOBYTE(v8) = *v26;
          if (*v26 == 10)
            break;
          ++v25;
          ++v26;
          *(v25 - 1) = v8;
        }
        *v25 = 0;
      }
      if (!buffer)
        strcpy(&buffer, "COMP 6");
      name_copy((int)aBishop, &buffer);
      v27 = &buffer;
      v28 = (char *)FindConfigVar(v71, &aAglobal1[1], &buffer, v8);
      if (v28) {
        while (1) {
          v29 = *v28;
          if (*v28 == 10)
            break;
          ++v27;
          ++v28;
          *(v27 - 1) = v29;
        }
        *v27 = 0;
      }
      if (!buffer)
        strcpy(&buffer, "COMP 7");
      name_copy((int)aVoyager, &buffer);
      v30 = &buffer;
      v31 = (_BYTE *)FindConfigVar(v71, &aIglobal2[1], &buffer, v8);
      if (v31) {
        while (1) {
          LOBYTE(v8) = *v31;
          if (*v31 == 10)
            break;
          ++v30;
          ++v31;
          *(v30 - 1) = v8;
        }
        *v30 = 0;
      }
      if (!buffer)
        strcpy(&buffer, "COMP 8");
      name_copy((int)aNomad, &buffer);
      v32 = &buffer;
      v33 = (char *)FindConfigVar(v71, &aOmillion1[1], &buffer, v8);
      if (v33) {
        while (1) {
          v34 = *v33;
          if (*v33 == 10)
            break;
          ++v32;
          ++v33;
          *(v32 - 1) = v34;
        }
        *v32 = 0;
      }
      if (!buffer)
        strcpy(&buffer, "COMP 9");
      name_copy((int)aBob, &buffer);
      v35 = &buffer;
      v36 = (_BYTE *)FindConfigVar(v71, aMillion2, &buffer, v8);
      if (v36) {
        while (1) {
          LOBYTE(v8) = *v36;
          if (*v36 == 10)
            break;
          ++v35;
          ++v36;
          *(v35 - 1) = v8;
        }
        *v35 = 0;
      }
      if (!buffer)
        strcpy(&buffer, "COMP 10");
      name_copy((int)aVincent, &buffer);
      v37 = &buffer;
      v38 = (char *)FindConfigVar(v71, aMission1, &buffer, v8);
      if (v38) {
        while (1) {
          v39 = *v38;
          if (*v38 == 10)
            break;
          ++v37;
          ++v38;
          *(v37 - 1) = v39;
        }
        *v37 = 0;
      }
      if (!buffer)
        strcpy(&buffer, "COMP 11");
      name_copy((int)aEddie, &buffer);
      v40 = &buffer;
      v41 = (_BYTE *)FindConfigVar(v71, aMission2, &buffer, v8);
      if (v41) {
        while (1) {
          LOBYTE(v8) = *v41;
          if (*v41 == 10)
            break;
          ++v40;
          ++v41;
          *(v40 - 1) = v8;
        }
        *v40 = 0;
      }
      if (!buffer)
        strcpy(&buffer, "COMP 12");
      name_copy((int)aMarvin, &buffer);
      v42 = &buffer;
      v43 = (char *)FindConfigVar(v71, aZizin1, &buffer, v8);
      if (v43) {
        while (1) {
          v44 = *v43;
          if (*v43 == 10)
            break;
          ++v42;
          ++v43;
          *(v42 - 1) = v44;
        }
        *v42 = 0;
      }
      if (!buffer)
        strcpy(&buffer, "COMP 13");
      name_copy((int)aKryten, &buffer);
      v45 = &buffer;
      v46 = (_BYTE *)FindConfigVar(v71, aZizin2, &buffer, v8);
      if (v46) {
        while (1) {
          LOBYTE(v8) = *v46;
          if (*v46 == 10)
            break;
          ++v45;
          ++v46;
          *(v45 - 1) = v8;
        }
        *v45 = 0;
      }
      if (!buffer)
        strcpy(&buffer, "COMP 14");
      name_copy((int)aHolly, &buffer);
      v47 = &buffer;
      v48 = (char *)FindConfigVar(v71, aReise1, &buffer, v8);
      if (v48) {
        while (1) {
          v49 = *v48;
          if (*v48 == 10)
            break;
          ++v47;
          ++v48;
          *(v47 - 1) = v49;
        }
        *v47 = 0;
      }
      if (!buffer)
        strcpy(&buffer, "COMP 15");
      name_copy((int)aRobby, &buffer);
      v50 = &buffer;
      v51 = (_BYTE *)FindConfigVar(v71, aReise2, &buffer, v8);
      if (v51) {
        while (1) {
          LOBYTE(v8) = *v51;
          if (*v51 == 10)
            break;
          ++v50;
          ++v51;
          *(v50 - 1) = v8;
        }
        *v50 = 0;
      }
      if (!buffer)
        strcpy(&buffer, "COMP 16");
      name_copy((int)aGort, &buffer);
      v52 = aSlowcoach;
      v53 = (char *)FindConfigVar(v71, aNetmes1, aSlowcoach, v8);
      if (v53) {
        while (1) {
          v54 = *v53;
          if (*v53 == 10)
            break;
          ++v52;
          ++v53;
          *(v52 - 1) = v54;
        }
        *v52 = 0;
      }
      v55 = aOutOfMyWay;
      v56 = (char *)FindConfigVar(v71, aNetmes2, aOutOfMyWay, v8);
      if (v56) {
        while (1) {
          v57 = *v56;
          if (*v56 == 10)
            break;
          ++v55;
          ++v56;
          *(v55 - 1) = v57;
        }
        *v55 = 0;
      }
      v58 = aYouDie;
      v59 = (_BYTE *)FindConfigVar(v71, aNetmes3, aYouDie, v8);
      if (v59) {
        while (1) {
          LOBYTE(v8) = *v59;
          if (*v59 == 10)
            break;
          ++v58;
          ++v59;
          *(v58 - 1) = v8;
        }
        *v58 = 0;
      }
      v60 = aSucker;
      v61 = (char *)FindConfigVar(v71, aNetmes4, aSucker, v8);
      if (v61) {
        while (1) {
          v62 = *v61;
          if (*v61 == 10)
            break;
          ++v60;
          ++v61;
          *(v60 - 1) = v62;
        }
        *v60 = 0;
      }
      getconfigvalue(4);
      getconfigvalue(4);
      getconfigvalue(10);
      v63 = "ATX";
      v64 = (char *)FindConfigVar(v71, &aInmodeminit[2], "ATX", -10);
      if (v64) {
        while (1) {
          v65 = *v64;
          if (*v64 == 10)
            break;
          ++v63;
          ++v64;
          *((_BYTE *)v63 - 1) = v65;
        }
        *v63 = 0;
      }
      v66 = &modem_phone;
      v67 = (char *)FindConfigVar(v71, &aSsmodemphone[2], &modem_phone, -10);
      if (v67) {
        while (1) {
          v68 = *v67;
          if (*v67 == 10)
            break;
          ++v66;
          ++v67;
          *(v66 - 1) = v68;
        }
        *v66 = 0;
      }
      getconfigvalue(10);
      getconfigvalue(800);
      getconfigvalue(28800);
      v72 = network_slot;
      getconfigvalue(99999999);
      network_slot = v72;
      v0 = fre(&v71);
    } else {
      v0 = (_DWORD *)fclose(v1);
    }
  }
  return remove_uncalibrated(v0);
}

//-------------------------------------------------------------------------------------------------

int __fastcall getconfigvalue(int a1, int a2, int *a3, int a4, int a5)
{
  int result; // eax
  int v6; // [esp+0h] [ebp-4h] BYREF

  result = FindConfigVar(a1, a2, a3, a4);
  if (result) {
    sscanf(result, "%i", &v6);
    if (a4 > v6)
      v6 = a4;
    if (v6 > a5)
      v6 = a5;
    result = v6;
    *a3 = v6;
  }
  return result;
}

//-------------------------------------------------------------------------------------------------

char __fastcall getconfigvalueuc(int a1, int a2, _BYTE *a3, int a4, int a5)
{
  int ConfigVar; // eax
  __int16 v7; // [esp+0h] [ebp-4h] BYREF

  ConfigVar = FindConfigVar(a1, a2, a3, a4);
  if (ConfigVar) {
    sscanf(ConfigVar, "%hi", &v7);
    if (v7 < a4)
      v7 = a4;
    if (v7 > a5)
      v7 = a5;
    LOBYTE(ConfigVar) = v7;
    *a3 = v7;
  }
  return ConfigVar;
}

//-------------------------------------------------------------------------------------------------

int __fastcall displaycalibrationbar(int a1, int a2, int a3)
{
  int v3; // esi
  int v4; // ebp
  _BYTE *v5; // ecx
  int result; // eax
  int v7; // ebp
  int i; // edi
  int v9; // eax
  int v10; // ebp
  int j; // edi
  int v12; // eax
  int v13; // [esp+0h] [ebp-1Ch]

  v3 = winw;
  v4 = a3;
  if (a3 < -100)
    v4 = -100;
  if (v4 > 100)
    v4 = 100;
  v5 = (_BYTE *)(winw * a1 / 320 + scrbuf + winw * ((a2 * scr_size) >> 6));
  v13 = (10 * scr_size) >> 6;
  result = v13 - 1;
  if (current_mode) {
    v7 = v4 + 103;
    for (i = 0; i < v13; ++i) {
      if (i && i != v13 - 1) {
        *v5 = -113;
        v5[206 * v3 / 640] = -113;
        v9 = v3 * v7 / 640;
        v5[v9] = -85;
        v5[v9 - 1] = -85;
        v5[v9 - 2] = -85;
        v5[v9 + 1] = -85;
        v5[v9 + 2] = -85;
        v5[103 * v3 / 640] = -25;
        v5[104 * v3 / 640] = -25;
        result = 102 * v3 / 640;
        v5[result] = -25;
      } else {
        winw = v3;
        result = memset(v5, 143, 104 * v3 / 320 - 1);
        v3 = winw;
      }
      v5 += v3;
    }
  } else {
    v10 = v4 + 105;
    for (j = 0; j < v13; ++j) {
      if (j && j != v13 - 1) {
        *v5 = -113;
        v5[208 * v3 / 640] = -113;
        v12 = v3 * v10 / 640;
        v5[v12] = -85;
        v5[v12 - 1] = -85;
        v5[v12 + 1] = -85;
        result = 105 * v3 / 640;
        v5[result] = -25;
      } else {
        winw = v3;
        result = memset(v5, 143, 104 * v3 / 320 + 1);
        v3 = winw;
      }
      v5 += v3;
    }
  }
  winw = v3;
  return result;
}

//-------------------------------------------------------------------------------------------------

int __fastcall blankwindow(int a1, int a2, int a3, int a4)
{
  _DWORD v5[13]; // [esp+0h] [ebp-34h] BYREF

  if (SVGA_ON) {
    a3 *= 2;
    a2 *= 2;
    a1 *= 2;
    a4 *= 2;
  }
  v5[2] = a3;
  v5[3] = a2;
  v5[4] = a1;
  v5[5] = a2;
  v5[6] = a1;
  v5[7] = a4;
  v5[8] = a3;
  v5[9] = a4;
  v5[0] = 2097155;
  v5[1] = 4;
  return POLYFLAT(scrbuf, v5);
}

//-------------------------------------------------------------------------------------------------

int __fastcall volumebar(int a1, int a2)
{
  _BYTE *v2; // ecx
  int result; // eax
  int v4; // esi
  int v5; // ebp
  int v6; // edi

  v2 = (_BYTE *)(scrbuf + 175 * winw / 320 + ((scr_size * a1) >> 6) * winw);
  result = 100 * a2 / 127 * winw / 320;
  v4 = 0;
  v5 = (10 * scr_size) >> 6;
  v6 = result;
  if (v5 > 0) {
    do {
      if (v4 && v4 != v5 - 1) {
        *v2 = 112;
        memset(v2 + 1, 171, v6);
        result = 101 * winw / 320;
        v2[result] = 112;
      } else {
        result = memset(v2, 112, 102 * winw / 320);
      }
      v2 += winw;
      ++v4;
    } while (v4 < v5);
  }
  return result;
}

//-------------------------------------------------------------------------------------------------

int remove_uncalibrated()
{
  int result; // eax

  if (JAXmax - JAXmin < 100)
    x1ok = 0;
  if (JAYmax - JAYmin < 100)
    y1ok = 0;
  if (JBXmax - JBXmin < 100)
    x2ok = 0;
  if (JBYmax - JBYmin < 100)
    y2ok = 0;
  result = y2ok;
  bitaccept = y2ok | y1ok | x1ok | x2ok;
  if (x1ok || y1ok)
    Joy1used = -1;
  else
    Joy1used = x1ok;
  if (x2ok || y2ok)
    Joy2used = -1;
  else
    Joy2used = x2ok;
  return result;
}

//-------------------------------------------------------------------------------------------------

int __fastcall LoadRecords(int a1, int a2, int a3)
{
  int v3; // edx
  int v4; // ebp
  int v5; // edx
  int result; // eax
  int v7; // edx
  char *v8; // edi
  char *v9; // edi
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // eax
  int v14; // edx
  char *v15; // edi
  int *v16; // ebx
  int v17; // ebp
  int v18; // ecx
  int v19; // eax
  int v20; // esi
  int v21; // eax
  char v22; // dl
  unsigned int v23; // [esp+0h] [ebp-24h] BYREF
  int v24; // [esp+4h] [ebp-20h]
  int v25; // [esp+8h] [ebp-1Ch]

  v3 = open(aDgkfcRec, 512, v23);
  v4 = v3;
  if (v3 == -1) {
    v5 = 9;
    RecordCars[0] = -1;
    RecordLaps[0] = 128.0;
    RecordKills[0] = 0;
    result = 1;
    strcpy(RecordNames, "----");
    do {
      RecordLaps[result] = 128.0;
      RecordCars[result] = -1;
      RecordKills[result] = 0;
      strcpy(&RecordNames[v5], "----");
      v7 = v5 + 9;
      RecordCars_variable_1[result] = -1;
      RecordLaps_variable_1[result] = 1124073472;
      v8 = &RecordNames[v7];
      RecordKills_variable_1[result] = 0;
      v7 += 9;
      strcpy(v8, "----");
      result += 3;
      v9 = &RecordNames[v7];
      RecordLaps_variable_3[result] = -1;
      updates[result] = 1124073472;
      RecordCars_variable_3[result] = 0;
      v5 = v7 + 9;
      strcpy(v9, "----");
    } while (result != 25);
  } else {
    v23 = getbuffer(0x400u);
    v10 = filelength(v3, v3, a3);
    v11 = v10;
    if (v10 == 336 || v10 == 504) {
      read(v3, v23, v10);
      close(v3, v23);
      v16 = (int *)v23;
      v17 = 1;
      v24 = v11 / 21;
      if (v11 / 21 >= 1) {
        v18 = 1;
        v25 = 18;
        do {
          RecordLaps[v18] = (double)*v16 * func2_c_variable_325;
          v19 = v16[1];
          v16 += 3;
          RecordCars[v18] = v19;
          v20 = v25;
          RecordKills[v18] = *(v16 - 1);
          v21 = 9 * v17;
          do {
            ++v21;
            v22 = *(_BYTE *)v16;
            v16 = (int *)((char *)v16 + 1);
            *((_BYTE *)&fudge_wait + v21 + 3) = v22;
          } while (v21 != v20);
          if (RecordLaps[v18] < func2_c_variable_326) {
            RecordLaps[v18] = 128.0;
            RecordCars[v18] = -1;
            RecordKills[v18] = 0;
            strcpy(&RecordNames[9 * v17], "----");
          }
          ++v18;
          ++v17;
          v25 += 9;
        } while (v17 <= v24);
      }
      return (int)fre(&v23);
    } else {
      v12 = 9;
      v13 = 1;
      RecordKills[0] = 0;
      RecordLaps[0] = 128.0;
      RecordCars[0] = -1;
      strcpy(RecordNames, "----");
      do {
        RecordLaps[v13] = 128.0;
        RecordKills[v13] = 0;
        RecordCars[v13] = -1;
        strcpy(&RecordNames[v12], "----");
        v14 = v12 + 9;
        RecordLaps_variable_1[v13] = 1124073472;
        RecordKills_variable_1[v13] = 0;
        RecordCars_variable_1[v13] = -1;
        v13 += 3;
        strcpy(&RecordNames[v14], "----");
        v14 += 9;
        updates[v13] = 1124073472;
        RecordCars_variable_3[v13] = 0;
        v15 = &RecordNames[v14];
        RecordLaps_variable_3[v13] = -1;
        v12 = v14 + 9;
        strcpy(v15, "----");
      } while (v13 != 25);
      close(v4, v12);
      return (int)fre(&v23);
    }
  }
  return result * 4;
}

//-------------------------------------------------------------------------------------------------

_DWORD *SaveRecords()
{
  int v0; // ebp
  int v1; // ebx
  int v2; // esi
  unsigned int v3; // eax
  int v4; // edi
  int v5; // edx
  double v6; // st7
  int v7; // eax
  int v8; // eax
  int v9; // edi
  char v10; // cl
  int v11; // esi
  unsigned int v13; // [esp+0h] [ebp-24h] BYREF
  int v14; // [esp+4h] [ebp-20h]
  int v15; // [esp+8h] [ebp-1Ch]

  v0 = 1;
  v1 = 18;
  v2 = 1;
  v3 = getbuffer(0x400u);
  v4 = 0;
  v5 = v3;
  v13 = v3;
  v14 = 18;
  do {
    v6 = RecordLaps[v2] * func2_c_variable_328;
    _CHP(v3, v5);
    v15 = (int)v6;
    v7 = copy_int(v5, (int)v6, v1);
    v15 = RecordCars[v2];
    v8 = copy_int(v7, v15, v1);
    v1 = v14;
    v15 = RecordKills[v2];
    v9 = v4 + 12;
    v5 = copy_int(v8, v15, v14);
    v3 = 9 * v0;
    do {
      ++v5;
      v10 = RecordNames[v3++];
      *(_BYTE *)(v5 - 1) = v10;
    } while (v3 != v1);
    v4 = v9 + 9;
    ++v2;
    ++v0;
    v14 += 9;
  } while (v0 < 25);
  v11 = fopen(aDgkfcRec, &func2_c_variable_327);
  if (!v11)
    v11 = fopen(aDgkfcRec, &aMwb[1]);
  fwrite(v13, 1, v4, v11);
  fclose(v11);
  return fre(&v13);
}

//-------------------------------------------------------------------------------------------------

int __fastcall copy_int(int a1, int a2)
{
  int v2; // eax
  int result; // eax

  v2 = a1 + 3;
  *(_WORD *)(v2 - 3) = a2;
  result = v2 + 1;
  *(_BYTE *)(result - 2) = BYTE2(a2);
  *(_BYTE *)(result - 1) = HIBYTE(a2);
  return result;
}

//-------------------------------------------------------------------------------------------------

int __fastcall ShowATime(int a1, int a2, float a3, int a4, int a5)
{
  double v7; // st7
  int v9; // [esp+0h] [ebp-1Ch]

  v7 = a3 * func2_c_variable_330;
  _CHP(a1, a2);
  v9 = (int)v7;
  if ((int)v7 > 599999)
    v9 = 599999;
  buffer_variable_1 = 0;
  if (v9 >= 0) {
    buffer = v9 % 10 + 48;
    v9 /= 10;
  } else {
    buffer = 45;
  }
  prt_string(rev_vga_variable_1, &buffer);
  if (v9 >= 0) {
    buffer = v9 % 10 + 48;
    v9 /= 10;
  } else {
    buffer = 45;
  }
  prt_string(rev_vga_variable_1, &buffer);
  prt_string(rev_vga_variable_1, func2_c_variable_329);
  if (v9 >= 0) {
    buffer = v9 % 10 + 48;
    v9 /= 10;
  } else {
    buffer = 45;
  }
  prt_string(rev_vga_variable_1, &buffer);
  if (v9 >= 0) {
    buffer = v9 % 6 + 48;
    v9 /= 6;
  } else {
    buffer = 45;
  }
  prt_string(rev_vga_variable_1, &buffer);
  prt_string(rev_vga_variable_1, func2_c_variable_329);
  if (v9 >= 0) {
    buffer = v9 % 10 + 48;
    v9 /= 10;
  } else {
    buffer = 45;
  }
  prt_string(rev_vga_variable_1, &buffer);
  if (v9 >= 0)
    buffer = v9 % 10 + 48;
  else
    buffer = 45;
  return prt_string(rev_vga_variable_1, &buffer);
}

//-------------------------------------------------------------------------------------------------

int setmodex()
{
  __asm { int     10h; -VIDEO - SET VIDEO MODE }
  modexsethardware(19, 964);
  __outword(0x3C4u, 0xF02u);
  return memset(screen, 0, cstart_branch_1);
}

//-------------------------------------------------------------------------------------------------

unsigned __int8 modexsethardware()
{
  unsigned __int8 v0; // al
  unsigned __int8 v1; // al
  unsigned __int8 v2; // al
  unsigned __int8 v3; // al
  unsigned __int8 v4; // al
  unsigned __int8 v5; // al
  unsigned __int8 result; // al

  __outbyte(0x3C4u, 4u);
  v0 = __inbyte(0x3C5u);
  __outbyte(0x3C5u, v0 & 3 | 4);
  __outbyte(0x3CEu, 5u);
  v1 = __inbyte(0x3CFu);
  __outbyte(0x3CFu, v1 & 0xEF);
  __outbyte(0x3CEu, 6u);
  v2 = __inbyte(0x3CFu);
  __outbyte(0x3CFu, v2 & 0xFD);
  __outbyte(0x3D4u, 9u);
  v3 = __inbyte(0x3D5u);
  __outbyte(0x3D5u, v3 & 0xE0);
  __outbyte(0x3D4u, 0x14u);
  v4 = __inbyte(0x3D5u);
  __outbyte(0x3D5u, v4 & 0xBF);
  __outbyte(0x3D4u, 0x17u);
  v5 = __inbyte(0x3D5u);
  result = v5 | 0x40;
  __outbyte(0x3D5u, result);
  return result;
}

//-------------------------------------------------------------------------------------------------

int modexclearscreen()
{
  __outword(0x3C4u, 0xF02u);
  return memset(screen, 0, cstart_branch_1);
}

//-------------------------------------------------------------------------------------------------

char *__fastcall copyscreenmodex(int a1, int a2)
{
  int v3; // esi
  int v4; // edi
  int v5; // ebx
  char *result; // eax
  int v7; // edx
  int v8; // edx
  char v9; // cl
  char *v10; // eax
  char v11; // cl
  char v12; // cl
  char v13; // cl
  char v14; // cl

  v3 = 0;
  v4 = 0;
  do {
    __outbyte(0x3C4u, 2u);
    v5 = 0;
    __outbyte(0x3C5u, 1 << (v3 & 3));
    result = (char *)(v4 + a1);
    v7 = a2 + (v3 >> 2);
    do {
      v8 = v7 + 80;
      v9 = *result;
      v10 = result + 640;
      v5 += 5;
      *(_BYTE *)(v8 - 80) = v9;
      v8 += 80;
      v11 = *v10;
      v10 += 640;
      *(_BYTE *)(v8 - 80) = v11;
      v8 += 80;
      v12 = *v10;
      v10 += 640;
      *(_BYTE *)(v8 - 80) = v12;
      v8 += 80;
      v13 = *v10;
      v10 += 640;
      *(_BYTE *)(v8 - 80) = v13;
      v7 = v8 + 80;
      v14 = *v10;
      result = v10 + 640;
      *(_BYTE *)(v7 - 80) = v14;
    } while (v5 < 400);
    ++v3;
    v4 += 2;
  } while (v3 < 320);
  return result;
}

//-------------------------------------------------------------------------------------------------

char __fastcall start_zoom(char *a1, int a2)
{
  int v4; // edx
  int v5; // ebp
  _BYTE *v6; // edi
  char result; // al

  v4 = a2;
  v5 = game_count[v4];
  sub_on[v4] = 0;
  zoom_size[v4] = -1;
  new_zoom[v4] = -1;
  v6 = &zoom_mes[24 * a2];
  if (v5 == -2) {
    do {
      result = *a1;
      *v6 = *a1;
      if (!result)
        break;
      result = a1[1];
      a1 += 2;
      v6[1] = result;
      v6 += 2;
    } while (result);
    game_count[v4] = 0;
    game_scale[v4] = 1191182336;
  } else {
    do {
      result = *a1;
      *v6 = *a1;
      if (!result)
        break;
      result = a1[1];
      a1 += 2;
      v6[1] = result;
      v6 += 2;
    } while (result);
    if (game_count[v4] == -1) {
      game_count[v4] = 0;
    } else if (game_scale[v4] == 1115684864) {
      game_count[v4] = 72;
    }
  }
  return result;
}

//-------------------------------------------------------------------------------------------------

char __fastcall small_zoom(_BYTE *a1)
{
  _BYTE *v1; // esi
  _BYTE *v2; // edi
  _BYTE *v3; // edi

  v1 = a1;
  new_zoom[0] = 0;
  if (game_count[0] == -2) {
    v2 = zoom_mes;
    sub_on[0] = 0;
    zoom_size[0] = 0;
    new_zoom[0] = -1;
    do {
      LOBYTE(a1) = *v1;
      *v2 = *v1;
      if (!(_BYTE)a1)
        break;
      LOBYTE(a1) = v1[1];
      v1 += 2;
      v2[1] = (_BYTE)a1;
      v2 += 2;
    } while ((_BYTE)a1);
    game_count[0] = 0;
    game_scale[0] = 1191182336;
  } else if (!zoom_size[0]) {
    v3 = zoom_mes;
    sub_on[0] = 0;
    zoom_size[0] = 0;
    new_zoom[0] = -1;
    do {
      LOBYTE(a1) = *v1;
      *v3 = *v1;
      if (!(_BYTE)a1)
        break;
      LOBYTE(a1) = v1[1];
      v1 += 2;
      v3[1] = (_BYTE)a1;
      v3 += 2;
    } while ((_BYTE)a1);
    if (game_count[0] == -1) {
      game_count[0] = 0;
    } else if (game_scale[0] == 1115684864) {
      game_count[0] = 72;
    }
  }
  return (char)a1;
}

//-------------------------------------------------------------------------------------------------

char __fastcall subzoom(_BYTE *a1)
{
  _BYTE *v1; // edi
  _BYTE *v2; // esi

  if (new_zoom[0]) {
    v1 = &zoom_sub;
    v2 = a1;
    sub_on[0] = -1;
    do {
      LOBYTE(a1) = *v2;
      *v1 = *v2;
      if (!(_BYTE)a1)
        break;
      LOBYTE(a1) = v2[1];
      v2 += 2;
      v1[1] = (_BYTE)a1;
      v1 += 2;
    } while ((_BYTE)a1);
  }
  return (char)a1;
}

//-------------------------------------------------------------------------------------------------

void __fastcall make_time(_BYTE *a1, int a2, float a3)
{
  double v6; // st7
  int v7; // [esp+0h] [ebp-14h]

  v6 = a3 * func2_c_variable_331;
  _CHP(a1, a2);
  v7 = (int)v6;
  if ((int)v6 > 599999)
    v7 = 599999;
  a1[8] = 0;
  if (v7 >= 0) {
    a1[7] = v7 % 10 + 48;
    a1[6] = v7 / 10 % 10 + 48;
    a1[4] = v7 / 10 / 10 % 10 + 48;
    a1[3] = v7 / 10 / 10 / 10 % 6 + 48;
    a1[1] = v7 / 10 / 10 / 10 / 6 % 10 + 48;
    a1[5] = 58;
    a1[2] = 58;
    *a1 = v7 / 10 / 10 / 10 / 6 / 10 % 10 + 48;
  } else {
    *a1 = 45;
    a1[1] = 45;
    a1[2] = 58;
    a1[3] = 45;
    a1[4] = 45;
    a1[5] = 58;
    a1[6] = 45;
    a1[7] = 45;
  }
}

//-------------------------------------------------------------------------------------------------

int check_machine_speed()
{
  int v0; // edx
  int result; // eax

  v0 = 0;
  while (frames + 4 != frames)
    ;
  while (frames + 13 != frames)
    ++v0;
  result = v0 / 1000;
  machine_speed = v0 / 1000;
  return result;
}

//-------------------------------------------------------------------------------------------------

void __fastcall load_language_file(int a1, int a2)
{
  int v4; // esi
  _BYTE *v5; // edi
  char *v6; // esi
  char v7; // al
  char v8; // al
  int v9; // esi
  int v10; // edi
  int v11; // ecx
  char *v12; // eax
  char *v13; // edx
  char *i; // edx
  char v15; // bl

  v4 = language;
  v5 = (_BYTE *)(strstr() + 1);
  v6 = (char *)&TextExt + 4 * v4;
  do {
    v7 = *v6;
    *v5 = *v6;
    if (!v7)
      break;
    v8 = v6[1];
    v6 += 2;
    v5[1] = v8;
    v5 += 2;
  } while (v8);
  v9 = fopen(a1, aR_0);
  if (v9) {
    v10 = 0;
    v11 = 0;
    do {
      fgets(&buffer, 512, v9, v11);
      if (buffer == 69 && buffer_variable_1 == 78 && buffer_variable_2 == 68) {
        v10 = -1;
      } else {
        v12 = &buffer_variable_1;
        if (a2 == 1)
          v13 = config_buffer;
        else
          v13 = (char *)&language_buffer;
        for (i = &v13[v11]; ; *(i - 1) = v15) {
          v15 = *v12;
          if (*v12 == 34)
            break;
          ++i;
          ++v12;
        }
        v11 += 64;
        *i = 0;
      }
    } while (!v10);
    fclose(v9);
  } else {
    printf(&aMpunableToOpen[2]);
    doexit();
  }
}

//-------------------------------------------------------------------------------------------------

int __fastcall do_blip(int a1)
{
  int v2; // eax
  double v3; // st7
  int v4; // eax
  int result; // eax
  int v6; // [esp+0h] [ebp-10h]

  v2 = 77 * ViewType[a1];
  v3 = (func2_c_variable_335 - Car_variable_9[v2]) * func2_c_variable_336 * func2_c_variable_337;
  _CHP(v2 * 4, a1);
  v6 = (int)v3;
  if ((*(_DWORD *)((_BYTE *)Car_variable_9 + v4) & 0x7FFFFFFF) == 0)
    v6 = 14;
  result = 308 * ViewType[a1];
  if ((*(_DWORD *)((_BYTE *)Car_variable_8 + result) & 0x7FFFFFFF) != 0) {
    result = v6;
    lastblip[a1] = v6;
  }
  if (v6 < 14 && v6 < lastblip[a1]) {
    result = 308 * ViewType[a1];
    if (Car_variable_40[result]) {
      result = sfxsample(83, 0x8000, 4 * a1);
      lastblip[a1] = v6;
    }
  }
  return result;
}

//-------------------------------------------------------------------------------------------------