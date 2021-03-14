unsigned __int8 __stdcall call_effect()
{
  unsigned __int8 result; // al
  unsigned __int16 **v1; // esi
  unsigned __int16 v2; // di
  signed __int16 mask; // [esp+Ch] [ebp-8h]
  unsigned __int8 i; // [esp+10h] [ebp-4h]

  result = (unsigned __int8)current_call;
  v1 = (unsigned __int16 **)current_call->tbl_ptr;
  v2 = current_call->track_map;
  i = 0;
  mask = 1;
  if ( max_tracks )
  {
    do
    {
      if ( v2 & (unsigned __int16)mask )
      {
        remove_processes_by_level_and_channel(1, i);
        channel_level[i] = 1;
        init_track_status(1, i);
        create_process(*v1, 1, i);
        ++v1;
      }
      result = ++i;
      mask *= 2;
    }
    while ( i < (unsigned __int8)max_tracks );
  }
  return result;
}