void __stdcall remove_processes_by_level_and_channel(char level, char channel)
{
  process *v2; // eax
  process *v3; // esi

  v2 = process_queue->next;
  if ( process_queue->next )
  {
    do
    {
      v3 = v2->next;
      if ( v2->level == level && v2->hard_channel == channel )
        kill_process(v2);
      v2 = v3;
    }
    while ( v3 );
  }
}