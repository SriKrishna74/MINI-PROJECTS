#define MAX_RESOLUTION_VGA
#define DEBUG_ENABLE 1
#define gpioPIR 13 //PIR Motion Sensor

// Replace with your WiFi credentials
#define WIFI_SSID "POCOX2"
#define WIFI_PASS "krishna2003"

// Replace with your Telegram credentials
#define TELEGRAM_TOKEN "6393496928:AAFu6w9CMM4EUIR0AsAaCEXxjru7ntd5bng"
#define CHAT_ID "953665415"

#include "esp32cam.h"
#include "esp32cam/JpegDecoder.h"
#include "esp32cam/motion/Detector.h"
#include "esp32cam/motion/SimpleChange.h"
#include "esp32cam/http/TelegramChat.h"

using namespace Eloquent::Esp32cam;

Cam cam;
JpegDecoder decoder;
Motion::SimpleChange algorithm;
Motion::Detector detector(algorithm);
Http::TelegramChat telegram(TELEGRAM_TOKEN, CHAT_ID);
void setup() {
    Serial.begin(115200);
    delay(3000);
    Serial.println("Init");

    // see 2_CameraSettings for more details
    cam.aithinker();
    cam.highQuality();
    cam.vga();
    cam.highestSaturation();
    cam.disableAutomaticWhiteBalance();
    cam.disableAutomaticExposureControl();
    cam.disableGainControl();

    // See 10_Image_Wise_Motion_Detection for details
    detector.trainFor(30);
    detector.retrainAfter(33ULL * 600);
    detector.triggerAbove(0.2);
    detector.denoise();
    detector.debounceSeconds(5);

    algorithm.differBy(20);
    algorithm.smooth(0.9);
    algorithm.onlyUpdateBackground();

    while (!cam.begin())
        Serial.println(cam.getErrorMessage());

    while (!cam.connect(WIFI_SSID, WIFI_PASS))
        Serial.println(cam.getErrorMessage());

    /**
     * Initialize bot
     */
    while (!telegram.begin())
        Serial.println(telegram.getErrorMessage());
}
void loop() {
    if (!cam.capture()) {
        Serial.println(cam.getErrorMessage());
        return;
    }

    if (!decoder.decode(cam)) {
        Serial.println(decoder.getErrorMessage());
        return;
    }

    if (!detector.update(decoder.luma)) {
        Serial.println(detector.getErrorMessage());
        return;
    }

    /**
     * When motion is detected...
     */
     
  pinMode(gpioPIR, INPUT_PULLUP);
  int v = digitalRead(gpioPIR);
  Serial.println(v);
  if (v==1){

  
     
    if (detector.triggered()) {
        Serial.println("Motion detected. Sending to Telegram... ");

        /**
         * ...send message and picture to Telegram chat
         */
        Serial.println(telegram.sendText("Motion detected") ? "Text OK" : "Text ERROR");
        Serial.println(telegram.sendPhoto(cam) ? "Picture OK" : "Picture ERROR");
    }
}
}
