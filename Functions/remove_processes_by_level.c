process *__stdcall remove_processes_by_level(char level)
{
  process *result; // eax
  process *v2; // esi

  result = process_queue->next;
  if ( process_queue->next )
  {
    do
    {
      v2 = result->next;
      if ( result->level == level )
        kill_process(result);
      result = v2;
    }
    while ( v2 );
  }
  return result;
}