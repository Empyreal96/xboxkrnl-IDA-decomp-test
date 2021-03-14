int __stdcall RtlIntegerToChar(unsigned int Value, unsigned int Base, int OutputLength, char *String)
{
  signed int v5; // ebx
  unsigned int v6; // esi
  char *v7; // edi
  unsigned int v8; // eax
  int v9; // edx
  unsigned __int64 v10; // rtt
  signed int v11; // esi
  int v12; // ebx
  bool v13; // zf
  bool v14; // sf
  unsigned __int8 v15; // of
  int v16; // eax
  signed int v17; // [esp-4h] [ebp-54h]
  char Result[33]; // [esp+Ch] [ebp-44h]
  unsigned int Mask; // [esp+30h] [ebp-20h]
  CPPEH_RECORD ms_exc; // [esp+38h] [ebp-18h]

  if ( !Base )
  {
    Base = 10;
    goto LABEL_12;
  }
  if ( Base == 2 )
  {
    v5 = 1;
    goto LABEL_13;
  }
  if ( Base != 8 )
  {
    if ( Base != 10 )
    {
      if ( Base != 16 )
        return -1073741811;
      v17 = 4;
      goto LABEL_9;
    }
LABEL_12:
    v5 = 0;
    goto LABEL_13;
  }
  v17 = 3;
LABEL_9:
  v5 = v17;
LABEL_13:
  if ( v5 )
    v6 = 15 >> (4 - v5);
  else
    v6 = Mask;
  v7 = &Result[32];
  Result[32] = 0;
  v8 = Value;
  do
  {
    if ( v5 )
    {
      v9 = v8 & v6;
      v8 >>= v5;
    }
    else
    {
      v10 = v8;
      v8 /= Base;
      v9 = v10 % Base;
    }
    *--v7 = RtlpIntegerChars[v9];
  }
  while ( v8 );
  v11 = &Result[32] - v7;
  v12 = OutputLength;
  if ( OutputLength < 0 )
  {
    v12 = -OutputLength;
    v15 = __OFSUB__(v11, -OutputLength);
    v13 = v11 == -OutputLength;
    v14 = v11 + OutputLength < 0;
    if ( v11 >= -OutputLength )
      goto LABEL_26;
    v16 = v12 - v11;
    v11 = -OutputLength;
    do
    {
      *--v7 = 48;
      --v16;
    }
    while ( v16 );
  }
  v15 = __OFSUB__(v11, v12);
  v13 = v11 == v12;
  v14 = v11 - v12 < 0;
LABEL_26:
  if ( !((unsigned __int8)(v14 ^ v15) | v13) )
    return -2147483643;
  ms_exc.registration.TryLevel = 0;
  memmove(String, v7, v11);
  if ( v11 < v12 )
    String[v11] = 0;
  return 0;
}