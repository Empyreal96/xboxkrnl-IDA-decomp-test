int __stdcall RtlCompareString(_STRING *String1, _STRING *String2, char CaseInSensitive)
{
  char *v3; // esi
  int v4; // eax
  char *v5; // edi
  int v6; // ecx
  unsigned int v7; // ebx
  char v8; // al
  char v9; // cl
  unsigned __int8 v10; // al
  int v12; // ecx
  int v13; // eax
  int n2; // [esp+Ch] [ebp-4h]
  char c2; // [esp+18h] [ebp+8h]
  int n1; // [esp+1Ch] [ebp+Ch]
  unsigned __int8 c1; // [esp+20h] [ebp+10h]

  v3 = String1->Buffer;
  v4 = String1->Length;
  v5 = String2->Buffer;
  v6 = String2->Length;
  n1 = String1->Length;
  n2 = v6;
  if ( v4 > v6 )
    v4 = v6;
  v7 = (unsigned int)&v3[v4];
  if ( CaseInSensitive )
  {
    while ( (unsigned int)v3 < v7 )
    {
      v8 = *v3;
      v9 = *v5;
      ++v3;
      ++v5;
      c2 = v9;
      if ( v8 != v9 )
      {
        c1 = RtlUpperChar(v8);
        v10 = RtlUpperChar(c2);
        if ( c1 != v10 )
        {
          v12 = v10;
          v13 = c1;
          return v13 - v12;
        }
      }
    }
  }
  else
  {
    while ( (unsigned int)v3 < v7 )
    {
      LOBYTE(v13) = *v3;
      LOBYTE(v12) = *v5;
      ++v3;
      ++v5;
      if ( (_BYTE)v13 != (_BYTE)v12 )
      {
        v12 = (unsigned __int8)v12;
        v13 = (unsigned __int8)v13;
        return v13 - v12;
      }
    }
  }
  return n1 - n2;
}