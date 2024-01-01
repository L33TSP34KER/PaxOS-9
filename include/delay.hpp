//
// Created by Charlito33 on 31/12/2023.
// Copyright (c) 2023 Charlito33. All rights reserved.
//

#ifndef DELAY_HPP
#define DELAY_HPP

#ifdef ESP_PLATFORM

#define delay(ms) vTaskDelay(pdMS_TO_TICKS(ms))

#else

#define delay(ms) SDL_Delay(ms)

#endif

#endif //DELAY_HPP
