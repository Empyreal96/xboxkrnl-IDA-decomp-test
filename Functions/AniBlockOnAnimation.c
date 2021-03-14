void __usercall AniBlockOnAnimation(int a1@<edx>, int *a2@<edi>, int a3@<esi>)
{
  int v3; // edx
  int v4; // ecx
  int v5; // edx
  _KWAIT_BLOCK WaitBlocks[2]; // [esp+0h] [ebp-3Ch]
  void *WaitObjects[2]; // [esp+30h] [ebp-Ch]
  _ETHREAD *ThreadObject; // [esp+38h] [ebp-4h]

  if ( g_hThread )
  {
    if ( ObReferenceObjectByHandle(
           a1,
           (int)&ThreadObject,
           a2,
           a3,
           g_hThread,
           &PsThreadObjectType,
           (void **)&ThreadObject) >= 0 )
    {
      WaitObjects[0] = ThreadObject;
      WaitObjects[1] = &g_EventLogoWaiting;
      KeWaitForMultipleObjects(v3, v4, a3, 2u, WaitObjects, WaitAny, 0, 0, 0, 0, WaitBlocks);
      ObfDereferenceObject(ThreadObject, v5);
    }
  }
}