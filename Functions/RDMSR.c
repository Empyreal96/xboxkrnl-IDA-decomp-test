unsigned __int64 __thiscall RDMSR(void *this)
{
  return __readmsr((unsigned int)this);
}