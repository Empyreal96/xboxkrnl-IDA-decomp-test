// write access to const memory has been detected, the output may be wrong!
int __stdcall create_process(unsigned __int16 *mem_ptr, char level, char channel)
{
  __int16 v3; // cx
  process *v4; // eax
  bool v5; // zf

  pp = get_process_packet();
  pp->mem_ptr.c = (char *)mem_ptr;
  pp->level = level;
  pp->timer = 0;
  pp->hard_channel = channel;
  pp->function = *mem_ptr;
  pp->type = 0;
  pp->prev = process_queue;
  v3 = system_clock_music;
  if ( level )
    v3 = system_clock_fx;
  pp->prev_timer = v3;
  v4 = process_queue->next;
  v5 = process_queue->next == 0;
  pp->next = process_queue->next;
  if ( !v5 )
    v4->prev = pp;
  process_queue->next = pp;
  return 1;
}