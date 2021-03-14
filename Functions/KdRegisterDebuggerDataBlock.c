char __stdcall KdRegisterDebuggerDataBlock(unsigned int Tag, _DBGKD_DEBUG_DATA_HEADER64 *DataHeader, unsigned int Size)
{
  KIRQL v3; // al
  _LIST_ENTRY *v4; // esi
  KIRQL v5; // cl
  _LIST_ENTRY *v6; // eax
  bool v7; // zf
  _LIST_ENTRY *v8; // esi
  char v9; // bl

  v3 = KeRaiseIrqlToDpcLevel();
  v4 = KdpDebuggerDataListHead.Flink;
  v5 = v3;
  do
  {
    if ( v4 == &KdpDebuggerDataListHead )
    {
      DataHeader->OwnerTag = Tag;
      DataHeader->Size = Size;
      v8 = KdpDebuggerDataListHead.Blink;
      LODWORD(DataHeader->List.Flink) = &KdpDebuggerDataListHead;
      HIDWORD(DataHeader->List.Flink) = v8;
      v8->Flink = (_LIST_ENTRY *)DataHeader;
      KdpDebuggerDataListHead.Blink = (_LIST_ENTRY *)DataHeader;
      v9 = 1;
      goto LABEL_6;
    }
    v6 = v4;
    v7 = v4 == (_LIST_ENTRY *)DataHeader;
    v4 = v4->Flink;
  }
  while ( !v7 && v6[2].Flink != (_LIST_ENTRY *)Tag );
  v9 = 0;
LABEL_6:
  KfLowerIrql(v5);
  return v9;
}