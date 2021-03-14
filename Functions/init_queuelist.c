// write access to const memory has been detected, the output may be wrong!
int __stdcall init_queuelist()
{
  unsigned __int8 v0; // bl
  int v1; // esi
  signed int v2; // eax
  unsigned int v3; // eax
  int v4; // eax
  process *v5; // eax

  dword_80114BCC[0] = 0;
  v0 = 1;
  v1 = max_processes - 1;
  queue_list[0].next = (process *)dword_80114BE4;
  if ( v1 > 1 )
  {
    v2 = 1;
    do
    {
      v3 = 28 * v2;
      queue_list[v3 / 0x1C].next = (process *)&dword_80114BE4[v3 / 4];
      ++v0;
      dword_80114BCC[v3 / 4] = (int)&queue_list[v3 / 0x1C - 1];
      v2 = v0;
    }
    while ( v0 < v1 );
  }
  v4 = 28 * max_processes;
  *(_LIST_ENTRY **)((char *)&g_BootSoundDpc.DpcListEntry.Flink + v4) = 0;
  *(_LIST_ENTRY **)((char *)&g_BootSoundDpc.DpcListEntry.Blink + v4) = (_LIST_ENTRY *)&queue_list[max_processes - 2];
  v5 = get_process_packet();
  process_queue = v5;
  if ( v5 )
  {
    v5->next = 0;
    process_queue->prev = 0;
    if ( max_tracks )
      memset(channel_level, 0, (unsigned __int8)max_tracks);
  }
  return 0;
}