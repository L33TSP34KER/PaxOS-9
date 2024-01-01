// #ifdef ESP_PLATFORM
//
// #include <cstdio>
//
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "driver/gpio.h"
// #include "esp_log.h"
//
// #include "LGFX_ESP32.hpp"
//
// #define LGFX_USE_V1
//
// #include <LovyanGFX.hpp>
//
// LGFX lcd;
//
// extern "C" void app_main()
// {
//     lcd.init();
//
//     lcd.setBrightness(0xFF);
//     lcd.setColorDepth(16);
//     lcd.setTextColor(TFT_WHITE);
//     lcd.fillScreen(TFT_BLACK);
//     lcd.printf("Hello World !\n");
//     lcd.printf("C++ Version : %ld\n", __cplusplus);
//
//     while (true) {
//         vTaskDelay(pdMS_TO_TICKS(1000));
//     }
// }
//
// #else
//
// #include "graphics.hpp"
// #include "Surface.hpp"
// #include "color.hpp"
//
// int main(int argc, char **argv)
// {
//     graphics::init();
//
//     auto surface = graphics::Surface(480, 320);
//     surface.setPixel(8, 8, graphics::packRGB565(255, 0, 0));
//
//     int i = 0;
//
//     while (graphics::update())
//     {
//         graphics::clear();
//
//         std::sin(static_cast<double>(10));
//
//         graphics::setColor(255, 0, 0);
//         graphics::fillRect(static_cast<uint16_t>(64 + std::sin(static_cast<double>(i)) * 128), 16, 32, 32);
//
//         i++;
//     }
//
//     graphics::cleanup();
//
//     return 0;
// }
//
// #endif

#ifdef ESP_PLATFORM

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#endif

#include "graphics.hpp"
#include "delay.hpp"

// ESP-IDF main
extern "C" void app_main()
{
    graphics::init();
    graphics::setColor(255, 0, 0);
    graphics::fillRect(0, 0, 64, 64);

    while (graphics::isRunning())
    {
#ifdef ESP_PLATFORM

        vTaskDelay(pdMS_TO_TICKS(1000));

#else

        SDL_Delay(1000);

#endif
    }
}

#ifndef ESP_PLATFORM

// x64 main
int main(int argc, char **argv)
{
    graphics::SDLInit(app_main);
}

#endif
