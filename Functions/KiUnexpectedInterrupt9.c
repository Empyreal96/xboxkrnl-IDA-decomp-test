int __usercall KiUnexpectedInterrupt9@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int *a4)
{
  return KiUnexpectedInterruptTail(a1, a2, a3, a4);
}