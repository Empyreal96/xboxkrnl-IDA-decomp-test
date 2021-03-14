// write access to const memory has been detected, the output may be wrong!
void __stdcall kill_process(process *pp)
{
  pp->prev->next = pp->next;
  if ( pp->next )
    pp->next->prev = pp->prev;
  pp->next = queue_list[0].next;
  pp->prev = queue_list;
  queue_list[0].next = pp;
  if ( pp->next )
    pp->next->prev = pp;
}