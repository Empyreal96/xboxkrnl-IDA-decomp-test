// write access to const memory has been detected, the output may be wrong!
int __stdcall call_silence()
{
  process *v0; // eax
  process *v1; // esi
  unsigned __int8 i; // [esp+4h] [ebp-4h]

  v0 = process_queue->next;
  if ( process_queue->next )
  {
    do
    {
      v1 = v0->next;
      kill_process(v0);
      v0 = v1;
    }
    while ( v1 );
  }
  current_timer_priority = 0;
  for ( i = 0; i < (unsigned __int8)max_tracks; ++i )
  {
    channel_level[i] = 0;
    init_track_status(0, i);
    init_track_status(1, i);
    nosound(i);
  }
  return call_user_function();
}