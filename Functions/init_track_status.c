track_info *__stdcall init_track_status(char level, char channel)
{
  track_info *result; // eax

  result = get_track_info_block2(level, channel);
  result->patch = 0;
  result->loop_level = 0;
  result->mux_level = 0;
  result->transpose = 0;
  result->filtercutoff = 0;
  result->volume = 127;
  result->pan = 0;
  return result;
}