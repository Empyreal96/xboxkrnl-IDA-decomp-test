void __fastcall KiWaitTest(void *Object, int Increment)
{
  _DWORD *v2; // esi
  _KWAIT_BLOCK *v3; // edi
  _KTHREAD *v4; // ebx
  _KWAIT_BLOCK *i; // ecx
  _DWORD *v6; // eax
  char v7; // al
  bool v8; // zf
  _LIST_ENTRY *v9; // eax
  _LIST_ENTRY *v10; // edx
  int v11; // [esp+8h] [ebp-8h]
  _KWAIT_BLOCK *WaitBlock; // [esp+Ch] [ebp-4h]

  v11 = Increment;
  v2 = Object;
  v3 = (_KWAIT_BLOCK *)*((_DWORD *)Object + 2);
  if ( *((_DWORD *)Object + 1) > 0 )
  {
    do
    {
      if ( v3 == (_KWAIT_BLOCK *)(v2 + 2) )
        break;
      v4 = v3->Thread;
      WaitBlock = v3;
      if ( v3->WaitType == 1 )
      {
        v7 = *(_BYTE *)v2;
        v3 = (_KWAIT_BLOCK *)v3->WaitListEntry.Blink;
        if ( (*(_BYTE *)v2 & 7) == 1 )
        {
          v2[1] = 0;
        }
        else if ( v7 == 5 )
        {
          --v2[1];
        }
        else if ( v7 == 2 )
        {
          v8 = v2[1]-- == 1;
          if ( v8 )
          {
            v8 = *((_BYTE *)v2 + 28) == 1;
            v2[6] = v4;
            if ( v8 )
            {
              *((_BYTE *)v2 + 28) = 0;
              v4->WaitStatus = 128;
            }
            v9 = v4->MutantListHead.Blink;
            v10 = v9->Flink;
            v2[4] = v9->Flink;
            v2[5] = v9;
            v10->Blink = (_LIST_ENTRY *)(v2 + 4);
            v9->Flink = (_LIST_ENTRY *)(v2 + 4);
          }
        }
      }
      else
      {
        for ( i = v3->NextWaitBlock; i != v3; i = i->NextWaitBlock )
        {
          if ( i->WaitKey != 258 )
          {
            v6 = i->Object;
            if ( (*(_BYTE *)v6 != 2 || v6[1] <= 0 && v4 != (_KTHREAD *)v6[6]) && v6[1] <= 0 )
              goto scan;
          }
        }
        v3 = (_KWAIT_BLOCK *)v3->WaitListEntry.Blink;
        KiWaitSatisfyAll(WaitBlock);
      }
      KiUnwaitThread(v4, WaitBlock->WaitKey, v11);
scan:
      v3 = (_KWAIT_BLOCK *)v3->WaitListEntry.Flink;
    }
    while ( v2[1] > 0 );
  }
}