int __stdcall IDirectSound_Release(IDirectSound *pDirectSound)
{
  int result; // eax

  if ( pDirectSound )
    result = (*(int (__stdcall **)(IDirectSound *, IDirectSound *))(*(_DWORD *)&pDirectSound[-8] + 8))(
               pDirectSound - 8,
               pDirectSound - 8);
  else
    result = (*(int (__stdcall **)(_DWORD, _DWORD))(MEMORY[0] + 8))(0, 0);
  return result;
}