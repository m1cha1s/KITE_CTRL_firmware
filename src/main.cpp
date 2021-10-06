#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_BusIO_Register.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_NeoMatrix.h>

#define NEO_PIN 13
#define NEO_X 30
#define NEO_Y 5

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(NEO_X, NEO_Y, NEO_PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  for(int i = 0; i < 1; i ++) {
    if(Serial) break;
    delay(1000);
  }

  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(40);
  matrix.setTextColor(matrix.Color(255,255,255));
}

void loop() {
  matrix.fill(0);
  matrix.setCursor(0,0);
  matrix.print(F("Hello"));
  matrix.show();
}