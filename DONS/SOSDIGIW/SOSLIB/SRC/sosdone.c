
void sosDIGIDone_Start()
{
  ;
}

//-------------------------------------------------------------------------------------------------

int __fastcall sosDIGISampleDone(int a1, unsigned int a2)
{
  if (a2 >= 0x20)
    return 10;
  else
    return ((__readgsword(*(_DWORD *)&_lpSOSSampleList[192 * a1 + 6 * a2] + 48) >> 8) & 0x80u) == 0;
}

//-------------------------------------------------------------------------------------------------

int __fastcall sosDIGISampleFilling(int a1, unsigned int a2)
{
  if (a2 >= 0x20)
    return 10;
  if ((__readgsbyte(*(_DWORD *)&_lpSOSSampleList[192 * a1 + 6 * a2] + 49) & 0x10) != 0)
    return 0;
  return ((__readgsword(*(_DWORD *)&_lpSOSSampleList[192 * a1 + 6 * a2] + 48) >> 8) & 0x80u) != 0;
}

//-------------------------------------------------------------------------------------------------

void sosDIGIDone_End()
{
  ;
}

//-------------------------------------------------------------------------------------------------