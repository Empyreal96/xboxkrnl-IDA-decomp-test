int __stdcall KiComputeTimerTableIndex(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // kr00_8

  v3 = a2 - a1;
  *(_QWORD *)(a3 + 16) = a2 - a1;
  return ((((unsigned int)KiTimeIncrementReciprocal.HighPart * (unsigned __int64)(unsigned int)v3 >> 32)
         + (KiTimeIncrementReciprocal.LowPart * (unsigned __int64)HIDWORD(v3) >> 32)
         + (((KiTimeIncrementReciprocal.LowPart * (unsigned __int64)(unsigned int)(a2 - a1) >> 32)
           + (unsigned int)(KiTimeIncrementReciprocal.HighPart * (a2 - a1))
           + (unsigned __int64)(KiTimeIncrementReciprocal.LowPart * HIDWORD(v3))) >> 32)
         + (unsigned int)KiTimeIncrementReciprocal.HighPart * (unsigned __int64)HIDWORD(v3)) >> KiTimeIncrementShiftCount) & 0x1F;
}