int __stdcall RtlCharToInteger(const char *String, unsigned int Base, unsigned int *Value)
{
  const char *v3; // esi
  char i; // bl
  const char *v5; // esi
  char v6; // al
  unsigned int v7; // edi
  signed int v8; // ecx
  char v9; // al
  _BYTE *v10; // esi
  int v12; // edx
  unsigned int v13; // eax
  signed int v14; // [esp-4h] [ebp-2Ch]
  signed int v15; // [esp-4h] [ebp-2Ch]

  v3 = String;
  for ( i = *String; ; i = *v3 )
  {
    if ( i > 32 )
    {
      v5 = v3 + 1;
      goto LABEL_6;
    }
    if ( !*++v3 )
      break;
  }
  v5 = v3 - 1;
LABEL_6:
  v6 = i;
  if ( i == 45 || i == 43 )
    v6 = *v5++;
  v7 = Base;
  if ( !Base )
  {
    v7 = 10;
    v8 = 0;
    if ( v6 != 48 )
      goto LABEL_31;
    v9 = *v5;
    v10 = v5 + 1;
    if ( v9 == 120 )
    {
      v7 = 16;
      v14 = 4;
    }
    else
    {
      if ( v9 != 111 )
      {
        if ( v9 == 98 )
        {
          v7 = 2;
          v8 = 1;
        }
        else
        {
          --v10;
        }
        goto LABEL_20;
      }
      v7 = 8;
      v14 = 3;
    }
    v8 = v14;
LABEL_20:
    v6 = *v10;
    v5 = v10 + 1;
    goto LABEL_31;
  }
  if ( Base == 2 )
  {
    v8 = 1;
  }
  else
  {
    switch ( Base )
    {
      case 8u:
        v15 = 3;
        break;
      case 0xAu:
        v8 = 0;
        goto LABEL_31;
      case 0x10u:
        v15 = 4;
        break;
      default:
        return -1073741811;
    }
    v8 = v15;
  }
LABEL_31:
  v12 = 0;
  while ( v6 )
  {
    if ( v6 < 48 || v6 > 57 )
    {
      if ( v6 < 65 || v6 > 70 )
      {
        if ( v6 < 97 || v6 > 102 )
          break;
        v13 = v6 - 87;
      }
      else
      {
        v13 = v6 - 55;
      }
    }
    else
    {
      v13 = v6 - 48;
    }
    if ( v13 >= v7 )
      break;
    if ( v8 )
      v12 = v13 | (v12 << v8);
    else
      v12 = v13 + v7 * v12;
    v6 = *v5++;
  }
  if ( i == 45 )
    v12 = -v12;
  *Value = v12;
  return 0;
}