int __userpurge CMcpxBuffer::Stop@<eax>(CMcpxBuffer *this@<ecx>, int *a2@<edi>, int a3@<esi>, __int64 rtTimeStamp)
{
  CMcpxBuffer *thisa; // [esp+0h] [ebp-Ch]
  int hr; // [esp+4h] [ebp-8h]
  int fDeferred; // [esp+8h] [ebp-4h]

  thisa = this;
  fDeferred = 0;
  hr = 0;
  if ( rtTimeStamp )
    fDeferred = CMcpxBuffer::ScheduleDeferredCommand(this, a2, 3u, rtTimeStamp, 0);
  if ( !fDeferred )
    hr = CMcpxBuffer::Stop(thisa, a2, a3);
  return hr;
}