#ifdef ENABLE_SOSMLIB_PSEUDO
//-------------------------------------------------------------------------------------------------

void sosMIDIDone_Start()
{
  ;
}

//-------------------------------------------------------------------------------------------------

bool __fastcall sosMIDISongDone(int a1)
{
  return _wSOSMIDISongActive[a1] == 0;
}

//-------------------------------------------------------------------------------------------------

void sosMIDIDone_End()
{
  ;
}

//-------------------------------------------------------------------------------------------------
#endif