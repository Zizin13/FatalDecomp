
//-------------------------------------------------------------------------------------------------

void sosDIGIRate_Start()
{
  ;
}

//-------------------------------------------------------------------------------------------------

int __fastcall sosDIGISetOutputRate(int a1, int a2)
{
  if (!_wSOSDriverLoaded[a1])
    return 1;
  _wSOSOutputRate[a1] = a2;
  return 0;
}

//-------------------------------------------------------------------------------------------------

void sosDIGIRate_End()
{
  ;
}

//-------------------------------------------------------------------------------------------------