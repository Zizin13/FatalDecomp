
//-------------------------------------------------------------------------------------------------

int __fastcall winner_screen(int a1, char a2, _WORD *a3)
{
  _BYTE *v4; // ecx
  __int64 picture; // rax
  int v6; // ebp
  int v7; // eax
  int v8; // eax
  int v9; // esi
  int v10; // edx
  int v11; // ecx
  int v12; // edi
  int v13; // esi
  unsigned int v14; // ecx
  char v15; // al
  unsigned int v16; // ecx
  _UNKNOWN **v17; // edx
  int v18; // ebx
  __int16 v19; // ax
  int *v20; // edx
  int *v21; // eax
  char *v22; // edx
  _DWORD *v23; // eax
  int v25; // [esp+0h] [ebp-28h]
  int v26; // [esp+4h] [ebp-24h]
  int v27; // [esp+8h] [ebp-20h]
  int v28; // [esp+Ch] [ebp-1Ch]

  tick_on = -1;
  frontend_on = -1;
  v25 = -1;
  SVGA_ON = -1;
  v26 = gfx_size;
  front_fade = 0;
  init_screen(gfx_size, -1, (int)a3);
  v4 = (_BYTE *)MusicVolume;
  winx = 0;
  winy = 0;
  winw = XMAX;
  mirror = 0;
  winh = YMAX;
  if (MusicVolume && MusicCard)
    v28 = 720;
  else
    v28 = 180;
  front_vga[0] = load_picture(aWinnerBm);
  picture = load_picture(&aXfont3Bm[2]);
  front_vga_variable_1 = picture;
  v6 = 0;
  setpal((int)&aIntwinnerPal[3], SHIDWORD(picture), a3, v4);
  FindShades();
  frames = 0;
  Car[0] = 0.0;
  Car_variable_1[0] = 0.0;
  Car_variable_2[0] = 0.0;
  gfx_size = 0;
  Car_variable_7[0] = 0;
  Car_variable_5[0] = 0;
  Car_variable_6[0] = 0;
  set_starts(0);
  v7 = 2;
  car_texs_loaded[0] = 0;
  car_texs_loaded_variable_1 = -1;
  do {
    v7 += 7;
    SmokePt_variable_16[v7] = -1;
    SmokePt_variable_17[v7] = -1;
    SmokePt_variable_18[v7] = -1;
    SmokePt_variable_19[v7] = -1;
    SmokePt_variable_20[v7] = -1;
    SmokePt_variable_21[v7] = -1;
    SmokePt_variable_22[v7] = -1;
  } while (v7 != 16);
  v8 = CarDesigns_variable_5[7 * a1];
  v9 = v8;
  v10 = 1;
  v11 = car_texs_loaded[v8];
  if (v11 == -1) {
    LoadCarTexture(v8, 1, (char *)(4 * a1));
    v10 = 2;
    car_texmap[a1] = 1;
    car_texs_loaded[v9] = 1;
  } else {
    car_texmap[a1] = v11;
  }
  LoadCarTextures = v10;
  NoOfTextures = 255;
  if (SVGA_ON)
    scr_size = 128;
  else
    scr_size = 64;
  ticks = 0;
  frames = 0;
  startmusic(winsong);
  v27 = a2 & 1;
  do {
    v12 = scrbuf;
    v13 = front_vga[0];
    if (SVGA_ON)
      v14 = 256000;
    else
      v14 = 64000;
    v15 = v14;
    v16 = v14 >> 2;
    qmemcpy((void *)scrbuf, (const void *)front_vga[0], 4 * v16);
    qmemcpy((void *)(v12 + 4 * v16), (const void *)(v13 + 4 * v16), v15 & 3);
    DrawCar(2200.0, 512, v27);
    front_text(320, 120, 143, 1);
    v17 = screen;
    copypic((char *)scrbuf, (int)screen);
    v18 = front_fade;
    if (!front_fade) {
      front_fade = -1;
      fade_palette(32, (int)v17, 0, -1);
      frames = 0;
    }
    while (fatkbhit()) {
      if (!(unsigned __int8)fatgetch())
        fatgetch();
      v6 = -1;
      v25 = 0;
    }
    if (ticks > v28)
      v6 = -1;
    v19 = Car_variable_7[0] + 32 * frames;
    HIBYTE(v19) &= 0x3Fu;
    Car_variable_7[0] = v19;
    frames = 0;
  } while (!v6);
  v20 = front_vga;
  do {
    v21 = v20++;
    fre(v21);
  } while (v20 != &front_vga[16]);
  v22 = (char *)&cartex_vga;
  do {
    v23 = v22;
    v22 += 4;
    fre(v23);
  } while (v22 != (char *)&cartex_vga + 64);
  remove_mapsels();
  gfx_size = v26;
  if (!v25) {
    fade_palette(0, (int)v22, v18, 0);
    front_fade = 0;
  }
  return v25;
}

//-------------------------------------------------------------------------------------------------

int StoreResult()
{
  int v0; // edi
  int v1; // ebx
  unsigned int v2; // eax
  int v3; // ebp
  int v4; // esi
  unsigned int v5; // ebx
  int v6; // edx
  double v7; // st7
  unsigned __int8 v8; // al
  int result; // eax
  int v10; // esi
  int i; // edx
  int v12; // edx

  v0 = result_p2_pos;
  if (numcars > 0) {
    v1 = 4 * numcars;
    v2 = 0;
    do {
      v2 += 4;
      result_lap_variable_1[v2 / 4] = nearcall_variable_4[v2 / 4];
      result_competing_variable_1[v2 / 4] = team_wins_variable_1[v2 / 4];
      result_best_variable_1[v2 / 4] = TrackArrow_variable_1[v2 / 4];
    } while ((int)v2 < v1);
  }
  v3 = -1;
  BestTime = 100000000.0;
  if (racers > 0) {
    v4 = 4 * racers;
    v5 = 0;
    do {
      v6 = result_order[v5 / 4];
      if ((Car_variable_53[77 * v6] & 0x7FFFFFFF) != 0 && *(float *)&Car_variable_53[77 * v6] < (double)BestTime) {
        v3 = result_order[v5 / 4];
        BestTime = *(float *)&Car_variable_53[77 * v6];
      }
      result_best[v6] = Car_variable_53[77 * v6];
      v7 = *(float *)&Car_variable_55[77 * v6];
      result_kills[v6] = (unsigned __int8)Car_variable_42[308 * v6];
      LODWORD(result_lap[v6]) = Car_variable_31[308 * v6];
      result_lives[v6] = Car_variable_23[308 * v6];
      v8 = Car_variable_22[308 * v6];
      result_time[v6] = v7;
      v5 += 4;
      result_design[v6] = v8;
    } while ((int)v5 < v4);
  }
  result = carorder[0];
  v10 = 0;
  for (i = 0; result != result_p1; ++v10)
    result = carorder_variable_1[i++];
  if (player_type == 2) {
    v0 = 0;
    result = 0;
    if (carorder[0] != result_p2) {
      do {
        v12 = *(int *)((char *)carorder_variable_1 + result);
        result += 4;
        ++v0;
      } while (v12 != result_p2);
    }
  }
  FastestLap = v3;
  result_p2_pos = v0;
  result_p1_pos = v10;
  return result;
}

//-------------------------------------------------------------------------------------------------

void __fastcall RaceResult(int a1, int a2, int a3, _BYTE *a4)
{
  int v4; // edi
  int v5; // esi
  unsigned int v6; // ecx
  char v7; // al
  unsigned int v8; // ecx
  int v9; // ecx
  int v10; // ebx
  unsigned int v11; // eax
  int v12; // esi
  int i; // edi
  float v14; // eax
  double v15; // st7
  double v16; // st7
  int v17; // eax
  _UNKNOWN **v18; // edx
  int v19; // [esp+0h] [ebp-4Ch]
  int v20; // [esp+4h] [ebp-48h]
  float v21; // [esp+8h] [ebp-44h]
  const char *v22; // [esp+Ch] [ebp-40h]
  int v23; // [esp+10h] [ebp-3Ch]
  int v24; // [esp+14h] [ebp-38h]
  int v25; // [esp+1Ch] [ebp-30h]
  int v26; // [esp+20h] [ebp-2Ch]
  int v27; // [esp+24h] [ebp-28h]
  int v28; // [esp+28h] [ebp-24h]
  int v29; // [esp+2Ch] [ebp-20h]
  int v30; // [esp+2Ch] [ebp-20h]

  tick_on = 0;
  v20 = scr_size;
  SVGA_ON = -1;
  init_screen(scr_size, 0, -1);
  setpal((int)&aEresultPal[1], 0, (_WORD *)0xFFFFFFFF, a4);
  winx = 0;
  winw = XMAX;
  winy = 0;
  winh = YMAX;
  mirror = 0;
  front_vga_variable_2 = load_picture(&aIresultBm[1]);
  front_vga_variable_3 = load_picture(&aAcfont2Bm[2]);
  front_vga[0] = load_picture(&aSelsmallcarBm[3]);
  front_vga_variable_1 = load_picture(aTabtextBm_0);
  frontend_on = -1;
  tick_on = -1;
  v4 = scrbuf;
  v5 = front_vga_variable_2;
  if (SVGA_ON)
    v6 = 256000;
  else
    v6 = 64000;
  v7 = v6;
  v8 = v6 >> 2;
  qmemcpy((void *)scrbuf, (const void *)front_vga_variable_2, 4 * v8);
  qmemcpy((void *)(v4 + 4 * v8), (const void *)(v5 + 4 * v8), v7 & 3);
  v28 = 49;
  display_block(3, -1);
  v9 = numcars;
  if (numcars > 0) {
    v10 = 4 * numcars;
    v11 = 0;
    do {
      v11 += 4;
      TrackArrow_variable_1[v11 / 4] = result_best_variable_1[v11 / 4];
    } while ((int)v11 < v10);
  }
  v19 = 0;
  if (racers > 0) {
    v23 = 44;
    v24 = 45;
    v26 = 0;
    v22 = a1st;
    v25 = 46;
    do {
      v27 = result_order[v26];
      if (result_control[v27])
        display_block(v23, 0);
      sprintf(&buffer, "%s", v22);
      front_text(33, v28, 143, 0);
      sprintf(&buffer, "%s", &driver_names[9 * v27]);
      front_text(85, v28, 143, 0);
      sprintf(&buffer, "%s", &CompanyNames[20 * result_design[v27]]);
      front_text(218, v28, 143, 0);
      if (result_design[v27] >= 8)
        front_text(165, v28, 143, 0);
      else
        display_block(v25, 0);
      if (result_kills[v27] > 3) {
        display_block(v24, 0);
        sprintf(&buffer, "%i", result_kills[v27]);
        front_text(376, v28, 143, 0);
      } else {
        v12 = 356;
        for (i = 0; i < result_kills[v27]; v12 += 18) {
          ++i;
          display_block(v24, 0);
        }
      }
      if (v27 == FastestLap && FastestLap >= 0)
        display_block(v25, 0);
      if (result_lives[v27] > 0) {
        v14 = result_lap[v27];
        if (SLODWORD(v14) > NoOfLaps) {
          if (v19) {
            v15 = result_time[v27] - v21;
          } else {
            v14 = result_time[v27];
            v21 = v14;
            v15 = v14;
          }
          v16 = v15 * func3_c_variable_16;
          _CHP(LODWORD(v14), 4 * v27);
          v29 = (int)v16;
          if ((int)v16 > 599999)
            v29 = 599999;
          buffer_variable_1[0] = v29 % 10 + 48;
          v30 = v29 / 10;
          buffer = v30 % 10 + 48;
          buffer_variable_2 = 0;
          front_text(492, v28, 143, 0);
          front_text(467, v28, 143, 0);
          v30 /= 10;
          buffer_variable_1[0] = v30 % 10 + 48;
          v30 /= 10;
          buffer = v30 % 6 + 48;
          buffer_variable_2 = 0;
          front_text(471, v28, 143, 0);
          front_text(488, v28, 143, 0);
          v30 /= 6;
          buffer_variable_1[0] = v30 % 10 + 48;
          buffer = v30 / 10 % 10 + 48;
          buffer_variable_2 = 0;
          front_text(450, v28, 143, 0);
          goto LABEL_34;
        }
        if (LODWORD(v14) == NoOfLaps)
          sprintf(&buffer, "1 %s", language_buffer_variable_4);
        else
          sprintf(&buffer, "%i %s", NoOfLaps - LODWORD(result_lap[v27]) + 1, language_buffer_variable_5);
      }
      front_text(450, v28, 143, 0);
    LABEL_34:
      if (v27 == FastestLap)
        v17 = result_kills[v27] + points[v26] + 1;
      else
        v17 = result_kills[v27] + points[v26];
      sprintf(&buffer, "%2i", v17);
      v22 += 5;
      ++v26;
      front_text(560, v28, 143, 0);
      v9 = v28 + 22;
      v28 += 22;
      v23 += 22;
      v24 += 22;
      v25 += 22;
      ++v19;
    } while (v19 < racers);
  }
  v18 = screen;
  copypic((char *)scrbuf, (int)screen);
  fade_palette(32, (int)v18, 0, v9);
  ticks = 0;
  while (!fatkbhit() && ticks < 2160)
    ;
  fre(front_vga);
  fre(&front_vga_variable_1);
  fre(&front_vga_variable_2);
  fre(&front_vga_variable_3);
  scr_size = v20;
  holdmusic = -1;
  fade_palette(0, (int)v18, 0, v9);
}

//-------------------------------------------------------------------------------------------------

void __fastcall TimeTrials(int a1, int a2, int a3, _BYTE *a4)
{
  int v5; // edi
  int v6; // esi
  unsigned int v7; // ecx
  char v8; // al
  unsigned int v9; // ecx
  int v10; // edi
  int v11; // ebp
  __int64 v12; // rax
  double v13; // st7
  int v14; // esi
  int v15; // ebp
  int v16; // edi
  __int16 v17; // fps
  double v18; // st7
  _BOOL1 v19; // c0
  char v20; // c2
  _BOOL1 v21; // c3
  __int64 v22; // rax
  double v23; // st7
  int v24; // esi
  int v25; // edi
  __int64 v26; // rax
  double v27; // st7
  int v28; // edi
  int v29; // esi
  int v30; // edi
  __int64 v31; // rax
  double v32; // st7
  _UNKNOWN **v33; // edx
  int v34; // [esp-Ch] [ebp-40h]
  int v35; // [esp+0h] [ebp-34h]
  int v36; // [esp+4h] [ebp-30h]
  int v37; // [esp+4h] [ebp-30h]
  int v38; // [esp+8h] [ebp-2Ch]
  int v39; // [esp+8h] [ebp-2Ch]
  int v40; // [esp+Ch] [ebp-28h]
  int v41; // [esp+Ch] [ebp-28h]
  int v42; // [esp+10h] [ebp-24h]
  int v43; // [esp+14h] [ebp-20h]
  int v44; // [esp+18h] [ebp-1Ch]
  int v45; // [esp+18h] [ebp-1Ch]

  tick_on = 0;
  v35 = scr_size;
  SVGA_ON = -1;
  init_screen(scr_size, 0, -1);
  setpal((int)&aEresultPal[1], 0, (_WORD *)0xFFFFFFFF, a4);
  winx = 0;
  winw = XMAX;
  winy = 0;
  winh = YMAX;
  mirror = 0;
  front_vga_variable_3 = load_picture(&aIresultBm[1]);
  front_vga_variable_2 = load_picture(&aAcfont2Bm[2]);
  front_vga[0] = load_picture(&aSelsmallcarBm[3]);
  front_vga_variable_1 = load_picture(aTabtextBm_0);
  frontend_on = -1;
  tick_on = -1;
  v5 = scrbuf;
  v6 = front_vga_variable_3;
  if (SVGA_ON)
    v7 = 256000;
  else
    v7 = 64000;
  v8 = v7;
  v9 = v7 >> 2;
  qmemcpy((void *)scrbuf, (const void *)front_vga_variable_3, 4 * v9);
  qmemcpy((void *)(v5 + 4 * v9), (const void *)(v6 + 4 * v9), v8 & 3);
  display_block(5, -1);
  sprintf(&buffer, "%s", &driver_names[9 * a1]);
  v10 = a1;
  v11 = a1;
  front_text(85, 49, 143, 0);
  sprintf(&buffer, "%s", &CompanyNames[20 * result_design[v11]]);
  front_text(218, 49, 143, 0);
  if (result_design[v11] >= 8)
    v12 = front_text(165, 49, 143, 0);
  else
    v12 = display_block(46, 0);
  v13 = *(float *)&Car_variable_53[77 * v10] * func3_c_variable_19;
  _CHP(308 * v10, HIDWORD(v12));
  v40 = (int)v13;
  if ((int)v13 > (int)&loc_186A0)
    v40 = 0;
  buffer_variable_1[0] = v40 % 10 + 48;
  v41 = v40 / 10;
  buffer = v41 % 10 + 48;
  buffer_variable_2 = 0;
  front_text(492, 49, 143, 0);
  front_text(467, 49, 143, 0);
  v41 /= 10;
  buffer_variable_1[0] = v41 % 10 + 48;
  v41 /= 10;
  buffer = v41 % 6 + 48;
  buffer_variable_2 = 0;
  front_text(471, 49, 143, 0);
  front_text(488, 49, 143, 0);
  v41 /= 6;
  buffer_variable_1[0] = v41 % 10 + 48;
  buffer = v41 / 10 % 10 + 48;
  buffer_variable_2 = 0;
  front_text(450, 49, 143, 0);
  v14 = 93;
  v15 = 1;
  v42 = 308 * v10;
  v43 = 90;
  v16 = 24 * v10 + 4;
  while (v15 < Car_variable_31[v42]) {
    sprintf(&buffer, "%s %i", language_buffer_variable_4, v15);
    v22 = front_text(220, v14, 143, 0);
    v18 = *(float *)((char *)trial_times + v16);
    WORD1(v22) = HIWORD(v42);
    v19 = v18 < *(float *)((char *)Car_variable_53 + v42);
    v20 = 0;
    v21 = v18 == *(float *)((char *)Car_variable_53 + v42);
    LOWORD(v22) = v17;
    if (v18 == *(float *)((char *)Car_variable_53 + v42))
      v22 = display_block(v43, 0);
    v23 = *(float *)((char *)trial_times + v16) * func3_c_variable_19;
    _CHP(v22, HIDWORD(v22));
    v44 = (int)v23;
    if ((int)v23 > (int)&loc_186A0)
      v44 = 0;
    buffer_variable_1[0] = v44 % 10 + 48;
    v45 = v44 / 10;
    buffer = v45 % 10 + 48;
    buffer_variable_2 = 0;
    front_text(492, v14, 143, 0);
    front_text(467, v14, 143, 0);
    v45 /= 10;
    buffer_variable_1[0] = v45 % 10 + 48;
    v45 /= 10;
    buffer = v45 % 6 + 48;
    buffer_variable_2 = 0;
    front_text(471, v14, 143, 0);
    front_text(488, v14, 143, 0);
    v45 /= 6;
    buffer_variable_1[0] = v45 % 10 + 48;
    buffer = v45 / 10 % 10 + 48;
    buffer_variable_2 = 0;
    v16 += 4;
    front_text(450, v14, 143, 0);
    ++v15;
    v14 += 22;
    v43 += 22;
  }
  v34 = v14 + 44;
  v24 = v14 + 66;
  front_text(218, v34, 143, 0);
  v25 = RecordCars[TrackLoad];
  if (v25 < 0) {
    sprintf(&buffer, "%s", &RecordNames[9 * TrackLoad]);
    front_text(165, v24, 143, 0);
    front_text(450, v24, 143, 0);
  } else {
    sprintf(&buffer, "%s", &RecordNames[9 * TrackLoad]);
    front_text(85, v24, 143, 0);
    sprintf(&buffer, "%s", &CompanyNames[20 * (v25 & 0xF)]);
    front_text(218, v24, 143, 0);
    if ((v25 & 0xFu) >= 8)
      v26 = front_text(165, v24, 143, 0);
    else
      v26 = display_block(v24 - 3, 0);
    v27 = RecordLaps[TrackLoad] * func3_c_variable_19;
    _CHP(TrackLoad, HIDWORD(v26));
    v36 = (int)v27;
    if ((int)v27 > (int)&loc_186A0)
      v36 = 0;
    buffer_variable_1[0] = v36 % 10 + 48;
    v37 = v36 / 10;
    buffer = v37 % 10 + 48;
    buffer_variable_2 = 0;
    front_text(492, v24, 143, 0);
    front_text(467, v24, 143, 0);
    v37 /= 10;
    buffer_variable_1[0] = v37 % 10 + 48;
    v37 /= 10;
    buffer = v37 % 6 + 48;
    buffer_variable_2 = 0;
    front_text(471, v24, 143, 0);
    front_text(488, v24, 143, 0);
    v37 /= 6;
    buffer_variable_1[0] = v37 % 10 + 48;
    buffer_variable_2 = 0;
    buffer = v37 / 10 % 10 + 48;
    front_text(450, v24, 143, 0);
  }
  front_text(218, v24 + 44, 143, 0);
  v28 = FastestLap;
  v29 = v24 + 66;
  if (FastestLap >= 0) {
    sprintf(&buffer, "%s", &driver_names[9 * FastestLap]);
    v30 = v28;
    front_text(85, v29, 143, 0);
    sprintf(&buffer, "%s", &CompanyNames[20 * result_design[v30]]);
    front_text(218, v29, 143, 0);
    if (result_design[v30] >= 8)
      v31 = front_text(165, v29, 143, 0);
    else
      v31 = display_block(v29 - 3, 0);
    v32 = BestTime * func3_c_variable_19;
    _CHP(v31, HIDWORD(v31));
    v38 = (int)v32;
    if ((int)v32 > (int)&loc_186A0)
      v38 = 0;
    buffer_variable_1[0] = v38 % 10 + 48;
    v39 = v38 / 10;
    buffer_variable_2 = 0;
    buffer = v39 % 10 + 48;
    front_text(492, v29, 143, 0);
    front_text(467, v29, 143, 0);
    v39 /= 10;
    buffer_variable_1[0] = v39 % 10 + 48;
    v39 /= 10;
    buffer = v39 % 6 + 48;
    buffer_variable_2 = 0;
    front_text(471, v29, 143, 0);
    front_text(488, v29, 143, 0);
    v39 /= 6;
    buffer_variable_1[0] = v39 % 10 + 48;
    buffer = v39 / 10 % 10 + 48;
    buffer_variable_2 = 0;
    front_text(450, v29, 143, 0);
  }
  v33 = screen;
  copypic((char *)scrbuf, (int)screen);
  startmusic(leaderboardsong);
  fade_palette(32, (int)v33, (int)&font2_ascii, (int)&font2_offsets);
  ticks = 0;
  while (!fatkbhit() && ticks < 2160)
    ;
  fre(front_vga);
  fre(&front_vga_variable_1);
  fre(&front_vga_variable_3);
  fre(&front_vga_variable_2);
  scr_size = v35;
  fade_palette(0, (int)v33, (int)&font2_ascii, (int)&font2_offsets);
}

//-------------------------------------------------------------------------------------------------

void __fastcall ChampionshipStandings(int a1, int a2, int a3, _BYTE *a4)
{
  int v4; // ebp
  int v5; // edi
  int v6; // esi
  unsigned int v7; // ecx
  char v8; // al
  unsigned int v9; // ecx
  int v10; // ebx
  int v11; // edx
  int v12; // esi
  int v13; // eax
  int v14; // ecx
  int v15; // edi
  int v16; // ecx
  int v17; // ecx
  int v18; // esi
  int v19; // edi
  int v20; // ecx
  int v21; // eax
  int v22; // edx
  int v23; // edx
  int v24; // eax
  int v25; // esi
  int v26; // ebx
  int v27; // edi
  _UNKNOWN **v28; // edx
  const char *v29; // [esp+4h] [ebp-34h]
  int v30; // [esp+8h] [ebp-30h]
  int v31; // [esp+Ch] [ebp-2Ch]
  int v32; // [esp+10h] [ebp-28h]
  int v33; // [esp+14h] [ebp-24h]
  int v34; // [esp+1Ch] [ebp-1Ch]

  tick_on = 0;
  v4 = scr_size;
  SVGA_ON = -1;
  init_screen(a1, 0, -1);
  setpal((int)&aEresultPal[1], 0, (_WORD *)0xFFFFFFFF, a4);
  winx = 0;
  winw = XMAX;
  winy = 0;
  winh = YMAX;
  mirror = 0;
  front_vga_variable_3 = load_picture(&aIresultBm[1]);
  front_vga_variable_2 = load_picture(&aAcfont2Bm[2]);
  front_vga[0] = load_picture(&aSelsmallcarBm[3]);
  front_vga_variable_1 = load_picture(aTabtextBm_0);
  frontend_on = -1;
  tick_on = -1;
  v5 = scrbuf;
  v6 = front_vga_variable_3;
  if (SVGA_ON)
    v7 = 256000;
  else
    v7 = 64000;
  v8 = v7;
  v9 = v7 >> 2;
  qmemcpy((void *)scrbuf, (const void *)front_vga_variable_3, 4 * v9);
  qmemcpy((void *)(v5 + 4 * v9), (const void *)(v6 + 4 * v9), v8 & 3);
  v10 = 0;
  if (racers > 0) {
    v11 = 0;
    do {
      v12 = result_order[v11];
      if (game_type != 3) {
        v13 = v12;
        v14 = result_kills[v12];
        championship_points[v13] = v14 + points[v11] + championship_points[v12];
        v15 = v14 + total_kills[v12];
        v16 = FastestLap;
        total_kills[v13] = v15;
        if (v12 == v16) {
          v17 = total_fasts[v12] + 1;
          ++championship_points[v12];
          total_fasts[v12] = v17;
        }
        if (!v10)
          ++total_wins[v12];
      }
      ++v10;
      champorder[v11++] = v12;
    } while (v10 < racers);
  }
  v18 = 0;
  if (racers > 0) {
    v19 = 0;
    do {
      v20 = v18;
      v21 = v18 + 1;
      v4 = championship_points[champorder[v19]];
      if (v18 + 1 < racers) {
        v22 = v21;
        do {
          if (championship_points[champorder[v22]] > v4) {
            v20 = v21;
            v4 = championship_points[champorder[v22]];
          }
          ++v21;
          ++v22;
        } while (v21 < racers);
      }
      ++v19;
      ++v18;
      v23 = teamorder_variable_1[v19];
      teamorder_variable_1[v19] = champorder[v20];
      v24 = racers;
      champorder[v20] = v23;
    } while (v18 < v24);
  }
  v25 = 49;
  display_block(4, -1);
  v26 = racers;
  v33 = 0;
  if (racers > 0) {
    v27 = 46;
    v30 = 0;
    v29 = a1st;
    v32 = 45;
    v31 = 44;
    do {
      v34 = champorder[v30];
      if (result_control[v34])
        display_block(v31, 0);
      sprintf(&buffer, "%s", v29);
      front_text(33, v25, 143, 0);
      sprintf(&buffer, "%s", &driver_names[9 * v34]);
      front_text(85, v25, 143, 0);
      sprintf(&buffer, "%s", &CompanyNames[20 * result_design[v34]]);
      front_text(218, v25, 143, 0);
      if (result_design[v34] >= 8)
        front_text(165, v25, 143, 0);
      else
        display_block(v27, 0);
      display_block(v32, 0);
      sprintf(&buffer, "%i", total_kills[v34]);
      front_text(376, v25, 143, 0);
      display_block(v27, 0);
      sprintf(&buffer, "%i", total_wins[v34]);
      front_text(500, v25, 143, 0);
      display_block(v27, 0);
      sprintf(&buffer, "%i", total_fasts[v34]);
      front_text(448, v25, 143, 0);
      sprintf(&buffer, "%3i", championship_points[v34]);
      v27 += 22;
      front_text(560, v25, 143, 0);
      v25 += 22;
      v31 += 22;
      v32 += 22;
      ++v30;
      v26 = v33 + 1;
      v29 += 5;
      ++v33;
    } while (v33 < racers);
  }
  v28 = screen;
  copypic((char *)scrbuf, (int)screen);
  holdmusic = -1;
  fade_palette(32, (int)v28, v26, -1);
  ticks = 0;
  if (game_type == 3) {
    while (!fatkbhit())
      ;
  } else {
    while (!fatkbhit() && ticks < 2160)
      ;
  }
  fre(front_vga);
  fre(&front_vga_variable_1);
  fre(&front_vga_variable_3);
  fre(&front_vga_variable_2);
  scr_size = v4;
  holdmusic = -1;
  fade_palette(0, (int)v28, v26, -1);
}

//-------------------------------------------------------------------------------------------------

void __fastcall TeamStandings(int a1, int a2, int a3, _BYTE *a4)
{
  int v4; // edi
  int v5; // esi
  unsigned int v6; // ecx
  char v7; // al
  unsigned int v8; // ecx
  int v9; // edx
  int v10; // ebx
  int v11; // ebp
  int v12; // esi
  int v13; // eax
  int v14; // ecx
  int v15; // ebp
  int v16; // eax
  int v17; // edx
  int v18; // edi
  int v19; // ebp
  int v20; // ecx
  int v21; // eax
  int v22; // esi
  int v23; // edx
  int v24; // edx
  int v25; // edi
  int v26; // ebp
  int v27; // edi
  int v28; // ecx
  int v29; // ebp
  int v30; // ebx
  _UNKNOWN **v31; // edx
  const char *v32; // [esp+8h] [ebp-28h]
  int v33; // [esp+Ch] [ebp-24h]

  tick_on = 0;
  SVGA_ON = -1;
  init_screen(a1, 0, -1);
  setpal((int)&aEresultPal[1], 0, (_WORD *)0xFFFFFFFF, a4);
  winx = 0;
  winw = XMAX;
  winy = 0;
  winh = YMAX;
  mirror = 0;
  front_vga_variable_3 = load_picture(&aIresultBm[1]);
  front_vga_variable_2 = load_picture(&aAcfont2Bm[2]);
  front_vga[0] = load_picture(&aSelsmallcarBm[3]);
  front_vga_variable_1 = load_picture(aTabtextBm_0);
  frontend_on = -1;
  tick_on = -1;
  v4 = scrbuf;
  v5 = front_vga_variable_3;
  if (SVGA_ON)
    v6 = 256000;
  else
    v6 = 64000;
  v7 = v6;
  v8 = v6 >> 2;
  qmemcpy((void *)scrbuf, (const void *)front_vga_variable_3, 4 * v8);
  qmemcpy((void *)(v4 + 4 * v8), (const void *)(v5 + 4 * v8), v7 & 3);
  if (game_type != 3) {
    v9 = 0;
    if (racers > 0) {
      v10 = 0;
      do {
        v11 = result_order[v10];
        v12 = result_design[v11];
        if (v12 < 8) {
          v13 = v12;
          team_points[v13] += result_kills[v11] + points[v10];
          v14 = FastestLap;
          team_kills[v13] = result_kills[v11] + team_kills[v12];
          if (v11 == v14) {
            v15 = team_fasts[v12] + 1;
            ++team_points[v12];
            team_fasts[v12] = v15;
          }
          if (!v9)
            ++team_wins[v12];
        }
        ++v9;
        ++v10;
      } while (v9 < racers);
    }
  }
  v16 = 0;
  v17 = 0;
  do
    teamorder[v17++] = v16++;
  while (v16 < 8);
  v18 = 0;
  v19 = 0;
  do {
    v20 = v18;
    v21 = v18 + 1;
    v22 = team_points[teamorder[v19]];
    if (v18 + 1 < 8) {
      v23 = v21;
      do {
        if (team_points[teamorder[v23]] > v22) {
          v20 = v21;
          v22 = team_points[teamorder[v23]];
        }
        ++v21;
        ++v23;
      } while (v21 < 8);
    }
    v24 = DeathView_variable_1[++v19];
    DeathView_variable_1[v19] = teamorder[v20];
    ++v18;
    teamorder[v20] = v24;
  } while (v18 < 8);
  v25 = 49;
  display_block(3, -1);
  v33 = 0;
  v32 = a1st;
  do {
    v26 = teamorder[v33];
    if (result_control_variable_1[2 * v26] || result_control[2 * v26])
      display_block(v25 - 5, 0);
    sprintf(&buffer, "%s", v32);
    front_text(33, v25, 143, 0);
    sprintf(&buffer, "%s", &CompanyNames[20 * v26]);
    front_text(190, v25, 143, 0);
    display_block(v25 - 3, 0);
    display_block(v25 - 3, 0);
    display_block(v25 - 3, 0);
    sprintf(&buffer, "%i", team_wins[v26]);
    front_text(500, v25, 143, 0);
    display_block(v25 - 3, 0);
    sprintf(&buffer, "%i", team_fasts[v26]);
    front_text(448, v25, 143, 0);
    sprintf(&buffer, "%3i", team_points[v26]);
    front_text(560, v25, 143, 0);
    display_block(v25 + 18, 0);
    sprintf(&buffer, "%i", team_kills[v26]);
    v27 = v25 + 22;
    front_text(448, v27, 143, 0);
    sprintf(&buffer, "%s", &driver_names[18 * v26]);
    front_text(110, v27, 143, 0);
    sprintf(&buffer, "%s", &driver_names[18 * v26 + 9]);
    v28 = (int)&font2_offsets;
    v29 = 2 * v26;
    front_text(310, v27, 143, 0);
    if (result_control_variable_1[v29] || result_control[v29]) {
      v28 = 13;
      display_block(v27 - 5, 0);
    }
    v25 = v27 + 22;
    v30 = (int)(v32 + 5);
    ++v33;
    v32 += 5;
  } while (v33 != 8);
  v31 = screen;
  copypic((char *)scrbuf, (int)screen);
  holdmusic = -1;
  fade_palette(32, (int)v31, v30, v28);
  ticks = 0;
  if (game_type == 3) {
    while (!fatkbhit())
      ;
  } else {
    while (!fatkbhit() && ticks < 2160)
      ;
  }
  fre(front_vga);
  fre(&front_vga_variable_1);
  fre(&front_vga_variable_3);
  fre(&front_vga_variable_2);
  scr_size = v22;
  holdmusic = -1;
  fade_palette(0, (int)v31, -1, v28);
}

void __fastcall ShowLapRecords(int a1, int a2, int a3, _BYTE *a4)
{
  unsigned __int64 picture; // kr00_8
  int v5; // edi
  int v6; // esi
  unsigned int v7; // ecx
  char v8; // al
  unsigned int v9; // ecx
  int v10; // esi
  int v11; // ebp
  int v12; // edi
  __int64 v13; // rax
  double v14; // st7
  int v15; // ebx
  _UNKNOWN **v16; // edx
  int v17; // edi
  int v18; // esi
  unsigned int v19; // ecx
  char v20; // al
  unsigned int v21; // ecx
  int v22; // esi
  int v23; // ebp
  int v24; // edi
  __int64 v25; // rax
  double v26; // st7
  int v27; // [esp+4h] [ebp-44h]
  int v28; // [esp+8h] [ebp-40h]
  int v29; // [esp+Ch] [ebp-3Ch]
  int v30; // [esp+10h] [ebp-38h]
  int v31; // [esp+14h] [ebp-34h]
  int v32; // [esp+18h] [ebp-30h]
  int v33; // [esp+1Ch] [ebp-2Ch]
  const char *v34; // [esp+20h] [ebp-28h]
  const char *v35; // [esp+24h] [ebp-24h]
  int v36; // [esp+28h] [ebp-20h]
  int v37; // [esp+28h] [ebp-20h]
  int v38; // [esp+2Ch] [ebp-1Ch]
  int v39; // [esp+2Ch] [ebp-1Ch]

  holdmusic = -1;
  tick_on = 0;
  SVGA_ON = -1;
  v28 = scr_size;
  init_screen(scr_size, -1, 0);
  setpal((int)&aEresultPal[1], -1, 0, a4);
  winx = 0;
  winw = XMAX;
  winy = 0;
  winh = YMAX;
  mirror = 0;
  front_vga_variable_2 = load_picture(&aIresultBm[1]);
  front_vga_variable_3 = load_picture(&aAcfont2Bm[2]);
  front_vga[0] = load_picture(&aSelsmallcarBm[3]);
  picture = load_picture(aTabtextBm_0);
  frontend_on = HIDWORD(picture);
  tick_on = HIDWORD(picture);
  front_vga_variable_1 = picture;
  v5 = scrbuf;
  v6 = front_vga_variable_2;
  if (SVGA_ON)
    v7 = 256000;
  else
    v7 = 64000;
  v8 = v7;
  v9 = v7 >> 2;
  qmemcpy((void *)scrbuf, (const void *)front_vga_variable_2, 4 * v9);
  qmemcpy((void *)(v5 + 4 * v9), (const void *)(v6 + 4 * v9), v8 & 3);
  v10 = 49;
  v11 = 1;
  display_block(2, -1);
  v12 = 1;
  v34 = &RecordNames[9];
  v27 = 46;
  v30 = 45;
  do {
    sprintf(&buffer, "%02i", v11);
    front_text(33, v10, 143, 0);
    v32 = RecordCars[v12];
    if (v32 < 0) {
      sprintf(&buffer, "%s", v34);
      front_text(165, v10, 143, 0);
      front_text(450, v10, 143, 0);
    } else {
      sprintf(&buffer, "%s", v34);
      front_text(85, v10, 143, 0);
      sprintf(&buffer, "%s", &CompanyNames[20 * (v32 & 0xF)]);
      front_text(218, v10, 143, 0);
      if ((v32 & 0xFu) >= 8)
        front_text(165, v10, 143, 0);
      else
        display_block(v27, 0);
      display_block(v30, 0);
      sprintf(&buffer, "%i", RecordKills[v12]);
      v13 = front_text(560, v10, 143, 0);
      v14 = RecordLaps[v12] * func3_c_variable_22;
      _CHP(v13, HIDWORD(v13));
      v38 = (int)v14;
      if ((int)v14 > 599999)
        v38 = 599999;
      buffer_variable_1[0] = v38 % 10 + 48;
      v39 = v38 / 10;
      buffer = v39 % 10 + 48;
      buffer_variable_2 = 0;
      front_text(492, v10, 143, 0);
      front_text(467, v10, 143, 0);
      v39 /= 10;
      buffer_variable_1[0] = v39 % 10 + 48;
      v39 /= 10;
      buffer = v39 % 6 + 48;
      buffer_variable_2 = 0;
      front_text(471, v10, 143, 0);
      front_text(488, v10, 143, 0);
      v39 /= 6;
      buffer_variable_1[0] = v39 % 10 + 48;
      buffer = v39 / 10 % 10 + 48;
      buffer_variable_2 = 0;
      front_text(450, v10, 143, 0);
    }
    v10 += 22;
    ++v12;
    ++v11;
    v15 = (int)(v34 + 9);
    v27 += 22;
    v30 += 22;
    v34 += 9;
  } while (v11 < 17);
  v16 = screen;
  copypic((char *)scrbuf, (int)screen);
  holdmusic = -1;
  fade_palette(32, (int)v16, v15, -1);
  ticks = 0;
  if (game_type == 4) {
    while (!fatkbhit())
      ;
  } else {
    while (!fatkbhit() && ticks < 720)
      ;
  }
  scr_size = v28;
  if ((textures_off & 0x20000) != 0) {
    holdmusic = -1;
    fade_palette(0, -1, v15, -1);
    v17 = scrbuf;
    v18 = front_vga_variable_2;
    if (SVGA_ON)
      v19 = 256000;
    else
      v19 = 64000;
    v20 = v19;
    v21 = v19 >> 2;
    qmemcpy((void *)scrbuf, (const void *)front_vga_variable_2, 4 * v21);
    qmemcpy((void *)(v17 + 4 * v21), (const void *)(v18 + 4 * v21), v20 & 3);
    v22 = 49;
    v23 = 17;
    display_block(2, -1);
    v24 = 17;
    v35 = &RecordNames[153];
    v31 = 46;
    v29 = 45;
    do {
      sprintf(&buffer, "%02i", v23);
      front_text(33, v22, 143, 0);
      v33 = RecordCars[v24];
      if (v33 < 0) {
        sprintf(&buffer, "%s", v35);
        front_text(165, v22, 143, 0);
        front_text(450, v22, 143, 0);
      } else {
        sprintf(&buffer, "%s", v35);
        front_text(85, v22, 143, 0);
        sprintf(&buffer, "%s", &CompanyNames[20 * (v33 & 0xF)]);
        front_text(218, v22, 143, 0);
        if ((v33 & 0xFu) >= 8)
          front_text(165, v22, 143, 0);
        else
          display_block(v31, 0);
        display_block(v29, 0);
        sprintf(&buffer, "%i", RecordKills[v24]);
        v25 = front_text(560, v22, 143, 0);
        v26 = RecordLaps[v24] * func3_c_variable_22;
        _CHP(v25, HIDWORD(v25));
        v36 = (int)v26;
        if ((int)v26 > 599999)
          v36 = 599999;
        buffer_variable_1[0] = v36 % 10 + 48;
        v37 = v36 / 10;
        buffer = v37 % 10 + 48;
        buffer_variable_2 = 0;
        front_text(492, v22, 143, 0);
        front_text(467, v22, 143, 0);
        v37 /= 10;
        buffer_variable_1[0] = v37 % 10 + 48;
        v37 /= 10;
        buffer = v37 % 6 + 48;
        buffer_variable_2 = 0;
        front_text(471, v22, 143, 0);
        front_text(488, v22, 143, 0);
        v37 /= 6;
        buffer_variable_1[0] = v37 % 10 + 48;
        buffer_variable_2 = 0;
        buffer = v37 / 10 % 10 + 48;
        front_text(450, v22, 143, 0);
      }
      v22 += 22;
      ++v24;
      ++v23;
      v15 = (int)(v35 + 9);
      v31 += 22;
      v29 += 22;
      v35 += 9;
    } while (v23 < 25);
    v16 = screen;
    copypic((char *)scrbuf, (int)screen);
    holdmusic = -1;
    fade_palette(32, (int)v16, v15, -1);
    ticks = 0;
    if (game_type == 4) {
      while (!fatkbhit())
        ;
    } else {
      while (!fatkbhit() && ticks < 720)
        ;
    }
    scr_size = v28;
  }
  fre(front_vga);
  fre(&front_vga_variable_1);
  fre(&front_vga_variable_2);
  fre(&front_vga_variable_3);
  holdmusic = (game_type != 4) - 1;
  fade_palette(0, (int)v16, v15, -1);
  if (game_type != 4)
    holdmusic = 0;
}

//-------------------------------------------------------------------------------------------------

void __stdcall show_3dmap(float a1, int a2, int a3)
{
  int v3; // edx
  double v4; // st7
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st5
  double v11; // st4
  double v12; // st2
  double v13; // st6
  double v14; // rt2
  double v15; // st5
  double v16; // st7
  __int16 v17; // fps
  _BOOL1 v18; // c0
  char v19; // c2
  _BOOL1 v20; // c3
  int v21; // eax
  double v22; // st7
  double v23; // st6
  double v24; // st5
  double v25; // st7
  int v26; // eax
  double v27; // st6
  double v28; // st5
  double v29; // st3
  double v30; // st7
  double v31; // rtt
  double v32; // st5
  double v33; // st4
  int v34; // edi
  double v35; // st3
  float v36; // eax
  double v37; // st4
  float v38; // eax
  double v39; // st7
  __int16 v40; // fps
  _BOOL1 v41; // c0
  char v42; // c2
  _BOOL1 v43; // c3
  int v44; // eax
  double v45; // st7
  double v46; // st6
  double v47; // st5
  double v48; // st7
  int v49; // eax
  double v50; // st6
  double v51; // st5
  double v52; // st3
  double v53; // st7
  double v54; // rt1
  double v55; // st5
  double v56; // st4
  int v57; // edi
  double v58; // st3
  float v59; // eax
  double v60; // st4
  float v61; // eax
  double v62; // st7
  __int16 v63; // fps
  _BOOL1 v64; // c0
  char v65; // c2
  _BOOL1 v66; // c3
  int v67; // eax
  double v68; // st7
  double v69; // st6
  double v70; // st5
  double v71; // st7
  int v72; // eax
  double v73; // st6
  double v74; // st5
  double v75; // st3
  double v76; // st7
  double v77; // rtt
  double v78; // st5
  double v79; // st4
  int v80; // edi
  double v81; // st3
  float v82; // eax
  double v83; // st4
  float v84; // eax
  double v85; // st7
  __int16 v86; // fps
  _BOOL1 v87; // c0
  char v88; // c2
  _BOOL1 v89; // c3
  int v90; // eax
  double v91; // st7
  double v92; // st6
  double v93; // st5
  double v94; // st7
  int v95; // edi
  int v96; // eax
  int v97; // eax
  int v98; // ecx
  float *v99; // ebx
  float *v100; // edi
  float *v101; // eax
  double v102; // st6
  double v103; // st5
  double v104; // st3
  double v105; // st7
  double v106; // rt1
  double v107; // st5
  double v108; // st7
  __int16 v109; // fps
  _BOOL1 v110; // c0
  char v111; // c2
  _BOOL1 v112; // c3
  int v113; // eax
  double v114; // st7
  double v115; // st6
  double v116; // st5
  double v117; // st7
  int v118; // eax
  double v119; // st6
  double v120; // st5
  double v121; // st3
  double v122; // st7
  double v123; // rtt
  double v124; // st5
  double v125; // st7
  __int16 v126; // fps
  _BOOL1 v127; // c0
  char v128; // c2
  _BOOL1 v129; // c3
  int v130; // eax
  double v131; // st7
  double v132; // st6
  double v133; // st5
  double v134; // st7
  int v135; // ebp
  int v136; // esi
  int v137; // eax
  int v138; // ecx
  float *v139; // edi
  int v140; // esi
  int v141; // edx
  float *v142; // edx
  float v143; // eax
  float v144; // eax
  int v145; // eax
  int v146; // eax
  int v147; // edx
  int v148; // ebp
  int v149; // ecx
  int v150; // ebx
  _DWORD *v151; // esi
  double v152; // st7
  _DWORD *v153; // edi
  int v154; // eax
  int v155; // edx
  int v156; // ebx
  int v157; // eax
  float v158; // [esp+34h] [ebp-B0h]
  float v159; // [esp+38h] [ebp-ACh]
  float v160; // [esp+3Ch] [ebp-A8h]
  float v161; // [esp+40h] [ebp-A4h]
  float v162; // [esp+40h] [ebp-A4h]
  float v163; // [esp+40h] [ebp-A4h]
  float v164; // [esp+40h] [ebp-A4h]
  float v165; // [esp+44h] [ebp-A0h]
  float v166; // [esp+44h] [ebp-A0h]
  float v167; // [esp+44h] [ebp-A0h]
  float v168; // [esp+44h] [ebp-A0h]
  float v169; // [esp+48h] [ebp-9Ch]
  float v170; // [esp+48h] [ebp-9Ch]
  float v171; // [esp+48h] [ebp-9Ch]
  float v172; // [esp+48h] [ebp-9Ch]
  float v173; // [esp+4Ch] [ebp-98h]
  float v174; // [esp+4Ch] [ebp-98h]
  float v175; // [esp+4Ch] [ebp-98h]
  float v176; // [esp+4Ch] [ebp-98h]
  float v177; // [esp+50h] [ebp-94h]
  float v178; // [esp+58h] [ebp-8Ch]
  float v179; // [esp+5Ch] [ebp-88h]
  float v180; // [esp+60h] [ebp-84h]
  float v181; // [esp+64h] [ebp-80h]
  float v182; // [esp+68h] [ebp-7Ch]
  float v183; // [esp+6Ch] [ebp-78h]
  float v184; // [esp+70h] [ebp-74h]
  float v185; // [esp+74h] [ebp-70h]
  float v186; // [esp+78h] [ebp-6Ch]
  float v187; // [esp+8Ch] [ebp-58h]
  int v188; // [esp+90h] [ebp-54h]
  float v189; // [esp+94h] [ebp-50h]
  float v190; // [esp+94h] [ebp-50h]
  float v191; // [esp+98h] [ebp-4Ch]
  float v192; // [esp+98h] [ebp-4Ch]
  float v193; // [esp+9Ch] [ebp-48h]
  float v194; // [esp+9Ch] [ebp-48h]
  float v195; // [esp+A0h] [ebp-44h]
  float v196; // [esp+A0h] [ebp-44h]
  float v197; // [esp+A4h] [ebp-40h]
  float v198; // [esp+A4h] [ebp-40h]
  float v199; // [esp+A8h] [ebp-3Ch]
  float v200; // [esp+A8h] [ebp-3Ch]
  float v201; // [esp+ACh] [ebp-38h]
  float v202; // [esp+ACh] [ebp-38h]
  float v203; // [esp+B0h] [ebp-34h]
  float v204; // [esp+B0h] [ebp-34h]
  float v205; // [esp+B4h] [ebp-30h]
  float v206; // [esp+B4h] [ebp-30h]
  float v207; // [esp+B8h] [ebp-2Ch]
  float v208; // [esp+BCh] [ebp-28h]
  float v209; // [esp+BCh] [ebp-28h]
  float v210; // [esp+C0h] [ebp-24h]
  float v211; // [esp+C0h] [ebp-24h]
  float v212; // [esp+C4h] [ebp-20h]
  float v213; // [esp+C4h] [ebp-20h]
  int v214; // [esp+C8h] [ebp-1Ch]
  int v215; // [esp+C8h] [ebp-1Ch]

  v159 = (float)xbase;
  v158 = (float)ybase;
  *(float *)&worldx = -a1 * tcos[a2];
  *(float *)&worldz = a1 * tsin[a2];
  worldy = 0;
  v205 = 9.9999998e17;
  v191 = 9.9999998e17;
  v193 = 9.9999998e17;
  v207 = -9.9999998e17;
  v195 = -9.9999998e17;
  v197 = -9.9999998e17;
  vdirection = 0;
  vtilt = 0;
  velevation = -a2 & 0x3FFF;
  v199 = 0.0;
  xbase += 40;
  calculatetransform(-1, 0, -a2 & 0x3FFF, 0, *(float *)&worldx, 0.0, worldz, 0.0, 0.0, 0.0);
  v201 = 0.0;
  worlddirn = vdirection;
  v203 = 0.0;
  worldelev = velevation;
  worldtilt = vtilt;
  if (TRAK_LEN > 0) {
    v3 = 0;
    do {
      v199 = TrakPt[v3] + TrakPt_variable_9[v3] + v199;
      v201 = TrakPt_variable_1[v3] + TrakPt_variable_10[v3] + v201;
      v203 = TrakPt_variable_2[v3] + TrakPt_variable_11[v3] + v203;
      if (TrakPt[v3] < (double)v193)
        v193 = TrakPt[v3];
      if (TrakPt_variable_9[v3] < (double)v193)
        v193 = TrakPt_variable_9[v3];
      if (TrakPt_variable_1[v3] < (double)v191)
        v191 = TrakPt_variable_1[v3];
      if (TrakPt_variable_10[v3] < (double)v191)
        v191 = TrakPt_variable_10[v3];
      if (TrakPt_variable_2[v3] < (double)v205)
        v205 = TrakPt_variable_2[v3];
      if (TrakPt_variable_11[v3] < (double)v205)
        v205 = TrakPt_variable_11[v3];
      if (TrakPt[v3] > (double)v197)
        v197 = TrakPt[v3];
      if (TrakPt_variable_9[v3] > (double)v197)
        v197 = TrakPt_variable_9[v3];
      if (TrakPt_variable_1[v3] > (double)v195)
        v195 = TrakPt_variable_1[v3];
      if (TrakPt_variable_10[v3] > (double)v195)
        v195 = TrakPt_variable_10[v3];
      if (TrakPt_variable_2[v3] > (double)v207)
        v207 = TrakPt_variable_2[v3];
      if (TrakPt_variable_11[v3] > (double)v207)
        v207 = TrakPt_variable_11[v3];
      v3 += 18;
    } while (v3 < 18 * TRAK_LEN);
  }
  v4 = (v197 - v193) * func3_c_variable_23;
  v194 = v193 - v4;
  v198 = v4 + v197;
  v5 = (v195 - v191) * func3_c_variable_23;
  v192 = v191 - v5;
  v196 = v5 + v195;
  v6 = v207 - v205;
  v177 = v6;
  v206 = v205 - v6 * func3_c_variable_24;
  v7 = 1.0 / (double)(2 * TRAK_LEN);
  v200 = -v199 * v7;
  v202 = -v201 * v7;
  v204 = v7 * -v203;
  v185 = tcos[a3] * tcos[0];
  v184 = tsin[a3] * tcos[0];
  v186 = tsin[0];
  v8 = tcos[a3] * tsin[0];
  v160 = v8;
  v179 = v8 * tsin[0] - v184;
  v9 = tsin[a3] * tsin[0];
  v183 = v9 * tsin[0] + v185;
  v180 = -tsin[0] * tcos[0];
  v181 = -tcos[a3] * tsin[0] * tcos[0] - v9;
  v182 = -tsin[a3] * tsin[0] * tcos[0] + v160;
  v178 = tcos[0] * tcos[0];
  v10 = v192 + v202;
  v11 = v206 + v204;
  v12 = v194 + v200;
  v13 = v12 * v185 + v10 * v179 + v11 * v181 - viewx;
  v14 = v12 * v184 + v10 * v183 + v11 * v182 - viewy;
  v15 = tsin[0] * v12 + v10 * v180 + v11 * v178 - viewz;
  v165 = v13 * vk1 + v14 * vk4 + v15 * vk7;
  v169 = v13 * vk2 + v14 * vk5 + v15 * vk8;
  v16 = v13 * vk3 + v14 * vk6 + v15 * vk9;
  v173 = v16;
  HIWORD(v21) = HIWORD(v173);
  v161 = v173;
  v18 = v16 < func3_c_variable_25;
  v19 = 0;
  v20 = v16 == func3_c_variable_25;
  LOWORD(v21) = v17;
  if (v16 < func3_c_variable_25) {
    v173 = 80.0;
    ++TrackScreenXYZ_variable_1;
  }
  v22 = (double)VIEWDIST;
  v23 = 1.0 / v173;
  v24 = v22 * v165 * v23 + (double)xbase;
  _CHP(v21, &TrackScreenXYZ);
  xp = (int)v24;
  v25 = v23 * (v22 * v169) + (double)ybase;
  _CHP(v26, &TrackScreenXYZ);
  yp = (int)v25;
  v27 = v192 + v202;
  v28 = v206 + v204;
  v29 = v198 + v200;
  v30 = v29 * v185 + v27 * v179 + v28 * v181 - viewx;
  v31 = v29 * v184 + v27 * v183 + v28 * v182 - viewy;
  v32 = v29 * v186 + v27 * v180 + v28 * v178 - viewz;
  v33 = v30 * vk1 + v31 * vk4;
  v34 = scr_size;
  v35 = v32 * vk7;
  *((_DWORD *)&TrackScreenXYZ + 2) = (scr_size * xp) >> 6;
  *((_DWORD *)&TrackScreenXYZ + 3) = (v34 * (199 - yp)) >> 6;
  v36 = v165;
  v166 = v33 + v35;
  v37 = v30 * vk2 + v31 * vk5 + v32 * vk8;
  *((float *)&TrackScreenXYZ + 4) = v36;
  v38 = v169;
  v170 = v37;
  v39 = v30 * vk3 + v31 * vk6 + v32 * vk9;
  v174 = v39;
  *((float *)&TrackScreenXYZ + 5) = v38;
  *((float *)&TrackScreenXYZ + 6) = v161;
  HIWORD(v44) = HIWORD(v174);
  v162 = v174;
  v41 = v39 < func3_c_variable_25;
  v42 = 0;
  v43 = v39 == func3_c_variable_25;
  LOWORD(v44) = v40;
  if (v39 < func3_c_variable_25) {
    v174 = 80.0;
    ++*((_DWORD *)&TrackScreenXYZ + 1);
  }
  v45 = (double)VIEWDIST;
  v46 = 1.0 / v174;
  v47 = v45 * v166 * v46 + (double)xbase;
  _CHP(v44, &TrackScreenXYZ);
  xp = (int)v47;
  v48 = v46 * (v45 * v170) + (double)ybase;
  _CHP(v49, &TrackScreenXYZ);
  yp = (int)v48;
  v50 = v196 + v202;
  v51 = v206 + v204;
  v52 = v198 + v200;
  v53 = v52 * v185 + v50 * v179 + v51 * v181 - viewx;
  v54 = v52 * v184 + v50 * v183 + v51 * v182 - viewy;
  v55 = v52 * v186 + v50 * v180 + v51 * v178 - viewz;
  v56 = v53 * vk1 + v54 * vk4;
  v57 = scr_size;
  v58 = v55 * vk7;
  *((_DWORD *)&TrackScreenXYZ + 7) = (scr_size * xp) >> 6;
  *((_DWORD *)&TrackScreenXYZ + 8) = (v57 * (199 - yp)) >> 6;
  v59 = v166;
  v167 = v56 + v58;
  v60 = v53 * vk2 + v54 * vk5 + v55 * vk8;
  *((float *)&TrackScreenXYZ + 9) = v59;
  v61 = v170;
  v171 = v60;
  v62 = v53 * vk3 + v54 * vk6 + v55 * vk9;
  v175 = v62;
  *((float *)&TrackScreenXYZ + 10) = v61;
  *((float *)&TrackScreenXYZ + 11) = v162;
  HIWORD(v67) = HIWORD(v175);
  v163 = v175;
  v64 = v62 < func3_c_variable_25;
  v65 = 0;
  v66 = v62 == func3_c_variable_25;
  LOWORD(v67) = v63;
  if (v62 < func3_c_variable_25) {
    v175 = 80.0;
    ++*((_DWORD *)&TrackScreenXYZ + 1);
  }
  v68 = (double)VIEWDIST;
  v69 = 1.0 / v175;
  v70 = v68 * v167 * v69 + (double)xbase;
  _CHP(v67, &TrackScreenXYZ);
  xp = (int)v70;
  v71 = v69 * (v68 * v171) + (double)ybase;
  _CHP(v72, &TrackScreenXYZ);
  yp = (int)v71;
  v73 = v196 + v202;
  v74 = v206 + v204;
  v75 = v194 + v200;
  v76 = v75 * v185 + v73 * v179 + v74 * v181 - viewx;
  v77 = v75 * v184 + v73 * v183 + v74 * v182 - viewy;
  v78 = v75 * v186 + v73 * v180 + v74 * v178 - viewz;
  v79 = v76 * vk1 + v77 * vk4;
  v80 = scr_size;
  v81 = v78 * vk7;
  *((_DWORD *)&TrackScreenXYZ + 12) = (scr_size * xp) >> 6;
  *((_DWORD *)&TrackScreenXYZ + 13) = (v80 * (199 - yp)) >> 6;
  v82 = v167;
  v168 = v79 + v81;
  v83 = v76 * vk2 + v77 * vk5 + v78 * vk8;
  *((float *)&TrackScreenXYZ + 14) = v82;
  v84 = v171;
  v172 = v83;
  v85 = v76 * vk3 + v77 * vk6 + v78 * vk9;
  v176 = v85;
  *((float *)&TrackScreenXYZ + 15) = v84;
  *((float *)&TrackScreenXYZ + 16) = v163;
  HIWORD(v90) = HIWORD(v176);
  v164 = v176;
  v87 = v85 < func3_c_variable_25;
  v88 = 0;
  v89 = v85 == func3_c_variable_25;
  LOWORD(v90) = v86;
  if (v85 < func3_c_variable_25) {
    v176 = 80.0;
    ++*((_DWORD *)&TrackScreenXYZ + 1);
  }
  v91 = (double)VIEWDIST;
  v92 = 1.0 / v176;
  v93 = v91 * v168 * v92 + (double)xbase;
  _CHP(v90, &TrackScreenXYZ);
  xp = (int)v93;
  v94 = v92 * (v91 * v172) + (double)ybase;
  v95 = scr_size;
  _CHP(scr_size * (int)v93, &TrackScreenXYZ);
  yp = (int)v94;
  *((_DWORD *)&TrackScreenXYZ + 17) = v96 >> 6;
  *((_DWORD *)&TrackScreenXYZ + 18) = (v95 * (199 - yp)) >> 6;
  *((float *)&TrackScreenXYZ + 19) = v168;
  *((float *)&TrackScreenXYZ + 20) = v172;
  *((float *)&TrackScreenXYZ + 21) = v164;
  RoadPoly_variable_4 = *((_DWORD *)&TrackScreenXYZ + 2);
  RoadPoly_variable_5 = *((_DWORD *)&TrackScreenXYZ + 3);
  RoadPoly_variable_6 = *((_DWORD *)&TrackScreenXYZ + 7);
  RoadPoly_variable_7 = *((_DWORD *)&TrackScreenXYZ + 8);
  RoadPoly_variable_8 = *((_DWORD *)&TrackScreenXYZ + 12);
  RoadPoly_variable_9 = *((_DWORD *)&TrackScreenXYZ + 13);
  v97 = *((_DWORD *)&TrackScreenXYZ + 17);
  RoadPoly_variable_3 = 4;
  RoadPoly_variable_10 = v97;
  RoadPoly_variable_11 = *((_DWORD *)&TrackScreenXYZ + 18);
  RoadPoly = 2105346;
  POLYFLAT(scrbuf, &RoadPoly);
  v98 = 0;
  if (TRAK_LEN > 0) {
    v99 = (float *)&TrackScreenXYZ;
    v100 = &TrakPt[12];
    do {
      v101 = &TrakPt[18 * v98];
      v99[1] = 0.0;
      v102 = v101[1] + v202;
      v103 = v101[2] + v204;
      v104 = *v101 + v200;
      v105 = v104 * v185 + v102 * v179 + v103 * v181 - viewx;
      v106 = v104 * v184 + v102 * v183 + v103 * v182 - viewy;
      v107 = v104 * v186 + v102 * v180 + v103 * v178 - viewz;
      v210 = v105 * vk1 + v106 * vk4 + v107 * vk7;
      v208 = v105 * vk2 + v106 * vk5 + v107 * vk8;
      v108 = v105 * vk3 + v106 * vk6 + v107 * vk9;
      v212 = v108;
      HIWORD(v113) = HIWORD(v212);
      v189 = v212;
      v110 = v108 < func3_c_variable_25;
      v111 = 0;
      v112 = v108 == func3_c_variable_25;
      LOWORD(v113) = v109;
      if (v108 < func3_c_variable_25) {
        v113 = *((_DWORD *)v99 + 1) + 1;
        v212 = 80.0;
        *((_DWORD *)v99 + 1) = v113;
      }
      v114 = (double)VIEWDIST;
      v115 = 1.0 / v212;
      v116 = v114 * v210 * v115 + (double)xbase;
      _CHP(v113, v99);
      xp = (int)v116;
      v117 = v115 * (v114 * v208) + (double)ybase;
      _CHP(scr_size * (int)v116, v99);
      yp = (int)v117;
      *((_DWORD *)v99 + 7) = v118 >> 6;
      *((_DWORD *)v99 + 8) = (scr_size * (199 - yp)) >> 6;
      v99[9] = v210;
      v99[10] = v208;
      v99[11] = v189;
      v119 = v100[1] + v202;
      v120 = v100[2] + v204;
      v121 = *v100 + v200;
      v122 = v121 * v185 + v119 * v179 + v120 * v181 - viewx;
      v123 = v121 * v184 + v119 * v183 + v120 * v182 - viewy;
      v124 = v121 * v186 + v119 * v180 + v120 * v178 - viewz;
      v211 = v122 * vk1 + v123 * vk4 + v124 * vk7;
      v209 = v122 * vk2 + v123 * vk5 + v124 * vk8;
      v125 = v122 * vk3 + v123 * vk6 + v124 * vk9;
      v213 = v125;
      HIWORD(v130) = HIWORD(v213);
      v190 = v213;
      v127 = v125 < func3_c_variable_25;
      v128 = 0;
      v129 = v125 == func3_c_variable_25;
      LOWORD(v130) = v126;
      if (v125 < func3_c_variable_25) {
        v130 = 1117782016;
        v213 = 80.0;
        ++*((_DWORD *)v99 + 1);
      }
      v131 = (double)VIEWDIST;
      v132 = 1.0 / v213;
      v133 = v131 * v211 * v132 + (double)xbase;
      _CHP(v130, v99);
      xp = (int)v133;
      v134 = v132 * (v131 * v209) + (double)ybase;
      v135 = scr_size;
      v136 = scr_size * (int)v133;
      _CHP(v137, v99);
      yp = (int)v134;
      *((_DWORD *)v99 + 2) = v136 >> 6;
      *((_DWORD *)v99 + 3) = (v135 * (199 - yp)) >> 6;
      v99[4] = v211;
      v100 += 36;
      v99[5] = v209;
      v98 += 2;
      v99[6] = v190;
      v99 += 64;
    } while (v98 < TRAK_LEN);
  }
  v138 = 0;
  v188 = 0;
  if (TRAK_LEN > 0) {
    v139 = (float *)&TrackScreenXYZ;
    v140 = 0;
    do {
      v141 = v138 + 2;
      if (v138 + 2 >= TRAK_LEN)
        v141 = 0;
      CarZOrder_variable_1[v140] = v138;
      v142 = (float *)((char *)&TrackScreenXYZ + 128 * v141);
      if (v139[11] <= (double)v139[6])
        v143 = v139[6];
      else
        v143 = v139[11];
      v187 = v143;
      if (v142[11] <= (double)v142[6])
        v144 = v142[6];
      else
        v144 = v142[11];
      if (v187 <= (double)v144) {
        if (v142[11] <= (double)v142[6])
          v145 = *((_DWORD *)v142 + 6);
        else
          v145 = *((_DWORD *)v142 + 11);
      } else if (v139[11] <= (double)v139[6]) {
        v145 = *((_DWORD *)v139 + 6);
      } else {
        v145 = *((_DWORD *)v139 + 11);
      }
      v140 += 3;
      v139 += 64;
      v138 += 2;
      CarPt_variable_14[v140] = v145;
      ++v188;
    } while (v138 < TRAK_LEN);
  }
  v146 = qsort(CarZOrder, v188, 12, carZcmp);
  v147 = v188;
  if (v188 > 0) {
    v148 = 0;
    v149 = 15 * v188;
    do {
      v150 = CarZOrder_variable_1[v148];
      if (v150 >= 0) {
        v147 = 24 * v150;
        if ((TrakColour_variable_1[12 * v150] & 2) == 0
          || (TrakColour_variable_5[12 * v150] & 2) == 0
          || (TrakColour_variable_8[12 * v150] & 2) == 0) {
          v214 = v150 + 2;
          v151 = (_DWORD *)((char *)&TrackScreenXYZ + 128 * v150);
          if (v150 + 2 >= TRAK_LEN)
            v214 = 0;
          RoadPoly_variable_3 = 4;
          v152 = (v207 - TrakPt_variable_5[18 * v150]) * func3_c_variable_26 / v177 + (double)(v149 / v188);
          _CHP(v149 / v188, v149 % v188);
          v153 = (_DWORD *)((char *)&TrackScreenXYZ + 128 * v214);
          v215 = 143 - (int)v152;
          if (v215 > 139)
            v215 = 139;
          if (!v150)
            v215 = 143;
          v154 = v215;
          BYTE1(v154) = BYTE1(v215) | 0x60;
          RoadPoly = v154;
          RoadPoly_variable_4 = v153[2];
          RoadPoly_variable_5 = v153[3];
          RoadPoly_variable_6 = v153[7];
          RoadPoly_variable_7 = v153[8];
          RoadPoly_variable_8 = v151[7];
          RoadPoly_variable_9 = v151[8];
          RoadPoly_variable_10 = v151[2];
          RoadPoly_variable_11 = v151[3];
          POLYFLAT(scrbuf, &RoadPoly);
          v155 = RoadPoly_variable_4;
          RoadPoly_variable_4 = RoadPoly_variable_6;
          v156 = RoadPoly_variable_5;
          RoadPoly_variable_5 = RoadPoly_variable_7;
          RoadPoly_variable_6 = RoadPoly_variable_8;
          RoadPoly_variable_7 = RoadPoly_variable_9;
          RoadPoly_variable_8 = RoadPoly_variable_10;
          RoadPoly_variable_10 = v155;
          v147 = (int)&RoadPoly;
          RoadPoly_variable_9 = RoadPoly_variable_11;
          RoadPoly_variable_11 = v156;
          POLYFLAT(scrbuf, &RoadPoly);
        }
      }
      v146 = 12 * v188;
      v148 += 3;
      v149 -= 15;
    } while (v148 < 3 * v188);
  }
  _CHP(v146, v147);
  xbase = (int)v159;
  _CHP(v157, v147);
  ybase = (int)v158;
}

//-------------------------------------------------------------------------------------------------

void __fastcall DrawCar(int a1, int a2, float a3, int a4, char a5)
{
  int v7; // ecx
  int v8; // eax
  double v9; // st7
  double v10; // st7
  double v11; // st7
  float *v12; // ebx
  int v13; // eax
  int v14; // edx
  int v15; // edi
  double v16; // st7
  double v17; // st6
  double v18; // st5
  double v19; // st7
  __int16 v20; // fps
  _BOOL1 v21; // c0
  char v22; // c2
  _BOOL1 v23; // c3
  int v24; // eax
  double v25; // st7
  double v26; // st6
  double v27; // st5
  double v28; // st7
  int v29; // eax
  double v30; // st7
  double v31; // st6
  double v32; // st5
  int v33; // esi
  unsigned __int8 *v34; // ebp
  int v35; // ecx
  unsigned __int8 *v36; // edx
  int i; // eax
  int v38; // ebx
  double v39; // st7
  double v40; // st5
  double v41; // st4
  double v42; // st3
  unsigned __int8 v43; // ah
  unsigned __int8 *v44; // ecx
  int j; // edx
  int v46; // ebx
  float *v47; // eax
  double v48; // st7
  double v49; // st5
  int v50; // eax
  double v51; // st6
  double v52; // st7
  double v53; // st6
  double v54; // st5
  double v55; // st7
  __int16 v56; // fps
  _BOOL1 v57; // c0
  char v58; // c2
  _BOOL1 v59; // c3
  int v60; // eax
  double v61; // st7
  double v62; // st6
  double v63; // st5
  double v64; // st7
  int v65; // edi
  int v66; // eax
  int v67; // eax
  unsigned int v68; // edx
  int v69; // eax
  float v70; // eax
  float v71; // eax
  float v72; // eax
  unsigned int v73; // edx
  float v74; // eax
  float v75; // eax
  int v76; // eax
  int v77; // edi
  int v78; // ecx
  int v79; // edi
  int v80; // ebx
  int k; // eax
  int v82; // edx
  int v83; // edi
  int v84; // esi
  unsigned __int8 *v85; // edx
  int v86; // ecx
  int m; // eax
  int *v88; // ebx
  double v89; // st7
  int v90; // eax
  int v91; // eax
  int v92; // eax
  float v93; // eax
  int v94; // eax
  int v95; // ecx
  int v96; // [esp+0h] [ebp-19Ch]
  float *v97; // [esp+4h] [ebp-198h]
  float *v98; // [esp+8h] [ebp-194h]
  float *v99; // [esp+Ch] [ebp-190h]
  float *v100; // [esp+10h] [ebp-18Ch]
  int v101; // [esp+14h] [ebp-188h]
  int v102; // [esp+18h] [ebp-184h]
  int v103; // [esp+1Ch] [ebp-180h]
  int v104; // [esp+20h] [ebp-17Ch]
  double v105; // [esp+24h] [ebp-178h]
  double v106; // [esp+2Ch] [ebp-170h]
  double v107; // [esp+34h] [ebp-168h]
  double v108; // [esp+44h] [ebp-158h]
  double v109; // [esp+4Ch] [ebp-150h]
  double v110; // [esp+54h] [ebp-148h]
  double v111; // [esp+5Ch] [ebp-140h]
  int v112; // [esp+64h] [ebp-138h]
  int v113; // [esp+68h] [ebp-134h]
  int v114; // [esp+6Ch] [ebp-130h]
  float v115; // [esp+70h] [ebp-12Ch]
  int v116; // [esp+74h] [ebp-128h]
  int v117; // [esp+78h] [ebp-124h]
  int v118; // [esp+7Ch] [ebp-120h]
  int v119; // [esp+80h] [ebp-11Ch]
  float v120; // [esp+90h] [ebp-10Ch]
  float v121; // [esp+94h] [ebp-108h]
  float v122; // [esp+98h] [ebp-104h]
  float v123; // [esp+9Ch] [ebp-100h]
  float v124; // [esp+A0h] [ebp-FCh]
  float v125; // [esp+B0h] [ebp-ECh]
  float v126; // [esp+B4h] [ebp-E8h]
  float v127; // [esp+B8h] [ebp-E4h]
  float v128; // [esp+BCh] [ebp-E0h]
  float v129; // [esp+C0h] [ebp-DCh]
  float v130; // [esp+C4h] [ebp-D8h]
  float v131; // [esp+C8h] [ebp-D4h]
  float v132; // [esp+CCh] [ebp-D0h]
  float v133; // [esp+D0h] [ebp-CCh]
  float v134; // [esp+D4h] [ebp-C8h]
  int v135; // [esp+D8h] [ebp-C4h]
  int v136; // [esp+DCh] [ebp-C0h]
  int v137; // [esp+E0h] [ebp-BCh]
  float v138; // [esp+E4h] [ebp-B8h]
  float v139; // [esp+E8h] [ebp-B4h]
  float v140; // [esp+ECh] [ebp-B0h]
  float v141; // [esp+F0h] [ebp-ACh]
  float v142; // [esp+F4h] [ebp-A8h]
  int v143; // [esp+F8h] [ebp-A4h]
  unsigned int v144; // [esp+FCh] [ebp-A0h]
  unsigned int v145; // [esp+104h] [ebp-98h]
  unsigned int v146; // [esp+108h] [ebp-94h]
  int v147; // [esp+10Ch] [ebp-90h]
  float v148; // [esp+110h] [ebp-8Ch]
  float v149; // [esp+114h] [ebp-88h]
  int v150; // [esp+118h] [ebp-84h]
  int v151; // [esp+11Ch] [ebp-80h]
  int v152; // [esp+120h] [ebp-7Ch]
  int v153; // [esp+124h] [ebp-78h]
  int v154; // [esp+128h] [ebp-74h]
  int v155; // [esp+12Ch] [ebp-70h]
  int v156; // [esp+130h] [ebp-6Ch]
  int v157; // [esp+134h] [ebp-68h]
  int v158; // [esp+138h] [ebp-64h]
  int v159; // [esp+13Ch] [ebp-60h]
  float v160; // [esp+140h] [ebp-5Ch]
  float v161; // [esp+144h] [ebp-58h]
  float v162; // [esp+148h] [ebp-54h]
  float v163; // [esp+14Ch] [ebp-50h]
  float v164; // [esp+150h] [ebp-4Ch]
  float v165; // [esp+154h] [ebp-48h]
  float v166; // [esp+15Ch] [ebp-40h]
  float v167; // [esp+160h] [ebp-3Ch]
  float v168; // [esp+164h] [ebp-38h]
  float v169; // [esp+178h] [ebp-24h]
  int v170; // [esp+180h] [ebp-1Ch]
  int v171; // [esp+184h] [ebp-18h]

  v114 = a1;
  v155 = a2;
  *(float *)&worldx = -a3 * tcos[a4];
  *(float *)&worldz = a3 * tsin[a4];
  v170 = -1;
  worldy = 0;
  vdirection = 0;
  velevation = -a4 & 0x3FFF;
  vtilt = 0;
  calculatetransform(-1, 0, -a4 & 0x3FFF, 0, *(float *)&worldx, 0.0, worldz, 0.0, 0.0, 0.0);
  worlddirn = vdirection;
  worldelev = velevation;
  worldtilt = vtilt;
  v7 = (unsigned __int8)CarDesigns_variable_1[28 * a2];
  v113 = (unsigned __int8)CarDesigns[28 * a2];
  v171 = (int)*(&CarDesigns_variable_7 + 7 * a2);
  v8 = Car_variable_7[0];
  v165 = tcos[v8] * tcos[Car_variable_6[0]];
  v115 = tsin[v8] * tcos[Car_variable_6[0]];
  v9 = tcos[v8];
  v164 = tsin[Car_variable_6[0]];
  v124 = v9 * v164 * tsin[Car_variable_5[0]] - tsin[v8] * tcos[Car_variable_5[0]];
  v163 = tsin[v8] * v164 * tsin[Car_variable_5[0]] + tcos[v8] * tcos[Car_variable_5[0]];
  v123 = -tsin[Car_variable_5[0]] * tcos[Car_variable_6[0]];
  v162 = -tcos[v8] * v164 * tcos[Car_variable_5[0]] - tsin[v8] * tsin[Car_variable_5[0]];
  v122 = -tsin[v8] * v164 * tcos[Car_variable_5[0]] + tcos[v8] * tsin[Car_variable_5[0]];
  v10 = tcos[Car_variable_6[0]];
  v121 = Car[0];
  v160 = Car_variable_1[0];
  v11 = v10 * tcos[Car_variable_5[0]];
  v120 = Car_variable_2[0];
  v12 = (float *)&CarBox[24 * a2];
  v13 = car_flat_remap_variable_1[2 * a2];
  v112 = car_flat_remap[2 * a2];
  v156 = v13;
  v14 = 0;
  v15 = scr_size;
  v161 = v11;
  do {
    v111 = *v12;
    v110 = v12[1];
    v109 = v12[2];
    CarPt_variable_2[v14] = v165 * v111 + v124 * v110 + v162 * v109 + v121;
    CarPt_variable_3[v14] = v115 * v111 + v163 * v110 + v122 * v109 + v160;
    CarPt_variable_4[v14] = v164 * v111 + v123 * v110 + v161 * v109 + v120;
    v16 = CarPt_variable_2[v14] - viewx;
    v17 = CarPt_variable_3[v14] - viewy;
    v18 = CarPt_variable_4[v14] - viewz;
    *(float *)&v119 = v16 * vk1 + v17 * vk4 + v18 * vk7;
    *(float *)&v118 = v16 * vk2 + v17 * vk5 + v18 * vk8;
    v19 = v16 * vk3 + v17 * vk6 + v18 * vk9;
    *(float *)&v117 = v19;
    HIWORD(v24) = HIWORD(v117);
    v12 += 3;
    v116 = v117;
    v21 = v19 < func3_c_variable_29;
    v22 = 0;
    v23 = v19 == func3_c_variable_29;
    LOWORD(v24) = v20;
    if (v19 < func3_c_variable_29)
      *(float *)&v117 = 80.0;
    v25 = (double)VIEWDIST;
    v26 = 1.0 / *(float *)&v117;
    v27 = v25 * *(float *)&v119 * v26 + (double)xbase;
    _CHP(v24, v14 * 4);
    xp = (int)v27;
    v28 = v26 * (v25 * *(float *)&v118) + (double)ybase;
    _CHP(v15 * (int)v27, v14 * 4);
    yp = (int)v28;
    CarPt[v14] = v29 >> 6;
    v14 += 8;
    carlocal_variable_3[v14] = (v15 * (199 - yp)) >> 6;
    roadheight_variable_1[v14] = v119;
    roadheight_variable_2[v14] = v118;
    roadheight_variable_3[v14] = v116;
  } while (v14 != 32);
  CarPol_variable_3 = CarPt[0];
  CarPol_variable_4 = CarPt_variable_1[0];
  CarPol_variable_5 = CarPt_variable_8;
  CarPol_variable_6 = CarPt_variable_9;
  CarPol_variable_7 = CarPt_variable_10;
  CarPol_variable_8 = CarPt_variable_11;
  CarPol_variable_9 = CarPt_variable_12;
  CarPol_variable_10 = CarPt_variable_13;
  CarPol = 2105346;
  CarPol_variable_2 = 4;
  POLYFLAT(v114, &CarPol);
  v30 = v121 - viewx;
  v31 = v160 - viewy;
  v32 = v120 - viewz;
  v168 = v165 * v30 + v115 * v31 + v164 * v32;
  v167 = v124 * v30 + v163 * v31 + v123 * v32;
  v33 = 0;
  v152 = (int)*(&CarDesigns_variable_3 + 7 * v155);
  v34 = (unsigned __int8 *)*(&CarDesigns_variable_2 + 7 * v155);
  v166 = v30 * v162 + v31 * v122 + v32 * v161;
  memset(car_persps, 0, 4 * v7);
  v154 = 0;
  if (v113 > 0) {
    v145 = 0;
    do {
      v35 = v152;
      v36 = v34;
      for (i = 0; i != 16; *(int *)((char *)&v96 + i) = v38) {
        i += 4;
        v38 = v35 + 12 * *v36++;
      }
      v39 = *v97 - *v99;
      v169 = v97[1] - v99[1];
      v40 = *v98 - *v100;
      v41 = v98[1] - v100[1];
      v42 = v98[2] - v100[2];
      v43 = v34[5];
      v107 = ((*v97 + *v98 + *v99 + *v100) * func3_c_variable_27 + v168) * (v169 * v42 - (v97[2] - v99[2]) * v41)
        + ((v97[1] + v98[1] + v99[1] + v100[1]) * func3_c_variable_27 + v167) * ((v97[2] - v99[2]) * v40 - v42 * v39)
        + (func3_c_variable_27 * (v97[2] + v98[2] + v99[2] + v100[2]) + v166) * (v41 * v39 - v40 * v169);
      if ((v43 & 0x20) != 0 || v107 <= 0.0) {
        v44 = v34;
        for (j = 0; j != 4; ++j) {
          v46 = *v44;
          if (!car_persps[v46]) {
            car_persps[v46] = -1;
            v47 = (&v97)[j];
            v108 = *v47;
            v106 = v47[1];
            v105 = v47[2];
            if ((cheat_mode & 0x8000) != 0) {
              v108 = v108 * func3_c_variable_28;
              v106 = func3_c_variable_28 * v106;
            }
            v48 = v108;
            v49 = v106;
            v50 = 8 * v46;
            v51 = v105;
            CarPt_variable_2[v50] = v165 * v108 + v124 * v106 + v162 * v105 + v121;
            CarPt_variable_3[v50] = v115 * v48 + v163 * v49 + v122 * v51 + v160;
            CarPt_variable_4[v50] = v48 * v164 + v49 * v123 + v51 * v161 + v120;
            v52 = CarPt_variable_2[8 * v46] - viewx;
            v53 = CarPt_variable_3[8 * v46] - viewy;
            v54 = CarPt_variable_4[8 * v46] - viewz;
            *(float *)&v151 = v52 * vk1 + v53 * vk4 + v54 * vk7;
            *(float *)&v150 = v52 * vk2 + v53 * vk5 + v54 * vk8;
            v55 = v52 * vk3 + v53 * vk6 + v54 * vk9;
            v149 = v55;
            HIWORD(v60) = HIWORD(v149);
            v148 = v149;
            v57 = v55 < func3_c_variable_29;
            v58 = 0;
            v59 = v55 == func3_c_variable_29;
            LOWORD(v60) = v56;
            if (v55 < func3_c_variable_29)
              v149 = 80.0;
            v61 = (double)VIEWDIST;
            v62 = 1.0 / v149;
            v63 = v61 * *(float *)&v151 * v62 + (double)xbase;
            _CHP(v60, j * 4);
            xp = (int)v63;
            v64 = v62 * (v61 * *(float *)&v150) + (double)ybase;
            v65 = (int)v63 * scr_size;
            _CHP(v66, j * 4);
            yp = (int)v64;
            v67 = 8 * v46;
            CarPt[v67] = v65 >> 6;
            CarPt_variable_1[v67] = (scr_size * (199 - yp)) >> 6;
            CarPt_variable_5[v67] = v151;
            CarPt_variable_6[v67] = v150;
            CarPt_variable_7[v67] = v148;
          }
          ++v44;
        }
        if (v107 > 0.0 && (v34[5] & 8) != 0) {
          v68 = v145;
          v69 = -v154 - 1;
        } else {
          v68 = v145;
          v69 = v154;
        }
        *(int *)((char *)CarZOrder_variable_1 + v68) = v69;
        CarZOrder[v145 / 4] = *((__int16 *)v34 + 4);
        if ((v34[5] & 0x80u) == 0) {
          if (CarPt_variable_7[8 * v34[2]] <= (double)CarPt_variable_7[8 * v34[3]])
            v74 = CarPt_variable_7[8 * v34[3]];
          else
            v74 = CarPt_variable_7[8 * v34[2]];
          v130 = v74;
          if (CarPt_variable_7[8 * *v34] <= (double)CarPt_variable_7[8 * v34[1]])
            v75 = CarPt_variable_7[8 * v34[1]];
          else
            v75 = CarPt_variable_7[8 * *v34];
          v131 = v75;
          if (v75 <= (double)v130) {
            if (CarPt_variable_7[8 * v34[2]] <= (double)CarPt_variable_7[8 * v34[3]])
              v72 = CarPt_variable_7[8 * v34[3]];
            else
              v72 = CarPt_variable_7[8 * v34[2]];
            v134 = v72;
          } else {
            if (CarPt_variable_7[8 * *v34] <= (double)CarPt_variable_7[8 * v34[1]])
              v72 = CarPt_variable_7[8 * v34[1]];
            else
              v72 = CarPt_variable_7[8 * *v34];
            v133 = v72;
          }
          v132 = v72;
          v73 = v145;
        } else {
          if (CarPt_variable_7[8 * v34[2]] >= (double)CarPt_variable_7[8 * v34[3]])
            v70 = CarPt_variable_7[8 * v34[3]];
          else
            v70 = CarPt_variable_7[8 * v34[2]];
          v125 = v70;
          if (CarPt_variable_7[8 * *v34] >= (double)CarPt_variable_7[8 * v34[1]])
            v71 = CarPt_variable_7[8 * v34[1]];
          else
            v71 = CarPt_variable_7[8 * *v34];
          v126 = v71;
          if (v71 >= (double)v125) {
            if (CarPt_variable_7[8 * v34[2]] >= (double)CarPt_variable_7[8 * v34[3]])
              v72 = CarPt_variable_7[8 * v34[3]];
            else
              v72 = CarPt_variable_7[8 * v34[2]];
            v129 = v72;
          } else {
            if (CarPt_variable_7[8 * *v34] >= (double)CarPt_variable_7[8 * v34[1]])
              v72 = CarPt_variable_7[8 * v34[1]];
            else
              v72 = CarPt_variable_7[8 * *v34];
            v128 = v72;
          }
          v127 = v72;
          v73 = v145;
        }
        *(float *)((char *)CarZOrder_variable_2 + v73) = v72;
        ++v33;
        v145 += 12;
      }
      v34 += 12;
      ++v154;
    } while (v154 < v113);
  }
  if (v33 > 0) {
    v153 = 0;
    v136 = 28 * v155;
    v76 = (int)*(&CarDesigns_variable_2 + 7 * v155);
    v146 = 0;
    v135 = v76;
    do {
      v77 = CarZOrder_variable_1[v146 / 4];
      if (v77 < 0)
        v77 = -1 - v77;
      v78 = *(__int16 *)(v135 + 12 * v77 + 8);
      v79 = v153;
      if (v78 >= 0) {
        v137 = *(int *)((char *)&CarDesigns_variable_2 + v136);
        do {
          v80 = -1;
          for (k = 0; k < v33; ++k) {
            v82 = CarZOrder_variable_1[3 * k];
            if (v82 < 0)
              v82 = -1 - v82;
            if (v78 == v82) {
              v80 = k;
              k = v33;
            }
          }
          if (v80 >= 0)
            CarZOrder_variable_2[3 * v80] = CarZOrder_variable_2[3 * v79] + func3_c_variable_30;
          v78 = *(__int16 *)(v137 + 12 * v78 + 8);
          v79 = v80;
        } while (v78 >= 0);
      }
      v146 += 12;
      ++v153;
    } while (v33 > v153);
    qsort(CarZOrder, v33, 12, carZcmp);
    v143 = v155 + 3;
    v144 = 4 * v155;
    v158 = 28 * v155;
    v159 = a5 & 1;
    v83 = 0;
    v147 = 12 * v33;
    do {
      v84 = CarZOrder_variable_1[v83 / 4u];
      if (v84 >= 0) {
        v157 = 0;
      } else {
        v157 = -1;
        v84 = -1 - v84;
      }
      v85 = (unsigned __int8 *)(*(char **)((char *)&CarDesigns_variable_2 + v158) + 12 * v84);
      v86 = *((_DWORD *)v85 + 1);
      for (m = 0; m != 4; (&v100)[m] = (float *)v88) {
        ++m;
        v88 = &CarPt[8 * *v85++];
      }
      v89 = *(float *)(v103 + 28);
      CarPol_variable_2 = 4;
      if (v89 >= *(float *)(v104 + 28))
        v90 = v104;
      else
        v90 = v103;
      v138 = *(float *)(v90 + 28);
      if (*(float *)(v101 + 28) >= (double)*(float *)(v102 + 28))
        v91 = v102;
      else
        v91 = v101;
      v139 = *(float *)(v91 + 28);
      if (v139 >= (double)v138) {
        if (*(float *)(v103 + 28) >= (double)*(float *)(v104 + 28))
          v94 = v104;
        else
          v94 = v103;
        v142 = *(float *)(v94 + 28);
        v93 = v142;
      } else {
        if (*(float *)(v101 + 28) >= (double)*(float *)(v102 + 28))
          v92 = v102;
        else
          v92 = v101;
        v141 = *(float *)(v92 + 28);
        v93 = v141;
      }
      v140 = v93;
      CarPol_variable_3 = *(_DWORD *)v101;
      CarPol_variable_4 = *(_DWORD *)(v101 + 4);
      CarPol_variable_5 = *(_DWORD *)v102;
      CarPol_variable_6 = *(_DWORD *)(v102 + 4);
      CarPol_variable_7 = *(_DWORD *)v103;
      CarPol_variable_8 = *(_DWORD *)(v103 + 4);
      CarPol_variable_9 = *(_DWORD *)v104;
      CarPol_variable_10 = *(_DWORD *)(v104 + 4);
      if (v157) {
        v86 = (*(_DWORD **)((char *)&CarDesigns_variable_4 + v158))[v84];
        BYTE1(v86) |= 0x20u;
      } else if ((v86 & 0x200) != 0) {
        if ((unsigned __int8)v86 >= 4u)
          v86 = *(_DWORD *)(v171 + 4 * (v159 + 17 * (unsigned __int8)v86) + 4);
        else
          v86 = *(_DWORD *)(v171 + 68 * (unsigned __int8)v86 + 4);
      }
      if (((unsigned int)cstart_branch_1 & textures_off) != 0 && (v86 & 0x100) == 0 && (unsigned __int8)v86 == v112)
        v86 = v156;
      CarPol = v86;
      if (v93 >= 1.0) {
        if ((v86 & 0x100) != 0 && v170) {
          v95 = car_texmap[v144 / 4];
          v96 = gfx_size;
          POLYTEX(horizon_vga[v95], v114, (int *)&CarPol, v95, gfx_size);
        } else {
          POLYFLAT(v114, &CarPol);
        }
      } else {
        v96 = gfx_size;
        subdivide(
          v114,
          (int)&CarPol,
          *(float *)(v101 + 20),
          *(float *)(v101 + 24),
          *(float *)(v101 + 28),
          *(float *)(v102 + 20),
          *(float *)(v102 + 24),
          *(float *)(v102 + 28),
          *(float *)(v103 + 20),
          *(float *)(v103 + 24),
          *(float *)(v103 + 28),
          *(float *)(v104 + 20),
          *(float *)(v104 + 24),
          *(float *)(v104 + 28),
          v143,
          gfx_size);
      }
      v83 += 12;
    } while (v83 < v147);
  }
}

//-------------------------------------------------------------------------------------------------

_DWORD *__fastcall championship_winner(int a1, int a2, int a3, _BYTE *a4)
{
  int v4; // edi
  int v5; // esi
  int v6; // ebp
  unsigned int v7; // ecx
  char v8; // al
  unsigned int v9; // ecx
  int v10; // ebx
  int v11; // edi
  char *v12; // esi
  unsigned int v13; // ecx
  char v14; // al
  unsigned int v15; // ecx
  int v17; // [esp+0h] [ebp-20h]
  int v18; // [esp+4h] [ebp-1Ch]

  SVGA_ON = -1;
  init_screen(a1, -1, 0);
  winx = 0;
  winw = XMAX;
  winy = 0;
  winh = YMAX;
  mirror = 0;
  setpal((int)&aReschampPal[3], -1, 0, a4);
  front_vga[0] = try_load_picture(&aOnchampBm[2]);
  if (front_vga[0]) {
    v17 = 12;
  } else {
    front_vga[0] = load_picture(&aSmachumpBm[3]);
    v17 = 1;
  }
  if (v17 != 1 && MusicVolume && MusicCard)
    v18 = 720;
  else
    v18 = 180;
  v4 = scrbuf;
  v5 = front_vga[0];
  v6 = 0;
  if (SVGA_ON)
    v7 = 256000;
  else
    v7 = 64000;
  v8 = v7;
  v9 = v7 >> 2;
  qmemcpy((void *)scrbuf, (const void *)front_vga[0], 4 * v9);
  qmemcpy((void *)(v4 + 4 * v9), (const void *)(v5 + 4 * v9), v8 & 3);
  copypic((char *)scrbuf, (int)screen);
  v10 = 0;
  startmusic(winchampsong);
  enable_keyboard();
  fade_palette(32, -1, 0, 0);
  front_fade = -1;
  ticks = 0;
  frames = 1;
  do {
    if (fatkbhit())
      break;
    v10 -= frames;
    frames = 0;
    if (v10 < 0) {
      v11 = scrbuf;
      v12 = (char *)(front_vga[0] + 256000 * v6);
      if (SVGA_ON)
        v13 = 256000;
      else
        v13 = 64000;
      v14 = v13;
      v15 = v13 >> 2;
      qmemcpy((void *)scrbuf, v12, 4 * v15);
      qmemcpy((void *)(v11 + 4 * v15), &v12[4 * v15], v14 & 3);
      copypic((char *)scrbuf, (int)screen);
      do {
        if (++v6 == v17)
          v6 ^= v17;
        v10 += 2;
      } while (v10 < 0);
    }
  } while (ticks < v18);
  return fre(front_vga);
}

//-------------------------------------------------------------------------------------------------

int print_mem_used()
{
  printf(&func3_c_variable_34);
  printf(aHiMemUsedI);
  return printf(aLoMemUsedI);
}

//-------------------------------------------------------------------------------------------------

int __fastcall try_load_picture(int a1, int a2, int a3, int a4)
{
  int v4; // ebx
  __int64 v5; // rax
  unsigned int v6; // eax
  int v7; // ecx

  v4 = 0;
  v5 = open(a1, 512);
  if ((_DWORD)v5 != -1) {
    close(v5, HIDWORD(v5));
    v6 = getcompactedfilelength(SHIDWORD(v5), SHIDWORD(v5), 0, a4);
    v7 = trybuffer(v6);
    v4 = v7;
    if (v7)
      loadcompactedfile(SHIDWORD(v5), v7);
  }
  return v4;
}

//-------------------------------------------------------------------------------------------------

_DWORD *__fastcall save_champ(int a1)
{
  char *v2; // eax
  _BYTE *v3; // eax
  char v4; // dl
  _BYTE *v5; // eax
  _BYTE *v6; // eax
  int i; // edx
  int v8; // ebx
  _BYTE *v9; // eax
  int v10; // ebx
  int v11; // ebx
  int v12; // esi
  int v13; // edx
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // esi
  int v19; // ebx
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int j; // ebx
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // edx
  int v28; // edi
  int k; // esi
  int v30; // edx
  int v31; // ebx
  int v32; // eax
  char v33; // cl
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int m; // edx
  int v39; // eax
  char v40; // bl
  int v41; // esi
  char v42; // cl
  char *v43; // eax
  int v44; // esi
  int n; // edx
  char v46; // ch
  int v47; // edi
  char *v49; // [esp+0h] [ebp-1Ch] BYREF

  v2 = (char *)getbuffer(0x800u);
  v49 = v2;
  *v2 = TrackLoad;
  v3 = v2 + 1;
  v4 = competitors;
  if (((unsigned int)cstart_branch_1 & textures_off) != 0)
    v4 = competitors | 0x20;
  if ((cheat_mode & 2) != 0)
    v4 |= 0x40u;
  if ((cheat_mode & 0x200) != 0)
    v4 |= 0x80u;
  v5 = v3 + 1;
  *(v5++ - 1) = v4;
  *(v5++ - 1) = players;
  *(v5 - 1) = level;
  v6 = v5 + 3;
  *(v6 - 3) = damage_level;
  *(v6 - 2) = player_type;
  *(v6 - 1) = my_number;
  for (i = 0; i != 16; ++i) {
    v8 = Players_Cars[i];
    if (player_invul[i])
      LOBYTE(v8) = v8 | 0x40;
    v9 = v6 + 1;
    *(v9 - 1) = v8;
    v6 = v9 + 1;
    v10 = manual_control[i];
    *(v6 - 1) = v10;
  }
  v11 = 1;
  v12 = 0;
  if (numcars > 0) {
    v13 = 0;
    do {
      if (non_competitors[v13])
        v12 |= v11;
      ++v13;
      v11 *= 2;
    } while (v13 < numcars);
  }
  v14 = sav_champ_int(v6, v12, v11);
  v15 = sav_champ_int(v14, network_champ_on, v11);
  v16 = sav_champ_int(v15, network_slot, v11);
  v17 = sav_champ_int(v16, net_type, v11);
  v18 = 0;
  if (numcars > 0) {
    v19 = 0;
    do {
      v20 = sav_champ_int(v17, championship_points[v19], v19 * 4);
      v21 = sav_champ_int(v20, total_kills[v19], v19 * 4);
      v22 = sav_champ_int(v21, total_fasts[v19], v19 * 4);
      ++v18;
      v17 = sav_champ_int(v22, total_wins[v19], v19 * 4);
      ++v19;
    } while (v18 < numcars);
  }
  for (j = 0; j != 8; v17 = sav_champ_int(v26, v27, j * 4)) {
    v24 = sav_champ_int(v17, team_points[j], j * 4);
    v25 = sav_champ_int(v24, team_kills[j], j * 4);
    v26 = sav_champ_int(v25, team_fasts[j], j * 4);
    v27 = team_wins[j++];
  }
  v28 = 9;
  for (k = 0; k < 16; ++k) {
    v30 = 9 * k;
    v31 = v28;
    do {
      v32 = v17 + 1;
      *(_BYTE *)(v32 - 1) = default_names[v30];
      v17 = v32 + 1;
      v33 = player_names[v30++];
      *(_BYTE *)(v17 - 1) = v33;
    } while (v30 != v28);
    v28 += 9;
  }
  v34 = sav_champ_int(v17, serial_port, v31);
  v35 = sav_champ_int(v34, modem_port, v31);
  v36 = sav_champ_int(v35, modem_call, v31);
  v37 = sav_champ_int(v36, modem_baud, v31) + 1;
  *(_BYTE *)(v37 - 1) = modem_phone[0];
  for (m = 1; m <= 50; m += 5) {
    v39 = v37 + 1;
    *(_BYTE *)(v39++ - 1) = modem_phone[m];
    *(_BYTE *)(v39++ - 1) = modem_phone_variable_1[m];
    *(_BYTE *)(v39++ - 1) = modem_phone_variable_2[m];
    *(_BYTE *)(v39 - 1) = modem_phone_variable_3[m];
    v37 = v39 + 1;
    v40 = modem_phone_variable_4[m];
    *(_BYTE *)(v37 - 1) = v40;
  }
  v41 = v37;
  v42 = 0;
  v43 = v49;
  v44 = v41 - (_DWORD)v49;
  for (n = 0; n < v44; v42 += v46) {
    ++n;
    v46 = *v43++;
  }
  *v43 = v42;
  v47 = fopen(&save_slots[13 * a1 - 13], &func3_c_variable_37);
  fwrite(v49, 1, v44 + 1, v47);
  fclose(v47);
  return fre(&v49);
}

//-------------------------------------------------------------------------------------------------

int __fastcall load_champ(int a1)
{
  int v1; // edx
  int v2; // ecx
  __int64 v3; // rax
  int v4; // esi
  char *v5; // eax
  char v6; // cl
  int i; // edx
  char v8; // ch
  int v9; // edi
  char v10; // al
  int v11; // edx
  int v12; // ecx
  _BYTE *v13; // ebx
  int j; // eax
  char v15; // dl
  unsigned __int8 *v16; // ebx
  int *v17; // ecx
  int v18; // edx
  int v19; // ebx
  _DWORD *v20; // edx
  int v21; // eax
  int v22; // esi
  int v23; // eax
  int v24; // ebp
  int v25; // ecx
  int *v26; // edx
  int v27; // eax
  _DWORD *v28; // edx
  int v29; // eax
  int *v30; // ecx
  int *v31; // esi
  int *v32; // ebx
  int *v33; // edi
  int v34; // ebp
  int *v35; // edx
  int v36; // ebp
  int *v37; // ebx
  int *v38; // eax
  int *v39; // esi
  int *v40; // ecx
  int v41; // edi
  int *v42; // edx
  int v43; // edi
  int v44; // edi
  int k; // ecx
  int v46; // eax
  char v47; // bl
  _BYTE *v48; // edx
  char *v49; // ebx
  int v50; // eax
  int *v51; // edx
  int v52; // eax
  int v53; // eax
  int v54; // eax
  char *v55; // edx
  int m; // eax
  char v57; // bl
  char *v58; // edx
  char v59; // bl
  char v60; // bl
  char v61; // bl
  int v62; // esi
  char *v63; // ebp
  int v64; // edi
  char *v65; // edx
  char *v66; // eax
  char v67; // cl
  int v68; // edi
  int v69; // esi
  char *v70; // ebp
  int v71; // eax
  int v72; // edx
  int v73; // eax
  int v74; // ebx
  char *v75; // edx
  char *v76; // eax
  char v77; // cl
  int v78; // edx
  unsigned int v79; // edi
  int v80; // edi
  signed int v81; // esi
  int v82; // edx
  unsigned int v83; // ecx
  int n; // eax
  int v85; // ebp
  int v86; // edi
  int v87; // eax
  int v88; // ecx
  int v89; // edx
  int v90; // edx
  int v91; // eax
  int Type; // eax
  char *v94; // [esp+0h] [ebp-30h] BYREF
  int v95; // [esp+4h] [ebp-2Ch]
  int *v96; // [esp+8h] [ebp-28h]
  int v97; // [esp+Ch] [ebp-24h]
  char *v98; // [esp+10h] [ebp-20h]
  signed int v99; // [esp+14h] [ebp-1Ch]

  v1 = open(&save_slots[13 * a1 - 13], 512);
  v2 = v1;
  v95 = 0;
  if (v1 != -1) {
    v94 = (char *)getbuffer(0x800u);
    v3 = filelength(v1, v1, 0);
    v4 = v3;
    if ((_DWORD)v3 == 795) {
      v3 = __PAIR64__((unsigned int)v94, HIDWORD(v3));
      read(v3, v94, 795);
    }
    close(v2, HIDWORD(v3));
    if (v4 == 795) {
      v5 = v94;
      v6 = 0;
      for (i = 0; i < 794; ++i) {
        v8 = *v5++;
        v6 += v8;
      }
      if (*v5 == v6)
        v95 = -1;
    }
    if (v95) {
      v9 = racers;
      broadcast_mode = -666;
      while (broadcast_mode)
        ;
      tick_on = 0;
      TrackLoad = (unsigned __int8)*v94;
      v10 = v94[1];
      competitors[0] = v10 & 0x1F;
      if ((v10 & 0x20) != 0)
        textures_off |= (unsigned int)cstart_branch_1;
      else
        textures_off &= ~0x10000u;
      if ((v10 & 0x40) != 0) {
        v11 = cheat_mode;
        LOBYTE(v11) = cheat_mode | 2;
        cheat_mode = v11;
      } else {
        cheat_mode &= ~2u;
      }
      if (v10 >= 0) {
        v12 = cheat_mode;
        BYTE1(v12) = BYTE1(cheat_mode) & 0xFD;
        cheat_mode = v12;
      } else {
        cheat_mode |= 0x200u;
      }
      players = (unsigned __int8)v94[2];
      level = (unsigned __int8)v94[3];
      damage_level = (unsigned __int8)v94[4];
      player_type = (unsigned __int8)v94[5];
      v13 = v94 + 7;
      my_number = (unsigned __int8)v94[6];
      for (j = 0; j != 16; competitors[j] = v18) {
        v15 = *v13;
        v16 = v13 + 1;
        infinite_laps[++j] = v15 & 0x1F;
        player_started_variable_2[j] = ((v15 & 0x40) == 0) - 1;
        v17 = (int *)(v16 + 1);
        v18 = *v16;
        v13 = v16 + 1;
      }
      v19 = 1;
      v20 = v17 + 1;
      v21 = *v17;
      racers = v9;
      v97 = v21;
      if (numcars > 0) {
        v22 = 4 * numcars;
        v23 = 0;
        v24 = v97;
        do {
          v23 += 4;
          v25 = ((v24 & v19) == 0) - 1;
          v19 *= 2;
          TrackArrow_variable_1[v23 / 4u] = v25;
        } while (v23 < v22);
      }
      v26 = v20 + 1;
      network_champ_on = *(v26++ - 1);
      network_slot = *(v26 - 1);
      v27 = *v26;
      v28 = v26 + 1;
      net_type = v27;
      gssCommsSetType(v27);
      v29 = 0;
      if (numcars > 0) {
        v30 = total_wins;
        v31 = total_fasts;
        v32 = total_kills;
        v33 = championship_points;
        do {
          v34 = *v28;
          v35 = v28 + 1;
          ++v30;
          *v33 = v34;
          ++v32;
          ++v31;
          *(v32 - 1) = *v35;
          ++v33;
          v36 = v35[1];
          ++v35;
          *(v31 - 1) = v36;
          ++v29;
          *(v30 - 1) = v35[1];
          v28 = v35 + 2;
        } while (v29 < numcars);
      }
      v37 = team_wins;
      v38 = team_points;
      v39 = team_fasts;
      v40 = team_kills;
      v96 = &team_points[8];
      do {
        v41 = *v28;
        v42 = v28 + 1;
        *v38 = v41;
        ++v37;
        ++v39;
        *v40++ = *v42;
        v43 = v42[1];
        ++v42;
        *(v39 - 1) = v43;
        ++v38;
        *(v37 - 1) = v42[1];
        v28 = v42 + 2;
      } while (v38 != v96);
      v44 = 9;
      for (k = 0; k < 16; ++k) {
        v46 = 9 * k;
        do {
          v47 = *(_BYTE *)v28;
          v48 = (char *)v28 + 1;
          default_names[v46] = v47;
          v49 = v48;
          ++v46;
          LOBYTE(v49) = *v48;
          v28 = v48 + 1;
          cheat_names_variable_1[v46] = (char)v49;
        } while (v46 != v44);
        v44 += 9;
      }
      v50 = *v28;
      v51 = v28 + 1;
      serial_port = v50;
      v52 = *v51++;
      modem_port = v52;
      v53 = *v51++;
      modem_call = v53;
      v54 = *v51++;
      modem_baud = v54;
      LOBYTE(v54) = *(_BYTE *)v51;
      v55 = (char *)v51 + 1;
      modem_phone[0] = v54;
      for (m = 1; m <= 50; modem_initstring_variable_1[m] = (char)v49) {
        v57 = *v55;
        v58 = v55 + 1;
        modem_phone[m] = v57;
        v59 = *v58++;
        modem_phone_variable_1[m] = v59;
        v60 = *v58++;
        modem_phone_variable_2[m] = v60;
        v61 = *v58++;
        modem_phone_variable_3[m] = v61;
        m += 5;
        LOBYTE(v49) = *v58;
        v55 = v58 + 1;
      }
      v62 = 0;
      if (numcars > 0) {
        v63 = driver_names;
        v64 = 0;
        v98 = &default_names[9];
        do {
          v49 = v98;
          human_control[v64] = 0;
          result_design[v64] = v62 / 2;
          v65 = v63;
          v66 = &default_names[9 * v62];
          do {
            ++v65;
            v67 = *v66++;
            *(v65 - 1) = v67;
          } while (v66 != v49);
          v63 += 9;
          ++v64;
          ++v62;
          v98 += 9;
        } while (v62 < numcars);
      }
      v68 = 0;
      if (players > 0) {
        v69 = 0;
        v70 = &player_names[9];
        do {
          v71 = Players_Cars[v69];
          if (v71 < 8) {
            v72 = 2 * v71;
            if (result_control[2 * v71])
              ++v72;
          } else {
            v72 = 0;
            v73 = 0;
            if (human_control[0]) {
              do {
                v74 = human_control_variable_1[v73++];
                ++v72;
              } while (v74);
            }
          }
          v49 = v70;
          human_control[v72] = manual_control[v69];
          v75 = &driver_names[9 * v72];
          v76 = &player_names[9 * v68];
          do {
            ++v75;
            v77 = *v76++;
            *(v75 - 1) = v77;
          } while (v76 != v70);
          v70 += 9;
          ++v69;
          ++v68;
        } while (v68 < players);
      }
      if (numcars > 0) {
        v78 = 4 * numcars;
        v79 = 0;
        do {
          v79 += 4;
          result_competing_variable_1[v79 / 4] = team_wins_variable_1[v79 / 4];
        } while ((int)v79 < v78);
      }
      v80 = competitors[0];
      v81 = competitors[0];
      if (competitors[0] == 2) {
        v80 = players;
        if (players < 2)
          v80 = competitors[0];
      }
      v82 = 0;
      if (v80 > 0) {
        v81 = 4 * v80;
        v83 = 0;
        do {
          for (n = v82; ; ++n) {
            v49 = (char *)(v82 + 1);
            if (!non_competitors[n])
              break;
            ++v82;
          }
          result_order[v83 / 4] = v82;
          champorder[v83 / 4] = v82;
          v83 += 4;
          ++v82;
        } while ((int)v83 < v81);
      }
      racers = v80;
      v99 = 0;
      if (v80 > 0) {
        v85 = 0;
        do {
          v81 = v99;
          v86 = racers;
          v87 = v99 + 1;
          v88 = championship_points[champorder[v85]];
          if (v99 + 1 < racers) {
            v89 = v87;
            do {
              v49 = (char *)championship_points[champorder[v89]];
              if ((int)v49 > v88) {
                v81 = v87;
                v88 = championship_points[champorder[v89]];
              }
              ++v87;
              ++v89;
            } while (v87 < racers);
          }
          v90 = teamorder_variable_1[++v85];
          teamorder_variable_1[v85] = champorder[v81];
          racers = v86;
          v91 = v99 + 1;
          champorder[v81] = v90;
          v99 = v91;
        } while (v86 > v91);
      }
      Race = ((_BYTE)TrackLoad - 1) & 7;
      tick_on = -1;
      Type = gssCommsGetType();
      if (Type) {
        Type = gssCommsUnInitSystem(Type);
        network_on = 0;
        net_started = 0;
      }
      if (player_type == 1 && net_type == 1)
        Type = select_comport(3u, v49, v81);
      if (player_type == 1 && net_type == 2)
        Type = select_modemstuff(4);
      if (network_on) {
        if (player_type == 1) {
          reset_network(0);
        } else {
          close_network(Type, 0, (int)v49);
          time_to_start = 0;
        }
      } else if (player_type == 1 && net_type != 2) {
        Initialise_Network(0);
      }
    }
    fre(&v94);
  }
  return v95;
}

//-------------------------------------------------------------------------------------------------

unsigned __int8 *__fastcall lod_champ_char(unsigned __int8 *a1, _DWORD *a2)
{
  int v2; // ebx
  unsigned __int8 *result; // eax

  v2 = *a1;
  result = a1 + 1;
  *a2 = v2;
  return result;
}

//-------------------------------------------------------------------------------------------------

_DWORD *__fastcall sav_champ_char(int *a1, _DWORD *a2)
{
  int v2; // ebx
  _DWORD *result; // eax

  v2 = *a1;
  result = a1 + 1;
  *a2 = v2;
  return result;
}

//-------------------------------------------------------------------------------------------------

int __fastcall sav_champ_int(int a1, int a2)
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

int __fastcall check_saves(int a1, int a2, int a3)
{
  char *v3; // esi
  int i; // ecx
  int result; // eax
  int v6; // edx
  int v7; // ebp
  __int64 v8; // rax
  int v9; // edi
  unsigned __int8 *v10; // eax
  unsigned __int8 v11; // al
  unsigned __int8 *v12; // [esp+0h] [ebp-1Ch] BYREF

  v3 = save_slots;
  for (i = 0; i != 24; i += 6) {
    result = open(v3, 512);
    v6 = result;
    v7 = result;
    if (result == -1) {
      save_status[i] = 0;
    } else {
      v12 = (unsigned __int8 *)getbuffer(0x800u);
      v8 = filelength(v6, v6, a3);
      a3 = v8;
      v9 = v8;
      if ((_DWORD)v8 == 795) {
        v8 = __PAIR64__((unsigned int)v12, HIDWORD(v8));
        read(v8, v12, 795);
      }
      close(v7, HIDWORD(v8));
      if (v9 == 795) {
        a3 = -1;
        v10 = v12;
        save_status[i] = -1;
        save_status_variable_1[i] = *v10;
        save_status_variable_2[i] = v12[3];
        save_status_variable_3[i] = v12[5];
        v11 = v12[51];
        if (save_status_variable_3[i] == 1 && v11) {
          if (v11 <= 1u) {
            save_status_variable_3[i] = 3;
          } else if (v11 == 2) {
            save_status_variable_3[i] = 4;
          }
        }
      } else {
        save_status[i] = 0;
      }
      result = (int)fre(&v12);
    }
    v3 += 13;
  }
  return result;
}

//-------------------------------------------------------------------------------------------------

void __fastcall ResultRoundUp(int a1, int a2, int a3, _BYTE *a4)
{
  int v4; // edi
  int v5; // esi
  unsigned int v6; // ecx
  char v7; // al
  unsigned int v8; // ecx
  int v9; // edi
  __int64 v10; // rax
  double v11; // st7
  int v12; // esi
  int v13; // eax
  int v14; // edx
  int v15; // ebx
  int v16; // edi
  int v17; // edi
  int v18; // ebp
  int v19; // esi
  int v20; // eax
  int v21; // edx
  int v22; // edi
  double v23; // st7
  int v24; // edi
  int v25; // ebp
  int v26; // esi
  int v27; // edi
  __int64 v28; // rax
  int v29; // edi
  double v30; // st7
  _UNKNOWN **v31; // edx
  int v32; // [esp+0h] [ebp-28h]
  int v33; // [esp+4h] [ebp-24h]
  int v34; // [esp+4h] [ebp-24h]
  int v35; // [esp+8h] [ebp-20h]
  int v36; // [esp+8h] [ebp-20h]
  int v37; // [esp+Ch] [ebp-1Ch]
  int v38; // [esp+Ch] [ebp-1Ch]

  tick_on = 0;
  v32 = scr_size;
  SVGA_ON = -1;
  init_screen(scr_size, 0, -1);
  setpal((int)aResroundPal, 0, (_WORD *)0xFFFFFFFF, a4);
  winx = 0;
  winw = XMAX;
  winy = 0;
  winh = YMAX;
  mirror = 0;
  front_vga_variable_2 = load_picture(&a00ResroundBm[3]);
  front_vga_variable_1 = load_picture(aFont4Bm);
  front_vga[0] = load_picture(aFont5Bm);
  frontend_on = -1;
  tick_on = -1;
  v4 = scrbuf;
  v5 = front_vga_variable_2;
  if (SVGA_ON)
    v6 = 256000;
  else
    v6 = 64000;
  v7 = v6;
  v8 = v6 >> 2;
  qmemcpy((void *)scrbuf, (const void *)front_vga_variable_2, 4 * v8);
  qmemcpy((void *)(v4 + 4 * v8), (const void *)(v5 + 4 * v8), v7 & 3);
  front_text(320, 8, 143, 1);
  sprintf(&buffer, "%s  %s", &driver_names[9 * result_order[0]], &CompanyNames[20 * result_design[result_order[0]]]);
  front_text(320, 41, 143, 1);
  v9 = 74;
  if (FastestLap >= 0 && BestTime < (double)func3_c_variable_47) {
    v10 = front_text(320, 74, 143, 1);
    v11 = BestTime * func3_c_variable_48;
    _CHP(v10, HIDWORD(v10));
    v37 = (int)v11;
    if ((int)v11 > 599999)
      v37 = 599999;
    fp_buf_variable_8 = 0;
    fp_buf_variable_7 = v37 % 10 + 48;
    v38 = v37 / 10;
    fp_buf_variable_6 = v38 % 10 + 48;
    fp_buf_variable_5 = 58;
    v38 /= 10;
    fp_buf_variable_4 = v38 % 10 + 48;
    v38 /= 10;
    fp_buf_variable_3 = v38 % 6 + 48;
    v38 /= 6;
    fp_buf_variable_1 = v38 % 10 + 48;
    fp_buf = v38 / 10 % 10 + 48;
    fp_buf_variable_2 = 58;
    sprintf(
      &buffer,
      "%s  %s  %s",
      &driver_names[9 * FastestLap],
      &CompanyNames[20 * result_design[FastestLap]],
      &fp_buf);
    front_text(320, 107, 143, 1);
    v9 = 140;
  }
  v12 = -1;
  v13 = 0;
  if (racers > 0) {
    v14 = 0;
    do {
      v15 = result_order[v14];
      if (v13 < result_kills[v15]) {
        v12 = result_order[v14];
        v13 = result_kills[v15];
      }
      ++v14;
    } while (v14 < racers);
  }
  if (v12 >= 0) {
    front_text(320, v9, 143, 1);
    sprintf(
      &buffer,
      "%s  %s  %s %i",
      &driver_names[9 * v12],
      &CompanyNames[20 * result_design[v12]],
      language_buffer_variable_62,
      result_kills[v12]);
    v16 = v9 + 33;
    front_text(320, v16, 143, 1);
    v9 = v16 + 33;
  }
  v17 = v9 + 4;
  front_text(320, v17, 143, 1);
  v18 = result_p1;
  v19 = result_p1;
  sprintf(&buffer, "%s  %s", &driver_names[9 * result_p1], &CompanyNames[20 * result_design[result_p1]]);
  v17 += 33;
  v20 = front_text(320, v17, 143, 1);
  v21 = LODWORD(result_lap[v19]);
  v22 = v17 + 29;
  if (v21 >= 2) {
    v23 = *(float *)&result_best[v19] * func3_c_variable_48;
    _CHP(v20, v21);
    v35 = (int)v23;
    if ((int)v23 > 599999)
      v35 = 599999;
    fp_buf_variable_8 = 0;
    fp_buf_variable_7 = v35 % 10 + 48;
    v36 = v35 / 10;
    fp_buf_variable_6 = v36 % 10 + 48;
    fp_buf_variable_5 = 58;
    v36 /= 10;
    fp_buf_variable_4 = v36 % 10 + 48;
    v36 /= 10;
    fp_buf_variable_3 = v36 % 6 + 48;
    v36 /= 6;
    fp_buf_variable_1 = v36 % 10 + 48;
    fp_buf_variable_2 = 58;
    fp_buf = v36 / 10 % 10 + 48;
  } else {
    fp_buf_variable_8 = 0;
    fp_buf_variable_7 = 45;
    fp_buf_variable_6 = 45;
    fp_buf_variable_5 = 58;
    fp_buf_variable_4 = 45;
    fp_buf_variable_3 = 45;
    fp_buf_variable_2 = 58;
    fp_buf_variable_1 = 45;
    fp_buf = 45;
  }
  if (racers - 1 > result_p1_pos || racers == 1)
    sprintf(&buffer, "%s: %s", language_buffer_variable_22, (const char *)&language_buffer + 64 * result_p1_pos + 384);
  else
    sprintf(&buffer, "%s: %s", language_buffer_variable_22, language_buffer_variable_21);
  sprintf(
    &buffer,
    "%s  %s %s  %s %i",
    &buffer,
    language_buffer_variable_1,
    &fp_buf,
    language_buffer_variable_62,
    result_kills[v18]);
  front_text(320, v22, 143, 1);
  v24 = v22 + 37;
  if (player_type == 2) {
    front_text(320, v24, 143, 1);
    v25 = result_p2;
    v26 = result_p2;
    sprintf(&buffer, "%s  %s", &driver_names[9 * result_p2], &CompanyNames[20 * result_design[result_p2]]);
    v27 = v24 + 33;
    v28 = front_text(320, v27, 143, 1);
    *(float *)&v28 = result_lap[v26];
    v29 = v27 + 29;
    if ((int)v28 >= 2) {
      v30 = *(float *)&result_best[v26] * func3_c_variable_48;
      _CHP(v28, HIDWORD(v28));
      v33 = (int)v30;
      if ((int)v30 > 599999)
        v33 = 599999;
      fp_buf_variable_8 = 0;
      fp_buf_variable_7 = v33 % 10 + 48;
      v34 = v33 / 10;
      fp_buf_variable_5 = 58;
      fp_buf_variable_6 = v34 % 10 + 48;
      v34 /= 10;
      fp_buf_variable_4 = v34 % 10 + 48;
      v34 /= 10;
      fp_buf_variable_3 = v34 % 6 + 48;
      fp_buf_variable_2 = 58;
      v34 /= 6;
      fp_buf_variable_1 = v34 % 10 + 48;
      fp_buf = v34 / 10 % 10 + 48;
    } else {
      fp_buf_variable_8 = 0;
      fp_buf_variable_7 = 45;
      fp_buf_variable_6 = 45;
      fp_buf_variable_5 = 58;
      fp_buf_variable_4 = 45;
      fp_buf_variable_3 = 45;
      fp_buf_variable_2 = 58;
      fp_buf_variable_1 = 45;
      fp_buf = 45;
    }
    if (racers - 1 > result_p2_pos || racers == 1)
      sprintf(&buffer, "%s: %s", language_buffer_variable_22, (const char *)&language_buffer + 64 * result_p2_pos + 384);
    else
      sprintf(&buffer, "%s: %s", language_buffer_variable_22, language_buffer_variable_21);
    sprintf(
      &buffer,
      "%s  %s %s  %s %i",
      &buffer,
      language_buffer_variable_1,
      &fp_buf,
      language_buffer_variable_62,
      result_kills[v25]);
    front_text(320, v29, 143, 1);
  }
  v31 = screen;
  copypic((char *)scrbuf, (int)screen);
  startmusic(leaderboardsong);
  fade_palette(32, (int)v31, (int)&font4_ascii, 0);
  ticks = 0;
  while (!fatkbhit() && ticks < 2160)
    ;
  fre(&front_vga_variable_2);
  fre(&front_vga_variable_1);
  fre(front_vga);
  scr_size = v32;
  holdmusic = -1;
  fade_palette(0, -1, (int)&font4_ascii, 0);
}

//-------------------------------------------------------------------------------------------------

int __usercall RollCredits@<eax>(_WORD *a1@<ebx>, _BYTE *a2@<ecx>, unsigned int a3@<edi>)
{
  __int64 picture; // rax
  int v4; // edi
  int v5; // esi
  int v6; // ecx
  int v7; // ebp
  __int64 v8; // rax
  int v9; // ecx
  _UNKNOWN **v10; // edx
  int v11; // ebx
  int i; // eax
  int result; // eax

  title_screens(0, a1, a2, a3);
  ticks = 0;
  frontend_on = -1;
  tick_on = -1;
  front_vga[0] = load_picture(aCredit1Bm);
  picture = load_picture(&aEcredit2Bm[1]);
  front_vga_variable_1 = picture;
  while (ticks < 108)
    ;
  fade_palette(0, SHIDWORD(picture), -1, (int)a2);
  v4 = 0;
  v5 = 0;
  setpal((int)aCredit1Pal, SHIDWORD(picture), (_WORD *)0xFFFFFFFF, a2);
  do {
    v6 = credit_order[v5];
    if (v6 < 0) {
      if (v6 == -3)
        --v4;
      else
        ++v4;
      v6 = credit_order_variable_1[v5++];
    }
    memset(scrbuf, 0, 256000);
    v7 = front_vga[v4];
    v8 = *(int *)(12 * v6 + v7 + 4);
    v9 = XMAX / 2 - *(_DWORD *)(12 * v6 + v7) / 2;
    display_block(YMAX / 2 - (((int)v8 - HIDWORD(v8)) >> 1), -1);
    v10 = screen;
    copypic((char *)scrbuf, (int)screen);
    fade_palette(32, (int)v10, 0, v9);
    ticks = 0;
    v11 = 72;
    do {
      while (fatkbhit()) {
        ticks = 74;
        if (!fatgetch())
          fatgetch();
        for (i = v5; credit_order[i] != -2; ++i)
          ++v5;
      }
    } while (ticks < 72);
    if (credit_order[v5] != -2)
      ++v5;
    if (credit_order[v5] == -2) {
      v11 = 0;
      holdmusic = 0;
    }
    fade_palette(0, (int)v10, v11, -2);
  } while (credit_order[v5] != -2);
  fre(front_vga);
  fre(&front_vga_variable_1);
  result = 0;
  front_fade = 0;
  return result;
}

//-------------------------------------------------------------------------------------------------

int __fastcall ChampionshipOver(int a1, int a2, int a3, _BYTE *a4)
{
  int v4; // edx
  int v5; // eax
  int v6; // ebx
  int v7; // ebx
  int i; // eax
  int v9; // edi
  int v10; // esi
  unsigned int v11; // ecx
  char v12; // al
  unsigned int v13; // ecx
  unsigned int v14; // edi
  int v15; // eax
  _BYTE *v16; // ecx
  _UNKNOWN **v17; // edx
  int v18; // eax
  int result; // eax
  int v20; // [esp-4h] [ebp-24h]
  int v21; // [esp+0h] [ebp-20h]
  int v22; // [esp+4h] [ebp-1Ch]

  v4 = 0;
  network_champ_on = 0;
  v5 = 0;
  if (champorder[0] != result_p1) {
    do {
      v6 = champorder_variable_1[v5++];
      ++v4;
    } while (v6 != result_p1);
  }
  v7 = player_type;
  v22 = v4;
  if (player_type == 2) {
    v7 = champorder[0];
    a4 = (_BYTE *)result_p2;
    v4 = 0;
    for (i = 0; v7 != result_p2; ++v4)
      v7 = champorder_variable_1[i++];
    if (v4 < v22)
      v22 = v4;
  }
  if (!v22) {
    championship_winner(0, v4, v7, a4);
    champion_race();
  }
  tick_on = 0;
  v21 = scr_size;
  SVGA_ON = -1;
  init_screen(scr_size, 0, -1);
  setpal((int)aResroundPal, 0, (_WORD *)0xFFFFFFFF, a4);
  winx = 0;
  winw = XMAX;
  winy = 0;
  winh = YMAX;
  mirror = 0;
  startmusic(winsong);
  holdmusic = -1;
  title_vga = load_picture(&a00ResroundBm[3]);
  font_vga = load_picture(aFont4Bm);
  front_vga[0] = load_picture(aFont5Bm);
  frontend_on = -1;
  tick_on = -1;
  v9 = scrbuf;
  v10 = title_vga;
  if (SVGA_ON)
    v11 = 256000;
  else
    v11 = 64000;
  v20 = scrbuf;
  v12 = v11;
  v13 = v11 >> 2;
  qmemcpy((void *)scrbuf, (const void *)title_vga, 4 * v13);
  qmemcpy((void *)(v9 + 4 * v13), (const void *)(v10 + 4 * v13), v12 & 3);
  v14 = v20;
  if (v22) {
    if (v22 == 1) {
      front_text(320, 64, 143, 1);
      front_text(320, 100, 143, 1);
      front_text(320, 140, 143, 1);
      v16 = &font5_offsets;
      front_text(320, 180, 143, 1);
      if (Race == 8) {
        TrackLoad = (((_BYTE)TrackLoad - 1) & 7) + 1;
        Race = 0;
      }
    } else {
      front_text(320, 64, 143, 1);
      front_text(320, 140, 143, 1);
      v16 = &font4_offsets;
      front_text(320, 180, 143, 1);
      if (Race == 8) {
        TrackLoad = (((_BYTE)TrackLoad - 1) & 7) + 1;
        v14 = 0;
        Race = 0;
      }
    }
  } else {
    front_text(320, 64, 143, 1);
    if (Race == 8) {
      if (level < 4)
        textures_off |= 0x1000u;
      if (level < 2) {
        v15 = textures_off;
        BYTE1(v15) = BYTE1(textures_off) | 0x80;
        textures_off = v15;
      }
    }
    if (TrackLoad >= 17 || level >= 4) {
      TrackLoad = 17;
      if (level > 0 && Race == 8)
        --level;
    }
    v16 = &font4_offsets;
    front_text(320, 100, 143, 1);
    if (Race == 8) {
      v16 = 0;
      Race = 0;
    }
  }
  v17 = screen;
  copypic((char *)scrbuf, (int)screen);
  fade_palette(32, (int)v17, (int)font4_ascii, (int)v16);
  ticks = 0;
  while (!fatkbhit() && ticks < 2160)
    ;
  fre(&title_vga);
  fre(&font_vga);
  fre(front_vga);
  scr_size = v21;
  fade_palette(0, (int)v17, (int)font4_ascii, (int)v16);
  EndChampSequence(v18);
  result = RollCredits(font4_ascii, v16, v14);
  if (TrackLoad >= 17)
    TrackLoad = 1;
  return result;
}

//-------------------------------------------------------------------------------------------------

_DWORD *__fastcall EndChampSequence(int a1, int a2, int a3, int a4)
{
  int v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  __int64 picture; // rax
  _DWORD *result; // eax

  ticks = 0;
  frontend_on = -1;
  tick_on = -1;
  v4 = 0;
  front_vga[0] = load_picture(round_pics);
  do {
    setpal((int)&round_pals[13 * v4], 0, (char *)&loc_3E7FD + 3, (_BYTE *)a4);
    v5 = memset(scrbuf, 0, 256000);
    v6 = rand(v5);
    v7 = 300 * ((5 * v6 - (__CFSHL__((5 * v6) >> 31, 15) + ((5 * v6) >> 31 << 15))) >> 15);
    a4 = (v7 - (__CFSHL__(v7 >> 31, 2) + 4 * (v7 >> 31))) >> 2;
    display_block(0, -1);
    HIDWORD(picture) = screen;
    copypic((char *)scrbuf, (int)screen);
    fade_palette(32, SHIDWORD(picture), 0, a4);
    ticks = 0;
    if (++v4 < 8) {
      fre(front_vga);
      picture = load_picture(&round_pics[13 * v4]);
      front_vga[0] = picture;
    }
    do {
      if (fatkbhit()) {
        v4 = 8;
        if (!fatgetch())
          fatgetch();
        ticks = 144;
      }
    } while (ticks < 144);
    fade_palette(0, SHIDWORD(picture), 0, a4);
  } while (v4 < 8);
  result = fre(front_vga);
  front_fade = 0;
  return result;
}

//-------------------------------------------------------------------------------------------------

void __fastcall network_fucked(int a1, int a2, int a3)
{
  int v3; // ebp
  int v4; // edi
  int v5; // esi
  unsigned int v6; // ecx
  char v7; // al
  unsigned int v8; // ecx
  _UNKNOWN **v9; // edx
  int v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // [esp-Ch] [ebp-24h]

  if (network_buggered != 666)
    a1 = close_network(a1, a2, a3);
  tick_on = 0;
  v3 = scr_size;
  SVGA_ON = -1;
  init_screen(a1, a2, 0);
  setpal((int)aResroundPal, a2, 0, (_BYTE *)0xFFFFFFFF);
  winx = 0;
  winw = XMAX;
  winy = 0;
  winh = YMAX;
  mirror = 0;
  title_vga = load_picture(&a00ResroundBm[3]);
  font_vga = load_picture(aFont4Bm);
  front_vga[0] = load_picture(aFont5Bm);
  frontend_on = -1;
  tick_on = -1;
  v4 = scrbuf;
  v5 = title_vga;
  if (SVGA_ON)
    v6 = 256000;
  else
    v6 = 64000;
  v7 = v6;
  v8 = v6 >> 2;
  qmemcpy((void *)scrbuf, (const void *)title_vga, 4 * v8);
  qmemcpy((void *)(v4 + 4 * v8), (const void *)(v5 + 4 * v8), v7 & 3);
  if (network_buggered == 666) {
    front_text(320, 100, 143, 1);
    front_text(320, 140, 143, 1);
    front_text(320, 200, 143, 1);
    v13 = 260;
  } else {
    v13 = 192;
  }
  front_text(320, v13, 143, 1);
  v9 = screen;
  copypic((char *)scrbuf, (int)screen);
  startmusic(leaderboardsong);
  fade_palette(32, (int)v9, (int)font4_ascii, (int)&font4_offsets);
  ticks = 0;
  if (network_buggered == 666) {
    v10 = 0;
    do {
      while (fatkbhit()) {
        v11 = fatgetch();
        v9 = (_UNKNOWN **)v11;
        if (v11) {
          if (v11 == 121 || v11 == 89) {
            v10 = -1;
            restart_net = -1;
          }
          if (v11 == 110 || v11 == 78) {
            v10 = -1;
            restart_net = 0;
          }
        } else {
          fatgetch();
        }
      }
    } while (!v10);
  } else {
    while (!fatkbhit() && ticks < 2160)
      ;
  }
  fre(&title_vga);
  fre(&font_vga);
  fre(front_vga);
  scr_size = v3;
  holdmusic = -1;
  fade_palette(0, (int)v9, -1, (int)&font4_offsets);
  if (network_buggered == 666 && !restart_net) {
    broadcast_mode = -666;
    while (broadcast_mode)
      ;
    close_network(v12, (int)v9, -1);
  }
}

//-------------------------------------------------------------------------------------------------

void __fastcall no_cd(int a1, int a2, int a3, _BYTE *a4)
{
  int v4; // ebp
  int v5; // edi
  int v6; // esi
  unsigned int v7; // ecx
  char v8; // al
  unsigned int v9; // ecx
  _UNKNOWN **v10; // edx

  tick_on = 0;
  v4 = scr_size;
  SVGA_ON = -1;
  init_screen(a1, 0, -1);
  setpal((int)aResroundPal, 0, (_WORD *)0xFFFFFFFF, a4);
  winx = 0;
  winw = XMAX;
  winy = 0;
  winh = YMAX;
  mirror = 0;
  title_vga = load_picture(&a00ResroundBm[3]);
  font_vga = load_picture(aFont4Bm);
  front_vga[0] = load_picture(aFont5Bm);
  frontend_on = -1;
  tick_on = -1;
  v5 = scrbuf;
  v6 = title_vga;
  if (SVGA_ON)
    v7 = 256000;
  else
    v7 = 64000;
  v8 = v7;
  v9 = v7 >> 2;
  qmemcpy((void *)scrbuf, (const void *)title_vga, 4 * v9);
  qmemcpy((void *)(v5 + 4 * v9), (const void *)(v6 + 4 * v9), v8 & 3);
  front_text(320, 192, 143, 1);
  v10 = screen;
  copypic((char *)scrbuf, (int)screen);
  fade_palette(32, (int)v10, (int)font4_ascii, 0);
  ticks = 0;
  while (!fatkbhit() && ticks < 2160)
    ;
  fre(&title_vga);
  fre(&font_vga);
  fre(front_vga);
  scr_size = v4;
  holdmusic = 0;
  fade_palette(0, (int)v10, (int)font4_ascii, 0);
  __asm { int     10h; -VIDEO - SET VIDEO MODE }
  doexit();
}

//-------------------------------------------------------------------------------------------------

int __fastcall name_cmp(int a1, int a2)
{
  int v4; // edx
  int v5; // eax
  char v6; // cl

  v4 = -1;
  v5 = 0;
  do {
    if (v5 >= 9)
      break;
    v6 = *(_BYTE *)(a2 + v5);
    if (v6) {
      if (v6 != *(_BYTE *)(a1 + v5))
        v4 = 0;
      ++v5;
    } else {
      v5 = 9;
    }
  } while (v4);
  return v4;
}

//-------------------------------------------------------------------------------------------------

char *__fastcall name_copy(int a1, char *a2)
{
  char *result; // eax
  char *v5; // ebx
  char v6; // cl

  result = a2;
  v5 = a2 + 9;
  do {
    ++a1;
    v6 = *result++;
    *(_BYTE *)(a1 - 1) = v6;
  } while (result != v5);
  return result;
}

//-------------------------------------------------------------------------------------------------

int __fastcall loadtracksample(int a1)
{
  char *v1; // esi
  char *v2; // edi
  char v3; // al
  char v4; // al

  strcpy(buffer, "track");
  sprintf(&buffer_variable_5, "%02d", a1);
  v1 = &aBmRaw[3];
  v2 = &buffer[strlen(buffer)];
  do {
    v3 = *v1;
    *v2 = *v1;
    if (!v3)
      break;
    v4 = v1[1];
    v1 += 2;
    v2[1] = v4;
    v2 += 2;
  } while (v4);
  return loadfrontendsample((int)buffer);
}

//-------------------------------------------------------------------------------------------------

_DWORD *__fastcall front_letter(int a1, unsigned __int8 a2, _DWORD *a3, _DWORD *a4, int a5, char a6)
{
  int v6; // edx
  _DWORD *result; // eax
  int v8; // esi
  int v9; // ebp
  char *v10; // ebx
  char *v11; // eax
  int i; // edi
  int j; // edx
  char v14; // cl

  v6 = *(unsigned __int8 *)(a5 + a2);
  if (v6 == 255) {
    result = a3;
    *a3 += 8;
  } else {
    v8 = *(_DWORD *)(a1 + 12 * v6);
    v9 = *(_DWORD *)(a1 + 12 * v6 + 4);
    v10 = (char *)(a1 + *(_DWORD *)(a1 + 12 * v6 + 8));
    v11 = (char *)(*a3 + scrbuf + 640 * *a4);
    for (i = 0; i < v9; v11 += 640 - v8) {
      for (j = 0; j < v8; ++v11) {
        v14 = *v10++;
        if (v14) {
          if (v14 == -113)
            v14 = a6;
          *v11 = v14;
        }
        ++j;
      }
      ++i;
    }
    result = a3;
    *a3 += v8 + 1;
  }
  return result;
}

//-------------------------------------------------------------------------------------------------

int __fastcall scale_letter(int a1, unsigned __int8 a2, _DWORD *a3, _DWORD *a4, int a5, char a6, int a7)
{
  int v7; // edx
  int result; // eax
  int v9; // ebp
  char *v10; // edx
  char *i; // edi
  int v12; // eax
  int v13; // ebx
  char v14; // cl
  char *v15; // [esp+0h] [ebp-24h]
  int v17; // [esp+Ch] [ebp-18h]
  char *v18; // [esp+10h] [ebp-14h]
  int v19; // [esp+14h] [ebp-10h]

  v7 = *(unsigned __int8 *)(a5 + a2);
  if (v7 == 255) {
    result = (8 * a7) >> 6;
    *a3 += result;
  } else {
    v9 = *(_DWORD *)(a1 + 12 * v7);
    v17 = *(_DWORD *)(a1 + 12 * v7 + 4);
    v10 = (char *)(a1 + *(_DWORD *)(a1 + 12 * v7 + 8));
    v19 = 0;
    for (i = (char *)(640 * *a4 + scrbuf + *a3); v19 < v17; ++v19) {
      v15 = i;
      v18 = v10;
      v12 = a7;
      v13 = 0;
      while (v13 < v9) {
        v14 = *v10;
        if (*v10) {
          if (v14 == -113)
            v14 = a6;
          *i = v14;
        }
        v12 -= 64;
        ++i;
        for (; v12 <= 0; ++v13) {
          ++v10;
          v12 += a7;
        }
      }
      i = v15 + 640;
      v10 = &v18[v9];
    }
    result = (a7 * (v9 + 1)) >> 6;
    *a3 += result;
  }
  return result;
}

//-------------------------------------------------------------------------------------------------

int __fastcall front_text(int a1, unsigned __int8 *a2, int a3, int a4, int a5, int a6, char a7, unsigned int a8)
{
  unsigned __int8 *v9; // esi
  int result; // eax
  int v12; // edx
  int v13; // ebx
  int v14; // ebx
  int v15; // [esp+0h] [ebp-20h]
  int v16; // [esp+4h] [ebp-1Ch] BYREF
  int v17; // [esp+8h] [ebp-18h] BYREF
  int v18; // [esp+Ch] [ebp-14h]
  int v19; // [esp+10h] [ebp-10h]

  v9 = a2;
  v18 = a4;
  result = (int)a2;
  v17 = a5;
  v16 = a6;
  if (a8 && a8 <= 2) {
    v12 = 0;
    if (*v9) {
      do {
        v13 = *(unsigned __int8 *)result++;
        v14 = *(unsigned __int8 *)(a3 + v13);
        if (v14 == 255)
          v12 += 8;
        else
          v12 += *(_DWORD *)(12 * v14 + a1) + 1;
      } while (*(_BYTE *)result);
    }
    if (a8 == 2) {
      v17 -= v12;
    } else {
      result = v12 / 2;
      v17 -= v12 / 2;
    }
  }
  v19 = 0;
  do {
    LOBYTE(result) = *v9;
    if (*v9) {
      if ((_BYTE)result != 10) {
        result = *v9;
        if (*(_BYTE *)(a3 + result) == 0xFF) {
          v17 += 8;
        } else {
          v15 = v16;
          v16 += *(_DWORD *)(v18 + 4 * *(unsigned __int8 *)(a3 + *v9));
          front_letter(a1, *v9, &v17, &v16, a3, a7);
          result = v15;
          v16 = v15;
        }
      }
    } else {
      v19 = -1;
    }
    ++v9;
  } while (!v19);
  return result;
}

//-------------------------------------------------------------------------------------------------

unsigned __int8 __fastcall scale_text(
        int a1,
        _BYTE *a2,
        int a3,
        int a4,
        int a5,
        int a6,
        char a7,
        unsigned int a8,
        int a9,
        int a10)
{
  int v11; // esi
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // edx
  _BYTE *v16; // eax
  int v17; // edx
  int v18; // esi
  unsigned __int8 *v19; // esi
  unsigned __int8 result; // al
  int v21; // [esp+0h] [ebp-34h]
  _BYTE *v22; // [esp+4h] [ebp-30h]
  int v23; // [esp+8h] [ebp-2Ch]
  int v24; // [esp+Ch] [ebp-28h] BYREF
  int v25; // [esp+10h] [ebp-24h] BYREF
  int v26; // [esp+14h] [ebp-20h]
  int v27; // [esp+18h] [ebp-1Ch]
  int v28; // [esp+1Ch] [ebp-18h]
  int v29; // [esp+20h] [ebp-14h]
  int v30; // [esp+24h] [ebp-10h]

  v22 = a2;
  v27 = a4;
  v25 = a5;
  v11 = 0;
  v24 = a6;
  while (*a2) {
    v12 = (unsigned __int8)*a2++;
    v13 = *(unsigned __int8 *)(a3 + v12);
    if (v13 == 255)
      v11 += 8;
    else
      v11 += *(_DWORD *)(12 * v13 + a1) + 1;
  }
  if (!a8) {
    v26 = v25;
    v14 = v11 + v25;
  LABEL_13:
    v21 = v14;
    goto LABEL_14;
  }
  if (a8 > 1) {
    if (a8 != 2)
      goto LABEL_14;
    v26 = v25 - v11;
    v14 = v25;
    goto LABEL_13;
  }
  v26 = v25 - v11 / 2;
  v21 = v11 / 2 + v25;
LABEL_14:
  if (a9 > v26 || v21 > a10) {
    if (a9 <= v26) {
      v15 = a10 - v26;
    } else if (v21 <= a10) {
      v15 = v21 - a9;
    } else {
      v15 = a10 - a9;
    }
    v30 = (v15 << 6) / v11;
  } else {
    v30 = 64;
  }
  v16 = v22;
  v17 = 0;
  while (*v16) {
    v18 = *(unsigned __int8 *)(a3 + (unsigned __int8)*v16++);
    if (v18 == 255)
      v17 += (8 * v30) >> 6;
    else
      v17 += (v30 * (*(_DWORD *)(12 * v18 + a1) + 1)) >> 6;
  }
  if (a8) {
    if (a8 <= 1) {
      v25 -= v17 / 2;
    } else if (a8 == 2) {
      v25 -= v17;
    }
  }
  v29 = 0;
  v19 = v22;
  v28 = (8 * v30) >> 6;
  do {
    result = *v19;
    if (*v19) {
      if (result != 10) {
        if (*(_BYTE *)(a3 + *v19) == 0xFF) {
          result = v28;
          v25 += v28;
        } else {
          v23 = v24;
          v24 += *(_DWORD *)(v27 + 4 * *(unsigned __int8 *)(a3 + *v19));
          scale_letter(a1, *v19, &v25, &v24, a3, a7, v30);
          result = v23;
          v24 = v23;
        }
      }
    } else {
      v29 = -1;
    }
    ++v19;
  } while (!v29);
  return result;
}

int __fastcall clear_screen(int a1, int a2)
{
  return memset(a1, a2, 256000);
}

//-------------------------------------------------------------------------------------------------

unsigned int __fastcall display_picture(void *a1, const void *a2)
{
  unsigned int v3; // ecx
  unsigned int result; // eax

  if (SVGA_ON)
    v3 = 256000;
  else
    v3 = 64000;
  result = v3;
  qmemcpy(a1, a2, v3);
  return result;
}

//-------------------------------------------------------------------------------------------------

unsigned __int8 *__fastcall display_block(int a1, int a2, int a3, unsigned int a4, int a5, int a6)
{
  int v7; // ebp
  int v8; // edx
  int v9; // ebx
  unsigned __int8 *result; // eax
  unsigned __int8 *v11; // esi
  unsigned int v12; // edx
  int j; // ebx
  unsigned __int8 v14; // cl
  int v16; // [esp+8h] [ebp-18h]
  int i; // [esp+Ch] [ebp-14h]

  v7 = *(_DWORD *)(a2 + 12 * a3);
  v8 = 3 * a3;
  v9 = *(_DWORD *)(a2 + 12 * a3 + 4);
  result = (unsigned __int8 *)(a1 + a4 + 640 * a5);
  v11 = (unsigned __int8 *)(*(_DWORD *)(a2 + 4 * v8 + 8) + a2);
  v16 = v9;
  for (i = 0; i < v16; ++i) {
    v12 = a4;
    for (j = 0; j < v7; ++result) {
      v14 = *v11++;
      if (v12 < 0x280 && (a6 < 0 || v14 != a6))
        *result = v14;
      ++v12;
      ++j;
    }
    result += 640 - v7;
  }
  return result;
}

//-------------------------------------------------------------------------------------------------

int __fastcall load_picture(int a1, int a2, int a3, int a4)
{
  __int64 v4; // rax
  int v5; // ebx
  unsigned int v6; // ebx

  v4 = open(a1, 512);
  v5 = v4;
  if ((_DWORD)v4 == -1) {
    printf(&aSUnableToOpenT[3]);
    doexit();
  }
  close(v5, HIDWORD(v4));
  LODWORD(v4) = getcompactedfilelength(SHIDWORD(v4), SHIDWORD(v4), v5, a4);
  v6 = getbuffer(v4);
  loadcompactedfile(SHIDWORD(v4), v6);
  LODWORD(v4) = v6;
  return v4;
}

//-------------------------------------------------------------------------------------------------

int __fastcall AllocateCars(int a1)
{
  int result; // eax
  int v2; // esi
  char *v3; // ebp
  int v4; // edi
  int v5; // eax
  char *v6; // edx
  char *v7; // eax
  char v8; // cl
  int v9; // ecx
  int v10; // edi
  int v11; // ebp
  int v12; // ebx
  int v13; // edx
  int v14; // ecx
  int v15; // edx
  int v16; // esi
  char *v17; // ebx
  char *v18; // edx
  char v19; // cl
  int v20; // edx
  int v21; // ebx
  int v22; // edx
  int v23; // eax
  int v24; // edx
  int v25; // eax
  int v26; // eax
  int v27; // edi
  int v28; // eax
  int v29; // eax
  int v30; // edi
  char *v31; // ebp
  int v32; // esi
  char *v33; // eax
  char *v34; // edx
  char v35; // cl
  int v36; // edx
  int v37; // esi
  char *v38; // [esp+0h] [ebp-20h]
  char *v39; // [esp+4h] [ebp-1Ch]

  my_number = -1;
  numcars = 16;
  ViewType_variable_1 = -1;
  result = check_cars(a1);
  v2 = 0;
  if (numcars > 0) {
    v3 = &default_names[9];
    v39 = driver_names;
    v4 = 0;
    do {
      if ((cheat_mode & 0x4000) != 0)
        v5 = Players_Cars[0];
      else
        v5 = v2 / 2;
      Drivers_Car[v4] = v5;
      v6 = v39;
      v7 = &default_names[9 * v2];
      do {
        ++v6;
        v8 = *v7++;
        *(v6 - 1) = v8;
      } while (v7 != v3);
      v9 = numcars;
      v3 += 9;
      ++v4;
      ++v2;
      result = 0;
      team_wins_variable_1[v4] = 0;
      RecordNames_variable_1[v4] = 0;
      v39 += 9;
    } while (v2 < v9);
  }
  v10 = 0;
  if (players > 0) {
    v11 = 0;
    v38 = &player_names[9];
    do {
      v12 = Players_Cars[v11];
      if (v10 || (result = my_number, my_number < 0)) {
        if (v12 >= 8 || (cheat_mode & 0x4000) != 0) {
          result = 0;
          v13 = 0;
          if (human_control[0]) {
            do {
              v14 = human_control_variable_1[v13++];
              ++result;
            } while (v14);
          }
        } else {
          result = 2 * v12;
          if (human_control[2 * v12])
            ++result;
        }
        if (result >= numcars) {
          result = 0;
          v15 = 0;
          if (human_control[0]) {
            do {
              v16 = human_control_variable_1[v15++];
              ++result;
            } while (v16);
          }
        }
      }
      Drivers_Car[result] = v12;
      v17 = &driver_names[9 * result];
      v18 = &player_names[9 * v10];
      do {
        ++v17;
        v19 = *v18++;
        *(v17 - 1) = v19;
      } while (v18 != v38);
      v20 = wConsoleNode;
      human_control[result] = manual_control[v11];
      v21 = player_invul[v11];
      car_to_player[result] = v10;
      invulnerable[result] = v21;
      if (v10 == v20) {
        LOWORD(player1_car) = result;
        ViewType[0] = result;
      }
      if (player_type == 2 && v10 == player2_car) {
        player2_car = result;
        ViewType_variable_1 = result;
      }
      ++v11;
      ++v10;
      v38 += 9;
    } while (v10 < players);
  }
  if (game_type != 1 || !Race) {
    if (numcars > 0) {
      v22 = 4 * numcars;
      v23 = 0;
      do {
        v23 += 4;
        TrackArrow_variable_1[v23 / 4u] = 0;
      } while (v23 < v22);
    }
    result = competitors[0];
    v24 = 4 * numcars;
    if (competitors[0] < 2u) {
      if (competitors[0] == 1 && numcars > 0) {
        result = 0;
        do {
          if (!*(int *)((char *)human_control + result))
            *(int *)((char *)non_competitors + result) = -1;
          result += 4;
        } while (result < v24);
      }
    } else if (competitors[0] <= 2u) {
      if (numcars > 0) {
        result = 0;
        do {
          if (!*(int *)((char *)human_control + result))
            *(int *)((char *)non_competitors + result) = -1;
          result += 4;
        } while (result < v24);
      }
      if (players == 1) {
        do {
          v25 = rand(result);
          v26 = (8 * v25 - (__CFSHL__((8 * v25) >> 31, 15) + ((8 * v25) >> 31 << 15))) >> 15;
          if (v26 == 8)
            v26 = 7;
          result = 8 * v26;
        } while (*(int *)((char *)human_control + result));
        *(int *)((char *)&non_competitors_variable_1 + result) = 0;
      }
    } else if (competitors[0] == 8) {
      if (numcars > 0) {
        result = 0;
        do {
          if (!*(int *)((char *)human_control + result))
            *(int *)((char *)non_competitors + result) = -1;
          result += 4;
        } while (result < v24);
      }
      if (players < 8) {
        v27 = players;
        while (1) {
          v28 = rand(result);
          v29 = (8 * v28 - (__CFSHL__((8 * v28) >> 31, 15) + ((8 * v28) >> 31 << 15))) >> 15;
          if (v29 == 8)
            v29 = 7;
          result = 8 * v29;
          if (!*(int *)((char *)human_control + result)) {
            if (*(int *)((char *)&non_competitors_variable_1 + result)) {
              ++v27;
              *(int *)((char *)&non_competitors_variable_1 + result) = 0;
              if (v27 >= 8)
                break;
            }
          }
        }
      }
    }
  }
  if ((cheat_mode & 0x200) != 0) {
    v30 = 0;
    if (numcars > 0) {
      v31 = driver_names;
      v32 = 0;
      do {
        if (!human_control[v32]) {
          v33 = &aMrEvil[2];
          v34 = v31;
          Drivers_Car[v32] = 13;
          do {
            ++v34;
            v35 = *v33++;
            *(v34 - 1) = v35;
          } while (v33 != &aMrEvil[11]);
        }
        result = numcars;
        ++v32;
        ++v30;
        v31 += 9;
      } while (v30 < numcars);
    }
  }
  v36 = 0;
  if (numcars > 0) {
    v37 = numcars;
    result = 0;
    do {
      if (*(int *)((char *)human_control + result))
        player_to_car[*(int *)((char *)car_to_player + result)] = v36;
      ++v36;
      result += 4;
    } while (v36 < v37);
  }
  return result;
}

//-------------------------------------------------------------------------------------------------

int __fastcall check_cars(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // edx
  int v5; // edi
  int v6; // ebx

  _STOSD(allocated_cars, 0, a3, 14);
  result = player_type;
  if (!player_type) {
    players = 1;
    goto LABEL_8;
  }
  if ((unsigned int)player_type <= 1) {
    result = network_on;
    goto LABEL_7;
  }
  if (player_type == 2)
    LABEL_7:
  players = result;
LABEL_8:
  v4 = 0;
  if (players > 0) {
    result = 0;
    do {
      v5 = *(int *)((char *)Players_Cars + result);
      if (v5 >= 0) {
        if ((cheat_mode & 0x4000) == 0)
          ++allocated_cars[v5];
        v6 = *(int *)((char *)Players_Cars + result);
        if (allocated_cars[v6] == 1)
          car_to_player[2 * v6] = v4;
        else
          car_to_player_variable_1[2 * v6] = v4;
      }
      result += 4;
      ++v4;
    } while (v4 < players);
  }
  return result;
}

//-------------------------------------------------------------------------------------------------

char *select_messages()
{
  char *result; // eax
  int v2; // edi
  int v3; // esi
  unsigned int v4; // ecx
  char v5; // al
  unsigned int v6; // ecx
  unsigned int v7; // edi
  char *v8; // ebx
  int v9; // ecx
  char *v10; // edx
  char *v11; // eax
  char v12; // al
  int v13; // esi
  char *v14; // edi
  char v15; // al
  int v16; // eax
  unsigned int v17; // eax
  int v18; // ebx
  unsigned int v19; // eax
  int j; // eax
  int i; // eax
  int v23; // [esp+4h] [ebp-1Ch]
  int v24; // [esp+8h] [ebp-18h]
  unsigned int v25; // [esp+Ch] [ebp-14h]
  unsigned int v26; // [esp+Ch] [ebp-14h]
  int v27; // [esp+10h] [ebp-10h]
  int v28; // [esp+14h] [ebp-Ch]
  int v29; // [esp+18h] [ebp-8h]
  int v30; // [esp+1Ch] [ebp-4h]

  v29 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  send_status = 0;
  send_message_to = -1;
  v23 = 0;
  v24 = 0;
  if (send_buffer[0]) {
    while (send_buffer[++v24])
      ;
  }
  result = &player_names[9];
LABEL_4:
  if (!v29) {
    if (v27 < 0 || v27 >= network_on)
      v27 = 0;
    v2 = scrbuf;
    v3 = front_vga[0];
    if (SVGA_ON)
      v4 = 256000;
    else
      v4 = 64000;
    v5 = v4;
    v6 = v4 >> 2;
    qmemcpy((void *)scrbuf, (const void *)front_vga[0], 4 * v6);
    qmemcpy((void *)(v2 + 4 * v6), (const void *)(v3 + 4 * v6), v5 & 3);
    display_block(scrbuf, front_vga_variable_1, 3, head_x, head_y, 0);
    display_block(scrbuf, front_vga_variable_6, 0, 0x24u, 2, 0);
    display_block(scrbuf, front_vga_variable_5, 1, 0xFFFFFFFC, 247, 0);
    display_block(scrbuf, front_vga_variable_5, game_type + 5, 0x87u, 247, 0);
    v7 = v25;
    display_block(scrbuf, front_vga_variable_4, 4, 0x4Cu, 257, -1);
    if (v25) {
      v26 = v25 - 1;
      if ((int)(v7 - 1) >= 3) {
        display_block(scrbuf, front_vga_variable_6, 4, 0x3Eu, 336, -1);
      } else {
        display_block(scrbuf, front_vga_variable_6, 2, 0x3Eu, 336, -1);
        front_text(
          front_vga_variable_2,
          (unsigned __int8 *)asc_A2400,
          (int)&font2_ascii,
          (int)&font2_offsets,
          sel_posns[4 * v26],
          sel_posns_variable_1[4 * v26],
          143,
          0);
      }
      v25 = v26 + 1;
    } else if (v28 >= 3) {
      display_block(scrbuf, front_vga_variable_6, 4, 0x3Eu, 336, -1);
    } else {
      display_block(scrbuf, front_vga_variable_6, 2, 0x3Eu, 336, -1);
      front_text(
        front_vga_variable_2,
        (unsigned __int8 *)asc_A2400,
        (int)&font2_ascii,
        (int)&font2_offsets,
        sel_posns[4 * v28],
        sel_posns_variable_1[4 * v28],
        143,
        0);
    }
    front_text(
      front_vga_variable_2,
      language_buffer_variable_110,
      (int)&font2_ascii,
      (int)&font2_offsets,
      sel_posns[0] + 132,
      sel_posns_variable_1[0] + 7,
      143,
      2u);
    front_text(
      front_vga_variable_2,
      language_buffer_variable_111,
      (int)&font2_ascii,
      (int)&font2_offsets,
      sel_posns_variable_4 + 132,
      sel_posns_variable_5 + 7,
      143,
      2u);
    v8 = (char *)&font2_ascii;
    front_text(
      front_vga_variable_2,
      language_buffer_variable_112,
      (int)&font2_ascii,
      (int)&font2_offsets,
      sel_posns_variable_8 + 132,
      sel_posns_variable_9 + 7,
      143,
      2u);
    v9 = v25;
    v10 = (char *)v25;
    v11 = &player_names[9 * v27];
    switch (v25) {
      case 0u:
        if (v27)
          sprintf(buffer, "%s", &player_names[9 * v27]);
        else
          sprintf(buffer, "%s", language_buffer_variable_113);
        scale_text(front_vga_variable_10, buffer, (int)font1_ascii, (int)&font1_offsets, 190, 66, 143, 0, 180, 640);
        v10 = send_buffer;
        v8 = font1_ascii;
        v9 = (int)&font1_offsets;
        LOBYTE(v11) = scale_text(
                        front_vga_variable_10,
                        send_buffer,
                        (int)font1_ascii,
                        (int)&font1_offsets,
                        190,
                        110,
                        143,
                        0,
                        180,
                        640);
        if (send_status > 0)
          goto LABEL_24;
        if (send_status)
          goto LABEL_50;
        if (v23) {
          v9 = 2;
          v25 = send_status;
          v23 = send_status;
          v28 = 2;
        }
        goto LABEL_52;
      case 1u:
        scale_text(
          front_vga_variable_10,
          language_buffer_variable_114,
          (int)&font2_ascii,
          (int)&font2_offsets,
          400,
          60,
          143,
          1u,
          200,
          640);
        if (v28)
          v12 = -113;
        else
          v12 = -85;
        v10 = language_buffer_variable_113;
        v8 = (char *)&font2_ascii;
        v9 = (int)&font2_offsets;
        v13 = 1;
        LOBYTE(v11) = scale_text(
                        front_vga_variable_10,
                        language_buffer_variable_113,
                        (int)&font2_ascii,
                        (int)&font2_offsets,
                        400,
                        98,
                        v12,
                        1u,
                        200,
                        640);
        if (network_on > 1) {
          v14 = &player_names[9];
          v30 = 116;
          do {
            if (v13 == v28)
              v15 = -85;
            else
              v15 = -113;
            v8 = (char *)&font2_ascii;
            v9 = (int)&font2_offsets;
            LOBYTE(v11) = scale_text(
                            front_vga_variable_10,
                            v14,
                            (int)&font2_ascii,
                            (int)&font2_offsets,
                            400,
                            v30,
                            v15,
                            1u,
                            200,
                            640);
            ++v13;
            v10 = (char *)(v30 + 18);
            v14 += 9;
            v30 += 18;
          } while (v13 < network_on);
        }
        goto LABEL_52;
      case 2u:
        scale_text(
          front_vga_variable_10,
          language_buffer_variable_115,
          (int)&font2_ascii,
          (int)&font2_offsets,
          400,
          60,
          143,
          1u,
          200,
          640);
        if ((frames & 0xFu) < 8) {
          v16 = stringwidth(send_buffer) + 190;
          if (v16 <= 620)
            scale_text(
              front_vga_variable_10,
              &aI_5[2],
              (int)font1_ascii,
              (int)&font1_offsets,
              v16,
              110,
              171,
              0,
              180,
              640);
          else
            scale_text(
              front_vga_variable_10,
              &aI_5[2],
              (int)font1_ascii,
              (int)&font1_offsets,
              621,
              110,
              171,
              0,
              180,
              640);
        }
        v10 = send_buffer;
        v8 = font1_ascii;
        v9 = (int)&font1_offsets;
        LOBYTE(v11) = scale_text(
                        front_vga_variable_10,
                        send_buffer,
                        (int)font1_ascii,
                        (int)&font1_offsets,
                        190,
                        110,
                        143,
                        0,
                        180,
                        630);
        goto LABEL_52;
      case 3u:
        if (v27)
          sprintf(buffer, "%s", &player_names[9 * v27]);
        else
          sprintf(buffer, "%s", language_buffer_variable_113);
        scale_text(front_vga_variable_10, buffer, (int)font1_ascii, (int)&font1_offsets, 190, 66, 143, 0, 180, 640);
        scale_text(
          front_vga_variable_10,
          send_buffer,
          (int)font1_ascii,
          (int)&font1_offsets,
          190,
          110,
          143,
          0,
          180,
          640);
        v10 = language_buffer_variable_116;
        v8 = (char *)&font2_ascii;
        v9 = (int)&font2_offsets;
        scale_text(
          front_vga_variable_10,
          language_buffer_variable_116,
          (int)&font2_ascii,
          (int)&font2_offsets,
          400,
          150,
          143,
          1u,
          200,
          640);
        if (send_status > 0) {
        LABEL_24:
          v10 = (char *)&language_buffer_variable_117;
        } else {
          v11 = (char *)send_status;
          if (!send_status) {
            if (v23) {
              v25 = send_status;
              v23 = send_status;
              v28 = 2;
            }
            goto LABEL_52;
          }
        LABEL_50:
          v10 = (char *)&language_buffer_variable_118;
        }
        v8 = (char *)&font2_ascii;
        v9 = (int)&font2_offsets;
        LOBYTE(v11) = scale_text(
                        front_vga_variable_10,
                        v10,
                        (int)&font2_ascii,
                        (int)&font2_offsets,
                        400,
                        180,
                        231,
                        1u,
                        200,
                        640);
        --send_status;
      LABEL_52:
        show_received_mesage(v11, v10, v8, v9);
        copypic((char *)scrbuf, (int)screen);
        while (1) {
          result = (char *)fatkbhit();
          if (!result)
            goto LABEL_4;
          v17 = fatgetch();
          v18 = v17;
          if (v17 < 8) {
            if (v17)
              goto LABEL_95;
            v19 = fatgetch();
            if (v19 >= 0x48) {
              if (v19 <= 0x48) {
                if (v25 <= 1 && v28 > 0)
                  --v28;
              } else if (v19 == 80) {
                if (v25) {
                  if (v25 == 1 && network_on - 1 > v28)
                    ++v28;
                } else if (v28 < 3) {
                  ++v28;
                }
              }
            }
          } else if (v17 <= 8) {
            if (v25 == 2 && v24 > 0) {
              send_buffer[v24--] = 0;
              send_buffer[v24] = 0;
            }
            if (v25 == 3 && !v23) {
              v25 = 0;
              v28 = 2;
            }
          } else if (v17 < 0xD) {
          LABEL_95:
            if (v25 == 3 && !v23) {
              if (v17 == 121 || v17 == 89) {
                v23 = -1;
                send_message_to = v27;
                for (i = 0; i < 32; rec_mes_buf_variable_8[i] = round_pics_variable_8[i]) {
                  i += 8;
                  rec_mes_buf_variable_1[i] = round_pics_variable_1[i];
                  rec_mes_buf_variable_2[i] = round_pics_variable_2[i];
                  rec_mes_buf_variable_3[i] = round_pics_variable_3[i];
                  rec_mes_buf_variable_4[i] = round_pics_variable_4[i];
                  rec_mes_buf_variable_5[i] = round_pics_variable_5[i];
                  rec_mes_buf_variable_6[i] = round_pics_variable_6[i];
                  rec_mes_buf_variable_7[i] = round_pics_variable_7[i];
                }
              } else {
                v25 = 0;
                v28 = 2;
              }
            }
            if (v25 == 2 && v24 < 30) {
              if (keys_variable_3 || keys_variable_4) {
                switch (v18) {
                  case '#':
                    v18 = 126;
                    break;
                  case '\'':
                    v18 = 64;
                    break;
                  case ',':
                    v18 = 60;
                    break;
                  case '-':
                    v18 = 95;
                    break;
                  case '.':
                    v18 = 62;
                    break;
                  case '/':
                    v18 = 63;
                    break;
                  case '0':
                    v18 = 41;
                    break;
                  case '1':
                    v18 = 33;
                    break;
                  case '2':
                    v18 = 34;
                    break;
                  case '3':
                    v18 = 156;
                    break;
                  case '4':
                    v18 = 36;
                    break;
                  case '5':
                    v18 = 37;
                    break;
                  case '6':
                    v18 = 94;
                    break;
                  case '7':
                    v18 = 38;
                    break;
                  case '8':
                    v18 = 42;
                    break;
                  case '9':
                    v18 = 40;
                    break;
                  case ';':
                    v18 = 58;
                    break;
                  case '=':
                    v18 = 43;
                    break;
                  default:
                    break;
                }
              }
              if (v18 >= 97 && v18 <= 122)
                v18 -= 32;
              if (v18 != 127) {
                send_buffer[v24++] = v18;
                send_buffer[v24] = 0;
              }
            }
          } else if (v17 <= 0xD) {
            if (v25 <= 3) {
              switch (v25) {
                case 0u:
                  v25 = v28 + 1;
                  switch (v28) {
                    case 0:
                      v28 = v27;
                      break;
                    case 1:
                      v24 = 0;
                      if (send_buffer[0]) {
                        while (send_buffer[++v24])
                          ;
                      }
                      break;
                    case 2:
                      v23 = -1;
                      send_message_to = v27;
                      for (j = 0; j < 32; rec_mes_buf_variable_8[j] = round_pics_variable_8[j]) {
                        j += 8;
                        rec_mes_buf_variable_1[j] = round_pics_variable_1[j];
                        rec_mes_buf_variable_2[j] = round_pics_variable_2[j];
                        rec_mes_buf_variable_3[j] = round_pics_variable_3[j];
                        rec_mes_buf_variable_4[j] = round_pics_variable_4[j];
                        rec_mes_buf_variable_5[j] = round_pics_variable_5[j];
                        rec_mes_buf_variable_6[j] = round_pics_variable_6[j];
                        rec_mes_buf_variable_7[j] = round_pics_variable_7[j];
                      }
                      v25 = 0;
                      break;
                    case 3:
                      goto LABEL_77;
                    default:
                      continue;
                  }
                  break;
                case 1u:
                  v25 = 0;
                  v27 = v28;
                  v28 = 0;
                  break;
                default:
                  continue;
              }
            }
          } else {
            if (v17 != 27)
              goto LABEL_95;
            if (v25)
              v25 = 0;
            else
              LABEL_77:
            v29 = -1;
          }
        }
      default:
        goto LABEL_52;
    }
  }
  return result;
}

//-------------------------------------------------------------------------------------------------

void show_received_mesage()
{
  int v0; // ebx
  int v1; // eax
  int v2; // ecx
  int v3; // edx
  int v4; // ecx

  if (rec_status > 0 && front_fade) {
    sprintf(buffer, "%s %s", language_buffer_variable_119, rec_mes_name);
    v0 = stringwidth(rec_mes_buf);
    v1 = stringwidth(buffer);
    if (v1 > v0)
      v0 = v1;
    v2 = 400 - v0 / 2;
    if (v2 < 180)
      v2 = 180;
    v3 = v0 / 2 + 408;
    v4 = v2 - 8;
    if (v3 > 639)
      v3 = 639;
    blankwindow(v4 / 2, 86, v3 / 2, 118);
    scale_text(front_vga_variable_10, buffer, (int)font1_ascii, (int)&font1_offsets, 400, 180, 143, 1u, 180, 640);
    scale_text(front_vga_variable_10, rec_mes_buf, (int)font1_ascii, (int)&font1_offsets, 400, 210, 143, 1u, 180, 640);
    copypic((char *)scrbuf, (int)screen);
    rec_status = 0;
    frames = 0;
    do {
      if (time_to_start)
        break;
      while (fatkbhit()) {
        if (!fatgetch())
          fatgetch();
      }
    } while (frames < 72);
    if (frames >= 72 && !time_to_start) {
      while (!fatkbhit() && !time_to_start)
        ;
      while (fatkbhit() && !time_to_start) {
        if (!fatgetch())
          fatgetch();
      }
    }
    frames = 0;
  }
}

//-------------------------------------------------------------------------------------------------

int select_netslot()
{
  int v0; // ebx
  int v1; // esi
  int v2; // ebp
  int v3; // edx
  int i; // eax
  char v5; // bl
  int v6; // edx
  int v7; // eax
  int v8; // edi
  int v9; // esi
  unsigned int v10; // ecx
  char v11; // al
  unsigned int v12; // ecx
  _BYTE *v13; // esi
  int v14; // edi
  int v15; // edi
  _BYTE *v16; // esi
  _BYTE *v17; // esi
  int v18; // edi
  int v19; // edi
  _BYTE *v20; // esi
  unsigned int v21; // eax
  int v22; // ebx
  unsigned int v23; // eax
  int v24; // edx
  int v25; // eax
  int v26; // edx
  int v27; // eax
  int v29; // [esp+0h] [ebp-4Ch]
  int v30; // [esp+4h] [ebp-48h]
  int v31; // [esp+8h] [ebp-44h]
  _DWORD v32[3]; // [esp+Ch] [ebp-40h]
  char v33; // [esp+18h] [ebp-34h]
  int v34; // [esp+1Ch] [ebp-30h]
  int v35; // [esp+20h] [ebp-2Ch]
  int v36; // [esp+24h] [ebp-28h]
  int v37; // [esp+28h] [ebp-24h]
  int v38; // [esp+2Ch] [ebp-20h]
  int v39; // [esp+30h] [ebp-1Ch]

  v36 = 0;
  network_slot = -1;
  v35 = -1;
  Initialise_Network(-1);
  if (network_on) {
    v35 = 0;
    v0 = 0;
    v1 = 7;
    v2 = 0;
    v33 = 0;
    v30 = 131;
    v31 = 131;
    v32[0] = 131;
    v29 = 171;
    do {
      *((_BYTE *)&v32[1] + v1--) = v0 % 10 + 48;
      v0 /= 10;
    } while (v0 > 0);
    v3 = 0;
    for (i = v1 + 1; i < 8; *((_BYTE *)v32 + v3 + 3) = v5) {
      ++v3;
      v5 = *((_BYTE *)&v32[1] + i++);
    }
    while (1) {
      if (v36)
        return v35;
      v6 = 0;
      v7 = 0;
      do {
        if (gamers_playing[v7] == 16) {
          if (v6 == v2)
            *(int *)((char *)&v29 + v7 * 4) = 168;
          else
            *(int *)((char *)&v29 + v7 * 4) = 127;
        }
        ++v6;
        ++v7;
      } while (v6 < 4);
      v8 = scrbuf;
      v9 = front_vga[0];
      if (SVGA_ON)
        v10 = 256000;
      else
        v10 = 64000;
      v11 = v10;
      v12 = v10 >> 2;
      qmemcpy((void *)scrbuf, (const void *)front_vga[0], 4 * v12);
      qmemcpy((void *)(v8 + 4 * v12), (const void *)(v9 + 4 * v12), v11 & 3);
      display_block(scrbuf, front_vga_variable_1, 3, head_x, head_y, 0);
      display_block(scrbuf, front_vga_variable_6, 0, 0x24u, 2, 0);
      display_block(scrbuf, front_vga_variable_5, 1, 0xFFFFFFFC, 247, 0);
      display_block(scrbuf, front_vga_variable_5, game_type + 5, 0x87u, 247, 0);
      display_block(scrbuf, front_vga_variable_4, 4, 0x4Cu, 257, -1);
      display_block(scrbuf, front_vga_variable_6, 4, 0x3Eu, 336, -1);
      scale_text(
        front_vga_variable_10,
        language_buffer_variable_103,
        (int)font1_ascii,
        (int)&font1_offsets,
        400,
        55,
        143,
        1u,
        200,
        640);
      scale_text(
        front_vga_variable_10,
        language_buffer_variable_104,
        (int)font1_ascii,
        (int)&font1_offsets,
        400,
        73,
        143,
        1u,
        200,
        640);
      sprintf(buffer, "%s1", language_buffer_variable_120);
      scale_text(front_vga_variable_10, buffer, (int)font1_ascii, (int)&font1_offsets, 260, 92, v29, 1u, 200, 320);
      if (gamers_playing[0] < 0) {
        if (gamers_playing[0] == -2) {
          scale_text(
            front_vga_variable_10,
            language_buffer_variable_123,
            (int)font1_ascii,
            (int)&font1_offsets,
            260,
            200,
            v29,
            1u,
            200,
            319);
          goto LABEL_27;
        }
      } else {
        if (gamers_playing[0] <= 0) {
          scale_text(
            front_vga_variable_10,
            language_buffer_variable_121,
            (int)font1_ascii,
            (int)&font1_offsets,
            260,
            200,
            v29,
            1u,
            200,
            319);
          goto LABEL_27;
        }
        if (gamers_playing[0] == 16) {
          scale_text(
            front_vga_variable_10,
            language_buffer_variable_122,
            (int)font1_ascii,
            (int)&font1_offsets,
            260,
            200,
            v29,
            1u,
            200,
            319);
          goto LABEL_27;
        }
      }
      v39 = 0;
      if (gamers_playing[0] > 0) {
        v13 = &gamers_names;
        v14 = 110;
        do {
          scale_text(front_vga_variable_10, v13, (int)font1_ascii, (int)&font1_offsets, 260, v14, v29, 1u, 200, 319);
          v13 += 9;
          v14 += 18;
          ++v39;
        } while (v39 < gamers_playing[0]);
      }
    LABEL_27:
      sprintf(buffer, "%s2", language_buffer_variable_120);
      scale_text(front_vga_variable_10, buffer, (int)font1_ascii, (int)&font1_offsets, 370, 92, v30, 1u, 200, 640);
      if (gamers_playing_variable_1 < 0) {
        if (gamers_playing_variable_1 == -2) {
          scale_text(
            front_vga_variable_10,
            language_buffer_variable_123,
            (int)font1_ascii,
            (int)&font1_offsets,
            370,
            200,
            v30,
            1u,
            321,
            419);
          goto LABEL_38;
        }
      } else {
        if (gamers_playing_variable_1 <= 0) {
          scale_text(
            front_vga_variable_10,
            language_buffer_variable_121,
            (int)font1_ascii,
            (int)&font1_offsets,
            370,
            200,
            v30,
            1u,
            321,
            419);
          goto LABEL_38;
        }
        if (gamers_playing_variable_1 == 16) {
          scale_text(
            front_vga_variable_10,
            language_buffer_variable_122,
            (int)font1_ascii,
            (int)&font1_offsets,
            370,
            200,
            v30,
            1u,
            321,
            419);
          goto LABEL_38;
        }
      }
      v15 = 0;
      if (gamers_playing_variable_1 > 0) {
        v16 = &gamers_names_variable_1;
        v34 = 110;
        do {
          scale_text(front_vga_variable_10, v16, (int)font1_ascii, (int)&font1_offsets, 370, v34, v30, 1u, 321, 419);
          ++v15;
          v16 += 9;
          v34 += 18;
        } while (v15 < gamers_playing_variable_1);
      }
    LABEL_38:
      sprintf(buffer, "%s3", language_buffer_variable_120);
      scale_text(front_vga_variable_10, buffer, (int)font1_ascii, (int)&font1_offsets, 474, 92, v31, 1u, 200, 640);
      if (gamers_playing_variable_2 < 0) {
        if (gamers_playing_variable_2 == -2) {
          scale_text(
            front_vga_variable_10,
            language_buffer_variable_123,
            (int)font1_ascii,
            (int)&font1_offsets,
            474,
            200,
            v31,
            1u,
            421,
            519);
          goto LABEL_49;
        }
      } else {
        if (gamers_playing_variable_2 <= 0) {
          scale_text(
            front_vga_variable_10,
            language_buffer_variable_121,
            (int)font1_ascii,
            (int)&font1_offsets,
            474,
            200,
            v31,
            1u,
            421,
            519);
          goto LABEL_49;
        }
        if (gamers_playing_variable_2 == 16) {
          scale_text(
            front_vga_variable_10,
            language_buffer_variable_122,
            (int)font1_ascii,
            (int)&font1_offsets,
            474,
            200,
            v31,
            1u,
            421,
            519);
          goto LABEL_49;
        }
      }
      v38 = 0;
      if (gamers_playing_variable_2 > 0) {
        v17 = &gamers_names_variable_2;
        v18 = 110;
        do {
          scale_text(front_vga_variable_10, v17, (int)font1_ascii, (int)&font1_offsets, 474, v18, v31, 1u, 421, 519);
          v17 += 9;
          v18 += 18;
          ++v38;
        } while (v38 < gamers_playing_variable_2);
      }
    LABEL_49:
      sprintf(buffer, "%s4", language_buffer_variable_120);
      scale_text(front_vga_variable_10, buffer, (int)font1_ascii, (int)&font1_offsets, 580, 92, v32[0], 1u, 520, 640);
      if (gamers_playing_variable_3 < 0) {
        if (gamers_playing_variable_3 == -2) {
          scale_text(
            front_vga_variable_10,
            language_buffer_variable_123,
            (int)font1_ascii,
            (int)&font1_offsets,
            580,
            200,
            v32[0],
            1u,
            521,
            639);
          goto LABEL_60;
        }
      } else {
        if (gamers_playing_variable_3 <= 0) {
          scale_text(
            front_vga_variable_10,
            language_buffer_variable_121,
            (int)font1_ascii,
            (int)&font1_offsets,
            580,
            200,
            v32[0],
            1u,
            521,
            639);
          goto LABEL_60;
        }
        if (gamers_playing_variable_3 == 16) {
          scale_text(
            front_vga_variable_10,
            language_buffer_variable_122,
            (int)font1_ascii,
            (int)&font1_offsets,
            580,
            200,
            v32[0],
            1u,
            521,
            639);
          goto LABEL_60;
        }
      }
      v19 = 0;
      if (gamers_playing_variable_3 > 0) {
        v20 = &gamers_names_variable_3;
        v37 = 110;
        do {
          scale_text(front_vga_variable_10, v20, (int)font1_ascii, (int)&font1_offsets, 580, v37, v32[0], 1u, 521, 639);
          ++v19;
          v20 += 9;
          v37 += 18;
        } while (v19 < gamers_playing_variable_3);
      }
    LABEL_60:
      show_received_mesage();
      copypic((char *)scrbuf, (int)screen);
      while (fatkbhit()) {
        v21 = fatgetch();
        v22 = v2 + 1;
        if (v21 < 0xD) {
          if (!v21) {
            v23 = fatgetch();
            if (v23 >= 0x4B) {
              if (v23 <= 0x4B) {
                if (v2 > 0) {
                  *(&v29 + v2) = 131;
                  v24 = v2 - 1;
                  if (v2 - 1 > 0) {
                    v25 = v24;
                    do {
                      if (gamers_playing[v25] != 16)
                        break;
                      --v25;
                      --v24;
                    } while (v25 > 0);
                  }
                  if (gamers_playing[v24] < 16)
                    v2 = v24;
                  *(&v29 + v2) = 171;
                }
              } else if (v23 == 77 && v2 < 3) {
                *(&v29 + v2) = 131;
                v26 = v2 + 1;
                if (v22 < 3) {
                  v27 = v22;
                  do {
                    if (gamers_playing[v27] != 16)
                      break;
                    ++v27;
                    ++v26;
                  } while (v27 < 3);
                }
                if (gamers_playing[v26] < 16)
                  v2 = v26;
                *(&v29 + v2) = 171;
              }
            }
          }
        } else if (v21 <= 0xD) {
          if ((unsigned int)gamers_playing[v2] < 0x10) {
            v36 = -1;
            v35 = v2 + 1;
          }
        } else if (v21 == 27) {
          v36 = -1;
          v35 = -2;
        }
      }
    }
  }
  return v35;
}

//-------------------------------------------------------------------------------------------------
