_IMAGE_BASE_RELOCATION *__userpurge LdrProcessRelocationBlock@<eax>(int *a1@<edi>, int a2@<esi>, unsigned int VA, unsigned int SizeOfBlock, unsigned __int16 *NextOffset, int Diff)
{
  int v6; // edx
  int v7; // ST0C_4
  _IMAGE_BASE_RELOCATION *result; // eax
  unsigned int i; // esi
  _WORD *v10; // ecx
  unsigned int v11; // edx
  int v12; // edx
  int v13; // edx
  int v14; // edx
  int v15; // edx
  int v16; // edx
  int v17; // edx

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a1, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v6, v7, a1, a2, "FALSE", "d:\\xbox-apr03\\private\\ntos\\rtl\\ldrreloc.c", 0x8Cu, 0);
  }
  result = (_IMAGE_BASE_RELOCATION *)NextOffset;
  for ( i = SizeOfBlock; i; result = (_IMAGE_BASE_RELOCATION *)((char *)result + 2) )
  {
    v10 = (_WORD *)(VA + (result->VirtualAddress & 0xFFF));
    v11 = (unsigned int)LOWORD(result->VirtualAddress) >> 12;
    --i;
    if ( v11 )
    {
      v12 = v11 - 1;
      if ( !v12 )
      {
        v17 = Diff + ((unsigned __int16)*v10 << 16);
        goto LABEL_17;
      }
      v13 = v12 - 1;
      if ( v13 )
      {
        v14 = v13 - 1;
        if ( v14 )
        {
          v15 = v14 - 1;
          if ( !v15 )
          {
            result = (_IMAGE_BASE_RELOCATION *)((char *)result + 2);
            --i;
            v17 = SLOWORD(result->VirtualAddress) + Diff + ((unsigned __int16)*v10 << 16) + 0x8000;
LABEL_17:
            *v10 = HIWORD(v17);
            continue;
          }
          v16 = v15 - 2;
          if ( v16 && v16 != 1 )
            return 0;
        }
        else
        {
          *(_DWORD *)v10 += Diff;
        }
      }
      else
      {
        *v10 += Diff;
      }
    }
  }
  return result;
}