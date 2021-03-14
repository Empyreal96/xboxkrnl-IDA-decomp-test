// write access to const memory has been detected, the output may be wrong!
char __stdcall sos_main()
{
  process *v0; // eax
  bool i; // zf
  process *v2; // esi
  char v3; // dl
  unsigned __int8 v4; // cl

  do
  {
    if ( fifo.fifo_read != fifo.fifo_write )
    {
      LOBYTE(v0) = get_fifo();
      sound_call = (char)v0;
      if ( (unsigned __int8)v0 > (unsigned __int8)max_sound_call )
        continue;
      current_call = (sound *)(8 * (unsigned __int8)v0 - 2146388448);
      (*(void (__stdcall **)())(4 * (unsigned __int8)current_call->type - 2146422808))();
    }
    v0 = process_queue->next;
    for ( i = process_queue->next == 0; ; i = v2 == 0 )
    {
      current_process = v0;
      if ( i )
        break;
      v2 = v0->next;
      v0->timer += v0->prev_timer - system_clock_music;
      current_process->prev_timer = system_clock_music;
      if ( current_process->timer < 0 )
      {
        v3 = current_process->hard_channel;
        current_channel = current_process->hard_channel;
        current_level = current_process->level;
        v4 = current_level ? v3 + max_tracks : v3;
        gtifbtmp = v4;
        ti = &track_status[v4];
        if ( !(*(int (__stdcall **)())(4 * current_process->function - 2146422960))() )
        {
          v0 = process_queue->next;
          current_process = process_queue->next;
          break;
        }
      }
      v0 = v2;
    }
  }
  while ( sos_only );
  return (char)v0;
}