int __stdcall RtlUnicodeStringToInteger(_UNICODE_STRING *String, unsigned int Base, unsigned int *Value)
{
  unsigned __int16 *v3; // edx
  unsigned int v4; // edi
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // ax
  unsigned int v7; // ecx
  unsigned __int16 v8; // ax
  unsigned int v10; // esi
  unsigned int v11; // eax
  signed int v12; // [esp-4h] [ebp-30h]
  signed int v13; // [esp-4h] [ebp-30h]
  unsigned __int16 Sign; // [esp+10h] [ebp-1Ch]

  v3 = String->Buffer;
  v4 = (unsigned int)String->Length >> 1;
  if ( v4 )
  {
    while ( 1 )
    {
      --v4;
      v5 = *v3;
      Sign = *v3;
      ++v3;
      if ( v5 > 0x20u )
        break;
      if ( !v4 )
      {
        Sign = 0;
        break;
      }
    }
  }
  else
  {
    v4 = -1;
  }
  v6 = Sign;
  if ( Sign == 45 || Sign == 43 )
  {
    if ( v4 )
    {
      --v4;
      v6 = *v3;
      ++v3;
    }
    else
    {
      v6 = 0;
    }
  }
  v7 = Base;
  if ( !Base )
  {
    Base = 10;
    if ( v6 != 48 )
      goto LABEL_35;
    if ( !v4 )
    {
LABEL_24:
      v6 = 0;
      goto LABEL_35;
    }
    --v4;
    v8 = *v3;
    ++v3;
    if ( v8 == 120 )
    {
      Base = 16;
      v12 = 4;
    }
    else
    {
      if ( v8 != 111 )
      {
        if ( v8 == 98 )
        {
          Base = 2;
          v7 = 1;
        }
        else
        {
          ++v4;
          --v3;
        }
LABEL_22:
        if ( v4 )
        {
          --v4;
          v6 = *v3;
          ++v3;
          goto LABEL_35;
        }
        goto LABEL_24;
      }
      Base = 8;
      v12 = 3;
    }
    v7 = v12;
    goto LABEL_22;
  }
  if ( Base == 2 )
  {
    v7 = 1;
  }
  else
  {
    switch ( Base )
    {
      case 8u:
        v13 = 3;
        break;
      case 0xAu:
        v7 = 0;
        goto LABEL_35;
      case 0x10u:
        v13 = 4;
        break;
      default:
        return -1073741811;
    }
    v7 = v13;
  }
LABEL_35:
  v10 = 0;
  while ( v6 )
  {
    if ( v6 < 0x30u || v6 > 0x39u )
    {
      if ( v6 < 0x41u || v6 > 0x46u )
      {
        if ( v6 < 0x61u || v6 > 0x66u )
          break;
        v11 = v6 - 87;
      }
      else
      {
        v11 = v6 - 55;
      }
    }
    else
    {
      v11 = v6 - 48;
    }
    if ( v11 >= Base )
      break;
    v10 = v7 ? v11 | (v10 << v7) : v11 + Base * v10;
    if ( !v4 )
      break;
    --v4;
    v6 = *v3;
    ++v3;
  }
  if ( Sign == 45 )
    v10 = -v10;
  *Value = v10;
  return 0;
}