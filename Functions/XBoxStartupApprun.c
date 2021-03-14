int __usercall XBoxStartupApp::run@<eax>(XBoxStartupApp *this@<ecx>, int a2@<edx>, int *a3@<edi>)
{
  XBoxStartupApp *v3; // esi

  v3 = this;
  if ( !g_bShortVersion )
    BootSound_Start(a3);
  while ( v3->fTimeElapsed < 8.0 )
    XBoxStartupApp::process(v3);
  if ( !g_bShortVersion )
    BootSound_Stop(a2, (int)this, a3);
  return 0;
}