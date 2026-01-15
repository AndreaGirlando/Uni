class Face {
  int shift;
  float dimensioneDelta;
  
  Face(int tempShift, float tempDimensionDelta) {
      shift = tempShift;
      dimensioneDelta = tempDimensionDelta;
  } // Niente punto e virgola qui

  void drawFace() {
    stroke(0);

    // 1. La Testa
    strokeWeight(5 * dimensioneDelta);
    circle((0 + shift) * dimensioneDelta, 0, 250 * dimensioneDelta);

    // 2. Il Naso (Triangolo)
    strokeWeight(1);
    triangle(
      (-10 + shift) * dimensioneDelta, (20) * dimensioneDelta,
      (10 + shift) * dimensioneDelta, (20) * dimensioneDelta,
      (0 + shift) * dimensioneDelta, (-8) * dimensioneDelta
      );

    // 3. Gli Occhi
    fill(0, 0, 210);
    circle((-50 + shift) * dimensioneDelta, -50 * dimensioneDelta, 50 * dimensioneDelta);
    circle((50 + shift) * dimensionDelta, -50 * dimensionDelta, 50 * dimensionDelta);

    // 4. La Bocca
    fill(255);
    arc((0 + shift) * dimensioneDelta, 50 * dimensioneDelta, 100 * dimensioneDelta, 100 * dimensioneDelta, 0, PI, PIE);
  }
}
