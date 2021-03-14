int __stdcall VectorToRGBA(_D3DVECTOR *v)
{
  float r; // ST0C_4
  float g; // ST10_4
  float b; // [esp+1Ch] [ebp+8h]

  r = (v->x + 1.0) * 127.5;
  g = (v->y + 1.0) * 127.5;
  b = (v->z + 1.0) * 127.5;
  return ((signed int)255.0 << 24) | ((signed int)r << 16) | ((signed int)g << 8) | (signed int)b;
}