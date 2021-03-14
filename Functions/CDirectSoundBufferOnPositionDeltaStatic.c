void __userpurge CDirectSoundBuffer::OnPositionDeltaStatic(int *a1@<edi>, int a2@<esi>, unsigned int dwPlayCursor, void *pvContext)
{
  CDirectSoundBuffer::OnPositionDelta(a1, a2, (CDirectSoundBuffer *)pvContext, dwPlayCursor);
}