unsigned int __stdcall regValue(char reg, _CONTEXT *ContextRecord)
{
  unsigned int result; // eax

  switch ( reg )
  {
    case 0:
      result = ContextRecord->Eax;
      break;
    case 1:
      result = ContextRecord->Ecx;
      break;
    case 2:
      result = ContextRecord->Edx;
      break;
    case 3:
      result = ContextRecord->Ebx;
      break;
    case 4:
      result = ContextRecord->Esp;
      break;
    case 5:
      result = ContextRecord->Ebp;
      break;
    case 6:
      result = ContextRecord->Esi;
      break;
    case 7:
      result = ContextRecord->Edi;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}