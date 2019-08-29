#include "TinyPICO.h"
#include "Hash.h"

TinyPICO tinyPICO = TinyPICO();

int testSize;
char testData[2048];

void strrnd(char *s, const int len) {
  static const char alphanum[] =
      "0123456789"
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
      "abcdefghijklmnopqrstuvwxyz"
      "!@#$%^&*()_+:';/.,<>?|~`";

  for (int i = 0; i < len; ++i) {
    s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
}

void setup() {
  tinyPICO.DotStar_SetBrightness(255);
  tinyPICO.DotStar_SetPixelColor(255, 0, 0);
  Serial.begin(115200);
  while (!Serial) { }
  tinyPICO.DotStar_SetBrightness(255);
  tinyPICO.DotStar_SetPixelColor(0, 255, 0);
}

void loop() {
  testSize = rand() % 2048;
  strrnd((char *)&testData, testSize);

  uint8_t hash[20];
  sha1(testData, &hash[0]);

  Serial.printf("%s\n", testData);
  Serial.print("SHA1:");
  for(uint16_t i = 0; i < 20; i++) {
      Serial.printf("%02x", hash[i]);
  }
  Serial.printf("\n");
}
