void __userpurge CDirectSoundBuffer::OnStopStatic(int a1@<ecx>, int *a2@<edi>, int a3@<esi>, void *pvContext)
{
  CDirectSoundBuffer::OnStop(a1, a2, a3, (CDirectSoundBuffer *)pvContext);
}