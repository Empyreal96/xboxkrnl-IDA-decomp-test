int __userpurge NtFsControlFile@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *FileHandle, void *Event, void (__stdcall *ApcRoutine)(void *, _IO_STATUS_BLOCK *, unsigned int), void *ApcContext, _IO_STATUS_BLOCK *IoStatusBlock, unsigned int IoControlCode, void *InputBuffer, unsigned int InputBufferLength, void *OutputBuffer, unsigned int OutputBufferLength)
{
  return IopXxxControlFile(
           a1,
           a2,
           a3,
           a4,
           FileHandle,
           Event,
           ApcRoutine,
           ApcContext,
           IoStatusBlock,
           IoControlCode,
           InputBuffer,
           InputBufferLength,
           OutputBuffer,
           OutputBufferLength,
           0);
}