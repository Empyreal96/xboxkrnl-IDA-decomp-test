// write access to const memory has been detected, the output may be wrong!
process *__stdcall get_process_packet()
{
  process *result; // eax

  result = queue_list[0].next;
  queue_list[0].next = queue_list[0].next->next;
  if ( queue_list[0].next->next )
    queue_list[0].next->next->prev = queue_list;
  return result;
}