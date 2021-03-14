int __stdcall GetNumberOfIndicesForTristripMesh(int x_quads, int y_quads, bool b_d_tap_1, bool b_d_tap_2)
{
  int v5; // esi

  if ( x_quads <= 14 )
    return (b_d_tap_2 != 0) + (b_d_tap_1 != 0) + 2 * (x_quads + y_quads * (x_quads + 2));
  v5 = GetNumberOfIndicesForTristripMesh(x_quads - 14, y_quads, 1, b_d_tap_2);
  return v5 + GetNumberOfIndicesForTristripMesh(14, y_quads, b_d_tap_1, 1);
}