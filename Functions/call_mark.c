// write access to const memory has been detected, the output may be wrong!
char __stdcall call_mark()
{
  char result; // al

  result = current_call->priority;
  marker = current_call->priority;
  return result;
}