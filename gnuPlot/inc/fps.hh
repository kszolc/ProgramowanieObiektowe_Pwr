#pragma once
#include <chrono>

/**
 * @brief Checking duration between two measurements
 * 
 * frame_time_ms - miliseconds between two measurements
 * fps_now - current Frames Per Second
 * 
 */
class FrameTime
{
private:
  std::chrono::milliseconds last_time_ms;

public:
  double frame_time_ms;
  double fps_now;

  void measure()
  {
    std::chrono::milliseconds now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    frame_time_ms = (now_ms - last_time_ms).count();
    if (frame_time_ms < 1)
      frame_time_ms = 1;
    fps_now = 1000 / frame_time_ms;
    last_time_ms = now_ms;
  }
  void wait(double sec)
  {
    std::chrono::milliseconds now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    std::chrono::milliseconds t;
    do{
      t = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    }while((t - now).count() <= sec*1000);
  }
};