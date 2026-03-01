/*!
 * @file max44009_simpletest.ino
 *
 * Simple example for the MAX44009 ambient light sensor.
 * Reads lux value every 100ms in auto-ranging mode.
 * Output is Serial Plotter friendly.
 */

#include <Adafruit_MAX44009.h>
#include <Wire.h>

Adafruit_MAX44009 max44009;

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    delay(10);
  }

  if (!max44009.begin()) {
    Serial.println(F("Could not find MAX44009 sensor!"));
    while (1) {
      delay(10);
    }
  }

  Serial.println(F("Lux"));
}

void loop() {
  float lux = max44009.readLux();

  if (!isnan(lux)) {
    Serial.println(lux);
  }

  delay(100);
}
