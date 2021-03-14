int __userpurge CMcpxBuffer::Play@<eax>(CMcpxBuffer *this@<ecx>, int *a2@<edi>, int a3@<esi>, __int64 rtTimeStamp, int fLoop)
{
  CMcpxBuffer *thisa; // [esp+0h] [ebp-Ch]
  int hr; // [esp+4h] [ebp-8h]
  int fDeferred; // [esp+8h] [ebp-4h]

  thisa = this;
  fDeferred = 0;
  hr = 0;
  if ( rtTimeStamp )
    fDeferred = CMcpxBuffer::ScheduleDeferredCommand(this, a2, 2u, rtTimeStamp, fLoop);
  if ( !fDeferred )
    hr = CMcpxBuffer::Play(thisa, a2, a3, fLoop);
  return hr;
}