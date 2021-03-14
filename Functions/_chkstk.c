void *__usercall _chkstk@<eax>(void *result@<eax>)
{
  void *retaddr; // [esp+0h] [ebp+0h]

  if ( result )
    result = retaddr;
  return result;
}