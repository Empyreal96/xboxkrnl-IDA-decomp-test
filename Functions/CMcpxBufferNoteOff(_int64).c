int __userpurge CMcpxBuffer::NoteOff@<eax>(CMcpxBuffer *this@<ecx>, int *a2@<edi>, int a3@<esi>, __int64 rtTimeStamp, int fBreakLoop)
{
  CMcpxBuffer *thisa; // [esp+0h] [ebp-Ch]
  int hr; // [esp+4h] [ebp-8h]
  int fDeferred; // [esp+8h] [ebp-4h]

  thisa = this;
  fDeferred = 0;
  hr = 0;
  if ( rtTimeStamp )
    fDeferred = CMcpxBuffer::ScheduleDeferredCommand(this, a2, 4u, rtTimeStamp, fBreakLoop);
  if ( !fDeferred )
    hr = CMcpxBuffer::NoteOff(thisa, a2, a3, fBreakLoop);
  return hr;
}