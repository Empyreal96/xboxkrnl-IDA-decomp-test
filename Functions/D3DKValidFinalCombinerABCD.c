int __userpurge D3DK::ValidFinalCombinerABCD@<eax>(int *a1@<edi>, unsigned int val, char *err)
{
  unsigned int v3; // eax
  unsigned int v4; // ecx
  int *v6; // edi
  unsigned int v7; // esi
  unsigned int v8; // edx
  unsigned int vala; // [esp+8h] [ebp+8h]

  v3 = val;
  v4 = (val >> 24) & 0xF;
  if ( (v4 == 14 || v4 == 15) && val & 0x10000000 )
  {
    DbgPrint(a1, "%s: %s", err, "Alpha invalid for SUM or PROD on A");
    D3DK::DXGRIP(a1, byte_80014442);
    return 0;
  }
  v6 = (int *)((val >> 16) & 0xF);
  if ( (v6 == (int *)14 || v6 == (int *)15) && v3 & 0x100000 )
  {
    DbgPrint(v6, "%s: %s", err, "Alpha invalid for SUM or PROD on B");
    D3DK::DXGRIP(v6, byte_80014442);
    return 0;
  }
  v7 = (val >> 8) & 0xF;
  if ( (v7 == 14 || v7 == 15) && v3 & 0x1000 )
  {
    DbgPrint(v6, "%s: %s", err, "Alpha invalid for SUM or PROD on C");
    D3DK::DXGRIP(v6, byte_80014442);
    return 0;
  }
  v8 = val & 0xF;
  vala = val & 0xF;
  if ( (v8 == 14 || v8 == 15) && v3 & 0x10 )
  {
    DbgPrint(v6, "%s: %s", err, "Alpha invalid for SUM or PROD on D");
LABEL_17:
    D3DK::DXGRIP(v6, byte_80014442);
    return 0;
  }
  if ( !((65343 >> v4) & 1) )
  {
    DbgPrint(v6, "%s: %s", err, "Invalid A Register");
    goto LABEL_17;
  }
  if ( !((65343 >> (BYTE2(v3) & 0xF)) & 1) )
  {
    DbgPrint(v6, "%s: %s", err, "Invalid B Register");
    goto LABEL_17;
  }
  if ( !((65343 >> v7) & 1) )
  {
    DbgPrint(v6, "%s: %s", err, "Invalid C Register");
    goto LABEL_17;
  }
  if ( !((65343 >> vala) & 1) )
  {
    DbgPrint(v6, "%s: %s", err, "Invalid D Register");
    goto LABEL_17;
  }
  if ( !((3 >> (v3 >> 29)) & 1) )
  {
    DbgPrint(v6, "%s: %s", err, "Invalid input mapping Reg A");
    goto LABEL_17;
  }
  if ( !((3 >> ((v3 >> 21) & 7)) & 1) )
  {
    DbgPrint(v6, "%s: %s", err, "Invalid input mapping Reg B");
    goto LABEL_17;
  }
  if ( !((3 >> ((unsigned __int16)v3 >> 13)) & 1) )
  {
    DbgPrint(v6, "%s: %s", err, "Invalid input mapping Reg C");
    goto LABEL_17;
  }
  if ( !((3 >> ((unsigned __int8)v3 >> 5)) & 1) )
  {
    DbgPrint(v6, "%s: %s", err, "Invalid input mapping Reg D");
    goto LABEL_17;
  }
  return 1;
}