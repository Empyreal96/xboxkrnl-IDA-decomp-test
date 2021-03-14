int __usercall CMcpxCore::AllocateApuMemory@<eax>(CMcpxCore *this@<ecx>, int *a2@<edi>, int a3@<esi>)
{
  CMcpxCore *thisa; // [esp+0h] [ebp-80h]
  int hr; // [esp+4h] [ebp-7Ch]
  $85C18268D143D6C9D9E7E2C9A248C4F2 Alloc[14]; // [esp+8h] [ebp-78h]
  unsigned int i; // [esp+7Ch] [ebp-4h]

  thisa = this;
  Alloc[0].Size = 0;
  Alloc[0].Alignment = 4096;
  Alloc[1].Size = 0;
  Alloc[1].Alignment = 4096;
  Alloc[2].Size = 4;
  Alloc[2].Alignment = 4096;
  Alloc[3].Size = 0x8000;
  Alloc[3].Alignment = 0x8000;
  Alloc[4].Size = 16416;
  Alloc[4].Alignment = 0x4000;
  Alloc[5].Size = 0x4000;
  Alloc[5].Alignment = 0x4000;
  Alloc[6].Size = 0x10000;
  Alloc[6].Alignment = 0x4000;
  Alloc[7].Size = 0x2000;
  Alloc[7].Alignment = 0x4000;
  Alloc[8].Size = 0x2000;
  Alloc[8].Alignment = 0x4000;
  Alloc[9].Size = 0;
  Alloc[9].Alignment = 0x4000;
  Alloc[10].Size = 0;
  Alloc[10].Alignment = 0x4000;
  Alloc[11].Size = 4096;
  Alloc[11].Alignment = 0x4000;
  Alloc[12].Size = 49152;
  Alloc[12].Alignment = 0x4000;
  Alloc[13].Size = 0;
  Alloc[13].Alignment = 0x4000;
  hr = 0;
  for ( i = 0; i < 1; ++i )
    Alloc[0].Size += *(_DWORD *)(4 * i - 2146508028);
  for ( i = 0; i < 2; ++i )
    Alloc[1].Size += *(_DWORD *)(4 * i - 2146508024);
  Alloc[9].Size = 8 * (Alloc[0].Size >> 12);
  Alloc[10].Size = 8 * (Alloc[1].Size >> 12);
  Alloc[12].Size += 6291456;
  Alloc[13].Size = 8 * (Alloc[12].Size >> 12) + 4096;
  for ( i = 0; i < 0xE && hr >= 0; ++i )
    hr = CMcpxCore::AllocateContext(a2, a3, &thisa->m_ctxMemory[i], Alloc[i].Size, Alloc[i].Alignment, 4u);
  return hr;
}