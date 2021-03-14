int __stdcall IDirectSoundBuffer_Release(IDirectSoundBuffer *pBuffer)
{
  int result; // eax

  if ( pBuffer )
    result = (*(int (__stdcall **)(IDirectSoundBuffer *, IDirectSoundBuffer *))(*(_DWORD *)&pBuffer[-28] + 8))(
               pBuffer - 28,
               pBuffer - 28);
  else
    result = (*(int (__stdcall **)(_DWORD, _DWORD))(MEMORY[0] + 8))(0, 0);
  return result;
}