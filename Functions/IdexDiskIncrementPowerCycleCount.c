void __usercall IdexDiskIncrementPowerCycleCount(int a1@<edx>, int a2@<ecx>, int *a3@<edi>)
{
  int *v3; // eax
  int v4; // edx
  int v5; // ecx
  int *v6; // eax
  _XBOX_REFURB_INFO RefurbInfo; // [esp+0h] [ebp-10h]

  if ( !(XboxBootFlags & 0x11) && (XboxGameRegion & 0x80000000) == 0 )
  {
    v3 = ExReadWriteRefurbInfo(a1, a2, a3, &RefurbInfo, 0x10u, 0);
    if ( (signed int)v3 >= 0 )
    {
      ++RefurbInfo.PowerCycleCount;
      v6 = ExReadWriteRefurbInfo(v4, v5, a3, &RefurbInfo, 0x10u, 1);
      if ( (signed int)v6 < 0 )
        DbgPrint(a3, "IDEX: failed to write refurb info (status=%08x).\n", v6);
    }
    else
    {
      DbgPrint(a3, "IDEX: failed to read refurb info (status=%08x).\n", v3);
    }
  }
}