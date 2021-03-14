// write access to const memory has been detected, the output may be wrong!
track_info *__stdcall get_track_info_block2(char level, char chan)
{
  gtifbtmp = chan + level * max_tracks;
  return &track_status[(unsigned __int8)gtifbtmp];
}