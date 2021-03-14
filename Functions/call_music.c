// write access to const memory has been detected, the output may be wrong!
unsigned __int8 __stdcall call_music()
{
  unsigned __int8 result; // al
  unsigned __int16 **v1; // edi
  char *v2; // esi
  unsigned __int16 track_map; // [esp+8h] [ebp-Ch]
  signed __int16 mask; // [esp+Ch] [ebp-8h]
  unsigned __int8 i; // [esp+10h] [ebp-4h]

  marker = 0;
  last_music_call = sound_call;
  remove_processes_by_level(0);
  result = (unsigned __int8)current_call;
  v1 = (unsigned __int16 **)current_call->tbl_ptr;
  track_map = current_call->track_map;
  i = 0;
  for ( mask = 1; i < (unsigned __int8)max_tracks; mask *= 2 )
  {
    if ( track_map & (unsigned __int16)mask )
    {
      init_track_status(0, i);
      create_process(*v1, 0, i);
      v2 = &channel_level[i];
      ++v1;
      if ( (unsigned __int8)*v2 < 1u )
      {
        nosound(i);
        *v2 = 0;
      }
    }
    result = ++i;
  }
  return result;
}