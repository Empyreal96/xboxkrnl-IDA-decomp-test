void __userpurge D3DK::ShowDump(int *a1@<edi>, unsigned int subch)
{
  D3DK::_FieldDescription *v2; // esi
  int *v3; // edi
  unsigned int v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // ecx
  char v7; // al
  unsigned int v8; // eax
  unsigned int v9; // ebx
  unsigned int v10; // eax
  float f; // ST10_4
  unsigned int v12; // eax
  int *v13; // edi
  unsigned int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // eax
  float v17; // ST10_4
  unsigned int v18; // eax
  unsigned int *v19; // ebx
  int *v20; // edi
  int v21; // ecx
  unsigned int v22; // eax
  int v23; // ecx
  unsigned int *v24; // ebx
  float v25; // ST10_4
  unsigned int v26; // eax
  int *v27; // edi
  int v28; // ecx
  unsigned int v29; // eax
  int v30; // ecx
  unsigned int v31; // eax
  unsigned int v32; // ecx
  unsigned int i; // [esp+18h] [ebp+8h]
  unsigned int ia; // [esp+18h] [ebp+8h]

  if ( subch )
  {
    DbgPrint(a1, "No field description for subchannel %li", subch);
  }
  else
  {
    v2 = D3DK::g_Kelvin;
    DbgPrint(a1, "-----------------------------------------------------------\n");
    do
    {
      v3 = 0;
      if ( !v2->ReplicationCount[0] || !v2->ReplicationCount[1] )
        D3DK::DXGRIP(
          0,
          "Assertion failure: %s",
          "(pField->ReplicationCount[0] != 0) && (pField->ReplicationCount[1] != 0)");
      i = 0;
      if ( v2->ReplicationCount[0] )
      {
        do
        {
          v4 = v2->ReplicationCount[1];
          if ( v4 )
          {
            v5 = v2->Method + (_DWORD)v3 * v2->ReplicationStride[0];
            do
            {
              if ( *(_DWORD *)(4 * (v5 >> 2) - 2146614640) )
                i = 1;
              v5 += v2->ReplicationStride[1];
              --v4;
            }
            while ( v4 );
          }
          v6 = v2->ReplicationCount[0];
          v3 = (int *)((char *)v3 + 1);
        }
        while ( (unsigned int)v3 < v6 );
        if ( i )
        {
          v7 = v2->FieldType;
          if ( v7 < 65 || v7 > 90 )
          {
            if ( v6 <= 1 )
            {
              v24 = (unsigned int *)(4 * (v2->Method >> 2) - 2146614640);
              DbgPrint(v3, "0x%lx - %s\t\t\t0x%lx\n", v2->Method, v2->MethodName, *v24);
              if ( v2->FieldType == 102 )
              {
                DbgPrint(v3, "    %-20s:\t", v2->FieldName);
                v25 = *(float *)v24 * 1000.0;
                v26 = D3DK::FloatToLong(v25);
                DbgPrint(v3, "%li.%03li", v26 / 0x3E8, v26 % 0x3E8);
                DbgPrint(v3, "\n");
              }
              else
              {
                v27 = (int *)&v2->FieldLowBit;
                do
                {
                  v28 = *(v27 - 1);
                  v29 = *v24;
                  if ( v28 != 31 )
                    v29 &= (1 << (v28 + 1)) - 1;
                  DbgPrint(v27, "    %-20s:\t0x%lx\n", *(v27 - 2), v29 >> *v27);
                  v30 = v27[2];
                  v27 += 10;
                }
                while ( v30 == v2->Method );
              }
            }
            else if ( v2->ReplicationCount[1] > 1 || v2->FieldHighBit != 31 || v2->FieldLowBit )
            {
              v13 = 0;
              for ( ia = 0; ; v13 = (int *)ia )
              {
                if ( v2->ReplicationCount[1] <= 1 )
                {
                  v19 = (unsigned int *)(4 * ((v2->Method + (_DWORD)v13 * v2->ReplicationStride[0]) >> 2) - 2146614640);
                  DbgPrint(v13, "0x%lx - %s(%li)\t\t\t0x%lx\n", v2->Method, v2->MethodName, v13, *v19);
                  v20 = (int *)&v2->FieldLowBit;
                  do
                  {
                    v21 = *(v20 - 1);
                    v22 = *v19;
                    if ( v21 != 31 )
                      v22 &= (1 << (v21 + 1)) - 1;
                    DbgPrint(v20, "    %-20s:\t0x%lx\n", *(v20 - 2), v22 >> *v20);
                    v23 = v20[2];
                    v20 += 10;
                  }
                  while ( v23 == v2->Method );
                }
                else
                {
                  if ( v2->FieldHighBit != 31 || v2->FieldLowBit )
                    D3DK::DXGRIP(
                      v13,
                      "Assertion failure: %s",
                      "(pField->FieldHighBit == 31) && (pField->FieldLowBit == 0)");
                  DbgPrint(v13, "0x%lx - %s(%li)\n    %-20s:\t", v2->Method, v2->MethodName, v13, v2->FieldName);
                  v14 = v2->ReplicationCount[1];
                  v15 = 0;
                  if ( v14 )
                  {
                    do
                    {
                      if ( v15 && !(v15 & 3) && v14 == 16 )
                        DbgPrint(v13, "\n\t\t\t\t");
                      v16 = (v2->Method + ia * v2->ReplicationStride[0] + v15 * v2->ReplicationStride[1]) >> 2;
                      if ( v2->FieldType == 102 )
                      {
                        v17 = *(float *)(4 * v16 - 2146614640) * 1000.0;
                        v18 = D3DK::FloatToLong(v17);
                        DbgPrint(v13, "%li.%03li", v18 / 0x3E8, v18 % 0x3E8);
                        DbgPrint(v13, "\t ");
                      }
                      else
                      {
                        DbgPrint(v13, "0x%lx\t", *(_DWORD *)(4 * v16 - 2146614640));
                      }
                      v14 = v2->ReplicationCount[1];
                      ++v15;
                    }
                    while ( v15 < v14 );
                  }
                  DbgPrint(v13, "\n");
                }
                if ( ++ia >= v2->ReplicationCount[0] )
                  break;
              }
            }
            else
            {
              DbgPrint(v3, "0x%lx - %s\n    %-20s:\t", v2->Method, v2->MethodName, v2->FieldName);
              v8 = v2->ReplicationCount[0];
              v9 = 0;
              if ( v8 )
              {
                do
                {
                  if ( v9 && !(v9 & 3) && v8 == 16 )
                    DbgPrint(v3, "\n\t\t\t\t");
                  v10 = (v2->Method + v9 * v2->ReplicationStride[0]) >> 2;
                  if ( v2->FieldType == 102 )
                  {
                    f = *(float *)(4 * v10 - 2146614640) * 1000.0;
                    v12 = D3DK::FloatToLong(f);
                    DbgPrint(v3, "%li.%03li", v12 / 0x3E8, v12 % 0x3E8);
                    DbgPrint(v3, " \t");
                  }
                  else
                  {
                    DbgPrint(v3, "0x%lx\t", *(_DWORD *)(4 * v10 - 2146614640));
                  }
                  v8 = v2->ReplicationCount[0];
                  ++v9;
                }
                while ( v9 < v8 );
              }
              DbgPrint(v3, "\n");
            }
          }
        }
      }
      v31 = v2->Method;
      do
      {
        v32 = v2[1].Method;
        ++v2;
      }
      while ( v32 == v31 );
    }
    while ( v2 < &D3DK::g_Kelvin[488] );
  }
}