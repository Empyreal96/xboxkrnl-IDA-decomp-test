void __fastcall KiWaitSatisfyAll(_KWAIT_BLOCK *WaitBlock)
{
  _KWAIT_BLOCK *v1; // eax
  _KTHREAD *v2; // ebx
  _LIST_ENTRY *v3; // eax
  char v4; // dl
  bool v5; // zf
  _LIST_ENTRY *v6; // edx
  _LIST_ENTRY *v7; // edi
  _KWAIT_BLOCK *WaitBlock1; // [esp+10h] [ebp-4h]

  v1 = WaitBlock;
  v2 = WaitBlock->Thread;
  WaitBlock1 = WaitBlock;
  do
  {
    if ( v1->WaitKey != 258 )
    {
      v3 = (_LIST_ENTRY *)v1->Object;
      v4 = (char)v3->Flink;
      if ( ((_DWORD)v3->Flink & 7) == 1 )
      {
        v3->Blink = 0;
      }
      else if ( v4 == 5 )
      {
        --v3->Blink;
      }
      else if ( v4 == 2 )
      {
        v5 = v3->Blink-- == (_LIST_ENTRY *)1;
        if ( v5 )
        {
          v5 = LOBYTE(v3[3].Blink) == 1;
          v3[3].Flink = (_LIST_ENTRY *)v2;
          if ( v5 )
          {
            LOBYTE(v3[3].Blink) = 0;
            v2->WaitStatus = 128;
          }
          v6 = v2->MutantListHead.Blink;
          v7 = v6->Flink;
          v3[2].Flink = v6->Flink;
          v3[2].Blink = v6;
          v7->Blink = v3 + 2;
          v6->Flink = v3 + 2;
        }
      }
    }
    WaitBlock1 = WaitBlock1->NextWaitBlock;
    v1 = WaitBlock1;
  }
  while ( WaitBlock1 != WaitBlock );
}