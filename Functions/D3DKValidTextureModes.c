int __userpurge D3DK::ValidTextureModes@<eax>(int *a1@<edi>, unsigned int val, char *err)
{
  unsigned int v3; // edx
  unsigned int v5; // esi
  unsigned int v6; // ecx
  const char *v7; // [esp-Ch] [ebp-10h]

  v3 = val & 0x1F;
  if ( !((63 >> (val & 0x1F)) & 1) )
  {
    DbgPrint(a1, "%s: %s", err, "Invalid Stg 0 Mode");
    D3DK::DXGRIP(a1, byte_80014442);
    return 0;
  }
  v5 = (val >> 5) & 0x1F;
  if ( !((229631 >> ((val >> 5) & 0x1F)) & 1) )
  {
    v7 = "Invalid Stg 1 Mode";
LABEL_62:
    DbgPrint(a1, "%s: %s", err, v7);
    goto LABEL_63;
  }
  a1 = (int *)((val >> 10) & 0x1F);
  if ( (233471 >> ((val >> 10) & 0x1F)) & 1 )
  {
    v6 = (val >> 15) & 0x1F;
    if ( !((391167 >> v6) & 1) )
    {
      DbgPrint(a1, "%s: %s", err, "Invalid Stg 3 Mode");
      goto LABEL_63;
    }
    if ( val & 0xFFF00000 )
    {
      v7 = "31:20 must be 0";
      goto LABEL_62;
    }
    if ( (v5 == 6 || v5 == 7 || v5 == 15 || v5 == 16 || v5 == 17) && (v3 == 5 || !(val & 0x1F)) )
    {
      v7 = "Stg1 mode requires different Stg0 mode";
      goto LABEL_62;
    }
    if ( a1 == (int *)8 && (!(val & 0x1F) || v3 == 5) )
    {
      DbgPrint((int *)8, "%s: %s", err, "Stg2 mode requires different Stg0 mode");
      goto LABEL_63;
    }
    if ( v6 == 8 && (!v5 || v5 == 5 || v5 == 17) )
    {
      DbgPrint(a1, "%s: %s", err, "Stg3 mode requires different Stg1 mode");
      goto LABEL_63;
    }
    if ( a1 == (int *)9 && v5 != 17 )
    {
      v7 = "Stg2 mode requires DOTPRODUCT in Stg1";
      goto LABEL_62;
    }
    if ( v6 == 9 && a1 != (int *)17 )
    {
      DbgPrint(a1, "%s: %s", err, "Stg3 mode requires DOTPRODUCT in Stg2");
      goto LABEL_63;
    }
    if ( a1 == (int *)10 && v5 != 17 )
    {
      DbgPrint((int *)0xA, "%s: %s", err, "Stg2 mode requires DOTPRODUCT in Stg1");
      goto LABEL_63;
    }
    switch ( v6 )
    {
      case 0xAu:
        if ( a1 != (int *)17 )
        {
          v7 = "Stg3 mode requires DOTPRODUCT in Stg2";
          goto LABEL_62;
        }
        goto LABEL_52;
      case 0xDu:
        if ( a1 != (int *)17 || v5 != 17 )
        {
          DbgPrint(a1, "%s: %s", err, "Stg3 mode requires DOTPRODUCT in Stg2 or Stg1");
          goto LABEL_63;
        }
        break;
      case 0xEu:
        if ( a1 != (int *)17 || v5 != 17 )
        {
          DbgPrint(a1, "%s: %s", err, "Stg3 mode requires DOTPRODUCT in Stg2 or Stg1");
          goto LABEL_63;
        }
        break;
      default:
        if ( (v6 == 12 || v6 == 18) && a1 != (int *)17 )
        {
          if ( a1 != (int *)11 )
          {
            v7 = "Stg3 mode requires DOTPRODUCT or DOT_RFLCT_DIFF in Stg2";
            goto LABEL_62;
          }
LABEL_53:
          if ( v6 == 12 )
          {
LABEL_58:
            if ( v5 != 17 )
            {
              DbgPrint(a1, "%s: %s", err, "Stg 3 mode requires DOTPRODUCT in Stg 1");
              goto LABEL_63;
            }
            return 1;
          }
          if ( v6 != 18 )
          {
            DbgPrint(a1, "%s: %s", err, "Stg2 mode requires DOT_RFLCT_SPEC or DOT_RFLCT_SPEC_CONST in Stg 3");
            goto LABEL_63;
          }
LABEL_56:
          if ( v6 != 12 && v6 != 18 )
            return 1;
          goto LABEL_58;
        }
LABEL_52:
        if ( a1 != (int *)11 )
          goto LABEL_56;
        goto LABEL_53;
    }
    return 1;
  }
  DbgPrint(a1, "%s: %s", err, "Invalid Stg 2 Mode");
LABEL_63:
  D3DK::DXGRIP(a1, byte_80014442);
  return 0;
}